// Fill out your copyright notice in the Description page of Project Settings.


#include "LLMManager.h"

#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

#include "Dom/JsonObject.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonReader.h"

ALLMManager::ALLMManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ALLMManager::BeginPlay()
{
	Super::BeginPlay();

	// 테스트 메시지
	SendMessage("안녕 NPC");
}

void ALLMManager::SendMessage(FString PlayerMessage)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField("message", PlayerMessage);

	FString RequestBody;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&RequestBody);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request =
		FHttpModule::Get().CreateRequest();

	Request->SetURL("http://127.0.0.1:8001/npc");
	Request->SetVerb("POST");
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(RequestBody);

	Request->OnProcessRequestComplete().BindUObject(this, &ALLMManager::OnResponseReceived);

	Request->ProcessRequest();
}

void ALLMManager::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
{
	if (!bSuccess || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("LLM request failed"));
		return;
	}

	FString ResponseString = Response->GetContentAsString();

	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseString);

	if (FJsonSerializer::Deserialize(Reader, JsonObject))
	{
		FString NPCReply = JsonObject->GetStringField("response");

		UE_LOG(LogTemp, Warning, TEXT("NPC says: %s"), *NPCReply);

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				8.f,
				FColor::Green,
				NPCReply
			);
		}
	}
}
