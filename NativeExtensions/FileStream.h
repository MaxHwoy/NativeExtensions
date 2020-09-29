#pragma once



namespace NativeExtensions::IO
{
	struct SecurityAttributes
	{
		std::int32_t nLength = 0;
		std::uint8_t* pSecurityDescriptor = nullptr;
		std::int32_t bInheritHandle = 0;
	};

	class FileSecurity
	{

	};

	class FileStream : public Stream
	{
	private:
		const static const wchar_t* unknown_filename_;
		const static std::int32_t default_buffer_size_;
		std::uint8_t* buffer_;
		std::wstring filename_;
		bool is_async_;
		bool can_read_;
		bool can_seek_;
		bool can_write_;
		bool exposed_handle_;
		bool is_pipe_;
		std::int32_t read_pos_;
		std::int32_t read_len_;
		std::int32_t write_pos_;
		std::int32_t buffer_size_;
		HANDLE* handle_;
		std::int64_t pos_;
		std::int64_t append_start_;

		//const static std::int32_t FILE_FLAG_OVERLAPPED;
		//const static std::int32_t FILE_BEGIN;
		//const static std::int32_t FILE_CURRENT;
		//const static std::int32_t FILE_END;
		//const static std::int32_t ERROR_BROKEN_PIPE;
		//const static std::int32_t ERROR_NO_DATA;
		//const static std::int32_t ERROR_HANDLE_EOF;
		//const static std::int32_t ERROR_INVALID_PARAMETER;
		//const static std::int32_t ERROR_IO_PENDING;

	private:
		FileStream();
		FileStream(const std::wstring& path, FileMode mode, FileAccess access, FileShare share, std::int32_t bufferSize, FileOptions options, const std::wstring& msgPath, bool bFromProxy);
		FileStream(const std::wstring& path, FileMode mode, FileAccess access, FileShare share, std::int32_t bufferSize, FileOptions options, const std::wstring& msgPath, bool bFromProxy, bool useLongPath);
		FileStream(const std::wstring& path, FileMode mode, FileAccess access, FileShare share, std::int32_t bufferSize, FileOptions options, const std::wstring& msgPath, bool bFromProxy, bool useLongPath, bool checkHost);

	public:
		FileStream(const wchar_t* path, FileMode mode);
		FileStream(const wchar_t* path, FileMode mode, FileAccess access);
		FileStream(const wchar_t* path, FileMode mode, FileAccess access, FileShare share);
		FileStream(const wchar_t* path, FileMode mode, FileAccess access, FileShare share, std::int32_t bufferSize);
		FileStream(const wchar_t* path, FileMode mode, FileAccess access, FileShare share, std::int32_t bufferSize, FileOptions options);
		FileStream(const wchar_t* path, FileMode mode, FileAccess access, FileShare share, std::int32_t bufferSize, bool useAsync);
		FileStream(const wchar_t* path, FileMode mode, FileSystemRights rights, FileShare share, std::int32_t bufferSize, FileOptions options);
		FileStream(const wchar_t* path, FileMode mode, FileSystemRights rights, FileShare share, std::int32_t bufferSize, FileOptions options, FileSecurity fileSecurity);
		FileStream(const std::wstring& path, FileMode mode);
		FileStream(const std::wstring& path, FileMode mode, FileAccess access);
		FileStream(const std::wstring& path, FileMode mode, FileAccess access, FileShare share);
		FileStream(const std::wstring& path, FileMode mode, FileAccess access, FileShare share, std::int32_t bufferSize);
		FileStream(const std::wstring& path, FileMode mode, FileAccess access, FileShare share, std::int32_t bufferSize, FileOptions options);
		FileStream(const std::wstring& path, FileMode mode, FileAccess access, FileShare share, std::int32_t bufferSize, bool useAsync);
		FileStream(const std::wstring& path, FileMode mode, FileSystemRights rights, FileShare share, std::int32_t bufferSize, FileOptions options);
		FileStream(const std::wstring& path, FileMode mode, FileSystemRights rights, FileShare share, std::int32_t bufferSize, FileOptions options, FileSecurity fileSecurity);

	private:
		std::wstring InternalName();
		void VerifyOSHandlePosition();
		void SetLengthCore(std::int64_t length);
		static bool GetSecAttrs(SecurityAttributes* attributes, FileShare share);
		void Init(const std::wstring& path, FileMode mode, FileAccess access, std::int32_t rights, bool useRights, FileShare share, std::int32_t bufferSize, FileOptions options, SecurityAttributes* secAttrs, const std::wstring& msgPath, bool bFromProxy, bool useLongPath, bool checkHost);
		
	public:
		bool CanRead() override;
		bool CanSeek() override;
		bool CanWrite() override;
		std::int64_t Position() override;
		std::int64_t Length() override;
		void Position(std::int64_t position) override;
		void Length(std::int64_t length) override;
		std::wstring Name();
		virtual HANDLE FileHandle();
	};
}
