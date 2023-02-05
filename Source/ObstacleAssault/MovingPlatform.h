// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// // --Understing how variables work--
	// // Make it visible to the editor
	// UPROPERTY(EditAnywhere);
	// int32 MyInt = 99;

	// UPROPERTY(EditAnywhere);
	// int32 InputA = 0;

	// UPROPERTY(EditAnywhere);
	// int32 InputB = 0;

	// UPROPERTY(EditAnywhere);
	// int32 APlusB = 0;

	// UPROPERTY(EditAnywhere);
	// float InputAFloat = 0.0;

	// UPROPERTY(EditAnywhere);
	// float InputBFloat = 0.0;

	// UPROPERTY(EditAnywhere);
	// float APlusBFloat = 0.0;

	// UPROPERTY(EditAnywhere);
	// float MyAge = 21.0;

	// UPROPERTY(EditAnywhere);
	// bool MyBool = true;

	// // --Working with Struct in C++--
	// UPROPERTY(EditAnywhere);
	// //A Vector with 3 values, that accept float values
	// FVector MyVector = FVector(1, 2, 3);

	// UPROPERTY(EditAnywhere)
	// float MyX = 0;

	// // --Calling Functions in C++--
	// UPROPERTY(EditAnywhere)
	// FVector MyVector2 = FVector(-15500.000000, -3110.000000, 4056.000000);

	//EditAnywhere make it visible to the editor, and
	//category is header that should group this variable
	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector PlatformVelocity = FVector(100, 0, 0);
	UPROPERTY(EditAnywhere, Category="Moving Platform")
	float MoveDistance = 100;	

	FVector StartPosition;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	float GetDistanceMoved() const;
	//A const function is not able to modify values of the class
	//Just return values
	bool ShouldPlatformReturn() const;
};
