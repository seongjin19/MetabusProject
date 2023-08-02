// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "Character/AB_CharacterBase.h"
#include "AB_CharacterPlayer.generated.h" 

/**
 * 
 */
UCLASS()
class ABATTLE_API AAB_CharacterPlayer : public AAB_CharacterBase
{
	GENERATED_BODY()
public:
	AAB_CharacterPlayer();
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> CameraBoom;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> Camera;

	//Input section
protected:
	//Meta : ���� �����ڰ� protected�� EditAnywhere�� ����ص� ������ �ȵǴµ� Meta = (AllowPrivateAccess = "true"))�� ����������μ� ���� �����ϰ� �Ѵ�.
	/*UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"));
	TObjectPtr<class UInputMappingContext> DefaultMappingContext;*/

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"));
	TObjectPtr<class UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"));
	TObjectPtr<class UInputAction> SholderMoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"));
	TObjectPtr<class UInputAction> QuaterMoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"));
	TObjectPtr<class UInputAction> SholderLookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"));
	TObjectPtr<class UInputAction> ChangeControlAction;
	//
	void SholderMove(const FInputActionValue& value);
	void QuaterMove(const FInputActionValue& value);
	void SholderLook(const FInputActionValue& value);
	void ChangeControl();
	void SetCharactorControl(ECharactorControlType NewCharacterControlType);

	ECharactorControlType CurrentCharacterControlType;

	virtual void SetCharacterControlData(const UABCharacterControlDataAsset* CharacterControlData) override;

protected:
	virtual void BeginPlay();

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
