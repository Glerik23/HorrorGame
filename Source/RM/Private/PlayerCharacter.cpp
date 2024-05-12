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
	MyPlayerInput->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::Jump); // Назначення клавiши Space у випадку, якщо вона натиснута для PlayerCharacter (вказання яким об'эктом буде здiйснятися управлiння).
	MyPlayerInput->BindAction("Jump", IE_Released, this, &APlayerCharacter::StopJump); // Назначення клавiши Space у випадку, якщо вона вiдпущенна для PlayerCharacter (вказання яким об'эктом буде здiйснятися управлiння).

	MyPlayerInput->BindAction("Crouch", IE_Pressed, this, &APlayerCharacter::Crouch); // Назначення клавiши Ctrl у випадку, якщо вона натиснута для PlayerCharacter (вказання яким об'эктом буде здiйснятися управлiння).
	MyPlayerInput->BindAction("Crouch", IE_Released, this, &APlayerCharacter::StopCrouch); // Назначення клавiши Ctrl у випадку, якщо вона вiдпущенна для PlayerCharacter (вказання яким об'эктом буде здiйснятися управлiння).

	// Миша
	MyPlayerInput->BindAction("Interact", IE_Pressed, this, &APlayerCharacter::Interact);

	MyPlayerInput->BindAxis("Turn", this, &APlayerCharacter::AddControllerYawInput); // Назначення перемiщення мишi по осi X (Turn) на перемiщення камери влiво/вправо для PlayerCharacter (вказання яким об'эктом буде здiйснятися управлiння).
	MyPlayerInput->BindAxis("LookUpDown", this, &APlayerCharacter::AddControllerPitchInput); // Назначення перемiщення мишi по осi Y (LookUpDown) на перемiщення вверх/вниз для PlayerCharacter (вказання яким об'эктом буде здiйснятися управлiння).

	// Shift (Бiг)
	MyPlayerInput->BindAction("Sprint", IE_Pressed, this, &APlayerCharacter::Sprint); // Назначення клавiши Shift у випадку, якщо вона натиснута для PlayerCharacter (вказання яким об'эктом буде здiйснятися управлiння).
	MyPlayerInput->BindAction("Sprint", IE_Released, this, &APlayerCharacter::StopSprint); // Назначення клавiши Shift у випадку, якщо вона вiдпущенна для PlayerCharacter (вказання яким об'эктом буде здiйснятися управлiння).


}

void APlayerCharacter::Interact()
{
	FVector Loc;
	FRotator Rot;
	FHitResult Hit;

	GetController()->GetPlayerViewPoint(Loc, Rot);

	FVector Start = Loc;
	FVector End = Start + (Rot.Vector() * 400); // Длина луча 400 единиц

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

	if (Hit.bBlockingHit && IsValid(Hit.GetComponent())) // Проверка компонента
	{
		UPrimitiveComponent* HitComponent = Hit.GetComponent(); // Получение компонента
		if (HitComponent->ComponentHasTag("Door"))
		{
			UE_LOG(LogTemp, Log, TEXT("Trace hit door component: %s"), *HitComponent->GetName());
			// ... (код для взаимодействия с дверью)
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
	bPressedJump = false; // Якщо Space вiдпущенно - нiчого.
}



// Бiг
void APlayerCharacter::Sprint()
{
	bIsSprint = true; // true - персонаж бiжить.
	GetCharacterMovement()->MaxWalkSpeed = 800.0f; // Максимальная швидкiсть при бiгi 800.

	DecreaseStamina();
}

void APlayerCharacter::StopSprint()
{
	bIsSprint = false;
	GetCharacterMovement()->MaxWalkSpeed = 400.0f; // Максимальная швидкiсть при ходьбi 400.

	IncreaseStamina();
}

void APlayerCharacter::Crouch() 
{
	ACharacter::Crouch(false); // Якщо клавiша Ctrl нажато - ciсти.
}


void APlayerCharacter::StopCrouch()
{
	ACharacter::UnCrouch(false); // Якщо клавiша Ctrl вiдпущенно - встати.
}

void APlayerCharacter::DecreaseStamina() // функцiя вiднiмання витривалостi.
{
	CurrentStamina = Stamina - MinusStamina; // CurrentStamina(значення кiлькостi витривалостi) = Stamina(установленна кiлькiсть наприклад - 100) - MinusStamina(установленна кiлькiсть наприклад - 1) | Формула для вiднiмання витривалостi.
	Stamina = CurrentStamina; // Повернення значення пiсля обрахунку.

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Stamina Deacreased %f"), Stamina)); // Виклик повiдомлення (-1 - постiйно, коли йде виклик ScreenDebugMessage), (5.f - скiлки секунд буде висіти повiдомлення), (FColor::Red - червоним кольором).
}

void APlayerCharacter::IncreaseStamina() // функцiя додавання витривалостi.
{
	if (bIsSprint == false) {
		CurrentStamina = Stamina + PlusStamina;// CurrentStamina(значення кiлькостi витривалостi) = Stamina(установленна кiлькiсть наприклад - 100) + PlusStamina(установленна кiлькiсть наприклад - 1) | Формула для додавання витривалостi.
		Stamina = CurrentStamina;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Stamina Increased %f"), Stamina)); // Виклик повiдомлення (-1 - постiйно, коли йде виклик ScreenDebugMessage), (5.f - скiлки секунд буде висіти повiдомлення), (FColor::Green - зеленим кольором).
	}
}

void APlayerCharacter::Tick(float DeltaTime) // Дii, якi вiдбуваются за 1 iгровий Tick.
{
	///////////////////////////////////////////////////////////////////////// Робота з бiгом /////////////////////////////////////////////////////////////////////////

	if (bIsSprint == true && Stamina != 0.f) { // Якщо натиснута кнопка бiгу та Stamina не дорiвнюэ 0, тодi зменшувати витривалiсть.
		DecreaseStamina();
	}
	else {
		// Вiдновлення витривалостi.
		if (bIsSprint == false && Stamina < 100) { // Якщо кнопка бiгу не натиснута, та витривалiсть меньше 100.
			if (CurrentStamina + PlusStamina <= 100) { // Якщо значення витривалостi + вiдновлення витривалостi не привисять 100 .
				CurrentStamina += PlusStamina; // Додавати витривалiсть до загального значення.
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Stamina Increased %f"), Stamina));
			}
			else {// Умова для запобігання безкінечному відновленню, якщо загальне значення більше 100.
				CurrentStamina = 100; // На випадок, якщо сумма загального значення витривалостi, та вiдновлення будуть бiльше 100, встановити загальному значенню 100.
			}
			Stamina = CurrentStamina; // Повернути значення.
		}
	}

	// Умови, щоб витривалiсть не пiшла в мiнус.
	if (bIsSprint == true && Stamina < 100) { // Якщо кнопка бiгу натиснута, та витривалiсть меньше 100.
		if (CurrentStamina - PlusStamina <= 0) { // Якщо загальне значення - додавання витривалостi <= 0.
			StopSprint(); // Зупинити бiг.
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Stamina = %f"), Stamina)); 
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}