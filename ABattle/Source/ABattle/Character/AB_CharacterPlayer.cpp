// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AB_CharacterPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
AAB_CharacterPlayer::AAB_CharacterPlayer()
{
	//Camera
	CameraBoom = CreateDefaultSubobject<USpringArmComponent> (TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;//�Ÿ� ����
	CameraBoom->bUsePawnControlRotation = true; //Pawn�� ȸ���� ���� �� ȸ���� ���� ����� ������

	Camera = CreateDefaultSubobject<UCameraComponent> (TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;
}
