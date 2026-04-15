// A Vitamin Power Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Misc/VPKitchenObjectsTypes.h"
#include "GameFramework/Actor.h"
#include "KitchenObject.generated.h"


UCLASS()
class VITAMINPOWER_API AKitchenObject : public AActor
{
	GENERATED_BODY()
	
public:	
	AKitchenObject();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;
	
	UPROPERTY(EditAnywhere, Category = "Fields")
	FKitchenObjectParams Params{};
	
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
