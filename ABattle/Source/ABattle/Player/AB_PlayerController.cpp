// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AB_PlayerController.h"

void AAB_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	// ���콺 ���� ȭ�� ��Ŀ��
	FInputModeGameOnly GameOnlyInputMode;
	SetInputMode(GameOnlyInputMode);
}
