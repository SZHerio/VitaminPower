// A Vitamin Power Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Interfaces/VPKitchenObjectHolder.h"
#include "Props/Counters/VPInteractableObject.h"
#include "VPClearCounter.generated.h"

class AKitchenObject;

UCLASS()
class VITAMINPOWER_API AVPClearCounter : public AVPInteractableObject, public IVPKitchenObjectHolder
{
	GENERATED_BODY()

public:
	AVPClearCounter();
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USceneComponent> SpawnSceneComponent;
	
	UPROPERTY()
	TArray<TObjectPtr<AKitchenObject>> KitchenObjects;

	UPROPERTY(meta=(ClampMin = "1", ClampMax = "4"))
	int32 MaxKitchenObjectsSize = 4;
	
public:
	virtual void Interact(AVPBaseCharacter* BaseCharacter) override;
	virtual void RemoveKitchenObject() override;
	virtual void AddKitchenObject(AKitchenObject* Object) override;
	virtual bool HasKitchenObject() override;
	virtual AKitchenObject* GetKitchenObject() override;
};
