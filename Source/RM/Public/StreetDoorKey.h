// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickups.h"
#include "StreetDoorKey.generated.h"

/**
 * 
 */
UCLASS()
class RM_API AStreetDoorKey : public APickups
{
	GENERATED_BODY()

public:
	AStreetDoorKey();

protected:
	UPROPERTY(EditAnywhere)
		class AStreetDoor* LinkedDoor;

public:
	class AStreetDoor* GetLinkedDoor();

};
