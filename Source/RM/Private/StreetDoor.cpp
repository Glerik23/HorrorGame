// Fill out your copyright notice in the Description page of Project Settings.

#include "StreetDoor.h"
#include "Inventory.h"
#include "PlayerCharacter.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AStreetDoor::AStreetDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject <UStaticMeshComponent>("StaticMeshComponent");


	OpenRotation = FRotator::ZeroRotator;
	ClosedRotation = FRotator::ZeroRotator;

	bDoorOpen = false;
	bDoorLocked = false;
}

// Called when the game starts or when spawned
void AStreetDoor::BeginPlay()
{
	Super::BeginPlay();

	//ClosedRotation = this->GetActorRotation();

	GetWorld()->GetTimerManager().SetTimer(THDoor, this, &AStreetDoor::RotateDoor, 0.1f, true);
	GetWorld()->GetTimerManager().PauseTimer(THDoor);
	
}

void AStreetDoor::RotateDoor()
{
	if (bDoorOpen)
	{
		this->SetActorRotation(OpenRotation);
		GetWorld()->GetTimerManager().PauseTimer(THDoor);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Door open")));
	}
	else
	{
		this->SetActorRotation(ClosedRotation);
		GetWorld()->GetTimerManager().PauseTimer(THDoor);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Door closed")));
	}

}


void AStreetDoor::ToggleDoor()
{
	if (bDoorLocked) 
	{
		/*if (UInventory* PlayersInventory = Player->GetInventoryComponent())
		{
			UE_LOG(LogTemp, Warning, TEXT("GOT INVENTORY COMPONENT"));
		}*/
	}
	else
	{
	bDoorOpen = !bDoorOpen;
	GetWorld()->GetTimerManager().UnPauseTimer(THDoor);
	}
}