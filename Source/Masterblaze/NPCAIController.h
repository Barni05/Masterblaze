// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NPCAIController.generated.h"

/**
 * 
 */
UCLASS()
class MASTERBLAZE_API ANPCAIController : public AAIController
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	class UBlackboardComponent* BlackboardComponent;
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	class UBlackboardData* BlackboardToUse;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	class UBehaviorTree* BehaviorTreeToUse;
public:
	virtual void BeginPlay() override;

	void SetMoveToLocation(FVector Location);
};
