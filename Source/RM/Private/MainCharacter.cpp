// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h" // Пiдключення header файлу.
#include "Kismet/GameplayStatics.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CharacterStamina = 100.0f;

}

float AMainCharacter::GetStaminaPercent() // Викликання функції з AMainCharacter.h. (Отримання GetStaminaPercent з AMainCharacter.h)
{
	return CharacterStamina;
}

float AMainCharacter::AddStamina() // Викликання функції з AMainCharacter.h. (Отримання AddStamina з AMainCharacter.h)
{
	return 0.0f;
}

float AMainCharacter::DeacreaseStamina() // Викликання функції з AMainCharacter.h. (Отримання DeacreaseStamina з AMainCharacter.h)
{
	return 0.0f;
}

bool AMainCharacter::StaminaZero() // Викликання функції з AMainCharacter.h. (Отримання StaminaZero з AMainCharacter.h)
{
	if (CharacterStamina <= 0) { // Якщо стамiна <= 0, bIsTired = true (персонаж втомився).

		bIsTired = true;


	}
	else {
		bIsTired = false;
	}

	UGameplayStatics::SpawnSoundAtLocation(this, TiredSound, GetActorLocation()); // Відтворити звук біля персонажа.

	return bIsTired; // повернення значення bIsTired.
}