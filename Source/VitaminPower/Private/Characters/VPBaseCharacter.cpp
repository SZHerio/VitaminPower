// A Vitamin Power Game. All Rights Reserved.

#include "Characters/VPBaseCharacter.h"
#include "Components/CapsuleComponent.h"

AVPBaseCharacter::AVPBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	
	GetMesh()->SetHiddenInGame(true);
	GetMesh()->SetVisibility(false);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	GetCapsuleComponent()->InitCapsuleSize(CapsuleSizeRadius, CapsuleSizeHalfHeight);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	
	HeadMesh = CreateDefaultSubobject<UStaticMeshComponent>("HeadMesh");
	HeadMesh->SetupAttachment(RootComponent);
	HeadMesh->SetAbsolute(false, false, false);
	HeadMesh->SetRelativeLocation(HeadRelativeLocation);
	HeadMesh->SetRelativeScale3D(HeadRelativeScale3D);
	HeadMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>("BodyMesh");
	BodyMesh->SetupAttachment(RootComponent);
	BodyMesh->SetAbsolute(false, false, false);
	BodyMesh->SetRelativeLocation(BodyRelativeLocation);
	BodyMesh->SetRelativeScale3D(BodyRelativeScale3D);
	BodyMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	LeftEyeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftEyeMesh"));
	LeftEyeMesh->SetupAttachment(HeadMesh);
	LeftEyeMesh->SetRelativeLocation(LeftEyeRelativeLocation);
	LeftEyeMesh->SetRelativeRotation(EyesRelativeRotation);
	LeftEyeMesh->SetRelativeScale3D(EyesRelativeScale3D);
	LeftEyeMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	RightEyeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightEyeMesh"));
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

void AVPBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

