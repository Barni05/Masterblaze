// Fill out your copyright notice in the Description page of Project Settings.


#include "FocusEnemy.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "BehaviorTree/BTFunctionLibrary.h"

void UFocusEnemy::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	auto BlackboardComponent = OwnerComp.GetBlackboardComponent();
	auto AIController = OwnerComp.GetAIOwner();
	auto Enemy = UBTFunctionLibrary::GetBlackboardValueAsActor(this, EnemyKey);
	if (Enemy)
	{ 
		AIController->SetFocus(Cast<AActor>(Enemy));
	}

	return;
}