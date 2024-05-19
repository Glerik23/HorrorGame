// Fill out your copyright notice in the Description page of Project Settings.


#include "LineTrace.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/Engine.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Actor.h"

// Sets default values
ULineTrace::ULineTrace()
{

}

// Called when the game starts or when spawned
void ULineTrace::BeginPlay()
{
	Super::BeginPlay();

}

AActor* ULineTrace::LineTraceSingle(FVector Start, FVector End)
{
	FHitResult HitResult;
	FCollisionObjectQueryParams CollisionParams;
	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActor(GetOwner());

	if (GetWorld()->LineTraceSingleByObjectType(
		OUT HitResult,
		Start,
		End,
		CollisionParams,
		CollisionQueryParams
	))
	{
		return HitResult.GetActor();
	}
	else {
		return nullptr;
	}
}

AActor* ULineTrace::LineTraceSingle(FVector Start, FVector End, bool ShowDebugLine){
	
	AActor* Actor = LineTraceSingle(Start, End);
	if (ShowDebugLine) {
		DrawDebugLine(
			GetWorld(),
			Start,
			End,
			FColor::Green,
			false,
			0.1f,
			0,
			5.0f
		);
	}
	return Actor;
}
