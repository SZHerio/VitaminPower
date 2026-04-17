// A Vitamin Power Game. All Rights Reserved.

#include "Props/Counters/VPClearCounter.h"
#include "Characters/VPBaseCharacter.h"
#include "Core/Misc/VPUtils.h"
#include "Props/KitchenObjects/VPCuttingBoard.h"
#include "Props/KitchenObjects/VPSpecialKitchenObject.h"

AVPClearCounter::AVPClearCounter()
{
	SpawnPointComponent = CreateDefaultSubobject<USceneComponent>("SpawnPoint");
	SpawnPointComponent->SetupAttachment(RootComponent);
}

void AVPClearCounter::BeginPlay()
{
	Super::BeginPlay();

	OnKitchenObjectAdded.AddUObject(this, &AVPClearCounter::ClearCounter_OnKitchenObjectAdded);;
	SpawnKitchenObjectsOnStart();
}

void AVPClearCounter::Interact(AVPBaseCharacter* BaseCharacter)
{
	const auto CharacterKitchenObject = BaseCharacter->GetKitchenObject();

	if(!CharacterKitchenObject)
	{
		if(!HasKitchenObject()) return;

		const auto LastKitchenObject = KitchenObjects.Last();

		if(BaseCharacter->TryAddKitchenObject(LastKitchenObject)) return;;
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
	OnKitchenObjectAdded.Broadcast();

	return true;
}

AKitchenObject* AVPClearCounter::GetKitchenObject()
{
	if(!HasKitchenObject()) return nullptr;
	
	return KitchenObjects.Last();
}

void AVPClearCounter::SpawnKitchenObjectsOnStart()
{
	if(!GetWorld() || KitchenObjectClasses.Num() > MaxKitchenObjectsSize) return;

	for(auto KitchenObjectClass : KitchenObjectClasses)
	{
		const auto NewKitchenObject = VPUtils::GetSpawnedKitchenObject(GetWorld(), this, KitchenObjectClass);
		if(!TryAddKitchenObject(NewKitchenObject)) return;

		const auto SpawnLocation = SpawnPointComponent->GetComponentLocation();

		NewKitchenObject->SetActorLocation(SpawnLocation);
		VPUtils::MoveKitchenObjectToCounterSurface(GetWorld(), NewKitchenObject);
	}
}

void AVPClearCounter::ClearCounter_OnKitchenObjectAdded()
{
	if(KitchenObjects.Num() != 2) return;
	if(KitchenObjects[0]->GetType() != EKitchenObjectType::CuttingBoard) return;

	const auto CuttingBoard = Cast<AVPCuttingBoard>(KitchenObjects[0]);
	if(!CuttingBoard) return;

	CurrentCuttingBoardObject = CuttingBoard;
	const auto SpecialKitchenObject = Cast<AVPSpecialKitchenObject>(KitchenObjects[1]);
	if(!SpecialKitchenObject) return;
	
	CanCuttingBoardBeSpecialInteracted = CuttingBoard->TryFindRecipeForCutting(SpecialKitchenObject);
	CuttingBoard->ShowWidget();
}

void AVPClearCounter::SpecialInteract()
{
	if(KitchenObjects.Num() != 2) return;
	if(!CanCuttingBoardBeSpecialInteracted || !CurrentCuttingBoardObject) return;

	const auto NewKitchenObjectClass = CurrentCuttingBoardObject->GetCutKitchenObjectClass();
	if(!NewKitchenObjectClass) return;

	CurrentCuttingBoardObject->HideWidget();

	KitchenObjects[1]->Destroy();
	KitchenObjects.Pop();
	
	const auto NewKitchenObject = VPUtils::GetSpawnedKitchenObject(GetWorld(), this, NewKitchenObjectClass);
	if(!NewKitchenObject) return;

	TryAddKitchenObject(NewKitchenObject);
}
