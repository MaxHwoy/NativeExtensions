#pragma once



namespace NativeExtensions::Text
{
	class WStringBuilder final
	{
	private:
		wchar_t* buffer_chars_;
		std::int32_t buffer_length_;
		std::int32_t buffer_offset_;
		std::int32_t buffer_capacity_;
		const static std::int32_t default_buffer_size_;
		const static std::int32_t max_buffer_size_;

	public:
		WStringBuilder();
		WStringBuilder(const WStringBuilder& other);
		WStringBuilder(std::int32_t capacity);
		WStringBuilder(const wchar_t* const value);
		WStringBuilder(const std::wstring& value);
		WStringBuilder(const wchar_t* const value, std::int32_t capacity);
		WStringBuilder(const std::wstring& value, std::int32_t capacity);
		WStringBuilder(const std::wstring& value, std::int32_t startIndex, std::int32_t length, std::int32_t capacity);
		WStringBuilder(std::int32_t capacity, std::int32_t maxCapacity);
		WStringBuilder& operator=(const WStringBuilder& other);
		wchar_t& operator[](std::int32_t index);

	public:
		void Append(wchar_t value, std::int32_t repeatCount);
		void Append(wchar_t* value, std::int32_t startIndex, std::int32_t charCount);
		void Append(const wchar_t* const value);
		void Append(std::wstring* value);
		void Append(const wchar_t* const value, std::int32_t startIndex, std::int32_t count);
		void Append(std::wstring* value, std::int32_t startIndex, std::int32_t count);
		void Append(bool value);
		void Append(std::int8_t value);
		void Append(std::uint8_t value);
		void Append(wchar_t value);
		void Append(std::int16_t value);
		void Append(std::uint16_t value);
		void Append(std::int32_t value);
		void Append(std::uint32_t value);
		void Append(std::int64_t value);
		void Append(std::uint64_t value);
		void Append(float value);
		void Append(double value);
		void AppendLine();
		void AppendLine(const wchar_t* const value);
		void AppendLine(std::wstring* value);
		std::int32_t Capacity();
		void Capacity(std::int32_t value);
		void Clear();
		void CopyTo(std::int32_t srcIndex, Array<wchar_t>* dest, std::int32_t destIndex, std::int32_t count);
		void EnsureCapacity(std::int32_t capacity);
		bool Equals(WStringBuilder* other);

		std::int32_t Length();
		void Length(std::int32_t value);
		std::int32_t MaxCapacity();
		void ToString(std::string* value);
		void ToString(std::string* value, std::int32_t startIndex, std::int32_t count);
	};
}
