#include "RequestObject.h"
#include "Json.h"

void URequestObject::MakeRequest(const FRequest& Request)
{
	FString VerbString; // GET, PUT, POST, DELETE
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

	UE_LOG(LogTemp, Display, TEXT("MakeRequest: Verb(%s), Content(%s)"), *VerbString, *RequestString);
}

void URequestObject::ConvertResponseJson(const FString& ResponseContent)
{
	UE_LOG(LogTemp, Display, TEXT("Converting Response: %s"), *ResponseContent);

	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(ResponseContent);

	TSharedPtr<FJsonObject> JsonObject;
	if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
	{
		OnJsonConverted.Broadcast(JsonObject);	
	}
}

void URequestObject::OnRequestProcessed(FHttpRequestPtr Request, FHttpResponsePtr Response,
                                        bool bProcessedToStringSuccessfully)
{
	EHttpRequestStatus::Type HttpRequestStatus = Request->GetStatus();
	FString HttpRequestStatusString = ToString(HttpRequestStatus);

	if (bProcessedToStringSuccessfully)
	{
		FString ResponseContent = Response->GetContentAsString();
		ConvertResponseJson(ResponseContent);
	}

	UE_LOG(LogTemp, Display, TEXT("OnRequestProcessed: %s"), *HttpRequestStatusString);
}
