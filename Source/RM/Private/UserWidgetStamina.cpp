// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidgetStamina.h"
#include "PlayerCharacter.h"
#include "Kismet/GameplayStatics.h" // ��������� ������� �� ���������� class Gameplay.

float UUserWidgetStamina::GetCharacterStamina()
{
	APlayerCharacter* OurPlayer = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)); // ��������, �� PlayerCharacter - Character, � �� �� �����������(GetWorld), �� ����������� �� �������� 0.
	if (OurPlayer != nullptr) { // �����i��� �� character i����.

		float GetStamina = OurPlayer->Stamina / 100.f; // GetStamina = OurPlayer->Stamina(��������i���) / (���i����) �� 100. (������i� ����i���, ��� ���� ��� ������� �������� � HUD (� �������i HUD � 1, ��������i��� ��������� � 100, ��� ������� ��������, ����� ��� ����, ���� �� �i���� 1).)
		return GetStamina; // ���������� GetStamina.
	}
	else {
		return 0.0f;
	}
}
