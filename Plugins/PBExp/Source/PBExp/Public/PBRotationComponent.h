// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PBFlags.h"
#include "PBRotationComponent.generated.h"


UCLASS( ClassGroup=(PBActorComponents), meta=(BlueprintSpawnableComponent) )
class PBEXP_API UPBRotationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPBRotationComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:

	/*The Algorithm you choose to rotate your components*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PB Scale")
		EPBScaleAlgorithm SelectedAlgo = EPBScaleAlgorithm::Sine;

	/*The Axes you choose to rotate your components on*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PB Scale", meta = (Bitmask, BitmaskEnum = EPBAxis))
		int SelectedAxis = static_cast<int32>(EPBAxis::X);

	/*The maximum multiplier to your actor's scale*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PB Scale")
		float Amplitude = 1.0;

	/*The frequency with which the scale should modulate*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PB Scale")
		float Frequency = 2;

	/*Whether the Sine wave should go below 0
	Changes MinScaleFactor to |MinScaleFactor|
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PB Scale")
		bool bStrictlyPositive = true;

private:
	/*Scale your actor in a sinusoidal manner by tweaking the properties available in the detail panel
	This function is called in Tick().
	*/
	void RotateActorWithSine();

	/*Scale your actor in a cosinusoidal manner by tweaking the properties available in the detail panel
	This function is called in Tick().
	*/
	void RotateActorWithCosine();

private:

	/*The owner actor of this component*/
	AActor* MainActor;

	/*The scale of the owner actor at the time of BeginPlay()*/
	FRotator OriginalRotation;
		
};
