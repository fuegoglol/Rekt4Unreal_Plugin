// Fill out your copyright notice in the Description page of Project Settings.


#include "R4UToolBoxSubsystem.h"

#include "Settings/RPSettings.h"
#include "Sockets/R4USocket.h"

void UR4UToolBoxSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	// setup vars from settings
	if(const URPSettings * Plugin_Settings = GetDefault<URPSettings>())
	{
		RemoteIp = Plugin_Settings->IP;
		UdpPort = Plugin_Settings->Port;
		IdleTimeoutMs = Plugin_Settings->IdleTimeoutMs;
		SendBufferLength = Plugin_Settings->SendBufferLength;
	}

	QUIC_STATUS Status = QUIC_STATUS_SUCCESS;
	
	//
	// Open a handle to the library and get the API function table.
	//
	if (QUIC_FAILED(Status = MsQuicOpen2(&MsQuic))) {
		printf("MsQuicOpen2 failed, 0x%lx!\n", Status);
		goto Error;
	}

	OpenConnection();

	Error:

		if (MsQuic != NULL) {
			if (Configuration != NULL) {
				MsQuic->ConfigurationClose(Configuration);
			}
			if (Registration != NULL) {
				//
				// This will block until all outstanding child objects have been
				// closed.
				//
				MsQuic->RegistrationClose(Registration);
			}
			MsQuicClose(MsQuic);
		}

	
}

void UR4UToolBoxSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UR4UToolBoxSubsystem::OpenConnection()
{
	const R4USocket* Socket = new R4USocket(MsQuic,Registration,Configuration,RemoteIp,UdpPort);
}
