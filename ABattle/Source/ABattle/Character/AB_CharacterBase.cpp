// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AB_CharacterBase.h"

// Sets default values
AAB_CharacterBase::AAB_CharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAB_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAB_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAB_CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

