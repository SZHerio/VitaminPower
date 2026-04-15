// A Vitamin Power Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IVPInteractable.generated.h"

class AVPBaseCharacter;
class AVPInteractableObject;

UINTERFACE(MinimalAPI)
class UVPInteractable : public UInterface
{
	GENERATED_BODY()
};

class VITAMINPOWER_API IVPInteractable
{
	GENERATED_BODY()

public:
	virtual void Interact(AVPBaseCharacter* BaseCharacter) = 0;
	virtual void StartHighlighting() = 0;
	virtual void StopHighlighting() = 0;
};
