// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerGameMode.h"

APlayerGameMode::APlayerGameMode() : Super() {

	ConstructorHelpers::FClassFinder<APawn> MainCharacterPlayerCharacter(TEXT("/Game/Blueprints/Player/BP_Player")); // ���������� i������ ���������� BP_Player.

	DefaultPawnClass = MainCharacterPlayerCharacter.Class; // �� ������������� BP_Player �������� ��������.
	HUDClass = ACharacterHUD::StaticClass(); // HUD �� �������������.

}

// Respawn

/*void APlayerGameMode::Respawn(AController* Controller) {

	UE_LOG(LogTemp, Warning, TEXT("Respawn"));
}*/