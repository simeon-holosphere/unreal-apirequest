// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "APIRequestGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class APIREQUEST_API AAPIRequestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
};
