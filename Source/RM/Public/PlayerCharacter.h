// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Math/UnrealMathUtility.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class RM_API APlayerCharacter : public AMainCharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	UPROPERTY(VisibleAnywhere) // Макрос, щоб бачити та редагувати в BP.
		USpringArmComponent* SpringArm; // "Штатив" для камери з iм'ям SpringArm.

	UPROPERTY(VisibleAnywhere) // Макрос, щоб бачити та редагувати в BP.
		UCameraComponent* Camera; // Камера.


	virtual void SetupPlayerInputComponent(class UInputComponent* MyPlayerInput) override; // [Virtual] Оголошення функцii SetupPlayerInputComponent з class Pawn | оголошення MyPlayerInput з успадкуванням class UInputComponent | [override] перевезначення методу у class-спiдкоэмцi.

	// Перемiщення вперед/назад.
	void MoveForwardBackward(float Value); // Функцiя перемiщененя вперед/назад.

	// Перемiщення влiво/вправо.
	void MoveRightLeft(float Value); // Функцiя перемiщення вправо/влiво.

	// Стрибок
	void Jump(); // Функцiя стрибок.
	void StopJump(); // Функцiя зупинки стрибка.

	// Бiг
	void Sprint(); // Функцiя бiгу.
	void StopSprint(); // Функцiя зупинки бiгу.

	void Crouch();
	void StopCrouch();

	bool bIsSprint; // Бiжить/не бiжить.

	UPROPERTY(EditDefaultsOnly, Category = "Stamina", meta = (ClampMin = "0", ClampMax = "100")) // Вiдображення Stamina в Default в BP | Можливiсть виставлення в UE вiд 0 до 100.
	float Stamina = 100.0f; // Кількість витривалості.

	UPROPERTY(EditDefaultsOnly, Category = "Stamina") // Вiдображення PlusStamina в Default в BP(для редагування).
	float PlusStamina = 0.1f; // Кількість дадавання до CurrentStamina при при ходьбі.

	UPROPERTY(EditDefaultsOnly, Category = "Stamina") // Вiдображення MinusStamina в Default в BP(для редагування).
	float MinusStamina = 0.2f; // Кількість забирання від CurrentStamina при бігу.

	UPROPERTY(EditDefaultsOnly, Category = "Stamina") // Вiдображення CurrentStamina в Default в BP(для редагування).
	float CurrentStamina; // Змiнна яка зберiгаэ значення стамiни.

	void IncreaseStamina(); // Функцiя для додавання витривалостi.
	void DecreaseStamina(); // Функцiя для зменшення витривалості.

	virtual void Tick(float DeltaTime) override;

};