// Fill out your copyright notice in the Description page of Project Settings.

#pragma once // Пiдключення бiблiотеки та файлiв 1 раз.

#include "CoreMinimal.h" // Ядро UE.
#include "GameFramework/Character.h" // Пiдключення class Character.
#include "MainCharacter.generated.h" // Генератор коду для UE (обов'язково остання в пiдключеннi).

UCLASS() // Макрос що пояснює UE, що нижче йде class.
class RM_API AMainCharacter : public ACharacter // Пiдключення API для клонування class ACharacter для нового.
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	float CharacterStamina; // Витривалість персонажу.
	float GetStaminaPercent(); // Функцiя, яка буде повертати значення float.
	float AddStamina(); // Функцiя, яка буде повертати витривалiсть.
	float DeacreaseStamina(); // Функцiя, яка буде вiднiмати витривалiсть.

	bool StaminaZero(); // Функція, яка не дозволяє бігати за відсутності витривалості.

	USoundBase* TiredSound; // Змiнна, для вiдтворення звуку, за вiдсутностi витривалостi (Покажчик * - якщо об'єкт iснує: виконувати код).

	
};