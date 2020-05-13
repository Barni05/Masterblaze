// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SetNextMoveToLocation.generated.h"

/**
 * 
 */
UCLASS()
class MASTERBLAZE_API USetNextMoveToLocation : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere)
	struct FBlackboardKeySelector MoveToLocationKey;

};
