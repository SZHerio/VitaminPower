#pragma once

#include "CoreMinimal.h"
#include "VPKitchenObjectsTypes.generated.h"

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


