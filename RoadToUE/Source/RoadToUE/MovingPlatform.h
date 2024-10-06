// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class ROADTOUE_API AMovingPlatform : public AActor
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

//_____________________Default Values_____________________

public:
	//Test
	FRotator mRotator = { 0,0,0 }; 
	void MoveObject(float dt);
	void RotateObject();

	UPROPERTY(VisibleAnywhere, Category = "Movement");
	FVector currentLocation = GetActorLocation();

	UPROPERTY(VisibleAnywhere, Category = "Movement");
	FVector startLocation = { 500,0,50 };

	UPROPERTY(EditAnywhere, Category = "Movement"); 
	FVector objectVelocity = { 0,0,50 };
	
	UPROPERTY(EditAnywhere, Category = "Movement");
	float moveDistance = 200.f;



};
