// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RestAPIRequest/Public/RequestObject.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRequestObject() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
RESTAPIREQUEST_API UClass* Z_Construct_UClass_URequestObject();
RESTAPIREQUEST_API UClass* Z_Construct_UClass_URequestObject_NoRegister();
RESTAPIREQUEST_API UEnum* Z_Construct_UEnum_RestAPIRequest_ERequestType();
RESTAPIREQUEST_API UScriptStruct* Z_Construct_UScriptStruct_FRequest();
UPackage* Z_Construct_UPackage__Script_RestAPIRequest();
// End Cross Module References

// Begin Enum ERequestType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERequestType;
static UEnum* ERequestType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ERequestType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ERequestType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_RestAPIRequest_ERequestType, (UObject*)Z_Construct_UPackage__Script_RestAPIRequest(), TEXT("ERequestType"));
	}
	return Z_Registration_Info_UEnum_ERequestType.OuterSingleton;
}
template<> RESTAPIREQUEST_API UEnum* StaticEnum<ERequestType>()
{
	return ERequestType_StaticEnum();
}
struct Z_Construct_UEnum_RestAPIRequest_ERequestType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DELETE.Comment", "// This method allows the server to delete an entry in the database\n" },
		{ "DELETE.DisplayName", "Delete" },
		{ "DELETE.Name", "ERequestType::DELETE" },
		{ "DELETE.ToolTip", "This method allows the server to delete an entry in the database" },
		{ "GET.Comment", "// This method allows for the server to find the data you requested and sends it back to you \n" },
		{ "GET.DisplayName", "Get" },
		{ "GET.Name", "ERequestType::GET" },
		{ "GET.ToolTip", "This method allows for the server to find the data you requested and sends it back to you" },
		{ "ModuleRelativePath", "Public/RequestObject.h" },
		{ "POST.Comment", "// This method permits the server to create a new entry in the database\n" },
		{ "POST.DisplayName", "Post" },
		{ "POST.Name", "ERequestType::POST" },
		{ "POST.ToolTip", "This method permits the server to create a new entry in the database" },
		{ "PUT.Comment", "// If you preform the 'PUT' request, then the server will update an entry in the database\n" },
		{ "PUT.DisplayName", "Put" },
		{ "PUT.Name", "ERequestType::PUT" },
		{ "PUT.ToolTip", "If you preform the 'PUT' request, then the server will update an entry in the database" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ERequestType::GET", (int64)ERequestType::GET },
		{ "ERequestType::PUT", (int64)ERequestType::PUT },
		{ "ERequestType::POST", (int64)ERequestType::POST },
		{ "ERequestType::DELETE", (int64)ERequestType::DELETE },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_RestAPIRequest_ERequestType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_RestAPIRequest,
	nullptr,
	"ERequestType",
	"ERequestType",
	Z_Construct_UEnum_RestAPIRequest_ERequestType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_RestAPIRequest_ERequestType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_RestAPIRequest_ERequestType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_RestAPIRequest_ERequestType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_RestAPIRequest_ERequestType()
{
	if (!Z_Registration_Info_UEnum_ERequestType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERequestType.InnerSingleton, Z_Construct_UEnum_RestAPIRequest_ERequestType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ERequestType.InnerSingleton;
}
// End Enum ERequestType

// Begin ScriptStruct FRequest
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_Request;
class UScriptStruct* FRequest::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_Request.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_Request.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRequest, (UObject*)Z_Construct_UPackage__Script_RestAPIRequest(), TEXT("Request"));
	}
	return Z_Registration_Info_UScriptStruct_Request.OuterSingleton;
}
template<> RESTAPIREQUEST_API UScriptStruct* StaticStruct<FRequest>()
{
	return FRequest::StaticStruct();
}
struct Z_Construct_UScriptStruct_FRequest_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/RequestObject.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Headers_MetaData[] = {
		{ "Category", "RestAPI" },
		{ "Comment", "/*\n\x09* Content-Type: Specifies the media type of the request or response body (e.g., application/json, application/xml).\n\x09* Accept: Indicates the media type the client can accept in the response. \n\x09* Authorization: Contains authentication credentials for the request.\n\x09* X-API-Key: A custom header to hold an API key.\n\x09* X-RateLimit-Limit: A header to specify the rate limit for the API.\n\x09* X-Forwarded-For: A header used to determine the client's original IP address. \n\x09*/" },
		{ "ModuleRelativePath", "Public/RequestObject.h" },
		{ "ToolTip", "* Content-Type: Specifies the media type of the request or response body (e.g., application/json, application/xml).\n* Accept: Indicates the media type the client can accept in the response.\n* Authorization: Contains authentication credentials for the request.\n* X-API-Key: A custom header to hold an API key.\n* X-RateLimit-Limit: A header to specify the rate limit for the API.\n* X-Forwarded-For: A header used to determine the client's original IP address." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[] = {
		{ "Category", "RestAPI" },
		{ "Comment", "// Header name, header content. Like Authentication: <Token>\n" },
		{ "ModuleRelativePath", "Public/RequestObject.h" },
		{ "ToolTip", "Header name, header content. Like Authentication: <Token>" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_APIBase_MetaData[] = {
		{ "Category", "RestAPI" },
		{ "ModuleRelativePath", "Public/RequestObject.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_APIExtension_MetaData[] = {
		{ "Category", "RestAPI" },
		{ "Comment", "// Such as 'https://www.renewables.ninja/api/'\n" },
		{ "ModuleRelativePath", "Public/RequestObject.h" },
		{ "ToolTip", "Such as 'https:www.renewables.ninja/api/'" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Username_MetaData[] = {
		{ "Category", "RestAPI" },
		{ "Comment", "// Such as data/pv\n" },
		{ "ModuleRelativePath", "Public/RequestObject.h" },
		{ "ToolTip", "Such as data/pv" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Password_MetaData[] = {
		{ "Category", "RestAPI" },
		{ "ModuleRelativePath", "Public/RequestObject.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Args_MetaData[] = {
		{ "Category", "RestAPI" },
		{ "ModuleRelativePath", "Public/RequestObject.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonFilePath_MetaData[] = {
		{ "Category", "RestAPI" },
		{ "ModuleRelativePath", "Public/RequestObject.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Timeout_MetaData[] = {
		{ "Category", "RestAPI" },
		{ "ModuleRelativePath", "Public/RequestObject.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Headers_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Headers_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Headers;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
	static const UECodeGen_Private::FStrPropertyParams NewProp_APIBase;
	static const UECodeGen_Private::FStrPropertyParams NewProp_APIExtension;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Username;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Password;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Args_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Args;
	static const UECodeGen_Private::FStrPropertyParams NewProp_JsonFilePath;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Timeout;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRequest>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRequest_Statics::NewProp_Headers_ValueProp = { "Headers", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRequest_Statics::NewProp_Headers_Key_KeyProp = { "Headers_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FRequest_Statics::NewProp_Headers = { "Headers", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRequest, Headers), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Headers_MetaData), NewProp_Headers_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FRequest_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FRequest_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRequest, Type), Z_Construct_UEnum_RestAPIRequest_ERequestType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Type_MetaData), NewProp_Type_MetaData) }; // 2824685761
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRequest_Statics::NewProp_APIBase = { "APIBase", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRequest, APIBase), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_APIBase_MetaData), NewProp_APIBase_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRequest_Statics::NewProp_APIExtension = { "APIExtension", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRequest, APIExtension), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_APIExtension_MetaData), NewProp_APIExtension_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRequest_Statics::NewProp_Username = { "Username", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRequest, Username), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Username_MetaData), NewProp_Username_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRequest_Statics::NewProp_Password = { "Password", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRequest, Password), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Password_MetaData), NewProp_Password_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRequest_Statics::NewProp_Args_Inner = { "Args", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FRequest_Statics::NewProp_Args = { "Args", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRequest, Args), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Args_MetaData), NewProp_Args_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FRequest_Statics::NewProp_JsonFilePath = { "JsonFilePath", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRequest, JsonFilePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonFilePath_MetaData), NewProp_JsonFilePath_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRequest_Statics::NewProp_Timeout = { "Timeout", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRequest, Timeout), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Timeout_MetaData), NewProp_Timeout_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FRequest_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRequest_Statics::NewProp_Headers_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRequest_Statics::NewProp_Headers_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRequest_Statics::NewProp_Headers,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRequest_Statics::NewProp_Type_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRequest_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRequest_Statics::NewProp_APIBase,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRequest_Statics::NewProp_APIExtension,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRequest_Statics::NewProp_Username,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRequest_Statics::NewProp_Password,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRequest_Statics::NewProp_Args_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRequest_Statics::NewProp_Args,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRequest_Statics::NewProp_JsonFilePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRequest_Statics::NewProp_Timeout,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRequest_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FRequest_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_RestAPIRequest,
	nullptr,
	&NewStructOps,
	"Request",
	Z_Construct_UScriptStruct_FRequest_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRequest_Statics::PropPointers),
	sizeof(FRequest),
	alignof(FRequest),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRequest_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FRequest_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FRequest()
{
	if (!Z_Registration_Info_UScriptStruct_Request.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_Request.InnerSingleton, Z_Construct_UScriptStruct_FRequest_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_Request.InnerSingleton;
}
// End ScriptStruct FRequest

// Begin Class URequestObject
void URequestObject::StaticRegisterNativesURequestObject()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URequestObject);
UClass* Z_Construct_UClass_URequestObject_NoRegister()
{
	return URequestObject::StaticClass();
}
struct Z_Construct_UClass_URequestObject_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "RequestObject.h" },
		{ "ModuleRelativePath", "Public/RequestObject.h" },
		{ "NotBlueprintType", "true" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URequestObject>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_URequestObject_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_RestAPIRequest,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URequestObject_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_URequestObject_Statics::ClassParams = {
	&URequestObject::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URequestObject_Statics::Class_MetaDataParams), Z_Construct_UClass_URequestObject_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_URequestObject()
{
	if (!Z_Registration_Info_UClass_URequestObject.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URequestObject.OuterSingleton, Z_Construct_UClass_URequestObject_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_URequestObject.OuterSingleton;
}
template<> RESTAPIREQUEST_API UClass* StaticClass<URequestObject>()
{
	return URequestObject::StaticClass();
}
URequestObject::URequestObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(URequestObject);
URequestObject::~URequestObject() {}
// End Class URequestObject

// Begin Registration
struct Z_CompiledInDeferFile_FID_Perforce_playground_unreal_apirequest_Builds_RestAPIRequest_HostProject_Plugins_RestAPIRequest_Source_RestAPIRequest_Public_RequestObject_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ERequestType_StaticEnum, TEXT("ERequestType"), &Z_Registration_Info_UEnum_ERequestType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2824685761U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FRequest::StaticStruct, Z_Construct_UScriptStruct_FRequest_Statics::NewStructOps, TEXT("Request"), &Z_Registration_Info_UScriptStruct_Request, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRequest), 3780586255U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_URequestObject, URequestObject::StaticClass, TEXT("URequestObject"), &Z_Registration_Info_UClass_URequestObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URequestObject), 2793810459U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Perforce_playground_unreal_apirequest_Builds_RestAPIRequest_HostProject_Plugins_RestAPIRequest_Source_RestAPIRequest_Public_RequestObject_h_612593188(TEXT("/Script/RestAPIRequest"),
	Z_CompiledInDeferFile_FID_Perforce_playground_unreal_apirequest_Builds_RestAPIRequest_HostProject_Plugins_RestAPIRequest_Source_RestAPIRequest_Public_RequestObject_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Perforce_playground_unreal_apirequest_Builds_RestAPIRequest_HostProject_Plugins_RestAPIRequest_Source_RestAPIRequest_Public_RequestObject_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Perforce_playground_unreal_apirequest_Builds_RestAPIRequest_HostProject_Plugins_RestAPIRequest_Source_RestAPIRequest_Public_RequestObject_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Perforce_playground_unreal_apirequest_Builds_RestAPIRequest_HostProject_Plugins_RestAPIRequest_Source_RestAPIRequest_Public_RequestObject_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Perforce_playground_unreal_apirequest_Builds_RestAPIRequest_HostProject_Plugins_RestAPIRequest_Source_RestAPIRequest_Public_RequestObject_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Perforce_playground_unreal_apirequest_Builds_RestAPIRequest_HostProject_Plugins_RestAPIRequest_Source_RestAPIRequest_Public_RequestObject_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
