// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterHUD.h"
#include "Blueprint/UserWidget.h"

ACharacterHUD::ACharacterHUD() : Super() // ������ ����i���i� | ������������ �i� �������� ����� HUD.
{
	ConstructorHelpers::FClassFinder<UUserWidget> WBPStamina(TEXT("/Game/Blueprints/WBP_Stamina")); // �������� �� ����������� WPStamina.

	MainHUD = WBPStamina.Class; // ��i��� � class Widget = WBPStamina.

}

void ACharacterHUD::BeginPlay()
{
	Super::BeginPlay(); //������ ����i���i� BeginPlay, ��� �������� �������� �������.

	UUserWidget* CharacterWidget = CreateWidget(GetWorld(), MainHUD); // ��������� Widget MainHUD.
	CharacterWidget->AddToViewport(); // ������� Widget � Viewport.
}
