// A Vitamin Power Game. All Rights Reserved.

#include "Props/Counters/VPClearCounter.h"
#include "Characters/VPBaseCharacter.h"
#include "Core/Misc/VPUtils.h"

AVPClearCounter::AVPClearCounter()
{
	SpawnPointComponent = CreateDefaultSubobject<USceneComponent>("SpawnPoint");
	SpawnPointComponent->SetupAttachment(RootComponent);
}

void AVPClearCounter::Interact(AVPBaseCharacter* BaseCharacter)
{
	const auto CharacterKitchenObject = BaseCharacter->GetKitchenObject();

	if(!CharacterKitchenObject)
	{
		if(!HasKitchenObject()) return;

		const auto LastKitchenObject = KitchenObjects.Last();

		BaseCharacter->TryAddKitchenObject(LastKitchenObject);
		RemoveKitchenObject();
	}
	else
	{
		if(!BaseCharacter->HasKitchenObject()) return;
		if(!TryAddKitchenObject(CharacterKitchenObject)) return;
		
		const auto SpawnLocation = SpawnPointComponent->GetComponentLocation();

		CharacterKitchenObject->SetActorLocation(SpawnLocation);
		VPUtils::MoveKitchenObjectToCounterSurface(GetWorld(), CharacterKitchenObject);
		BaseCharacter->RemoveKitchenObject();
	}
}

bool AVPClearCounter::HasKitchenObject()
{
	return !KitchenObjects.IsEmpty();
}

void AVPClearCounter::RemoveKitchenObject()
{
	if(!HasKitchenObject()) return;
	KitchenObjects.Pop();
}

bool AVPClearCounter::TryAddKitchenObject(AKitchenObject* Object)
{
	if(!Object || KitchenObjects.Num() >= MaxKitchenObjectsSize) return false;

	Object->AttachToComponent(SpawnPointComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	Object->SetCollitsionParametersForCounter();
	KitchenObjects.Add(Object);
	return true;
}

AKitchenObject* AVPClearCounter::GetKitchenObject()
{
	if(!HasKitchenObject()) return nullptr;
	
	return KitchenObjects.Last();
}
