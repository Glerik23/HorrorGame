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
	MyPlayerInput->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::Jump); // ���������� ����i�� Space � �������, ���� ���� ��������� ��� PlayerCharacter (�������� ���� ��'����� ���� ��i�������� ������i���).
	MyPlayerInput->BindAction("Jump", IE_Released, this, &APlayerCharacter::StopJump); // ���������� ����i�� Space � �������, ���� ���� �i�������� ��� PlayerCharacter (�������� ���� ��'����� ���� ��i�������� ������i���).

	MyPlayerInput->BindAction("Crouch", IE_Pressed, this, &APlayerCharacter::Crouch); // ���������� ����i�� Ctrl � �������, ���� ���� ��������� ��� PlayerCharacter (�������� ���� ��'����� ���� ��i�������� ������i���).
	MyPlayerInput->BindAction("Crouch", IE_Released, this, &APlayerCharacter::StopCrouch); // ���������� ����i�� Ctrl � �������, ���� ���� �i�������� ��� PlayerCharacter (�������� ���� ��'����� ���� ��i�������� ������i���).

	// ����
	MyPlayerInput->BindAction("Interact", IE_Pressed, this, &APlayerCharacter::Interact);

	MyPlayerInput->BindAxis("Turn", this, &APlayerCharacter::AddControllerYawInput); // ���������� �����i����� ���i �� ��i X (Turn) �� �����i����� ������ ��i��/������ ��� PlayerCharacter (�������� ���� ��'����� ���� ��i�������� ������i���).
	MyPlayerInput->BindAxis("LookUpDown", this, &APlayerCharacter::AddControllerPitchInput); // ���������� �����i����� ���i �� ��i Y (LookUpDown) �� �����i����� �����/���� ��� PlayerCharacter (�������� ���� ��'����� ���� ��i�������� ������i���).

	// Shift (�i�)
	MyPlayerInput->BindAction("Sprint", IE_Pressed, this, &APlayerCharacter::Sprint); // ���������� ����i�� Shift � �������, ���� ���� ��������� ��� PlayerCharacter (�������� ���� ��'����� ���� ��i�������� ������i���).
	MyPlayerInput->BindAction("Sprint", IE_Released, this, &APlayerCharacter::StopSprint); // ���������� ����i�� Shift � �������, ���� ���� �i�������� ��� PlayerCharacter (�������� ���� ��'����� ���� ��i�������� ������i���).


}

void APlayerCharacter::Interact()
{
	FVector Loc;
	FRotator Rot;
	FHitResult Hit;

	GetController()->GetPlayerViewPoint(Loc, Rot);

	FVector Start = Loc;
	FVector End = Start + (Rot.Vector() * 400); // ����� ���� 400 ������

	FCollisionQueryParams TraceParams;

	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams);

	DrawDebugLine(
		GetWorld(),
		Start,
		End,
		FColor::Green,
		false,
		0.1f,
		0,
		3.f
	);

	if (Hit.bBlockingHit && IsValid(Hit.GetComponent())) // �������� ����������
	{
		UPrimitiveComponent* HitComponent = Hit.GetComponent(); // ��������� ����������
		if (HitComponent->ComponentHasTag("Door"))
		{
			UE_LOG(LogTemp, Log, TEXT("Trace hit door component: %s"), *HitComponent->GetName());
			// ... (��� ��� �������������� � ������)
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("Trace hit actor: %s, but it's not a door"), *HitComponent->GetName());
		}
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("No Actors were hit"));
	}
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
	bIsSprint = true; // true - �������� �i����.
	GetCharacterMovement()->MaxWalkSpeed = 800.0f; // ������������ �����i��� ��� �i�i 800.

	DecreaseStamina();
}

void APlayerCharacter::StopSprint()
{
	bIsSprint = false;
	GetCharacterMovement()->MaxWalkSpeed = 400.0f; // ������������ �����i��� ��� �����i 400.

	IncreaseStamina();
}

void APlayerCharacter::Crouch() 
{
	ACharacter::Crouch(false); // ���� ����i�� Ctrl ������ - ci���.
}


void APlayerCharacter::StopCrouch()
{
	ACharacter::UnCrouch(false); // ���� ����i�� Ctrl �i�������� - ������.
}

void APlayerCharacter::DecreaseStamina() // �����i� �i��i����� �����������i.
{
	CurrentStamina = Stamina - MinusStamina; // CurrentStamina(�������� �i������i �����������i) = Stamina(������������ �i���i��� ��������� - 100) - MinusStamina(������������ �i���i��� ��������� - 1) | ������� ��� �i��i����� �����������i.
	Stamina = CurrentStamina; // ���������� �������� �i��� ���������.

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Stamina Deacreased %f"), Stamina)); // ������ ���i�������� (-1 - ����i���, ���� ��� ������ ScreenDebugMessage), (5.f - ��i��� ������ ���� ����� ���i��������), (FColor::Red - �������� ��������).
}

void APlayerCharacter::IncreaseStamina() // �����i� ��������� �����������i.
{
	if (bIsSprint == false) {
		CurrentStamina = Stamina + PlusStamina;// CurrentStamina(�������� �i������i �����������i) = Stamina(������������ �i���i��� ��������� - 100) + PlusStamina(������������ �i���i��� ��������� - 1) | ������� ��� ��������� �����������i.
		Stamina = CurrentStamina;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Stamina Increased %f"), Stamina)); // ������ ���i�������� (-1 - ����i���, ���� ��� ������ ScreenDebugMessage), (5.f - ��i��� ������ ���� ����� ���i��������), (FColor::Green - ������� ��������).
	}
}

void APlayerCharacter::Tick(float DeltaTime) // �ii, ��i �i��������� �� 1 i������ Tick.
{
	///////////////////////////////////////////////////////////////////////// ������ � �i��� /////////////////////////////////////////////////////////////////////////

	if (bIsSprint == true && Stamina != 0.f) { // ���� ��������� ������ �i�� �� Stamina �� ���i���� 0, ���i ���������� ��������i���.
		DecreaseStamina();
	}
	else {
		// �i��������� �����������i.
		if (bIsSprint == false && Stamina < 100) { // ���� ������ �i�� �� ���������, �� ��������i��� ������ 100.
			if (CurrentStamina + PlusStamina <= 100) { // ���� �������� �����������i + �i��������� �����������i �� ��������� 100 .
				CurrentStamina += PlusStamina; // �������� ��������i��� �� ���������� ��������.
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Stamina Increased %f"), Stamina));
			}
			else {// ����� ��� ���������� ����������� ����������, ���� �������� �������� ����� 100.
				CurrentStamina = 100; // �� �������, ���� ����� ���������� �������� �����������i, �� �i��������� ������ �i���� 100, ���������� ���������� �������� 100.
			}
			Stamina = CurrentStamina; // ��������� ��������.
		}
	}

	// �����, ��� ��������i��� �� �i��� � �i���.
	if (bIsSprint == true && Stamina < 100) { // ���� ������ �i�� ���������, �� ��������i��� ������ 100.
		if (CurrentStamina - PlusStamina <= 0) { // ���� �������� �������� - ��������� �����������i <= 0.
			StopSprint(); // �������� �i�.
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Stamina = %f"), Stamina)); 
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}