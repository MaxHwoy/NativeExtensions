#include "pch.h"
#include "Array.h"
#include "StringBuilder.h"



namespace NativeExtensions::Text
{
	const std::int32_t WStringBuilder::default_buffer_size_ = 0x10;
	const std::int32_t WStringBuilder::max_buffer_size_ = 8000;

	WStringBuilder::WStringBuilder() : WStringBuilder(WStringBuilder::default_buffer_size_)
	{

	}

	WStringBuilder::WStringBuilder(const WStringBuilder& other)
	{

	}

	WStringBuilder::WStringBuilder(std::int32_t capacity)
	{
		this->buffer_chars_ = new wchar_t[capacity];
		this->buffer_length_ = 0;
		this->buffer_offset_ = 0;
		this->buffer_capacity_ = capacity;
	}

	WStringBuilder::WStringBuilder(const wchar_t* const value)
	{
		auto length = std::wcslen(value) + 1;
		bool over = length > WStringBuilder::default_buffer_size_;
		
		if (over)
		{

			this->buffer_chars_ = new wchar_t[length];
			this->buffer_capacity_ = length;
			this->buffer_length_ = length;
			this->buffer_offset_ = length;
			std::memcpy(this->buffer_chars_, value, sizeof(wchar_t) * length);

		}
		else
		{
			
			this->buffer_chars_ = new wchar_t[WStringBuilder::default_buffer_size_];
			this->buffer_capacity_ = WStringBuilder::default_buffer_size_;
			this->buffer_length_ = length;
			this->buffer_offset_ = length;
			std::memcpy(this->buffer_chars_, value, sizeof(wchar_t) * length);

		}
	}

	WStringBuilder::WStringBuilder(const std::wstring& value)
	{

	}

	WStringBuilder::WStringBuilder(const wchar_t* const value, std::int32_t capacity)
	{

	}

	WStringBuilder::WStringBuilder(const std::wstring& value, std::int32_t capacity)
	{

	}

	WStringBuilder::WStringBuilder(const std::wstring& value, std::int32_t startIndex, std::int32_t length, std::int32_t capacity)
	{

	}

	WStringBuilder::WStringBuilder(std::int32_t capacity, std::int32_t maxCapacity)
	{

	}

	WStringBuilder& WStringBuilder::operator=(const WStringBuilder& other)
	{

	}

	wchar_t& WStringBuilder::operator[](std::int32_t index)
	{

	}

	void WStringBuilder::Append(wchar_t value, std::int32_t repeatCount)
	{

	}

	void WStringBuilder::Append(wchar_t* value, std::int32_t startIndex, std::int32_t charCount)
	{

	}

	void WStringBuilder::Append(const wchar_t* const value)
	{

	}

	void WStringBuilder::Append(std::wstring* value)
	{

	}

	void WStringBuilder::Append(const wchar_t* const value, std::int32_t startIndex, std::int32_t count)
	{

	}

	void WStringBuilder::Append(std::wstring* value, std::int32_t startIndex, std::int32_t count)
	{

	}

	void WStringBuilder::Append(bool value)
	{

	}

	void WStringBuilder::Append(std::int8_t value)
	{

	}

	void WStringBuilder::Append(std::uint8_t value)
	{

	}

	void WStringBuilder::Append(wchar_t value)
	{

	}

	void WStringBuilder::Append(std::int16_t value)
	{

	}

	void WStringBuilder::Append(std::uint16_t value)
	{

	}

	void WStringBuilder::Append(std::int32_t value)
	{

	}

	void WStringBuilder::Append(std::uint32_t value)
	{

	}

	void WStringBuilder::Append(std::int64_t value)
	{

	}

	void WStringBuilder::Append(std::uint64_t value)
	{

	}

	void WStringBuilder::Append(float value)
	{

	}

	void WStringBuilder::Append(double value)
	{

	}

	void WStringBuilder::AppendLine()
	{

	}

	void WStringBuilder::AppendLine(const wchar_t* const value)
	{

	}

	void WStringBuilder::AppendLine(std::wstring* value)
	{

	}

	std::int32_t WStringBuilder::Capacity()
	{

	}

	void WStringBuilder::Capacity(std::int32_t value)
	{

	}

	void WStringBuilder::Clear()
	{

	}

	void WStringBuilder::CopyTo(std::int32_t srcIndex, Array<wchar_t>* dest, std::int32_t destIndex, std::int32_t count)
	{

	}

	void WStringBuilder::EnsureCapacity(std::int32_t capacity)
	{

	}

	bool WStringBuilder::Equals(WStringBuilder* other)
	{

	}

	std::int32_t Length()
	{

	}

	void Length(std::int32_t value)
	{

	}

	std::int32_t MaxCapacity()
	{

	}

	void ToString(std::string* value)
	{

	}

	void ToString(std::string* value, std::int32_t startIndex, std::int32_t count)
	{

	}

}
