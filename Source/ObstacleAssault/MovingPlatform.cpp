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
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

