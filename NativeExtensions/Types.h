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

	/// <summary>Defines constants for read, write, or read/write access to a file.</summary>
	enum class FileAccess
	{
		/// <summary>Read access to the file. Data can be read from the file. Combine with <see langword="Write" /> for read/write access.</summary>
		Read = 0x1,
		/// <summary>Write access to the file. Data can be written to the file. Combine with <see langword="Read" /> for read/write access.</summary>
		Write = 0x2,
		/// <summary>Read and write access to the file. Data can be written to and read from the file.</summary>
		ReadWrite = 0x3,
	};

	/// <summary>Provides attributes for files and directories.</summary>
	enum class FileAttributes
	{
		/// <summary>The file is read-only.</summary>
		ReadOnly = 0x1,
		/// <summary>The file is hidden, and thus is not included in an ordinary directory listing.</summary>
		Hidden = 0x2,
		/// <summary>The file is a system file. That is, the file is part of the operating system or is used exclusively by the operating system.</summary>
		System = 0x4,
		/// <summary>The file is a directory.</summary>
		Directory = 0x10,
		/// <summary>The file is a candidate for backup or removal.</summary>
		Archive = 0x20,
		/// <summary>Reserved for future use.</summary>
		Device = 0x40,
		/// <summary>The file is a standard file that has no special attributes. This attribute is valid only if it is used alone.</summary>
		Normal = 0x80,
		/// <summary>The file is temporary. A temporary file contains data that is needed while an application is executing but is not needed after the application is finished. File systems try to keep all the data in memory for quicker access rather than flushing the data back to mass storage. A temporary file should be deleted by the application as soon as it is no longer needed.</summary>
		Temporary = 0x100,
		/// <summary>The file is a sparse file. Sparse files are typically large files whose data consists of mostly zeros.</summary>
		SparseFile = 0x200,
		/// <summary>The file contains a reparse point, which is a block of user-defined data associated with a file or a directory.</summary>
		ReparsePoint = 0x400,
		/// <summary>The file is compressed.</summary>
		Compressed = 0x800,
		/// <summary>The file is offline. The data of the file is not immediately available.</summary>
		Offline = 0x1000,
		/// <summary>The file will not be indexed by the operating system's content indexing service.</summary>
		NotContentIndexed = 0x2000,
		/// <summary>The file or directory is encrypted. For a file, this means that all data in the file is encrypted. For a directory, this means that encryption is the default for newly created files and directories.</summary>
		Encrypted = 0x4000,
		/// <summary>The file or directory includes data integrity support. When this value is applied to a file, all data streams in the file have integrity support. When this value is applied to a directory, all new files and subdirectories within that directory, by default, include integrity support.</summary>
		IntegrityStream = 0x8000,
		/// <summary>The file or directory is excluded from the data integrity scan. When this value is applied to a directory, by default, all new files and subdirectories within that directory are excluded from data integrity.</summary>
		NoScrubData = 0x20000,
	};

	/// <summary>Specifies how the operating system should open a file.</summary>
	enum class FileMode
	{
		/// <summary>Specifies that the operating system should create a new file. This requires <see cref="F:System.Security.Permissions.FileIOPermissionAccess.Write" /> permission. If the file already exists, an <see cref="T:System.IO.IOException" /> exception is thrown.</summary>
		CreateNew = 1,
		/// <summary>Specifies that the operating system should create a new file. If the file already exists, it will be overwritten. This requires <see cref="F:System.Security.Permissions.FileIOPermissionAccess.Write" /> permission. <see langword="FileMode.Create" /> is equivalent to requesting that if the file does not exist, use <see cref="F:System.IO.FileMode.CreateNew" />; otherwise, use <see cref="F:System.IO.FileMode.Truncate" />. If the file already exists but is a hidden file, an <see cref="T:System.UnauthorizedAccessException" /> exception is thrown.</summary>
		Create,
		/// <summary>Specifies that the operating system should open an existing file. The ability to open the file is dependent on the value specified by the <see cref="T:System.IO.FileAccess" /> enumeration. A <see cref="T:System.IO.FileNotFoundException" /> exception is thrown if the file does not exist.</summary>
		Open,
		/// <summary>Specifies that the operating system should open a file if it exists; otherwise, a new file should be created. If the file is opened with <see langword="FileAccess.Read" />, <see cref="F:System.Security.Permissions.FileIOPermissionAccess.Read" /> permission is required. If the file access is <see langword="FileAccess.Write" />, <see cref="F:System.Security.Permissions.FileIOPermissionAccess.Write" /> permission is required. If the file is opened with <see langword="FileAccess.ReadWrite" />, both <see cref="F:System.Security.Permissions.FileIOPermissionAccess.Read" /> and <see cref="F:System.Security.Permissions.FileIOPermissionAccess.Write" /> permissions are required.</summary>
		OpenOrCreate,
		/// <summary>Specifies that the operating system should open an existing file. When the file is opened, it should be truncated so that its size is zero bytes. This requires <see cref="F:System.Security.Permissions.FileIOPermissionAccess.Write" /> permission. Attempts to read from a file opened with <see langword="FileMode.Truncate" /> cause an <see cref="T:System.ArgumentException" /> exception.</summary>
		Truncate,
		/// <summary>Opens the file if it exists and seeks to the end of the file, or creates a new file. This requires <see cref="F:System.Security.Permissions.FileIOPermissionAccess.Append" /> permission. <see langword="FileMode.Append" /> can be used only in conjunction with <see langword="FileAccess.Write" />. Trying to seek to a position before the end of the file throws an <see cref="T:System.IO.IOException" /> exception, and any attempt to read fails and throws a <see cref="T:System.NotSupportedException" /> exception.</summary>
		Append,
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
		Inheritable = 0x10,
	};
}
