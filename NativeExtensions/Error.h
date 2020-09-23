#pragma once



namespace NativeExtensions
{
	class Error
	{
	public:
		static std::string WinIOError(std::int32_t winError, std::string maybeFullPath);
	};
}
