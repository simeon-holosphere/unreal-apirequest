#pragma once

#include "CoreUObject.h"

// Http
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

#include "RequestObject.Generated.h"

UENUM()
enum class ERequestType : uint8
{
	GET, // This method allows for the server to find the data you requested and sends it back to you 
	PUT, // If you preform the 'PUT' request, then the server will update an entry in the database
	POST, // This method permits the server to create a new entry in the database
	DELETE // This method allows the server to delete an entry in the database
};

USTRUCT()
struct FRequest
{
	GENERATED_BODY()

	FString GetTypeAsString() const
	{
		FString Result;

		switch (Type)
		{
			case ERequestType::GET: Result = "GET"; break;
			case ERequestType::PUT: Result = "PUT"; break;
			case ERequestType::POST: Result = "POST"; break;
			case ERequestType::DELETE: Result = "DELETE"; break;
			default: Result = ""; break;
		}
		
		return Result;
	}
	
	/*
	* Content-Type: Specifies the media type of the request or response body (e.g., application/json, application/xml).
	* Accept: Indicates the media type the client can accept in the response. 
	* Authorization: Contains authentication credentials for the request.
	* X-API-Key: A custom header to hold an API key.
	* X-RateLimit-Limit: A header to specify the rate limit for the API.
	* X-Forwarded-For: A header used to determine the client's original IP address. 
	*/
	TMap<FString, FString> Headers; // Header name, header content. Like Authentication: <Token>
	
	ERequestType Type;

	FString APIBase; // Such as 'https://www.renewables.ninja/api/'
	FString APIExtension; // Such as data/pv

	FString Username;
	FString Password;
	
	TArray<FString> Args;	
	
	float Timeout;
};

DECLARE_MULTICAST_DELEGATE_OneParam(FOnJsonConverted, const TSharedPtr<FJsonObject>&);

UCLASS()
class RESTAPIREQUEST_API URequestObject : public UObject
{
	GENERATED_BODY()

public:
	void MakeRequest(const FRequest& Request);

public:
	FOnJsonConverted OnJsonConverted;	

private:
	void ConvertResponseJson(const FString& ResponseContent);
	void OnRequestProcessed(FHttpRequestPtr Request, FHttpResponsePtr Reponse, bool bProcessedSuccessfully);
};
