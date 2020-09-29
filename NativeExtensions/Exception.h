#pragma once



namespace NativeExtensions
{
	/// <summary>The exception that is thrown when one of the arguments provided to a method is not valid.</summary>
	class ArgumentException : public std::exception
	{
	public:
		explicit ArgumentException();
		explicit ArgumentException(const char* const message);
		explicit ArgumentException(const std::string& message);
	};

	/// <summary>The exception that is thrown when a null pointer is passed to a function that does not accept it as a valid argument.</summary>
	class ArgumentNullPtrException : public std::exception
	{
	public:
		explicit ArgumentNullPtrException();
		explicit ArgumentNullPtrException(const char* const message);
		explicit ArgumentNullPtrException(const std::string& message);
	};

	/// <summary>The exception that is thrown when the value of an argument is outside the allowable range of values as defined by the invoked method.</summary>
	class ArgumentOutOfRangeException : public std::exception
	{
	public:
		explicit ArgumentOutOfRangeException();
		explicit ArgumentOutOfRangeException(const char* const message);
		explicit ArgumentOutOfRangeException(const std::string& message);
	};

	/// <summary>The exception that is thrown when there is an attempt to dereference a null pointer.</summary>
	class NullPtrPointerException : public std::exception
	{
	public:
		explicit NullPtrPointerException();
		explicit NullPtrPointerException(const char* const message);
		explicit NullPtrPointerException(const std::string& message);
	};

	/// <summary>The exception that is thrown when an invoked method is not supported, or when there is an attempt to read, seek, or write to a stream that does not support the invoked functionality.</summary>
	class NotSupportedException : public std::exception
	{
	public:
		explicit NotSupportedException();
		explicit NotSupportedException(const char* const message);
		explicit NotSupportedException(const std::string& message);
	};

	/// <summary>The exception that is thrown when an operation is performed on a disposed object.</summary>
	class ObjectDisposedException : public std::exception
	{
	public:
		explicit ObjectDisposedException();
		explicit ObjectDisposedException(const char* const message);
		explicit ObjectDisposedException(const std::string& message);
	};
}
