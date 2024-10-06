// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//PlatformObject =  new UActorComponent();

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	currentLocation += startLocation;
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveObject(DeltaTime);
}

void AMovingPlatform::MoveObject(float dt)
{
	RotateObject();
	SetActorLocation(currentLocation);
	currentLocation.Z += (objectVelocity.Z * dt);

	//float member for distance difference from origin to given location before reversing direction.
	float distanceMoved = FVector::Dist(startLocation, currentLocation);
	UE_LOG(LogTemp, Warning, TEXT("The vector value is: %f"), distanceMoved);

	if (distanceMoved > moveDistance) //If distance from origin is greater than max distance, then reverse move-direction.
	{
		FVector moveDirection = objectVelocity.GetSafeNormal();
		startLocation += (moveDirection * moveDistance); //Update Start position. Essentially resetting the distance to 0.
		SetActorLocation(startLocation);
		objectVelocity *= -1;
	}
}

void AMovingPlatform::RotateObject()
{
	mRotator.Yaw += 2;
	SetActorRotation(mRotator);
}


