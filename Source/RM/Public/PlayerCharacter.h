// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class RM_API APlayerCharacter : public AMainCharacter
{
	GENERATED_BODY()

public:
		APlayerCharacter();
	UPROPERTY(VisibleAnywhere) // ������, ��� ������ �� ���������� � BP.
		USpringArmComponent* SpringArm; // "������" ��� ������ p i�'�� SpringArm.

	UPROPERTY(VisibleAnywhere) // ������, ��� ������ �� ���������� � BP.
		UCameraComponent* Camera; // ������.

};
