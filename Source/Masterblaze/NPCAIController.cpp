// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCAIController.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"

void ANPCAIController::BeginPlay()
{
	Super::BeginPlay();
	if (!BlackboardToUse) { return; }
	UseBlackboard(BlackboardToUse, BlackboardComponent);
	if (!BehaviorTreeToUse) { return; }
	RunBehaviorTree(BehaviorTreeToUse);
	UE_LOG(LogTemp, Warning, TEXT("MONKEY"))
}

void ANPCAIController::SetMoveToLocation(FVector Location)
{
	BlackboardComponent->SetValueAsVector(FName("NextDestination"), Location);
}