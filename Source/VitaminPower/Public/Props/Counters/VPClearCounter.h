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
	TObjectPtr<USceneComponent> SpawnPointComponent;
	
	UPROPERTY(VisibleAnywhere, Category = "Fields")
	TArray<TObjectPtr<AKitchenObject>> KitchenObjects;

	UPROPERTY(EditAnywhere, Category = "Fields", meta=(ClampMin = "1", ClampMax = "10"))
	int32 MaxKitchenObjectsSize = 10;
	
public:
	virtual void Interact(AVPBaseCharacter* BaseCharacter) override;
	virtual void RemoveKitchenObject() override;
	virtual bool TryAddKitchenObject(AKitchenObject* Object) override;
	virtual bool HasKitchenObject() override;
	virtual AKitchenObject* GetKitchenObject() override;
};
