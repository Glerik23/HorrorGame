// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"
#include "Pickups.h"
#include "Components/StaticMeshComponent.h"

// Sets default values for this component's properties
UInventory::UInventory()
{

}


// Called when the game starts
void UInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...

}

TArray<class APickups*> UInventory::GetInventoryItems()
{
	return Items;
}

int32 UInventory::GetCurrentInventoryCount()
{
	return Items.Num() - 1;
}

bool UInventory::AddItem(APickups* Item)
{
	Items.Add(Item);

	for (APickups* Pickup : Items) {

		UE_LOG(LogTemp, Warning, TEXT("Item: %s"), *Pickup->GetName());
	}

	UE_LOG(LogTemp, Warning, TEXT("END OF ITEMS"));
	return false;
}

void UInventory::RemoveItem(APickups* Item)
{
	Items.Remove(Item);
}
