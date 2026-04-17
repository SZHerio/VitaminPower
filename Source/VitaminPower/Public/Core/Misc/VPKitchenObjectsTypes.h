#pragma once

#include "CoreMinimal.h"
#include "VPKitchenObjectsTypes.generated.h"

class AVPSpecialKitchenObject;
class AKitchenObject;

UENUM(BlueprintType)
enum class EKitchenObjectType : uint8
{
	Bread,
	CheeseBlock,
	CheeseSlice,
	Tomato,
	TomatoSlice,
	Lettuce,
	LettuceSlice,
	MeatPattyUncooked,
	MeatPattyCooked,
	MeatPattyBurned,
	CuttingBoard, 
	Knife
};

USTRUCT(BlueprintType)
struct FKitchenObjectParams
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EKitchenObjectType Type;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UTexture2D> Image = nullptr;
};

USTRUCT(BlueprintType)
struct FKitchenObjectRecipe
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<AVPSpecialKitchenObject> KitchenObjectToCut;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<AKitchenObject> CutKitchenObject;

	UPROPERTY(EditDefaultsOnly, meta=(ClampMin = "0.1", ClampMax = "1.0"))
	float CuttingModifier = 0.3f;
};


