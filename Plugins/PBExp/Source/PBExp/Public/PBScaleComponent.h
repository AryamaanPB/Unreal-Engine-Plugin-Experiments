// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PBFlags.h"
#include "PBScaleComponent.generated.h"


UCLASS( ClassGroup=(PBActorComponents), meta=(BlueprintSpawnableComponent) )
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
	/*Get the ScaleMultiplier using Sine
	This function is called in Tick().
	*/
	float GetSineOffset();

	/*Get the ScaleMultiplier using Cosine
	This function is called in Tick().
	*/
	float GetCosineOffset();
	
	/*Scale your actor by multiplying ScaleMultiplier calculated by whichever algorithm
	This function is called in Tick().
	*/
	void ScaleActor(float ScaleMultiplier);

private:

	/*The owner actor of this component*/
	AActor* MainActor;

	/*The scale of the owner actor at the time of BeginPlay()*/
	FVector OriginalScale;
};
