// A Vitamin Power Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "VPKitchenObjectHolder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UVPKitchenObjectHolder : public UInterface
{
	GENERATED_BODY()
};

class VITAMINPOWER_API IVPKitchenObjectHolder
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual bool HasKitchenObject() = 0;

	UFUNCTION()
	virtual void SetKitchenObject(AKitchenObject* KitchenObject) = 0;
	
	UFUNCTION()
	virtual AKitchenObject* GetKitchenObject() = 0;
};
