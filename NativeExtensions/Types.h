#pragma once



namespace NativeExtensions
{
	/// <summary>Specifies the position in a stream to use for seeking.</summary>
	enum class SeekOrigin
	{
		/// <summary>Specifies the beginning of a stream.</summary>
		Begin,
		/// <summary>Specifies the current position within a stream.</summary>
		Current,
		/// <summary>Specifies the end of a stream.</summary>
		End,
	};

	/// <summary>Contains constants for controlling the kind of access other NativeExtensions::FileStream objects can have to the same file.</summary>
	enum class FileShare
	{
		/// <summary>Declines sharing of the current file. Any request to open the file (by this process or another process) will fail until the file is closed.</summary>
		None = 0x0,
		/// <summary>Allows subsequent opening of the file for reading. If this flag is not specified, any request to open the file for reading (by this process or another process) will fail until the file is closed. However, even if this flag is specified, additional permissions might still be needed to access the file.</summary>
		Read = 0x1,
		/// <summary>Allows subsequent opening of the file for writing. If this flag is not specified, any request to open the file for writing (by this process or another process) will fail until the file is closed. However, even if this flag is specified, additional permissions might still be needed to access the file.</summary>
		Write = 0x2,
		/// <summary>Allows subsequent opening of the file for reading or writing. If this flag is not specified, any request to open the file for reading or writing (by this process or another process) will fail until the file is closed. However, even if this flag is specified, additional permissions might still be needed to access the file.</summary>
		ReadWrite = 0x3,
		/// <summary>Allows subsequent deleting of a file.</summary>
		Delete = 0x4,
		/// <summary>Makes the file handle inheritable by child processes. This is not directly supported by Win32.</summary>
		Inheritable = 0x10
	};
}
