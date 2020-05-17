// Fill out your copyright notice in the Description page of Project Settings.


#include "HealingItem.h"
#include "SpawnPoint.h"
#include "Engine/World.h"
// Sets default values
AHealingItem::AHealingItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHealingItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHealingItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHealingItem::Destroyed()
{
	if (SpawnPoint)
	{
		SpawnPoint->ActivePawns.Remove(this);
		FTimerHandle TimerHandle;
		float RespawnTime = SpawnPoint->TimeTillRespawn;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, SpawnPoint, &ASpawnPoint::ReSpawn, RespawnTime, false);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("EC3: SpawnPoint reference is NULL in HealingItem"))
	}
	
}