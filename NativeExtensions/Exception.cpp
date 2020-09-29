#include "pch.h"
#include "Exception.h"



namespace NativeExtensions
{
	ArgumentException::ArgumentException() : exception("Parameter is invalid, incorrect, or nullptr")
	{
	}

	ArgumentException::ArgumentException(const char* const message) : exception(message)
	{
	}

	ArgumentException::ArgumentException(const std::string& message) : exception(message.c_str())
	{
	}


}
