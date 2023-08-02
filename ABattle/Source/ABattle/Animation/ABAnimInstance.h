// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ABAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ABATTLE_API UABAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UABAnimInstance();

protected:
	virtual void NativeInitializeAnimation() override;

	virtual void  NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = Character)
	TObjectPtr<class ACharacter> Owner;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = Character)
	TObjectPtr<class UCharacterMovementComponent> Movement;

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = Character)
	uint32 bIsRunning : 1;
	
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = Character)
	float GroundSpeed;

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = Character)
	FVector Velocity;

};
