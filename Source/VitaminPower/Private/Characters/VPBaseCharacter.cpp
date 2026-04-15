// A Vitamin Power Game. All Rights Reserved.

#include "Characters/VPBaseCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Props/Counters/VPInteractableObject.h"
#include "Props/KitchenObjects/KitchenObject.h"

AVPBaseCharacter::AVPBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	GetMesh()->SetHiddenInGame(true);
	GetMesh()->SetVisibility(false);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	GetCapsuleComponent()->InitCapsuleSize(CapsuleSizeRadius, CapsuleSizeHalfHeight);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	GetCharacterMovement()->MaxAcceleration = MaxAccelerationMovement;
	
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

	LeftEyeMesh = CreateDefaultSubobject<UStaticMeshComponent>("LeftEyeMesh");
	LeftEyeMesh->SetupAttachment(HeadMesh);
	LeftEyeMesh->SetRelativeLocation(LeftEyeRelativeLocation);
	LeftEyeMesh->SetRelativeRotation(EyesRelativeRotation);
	LeftEyeMesh->SetRelativeScale3D(EyesRelativeScale3D);
	LeftEyeMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	RightEyeMesh = CreateDefaultSubobject<UStaticMeshComponent>("RightEyeMesh");
	RightEyeMesh->SetupAttachment(HeadMesh);
	RightEyeMesh->SetRelativeLocation(RightEyeRelativeLocation);
	RightEyeMesh->SetRelativeScale3D(EyesRelativeScale3D);
	RightEyeMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	SpawnPointComponent = CreateDefaultSubobject<USceneComponent>("SpawnPoint");
	SpawnPointComponent->SetupAttachment(RootComponent);
	
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

	OnStartedInteraction.AddUObject(this, &AVPBaseCharacter::BaseCharacter_OnStartedInteraction);
}

void AVPBaseCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	FindObjectByTrace();
	SetInteractableObject();
	SelectInteractableObject();
}

void AVPBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool AVPBaseCharacter::HasKitchenObject()
{
	return KitchenObject ? true : false;
}

void AVPBaseCharacter::AddKitchenObject(AKitchenObject* Object)
{
	if(!Object || KitchenObject) return;
	
	KitchenObject = Object;
	KitchenObject->AttachToComponent(SpawnPointComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

void AVPBaseCharacter::RemoveKitchenObject()
{
	if(!HasKitchenObject()) return;
	KitchenObject = nullptr;
}

AKitchenObject* AVPBaseCharacter::GetKitchenObject()
{
	return KitchenObject;
}

void AVPBaseCharacter::FindObjectByTrace()
{
	const auto Start = GetActorLocation();
	const auto End = Start + GetActorForwardVector() * TraceLength;

	if(!GetWorld()) return;

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActor(this);
	
	const auto HasHit = GetWorld()->LineTraceSingleByChannel(ObjectHitResult, Start, End, ECC_Camera, CollisionQueryParams);
	DrawDebugLine(GetWorld(), Start, End, HasHit ? FColor::Green : FColor::Red, false, -1, 0, 2.0f);
}

void AVPBaseCharacter::SelectInteractableObject()
{
	if(CurrentInteractableObject == PreviousInteractableObject) return;

	if(PreviousInteractableObject)
	{
		PreviousInteractableObject->StopHighlighting();
	}

	if(CurrentInteractableObject)
	{
		CurrentInteractableObject->StartHighlighting();
	}
}

void AVPBaseCharacter::SetInteractableObject()
{
	const auto InteractableObject = Cast<AVPInteractableObject>(ObjectHitResult.GetActor());
	
	if(!InteractableObject)
	{
		PreviousInteractableObject = CurrentInteractableObject;
		CurrentInteractableObject = nullptr;
		return;
	}

	PreviousInteractableObject = CurrentInteractableObject;
	CurrentInteractableObject = InteractableObject;
}

void AVPBaseCharacter::BaseCharacter_OnStartedInteraction()
{
	if(!CurrentInteractableObject) return;

	CurrentInteractableObject->Interact(this);
}

