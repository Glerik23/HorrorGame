// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups.h"
#include "Components/StaticMeshComponent.h"
#include "PlayerCharacter.h"
#include "Engine/Texture2D.h"

// Sets default values
APickups::APickups()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	RootComponent = MeshComp;

	Icon = CreateDefaultSubobject<UTexture2D>("IconTexture");
}

// Called when the game starts or when spawned
void APickups::BeginPlay()
{
	Super::BeginPlay();
	
}

void APickups::DestroyActor()
{
	Destroy();
}

void APickups::UseItem(APlayerCharacter* Player) {

	UE_LOG(LogTemp, Warning, TEXT("Object raised"))

	/// 

	DestroyActor();
}

UTexture2D* APickups::GetItemIcon()
{
	return Icon;
}
