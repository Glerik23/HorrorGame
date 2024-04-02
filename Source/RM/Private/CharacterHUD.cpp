// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterHUD.h"
#include "Blueprint/UserWidget.h"

ACharacterHUD::ACharacterHUD() : Super() // Базова реалiзацiя | успадкування вiд базового класу HUD.
{
	ConstructorHelpers::FClassFinder<UUserWidget> WBPStamina(TEXT("/Game/Blueprints/WBP_Stamina")); // Указання де знаходиться WPStamina.

	MainHUD = WBPStamina.Class; // Змiнна з class Widget = WBPStamina.

}

void ACharacterHUD::BeginPlay()
{
	Super::BeginPlay(); //Базова реалiзацiя BeginPlay, для усунення можливих проблем.

	UUserWidget* CharacterWidget = CreateWidget(GetWorld(), MainHUD); // Створення Widget MainHUD.
	CharacterWidget->AddToViewport(); // Додання Widget в Viewport.
}
