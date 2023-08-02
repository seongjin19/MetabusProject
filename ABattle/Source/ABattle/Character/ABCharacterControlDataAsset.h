// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ABCharacterControlDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class ABATTLE_API UABCharacterControlDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UABCharacterControlDataAsset();

	UPROPERTY(EditAnywhere, category = Pawn)
	// bool 타입을 정의하기 위해서 앞에 b를 넣어줌(표시) / 데이터 사이즈를 확정짓기 위해 int 사용
	uint32 bUseControlRotationYaw : 1;

	UPROPERTY(EditAnywhere, category = Pawn)
		// bool 타입을 정의하기 위해서 앞에 b를 넣어줌(표시) / 데이터 사이즈를 확정짓기 위해 int 사용
	uint32 bUseControlRotationPitch : 1;

	UPROPERTY(EditAnywhere, category = Pawn)
		// bool 타입을 정의하기 위해서 앞에 b를 넣어줌(표시) / 데이터 사이즈를 확정짓기 위해 int 사용
	uint32 bUseControlRotationRoll : 1;

	UPROPERTY(EditAnywhere, category = CharacterMovement)
	FRotator RotationRate;


	UPROPERTY(EditAnywhere, category = CharacterMovement)
	uint32 bUseControllerDesiredRotation : 1;

	//이동해야되는 위치를 지정하면 그 방향을 바라보도록 지정
	UPROPERTY(EditAnywhere, category = CharacterMovement)
	uint32 bOrientRotationToMovement : 1;

	UPROPERTY(EditAnywhere, BluePrintReadOnly, category = Input)
	TObjectPtr<class UInputMappingContext> InputMappingContext;

	//SpringArm Section
	UPROPERTY(EditAnywhere, category = SpringArm)
	float TargetArmLength;

	UPROPERTY(EditAnywhere, category = SpringArm)
	FRotator RelativeRotation;

	UPROPERTY(EditAnywhere, category = SpringArm)
	uint32 bUsePawnControlRotation : 1;

	UPROPERTY(EditAnywhere, category = SpringArm)
	uint32 bDoCollisionTest : 1;

	UPROPERTY(EditAnywhere, category = SpringArm)
	uint32 bInheritYaw : 1;

	UPROPERTY(EditAnywhere, category = SpringArm)
	uint32 bInheritRoll : 1;

	UPROPERTY(EditAnywhere, category = SpringArm)
	uint32 bInheritPitch : 1;
};
