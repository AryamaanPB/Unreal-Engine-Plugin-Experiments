// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PBFlags.h"
#include "PBTranslationComponent.generated.h"


UCLASS( ClassGroup=(PBActorComponents), meta=(BlueprintSpawnableComponent) )
class PBEXP_API UPBTranslationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPBTranslationComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:

	/*The Algorithm you choose to translate your components*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PB Translate")
		EPBScaleAlgorithm SelectedAlgo = EPBScaleAlgorithm::Sine;

	/*The Axes you choose to translate your components on*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PB Translate", meta = (Bitmask, BitmaskEnum = EPBAxis))
		int SelectedAxis = static_cast<int32>(EPBAxis::X);

	/*The maximum multiplier to your actor's translation*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PB Translate")
		float Amplitude = 1.0;

	/*The frequency with which the translation should modulate*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PB Translate")
		float Frequency = 2;

	/*Whether the Sine wave should go below 0*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PB Translate")
		bool bStrictlyPositive = true;

private:
	/*Get the AddLocation using Sine
	This function is called in Tick().
	*/
	float GetSineOffset();

	/*Get the AddLocation using Cosine
	This function is called in Tick().
	*/
	float GetCosineOffset();

	/*Translate your actor by Adding Location offset calculated by whichever algorithm
	This function is called in Tick().
	*/
	void TranslateActor(float AddLocation);

private:

	/*The owner actor of this component*/
	AActor* MainActor;

	/*The scale of the owner actor at the time of BeginPlay()*/
	FVector OriginalLocation;
};
