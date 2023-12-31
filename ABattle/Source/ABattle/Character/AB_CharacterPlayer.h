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
	//Meta : 접근 지정자가 protected라 EditAnywhere을 사용해도 접근이 안되는데 Meta = (AllowPrivateAccess = "true"))을 사용해줌으로서 접근 가능하게 한다.
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
