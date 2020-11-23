// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SSM_SSMCharacter_generated_h
#error "SSMCharacter.generated.h already included, missing '#pragma once' in SSMCharacter.h"
#endif
#define SSM_SSMCharacter_generated_h

#define SSM_Source_SSM_SSMCharacter_h_12_SPARSE_DATA
#define SSM_Source_SSM_SSMCharacter_h_12_RPC_WRAPPERS
#define SSM_Source_SSM_SSMCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define SSM_Source_SSM_SSMCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASSMCharacter(); \
	friend struct Z_Construct_UClass_ASSMCharacter_Statics; \
public: \
	DECLARE_CLASS(ASSMCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SSM"), NO_API) \
	DECLARE_SERIALIZER(ASSMCharacter)


#define SSM_Source_SSM_SSMCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesASSMCharacter(); \
	friend struct Z_Construct_UClass_ASSMCharacter_Statics; \
public: \
	DECLARE_CLASS(ASSMCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SSM"), NO_API) \
	DECLARE_SERIALIZER(ASSMCharacter)


#define SSM_Source_SSM_SSMCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASSMCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASSMCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASSMCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASSMCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASSMCharacter(ASSMCharacter&&); \
	NO_API ASSMCharacter(const ASSMCharacter&); \
public:


#define SSM_Source_SSM_SSMCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASSMCharacter(ASSMCharacter&&); \
	NO_API ASSMCharacter(const ASSMCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASSMCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASSMCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASSMCharacter)


#define SSM_Source_SSM_SSMCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SideViewCameraComponent() { return STRUCT_OFFSET(ASSMCharacter, SideViewCameraComponent); } \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(ASSMCharacter, CameraBoom); }


#define SSM_Source_SSM_SSMCharacter_h_9_PROLOG
#define SSM_Source_SSM_SSMCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SSM_Source_SSM_SSMCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	SSM_Source_SSM_SSMCharacter_h_12_SPARSE_DATA \
	SSM_Source_SSM_SSMCharacter_h_12_RPC_WRAPPERS \
	SSM_Source_SSM_SSMCharacter_h_12_INCLASS \
	SSM_Source_SSM_SSMCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define SSM_Source_SSM_SSMCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	SSM_Source_SSM_SSMCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	SSM_Source_SSM_SSMCharacter_h_12_SPARSE_DATA \
	SSM_Source_SSM_SSMCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	SSM_Source_SSM_SSMCharacter_h_12_INCLASS_NO_PURE_DECLS \
	SSM_Source_SSM_SSMCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SSM_API UClass* StaticClass<class ASSMCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID SSM_Source_SSM_SSMCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
