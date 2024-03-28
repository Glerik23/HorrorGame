// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerGameMode.h"

APlayerGameMode::APlayerGameMode() : Super() {

	ConstructorHelpers::FClassFinder<APawn> MainCharacterPlayerCharacter(TEXT("/Game/Blueprints/BP_Player")); // Назначення iгровим персонажем BP_Player.

	DefaultPawnClass = MainCharacterPlayerCharacter.Class; // За замовченням BP_Player основний персонаж.
}