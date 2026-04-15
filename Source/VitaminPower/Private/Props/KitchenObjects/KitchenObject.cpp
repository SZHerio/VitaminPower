// A Vitamin Power Game. All Rights Reserved.

#include "Props/KitchenObjects/KitchenObject.h"
#include "Core/Misc/VPKitchenObjectsTypes.h"

AKitchenObject::AKitchenObject()
{
	PrimaryActorTick.bCanEverTick = true;
	
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	StaticMeshComponent->SetupAttachment(RootComponent);
	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AKitchenObject::BeginPlay()
{
	Super::BeginPlay();
}

void AKitchenObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

