#pragma once

struct KitchenObjectParams
{
	FString Name;
	FImage Image;
};

UENUM(BlueprintType)
enum class EKitchenObjectType
{
	Bread,
	CheeseBlock,
	CheeseSlice,
	Tomato,
	TomatoSlice,
	Cabbage,
	CabbageSlice,
	MeatPattyUncooked,
	MeatPattyCooked,
	MeatPattyBurned,
	CuttingBoard, 
	Knife
};
