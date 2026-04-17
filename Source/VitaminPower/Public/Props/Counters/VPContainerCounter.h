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

public:
	AVPContainerCounter();
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fields")
	TSubclassOf<AKitchenObject> KitchenObjectClass;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> DoorMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UDecalComponent> DoorDecalComponent;
	
	FVector DoorRelativeLocation{-50.0f, 35.0f, 68.0f};
	FRotator DoorRelativeRotation{-90.0f, 0.0f, 0.0f};
	FVector DoorRelativeScale3D{1.6f, 1.0f, 1.33f};

	FVector DoorDecalRelativeLocation{16.0f, -7.0f, 37.36f};
	FRotator DoorDecalRelativeRotation{0.0f, -90.0f, 0.0f};
	FVector DoorDecalRelativeScale3D{10.665f, 1.0f, 1.705f};
	FVector DoorDecalSize{3.0f, 20.0f, 8.0f};
	
protected:
	virtual void Interact(AVPBaseCharacter* BaseCharacter) override;
};
