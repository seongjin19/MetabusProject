// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AB_CharacterPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
AAB_CharacterPlayer::AAB_CharacterPlayer()
{
	//Camera
	CameraBoom = CreateDefaultSubobject<USpringArmComponent> (TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;//거리 지정
	CameraBoom->bUsePawnControlRotation = true; //Pawn이 회전을 했을 때 회전을 같이 사용할 것인지

	Camera = CreateDefaultSubobject<UCameraComponent> (TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;
}
