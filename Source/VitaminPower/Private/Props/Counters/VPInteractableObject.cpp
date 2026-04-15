// A Vitamin Power Game. All Rights Reserved.

#include "Props/Counters/VPInteractableObject.h"
#include "Core/Misc/VPUtils.h"

AVPInteractableObject::AVPInteractableObject()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("Scene");
	SetRootComponent(SceneComponent);
	
	MainMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MainMesh");
	MainMeshComponent->SetupAttachment(RootComponent);

	SelectableMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("SelectableMesh");
	SelectableMeshComponent->SetupAttachment(RootComponent);
	SelectableMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AVPInteractableObject::BeginPlay()
{
	Super::BeginPlay();

	StopHighlighting();
}

void AVPInteractableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AVPInteractableObject::Interact(AVPBaseCharacter* BaseCharacter)
{
	VPUtils::LogMessage("AVPInteractableObject:Interact()");
}

void AVPInteractableObject::StartHighlighting()
{
	SelectableMeshComponent->SetVisibility(true);
}

void AVPInteractableObject::StopHighlighting()
{
	SelectableMeshComponent->SetVisibility(false);
}

