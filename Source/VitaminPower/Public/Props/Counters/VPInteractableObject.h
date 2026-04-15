// A Vitamin Power Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Interfaces/IVPInteractable.h"
#include "GameFramework/Actor.h"
#include "VPInteractableObject.generated.h"

class UBoxComponent;

UCLASS()
class VITAMINPOWER_API AVPInteractableObject : public AActor, public IVPInteractable
{
	GENERATED_BODY()
	
public:	
	AVPInteractableObject();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USceneComponent> SceneComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> MainMeshComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> SelectableMeshComponent;
	
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
public:	
	UFUNCTION(Category = "Interaction")
	virtual void Interact(AVPBaseCharacter* BaseCharacter) override;

	UFUNCTION(Category = "Interaction")
	virtual void StartHighlighting();

	UFUNCTION(Category = "Interaction")
	virtual void StopHighlighting();
};
