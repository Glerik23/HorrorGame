// Fill out your copyright notice in the Description page of Project Settings.

#pragma once // �i��������� �i��i����� �� ����i� 1 ���.

#include "CoreMinimal.h" // ���� UE.
#include "GameFramework/Character.h" // �i��������� class Character.
#include "MainCharacter.generated.h" // ��������� ���� ��� UE (����'������ ������� � �i��������i).

UCLASS() // ������ �� ������� UE, �� ����� ��� class.
class RM_API AMainCharacter : public ACharacter // �i��������� API ��� ���������� class ACharacter ��� ������.
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	float CharacterStamina; // ����������� ���������.
	float GetStaminaPercent(); // �����i�, ��� ���� ��������� �������� float.
	float AddStamina(); // �����i�, ��� ���� ��������� ��������i���.
	float DeacreaseStamina(); // �����i�, ��� ���� �i��i���� ��������i���.

	bool StaminaZero(); // �������, ��� �� �������� ����� �� ��������� �����������.

	USoundBase* TiredSound; // ��i���, ��� �i��������� �����, �� �i��������i �����������i (�������� * - ���� ��'��� i���: ���������� ���).

	
};