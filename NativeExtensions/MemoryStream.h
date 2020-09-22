#pragma once



namespace NativeExtensions
{
	class MemoryStream : Stream
	{
	private:
		std::uint8_t* buffer_;
		std::int32_t origin_;
		std::int32_t position_;
		std::int32_t length_;
		std::int32_t capacity_;
		bool expandable_;
		bool writable_;
		bool exposable_;
		bool is_open_;
		bool dealloc_;
		bool disposed_;
		const static std::int32_t memory_stream_max_length_;

	public:
		MemoryStream();
		MemoryStream(std::int32_t capacity);
		MemoryStream(void* buffer, std::int32_t length, bool deallocOnDestruct);
		MemoryStream(void* buffer, std::int32_t length, bool writable, bool deallocOnDestruct);
		MemoryStream(void* buffer, std::int32_t index, std::int32_t count, bool deallocOnDestruct);
		MemoryStream(void* buffer, std::int32_t index, std::int32_t count, bool writable, bool deallocOnDestruct);
		MemoryStream(void* buffer, std::int32_t index, std::int32_t count, bool writable, bool publicallyVisible, bool deallocOnDestruct);
		~MemoryStream();

	private:
		bool EnsureCapacity(std::int32_t capacity);

	public:
		bool CanRead() override;
		bool CanSeek() override;
		bool CanWrite() override;
		virtual std::int32_t Capacity();
		std::int64_t Position() override;
		std::int64_t Length() override;
		virtual void Capacity(std::int32_t capacity);
		void Position(std::int64_t position) override;
		void Length(std::int64_t length) override;
		void Close() override;
		void Flush() override;
		void* GetBufferPointer();
		std::int64_t Seek(std::int64_t offset, SeekOrigin origin) override;
		std::int32_t Read(std::uint8_t* buffer, std::int32_t offset, std::int32_t count) override;
		std::int32_t ReadByte() override;
		void Write(std::uint8_t* buffer, std::int32_t offset, std::int32_t count) override;
		void WriteByte(std::uint8_t value) override;
		virtual void* ToArray();
		virtual void WriteTo(Stream* stream);
	};
}
