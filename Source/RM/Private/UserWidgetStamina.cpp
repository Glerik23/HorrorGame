// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidgetStamina.h"
#include "PlayerCharacter.h"
#include "Kismet/GameplayStatics.h" // Бібліотека сценаріїв та статичного class Gameplay.

float UUserWidgetStamina::GetCharacterStamina()
{
	APlayerCharacter* OurPlayer = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)); // Перевірка, чи PlayerCharacter - Character, і де він знаходиться(GetWorld), та знаходиться під індексом 0.
	if (OurPlayer != nullptr) { // Перевiрка що character iснуэ.

		float GetStamina = OurPlayer->Stamina / 100.f; // GetStamina = OurPlayer->Stamina(витривалiсть) / (подiлена) на 100. (операцiя потрiбна, для того щоб вывести значення в HUD (в значеннi HUD э 1, витривалiсть персонажу э 100, щоб вивести значення, треба щоб воно, було не бiльше 1).)
		return GetStamina; // Повернення GetStamina.
	}
	else {
		return 0.0f;
	}
}
