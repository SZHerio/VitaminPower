// A Vitamin Power Game. All Rights Reserved.

#include "Props/Counters/VPClearCounter.h"
#include "Characters/VPBaseCharacter.h"

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

		RemoveKitchenObject();
		BaseCharacter->AddKitchenObject(KitchenObjects.Top());
	}
	else
	{
		if(!BaseCharacter->HasKitchenObject()) return;

		AddKitchenObject(CharacterKitchenObject);
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

void AVPClearCounter::AddKitchenObject(AKitchenObject* Object)
{
	if(!Object || KitchenObjects.Num() >= MaxKitchenObjectsSize) return;

	KitchenObjects.Add(Object);
}

AKitchenObject* AVPClearCounter::GetKitchenObject()
{
	if(!HasKitchenObject()) return nullptr;
	
	return KitchenObjects.Last();
}
