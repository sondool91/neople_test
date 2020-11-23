// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SSM/SSMGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSSMGameMode() {}
// Cross Module References
	SSM_API UClass* Z_Construct_UClass_ASSMGameMode_NoRegister();
	SSM_API UClass* Z_Construct_UClass_ASSMGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_SSM();
// End Cross Module References
	void ASSMGameMode::StaticRegisterNativesASSMGameMode()
	{
	}
	UClass* Z_Construct_UClass_ASSMGameMode_NoRegister()
	{
		return ASSMGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ASSMGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASSMGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_SSM,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASSMGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "SSMGameMode.h" },
		{ "ModuleRelativePath", "SSMGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASSMGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASSMGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASSMGameMode_Statics::ClassParams = {
		&ASSMGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ASSMGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASSMGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASSMGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASSMGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASSMGameMode, 2576838624);
	template<> SSM_API UClass* StaticClass<ASSMGameMode>()
	{
		return ASSMGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASSMGameMode(Z_Construct_UClass_ASSMGameMode, &ASSMGameMode::StaticClass, TEXT("/Script/SSM"), TEXT("ASSMGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASSMGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
