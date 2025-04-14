#include "RequestObject.h"

void URequestObject::MakeRequest(const FRequest& Request)
{
	FString VerbString;
	FString ContentString;
	
	FHttpModule& HttpModule = FHttpModule::Get();

	TSharedRef<IHttpRequest> HttpRequest = HttpModule.CreateRequest();
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &URequestObject::OnRequestProcessed);
	HttpRequest->SetVerb(VerbString);
	HttpRequest->SetContentAsString(ContentString);
	HttpRequest->SetTimeout(Request.Timeout);

	HttpRequest->ProcessRequest();

	UE_LOG(LogTemp, Display, TEXT("MakeRequest: Verb(%s), Content(%s)"), *VerbString, *ContentString);
}

void URequestObject::OnRequestProcessed(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bProcessedToStringSuccessfully)
{
	EHttpRequestStatus::Type HttpRequestStatus = EHttpRequestStatus::Failed;
	FString HttpRequestStatusString = ToString(HttpRequestStatus);	
	
	if (Response)
	{
		HttpRequestStatus = Response->GetStatus();
    	HttpRequestStatusString = ToString(HttpRequestStatus);	
	}
	
	UE_LOG(LogTemp, Display, TEXT("OnRequestProcessed: %s"), *HttpRequestStatusString);	
}
