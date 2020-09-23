#pragma once



namespace NativeExtensions
{
	class BitConverter final
	{
	public:
		static SafeArray<std::uint8_t> GetBytes(bool value);
		static SafeArray<std::uint8_t> GetBytes(wchar_t value);
		static SafeArray<std::uint8_t> GetBytes(std::int16_t value);
		static SafeArray<std::uint8_t> GetBytes(std::uint16_t value);
		static SafeArray<std::uint8_t> GetBytes(std::int32_t value);
		static SafeArray<std::uint8_t> GetBytes(std::uint32_t value);
		static SafeArray<std::uint8_t> GetBytes(std::int64_t value);
		static SafeArray<std::uint8_t> GetBytes(std::uint64_t value);
		static SafeArray<std::uint8_t> GetBytes(float value);
		static SafeArray<std::uint8_t> GetBytes(double value);

		static bool ToBoolean(void* arr, std::int32_t startIndex);
		static wchar_t ToWChar(void* arr, std::int32_t startIndex);
		static std::int16_t ToInt16(void* arr, std::int32_t startIndex);
		static std::uint16_t ToUInt16(void* arr, std::int32_t startIndex);
		static std::int32_t ToInt32(void* arr, std::int32_t startIndex);
		static std::uint32_t ToUInt32(void* arr, std::int32_t startIndex);
		static std::int64_t ToInt64(void* arr, std::int32_t startIndex);
		static std::uint64_t ToUInt64(void* arr, std::int32_t startIndex);
		static float ToSingle(void* arr, std::int32_t startIndex);
		static double ToDouble(void* arr, std::int32_t startIndex);
		static std::string ToString(void* arr, std::int32_t startIndex);
		static std::string ToString(void* arr, std::int32_t startIndex, std::int32_t length);
		
		static float Int32BitsToSingle(std::int32_t value);
		static float UInt32BitsToSingle(std::uint32_t value);
		static std::int32_t SingleBitsToInt32(float value);
		static std::uint32_t SingleBitsToUInt32(float value);
		static double Int64BitsToSingle(std::int64_t value);
		static double UInt64BitsToSingle(std::uint64_t value);
		static std::int64_t DoubleBitsToInt64(double value);
		static std::uint64_t DoubleBitsToUInt64(double value);
	};
}
