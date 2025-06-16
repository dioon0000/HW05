// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AMyActor.generated.h"

UCLASS()
class HW05_API AAMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Move and Print
	virtual void Move();
	// Step X,Y
	virtual FVector2D Step();
	// Distance return
	virtual float Distance(FVector2D first, FVector2D second);
	// Play Event
	virtual int CreateEvent();

private:
	TArray<FVector2D> start;
	int evCnt;
	float totDist;
};
