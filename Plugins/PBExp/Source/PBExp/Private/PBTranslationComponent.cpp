// Fill out your copyright notice in the Description page of Project Settings.


#include "PBTranslationComponent.h"

// Sets default values for this component's properties
UPBTranslationComponent::UPBTranslationComponent()
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
void UPBTranslationComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	if (MainActor)
	{
		OriginalLocation = MainActor->GetActorLocation();
	}
	
}


// Called every frame
void UPBTranslationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
    float AddLocation;
	if (SelectedAlgo == EPBScaleAlgorithm::Sine)
	{
        AddLocation = GetSineOffset();
	}
	else if (SelectedAlgo == EPBScaleAlgorithm::Cosine)
	{
        AddLocation = GetCosineOffset();
	}

    TranslateActor(AddLocation);
}

float UPBTranslationComponent::GetSineOffset()
{
    // Get the world time
    float Time = GetWorld()->GetTimeSeconds();

    // Calculate the appropriate Sine value
    float AddLocation = FMath::Sin(Time * Frequency) * Amplitude;

    return AddLocation;
}

float UPBTranslationComponent::GetCosineOffset()
{
    // Get the world time
    float Time = GetWorld()->GetTimeSeconds();

    // Calculate the appropriate Sine value
    float AddLocation = FMath::Cos(Time * Frequency) * Amplitude;

    return AddLocation;
}

void UPBTranslationComponent::TranslateActor(float AddLocation)
{
    if (MainActor)
    {
        // Calculate the new location
        FVector NewLocation = OriginalLocation;

        if (SelectedAxis & static_cast<int32>(EPBAxis::X))
        {
            NewLocation.X += AddLocation;
        }

        if (SelectedAxis & static_cast<int32>(EPBAxis::Y))
        {
            NewLocation.Y += AddLocation;
        }

        if (SelectedAxis & static_cast<int32>(EPBAxis::Z))
        {
            NewLocation.Z += AddLocation;
        }

        // Set the actor's new location
        MainActor->SetActorLocation(NewLocation);

        // Debug messages to show the original and new locations
        FString OriginalLocationMsg = FString::Printf(TEXT("Original Location: %s"), *OriginalLocation.ToString());
        FString NewLocationMsg = FString::Printf(TEXT("New Location: %s"), *NewLocation.ToString());

        FColor TextColor = FColor::White;
        float DisplayTime = 2.0f; // Display time in seconds

        // Display the original location
        GEngine->AddOnScreenDebugMessage(0, DisplayTime, TextColor, OriginalLocationMsg);

        // Display the new location
        GEngine->AddOnScreenDebugMessage(1, DisplayTime, TextColor, NewLocationMsg);
    }
}

