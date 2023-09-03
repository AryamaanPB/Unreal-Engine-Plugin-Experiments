// Fill out your copyright notice in the Description page of Project Settings.


#include "PBRotationComponent.h"

// Sets default values for this component's properties
UPBRotationComponent::UPBRotationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
    MainActor = GetOwner();

    if (MainActor)
    {
        OriginalRotation = MainActor->GetActorRotation();

        UStaticMeshComponent* StaticMeshComp = MainActor->FindComponentByClass<UStaticMeshComponent>();
        if (StaticMeshComp)
        {
            StaticMeshComp->SetMobility(EComponentMobility::Movable); // Change mobility to Movable
        }
    }
}


// Called when the game starts
void UPBRotationComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UPBRotationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	if (SelectedAlgo == EPBScaleAlgorithm::Sine)
	{
		RotateActorWithSine();
	}
	else if (SelectedAlgo == EPBScaleAlgorithm::Cosine)
	{
		RotateActorWithCosine();
	}
}

void UPBRotationComponent::RotateActorWithSine()
{
    // Validate the owner actor
    if (MainActor)
    {
        // Get the world time
        float Time = GetWorld()->GetTimeSeconds();

        // Calculate the appropriate Sine value
        float RotationMultiplier = FMath::Sin(Time * Frequency) * Amplitude;

        // Calculate the new rotation
        FRotator NewRotation = OriginalRotation;

        if (SelectedAxis & static_cast<int32>(EPBAxis::X))
        {
            NewRotation.Add(RotationMultiplier, 0, 0);
        }

        if (SelectedAxis & static_cast<int32>(EPBAxis::Y))
        {
            NewRotation.Add(0, RotationMultiplier, 0);
        }

        if (SelectedAxis & static_cast<int32>(EPBAxis::Z))
        {
            NewRotation.Add(0, 0, RotationMultiplier);
        }

        // Set the actor's new rotation
        MainActor->SetActorRotation(NewRotation);
    }
}


void UPBRotationComponent::RotateActorWithCosine()
{
    // Validate the owner actor
    if (MainActor)
    {
        // Get the world time
        float Time = GetWorld()->GetTimeSeconds();

        // Calculate the appropriate Sine value
        float RotationMultiplier = FMath::Cos(Time * Frequency) * Amplitude;

        // Calculate the new rotation
        FRotator NewRotation = OriginalRotation;

        if (SelectedAxis & static_cast<int32>(EPBAxis::X))
        {
            NewRotation.Add(RotationMultiplier, 0, 0);
        }

        if (SelectedAxis & static_cast<int32>(EPBAxis::Y))
        {
            NewRotation.Add(0, RotationMultiplier, 0);
        }

        if (SelectedAxis & static_cast<int32>(EPBAxis::Z))
        {
            NewRotation.Add(0, 0, RotationMultiplier);
        }

        // Set the actor's new rotation
        MainActor->SetActorRotation(NewRotation);
    }
}

