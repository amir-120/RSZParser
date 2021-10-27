#include "RSZStructConstructor.hpp"
#include <windows.h>
#include <cstdlib>
#include <regex>

json rszInfo;
bool isInitialized{ false };
std::string tempStringBuffer;

/*std::regex uknListReg("^List(\\d+?)A(\\d+?)Data(\\d+?)A(\\d+?)$");
std::regex uknTypeReg("^Data(\\d+?)A(\\d+?)$");
std::regex stringListReg("^List(\\d+?)A(\\d+?)String(\\d+?)A(\\d+?)$");
std::regex listReg("^(\\w+)List$");*/

//Internal function

std::string StrLower(std::string str) {
	std::for_each(str.begin(), str.end(), [](char& c) { c = std::tolower(c); });
	return str;
}

inline const char* GetStringTempCopy(std::string str) {
	tempStringBuffer = std::string(str);
	return tempStringBuffer.c_str();
}

uint32_t GetFieldTypeInternal(std::string typeName) {
	if (StrLower(typeName) == StrLower("Undefined")) {
		return Undefined_tid;
	}
	else if (StrLower(typeName) == StrLower("Object")) {
		return Object_tid;
	}
	else if (StrLower(typeName) == StrLower("Action")) {
		return Action_tid;
	}
	else if (StrLower(typeName) == StrLower("Struct")) {
		return Struct_tid;
	}
	else if (StrLower(typeName) == StrLower("NativeObject")) {
		return NativeObject_tid;
	}
	else if (StrLower(typeName) == StrLower("Resource")) {
		return Resource_tid;
	}
	else if (StrLower(typeName) == StrLower("UserData")) {
		return UserData_tid;
	}
	else if (StrLower(typeName) == StrLower("Bool")) {
		return Bool_tid;
	}
	else if (StrLower(typeName) == StrLower("C8")) {
		return C8_tid;
	}
	else if (StrLower(typeName) == StrLower("C16")) {
		return C16_tid;
	}
	else if (StrLower(typeName) == StrLower("S8")) {
		return S8_tid;
	}
	else if (StrLower(typeName) == StrLower("U8")) {
		return U8_tid;
	}
	else if (StrLower(typeName) == StrLower("S16")) {
		return S16_tid;
	}
	else if (StrLower(typeName) == StrLower("U16")) {
		return U16_tid;
	}
	else if (StrLower(typeName) == StrLower("S32")) {
		return S32_tid;
	}
	else if (StrLower(typeName) == StrLower("U32")) {
		return U32_tid;
	}
	else if (StrLower(typeName) == StrLower("S64")) {
		return S64_tid;
	}
	else if (StrLower(typeName) == StrLower("U64")) {
		return U64_tid;
	}
	else if (StrLower(typeName) == StrLower("F32")) {
		return F32_tid;
	}
	else if (StrLower(typeName) == StrLower("F64")) {
		return F64_tid;
	}
	else if (StrLower(typeName) == StrLower("String")) {
		return String_tid;
	}
	else if (StrLower(typeName) == StrLower("MBString")) {
		return MBString_tid;
	}
	else if (StrLower(typeName) == StrLower("Enum")) {
		return Enum_tid;
	}
	else if (StrLower(typeName) == StrLower("Uint2")) {
		return Uint2_tid;
	}
	else if (StrLower(typeName) == StrLower("Uint3")) {
		return Uint3_tid;
	}
	else if (StrLower(typeName) == StrLower("Uint4")) {
		return Uint4_tid;
	}
	else if (StrLower(typeName) == StrLower("Int2")) {
		return Int2_tid;
	}
	else if (StrLower(typeName) == StrLower("Int3")) {
		return Int3_tid;
	}
	else if (StrLower(typeName) == StrLower("Int4")) {
		return Int4_tid;
	}
	else if (StrLower(typeName) == StrLower("Float2")) {
		return Float2_tid;
	}
	else if (StrLower(typeName) == StrLower("Float3")) {
		return Float3_tid;
	}
	else if (StrLower(typeName) == StrLower("Float4")) {
		return Float4_tid;
	}
	else if (StrLower(typeName) == StrLower("Float3x3")) {
		return Float3x3_tid;
	}
	else if (StrLower(typeName) == StrLower("Float3x4")) {
		return Float3x4_tid;
	}
	else if (StrLower(typeName) == StrLower("Float4x3")) {
		return Float4x3_tid;
	}
	else if (StrLower(typeName) == StrLower("Float4x4")) {
		return Float4x4_tid;
	}
	else if (StrLower(typeName) == StrLower("Half2")) {
		return Half2_tid;
	}
	else if (StrLower(typeName) == StrLower("Half4")) {
		return Half4_tid;
	}
	else if (StrLower(typeName) == StrLower("Mat3")) {
		return Mat3_tid;
	}
	else if (StrLower(typeName) == StrLower("Mat4")) {
		return Mat4_tid;
	}
	else if (StrLower(typeName) == StrLower("Vec2")) {
		return Vec2_tid;
	}
	else if (StrLower(typeName) == StrLower("Vec3")) {
		return Vec3_tid;
	}
	else if (StrLower(typeName) == StrLower("Vec4")) {
		return Vec4_tid;
	}
	else if (StrLower(typeName) == StrLower("VecU4")) {
		return VecU4_tid;
	}
	else if (StrLower(typeName) == StrLower("Quaternion")) {
		return Quaternion_tid;
	}
	else if (StrLower(typeName) == StrLower("Guid")) {
		return Guid_tid;
	}
	else if (StrLower(typeName) == StrLower("Color")) {
		return Color_tid;
	}
	else if (StrLower(typeName) == StrLower("DateTime")) {
		return DateTime_tid;
	}
	else if (StrLower(typeName) == StrLower("AABB")) {
		return AABB_tid;
	}
	else if (StrLower(typeName) == StrLower("Capsule")) {
		return Capsule_tid;
	}
	else if (StrLower(typeName) == StrLower("TaperedCapsule")) {
		return TaperedCapsule_tid;
	}
	else if (StrLower(typeName) == StrLower("Cone")) {
		return Cone_tid;
	}
	else if (StrLower(typeName) == StrLower("Line")) {
		return Line_tid;
	}
	else if (StrLower(typeName) == StrLower("LineSegment")) {
		return LineSegment_tid;
	}
	else if (StrLower(typeName) == StrLower("OBB")) {
		return OBB_tid;
	}
	else if (StrLower(typeName) == StrLower("Plane")) {
		return Plane_tid;
	}
	else if (StrLower(typeName) == StrLower("PlaneXZ")) {
		return PlaneXZ_tid;
	}
	else if (StrLower(typeName) == StrLower("Point")) {
		return Point_tid;
	}
	else if (StrLower(typeName) == StrLower("Range")) {
		return Range_tid;
	}
	else if (StrLower(typeName) == StrLower("RangeI")) {
		return RangeI_tid;
	}
	else if (StrLower(typeName) == StrLower("Ray")) {
		return Ray_tid;
	}
	else if (StrLower(typeName) == StrLower("RayY")) {
		return RayY_tid;
	}
	else if (StrLower(typeName) == StrLower("Segment")) {
		return Segment_tid;
	}
	else if (StrLower(typeName) == StrLower("Size")) {
		return Size_tid;
	}
	else if (StrLower(typeName) == StrLower("Sphere")) {
		return Sphere_tid;
	}
	else if (StrLower(typeName) == StrLower("Triangle")) {
		return Triangle_tid;
	}
	else if (StrLower(typeName) == StrLower("Cylinder")) {
		return Cylinder_tid;
	}
	else if (StrLower(typeName) == StrLower("Ellipsoid")) {
		return Ellipsoid_tid;
	}
	else if (StrLower(typeName) == StrLower("Area")) {
		return Area_tid;
	}
	else if (StrLower(typeName) == StrLower("Torus")) {
		return Torus_tid;
	}
	else if (StrLower(typeName) == StrLower("Rect")) {
		return Rect_tid;
	}
	else if (StrLower(typeName) == StrLower("Rect3D")) {
		return Rect3D_tid;
	}
	else if (StrLower(typeName) == StrLower("Frustum")) {
		return Frustum_tid;
	}
	else if (StrLower(typeName) == StrLower("KeyFrame")) {
		return KeyFrame_tid;
	}
	else if (StrLower(typeName) == StrLower("Uri")) {
		return Uri_tid;
	}
	else if (StrLower(typeName) == StrLower("GameObjectRef")) {
		return GameObjectRef_tid;
	}
	else if (StrLower(typeName) == StrLower("RuntimeType")) {
		return RuntimeType_tid;
	}
	else if (StrLower(typeName) == StrLower("Sfix")) {
		return Sfix_tid;
	}
	else if (StrLower(typeName) == StrLower("Sfix2")) {
		return Sfix2_tid;
	}
	else if (StrLower(typeName) == StrLower("Sfix3")) {
		return Sfix3_tid;
	}
	else if (StrLower(typeName) == StrLower("Sfix4")) {
		return Sfix4_tid;
	}
	else if (StrLower(typeName) == StrLower("Position")) {
		return Position_tid;
	}
	else if (StrLower(typeName) == StrLower("F16")) {
		return F16_tid;
	}
	else if (StrLower(typeName) == StrLower("End")) {
		return End_tid;
	}
	else if (StrLower(typeName) == StrLower("Data")) {
		return Data_tid;
	}
	else {
		return ukn_type;
	}
}

//External functions

DECL_EXPORT bool IsInitialized()
{
	return isInitialized;
}

DECL_EXPORT void ParseJson(const char* jsonPath)
{
	std::ifstream jsonBuffer(jsonPath, std::ifstream::in);

	if (jsonBuffer.fail()) {
		isInitialized = false;
		return;
	}

	std::stringstream ss;
	ss << jsonBuffer.rdbuf();
	rszInfo = json::parse(ss);

	isInitialized = true;
}

DECL_EXPORT const char* GetRSZClassName(uint32_t classHash)
{
	if (!isInitialized)
		return "Not Initialized!";

	auto hashKey = (std::stringstream{} << std::hex << classHash).str();

	if (rszInfo.contains(hashKey)) {
		return GetStringTempCopy(rszInfo[hashKey]["name"].get<std::string>());
	}
	else {
		return "Unknown Class!";
	}

	return "Unknown error!";
}

DECL_EXPORT uint32_t GetFieldCount(uint32_t classHash)
{
	if (!isInitialized) 
		return -1;

	auto classKey = (std::stringstream{} << std::hex << classHash).str();

	if (rszInfo.contains(classKey)) {
		return static_cast<uint32_t>(rszInfo[classKey]["fields"].size());
	}

	return -1;
}

DECL_EXPORT uint32_t GetFieldAlignment(uint32_t classHash, uint32_t fieldIndex)
{
	if (!isInitialized)
		return -1;

	auto classKey = (std::stringstream{} << std::hex << classHash).str();

	if (rszInfo.contains(classKey) && fieldIndex < rszInfo[classKey]["fields"].size() && fieldIndex >= 0) {
		return rszInfo[classKey]["fields"][fieldIndex]["align"].get<uint32_t>();
	}

	return -1;
}

DECL_EXPORT bool GetFieldArrayState(uint32_t classHash, uint32_t fieldIndex)
{
	if (!isInitialized)
		return false;

	auto classKey = (std::stringstream{} << std::hex << classHash).str();

	if (rszInfo.contains(classKey) && fieldIndex < rszInfo[classKey]["fields"].size() && fieldIndex >= 0) {
		return static_cast<uint32_t>(rszInfo[classKey]["fields"][fieldIndex]["array"].get<bool>());
	}

	return false;
}

DECL_EXPORT const char* GetFieldName(uint32_t classHash, uint32_t fieldIndex)
{
	if (!isInitialized)
		return "Not Initialized!";

	auto classKey = (std::stringstream{} << std::hex << classHash).str();

	if (rszInfo.contains(classKey)) {
		if (fieldIndex < rszInfo[classKey]["fields"].size() && fieldIndex >= 0) {
			return GetStringTempCopy(rszInfo[classKey]["fields"][fieldIndex]["name"].get<std::string>());
		}
		else {
			return "Field index out of range!";
		}
	}
	else {
		return "Class not found!";
	}

	return "Unknown error!";
}

DECL_EXPORT const char* GetFieldTypeName(uint32_t classHash, uint32_t fieldIndex)
{
	if (!isInitialized)
		return "Not Initialized!";

	auto classKey = (std::stringstream{} << std::hex << classHash).str();

	if (rszInfo.contains(classKey)) {
		if (fieldIndex < rszInfo[classKey]["fields"].size() && fieldIndex >= 0) {
			return GetStringTempCopy(rszInfo[classKey]["fields"][fieldIndex]["type"].get<std::string>());
		}
		else {
			return "Field index out of range!";
		}
	}
	else {
		return "Class not found!";
	}

	return "Unknown error!";
}

DECL_EXPORT const char* GetFieldOrgTypeName(uint32_t classHash, uint32_t fieldIndex)
{
	if (!isInitialized)
		return "Not Initialized!";

	auto classKey = (std::stringstream{} << std::hex << classHash).str();

	if (rszInfo.contains(classKey)) {
		if (fieldIndex < rszInfo[classKey]["fields"].size() && fieldIndex >= 0) {
			return GetStringTempCopy(rszInfo[classKey]["fields"][fieldIndex]["original_type"].get<std::string>());
		}
		else {
			return "Field index out of range!";
		}
	}
	else {
		return "Class not found!";
	}

	return "Unknown error!";
}

DECL_EXPORT uint32_t GetFieldSize(uint32_t classHash, uint32_t fieldIndex)
{
	if (!isInitialized)
		return -1;

	auto classKey = (std::stringstream{} << std::hex << classHash).str();

	if (rszInfo.contains(classKey) && fieldIndex < rszInfo[classKey]["fields"].size() && fieldIndex >= 0) {
		return rszInfo[classKey]["fields"][fieldIndex]["size"].get<uint32_t>();
	}

	return -1;
}

DECL_EXPORT uint64_t GetFieldType(uint32_t classHash, uint32_t fieldIndex)
{
	if (!isInitialized)
		return not_init;

	auto classKey =  (std::stringstream{} << std::hex << classHash).str();

	if (rszInfo.contains(classKey)) {
		if (fieldIndex < rszInfo[classKey]["fields"].size() && fieldIndex >= 0) {
			return GetFieldTypeInternal(rszInfo[classKey]["fields"][fieldIndex]["type"].get<std::string>());
		}
		else {
			return out_of_range;
		}
	}
	else {
		return class_not_found;
	}

	return ukn_error;
}

DECL_EXPORT bool IsClassNative(uint32_t classHash)
{
	if (!isInitialized)
		return false;

	auto classKey = (std::stringstream{} << std::hex << classHash).str();

	if (rszInfo.contains(classKey)) {
		return rszInfo[classKey]["native"].get<bool>();
	}

	return false;
}

DECL_EXPORT bool IsFieldNative(uint32_t classHash, uint32_t fieldIndex)
{
	if (!isInitialized)
		return false;

	auto classKey = (std::stringstream{} << std::hex << classHash).str();

	if (rszInfo.contains(classKey) && fieldIndex < rszInfo[classKey]["fields"].size() && fieldIndex >= 0) {
		return rszInfo[classKey]["fields"][fieldIndex]["native"].get<bool>();
	}

	return false;
}
