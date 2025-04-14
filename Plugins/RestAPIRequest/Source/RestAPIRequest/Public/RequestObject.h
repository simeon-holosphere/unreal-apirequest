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
	
	FString Url;
	ERequestType Type;
	float Timeout;
};

UCLASS()
class RESTAPIREQUEST_API URequestObject : public UObject
{
	GENERATED_BODY()
	
public:
	void MakeRequest(const FRequest& Request);

private:
	void OnRequestProcessed(FHttpRequestPtr Request, FHttpResponsePtr Reponse, bool bProcessedSuccessfully);
};
