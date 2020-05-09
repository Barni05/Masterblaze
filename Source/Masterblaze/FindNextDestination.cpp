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
	if (!GuardPathRef)
	{
		UE_LOG(LogTemp, Error, TEXT("EC1 A guard is missing GuardPathComponent"))
		return EBTNodeResult::Failed;
	}
	TArray<AActor*> Destinations = GuardPathRef->Paths;
	int CurrentIndex = BlackboardComponent->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComponent->SetValueAsObject(NextDestinationKey.SelectedKeyName, Destinations[CurrentIndex]);
	CurrentIndex++;
	int NewIndex = CurrentIndex % Destinations.Num();
	BlackboardComponent->SetValueAsInt(IndexKey.SelectedKeyName, NewIndex);
	return EBTNodeResult::Succeeded;
 }
