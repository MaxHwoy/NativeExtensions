#pragma once



namespace NativeExtensions::IO
{
	class Stream
	{
	private:
		void InternalCopyTo(Stream* destination, std::int32_t buffer_size);

	public:
		virtual bool CanRead() = 0;
		virtual bool CanSeek() = 0;
		virtual bool CanWrite() = 0;
		virtual std::int64_t Position() = 0;
		virtual std::int64_t Length() = 0;
		virtual void Position(std::int64_t position) = 0;
		virtual void Length(std::int64_t length) = 0;

		void CopyTo(Stream* destination);
		void CopyTo(Stream* destination, std::int32_t buffer_size);
		virtual void Close() = 0;
		virtual void Flush() = 0;
		virtual std::int64_t Seek(std::int64_t offset, SeekOrigin origin) = 0;
		virtual std::int32_t Read(std::uint8_t* buffer, std::int32_t offset, std::int32_t count) = 0;
		virtual std::int32_t ReadByte() = 0;
		virtual void Write(std::uint8_t* buffer, std::int32_t offset, std::int32_t count) = 0;
		virtual void WriteByte(std::uint8_t value) = 0;
	};
}
