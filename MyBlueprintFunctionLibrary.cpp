// Fill out your copyright notice in the Description page of Project Settings.include "MyBlueprintFunctionLibrary.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "HAL/PlatformFilemanager.h"
bool UMyBlueprintFunctionLibrary::LoadTxt(FString FileNameA, FString& SaveTextA)
{
return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::ProjectDir() + FileNameA));
}
bool UMyBlueprintFunctionLibrary::SaveTxt(FString SaveTextB, FString FileNameB)
{
return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::ProjectDir() + FileNameB));
}
bool UMyBlueprintFunctionLibrary::SaveCSV(FString SaveDirctory, FString FileName, TArray<FString> SaveText, bool AllowOverRighting =false)
{
SaveDirctory += "\\";
SaveDirctory += FileName;
if (!AllowOverRighting)
{
	if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirctory))
	{
		return false;
	}
}

FString FinalString = "";
for (FString& Each : SaveText)
{
	FinalString += Each;
	FinalString += LINE_TERMINATOR;
}
return FFileHelper::SaveStringToFile(FinalString, *SaveDirctory, FFileHelper::EEncodingOptions::ForceUTF8);

}
TArray<FString> UMyBlueprintFunctionLibrary::ReadCSV(FString SaveDirctory, FString FileName)
{
TArray<FString> TextData;
FString TextPath = SaveDirctory +"\\"+ FileName;
if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*TextPath))
{
	FFileHelper::LoadFileToStringArray(TextData, *TextPath);
	int32 line = 0;
	for (FString lineContent : TextData)
	{
		UE_LOG(LogTemp, Warning, TEXT("[line %d] %s"), ++line, *lineContent);
	}
}
return TextData;

}