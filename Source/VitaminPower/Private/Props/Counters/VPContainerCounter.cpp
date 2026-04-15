// A Vitamin Power Game. All Rights Reserved.

#include "Props/Counters/VPContainerCounter.h"
#include "Characters/VPBaseCharacter.h"
#include "Props/KitchenObjects/KitchenObject.h"

void AVPContainerCounter::Interact(AVPBaseCharacter* BaseCharacter)
{
	if(!GetWorld() || !KitchenObjectClass || !BaseCharacter || !BaseCharacter->HasKitchenObject()) return;

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AKitchenObject* NewKitchenObject = GetWorld()->SpawnActor<AKitchenObject>(
		KitchenObjectClass
		,GetActorLocation()
		,GetActorRotation()
		,SpawnParameters);

	if(!NewKitchenObject) return;
	BaseCharacter->AddKitchenObject(NewKitchenObject);
}
