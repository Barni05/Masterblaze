// Fill out your copyright notice in the Description page of Project Settings.


#include "UpdateLastKnownLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BTFunctionLibrary.h"

 void UUpdateLastKnownLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
     auto BlackboardComponent = OwnerComp.GetBlackboardComponent();
     auto Enemy = UBTFunctionLibrary::GetBlackboardValueAsActor(this, EnemyKey);
     if (!Enemy) { return; }
     auto LastKnownLocation = Enemy->GetActorLocation();
     BlackboardComponent->SetValueAsVector(LastKnownLocationKey.SelectedKeyName, LastKnownLocation);
}