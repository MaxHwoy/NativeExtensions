#include "pch.h"
#include "Stream.h"
#include "MemoryStream.h"

#pragma warning (disable : 6387)
#pragma warning (disable : 26451)


namespace NativeExtensions::IO
{
	const std::int32_t MemoryStream::memory_stream_max_length_ = INT32_MAX;

	MemoryStream::MemoryStream() : MemoryStream(0)
	{
	}
	
	MemoryStream::MemoryStream(std::int32_t capacity)
	{
		if (capacity < 0) throw; // throw argument out of range
		this->buffer_ = reinterpret_cast<std::uint8_t*>(std::malloc(capacity));
		this->capacity_ = capacity;
		this->expandable_ = true;
		this->writable_ = true;
		this->exposable_ = true;
		this->is_open_ = true;
		this->dealloc_ = true;
		this->disposed_ = false;
		this->origin_ = 0;
		this->position_ = 0;
		this->length_ = 0;
	}
	
	MemoryStream::MemoryStream(void* buffer, std::int32_t length, bool deallocOnDestruct)
		: MemoryStream(buffer, length, true, deallocOnDestruct)
	{
	}
	
	MemoryStream::MemoryStream(void* buffer, std::int32_t length, bool writable, bool deallocOnDestruct)
	{
		if (buffer == nullptr) throw; // throw argument null exception
		this->buffer_ = reinterpret_cast<std::uint8_t*>(buffer);
		this->capacity_ = this->length_ = length;
		this->writable_ = writable;
		this->exposable_ = this->expandable_ = this->disposed_ = false;
		this->is_open_ = true;
		this->dealloc_ = deallocOnDestruct;
		this->position_ = this->origin_ = 0;
	}
	
	MemoryStream::MemoryStream(void* buffer, std::int32_t index, std::int32_t count, bool deallocOnDestruct)
		: MemoryStream(buffer, index, count, true, false, deallocOnDestruct)
	{
	}
	
	MemoryStream::MemoryStream(void* buffer, std::int32_t index, std::int32_t count, bool writable, bool deallocOnDestruct)
		: MemoryStream(buffer, index, count, writable, false, deallocOnDestruct)
	{
	}
	
	MemoryStream::MemoryStream(void* buffer, std::int32_t index, std::int32_t count, bool writable, bool publicallyVisible, bool deallocOnDestruct)
	{
		if (buffer == nullptr) throw; // throw argument null exception
		if (index < 0) throw; // argument out of range exception
		if (count < 0) throw; // argument out of range exception
		this->buffer_ = reinterpret_cast<std::uint8_t*>(buffer);
		this->position_ = this->origin_ = index;
		this->length_ = this->capacity_ = index + count;
		this->writable_ = writable;
		this->exposable_ = publicallyVisible;
		this->expandable_ = this->disposed_ = false;
		this->is_open_ = true;
		this->dealloc_ = deallocOnDestruct;
	}

	MemoryStream::~MemoryStream()
	{
		if (!this->disposed_ && this->dealloc_) std::free(this->buffer_);
	}

	bool MemoryStream::EnsureCapacity(std::int32_t capacity)
	{
		if (capacity < 0) throw; // throw io exception
		if (capacity > this->capacity_)
		{

			std::int32_t count = capacity;
			std::int32_t doubl = this->capacity_ << 1;
			if (count < 256) count = 256;
			if (count < doubl) count = doubl;
			if ((std::uint32_t)doubl > 0x7FFFFFC7) count = (capacity > 0x7FFFFFC7) ? capacity : 0x7FFFFFC7;
			this->Capacity(count);
			return true;

		}
		else return false;
	}

	bool MemoryStream::CanRead()
	{
		return this->is_open_;
	}

	bool MemoryStream::CanSeek()
	{
		return this->is_open_;
	}

	bool MemoryStream::CanWrite()
	{
		return this->writable_;
	}

	std::int32_t MemoryStream::Capacity()
	{
		if (!this->is_open_) throw; // throw stream closed
		return this->capacity_ - this->origin_;
	}

	std::int64_t MemoryStream::Position()
	{
		if (!this->is_open_) throw; // throw stream closed exception
		return this->position_ - this->origin_;
	}

	std::int64_t MemoryStream::Length()
	{
		if (!this->is_open_) throw; // throw stream closed exception
		return this->length_ - this->origin_;
	}

	void MemoryStream::Capacity(std::int32_t capacity)
	{
		if (!this->is_open_) throw; // throw stream closed
		if (capacity < this->length_) throw; // throw argument out of range
		if (!this->expandable_ && capacity != this->capacity_) throw; // throw stream not expandable
		
		if (capacity > 0)
		{

			auto buffer = reinterpret_cast<std::uint8_t*>(std::malloc(capacity));
			if (this->length_ > 0) std::memcpy(buffer, this->buffer_, this->length_);
			std::free(this->buffer_);
			this->buffer_ = buffer;

		}
		else
		{

			std::free(this->buffer_);
		
		}

		this->capacity_ = capacity;
	}

	void MemoryStream::Position(std::int64_t position)
	{
		if (!this->is_open_) throw; // throw stream closed
		if (position < 0 || position > MemoryStream::memory_stream_max_length_) throw; // throw argument out of range
		this->position_ = this->origin_ + (std::int32_t)position;
	}

	void MemoryStream::Length(std::int64_t length)
	{
		if (!this->writable_) throw; // throw write not supported
		if (length < 0 || length > MemoryStream::memory_stream_max_length_ - this->origin_) throw; // throw argument out of range
		auto num = this->origin_ + (std::int32_t)length;

		if (!this->EnsureCapacity(num) && num > this->length_)
		{

			std::memset(this->buffer_ + this->length_, 0, num - this->length_);

		}

		this->length_ = num;
		if (this->position_ > num) this->position_ = num;
	}

	void MemoryStream::Close()
	{
		if (!this->disposed_ && this->dealloc_) std::free(this->buffer_);
		this->disposed_ = true;
		this->is_open_ = false;
		this->writable_ = false;
		this->expandable_ = false;
	}

	void MemoryStream::Flush()
	{
	}

	void* MemoryStream::GetBufferPointer()
	{
		if (!this->exposable_) throw; // throw unauthorized access exception
		return this->buffer_;
	}

	std::int64_t MemoryStream::Seek(std::int64_t offset, SeekOrigin origin)
	{
		if (!this->is_open_) throw; // throw stream is closed
		if (offset > MemoryStream::memory_stream_max_length_) throw; // throw argument out of range
		std::int32_t temp;

		switch (origin)
		{

		case SeekOrigin::Begin:
			temp = this->origin_ + (std::int32_t)offset;
			if (offset < 0 || temp < this->origin_) throw; // throw io exception
			this->position_ = temp;
			break;

		case SeekOrigin::Current:
			temp = this->position_ + (std::int32_t)offset;
			if (this->position_ + offset < this->origin_ || temp < this->origin_) throw; // throw io exception
			this->position_ = temp;
			break;

		case SeekOrigin::End:
			temp = this->position_ + this->length_;
			if (this->length_ + offset < this->origin_ || temp < this->origin_) throw; // throw io exception
			this->position_ = temp;
			break;

		default:
			throw; // throw invalid seek origin

		}

		return this->position_;
	}

	std::int32_t MemoryStream::Read(std::uint8_t* buffer, std::int32_t offset, std::int32_t count)
	{
		if (!this->is_open_) throw; // throw stream closed
		if (buffer == nullptr) throw; // throw argument null
		if (offset < 0) throw; // throw out of range
		if (count < 0) throw; // throw out of range

		int num = this->length_ - this->position_;

		if (num > count) num = count;
		if (num <= 0) return 0;
		if (num <= 8)
		{

			for (std::int32_t i = 0; i < num; ++i) buffer[offset + i] = this->buffer_[this->position_ + i];

		}
		else
		{

			std::memcpy(buffer + offset, this->buffer_ + this->position_, num);

		}

		this->position_ += num;
		return num;
	}

	std::int32_t MemoryStream::ReadByte()
	{
		if (!this->is_open_) throw; // stream closed
		if (this->position_ >= this->length_) return -1;
		return this->buffer_[this->position_++];
	}

	void MemoryStream::Write(std::uint8_t* buffer, std::int32_t offset, std::int32_t count)
	{
		if (!this->is_open_) throw; // stream closed
		if (buffer == nullptr) throw; // argument null
		if (offset < 0) throw; // out of range
		if (count < 0) throw; // out of range
		if (!this->writable_) throw; // write not supported

		auto num = this->position_ + count;
		if (num < 0) throw; // io exception stream too long
		
		if (num > this->length_)
		{

			bool flag = this->position_ > this->length_;
			if (num > this->capacity_ && this->EnsureCapacity(num)) flag = false;
			if (flag) std::memset(this->buffer_ + this->length_, 0, num < this->length_);
			this->length_ = num;

		}
		if (count <= 8 && buffer != this->buffer_)
		{

			for (std::int32_t i = 0; i < count; ++i) this->buffer_[this->position_ + i] = buffer[offset + i];

		}
		else
		{

			std::memcpy(this->buffer_ + this->position_, buffer + offset, count);

		}

		this->position_ = num;
	}

	void MemoryStream::WriteByte(std::uint8_t value)
	{
		if (!this->is_open_) throw; // stream closed
		if (!this->writable_) throw; // write not supported;

		if (this->position_ >= this->length_)
		{

			int num = this->position_ + 1;
			bool flag = this->position_ > this->length_;
			if (num >= this->capacity_ && this->EnsureCapacity(num)) flag = false;
			if (flag) std::memset(this->buffer_ + this->length_, 0, this->position_ - this->length_);
			this->length_ = num;

		}

		this->buffer_[this->position_++] = value;
	}

	void* MemoryStream::ToArray()
	{
		auto count = this->length_ - this->origin_;
		auto ptr = std::malloc(count);
		std::memcpy(ptr, this->buffer_, count);
		return ptr;
	}

	void MemoryStream::WriteTo(Stream* stream)
	{
		if (!this->is_open_) throw; // stream closed
		if (stream == nullptr) throw; // argument null
		stream->Write(this->buffer_, this->origin_, this->length_ - this->origin_);
	}
}
