// A Vitamin Power Game. All Rights Reserved.

#include "Props/KitchenObjects/VPSpecialKitchenObject.h"

void AVPSpecialKitchenObject::IncreaseCurrentProgress(float Modifier)
{
	CurrentProgress = FMath::Clamp(CurrentProgress + Modifier, 0.0f, 1.0f);
}

void AVPSpecialKitchenObject::ResetCurrentProgress()
{
	CurrentProgress = 0.0f;
}

bool AVPSpecialKitchenObject::IsCurrentProgressMax()
{
	return CurrentProgress >= 1.0f;
}
