// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "RequestObject.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef RESTAPIREQUEST_RequestObject_generated_h
#error "RequestObject.generated.h already included, missing '#pragma once' in RequestObject.h"
#endif
#define RESTAPIREQUEST_RequestObject_generated_h

#define FID_Perforce_playground_unreal_apirequest_Builds_RestAPIRequest_HostProject_Plugins_RestAPIRequest_Source_RestAPIRequest_Public_RequestObject_h_36_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FRequest_Statics; \
	RESTAPIREQUEST_API static class UScriptStruct* StaticStruct();


template<> RESTAPIREQUEST_API UScriptStruct* StaticStruct<struct FRequest>();

#define FID_Perforce_playground_unreal_apirequest_Builds_RestAPIRequest_HostProject_Plugins_RestAPIRequest_Source_RestAPIRequest_Public_RequestObject_h_95_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURequestObject(); \
	friend struct Z_Construct_UClass_URequestObject_Statics; \
public: \
	DECLARE_CLASS(URequestObject, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/RestAPIRequest"), NO_API) \
	DECLARE_SERIALIZER(URequestObject)


#define FID_Perforce_playground_unreal_apirequest_Builds_RestAPIRequest_HostProject_Plugins_RestAPIRequest_Source_RestAPIRequest_Public_RequestObject_h_95_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URequestObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	URequestObject(URequestObject&&); \
	URequestObject(const URequestObject&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URequestObject); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URequestObject); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URequestObject) \
	NO_API virtual ~URequestObject();


#define FID_Perforce_playground_unreal_apirequest_Builds_RestAPIRequest_HostProject_Plugins_RestAPIRequest_Source_RestAPIRequest_Public_RequestObject_h_92_PROLOG
#define FID_Perforce_playground_unreal_apirequest_Builds_RestAPIRequest_HostProject_Plugins_RestAPIRequest_Source_RestAPIRequest_Public_RequestObject_h_95_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Perforce_playground_unreal_apirequest_Builds_RestAPIRequest_HostProject_Plugins_RestAPIRequest_Source_RestAPIRequest_Public_RequestObject_h_95_INCLASS_NO_PURE_DECLS \
	FID_Perforce_playground_unreal_apirequest_Builds_RestAPIRequest_HostProject_Plugins_RestAPIRequest_Source_RestAPIRequest_Public_RequestObject_h_95_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> RESTAPIREQUEST_API UClass* StaticClass<class URequestObject>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Perforce_playground_unreal_apirequest_Builds_RestAPIRequest_HostProject_Plugins_RestAPIRequest_Source_RestAPIRequest_Public_RequestObject_h


#define FOREACH_ENUM_EREQUESTTYPE(op) \
	op(ERequestType::GET) \
	op(ERequestType::PUT) \
	op(ERequestType::POST) \
	op(ERequestType::DELETE) 

enum class ERequestType : uint8;
template<> struct TIsUEnumClass<ERequestType> { enum { Value = true }; };
template<> RESTAPIREQUEST_API UEnum* StaticEnum<ERequestType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
