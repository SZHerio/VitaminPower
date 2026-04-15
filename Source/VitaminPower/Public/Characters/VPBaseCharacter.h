// A Vitamin Power Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/Interfaces/VPKitchenObjectHolder.h"
#include "Core/Misc/VPVCoreTypes.h"
#include "GameFramework/Character.h"
#include "VPBaseCharacter.generated.h"

class AVPInteractableObject;
class IVPInteractable;

UCLASS()
class VITAMINPOWER_API AVPBaseCharacter : public ACharacter, public IVPKitchenObjectHolder
{
	GENERATED_BODY()

public:
	AVPBaseCharacter();

	FOnCharacterStartedInteractionHandle OnStartedInteraction;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
protected:
	UPROPERTY(VisibleAnywhere,  BlueprintReadOnly, Category = "Character")
	TObjectPtr<UStaticMeshComponent> HeadMesh;

	UPROPERTY(VisibleAnywhere,  BlueprintReadOnly, Category = "Character")
	TObjectPtr<UStaticMeshComponent> BodyMesh;

	UPROPERTY(VisibleAnywhere,  BlueprintReadOnly, Category = "Visual")
	TObjectPtr<UStaticMeshComponent> LeftEyeMesh;

	UPROPERTY(VisibleAnywhere,  BlueprintReadOnly, Category = "Visual")
	TObjectPtr<UStaticMeshComponent> RightEyeMesh;

	UPROPERTY(VisibleAnywhere,  BlueprintReadOnly, Category = "Character")
	TObjectPtr<USceneComponent> SpawnPointComponent;
	
protected:
	UPROPERTY(EditAnywhere, Category = "Tracing", meta=(ClampMax = "1000.0", ClampMin = "50.0"))
	float TraceLength = 200.0f;

	UPROPERTY()
	TObjectPtr<AKitchenObject> KitchenObject;

	UPROPERTY()
	TObjectPtr<AVPInteractableObject> CurrentInteractableObject;
	
	UPROPERTY()
	TObjectPtr<AVPInteractableObject> PreviousInteractableObject;
	
	float CapsuleSizeRadius = 54.0f;
	float CapsuleSizeHalfHeight = 70.0f;
	float MaxAccelerationMovement = 6000.0f;
	FVector BodyRelativeLocation = FVector(0.0f,0.0f, -20.0f);
	FVector BodyRelativeScale3D = FVector(1.0f,1.0f, 1.0f);
	FVector HeadRelativeLocation = FVector(0.0f,0.0f, 40.0f);
	FVector HeadRelativeScale3D = FVector(0.6f,0.6f, 0.6f);
	FVector RightEyeRelativeLocation = FVector(43.0f,13.0f, 18.0f);
	FVector LeftEyeRelativeLocation = FVector(43.0f,-13.0f, 18.0f);
	FVector EyesRelativeScale3D = FVector(0.13f, 0.13f, 0.19f);
	FRotator EyesRelativeRotation = FRotator(20.0f, 0.0f, 0.0f);
	FHitResult ObjectHitResult;
	
	
public:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual bool HasKitchenObject() override;
	virtual AKitchenObject* GetKitchenObject() override;
	virtual void RemoveKitchenObject() override;
	virtual void AddKitchenObject(AKitchenObject* Object) override;
	
protected:
	void FindObjectByTrace();
	void SelectInteractableObject();
	void SetInteractableObject();

private:
	void BaseCharacter_OnStartedInteraction();
};
