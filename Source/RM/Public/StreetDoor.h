// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StreetDoor.generated.h"

UCLASS()
class RM_API AStreetDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStreetDoor();

protected:
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* MeshComp;
	
	UPROPERTY(EditAnywhere)
		bool bDoorOpen;

	UPROPERTY(EditAnywhere)
		bool bDoorLocked;

	UPROPERTY(EditAnywhere)
		FRotator OpenRotation;
	
	UPROPERTY(EditAnywhere)
		FRotator ClosedRotation;

	FTimerHandle THDoor;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void RotateDoor();

public:	
	void ToggleDoor();
};
