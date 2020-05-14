// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnPoint.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "NPCCharacter.h"

// Sets default values
ASpawnPoint::ASpawnPoint()
{

	srand(0);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Bound = CreateDefaultSubobject<UBoxComponent>(FName("Bound"));
	Bound->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASpawnPoint::BeginPlay()
{
	Super::BeginPlay();
	for (int32 i = 0; i < SpawnAmount; i++)
	{
		SpawnAtRandomLocation();
	}
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ASpawnPoint::ReSpawn, TimeTillRespawn, false);
}
// Called every frame
void ASpawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnPoint::SpawnAtRandomLocation()
{

	FVector Origin;
	FVector BoxExtent;
	float Radius;
	UKismetSystemLibrary::GetComponentBounds(Bound, Origin, BoxExtent, Radius);

	//Define a random point in the box
	FVector RandomLocation = UKismetMathLibrary::RandomPointInBoundingBox(Origin, BoxExtent);

	FRotator CharacterRotation;
	CharacterRotation.Roll = 0;
	CharacterRotation.Pitch = 0;
	CharacterRotation.Yaw = rand();

	//Ray-cast to avoid spawning in the air
	FHitResult HitResult;
	FVector StartLocation = RandomLocation;
	StartLocation.Z += 1000;
	FVector EndLocation = (GetActorUpVector() * -1 * 50000) + RandomLocation;
	GetWorld()->LineTraceSingleByObjectType(HitResult, StartLocation, EndLocation, FCollisionObjectQueryParams(ECollisionChannel::ECC_WorldStatic));
	FVector HitLocation = HitResult.Location;
	HitLocation.Z += 100;
	auto NPC = GetWorld()->SpawnActor<ANPCCharacter>(NPCCharacter, HitLocation, CharacterRotation);
	NPC->SpawnDefaultController();
	NPC->SpawnPoint = this;
	ActivePawns.Add(NPC);
}

void ASpawnPoint::ReSpawn()
{
}