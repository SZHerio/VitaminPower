// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VPPlayerCharacter.generated.h"

UCLASS()
class VITAMINPOWER_API AVPPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AVPPlayerCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Character")
	TObjectPtr<UStaticMeshComponent> headMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Character")
	TObjectPtr<UStaticMeshComponent> bodyMesh;
	
public:	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
