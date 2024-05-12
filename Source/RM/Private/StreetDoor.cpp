// Fill out your copyright notice in the Description page of Project Settings.


#include "StreetDoor.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AStreetDoor::AStreetDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject <UStaticMeshComponent>("StaticMeshComponent");


	OpenRotation = FRotator::ZeroRotator;
	ClosedRotation = FRotator::ZeroRotator;
	bDoorOpen = false;

}

// Called when the game starts or when spawned
void AStreetDoor::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(THDoor, this, &AStreetDoor::RotateDoor, 0.1f, true);
	GetWorld()->GetTimerManager().PauseTimer(THDoor);
	
}

void AStreetDoor::OnRep_ToggleDoor()
{
	GetWorld()->GetTimerManager().UnPauseTimer(THDoor);
}

void AStreetDoor::RotateDoor()
{
	if (bDoorOpen) 
	{
		this->SetActorRotation(OpenRotation);
		GetWorld()->GetTimerManager().PauseTimer(THDoor);
	}
	else 
	{
		this->SetActorRotation(ClosedRotation);
		GetWorld()->GetTimerManager().PauseTimer(THDoor);
	}

}

void AStreetDoor::ToggleDoor()
{
	bDoorOpen = !bDoorOpen;
	OnRep_ToggleDoor();
}
