// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickups.generated.h"

UCLASS()
class RM_API APickups : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APickups();

protected:
	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere)
		class UTexture2D* Icon;

protected:
	// Called when the game starts or when 
	virtual void BeginPlay() override;

	void DestroyActor();

public:

	// œ≥‰ÈÓÏ Ó·'∫ÍÚÛ
	void UseItem(class APlayerCharacter* Player);

	UFUNCTION(BlueprintCallable)
	class UTexture2D* GetItemIcon();
};