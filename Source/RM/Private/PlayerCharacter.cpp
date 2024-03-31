// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

APlayerCharacter::APlayerCharacter() : Super() {

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent")); // Створення штативу з назвою SpringArmComponent.
	SpringArm->SetupAttachment(RootComponent); // Прiкрiплення SpringArm до капсули.
	SpringArm->TargetArmLength = 0.0f; 

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera")); // Створення камери з назвою PlayerCamera.
	Camera->SetupAttachment(SpringArm); // Прiкрiплення камери до SpringArm.


	// Управлiння камерою по осi Y, та усунення проблем.
	SpringArm->bUsePawnControlRotation = true; // Використовувати керування штативом для камери.
	Camera->bUsePawnControlRotation = false; // Не використовувати керуванняч камерою на пряму.

}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* MyPlayerInput){ // Прив'язання управлiння.

	Super::SetupPlayerInputComponent(MyPlayerInput); // Виклик базовоi реалiзацiэi SetupPlayerInputComponent (базова логiка).

	// Клавiатура
	MyPlayerInput->BindAxis("MoveForwardBackward", this, &APlayerCharacter::MoveForwardBackward); // Назначення клавiш W/S (MoveForwardBackward) на перемiщення вперед/назад для PlayerCharacter (вказання яким об'эктом буде здiйснятися управлiння).
	MyPlayerInput->BindAxis("MoveRightLeft", this, &APlayerCharacter::MoveRightLeft); // Назначення клавiш A/D (MoveRightLeft) на перемiщення влiво/вправо для PlayerCharacter (вказання яким об'эктом буде здiйснятися управлiння).
	MyPlayerInput->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::Jump); // Назначення клавiши Space у випадку, якщо вона нажата для PlayerCharacter (вказання яким об'эктом буде здiйснятися управлiння).
	MyPlayerInput->BindAction("Jump", IE_Released, this, &APlayerCharacter::StopJump); // Назначення клавiши Space у випадку, якщо вона вiдпущенна для PlayerCharacter (вказання яким об'эктом буде здiйснятися управлiння).
	/*
	MyPlayerInput->BindAction("Crouch", IE_Pressed, this, &APlayerCharacter::Crouch); //
	MyPlayerInput->BindAction("StopCrouch", IE_Released, this, &APlayerCharacter::StopCrouch); // 
	*/

	// Миша
	MyPlayerInput->BindAxis("Turn", this, &APlayerCharacter::AddControllerYawInput); // Назначення перемiщення мишi по осi X (Turn) на перемiщення камери влiво/вправо для PlayerCharacter (вказання яким об'эктом буде здiйснятися управлiння).
	MyPlayerInput->BindAxis("LookUpDown", this, &APlayerCharacter::AddControllerPitchInput); // Назначення перемiщення мишi по осi Y (LookUpDown) на перемiщення вверх/вниз для PlayerCharacter (вказання яким об'эктом буде здiйснятися управлiння).

	// Shift (Бiг)
	MyPlayerInput->BindAction("Sprint", IE_Pressed, this, &APlayerCharacter::Sprint); // 
	MyPlayerInput->BindAction("StopSprint", IE_Released, this, &APlayerCharacter::StopSprint); // 


}

// Перемiщення вперед/назад/вправо/влiво.
void APlayerCharacter::MoveForwardBackward(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X); // Оголошення змiнноi Direction з типом Vector(координати) | RotationMatrix - конструктор який прив'язанний до об'экту[Player](вiдслiдковуэ його поворот по осi X, за допомогою GetControlRotation. | GetScaledAxis - отримуэмо координати по осi X.
	AddMovementInput(Direction, Value); // Функцiя додаэ до значення Direction (отримане за допомогою GetControlRotation), float ...(введене за допомогою MoveForwardBackward [кiлькiсть зчитаного значення float, пiдчас event в виглядi натиснутоi кнопки].
}

void APlayerCharacter::MoveRightLeft(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y); // Оголошення змiнноi Direction з типом Vector(координати) | RotationMatrix - конструктор який прив'язанний до об'экту[Player](вiдслiдковуэ його поворот по осi Y, за допомогою GetControlRotation. | GetScaledAxis - отримуэмо координати по осi Y.
	AddMovementInput(Direction, Value); // Функцiя додаэ до значення Direction (отримане за допомогою GetControlRotation), float ...(введене за допомогою MoveForwardBackward [кiлькiсть зчитаного значення float, пiдчас event в виглядi натиснутоi кнопки].
}



// Стрибок
void APlayerCharacter::Jump()
{
	bPressedJump = true; // Якщо Space нажато - стрибок.
}

void APlayerCharacter::StopJump()
{
	bPressedJump = false; // Якщо Space вiдпещенно - нiчого.
}



// Бiг
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