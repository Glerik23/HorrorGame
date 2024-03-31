// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

APlayerCharacter::APlayerCharacter() : Super() {

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent")); // ��������� ������� � ������ SpringArmComponent.
	SpringArm->SetupAttachment(RootComponent); // ��i��i������ SpringArm �� �������.
	SpringArm->TargetArmLength = 0.0f; 

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera")); // ��������� ������ � ������ PlayerCamera.
	Camera->SetupAttachment(SpringArm); // ��i��i������ ������ �� SpringArm.


	// ������i��� ������� �� ��i Y, �� �������� �������.
	SpringArm->bUsePawnControlRotation = true; // ��������������� ��������� �������� ��� ������.
	Camera->bUsePawnControlRotation = false; // �� ��������������� ���������� ������� �� �����.

}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* MyPlayerInput){ // ����'������ ������i���.

	Super::SetupPlayerInputComponent(MyPlayerInput); // ������ ������i ����i���i�i SetupPlayerInputComponent (������ ���i��).

	// ����i�����
	MyPlayerInput->BindAxis("MoveForwardBackward", this, &APlayerCharacter::MoveForwardBackward); // ���������� ����i� W/S (MoveForwardBackward) �� �����i����� ������/����� ��� PlayerCharacter (�������� ���� ��'����� ���� ��i�������� ������i���).
	MyPlayerInput->BindAxis("MoveRightLeft", this, &APlayerCharacter::MoveRightLeft); // ���������� ����i� A/D (MoveRightLeft) �� �����i����� ��i��/������ ��� PlayerCharacter (�������� ���� ��'����� ���� ��i�������� ������i���).
	MyPlayerInput->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::Jump); // ���������� ����i�� Space � �������, ���� ���� ������ ��� PlayerCharacter (�������� ���� ��'����� ���� ��i�������� ������i���).
	MyPlayerInput->BindAction("Jump", IE_Released, this, &APlayerCharacter::StopJump); // ���������� ����i�� Space � �������, ���� ���� �i�������� ��� PlayerCharacter (�������� ���� ��'����� ���� ��i�������� ������i���).
	/*
	MyPlayerInput->BindAction("Crouch", IE_Pressed, this, &APlayerCharacter::Crouch); //
	MyPlayerInput->BindAction("StopCrouch", IE_Released, this, &APlayerCharacter::StopCrouch); // 
	*/

	// ����
	MyPlayerInput->BindAxis("Turn", this, &APlayerCharacter::AddControllerYawInput); // ���������� �����i����� ���i �� ��i X (Turn) �� �����i����� ������ ��i��/������ ��� PlayerCharacter (�������� ���� ��'����� ���� ��i�������� ������i���).
	MyPlayerInput->BindAxis("LookUpDown", this, &APlayerCharacter::AddControllerPitchInput); // ���������� �����i����� ���i �� ��i Y (LookUpDown) �� �����i����� �����/���� ��� PlayerCharacter (�������� ���� ��'����� ���� ��i�������� ������i���).

	// Shift (�i�)
	MyPlayerInput->BindAction("Sprint", IE_Pressed, this, &APlayerCharacter::Sprint); // 
	MyPlayerInput->BindAction("StopSprint", IE_Released, this, &APlayerCharacter::StopSprint); // 


}

// �����i����� ������/�����/������/��i��.
void APlayerCharacter::MoveForwardBackward(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X); // ���������� ��i���i Direction � ����� Vector(����������) | RotationMatrix - ����������� ���� ����'������� �� ��'����[Player](�i���i������ ���� ������� �� ��i X, �� ��������� GetControlRotation. | GetScaledAxis - ��������� ���������� �� ��i X.
	AddMovementInput(Direction, Value); // �����i� ����� �� �������� Direction (�������� �� ��������� GetControlRotation), float ...(������� �� ��������� MoveForwardBackward [�i���i��� ��������� �������� float, �i���� event � ������i ���������i ������].
}

void APlayerCharacter::MoveRightLeft(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y); // ���������� ��i���i Direction � ����� Vector(����������) | RotationMatrix - ����������� ���� ����'������� �� ��'����[Player](�i���i������ ���� ������� �� ��i Y, �� ��������� GetControlRotation. | GetScaledAxis - ��������� ���������� �� ��i Y.
	AddMovementInput(Direction, Value); // �����i� ����� �� �������� Direction (�������� �� ��������� GetControlRotation), float ...(������� �� ��������� MoveForwardBackward [�i���i��� ��������� �������� float, �i���� event � ������i ���������i ������].
}



// �������
void APlayerCharacter::Jump()
{
	bPressedJump = true; // ���� Space ������ - �������.
}

void APlayerCharacter::StopJump()
{
	bPressedJump = false; // ���� Space �i�������� - �i����.
}



// �i�
void APlayerCharacter::Sprint()
{
}

void APlayerCharacter::StopSprint()
{
}

void APlayerCharacter::DeacreaseStamina()
{
}

void APlayerCharacter::IncreaseStamina()
{
}



/* 
void APlayerCharacter::Crouch()
{
	ACharacter::Crouch(false);
}


void APlayerCharacter::StopCrouch()
{
	ACharacter::Crouch(false);
}
*/