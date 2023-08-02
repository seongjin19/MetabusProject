// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AB_CharacterPlayer.h"
#include "Character/ABCharacterControlDataAsset.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AAB_CharacterPlayer::AAB_CharacterPlayer()
{
	GetCharacterMovement()->MaxAcceleration = 200.0f;

	//Camera
	CameraBoom = CreateDefaultSubobject<USpringArmComponent> (TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;//거리 지정
	CameraBoom->bUsePawnControlRotation = true; //Pawn이 회전을 했을 때 회전을 같이 사용할 것인지

	Camera = CreateDefaultSubobject<UCameraComponent> (TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	// Input
	/*static ConstructorHelpers::FObjectFinder<UInputMappingContext> InputMappingContextRef(TEXT("/Script/EnhancedInput.InputMappingContext'/Game/ArenaBattle/Input/IMC_Default.IMC_Default'"));
	if (InputMappingContextRef.Object)
	{
		DefaultMappingContext = InputMappingContextRef.Object;
	}*/

	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionJumpContextRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_Jump.IA_Jump'"));
	if (InputActionJumpContextRef.Object)
	{
		JumpAction = InputActionJumpContextRef.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionSholderMoveContextRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_SholderMove.IA_SholderMove'"));
	if (InputActionSholderMoveContextRef.Object)
	{
		SholderMoveAction = InputActionSholderMoveContextRef.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionQuaterMoveContextRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_QuaterMove.IA_QuaterMove'"));
	if (InputActionQuaterMoveContextRef.Object)
	{
		QuaterMoveAction = InputActionQuaterMoveContextRef.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionSholderLookContextRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/IA_SholderLook.IA_SholderLook'"));
	if (InputActionSholderLookContextRef.Object)
	{
		SholderLookAction = InputActionSholderLookContextRef.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> InputActionChangeControlRef(TEXT("/Script/EnhancedInput.InputAction'/Game/ArenaBattle/Input/Actions/ChangeControl.ChangeControl'"));
	if (InputActionChangeControlRef.Object)
	{
		ChangeControlAction = InputActionChangeControlRef.Object;
	}

	CurrentCharacterControlType = ECharactorControlType::Quater;
}

void AAB_CharacterPlayer::SetCharacterControlData(const UABCharacterControlDataAsset* CharacterControlData)
{
	Super::SetCharacterControlData(CharacterControlData);

	CameraBoom->TargetArmLength = CharacterControlData->TargetArmLength;

	CameraBoom->SetRelativeRotation(CharacterControlData->RelativeRotation);

	CameraBoom->bUsePawnControlRotation = CharacterControlData->bUsePawnControlRotation;

	CameraBoom->bDoCollisionTest = CharacterControlData->bDoCollisionTest;

	CameraBoom->bInheritPitch = CharacterControlData->bInheritPitch;

	CameraBoom->bInheritYaw = CharacterControlData->bInheritYaw;

	CameraBoom->bInheritRoll = CharacterControlData->bInheritRoll;
}

void AAB_CharacterPlayer::BeginPlay()
{
	/*Super::BeginPlay();

	APlayerController* PlayerController = CastChecked<APlayerController>(GetController());
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}*/

	Super::BeginPlay();

	SetCharactorControl(CurrentCharacterControlType);
}

void AAB_CharacterPlayer::SholderMove(const FInputActionValue& value)
{
	FVector2D MovementVector = value.Get<FVector2D>();

	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(ForwardDirection, MovementVector.Y);
	AddMovementInput(RightDirection, MovementVector.X);
}

void AAB_CharacterPlayer::SholderLook(const FInputActionValue& value)
{
	FVector2D LookAxisVector = value.Get<FVector2D>();

	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);
}

void AAB_CharacterPlayer::QuaterMove(const FInputActionValue& value)
{
	FVector2D MovementVector = value.Get<FVector2D>();
	float MovementVectorSizeSquared = MovementVector.SquaredLength();
	float MovementVectorSize = 1.0f;

	if (MovementVectorSizeSquared > 1.0f)
	{
		MovementVector.Normalize();
	}
	else
	{
		MovementVectorSize = FMath::Sqrt(MovementVectorSizeSquared);
	}

	FVector MoveDirection = FVector(MovementVector.X, MovementVector.Y, 0.0f);
	GetController()->SetControlRotation(FRotationMatrix::MakeFromX(MoveDirection).Rotator());
	AddMovementInput(MoveDirection, MovementVectorSize);
}

void AAB_CharacterPlayer::ChangeControl()
{
	if (CurrentCharacterControlType == ECharactorControlType::Sholder)
	{
		SetCharactorControl(ECharactorControlType::Quater);
	}
	else if (CurrentCharacterControlType == ECharactorControlType::Quater)
	{
		SetCharactorControl(ECharactorControlType::Sholder);
	}
}

void AAB_CharacterPlayer::SetCharactorControl(ECharactorControlType NewCharacterControlType)
{
	UABCharacterControlDataAsset* NewCharacterControl = CharacterControlManager[NewCharacterControlType];

	SetCharacterControlData(NewCharacterControl);

	APlayerController* PlayerController = CastChecked<APlayerController>(GetController());
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
	{
		Subsystem->ClearAllMappings();
		if (NewCharacterControl->InputMappingContext)
		{
			Subsystem->AddMappingContext(NewCharacterControl->InputMappingContext, 0);
		}
	}
	CurrentCharacterControlType = NewCharacterControlType;
}

void AAB_CharacterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// InputAction과 InputMappingContext를 연결
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	//CastChecked<>() = 올바르게 형변환이 되는지 체크

	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump); //점프 시작
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping); //점프 완료

	EnhancedInputComponent->BindAction(SholderMoveAction, ETriggerEvent::Triggered, this, &AAB_CharacterPlayer::SholderMove);

	EnhancedInputComponent->BindAction(QuaterMoveAction, ETriggerEvent::Triggered, this, &AAB_CharacterPlayer::QuaterMove);

	EnhancedInputComponent->BindAction(SholderLookAction, ETriggerEvent::Triggered, this, &AAB_CharacterPlayer::SholderLook);

	EnhancedInputComponent->BindAction(ChangeControlAction, ETriggerEvent::Triggered, this, &AAB_CharacterPlayer::ChangeControl);
	
}
