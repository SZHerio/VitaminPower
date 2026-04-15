// A Vitamin Power Game. All Rights Reserved.

#include "Props/Counters/VPClearCounter.h"
#include "Characters/VPBaseCharacter.h"
#include "Core/Misc/VPUtils.h"

AVPClearCounter::AVPClearCounter()
{
	SpawnSceneComponent = CreateDefaultSubobject<USceneComponent>("SpawnPoint");
	SpawnSceneComponent->SetupAttachment(RootComponent);
}

void AVPClearCounter::Interact(AVPBaseCharacter* BaseCharacter)
{
	const auto CharacterKitchenObject = BaseCharacter->GetKitchenObject();

	if(!CharacterKitchenObject)
	{
		if(!HasKitchenObject()) return;

		SetKitchenObject(nullptr);
		BaseCharacter->SetKitchenObject(CharacterKitchenObject);
	}
	else
	{
		if(!BaseCharacter->HasKitchenObject()) return;
		
		SetKitchenObject(CharacterKitchenObject);
		BaseCharacter->SetKitchenObject(nullptr);
	}
}

bool AVPClearCounter::HasKitchenObject()
{
	return KitchenObjects.IsEmpty();
}

void AVPClearCounter::SetKitchenObject(AKitchenObject* Object)
{
	if(KitchenObjects.Num() >= MaxKitchenObjectsSize) return;

	KitchenObjects.Add(Object);
}

AKitchenObject* AVPClearCounter::GetKitchenObject()
{
	return KitchenObjects.Last();
}
