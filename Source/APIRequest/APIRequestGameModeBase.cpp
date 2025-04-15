// Fill out your copyright notice in the Description page of Project Settings.


#include "APIRequestGameModeBase.h"

#include "RequestObject.h"
#include "Json.h"
#include "Kismet/KismetStringLibrary.h"

AAPIRequestGameModeBase::AAPIRequestGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;
	TimeElapsed = 0.0f;
}

void AAPIRequestGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimeElapsed += DeltaTime;
}

void AAPIRequestGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	// RenewableNinjaExample();
	JsonPlaceHolderPutExample();	
}

void AAPIRequestGameModeBase::RenewableNinjaGetExample()
{
	URequestObject* RequestObject = NewObject<URequestObject>();
	if (RequestObject)
	{
		FRequest Request;

		TArray<FString> Args;
		Args.Emplace(FString::Printf(TEXT("lat=%f"), 52.437314));
		Args.Emplace(FString::Printf(TEXT("lon=%f"), -1.892573));
		Args.Emplace(FString::Printf(TEXT("date_from=%s"), TEXT("2015-07-01")));
		Args.Emplace(FString::Printf(TEXT("date_to=%s"), TEXT("2015-07-01")));
		Args.Emplace(TEXT("dataset=merra2"));
		Args.Emplace(TEXT("capacity=1.0"));
		Args.Emplace(TEXT("system_loss=0.1"));
		Args.Emplace(TEXT("tracking=0"));
		Args.Emplace(TEXT("tilt=35"));
		Args.Emplace(TEXT("azim=170"));
		Args.Emplace(TEXT("format=json"));

		TMap<FString, FString> Headers;
		Headers.Emplace(TEXT("Authorization"), TEXT("Token a0d8c47add5636f1d1753798de3749f6eb8fbe9f"));

		Request.Type = ERequestType::GET;
		Request.Headers = Headers;
		Request.APIBase = TEXT("https://www.renewables.ninja/api/");
		Request.APIExtension = TEXT("data/pv");
		Request.Args = Args;
		Request.Timeout = 5.0f;

		RequestObject->OnJsonDeserialization.AddLambda([&](
			const TSharedPtr<FJsonObject>& JsonObject)
			{
				const TSharedPtr<FJsonObject>* DataObject;
				JsonObject->TryGetObjectField(TEXT("data"), DataObject);

				if (DataObject)
				{
					for (auto Value : DataObject->Get()->Values)
					{
						FString StringValue = ConvertUNIXTime(Value.Key);

						double NumberValue;

						const TSharedPtr<FJsonObject>* ElectricityObject;
						Value.Value->TryGetObject(ElectricityObject);

						ElectricityObject->Get()->TryGetNumberField(TEXT("electricity"), NumberValue);

						UE_LOG(LogTemp, Warning, TEXT("%s | kW %f | Process Time %f"),
						       *StringValue, NumberValue, TimeElapsed);
					}

					SetActorTickEnabled(false);
					TimeElapsed = 0.0f;
				}
			});
		
		SetActorTickEnabled(true);
		TimeElapsed = 0.0f;
		RequestObject->MakeRequest(Request);
	}
}

void AAPIRequestGameModeBase::JsonPlaceHolderPutExample()
{
	URequestObject* RequestObject = NewObject<URequestObject>();
	if (RequestObject)
	{
		FRequest Request;
		Request.JsonFilePath = FPaths::Combine(FPaths::ProjectContentDir(), TEXT("External/jsonplaceholder.json"));
		Request.APIBase = TEXT("https://jsonplaceholder.typicode.com/");
		Request.APIExtension = TEXT("posts/1");
		Request.Timeout = 5.0f;
		Request.Type = ERequestType::PUT;
		
		RequestObject->MakeRequest(Request);
	}
}


FString AAPIRequestGameModeBase::ConvertUNIXTime(const FString& TimestampMilliseconds)
{
	int64 UnixTimeMiliseconds = FCString::Atoi64(*TimestampMilliseconds);
	int64 UnixTimeSeconds = UnixTimeMiliseconds / 1000;

	FDateTime Date = FDateTime::FromUnixTimestamp(UnixTimeSeconds);
	return Date.ToString(TEXT("Date: %d.%m.%y | Time: %H:%M.%S"));
}
