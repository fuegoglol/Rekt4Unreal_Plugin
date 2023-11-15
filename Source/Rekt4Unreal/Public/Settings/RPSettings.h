// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RPSettings.generated.h"

/**
 * 
 */
UCLASS(config = OnlineToolboxSettings)
class REKT4UNREAL_API URPSettings : public UObject
{
	GENERATED_BODY()
public:
	URPSettings(const FObjectInitializer& obj) {}
	
	//Will go to the project settings
	UPROPERTY(Config,EditAnywhere,DisplayName="Broker Adress", Category="Settings")
	FString IP = "127.0.0.1";
	
	UPROPERTY(Config,EditAnywhere,DisplayName="Broker port",Category="Settings")
	int32 Port = 4567;
	
	UPROPERTY(Config,EditAnywhere,DisplayName="Idle Timeout ms",Category="Settings")
	int32 IdleTimeoutMs = 1000;

	UPROPERTY(Config,EditAnywhere,DisplayName="Send Buffer Length",Category="Settings")
	int32 SendBufferLength = 100;


};
