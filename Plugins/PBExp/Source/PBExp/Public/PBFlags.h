// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/*An Enum of algorithms that can be used to scale your actor up and down*/
UENUM()
enum class EPBScaleAlgorithm : uint8
{
	Sine, /*Follows a Sine wave: sin(x)*/
	Cosine, /*Follows a Cosine wave: cos(x)*/
};

/** Two-handed transformations supported by the generic manipulator. */
UENUM(BlueprintType, meta = (Bitflags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class EPBAxis : uint8
{
	None = 0 UMETA(Hidden),
	/** X Axis. */
	X = 1 << 0,
	/** Y Axis */
	Y = 1 << 1,
	/** Z Axis */
	Z = 1 << 2,
};