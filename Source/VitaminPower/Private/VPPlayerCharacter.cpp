// Fill out your copyright notice in the Description page of Project Settings.

#include "VPPlayerCharacter.h"

// Sets default values
AVPPlayerCharacter::AVPPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->SetHiddenInGame(true);
	GetMesh()->SetVisibility(false);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	headMesh = CreateDefaultSubobject<UStaticMeshComponent>("Head Mesh");
	bodyMesh = CreateDefaultSubobject<UStaticMeshComponent>("Body Mesh");
}

void AVPPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AVPPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVPPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

