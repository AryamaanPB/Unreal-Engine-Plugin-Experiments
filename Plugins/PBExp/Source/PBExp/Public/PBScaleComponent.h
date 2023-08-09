// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PBScaleComponent.generated.h"

/*An Enum of algorithms that can be used to scale your actor up and down*/
UENUM()
enum class EPBScaleAlgorithm : uint8
{
	Sine, /*Follows a Sine wave: sin(x)*/
	Cosine, /*Follows a Cosine wave: cos(x)*/
};

UCLASS( ClassGroup=(PBScaleComponents), meta=(BlueprintSpawnableComponent) )
class PBEXP_API UPBScaleComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPBScaleComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:

	/*The Algorithm you choose to scale your components*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PB Scale")
		EPBScaleAlgorithm SelectedAlgo = EPBScaleAlgorithm::Sine;

	/*The maximum multiplier to your actor's scale*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PB Scale")
		float MaxScaleFactor = 1.0;

	/*The minimum multiplier to your actor's scale*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PB Scale")
		float MinScaleFactor = 0.5;

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
	void ScaleActorWithSine();

	/*Scale your actor in a cosinusoidal manner by tweaking the properties available in the detail panel
	This function is called in Tick().
	*/
	void ScaleActorWithCosine();

private:

	/*The owner actor of this component*/
	AActor* MainActor;

	/*The scale of the owner actor at the time of BeginPlay()*/
	FVector OriginalScale;
};
