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

	// --Understing how variables work--
	// Make it visible to the editor
	UPROPERTY(EditAnywhere);
	int32 MyInt = 99;

	UPROPERTY(EditAnywhere);
	int32 InputA = 0;

	UPROPERTY(EditAnywhere);
	int32 InputB = 0;

	UPROPERTY(EditAnywhere);
	int32 APlusB = 0;

	UPROPERTY(EditAnywhere);
	float InputAFloat = 0.0;

	UPROPERTY(EditAnywhere);
	float InputBFloat = 0.0;

	UPROPERTY(EditAnywhere);
	float APlusBFloat = 0.0;

	UPROPERTY(EditAnywhere);
	float MyAge = 21.0;

	UPROPERTY(EditAnywhere);
	bool MyBool = true;

	// --Working with Struct in C++--
	UPROPERTY(EditAnywhere);
	//A Vector with 3 values, that accept float values
	FVector MyVector = FVector(1, 2, 3);

	UPROPERTY(EditAnywhere)
	float MyX = 0;
};
