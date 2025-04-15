// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "APIRequestGameModeBase.generated.h"

USTRUCT(BlueprintType)
struct FElectricity
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString Date;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	double kW;
};

/**
 * 
 */
UCLASS()
class APIREQUEST_API AAPIRequestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	AAPIRequestGameModeBase();

	// Examples
	void RenewableNinjaGetExample();
	void JsonPlaceHolderPutExample();	
	
public:
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	FString ConvertUNIXTime(const FString& TimestampMilliseconds);

private:
	float TimeElapsed;
	TArray<FElectricity> ElectricityArr;
};
