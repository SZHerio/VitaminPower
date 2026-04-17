// A Vitamin Power Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Interfaces/VPKitchenObjectHolder.h"
#include "Core/Misc/VPVCoreTypes.h"
#include "Props/Counters/VPInteractableObject.h"
#include "VPClearCounter.generated.h"

class AKitchenObject;
class AVPCuttingBoard;

UCLASS()
class VITAMINPOWER_API AVPClearCounter : public AVPInteractableObject, public IVPKitchenObjectHolder
{
	GENERATED_BODY()

public:
	AVPClearCounter();

	FOnKitchenObjectAddedHandle OnKitchenObjectAdded;
	
protected:
	virtual void BeginPlay() override;
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USceneComponent> SpawnPointComponent;
	
	UPROPERTY(EditAnywhere, Category = "Fields")
	TArray<TSubclassOf<AKitchenObject>> KitchenObjectClasses;

	UPROPERTY(EditAnywhere, Category = "Fields", meta=(ClampMin = "1", ClampMax = "10"))
	int32 MaxKitchenObjectsSize = 10;

private:
	UPROPERTY()
	TArray<TObjectPtr<AKitchenObject>> KitchenObjects;

	UPROPERTY()
	AVPCuttingBoard* CurrentCuttingBoardObject = nullptr;
	
	bool CanCuttingBoardBeSpecialInteracted;
	
public:
	virtual void Interact(AVPBaseCharacter* BaseCharacter) override;
	virtual void RemoveKitchenObject() override;
	virtual bool TryAddKitchenObject(AKitchenObject* Object) override;
	virtual bool HasKitchenObject() override;
	virtual AKitchenObject* GetKitchenObject() override;
	void SpecialInteract();
	
private:
	virtual void SpawnKitchenObjectsOnStart() override;
	void ClearCounter_OnKitchenObjectAdded();
};
