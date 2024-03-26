// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h" // �i��������� header �����.
#include "Kismet/GameplayStatics.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CharacterStamina = 100.0f;

}

float AMainCharacter::GetStaminaPercent() // ���������� ������� � AMainCharacter.h. (��������� GetStaminaPercent � AMainCharacter.h)
{
	return CharacterStamina;
}

float AMainCharacter::AddStamina() // ���������� ������� � AMainCharacter.h. (��������� AddStamina � AMainCharacter.h)
{
	return 0.0f;
}

float AMainCharacter::DeacreaseStamina() // ���������� ������� � AMainCharacter.h. (��������� DeacreaseStamina � AMainCharacter.h)
{
	return 0.0f;
}

bool AMainCharacter::StaminaZero() // ���������� ������� � AMainCharacter.h. (��������� StaminaZero � AMainCharacter.h)
{
	if (CharacterStamina <= 0) { // ���� ����i�� <= 0, bIsTired = true (�������� ��������).

		bIsTired = true;


	}
	else {
		bIsTired = false;
	}

	UGameplayStatics::SpawnSoundAtLocation(this, TiredSound, GetActorLocation()); // ³�������� ���� ��� ���������.

	return bIsTired; // ���������� �������� bIsTired.
}