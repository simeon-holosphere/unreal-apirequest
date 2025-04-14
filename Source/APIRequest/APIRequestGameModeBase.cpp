// Fill out your copyright notice in the Description page of Project Settings.


#include "APIRequestGameModeBase.h"

#include "RequestObject.h"

void AAPIRequestGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	URequestObject* RequestObject = NewObject<URequestObject>();
	if (RequestObject)
	{
		FRequest Request;
		Request.Url = TEXT("");
		Request.Type = ERequestType::GET;
		Request.Timeout = 5.0f;
		
		RequestObject->MakeRequest(Request);
	}
}
