#pragma once
#include "Props/KitchenObjects/KitchenObject.h"

class VPUtils
{
public:
	static void LogMessage(const FString& Message)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, Message);
	}
	
	static void LogWarning(const FString& Message)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, Message);
	}
	
	static void LogError(const FString& Message)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, Message);
	}

	static void MoveKitchenObjectToCounterSurface(UWorld* World, AKitchenObject* KitchenObject)
	{
		if(!World || !KitchenObject) return;
		
		FVector TraceStart = KitchenObject->GetActorLocation();
		FVector TraceEnd = TraceStart + FVector(0.0f, 0.0f, -500.0f);
		
		FHitResult HitResult;

		FCollisionQueryParams Params;
		Params.AddIgnoredActor(KitchenObject);
		
		const auto HasHit = World->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECC_Visibility, Params);
		if(!HasHit) return;

		FVector Origin;
		FVector BoxExtent;
		KitchenObject->GetActorBounds(false, Origin, BoxExtent);

		const auto SurfaceDelta = 0.01f;
		const FVector BottomPoint = Origin - FVector(0.0f, 0.0f, BoxExtent.Z);
		const float BottomOffset = KitchenObject->GetActorLocation().Z - BottomPoint.Z;

		const auto TargetLocation = FVector(
			KitchenObject->GetActorLocation().X
			,KitchenObject->GetActorLocation().Y
			, HitResult.ImpactPoint.Z + BottomOffset + SurfaceDelta
			);

		KitchenObject->SetActorLocation(TargetLocation);
	}
	
};
