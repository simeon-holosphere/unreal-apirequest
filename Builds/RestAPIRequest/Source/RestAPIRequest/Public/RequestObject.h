#pragma once

#include "CoreUObject.h"

// Http
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

// Json
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#include "RequestObject.Generated.h"

UENUM(BlueprintType)
enum class ERequestType : uint8
{
	// This method allows for the server to find the data you requested and sends it back to you 
	GET UMETA(DisplayName="Get"),
	
	// If you preform the 'PUT' request, then the server will update an entry in the database
	PUT UMETA(DisplayName="Put"),
	
	// This method permits the server to create a new entry in the database
	POST UMETA(DisplayName="Post"),

	// This method allows the server to delete an entry in the database
	DELETE UMETA(DisplayName="Delete") 
};

USTRUCT(BlueprintType)
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RestAPI)
	TMap<FString, FString> Headers; // Header name, header content. Like Authentication: <Token>

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RestAPI)
	ERequestType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RestAPI)
	FString APIBase; // Such as 'https://www.renewables.ninja/api/'

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RestAPI)
	FString APIExtension; // Such as data/pv

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RestAPI)
	FString Username;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RestAPI)
	FString Password;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RestAPI)
	TArray<FString> Args;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RestAPI)
	FString JsonFilePath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RestAPI)
	float Timeout;
};

DECLARE_MULTICAST_DELEGATE_OneParam(FOnJsonDeserialization, const TSharedPtr<FJsonObject>&);

UCLASS(NotBlueprintType)
class RESTAPIREQUEST_API URequestObject : public UObject
{
	GENERATED_BODY()

public:
	void MakeRequest(const FRequest& Request);

public:
	FOnJsonDeserialization OnJsonDeserialization;	

private:
	bool DoesJsonFileExist() const;
	bool ReadJsonFile(FString& ModifiedString) const;
	void AddHeaders(TSharedRef<IHttpRequest> Request);
	void AddArgs(FString& QueryString) const;
	void AddCredentials(FString& QueryString) const;
	
	void Get();
	void Put();
	void Post();
	void Delete();
	
	void BroadcastJsonDeserialization(const FString& JsonString);
	
	void OnGetRequestProcessed(FHttpRequestPtr Request, FHttpResponsePtr Reponse, bool bProcessedSuccessfully);
	void OnPutRequestProcessed(FHttpRequestPtr Request, FHttpResponsePtr Reponse, bool bProcessedSuccessfully);
	void OnPostRequestProcessed(FHttpRequestPtr Request, FHttpResponsePtr Reponse, bool bProcessedSuccessfully);
	void OnDeleteRequestProcessed(FHttpRequestPtr Request, FHttpResponsePtr Reponse, bool bProcessedSuccessfully);

private:
	FRequest Internal_Request;
};
