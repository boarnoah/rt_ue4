// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IHttpRequest.h"
#include "RtRestSvc.generated.h"

class FHttpModule;
class IHttpRequest;

UCLASS()
class RT_API ARtRestSvc : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARtRestSvc();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FHttpModule* Http;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Configuration")
	FString APIBaseUrl = TEXT("http://localhost:8085/");
	
	TSharedRef<IHttpRequest> RequestWithRoute(FString Subroute);
	TSharedRef<IHttpRequest> GetRequest(FString Subroute);
	TSharedRef<IHttpRequest> PostRequest(FString Subroute, FString ContentJsonString);
	void Send(TSharedRef<IHttpRequest>& Request);
	bool ResponseIsValid(FHttpResponsePtr Response, bool bWasSuccessful);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};