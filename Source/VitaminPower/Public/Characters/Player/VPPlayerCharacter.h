// A Vitamin Power Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Characters/VPBaseCharacter.h"
#include "VPPlayerCharacter.generated.h"

class IVPInteractable;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class VITAMINPOWER_API AVPPlayerCharacter : public AVPBaseCharacter
{
	GENERATED_BODY()

public:
	AVPPlayerCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere,  BlueprintReadOnly, Category = "Components")
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	UPROPERTY(VisibleAnywhere,  BlueprintReadOnly, Category = "Components")
	TObjectPtr<UCameraComponent> CameraComponent;

	
private:
	FRotator MovementRotationRate = FRotator(0.0f, 720.0f, 0.0f);
	FRotator SpringArmRelativeRotation = FRotator(-50.0f, 0.0f, 0.0f);
	float SpringArmTargetArmLength = 450.0f;
	
public:	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void Move(const FVector2D& MovementVector);
};
