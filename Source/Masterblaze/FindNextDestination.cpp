// Fill out your copyright notice in the Description page of Project Settings.


#include "FindNextDestination.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "GuardPath.h"

EBTNodeResult::Type UFindNextDestination::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
	auto BlackboardComponent = OwnerComp.GetBlackboardComponent();
	auto Pawn = OwnerComp.GetAIOwner()->GetPawn();
	
	auto GuardPathRef = Pawn->FindComponentByClass<UGuardPath>();
	if (!GuardPathRef) { return EBTNodeResult::Failed; }
	TArray<AActor*> Destinations = GuardPathRef->Paths;
	int CurrentIndex = BlackboardComponent->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComponent->SetValueAsObject(NextDestinationKey.SelectedKeyName, Destinations[CurrentIndex]);
	auto NewIndex = (CurrentIndex + 1) % Destinations.Num();
	UE_LOG(LogTemp, Warning, TEXT("%i is the Index"), CurrentIndex)
	BlackboardComponent->SetValueAsInt(IndexKey.SelectedKeyName, NewIndex);
	return EBTNodeResult::Succeeded;
 }
