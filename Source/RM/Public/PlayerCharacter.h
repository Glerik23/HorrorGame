// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Math/UnrealMathUtility.h"
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
		USpringArmComponent* SpringArm; // "������" ��� ������ � i�'�� SpringArm.

	UPROPERTY(VisibleAnywhere) // ������, ��� ������ �� ���������� � BP.
		UCameraComponent* Camera; // ������.


	virtual void SetupPlayerInputComponent(class UInputComponent* MyPlayerInput) override; // [Virtual] ���������� �����ii SetupPlayerInputComponent � class Pawn | ���������� MyPlayerInput � ������������� class UInputComponent | [override] �������������� ������ � class-��i������i.

	// �����i����� ������/�����.
	void MoveForwardBackward(float Value); // �����i� �����i������ ������/�����.

	// �����i����� ��i��/������.
	void MoveRightLeft(float Value); // �����i� �����i����� ������/��i��.

	// �������
	void Jump(); // �����i� �������.
	void StopJump(); // �����i� ������� �������.

	// �i�
	void Sprint(); // �����i� �i��.
	void StopSprint(); // �����i� ������� �i��.

	void Crouch();
	void StopCrouch();

	bool bIsSprint; // �i����/�� �i����.

	UPROPERTY(EditDefaultsOnly, Category = "Stamina", meta = (ClampMin = "0", ClampMax = "100")) // �i���������� Stamina � Default � BP | ������i��� ����������� � UE �i� 0 �� 100.
	float Stamina = 100.0f; // ʳ������ �����������.

	UPROPERTY(EditDefaultsOnly, Category = "Stamina") // �i���������� PlusStamina � Default � BP(��� �����������).
	float PlusStamina = 0.1f; // ʳ������ ��������� �� CurrentStamina ��� ��� �����.

	UPROPERTY(EditDefaultsOnly, Category = "Stamina") // �i���������� MinusStamina � Default � BP(��� �����������).
	float MinusStamina = 0.2f; // ʳ������ ��������� �� CurrentStamina ��� ���.

	UPROPERTY(EditDefaultsOnly, Category = "Stamina") // �i���������� CurrentStamina � Default � BP(��� �����������).
	float CurrentStamina; // ��i��� ��� ����i��� �������� ����i��.

	void IncreaseStamina(); // �����i� ��� ��������� �����������i.
	void DecreaseStamina(); // �����i� ��� ��������� �����������.

	virtual void Tick(float DeltaTime) override;

};