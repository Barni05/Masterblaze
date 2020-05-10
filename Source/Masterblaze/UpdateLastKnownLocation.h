// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "UpdateLastKnownLocation.generated.h"

/**
 * 
 */
UCLASS()
class MASTERBLAZE_API UUpdateLastKnownLocation : public UBTService
{
	GENERATED_BODY()
public:
    virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

    UPROPERTY(EditAnywhere, Category = "Key")
    struct FBlackboardKeySelector LastKnownLocationKey;

    UPROPERTY(EditAnywhere, Category = "Key")
    FBlackboardKeySelector EnemyKey;
};
