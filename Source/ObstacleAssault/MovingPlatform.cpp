// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	// --Understing how variables work--
	this->MyInt = 9;

	this->APlusB = this->InputA + this->InputB;
	
	this->APlusBFloat = this->InputAFloat + this->InputBFloat;

	// --Working with Struct in C++--
	this->MyX = 5.0;
	this->MyVector.Y = this->MyX;
	this->MyX = this->MyVector.X;

	// --Calling Functions in C++--
	this->SetActorLocation(FVector(1, 2, 3));
	this->SetActorLocation(this->MyVector2);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// --Tick--
	this->MyVector2.Y += 1;
	this->SetActorLocation(this->MyVector2);
}
