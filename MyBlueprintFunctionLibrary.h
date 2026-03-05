// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"
/**
*
*/
UCLASS()
class PRJ_VR_DENTISIT_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
GENERATED_BODY()
public:
UFUNCTION(BlueprintPure, Category = "customs Save csv", meta = (Keywords = "Load Text File"))
	static bool LoadTxt(FString FileNameA, FString& SaveTextA);

UFUNCTION(BlueprintCallable, Category = "customs Save csv", meta = (Keywords = "Save Text File"))
	static bool SaveTxt(FString SaveTextB, FString FileNameB);

UFUNCTION(BlueprintCallable, Category = "customs Save csv", meta = (Keywords = "Save CSV File"))
	static bool SaveCSV(FString SaveDirctory, FString FileName, TArray<FString> SaveText,bool AllowOverRighting);

UFUNCTION(BlueprintCallable, Category = "customs Read csv", meta = (Keywords = "Read CSV File"))
	static  TArray<FString> ReadCSV(FString SaveDirctory, FString FileName);
	
	};