// Fill out your copyright notice in the Description page of Project Settings.


#include "SetNextMoveToLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "NPCCharacter.h"
#include "SpawnPoint.h"
#include "NPCAIController.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/BoxComponent.h"

EBTNodeResult::Type USetNextMoveToLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Pawn = OwnerComp.GetAIOwner()->GetPawn();
	auto AIController = OwnerComp.GetAIOwner();
	auto NPCGuard = Cast<ANPCCharacter>(Pawn);
	auto Bound = NPCGuard->SpawnPoint->Bound;

	//Generate a random location in the Bounding box
	FVector Origin;
	FVector BoxExtent;
	float SphereRadius;
	UKismetSystemLibrary::GetComponentBounds(Bound, Origin, BoxExtent, SphereRadius);
	//The Z value will be ignored by the navigation system
	FVector MoveToLocation = UKismetMathLibrary::RandomPointInBoundingBox(Origin, BoxExtent);
	
	auto NPCAICont = Cast<ANPCAIController>(AIController);
	NPCAICont->SetMoveToLocation(MoveToLocation);

	return EBTNodeResult::Succeeded;
}