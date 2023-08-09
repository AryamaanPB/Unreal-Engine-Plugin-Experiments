// Fill out your copyright notice in the Description page of Project Settings.


#include "PBScaleComponent.h"

// Sets default values for this component's properties
UPBScaleComponent::UPBScaleComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	MainActor = GetOwner();
	// ...
}


// Called when the game starts
void UPBScaleComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...

	//Getting the Owner actor's scale at the time of BeginPlay() to multiply 
	//the scale sinusoidally with the scale set in the details panel
	if (MainActor)
	{
		OriginalScale = MainActor->GetActorScale3D();
	}
}


// Called every frame
void UPBScaleComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	//Calling the Scaling function in Tick()

	if (SelectedAlgo == EPBScaleAlgorithm::Sine)
	{
		ScaleActorWithSine();
	}
	else if (SelectedAlgo == EPBScaleAlgorithm::Cosine)
	{
		ScaleActorWithCosine();
	}

}

// Function to scale the actor in a positive sinusoidal way
void UPBScaleComponent::ScaleActorWithSine()
{
	//Validating the owner actor
	if (MainActor)
	{
		//Getting world time
		float Time = GetWorld()->GetTimeSeconds();

		//Calculating the appropriate Sine value
		float ScaleMultiplier;

		//Calculating the Sinusoidal Scale Multiplier
		if (bStrictlyPositive)
		{
			ScaleMultiplier = FMath::Abs(FMath::Sin(Time * Frequency) * (MaxScaleFactor - FMath::Abs(MinScaleFactor))) + FMath::Abs(MinScaleFactor);
		}
		else
		{
			ScaleMultiplier = FMath::Sin(Time * Frequency) * (MaxScaleFactor - MinScaleFactor) + MinScaleFactor;
		}

		//Calculating the new scale
		FVector NewScale = OriginalScale * ScaleMultiplier;

		//Setting the actor's new scale
		MainActor->SetActorScale3D(NewScale);
	}
}

void UPBScaleComponent::ScaleActorWithCosine()
{
	//Validating the owner actor
	if (MainActor)
	{
		//Getting world time
		float Time = GetWorld()->GetTimeSeconds();

		//Calculating the appropriate Sine value
		float ScaleMultiplier;

		//Calculating the Cosinusoidal Scale Multiplier
		if (bStrictlyPositive)
		{
			ScaleMultiplier = FMath::Abs(FMath::Cos(Time * Frequency) * (MaxScaleFactor - FMath::Abs(MinScaleFactor))) + FMath::Abs(MinScaleFactor);
		}
		else
		{
			ScaleMultiplier = FMath::Cos(Time * Frequency) * (MaxScaleFactor - MinScaleFactor) + MinScaleFactor;
		}

		//Calculating the new scale
		FVector NewScale = OriginalScale * ScaleMultiplier;

		//Setting the actor's new scale
		MainActor->SetActorScale3D(NewScale);
	}
}
