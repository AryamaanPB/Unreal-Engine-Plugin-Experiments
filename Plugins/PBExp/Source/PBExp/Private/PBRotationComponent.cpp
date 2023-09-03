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
    if (MainActor)
    {
        OriginalRotation = MainActor->GetActorRotation();
    }
}


// Called every frame
void UPBRotationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

    float AddRotation;

	if (SelectedAlgo == EPBScaleAlgorithm::Sine)
	{
        AddRotation = GetSineOffset();
	}
	else if (SelectedAlgo == EPBScaleAlgorithm::Cosine)
	{
        AddRotation = GetCosineOffset();
	}

    RotateActor(AddRotation);
}

float UPBRotationComponent::GetSineOffset()
{
    // Get the world time
    float Time = GetWorld()->GetTimeSeconds();

    // Calculate the appropriate Sine value
    float AddRotation = FMath::Sin(Time * Frequency) * Amplitude;

    return AddRotation;
}


float UPBRotationComponent::GetCosineOffset()
{
    // Get the world time
    float Time = GetWorld()->GetTimeSeconds();

    // Calculate the appropriate Sine value
    float AddRotation = FMath::Cos(Time * Frequency) * Amplitude;

    return AddRotation;
}

void UPBRotationComponent::RotateActor(float AddRotation)
{
    if (MainActor)
    {
        // Calculate the new rotation
        FRotator NewRotation = OriginalRotation;

        if (SelectedAxis & static_cast<int32>(EPBAxis::X))
        {
            NewRotation.Add(AddRotation, 0, 0);
        }

        if (SelectedAxis & static_cast<int32>(EPBAxis::Y))
        {
            NewRotation.Add(0, AddRotation, 0);
        }

        if (SelectedAxis & static_cast<int32>(EPBAxis::Z))
        {
            NewRotation.Add(0, 0, AddRotation);
        }

        // Set the actor's new rotation
        MainActor->SetActorRotation(NewRotation);
    }
}

