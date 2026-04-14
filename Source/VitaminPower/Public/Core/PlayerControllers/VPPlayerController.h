// A Vitamin Power Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "VPPlayerController.generated.h"

class AVPPlayerCharacter;
struct FInputActionValue;
class UInputAction;
class UInputMappingContext;

UCLASS()
class VITAMINPOWER_API AVPPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> MappingContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveInputAction;

protected:
	virtual void SetupInputComponent() override;
	
private:
	void InitMappingContext();
	void Move(const FInputActionValue& val);
	void InitPlayerCharacter();

private:
	UPROPERTY()
	TObjectPtr<AVPPlayerCharacter> PlayerCharacter;
};
