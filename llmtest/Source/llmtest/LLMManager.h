// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "LLMManager.generated.h"

UCLASS()
class LLMTEST_API ALLMManager : public AActor
{
	GENERATED_BODY()

public:

	ALLMManager();

protected:

	virtual void BeginPlay() override;

public:

	void SendMessage(FString PlayerMessage);

	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

};
