#pragma once

constexpr auto StringEmpty = "";
constexpr auto WStringEmpty = L"";


namespace NativeExtensions
{
	template <typename T> using Method = T*;

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

	/// <summary>Represents advanced options for creating a NativeExtensions::FileStream object.</summary>
	enum class FileOptions
	{
		/// <summary>Indicates that no additional options should be used when creating a <see cref="T:System.IO.FileStream" /> object.</summary>
		None = 0x0,
		/// <summary>Indicates that the system should write through any intermediate cache and go directly to disk.</summary>
		WriteThrough = INT32_MAX,
		/// <summary>Indicates that a file can be used for asynchronous reading and writing.</summary>
		Asynchronous = 0x40000000,
		/// <summary>Indicates that the file is accessed randomly. The system can use this as a hint to optimize file caching.</summary>
		RandomAccess = 0x10000000,
		/// <summary>Indicates that a file is automatically deleted when it is no longer in use.</summary>
		DeleteOnClose = 0x4000000,
		/// <summary>Indicates that the file is to be accessed sequentially from beginning to end. The system can use this as a hint to optimize file caching. If an application moves the file pointer for random access, optimum caching may not occur; however, correct operation is still guaranteed.</summary>
		SequentialScan = 0x8000000,
		/// <summary>Indicates that a file is encrypted and can be decrypted only by using the same user account used for encryption.</summary>
		Encrypted = 0x4000
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

	/// <summary>Defines the access rights to use when creating access and audit rules.</summary>
	enum class FileSystemRights
	{
		/// <summary>Specifies the right to open and copy a file or folder.  This does not include the right to read file system attributes, extended file system attributes, or access and audit rules.</summary>
		ReadData = 0x1,
		/// <summary>Specifies the right to read the contents of a directory.</summary>
		ListDirectory = 0x1,
		/// <summary>Specifies the right to open and write to a file or folder.  This does not include the right to open and write file system attributes, extended file system attributes, or access and audit rules.</summary>
		WriteData = 0x2,
		/// <summary>Specifies the right to create a file.</summary>
		CreateFiles = 0x2,
		/// <summary>Specifies the right to append data to the end of a file.</summary>
		AppendData = 0x4,
		/// <summary>Specifies the right to create a folder.</summary>
		CreateDirectories = 0x4,
		/// <summary>Specifies the right to open and copy extended file system attributes from a folder or file.  For example, this value specifies the right to view author and content information.  This does not include the right to read data, file system attributes, or access and audit rules.</summary>
		ReadExtendedAttributes = 0x8,
		/// <summary>Specifies the right to open and write extended file system attributes to a folder or file.  This does not include the ability to write data, attributes, or access and audit rules.</summary>
		WriteExtendedAttributes = 0x10,
		/// <summary>Specifies the right to run an application file.</summary>
		ExecuteFile = 0x20,
		/// <summary>Specifies the right to list the contents of a folder and to run applications contained within that folder.</summary>
		Traverse = 0x20,
		/// <summary>Specifies the right to delete a folder and any files contained within that folder.</summary>
		DeleteSubdirectoriesAndFiles = 0x40,
		/// <summary>Specifies the right to open and copy file system attributes from a folder or file.  For example, this value specifies the right to view the file creation or modified date.  This does not include the right to read data, extended file system attributes, or access and audit rules.</summary>
		ReadAttributes = 0x80,
		/// <summary>Specifies the right to open and write file system attributes to a folder or file. This does not include the ability to write data, extended attributes, or access and audit rules.</summary>
		WriteAttributes = 0x100,
		/// <summary>Specifies the right to delete a folder or file.</summary>
		Delete = 0x10000,
		/// <summary>Specifies the right to open and copy access and audit rules from a folder or file.  This does not include the right to read data, file system attributes, and extended file system attributes.</summary>
		ReadPermissions = 0x20000,
		/// <summary>Specifies the right to change the security and audit rules associated with a file or folder.</summary>
		ChangePermissions = 0x40000,
		/// <summary>Specifies the right to change the owner of a folder or file.  Note that owners of a resource have full access to that resource.</summary>
		TakeOwnership = 0x80000,
		/// <summary>Specifies whether the application can wait for a file handle to synchronize with the completion of an I/O operation.</summary>
		Synchronize = 0x100000,
		/// <summary>Specifies the right to exert full control over a folder or file, and to modify access control and audit rules.  This value represents the right to do anything with a file and is the combination of all rights in this enumeration.</summary>
		FullControl = 0x1F01FF,
		/// <summary>Specifies the right to open and copy folders or files as read-only.  This right includes the <see cref="F:System.Security.AccessControl.FileSystemRights.ReadData" /> right, <see cref="F:System.Security.AccessControl.FileSystemRights.ReadExtendedAttributes" /> right, <see cref="F:System.Security.AccessControl.FileSystemRights.ReadAttributes" /> right, and <see cref="F:System.Security.AccessControl.FileSystemRights.ReadPermissions" /> right.</summary>
		Read = 0x20089,
		/// <summary>Specifies the right to open and copy folders or files as read-only, and to run application files.  This right includes the <see cref="F:System.Security.AccessControl.FileSystemRights.Read" /> right and the <see cref="F:System.Security.AccessControl.FileSystemRights.ExecuteFile" /> right.</summary>
		ReadAndExecute = 0x200A9,
		/// <summary>Specifies the right to create folders and files, and to add or remove data from files.  This right includes the <see cref="F:System.Security.AccessControl.FileSystemRights.WriteData" /> right, <see cref="F:System.Security.AccessControl.FileSystemRights.AppendData" /> right, <see cref="F:System.Security.AccessControl.FileSystemRights.WriteExtendedAttributes" /> right, and <see cref="F:System.Security.AccessControl.FileSystemRights.WriteAttributes" /> right.</summary>
		Write = 0x116,
		/// <summary>Specifies the right to read, write, list folder contents, delete folders and files, and run application files.  This right includes the <see cref="F:System.Security.AccessControl.FileSystemRights.ReadAndExecute" /> right, the <see cref="F:System.Security.AccessControl.FileSystemRights.Write" /> right, and the <see cref="F:System.Security.AccessControl.FileSystemRights.Delete" /> right.</summary>
		Modify = 0x301BF
	};
}
