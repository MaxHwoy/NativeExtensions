#include "pch.h"
#include "Error.h"
#include "Path.h"
#include "Stream.h"
#include "FileStream.h"




namespace NativeExtensions
{
	const const wchar_t* FileStream::unknown_filename_ = L"<UnknownFilename>";
	const std::int32_t FileStream::default_buffer_size_ = 0x1000;
	const std::int32_t FileStream::FILE_FLAG_OVERLAPPED = 0x40000000;
	const std::int32_t FileStream::FILE_BEGIN = 0x00;
	const std::int32_t FileStream::FILE_CURRENT = 0x01;
	const std::int32_t FileStream::FILE_END = 0x02;
	const std::int32_t FileStream::ERROR_BROKEN_PIPE = 0x6D;
	const std::int32_t FileStream::ERROR_NO_DATA = 0xE8;
	const std::int32_t FileStream::ERROR_HANDLE_EOF = 0x26;
	const std::int32_t FileStream::ERROR_INVALID_PARAMETER = 0x57;
	const std::int32_t FileStream::ERROR_IO_PENDING = 0x03E5;

	FileStream::FileStream()
	{
		this->handle_ = nullptr;
		this->append_start_ = 0;
		this->buffer_ = nullptr;
		this->buffer_size_ = 0;
		this->is_async_ = false;
		this->can_read_ = this->can_seek_ = this->can_write_ = false;
		this->exposed_handle_ = false;
		this->filename_ = WStringEmpty;
		this->is_pipe_ = false;
		this->pos_ = this->read_pos_ = this->read_len_ = this->write_pos_ = 0;
	}

	FileStream::FileStream(const std::wstring& path, FileMode mode, FileAccess access, FileShare share, std::int32_t bufferSize, FileOptions options, const std::wstring& msgPath, bool bFromProxy)
	{
		auto attr = SecurityAttributes();
		auto ptr = &attr;
		if (!FileStream::GetSecAttrs(ptr, share)) ptr = nullptr;
		this->Init(path, mode, access, 0, false, share, bufferSize, options, ptr, msgPath, bFromProxy, false, false);
	}

	FileStream::FileStream(const std::wstring& path, FileMode mode, FileAccess access, FileShare share, std::int32_t bufferSize, FileOptions options, const std::wstring& msgPath, bool bFromProxy, bool useLongPath)
	{
		auto attr = SecurityAttributes();
		auto ptr = &attr;
		if (!FileStream::GetSecAttrs(ptr, share)) ptr = nullptr;
		this->Init(path, mode, access, 0, false, share, bufferSize, options, ptr, msgPath, bFromProxy, useLongPath, false);
	}

	FileStream::FileStream(const std::wstring& path, FileMode mode, FileAccess access, FileShare share, std::int32_t bufferSize, FileOptions options, const std::wstring& msgPath, bool bFromProxy, bool useLongPath, bool checkHost)
	{
		auto attr = SecurityAttributes();
		auto ptr = &attr;
		if (!FileStream::GetSecAttrs(ptr, share)) ptr = nullptr;
		this->Init(path, mode, access, 0, false, share, bufferSize, options, ptr, msgPath, bFromProxy, useLongPath, checkHost);
	}

	FileStream::FileStream(const wchar_t* path, FileMode mode)
		: FileStream(std::wstring(path), mode)
	{
	}

	FileStream::FileStream(const wchar_t* path, FileMode mode, FileAccess access)
		: FileStream(std::wstring(path), mode, access)
	{
	}

	FileStream::FileStream(const wchar_t* path, FileMode mode, FileAccess access, FileShare share)
		: FileStream(std::wstring(path), mode, access, share)
	{
	}

	FileStream::FileStream(const wchar_t* path, FileMode mode, FileAccess access, FileShare share, std::int32_t bufferSize)
		: FileStream(std::wstring(path), mode, access, share, bufferSize)
	{
	}

	FileStream::FileStream(const wchar_t* path, FileMode mode, FileAccess access, FileShare share, std::int32_t bufferSize, FileOptions options)
		: FileStream(std::wstring(path), mode, access, share, bufferSize, options)
	{
	}

	FileStream::FileStream(const wchar_t* path, FileMode mode, FileAccess access, FileShare share, std::int32_t bufferSize, bool useAsync)
		: FileStream(std::wstring(path), mode, access, share, bufferSize, useAsync)
	{
	}

	FileStream::FileStream(const wchar_t* path, FileMode mode, FileSystemRights rights, FileShare share, std::int32_t bufferSize, FileOptions options)
		: FileStream(std::wstring(path), mode, rights, share, bufferSize, options)
	{
	}

	FileStream::FileStream(const wchar_t* path, FileMode mode, FileSystemRights rights, FileShare share, std::int32_t bufferSize, FileOptions options, FileSecurity fileSecurity)
		: FileStream(std::wstring(path), mode, rights, share, bufferSize, options, fileSecurity)
	{
	}

	FileStream::FileStream(const std::wstring& path, FileMode mode) : FileStream
	(
		path,
		mode,
		mode == FileMode::Append ? FileAccess::Write : FileAccess::ReadWrite,
		FileShare::Read,
		4096,
		FileOptions::None,
		Path::GetFileName(path),
		false
	)
	{
	}

	FileStream::FileStream(const std::wstring& path, FileMode mode, FileAccess access) : FileStream
	(
		path,
		mode,
		access,
		FileShare::Read,
		4096,
		FileOptions::None,
		Path::GetFileName(path),
		false
	)
	{
	}

	FileStream::FileStream(const std::wstring& path, FileMode mode, FileAccess access, FileShare share) : FileStream
	(
		path,
		mode,
		access,
		share,
		4096,
		FileOptions::None,
		Path::GetFileName(path),
		false
	)
	{
	}

	FileStream::FileStream(const std::wstring& path, FileMode mode, FileAccess access, FileShare share, std::int32_t bufferSize) : FileStream
	(
		path,
		mode,
		access,
		share,
		bufferSize,
		FileOptions::None,
		Path::GetFileName(path),
		false
	)
	{
	}
	
	FileStream::FileStream(const std::wstring& path, FileMode mode, FileAccess access, FileShare share, std::int32_t bufferSize, FileOptions options) : FileStream
	(
		path,
		mode,
		access,
		share,
		bufferSize,
		options,
		Path::GetFileName(path),
		false
	)
	{
	}
	
	FileStream::FileStream(const std::wstring& path, FileMode mode, FileAccess access, FileShare share, std::int32_t bufferSize, bool useAsync) : FileStream
	(
		path,
		mode,
		access,
		share,
		bufferSize,
		useAsync ? FileOptions::Asynchronous : FileOptions::None,
		Path::GetFileName(path),
		false
	)
	{
	}
	
	FileStream::FileStream(const std::wstring& path, FileMode mode, FileSystemRights rights, FileShare share, std::int32_t bufferSize, FileOptions options)
	{

	}
	
	FileStream::FileStream(const std::wstring& path, FileMode mode, FileSystemRights rights, FileShare share, std::int32_t bufferSize, FileOptions options, FileSecurity fileSecurity)
	{

	}

	void FileStream::Init(const std::wstring& path, FileMode mode, FileAccess access, std::int32_t rights, bool useRights, FileShare share, std::int32_t bufferSize, FileOptions options, SecurityAttributes* secAttrs, const std::wstring& msgPath, bool bFromProxy, bool useLongPath, bool checkHost)
	{
		if (path == WStringEmpty) throw; // empty path
		this->filename_ = std::wstring(msgPath);
		this->exposed_handle_ = false;
		auto fileShare = (std::int32_t)share & ~((std::int32_t)FileShare::Inheritable);
		const char* text = nullptr;

		if (mode == FileMode::CreateNew || mode > FileMode::Append) text = "mode";
		else if (!useRights && (access < FileAccess::Read || access > FileAccess::ReadWrite)) text = "access";
		else if (useRights && (rights < 1 || rights > 0x1F01FF)) text = "rights";
		else if (fileShare < 0 || fileShare > 7) text = "share";
		if (text != nullptr) throw; // argument out of range "text"
		if (options != FileOptions::None && ((std::int32_t)options & 0x03FFBFFF) != 0) throw; // out of range
		if (bufferSize <= 0) throw; // out of range

		if (((!useRights && ((std::int32_t)access & 2) == 0) || (useRights && (rights & 0x116) == 0)) && (mode == FileMode::Truncate || mode == FileMode::CreateNew || mode == FileMode::Create || mode == FileMode::Append))
		{

			if (!useRights) throw; // Argument_InvalidFileMode&AccessCombo
			throw; // Argument_InvalidFileMode&RightsCombo
		
		}
		if (useRights && mode == FileMode::Truncate)
		{
			if (rights != 278) throw; // Argument_InvalidFileModeTruncate&RightsCombo
			useRights = false;
			access = FileAccess::Write;

		}

		std::int32_t dwDesiredAccess;
		if (useRights) dwDesiredAccess = rights;
		else switch (access)
		{
		case FileAccess::Read: dwDesiredAccess = 0; break;
		case FileAccess::Write: dwDesiredAccess = 0x40000000; break;
		default: dwDesiredAccess = 0xC0000000; break;
		}

		std::int32_t maxPathLength = useLongPath ? 32767 : 260;
		
	}


	bool FileStream::CanRead()
	{
		return this->can_read_;
	}

	bool FileStream::CanSeek()
	{
		return this->can_seek_;
	}

	bool FileStream::CanWrite()
	{
		return this->can_write_;
	}

	std::int64_t FileStream::Position()
	{
		if (!this->handle_) throw; // file not open
		if (!this->can_seek_) throw; // seek not supported
		if (this->exposed_handle_) this->VerifyOSHandlePosition();
		return this->pos_ + (this->read_pos_ - this->read_len_ + this->write_pos_);
	}

	std::int64_t FileStream::Length()
	{
		if (!this->handle_) throw; // file closed
		if (!this->can_seek_) throw; // seek not supported

		std::uint32_t highSize = 0;
		std::uint32_t num = ::GetFileSize(this->handle_, (LPDWORD)&highSize);

		if (num == UINT32_MAX)
		{

			//auto error = ::GetLastError();
			//if (error != 0) Error::WinIOError(error, StringEmpty);

		}

		std::int64_t size = ((std::int64_t)highSize << 32) | num;
		auto max = this->pos_ + this->write_pos_;
		if (this->write_pos_ > 0 && max > size) size = max;
		return size;
	}

	void FileStream::Position(std::int64_t position)
	{
		if (position < 0) throw; // argument out of range
		//if (this->write_pos_ > 0) this->FlushWrite(calledFromFinalizer: false);
		this->read_pos_ = 0;
		this->read_len_ = 0;
		this->Seek(position, SeekOrigin::Begin);
	}

	void FileStream::Length(std::int64_t length)
	{
		if (length < 0) throw; // argument out of range
		if (!this->handle_) throw; // file not open
		if (!this->can_seek_) throw; // seek not supported
		if (!this->can_write_) throw; // write not supported
		//if (this->write_pos_ > 0) this->FlushWrite(calledFromFinalizer: false);
		//else if (this->read_pos_ < this->read_len_) this->FlushRead();
		this->read_pos_ = 0;
		this->read_len_ = 0;
		if (this->append_start_ != -1 && length < this->append_start_) throw; // io exception
		this->SetLengthCore(length);
	}

	std::wstring FileStream::Name()
	{
		if (this->filename_ == WStringEmpty) return this->unknown_filename_;
		// we need to get permissions ???
		return this->filename_;
	}

	std::wstring FileStream::InternalName()
	{
		return this->filename_ == WStringEmpty ? this->unknown_filename_ : this->filename_;
	}

	HANDLE FileStream::FileHandle()
	{
		this->Flush();
		this->read_pos_ = 0;
		this->read_len_ = 0;
		this->write_pos_ = 0;
		this->exposed_handle_ = true;
		return this->handle_;
	}

	bool FileStream::GetSecAttrs(SecurityAttributes* attributes, FileShare share)
	{
		if (((std::int32_t)share & (std::int32_t)FileShare::Inheritable) != 0)
		{

			attributes->nLength = sizeof(SecurityAttributes);
			attributes->bInheritHandle = 1;
			return true;

		}
		else return false;
	}
}
