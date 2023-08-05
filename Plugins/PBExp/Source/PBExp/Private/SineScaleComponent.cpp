// Fill out your copyright notice in the Description page of Project Settings.


#include "SineScaleComponent.h"

// Sets default values for this component's properties
USineScaleComponent::USineScaleComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	MainActor = GetOwner();

	// ...
}


// Called when the game starts
void USineScaleComponent::BeginPlay()
{
	Super::BeginPlay();

	//UE_LOG(LogTemp, Warning, TEXT("Actor is %s "), MainActor->GetName());
	// ...
	
}


// Called every frame
void USineScaleComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

