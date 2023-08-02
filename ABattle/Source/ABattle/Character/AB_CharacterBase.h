// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AB_CharacterBase.generated.h"

UENUM()
enum class ECharactorControlType : uint8
{
	Sholder,
	Quater
};

UCLASS()
class ABATTLE_API AAB_CharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAB_CharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditAnywhere, Category = CharacterControl, Meta = (AllowPrivateaccess = "true"))
	TMap<ECharactorControlType, class UABCharacterControlDataAsset*> CharacterControlManager;

	virtual void SetCharacterControlData(const UABCharacterControlDataAsset* CharacterControlData);
};
