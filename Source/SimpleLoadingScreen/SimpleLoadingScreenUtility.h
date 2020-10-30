// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SimpleLoadingScreenUtility.generated.h"

/**
 *  Core class
 */
class FSimpleLoadingScreenSystem : public FTickableGameObject
{
	TSharedPtr<SWidget>	LoadingScreenWidget;
	bool bShowing = false;
	UGameInstance* GameInstance;
	double LastTickTime = 0.0;
	void OnAsyncLoadingFlushUpdate();
	FName PackageName;
	float Progress = 0.0f;
public:
	FSimpleLoadingScreenSystem( UGameInstance* InGameInstance );
	~FSimpleLoadingScreenSystem();
	virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(FSimpleLoadingScreenSystem, STATGROUP_Tickables); }
	virtual void Tick(float DeltaTime) override;

	void SetWidget( TSharedPtr<SWidget> InWidget );
	void SetPackageNameForLoadingProgress(FName InPackageName) { PackageName = InPackageName; }
	float GetLoadingProgress();
	void ShowLoadingScreen();
	void HideLoadingScreen();

};

/**
 *  Blueprint library
 */
UCLASS(meta=(ScriptName = "SimpleLoadingScreen") )
class USimpleLoadingScreenLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable)
	static void SetLoadingScreenWidget( UUserWidget* InWidget );

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static void SetTargetPackageForLoadingProgress( const UObject* WorldContextObject, FName InPackageName );

	/** 0~1 */
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static float GetLoadingProgress(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static void ShowSimpleLoadingScreen( const UObject* WorldContextObject );

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static void HideSimpleLoadingScreen( const UObject* WorldContextObject );
};
