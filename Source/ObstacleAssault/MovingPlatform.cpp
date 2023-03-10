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
	
	// // --Understing how variables work--
	// this->MyInt = 9;

	// this->APlusB = this->InputA + this->InputB;
	
	// this->APlusBFloat = this->InputAFloat + this->InputBFloat;

	// // --Working with Struct in C++--
	// this->MyX = 5.0;
	// this->MyVector.Y = this->MyX;
	// this->MyX = this->MyVector.X;

	// // --Calling Functions in C++--
	// this->SetActorLocation(FVector(1, 2, 3));
	// this->SetActorLocation(this->MyVector2);

	//Stores the initial position of it, so we can later
	//see how much it has travelled
	this->StartPosition = this->GetActorLocation();

	// // --Writing to the output log--
	// UE_LOG(LogTemp, Display, TEXT("Your message"));
	// //Writes data from variables to the log
	// UE_LOG(LogTemp, Display, TEXT("Configured Moved Distance: %f"), this->MoveDistance);
	// UE_LOG(LogTemp, Warning, TEXT("Your message"));
	// UE_LOG(LogTemp, Error, TEXT("Your message"));

	// // --FString usage--
	// FString MyString = "My String Value";
	// //In Unreal Engine needs * to convert FString into the format it accepts
	// UE_LOG(LogTemp, Display, TEXT("Here's My String: %s"), *MyString);
	// // Logging a object name
	// FString Name = this->GetName();
	// UE_LOG(LogTemp, Display, TEXT("Here's the name of this object: %s"), *Name);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	this->MovePlatform(DeltaTime);
	this->RotatePlatform(DeltaTime);

	// // --Local Variables--
	// FVector LocalVector = this->MyVector2;
	// LocalVector.Z = LocalVector.Z + 100;

	// // --Tick--
	// this->MyVector2.Y += 1;
	
	// this->SetActorLocation(LocalVector);
}

//A before the class is for saying this is an actor. The :: is to say it is a function
void AMovingPlatform::MovePlatform(float DeltaTime)
{
	//Send platform back if gone too far		
		//Reverse direction of motion if it has gone too far.
	if (this->ShouldPlatformReturn())
	{	//Returns a copy of this vector, that is values are normalized
		//(If it has too small values, it returns a zeroed vector)
		FVector MoveDirection = this->PlatformVelocity.GetSafeNormal();
		//Calculates the start position to be the opposite side of its position,
		//by 100 meters in this case.
		this->StartPosition = this->StartPosition + (MoveDirection * this->MoveDistance);
		//Sets is position again in case it moved by the Tick
		this->SetActorLocation(this->StartPosition);

		//Makes the value of the vector to be inverted
		//(Positive to negative, and negative to positive)
		this->PlatformVelocity = -this->PlatformVelocity;
	}
	else
	{
		//Move forwards
			//Get current location
		FVector CurrentLocation = this->GetActorLocation();
			//Add vector to that location (DeltaTime makes it framerate independent)
		CurrentLocation += this->PlatformVelocity * DeltaTime;

			//Set the location
		this->SetActorLocation(CurrentLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	//This way should not be used because it will not always work, sometimes it
	//needs to flip rotation from negative to positive and this will cause bugs.
	// FRotator CurrentRotation = this->GetActorRotation();
	// CurrentRotation = CurrentRotation + (this->RotationVelocity * DeltaTime);

	// this->SetActorRotation(CurrentRotation);

	//Adds the value to the current location for us
	this->AddActorLocalRotation(RotationVelocity * DeltaTime);
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(this->StartPosition, this->GetActorLocation());
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	//Check how far it has gone
	float DistanceMoved = this->GetDistanceMoved();
	return DistanceMoved > this->MoveDistance;
}