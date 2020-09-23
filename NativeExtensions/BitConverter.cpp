#include "pch.h"
#include "SafeArray.h"
#include "BitConverter.h"



namespace NativeExtensions
{
	SafeArray<std::uint8_t> BitConverter::GetBytes(bool value)
	{
		auto result = SafeArray<std::uint8_t>(1);
		result[0] = (std::uint8_t)value;
		return result;
	}

	SafeArray<std::uint8_t> BitConverter::GetBytes(wchar_t value)
	{
		auto result = SafeArray<std::uint8_t>(2);
		*(wchar_t*)&result[0] = value;
		return result;
	}

	SafeArray<std::uint8_t> BitConverter::GetBytes(std::int16_t value)
	{
		auto result = SafeArray<std::uint8_t>(2);
		*(std::int16_t*)&result[0] = value;
		return result;
	}

	SafeArray<std::uint8_t> BitConverter::GetBytes(std::uint16_t value)
	{
		auto result = SafeArray<std::uint8_t>(2);
		*(std::uint16_t*)&result[0] = value;
		return result;
	}

	SafeArray<std::uint8_t> BitConverter::GetBytes(std::int32_t value)
	{
		auto result = SafeArray<std::uint8_t>(4);
		*(std::int32_t*)&result[0] = value;
		return result;
	}

	SafeArray<std::uint8_t> BitConverter::GetBytes(std::uint32_t value)
	{
		auto result = SafeArray<std::uint8_t>(4);
		*(std::uint32_t*)&result[0] = value;
		return result;
	}

	SafeArray<std::uint8_t> BitConverter::GetBytes(std::int64_t value)
	{
		auto result = SafeArray<std::uint8_t>(8);
		*(std::int64_t*)&result[0] = value;
		return result;
	}

	SafeArray<std::uint8_t> BitConverter::GetBytes(std::uint64_t value)
	{
		auto result = SafeArray<std::uint8_t>(8);
		*(std::uint64_t*)&result[0] = value;
		return result;
	}

	SafeArray<std::uint8_t> BitConverter::GetBytes(float value)
	{
		auto result = SafeArray<std::uint8_t>(4);
		*(float*)&result[0] = value;
		return result;
	}

	SafeArray<std::uint8_t> BitConverter::GetBytes(double value)
	{
		auto result = SafeArray<std::uint8_t>(8);
		*(double*)&result[0] = value;
		return result;
	}

	bool BitConverter::ToBoolean(void* arr, std::int32_t startIndex)
	{

	}

	wchar_t BitConverter::ToWChar(void* arr, std::int32_t startIndex)
	{
	
	}

	std::int16_t BitConverter::ToInt16(void* arr, std::int32_t startIndex)
	{

	}

	std::uint16_t BitConverter::ToUInt16(void* arr, std::int32_t startIndex)
	{

	}

	std::int32_t BitConverter::ToInt32(void* arr, std::int32_t startIndex)
	{

	}

	std::uint32_t BitConverter::ToUInt32(void* arr, std::int32_t startIndex)
	{

	}

	std::int64_t BitConverter::ToInt64(void* arr, std::int32_t startIndex)
	{

	}

	std::uint64_t BitConverter::ToUInt64(void* arr, std::int32_t startIndex)
	{

	}

	float BitConverter::ToSingle(void* arr, std::int32_t startIndex)
	{

	}

	double BitConverter::ToDouble(void* arr, std::int32_t startIndex)
	{

	}

	std::string BitConverter::ToString(void* arr, std::int32_t startIndex)
	{

	}

	std::string BitConverter::ToString(void* arr, std::int32_t startIndex, std::int32_t length)
	{

	}

	float BitConverter::Int32BitsToSingle(std::int32_t value)
	{

	}

	float BitConverter::UInt32BitsToSingle(std::uint32_t value)
	{

	}

	std::int32_t BitConverter::SingleBitsToInt32(float value)
	{

	}

	std::uint32_t BitConverter::SingleBitsToUInt32(float value)
	{

	}

	double BitConverter::Int64BitsToSingle(std::int64_t value)
	{

	}

	double BitConverter::UInt64BitsToSingle(std::uint64_t value)
	{

	}

	std::int64_t BitConverter::DoubleBitsToInt64(double value)
	{

	}

	std::uint64_t BitConverter::DoubleBitsToUInt64(double value)
	{

	}
}
