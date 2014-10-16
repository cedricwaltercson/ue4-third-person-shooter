

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUND_API APickup : public AActor
{
	GENERATED_UCLASS_BODY()

	/** The collision component of the Pickup */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	TSubobjectPtr<USphereComponent> SphereComponent;

	/** The static mesh of the Pickup */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
	TSubobjectPtr<UStaticMeshComponent> PickupMesh;

	/** If true, the Pickup can be picked up. If false, the Pickup can't be picked up */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
	bool bIsActive;

	/** The rotation rate at which the rotation of the Pickup is changed in deg/sec for each axis */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup Movement")
	FRotator RotationRate;

	virtual void Tick(float DeltaTime) override;
	virtual void ReceiveActorBeginOverlap(AActor* OtherActor) override;

protected:
	/** Called when the Pickup is picked up */
	virtual void OnPickedUp(APawn* Picker);
};