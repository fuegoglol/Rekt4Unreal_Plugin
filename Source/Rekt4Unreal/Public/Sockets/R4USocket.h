// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "inc/msquic.h"
#include "Common/UdpSocketReceiver.h"

/**
 * 
 */

class REKT4UNREAL_API R4USocket
{

public:
	
	R4USocket(const QUIC_API_TABLE* MsQuic, HQUIC Registration, HQUIC Configuration, const FString& RemoteIp,
	          int32 RemotePort);
	
	bool SendDataTo(const TArray<uint8>& Bytes, const FString& RemoteIp, const int32 RemotePort);

protected:

	static HRESULT ClientConnectionCallback(HQUIC Connection, void* Context, QUIC_CONNECTION_EVENT* Event);

private:

	FSocket* ListenSocket;

	QUIC_CONNECTION_CALLBACK_HANDLER ConnectionOpenHandler;
};

inline HRESULT R4USocket::ClientConnectionCallback(HQUIC Connection, void* Context, QUIC_CONNECTION_EVENT* Event)
{
}
