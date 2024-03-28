// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

APlayerCharacter::APlayerCharacter() : Super() {

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent")); // Створення штативу з назвою SpringArmComponent.
	SpringArm->SetupAttachment(RootComponent); // Прiкрiплення SpringArm до капсули.
	SpringArm->TargetArmLength = 0.0f; 

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera")); // Створення камери з назвою PlayerCamera.
	Camera->SetupAttachment(SpringArm); // Прiкрiплення камери до SpringArm.
}