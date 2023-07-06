// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ABFountain.generated.h"

UCLASS()
class ABATTLE_API AABFountain : public AActor
{
	GENERATED_BODY() //언리얼 엔진에서 우리가 만든 클래스를 관리하기 위한 것
	
public:	
	// Sets default values for this actor's properties
	AABFountain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	/*
		VisibleAnywhere:
		Visible / Edit : 읽기 전용 / 수정 가능
		Anywhere / DefaultsOnly / InstanceOnly : property를 노출시키고 어디서든지 노출, 수정 / 런타임에서만 읽기 전용으로 사용 / 인스턴스(실제로 메모리에 객체 생성)에만 속하도록 지정하고 클래스 수준에서는 공유하지 않는다.
		
		BlueprintReadOnly:
		BlueprintReadOnly / BlueprintReadwrite : 블루프린트에서 읽기 전용 / 블루프린트에서 읽기 쓰기 가능

		Category: 카테고리를 지정하여 분류를 쉽게
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh)
	// 기존 포인터 대신 언리얼에서 쓰는 포인터 TObjectPtr
	TObjectPtr<class UStaticMeshComponent> Body;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh)
	// 기존 포인터 대신 언리얼에서 쓰는 포인터 TObjectPtr
	TObjectPtr<class UStaticMeshComponent> Water;
};
