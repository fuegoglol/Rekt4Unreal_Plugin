// Fill out your copyright notice in the Description page of Project Settings.


#include "Sockets/R4USocket.h"
#include "MsQuic/msquic/src/core/library.h"

R4USocket::R4USocket(const QUIC_API_TABLE* MsQuic, HQUIC Registration, HQUIC Configuration, const FString& RemoteIp, const int32 RemotePort)
{
	QUIC_STATUS Status;
	const char* ResumptionTicketString = NULL;
	HQUIC Connection = NULL;

	//
	// Allocate a new connection object.
	//
	if (QUIC_FAILED(Status = MsQuic->ConnectionOpen(Registration, &R4USocket::ClientConnectionCallback, NULL, &Connection))) {
		printf("ConnectionOpen failed, 0x%x!\n", Status);
		goto Error;
	}

	printf("[conn][%p] Connecting...\n", Connection);

	//
	// Start the connection to the server.
	//
	if (QUIC_FAILED(Status = MsQuic->ConnectionStart(Connection, Configuration, QUIC_ADDRESS_FAMILY_UNSPEC, reinterpret_cast<char*>(**RemoteIp), RemotePort))) {
		printf("ConnectionStart failed, 0x%x!\n", Status);
		goto Error;
	}

	Error:

		if (QUIC_FAILED(Status) && Connection != nullptr) {
			MsQuic->ConnectionClose(Connection);
		}
	
}

bool R4USocket::SendDataTo(const TArray<uint8>& Bytes, const FString& RemoteIp, const int32 RemotePort)
{
	return  true;
}


