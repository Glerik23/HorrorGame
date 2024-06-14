// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Pickups.h"
#include "Inventory.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RM_API UInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventory();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Items")
		TArray<APickups*> Items;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UFUNCTION(BlueprintCallable)
		TArray<class APickups*> GetInventoryItems();

	UFUNCTION(BlueprintCallable)
		int32 GetCurrentInventoryCount();

	bool AddItem(class APickups* Item);
	void RemoveItem(class APickups* Item);
};
