// A Vitamin Power Game. All Rights Reserved.

#include "Props/KitchenObjects/KitchenObject.h"

#include "NetworkMessage.h"
#include "Core/Misc/VPKitchenObjectsTypes.h"

AKitchenObject::AKitchenObject()
{
	PrimaryActorTick.bCanEverTick = true;
	
	MainMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(MainMeshComponent);
	MainMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void AKitchenObject::BeginPlay()
{
	Super::BeginPlay();
}

void AKitchenObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AKitchenObject::SetCollitsionParametersForCounter()
{
	MainMeshComponent->SetSimulatePhysics(false);
	MainMeshComponent->SetEnableGravity(false);
	MainMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	MainMeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	MainMeshComponent->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

