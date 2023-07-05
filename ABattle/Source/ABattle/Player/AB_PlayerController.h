// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AB_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ABATTLE_API AAB_PlayerController : public APlayerController
{
	GENERATED_BODY()

	void BeginPlay() override;
};
