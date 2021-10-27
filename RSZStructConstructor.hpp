#pragma once
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
#include <nlohmann/json.hpp>

#define DECL_EXPORT extern "C" __declspec(dllexport)

using json = nlohmann::json;

enum TypesIDs : uint32_t {
	ukn_error = 0,
	ukn_type,
	not_init,
	class_not_found,
	out_of_range,
	Undefined_tid,
	Object_tid,
	Action_tid,
	Struct_tid,
	NativeObject_tid,
	Resource_tid,
	UserData_tid,
	Bool_tid,
	C8_tid,
	C16_tid,
	S8_tid,
	U8_tid,
	S16_tid,
	U16_tid,
	S32_tid,
	U32_tid,
	S64_tid,
	U64_tid,
	F32_tid,
	F64_tid,
	String_tid,
	MBString_tid,
	Enum_tid,
	Uint2_tid,
	Uint3_tid,
	Uint4_tid,
	Int2_tid,
	Int3_tid,
	Int4_tid,
	Float2_tid,
	Float3_tid,
	Float4_tid,
	Float3x3_tid,
	Float3x4_tid,
	Float4x3_tid,
	Float4x4_tid,
	Half2_tid,
	Half4_tid,
	Mat3_tid,
	Mat4_tid,
	Vec2_tid,
	Vec3_tid,
	Vec4_tid,
	VecU4_tid,
	Quaternion_tid,
	Guid_tid,
	Color_tid,
	DateTime_tid,
	AABB_tid,
	Capsule_tid,
	TaperedCapsule_tid,
	Cone_tid,
	Line_tid,
	LineSegment_tid,
	OBB_tid,
	Plane_tid,
	PlaneXZ_tid,
	Point_tid,
	Range_tid,
	RangeI_tid,
	Ray_tid,
	RayY_tid,
	Segment_tid,
	Size_tid,
	Sphere_tid,
	Triangle_tid,
	Cylinder_tid,
	Ellipsoid_tid,
	Area_tid,
	Torus_tid,
	Rect_tid,
	Rect3D_tid,
	Frustum_tid,
	KeyFrame_tid,
	Uri_tid,
	GameObjectRef_tid,
	RuntimeType_tid,
	Sfix_tid,
	Sfix2_tid,
	Sfix3_tid,
	Sfix4_tid,
	Position_tid,
	F16_tid,
	End_tid,
	Data_tid
};

DECL_EXPORT bool IsInitialized();

DECL_EXPORT void ParseJson(const char* jsonPath);

DECL_EXPORT const char* GetRSZClassName(uint32_t classHash);

DECL_EXPORT uint32_t GetFieldCount(uint32_t classHash);

DECL_EXPORT uint32_t GetFieldAlignment(uint32_t classHash, uint32_t fieldIndex);

DECL_EXPORT bool GetFieldArrayState(uint32_t classHash, uint32_t fieldIndex);

DECL_EXPORT const char* GetFieldName(uint32_t classHash, uint32_t fieldIndex);

DECL_EXPORT const char* GetFieldTypeName(uint32_t classHash, uint32_t fieldIndex);

DECL_EXPORT const char* GetFieldOrgTypeName(uint32_t classHash, uint32_t fieldIndex);

DECL_EXPORT uint32_t GetFieldSize(uint32_t classHash, uint32_t fieldIndex);

DECL_EXPORT uint64_t GetFieldType(uint32_t classHash, uint32_t fieldIndex);

DECL_EXPORT bool IsClassNative(uint32_t classHash);

DECL_EXPORT bool IsFieldNative(uint32_t classHash, uint32_t fieldIndex);