// A Vitamin Power Game. All Rights Reserved.

#include "Props/KitchenObjects/VPCuttingBoard.h"
#include "Components/WidgetComponent.h"
#include "Props/KitchenObjects/VPSpecialKitchenObject.h"

TSubclassOf<AKitchenObject> AVPCuttingBoard::GetCutKitchenObjectClass() const
{
	const auto CuttingModifier = CurrentKitchenObjectRecipe.CuttingModifier;
	const auto KitchenObjectToCut = CurrentKitchenObjectRecipe.KitchenObjectToCut;
	
	KitchenObjectToCut->IncreaseCurrentProgress(CuttingModifier);

	if(!KitchenObjectToCut->IsCurrentProgressMax()) return nullptr;

	KitchenObjectToCut->ResetCurrentProgress();

	const auto CutKitchenObject = CurrentKitchenObjectRecipe.CutKitchenObject;
	if(!CutKitchenObject) return nullptr;
	
	return CutKitchenObject.GetClass();
}

AVPCuttingBoard::AVPCuttingBoard()
{
	StatusBarComponent = CreateDefaultSubobject<UWidgetComponent>("StatusBar");
	StatusBarComponent->SetupAttachment(RootComponent);
}

bool AVPCuttingBoard::TryFindRecipeForCutting(const AVPSpecialKitchenObject* SpecialKitchenObject)
{
	if(KitchenObjectRecipes.IsEmpty()) return false;
	
	for(const FKitchenObjectRecipe& Recipe : KitchenObjectRecipes)
	{
		const auto SpecialKitchenObjectToCut = Recipe.KitchenObjectToCut;

		if(!SpecialKitchenObjectToCut) continue;
		if(SpecialKitchenObject->GetType() != SpecialKitchenObjectToCut->GetType()) continue;
		
		CurrentKitchenObjectRecipe = Recipe;
		return true;
	}

	return false;
}

void AVPCuttingBoard::ShowWidget()
{
}

void AVPCuttingBoard::HideWidget()
{
}
