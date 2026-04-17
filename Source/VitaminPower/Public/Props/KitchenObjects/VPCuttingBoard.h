// A Vitamin Power Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Props/KitchenObjects/KitchenObject.h"
#include "VPCuttingBoard.generated.h"

class UWidgetComponent;
struct FKitchenObjectRecipe;

UCLASS()
class VITAMINPOWER_API AVPCuttingBoard : public AKitchenObject
{
	GENERATED_BODY()

public:
	AVPCuttingBoard();
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UWidgetComponent> StatusBarComponent;
			
	UPROPERTY(EditDefaultsOnly, Category = "Fields")
	TArray<FKitchenObjectRecipe> KitchenObjectRecipes{};

private:
	UPROPERTY()
	FKitchenObjectRecipe CurrentKitchenObjectRecipe;
	
public:
	bool TryFindRecipeForCutting(const AVPSpecialKitchenObject* SpecialKitchenObject);
	void ShowWidget();
	void HideWidget();
	TSubclassOf<AKitchenObject> GetCutKitchenObjectClass() const;
};
