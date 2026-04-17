// A Vitamin Power Game. All Rights Reserved.

#include "Props/Counters/VPContainerCounter.h"
#include "Characters/VPBaseCharacter.h"
#include "Props/KitchenObjects/KitchenObject.h"
#include "Components/DecalComponent.h"
#include "Core/Misc/VPUtils.h"

AVPContainerCounter::AVPContainerCounter()
{
	DoorMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Door");
	DoorMeshComponent->SetupAttachment(MainMeshComponent);
	DoorMeshComponent->SetRelativeScale3D(DoorRelativeScale3D);
	DoorMeshComponent->SetRelativeLocation(DoorRelativeLocation);
	DoorMeshComponent->SetRelativeRotation(DoorRelativeRotation);

	DoorDecalComponent = CreateDefaultSubobject<UDecalComponent>("DoorDecal");
	DoorDecalComponent->SetupAttachment(DoorMeshComponent);
	DoorDecalComponent->SetRelativeScale3D(DoorDecalRelativeScale3D);
	DoorDecalComponent->SetRelativeLocation(DoorDecalRelativeLocation);
	DoorDecalComponent->SetRelativeRotation(DoorDecalRelativeRotation);
	DoorDecalComponent->DecalSize = DoorDecalSize;
}

void AVPContainerCounter::Interact(AVPBaseCharacter* BaseCharacter)
{
	if(!GetWorld() || !KitchenObjectClass || !BaseCharacter || BaseCharacter->HasKitchenObject()) return;

	const auto NewKitchenObject = VPUtils::GetSpawnedKitchenObject(GetWorld(), this, KitchenObjectClass);
	BaseCharacter->TryAddKitchenObject(NewKitchenObject);
}
