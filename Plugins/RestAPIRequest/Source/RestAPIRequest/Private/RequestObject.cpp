#include "RequestObject.h"
#include "Json.h"
#include "Misc/FileHelper.h"

void URequestObject::AddHeaders(TSharedRef<IHttpRequest> HttpRequest)
{
	TArray<FString> HeaderKeys;
	Internal_Request.Headers.GetKeys(HeaderKeys);
	for (int32 i = 0; i < HeaderKeys.Num(); i++)
	{
		FString HeaderKey = HeaderKeys[i];
		FString KeyValue = Internal_Request.Headers[HeaderKey];

		HttpRequest->AppendToHeader(HeaderKey, KeyValue);
	}
}

void URequestObject::AddArgs(FString& QueryString) const
{
	TArray<FString> Args = Internal_Request.Args;
	for (int32 i = 0; i < Args.Num(); i++)
	{
		QueryString.Append(Args[i]);

		if (i < Args.Num() - 1)
		{
			QueryString.Append(TEXT("&"));
		}
	}
}

void URequestObject::AddCredentials(FString& QueryString) const
{
	if (!Internal_Request.Username.IsEmpty())
	{
		QueryString.Append(TEXT("identity="));
		QueryString.Append(Internal_Request.Username);
		QueryString.Append(TEXT("&"));
	}

	if (!Internal_Request.Password.IsEmpty())
	{
		QueryString.Append(TEXT("password="));
		QueryString.Append(Internal_Request.Password);
		QueryString.Append(TEXT("&"));
	}
}

void URequestObject::Get()
{
	FHttpModule& HttpModule = FHttpModule::Get();
	TSharedRef<IHttpRequest> HttpRequest = HttpModule.CreateRequest();

	FString URL = Internal_Request.APIBase + Internal_Request.APIExtension;

	FString VerbString = Internal_Request.GetTypeAsString();
	HttpRequest->SetVerb(VerbString);
	
	AddHeaders(HttpRequest);

	FString RequestString = URL;
	RequestString.Append(TEXT("?"));

	AddCredentials(RequestString);
	AddArgs(RequestString);

	HttpRequest->SetURL(RequestString);
	HttpRequest->SetTimeout(Internal_Request.Timeout);
	
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &URequestObject::OnGetRequestProcessed);
	
	HttpRequest->ProcessRequest();
}

void URequestObject::Put()
{
	if (!IFileManager::Get().FileExists(*Internal_Request.JsonFilePath))
	{
		UE_LOG(LogTemp, Error, TEXT("RequestObject: Failed to detect json file at path: %s"),
		       *Internal_Request.JsonFilePath);
		return;
	}

	FHttpModule& HttpModule = FHttpModule::Get();
	TSharedRef<IHttpRequest> HttpRequest = HttpModule.CreateRequest();

	FString URL = Internal_Request.APIBase + Internal_Request.APIExtension;
	FString RequestString = URL;

	FString VerbString = Internal_Request.GetTypeAsString();
	HttpRequest->SetVerb(VerbString);

	AddHeaders(HttpRequest);

	FArchive* File = IFileManager::Get().CreateFileReader(*Internal_Request.JsonFilePath, FILEREAD_Silent);
	if (!File)
	{
		UE_LOG(LogTemp, Error, TEXT("RequestObject: Failed to open Json file at path: %s for reading"),
		       *Internal_Request.JsonFilePath);
	}

	FString ContentString;
	if (!FFileHelper::LoadFileToString(ContentString, *File))
	{
		UE_LOG(LogTemp, Error, TEXT("RequestObject: Failed to convert file contents to string: %s"),
		       *Internal_Request.JsonFilePath);
		return;
	}

	HttpRequest->SetContentAsString(ContentString);
	UE_LOG(LogTemp, Display, TEXT("Sending PUT content: %s"), *ContentString);
	
	HttpRequest->SetURL(RequestString);
	HttpRequest->SetTimeout(Internal_Request.Timeout);

	HttpRequest->OnProcessRequestComplete().BindUObject(this, &URequestObject::OnPutRequestProcessed);

	if (File->Close())
	{
		UE_LOG(LogTemp, Display, TEXT("Closed file successfully: %s"), *Internal_Request.JsonFilePath);
	}

	HttpRequest->ProcessRequest();
}

void URequestObject::Post()
{
}

void URequestObject::Delete()
{
}

void URequestObject::MakeRequest(const FRequest& Request)
{
	Internal_Request = Request;

	ERequestType Type = Request.Type;
	switch (Type)
	{
	case ERequestType::GET:
		Get();
		break;
	case ERequestType::PUT:
		Put();
		break;
	case ERequestType::POST:
		Post();
		break;
	case ERequestType::DELETE:
		Delete();
		break;
	default: UE_LOG(LogTemp, Warning, TEXT("MakeRequest: Something went wrong."));
		break;
	}

	return;

	/*FString VerbString; // GET, PUT, POST, DELETE
	FString HeaderString; // Authentication method + authentication
	FString RequestString; // Url + args

	FHttpModule& HttpModule = FHttpModule::Get();

	TSharedRef<IHttpRequest> HttpRequest = HttpModule.CreateRequest();
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &URequestObject::OnRequestProcessed);

	FString URL = Request.APIBase + Request.APIExtension;

	// Set verb
	VerbString = Request.GetTypeAsString();
	HttpRequest->SetVerb(VerbString);

	// Set header(s)
	TArray<FString> HeaderKeys;
	Request.Headers.GetKeys(HeaderKeys);
	for (int32 i = 0; i < HeaderKeys.Num(); i++)
	{
		FString HeaderKey = HeaderKeys[i];
		FString KeyValue = Request.Headers[HeaderKey];

		HttpRequest->AppendToHeader(HeaderKey, KeyValue);
	}

	if (Request.Type == ERequestType::GET)
	{
		RequestString = URL;

		// Add query parameters to URL
		RequestString.Append(TEXT("?"));
	}

	// Set content
	if (!Request.Username.IsEmpty())
	{
		RequestString.Append(TEXT("identity="));
		RequestString.Append(Request.Username);
		RequestString.Append(TEXT("&"));
	}

	if (!Request.Password.IsEmpty())
	{
		RequestString.Append(TEXT("password="));
		RequestString.Append(Request.Password);
		RequestString.Append(TEXT("&"));
	}

	TArray<FString> Args = Request.Args;

	for (int32 i = 0; i < Args.Num(); i++)
	{
		RequestString.Append(Args[i]);

		if (i < Args.Num() - 1)
		{
			RequestString.Append(TEXT("&"));
		}
	}

	if (Request.Type == ERequestType::POST)
	{
		HttpRequest->SetURL(URL);
		HttpRequest->SetContentAsString(RequestString);
	}
	else if (Request.Type == ERequestType::GET)
	{
		HttpRequest->SetURL(RequestString);
	}

	HttpRequest->SetTimeout(Request.Timeout);

	HttpRequest->ProcessRequest();

	UE_LOG(LogTemp, Display, TEXT("MakeRequest: Verb(%s), Content(%s)"), *VerbString, *RequestString);*/
}

void URequestObject::BroadcastJsonDeserialization(const FString& JsonString)
{
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonString);

	TSharedPtr<FJsonObject> JsonObject;
	if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
	{
		OnJsonDeserialization.Broadcast(JsonObject);
	}
}

void URequestObject::OnGetRequestProcessed(FHttpRequestPtr Request, FHttpResponsePtr Response,
                                           bool bProcessedSuccessfully)
{
	EHttpRequestStatus::Type HttpRequestStatus = Request->GetStatus();
	FString HttpRequestStatusString = ToString(HttpRequestStatus);

	if (bProcessedSuccessfully)
	{
		FString ResponseContent = Response->GetContentAsString();
		BroadcastJsonDeserialization(ResponseContent);
	}

	UE_LOG(LogTemp, Display, TEXT("OnGetRequestProcessed: %s"), *HttpRequestStatusString);
}

void URequestObject::OnPutRequestProcessed(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (bWasSuccessful && Response.IsValid())
	{
		UE_LOG(LogTemp, Display, TEXT("OnPutRequestProcessed: Succeeded"));
        
		// Log the response content to see what was returned
		FString ResponseContent = Response->GetContentAsString();
		UE_LOG(LogTemp, Display, TEXT("Response Content: %s"), *ResponseContent);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("OnPutRequestProcessed: Failed"));
	}
}

void URequestObject::OnPostRequestProcessed(FHttpRequestPtr Request, FHttpResponsePtr Reponse,
                                            bool bProcessedSuccessfully)
{
}

void URequestObject::OnDeleteRequestProcessed(FHttpRequestPtr Request, FHttpResponsePtr Reponse,
                                              bool bProcessedSuccessfully)
{
}
