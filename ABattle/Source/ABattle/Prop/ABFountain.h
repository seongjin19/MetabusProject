// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ABFountain.generated.h"

UCLASS()
class ABATTLE_API AABFountain : public AActor
{
	GENERATED_BODY() //�𸮾� �������� �츮�� ���� Ŭ������ �����ϱ� ���� ��
	
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
		Visible / Edit : �б� ���� / ���� ����
		Anywhere / DefaultsOnly / InstanceOnly : property�� �����Ű�� ��𼭵��� ����, ���� / ��Ÿ�ӿ����� �б� �������� ��� / �ν��Ͻ�(������ �޸𸮿� ��ü ����)���� ���ϵ��� �����ϰ� Ŭ���� ���ؿ����� �������� �ʴ´�.
		
		BlueprintReadOnly:
		BlueprintReadOnly / BlueprintReadwrite : �������Ʈ���� �б� ���� / �������Ʈ���� �б� ���� ����

		Category: ī�װ��� �����Ͽ� �з��� ����
	*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh)
	// ���� ������ ��� �𸮾󿡼� ���� ������ TObjectPtr
	TObjectPtr<class UStaticMeshComponent> Body;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh)
	// ���� ������ ��� �𸮾󿡼� ���� ������ TObjectPtr
	TObjectPtr<class UStaticMeshComponent> Water;
};
