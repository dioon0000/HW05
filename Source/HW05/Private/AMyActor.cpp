#include "AMyActor.h"

AAMyActor::AAMyActor() : evCnt(0), totDist(0)
{
	PrimaryActorTick.bCanEverTick = true;
	start.Add(FVector2D(0, 0));
}

void AAMyActor::BeginPlay()
{
	Super::BeginPlay();
	Move();
}

void AAMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAMyActor::Move()
{
	for(int i=1; i<=10; ++i)
	{
		FVector2D step = Step();
		//UE_LOG(LogTemp, Error, TEXT("stepX, stepY: %d %d"), (int)step.X, (int)step.Y);
		start.Add(FVector2D(start[i-1].X + step.X, start[i-1].Y + step.Y));
		float distance = Distance(start[i], start[i-1]);
		UE_LOG(LogTemp, Warning, TEXT("Number[%d] Current Coord: { %d, %d }"),i, (int)start[i].X, (int)start[i].Y);
		UE_LOG(LogTemp, Warning, TEXT("Move Distance: %f"), distance);
		evCnt+=CreateEvent();
		totDist+=distance;
	}
	UE_LOG(LogTemp, Error, TEXT("All Move Distance: %f"), totDist);
	UE_LOG(LogTemp, Error, TEXT("Event Cnt: %d"), evCnt);
}

FVector2D AAMyActor::Step()
{
	int x = FMath::RandRange(0, 1);
	int y = FMath::RandRange(0, 1);
	return FVector2D(x, y);
}

float AAMyActor::Distance(FVector2D first, FVector2D second)
{
	float dx = first.X - second.X;
	float dy = first.Y - second.Y;
	//UE_LOG(LogTemp, Error, TEXT("dx, dy: %f %f"), dx, dy);
	return FMath::Sqrt(dx*dx + dy*dy);
}

int AAMyActor::CreateEvent()
{
	int Event=FMath::RandRange(0, 1);
	if(Event) UE_LOG(LogTemp, Error, TEXT("Event Occurred!"));
	return Event;
}