// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "inc/msquic.h"
#include "R4UToolBoxSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class REKT4UNREAL_API UR4UToolBoxSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	// Constructor / Destructor //
	
protected:
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	virtual void Deinitialize() override;

private:

	//
	// The UDP port used by the server side of the protocol.
	//
	FString RemoteIp = "127.0.0.1";

	//
	// The UDP port used by the server side of the protocol.
	//
	uint16_t UdpPort = 4567;

	//
	// The default idle timeout period (1 second) used for the protocol.
	//
	uint64_t IdleTimeoutMs = 1000;

	//
	// The length of buffer sent over the streams in the protocol.
	//
	uint32_t SendBufferLength = 100;

	//
	// The QUIC API/function table returned from MsQuicOpen2. It contains all the
	// functions called by the app to interact with MsQuic.
	//
	const QUIC_API_TABLE* MsQuic;
	
	//
	// The QUIC handle to the registration object. This is the top level API object
	// that represents the execution context for all work done by MsQuic on behalf
	// of the app.
	//
	HQUIC Registration;

	//
	// The QUIC handle to the configuration object. This object abstracts the
	// connection configuration. This includes TLS configuration and any other
	// QUIC layer settings.
	//
	HQUIC Configuration;

private:

	void OpenConnection();
	
};
