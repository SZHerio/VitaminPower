// A Vitamin Power Game. All Rights Reserved.

#include "Characters/VPBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"

AVPBaseCharacter::AVPBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	GetMesh()->SetHiddenInGame(true);
	GetMesh()->SetVisibility(false);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	GetCapsuleComponent()->InitCapsuleSize(CapsuleSizeRadius, CapsuleSizeHalfHeight);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	
	HeadMesh = CreateDefaultSubobject<UStaticMeshComponent>("Head Mesh");
	HeadMesh->SetupAttachment(RootComponent);
	HeadMesh->SetAbsolute(false, false, false);
	HeadMesh->SetRelativeLocation(HeadRelativeLocation);
	HeadMesh->SetRelativeScale3D(HeadRelativeScale3D);
	HeadMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>("Body Mesh");
	BodyMesh->SetupAttachment(RootComponent);
	BodyMesh->SetAbsolute(false, false, false);
	BodyMesh->SetRelativeLocation(BodyRelativeLocation);
	BodyMesh->SetRelativeScale3D(BodyRelativeScale3D);
	BodyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	LeftEyeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left Eye Mesh"));
	LeftEyeMesh->SetupAttachment(HeadMesh);
	LeftEyeMesh->SetRelativeLocation(LeftEyeRelativeLocation);
	LeftEyeMesh->SetRelativeRotation(EyesRelativeRotation);
	LeftEyeMesh->SetRelativeScale3D(EyesRelativeScale3D);
	LeftEyeMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	RightEyeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right Eye Mesh"));
	RightEyeMesh->SetupAttachment(HeadMesh);
	RightEyeMesh->SetRelativeLocation(RightEyeRelativeLocation);
	RightEyeMesh->SetRelativeScale3D(EyesRelativeScale3D);
	RightEyeMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("/Engine/BasicShapes/Sphere.Sphere"));

	if(SphereMeshAsset.Succeeded())
	{
		BodyMesh->SetStaticMesh(SphereMeshAsset.Object);
		HeadMesh->SetStaticMesh(SphereMeshAsset.Object);
		LeftEyeMesh->SetStaticMesh(SphereMeshAsset.Object);
		RightEyeMesh->SetStaticMesh(SphereMeshAsset.Object);
	}
}

void AVPBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AVPBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVPBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

