// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerGameMode.h"

APlayerGameMode::APlayerGameMode() : Super() {

	ConstructorHelpers::FClassFinder<APawn> MainCharacterPlayerCharacter(TEXT("/Game/Blueprints/Player/BP_Player")); // Назначення iгровим персонажем BP_Player.

	DefaultPawnClass = MainCharacterPlayerCharacter.Class; // За замовчуванням BP_Player основний персонаж.
	HUDClass = ACharacterHUD::StaticClass(); // HUD за замовчуванням.

}