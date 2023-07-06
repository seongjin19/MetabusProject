// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TObjectPtr<class USpringArmComponent> CameraBoom;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TObjectPtr<class UCameraComponent> Camera;
};
