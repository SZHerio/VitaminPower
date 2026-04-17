// A Vitamin Power Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "VPKitchenObjectHolder.generated.h"

class AKitchenObject;

UINTERFACE(MinimalAPI)
class UVPKitchenObjectHolder : public UInterface
{
	GENERATED_BODY()
};

class VITAMINPOWER_API IVPKitchenObjectHolder
{
	GENERATED_BODY()

public:
	virtual bool HasKitchenObject() = 0;
	virtual void RemoveKitchenObject() = 0;
	virtual bool TryAddKitchenObject(AKitchenObject* Object) = 0;
	virtual AKitchenObject* GetKitchenObject() = 0;
	virtual void SpawnKitchenObjectsOnStart() = 0;
};
