// A Vitamin Power Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VPBaseCharacter.generated.h"

UCLASS()
class VITAMINPOWER_API AVPBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVPBaseCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Character")
	TObjectPtr<UStaticMeshComponent> HeadMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Character")
	TObjectPtr<UStaticMeshComponent> BodyMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Visual")
	TObjectPtr<UStaticMeshComponent> LeftEyeMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Visual")
	TObjectPtr<UStaticMeshComponent> RightEyeMesh;
	
protected:
	float CapsuleSizeRadius = 54.0f;
	float CapsuleSizeHalfHeight = 70.0f;
	FVector BodyRelativeLocation = FVector(0.0f,0.0f, -20.0f);
	FVector BodyRelativeScale3D = FVector(1.0f,1.0f, 1.0f);
	FVector HeadRelativeLocation = FVector(0.0f,0.0f, 40.0f);
	FVector HeadRelativeScale3D = FVector(0.6f,0.6f, 0.6f);
	FVector RightEyeRelativeLocation = FVector(43.0f,13.0f, 18.0f);
	FVector LeftEyeRelativeLocation = FVector(43.0f,-13.0f, 18.0f);
	FVector EyesRelativeScale3D = FVector(0.13f, 0.13f, 0.19f);
	FRotator EyesRelativeRotation = FRotator(20.0f, 0.0f, 0.0f);

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
