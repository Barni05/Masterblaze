// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FindNextDestination.generated.h"

/**
 * 
 */
UCLASS()
class MASTERBLAZE_API UFindNextDestination : public UBTTaskNode
{
	GENERATED_BODY()
private:
public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
protected:
	UPROPERTY(EditAnywhere, Category = "Key")
	struct FBlackboardKeySelector NextDestinationKey;

	UPROPERTY(EditAnywhere, Category = "Key")
	FBlackboardKeySelector IndexKey;

};
