// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AB_PlayerController.h"

void AAB_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	// 마우스 게임 화면 포커싱
	FInputModeGameOnly GameOnlyInputMode;
	SetInputMode(GameOnlyInputMode);
}
