// A Vitamin Power Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Props/Counters/VPInteractableObject.h"
#include "VPContainerCounter.generated.h"

class AKitchenObject;

UCLASS()
class VITAMINPOWER_API AVPContainerCounter : public AVPInteractableObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Fields")
	TSubclassOf<AKitchenObject> KitchenObjectClass;

protected:
	virtual void Interact(AVPBaseCharacter* BaseCharacter) override;
};
