// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SSM_SSMGameMode_generated_h
#error "SSMGameMode.generated.h already included, missing '#pragma once' in SSMGameMode.h"
#endif
#define SSM_SSMGameMode_generated_h

#define SSM_Source_SSM_SSMGameMode_h_12_SPARSE_DATA
#define SSM_Source_SSM_SSMGameMode_h_12_RPC_WRAPPERS
#define SSM_Source_SSM_SSMGameMode_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define SSM_Source_SSM_SSMGameMode_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASSMGameMode(); \
	friend struct Z_Construct_UClass_ASSMGameMode_Statics; \
public: \
	DECLARE_CLASS(ASSMGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/SSM"), SSM_API) \
	DECLARE_SERIALIZER(ASSMGameMode)


#define SSM_Source_SSM_SSMGameMode_h_12_INCLASS \
private: \
	static void StaticRegisterNativesASSMGameMode(); \
	friend struct Z_Construct_UClass_ASSMGameMode_Statics; \
public: \
	DECLARE_CLASS(ASSMGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/SSM"), SSM_API) \
	DECLARE_SERIALIZER(ASSMGameMode)


#define SSM_Source_SSM_SSMGameMode_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	SSM_API ASSMGameMode(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASSMGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(SSM_API, ASSMGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASSMGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	SSM_API ASSMGameMode(ASSMGameMode&&); \
	SSM_API ASSMGameMode(const ASSMGameMode&); \
public:


#define SSM_Source_SSM_SSMGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	SSM_API ASSMGameMode(ASSMGameMode&&); \
	SSM_API ASSMGameMode(const ASSMGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(SSM_API, ASSMGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASSMGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASSMGameMode)


#define SSM_Source_SSM_SSMGameMode_h_12_PRIVATE_PROPERTY_OFFSET
#define SSM_Source_SSM_SSMGameMode_h_9_PROLOG
#define SSM_Source_SSM_SSMGameMode_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SSM_Source_SSM_SSMGameMode_h_12_PRIVATE_PROPERTY_OFFSET \
	SSM_Source_SSM_SSMGameMode_h_12_SPARSE_DATA \
	SSM_Source_SSM_SSMGameMode_h_12_RPC_WRAPPERS \
	SSM_Source_SSM_SSMGameMode_h_12_INCLASS \
	SSM_Source_SSM_SSMGameMode_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SSM_Source_SSM_SSMGameMode_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SSM_Source_SSM_SSMGameMode_h_12_PRIVATE_PROPERTY_OFFSET \
	SSM_Source_SSM_SSMGameMode_h_12_SPARSE_DATA \
	SSM_Source_SSM_SSMGameMode_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	SSM_Source_SSM_SSMGameMode_h_12_INCLASS_NO_PURE_DECLS \
	SSM_Source_SSM_SSMGameMode_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SSM_API UClass* StaticClass<class ASSMGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SSM_Source_SSM_SSMGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
