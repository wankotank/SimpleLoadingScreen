// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "SimpleLoadingScreenUtility.h"

void UMyGameInstance::Init() 
{
	Super::Init();
	SimpleLoadingScreenSystem = MakeShareable( new FSimpleLoadingScreenSystem(this) );
}
void UMyGameInstance::Shutdown()
{
	SimpleLoadingScreenSystem.Reset();
	Super::Shutdown();
}
