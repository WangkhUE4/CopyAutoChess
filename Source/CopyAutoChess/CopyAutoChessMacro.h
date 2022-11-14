#pragma once
#include "GameFramework/Actor.h"


#define RegisterUIManager(class_name)																											\
	class_name* create##class_name(AActor* RootActor)																							\
	{																																			\
		class_name* ManagerT = RootActor->GetWorld()->SpawnActorDeferred<class_name>(class_name::StaticClass(), FTransform3d::Identity);			\
		ManagerT->FinishSpawning(FTransform(), true);																							\
		ManagerT->AttachToActor(RootActor, FAttachmentTransformRules::SnapToTargetNotIncludingScale);											\
		ManagerT->init();																														\
		return ManagerT;																														\
	}

#define ExternUIManager(class_name)																												\
	extern class_name* create##class_name(AActor* RootActor);
