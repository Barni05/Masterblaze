// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "SpawnPoint.generated.h"

UCLASS()
class MASTERBLAZE_API ASpawnPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnPoint();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ReSpawn();

	UPROPERTY(EditAnywhere, Category = "Setup")
	class UBoxComponent* Bound;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	int32 SpawnAmount;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<class AActor> NPCCharacter;

	UFUNCTION(BlueprintCallable)
	void SpawnAtRandomLocation();

	UPROPERTY(EditAnywhere, Category = "Respawn")
	TArray<class AActor*> ActivePawns;

	UPROPERTY(EditAnywhere, Category = "Respawn")
	float TimeTillRespawn;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	bool bIsNPC;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
