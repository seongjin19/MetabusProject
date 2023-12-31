// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AB_CharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputMappingContext.h"
#include "Character/ABCharacterControlDataAsset.h"

// Sets default values
AAB_CharacterBase::AAB_CharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	// Capsule Commponent
	GetCapsuleComponent()->InitCapsuleSize(35.0f, 90.0f);
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Pawn"));

	// SkeletalMesh Component
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -90.0f), FRotator(0.0f, -90.0f, 0.0f));
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	GetMesh()->SetCollisionProfileName(TEXT("CharacerMesh"));

	// CharacterMovement Component
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // 한번에 바뀌는 로테이션 값
	GetCharacterMovement()->JumpZVelocity = 500.0f; // 점프 수치
	GetCharacterMovement()->AirControl = 0.35f; // 공중에서의 감속, 이동
	GetCharacterMovement()->MaxWalkSpeed = 500.0f;  
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.0f; 
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.0f; //이동하다 멈출 때 제동 수치

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> CharacterMeshRef(TEXT("/Script/Engine.SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Forge.SK_CharM_Forge'"));
	if (CharacterMeshRef.Object)
	{
		GetMesh()->SetSkeletalMesh(CharacterMeshRef.Object);
	}

	static ConstructorHelpers::FClassFinder<UAnimInstance> CharacterAnimRef(TEXT("/Game/Animation/ABP_Player.ABP_Player_C"));
	if (CharacterAnimRef.Class)
	{
		GetMesh()->SetAnimInstanceClass(CharacterAnimRef.Class);
	}

	static ConstructorHelpers::FObjectFinder<UABCharacterControlDataAsset> SholderDataRef(TEXT("/Script/ABattle.ABCharacterControlDataAsset'/Game/ArenaBattle/CharacterControl/ABC_Sholder.ABC_Sholder'"));
	if (SholderDataRef.Object)
	{
		CharacterControlManager.Add(ECharactorControlType::Sholder, SholderDataRef.Object);
	}

	static ConstructorHelpers::FObjectFinder<UABCharacterControlDataAsset> QuaterDataRef(TEXT("/Script/ABattle.ABCharacterControlDataAsset'/Game/ArenaBattle/CharacterControl/ABC_Quater.ABC_Quater'"));
	if (QuaterDataRef.Object)
	{
		CharacterControlManager.Add(ECharactorControlType::Quater, QuaterDataRef.Object);
	}
}

// Called when the game starts or when spawned
void AAB_CharacterBase::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AAB_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAB_CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAB_CharacterBase::SetCharacterControlData(const UABCharacterControlDataAsset* CharacterControlData)
{
	bUseControllerRotationYaw = CharacterControlData->bUseControlRotationYaw;
	
	bUseControllerRotationPitch = CharacterControlData->bUseControlRotationPitch;

	bUseControllerRotationRoll = CharacterControlData->bUseControlRotationRoll;

	GetCharacterMovement()->RotationRate = CharacterControlData->RotationRate;

	GetCharacterMovement()->bUseControllerDesiredRotation = CharacterControlData->bUseControllerDesiredRotation;

	GetCharacterMovement()->bOrientRotationToMovement = CharacterControlData->bOrientRotationToMovement;
}

