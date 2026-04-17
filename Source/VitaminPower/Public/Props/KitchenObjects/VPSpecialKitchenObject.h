// A Vitamin Power Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Props/KitchenObjects/KitchenObject.h"
#include "VPSpecialKitchenObject.generated.h"

UCLASS()
class VITAMINPOWER_API AVPSpecialKitchenObject : public AKitchenObject
{
	GENERATED_BODY()

private:
	UPROPERTY(meta=(ClampMin = "0"))
	float CurrentProgress = 0.0f;

public:
	void IncreaseCurrentProgress(float Modifier);
	void ResetCurrentProgress();
	bool IsCurrentProgressMax();
};
