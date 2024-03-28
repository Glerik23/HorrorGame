// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

APlayerCharacter::APlayerCharacter() : Super() {

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent")); // ��������� ������� � ������ SpringArmComponent.
	SpringArm->SetupAttachment(RootComponent); // ��i��i������ SpringArm �� �������.
	SpringArm->TargetArmLength = 0.0f; 

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera")); // ��������� ������ � ������ PlayerCamera.
	Camera->SetupAttachment(SpringArm); // ��i��i������ ������ �� SpringArm.
}