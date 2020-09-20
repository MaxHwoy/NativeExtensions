#pragma once



namespace NativeExtensions
{
	class Path
	{
	private:
		const static std::int8_t trim_end_chars_[8];
		const static std::int8_t real_invalid_path_chars_[36];
		const static std::int8_t invalid_path_chars_with_additional_checks_[38];
		const static std::int8_t invalid_filename_chars_[41];
		const static std::int8_t base32_char_[32];
		const static std::int32_t max_path_length_;
		const static std::int32_t max_directory_path_;
		const static std::int32_t max_directory_length_;
		const static std::int32_t max_long_path_length_;
		const static std::string long_path_prefix_;
		const static std::string unc_path_prefix_;
		const static std::string unc_long_path_prefix_to_insert_;
		const static std::string unc_long_path_prefix_;

	public:
		/// <summary>Provides a platform-specific character used to separate directory levels in a path string that reflects a hierarchical file system organization.</summary>
		const static std::int8_t DirectorySeparatorChar;

		/// <summary>Provides a platform-specific string used to separate directory levels in a path string that reflects a hierarchical file system organization.</summary>
		const static std::string DirectorSeparatorCharAsString;
		
		/// <summary>Provides a platform-specific alternate character used to separate directory levels in a path string that reflects a hierarchical file system organization.</summary>
		const static std::int8_t AltDirectorySeparatorChar;

		/// <summary>Provides a platform-specific volume separator character.</summary>
		const static std::int8_t VolumeSeparatorChar;

		/// <summary>A platform-specific separator character used to separate path strings in environment variables.</summary>
		const static std::int8_t PathSeparator;

		/// <summary>Provides a platform-specific array of characters that cannot be specified in path string arguments passed to members of the NativeExtensions::Path class.</summary>
		const static std::int8_t InvalidPathChars[36];

	public:
		static void CheckInvalidPathChars(const std::string& path, bool checkAdditional = false);
	};
}
