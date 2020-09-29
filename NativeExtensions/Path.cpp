#include "pch.h"
#include "Path.h"
#include <filesystem>

#pragma warning (disable : 4566)

namespace NativeExtensions::IO
{
	const std::int8_t Path::trim_end_chars_[8] = {
		'\t',
		'\n',
		'\v',
		'\f',
		'\r',
		' ',
		'\u0085',
		'\u00a0'
	};
	const std::int8_t Path::real_invalid_path_chars_[36] = {
		'"',
		'<',
		'>',
		'|',
		'\0',
		'\u0001',
		'\u0002',
		'\u0003',
		'\u0004',
		'\u0005',
		'\u0006',
		'\a',
		'\b',
		'\t',
		'\n',
		'\v',
		'\f',
		'\r',
		'\u000e',
		'\u000f',
		'\u0010',
		'\u0011',
		'\u0012',
		'\u0013',
		'\u0014',
		'\u0015',
		'\u0016',
		'\u0017',
		'\u0018',
		'\u0019',
		'\u001a',
		'\u001b',
		'\u001c',
		'\u001d',
		'\u001e',
		'\u001f'
	};
	const std::int8_t Path::invalid_path_chars_with_additional_checks_[38] = {
		'"',
		'<',
		'>',
		'|',
		'\0',
		'\u0001',
		'\u0002',
		'\u0003',
		'\u0004',
		'\u0005',
		'\u0006',
		'\a',
		'\b',
		'\t',
		'\n',
		'\v',
		'\f',
		'\r',
		'\u000e',
		'\u000f',
		'\u0010',
		'\u0011',
		'\u0012',
		'\u0013',
		'\u0014',
		'\u0015',
		'\u0016',
		'\u0017',
		'\u0018',
		'\u0019',
		'\u001a',
		'\u001b',
		'\u001c',
		'\u001d',
		'\u001e',
		'\u001f',
		'*',
		'?'
	};
	const std::int8_t Path::invalid_filename_chars_[41] = {
		'"',
		'<',
		'>',
		'|',
		'\0',
		'\u0001',
		'\u0002',
		'\u0003',
		'\u0004',
		'\u0005',
		'\u0006',
		'\a',
		'\b',
		'\t',
		'\n',
		'\v',
		'\f',
		'\r',
		'\u000e',
		'\u000f',
		'\u0010',
		'\u0011',
		'\u0012',
		'\u0013',
		'\u0014',
		'\u0015',
		'\u0016',
		'\u0017',
		'\u0018',
		'\u0019',
		'\u001a',
		'\u001b',
		'\u001c',
		'\u001d',
		'\u001e',
		'\u001f',
		':',
		'*',
		'?',
		'\\',
		'/'
	};
	const std::int8_t Path::base32_char_[32] = {
		'a',
		'b',
		'c',
		'd',
		'e',
		'f',
		'g',
		'h',
		'i',
		'j',
		'k',
		'l',
		'm',
		'n',
		'o',
		'p',
		'q',
		'r',
		's',
		't',
		'u',
		'v',
		'w',
		'x',
		'y',
		'z',
		'0',
		'1',
		'2',
		'3',
		'4',
		'5'
	};
	const std::int32_t Path::max_path_length_ = 260;
	const std::int32_t Path::max_directory_path_ = 248;
	const std::int32_t Path::max_directory_length_ = 255;
	const std::int32_t Path::max_long_path_length_ = 32767;
	const std::string Path::long_path_prefix_ = "\\\\?\\";
	const std::string Path::unc_path_prefix_ = "\\\\";
	const std::string unc_long_path_prefix_to_insert_ = "?\\UNC\\";
	const std::string unc_long_path_prefix_ = "\\\\?\\UNC\\";

	const std::int8_t Path::DirectorySeparatorChar = '\\';
	const std::string Path::DirectorSeparatorCharAsString = "\\";
	const std::int8_t Path::AltDirectorySeparatorChar = '/';
	const std::int8_t Path::VolumeSeparatorChar = ':';
	const std::int8_t Path::PathSeparator = ';';
	const std::int8_t Path::InvalidPathChars[36] = {
		'"',
		'<',
		'>',
		'|',
		'\0',
		'\u0001',
		'\u0002',
		'\u0003',
		'\u0004',
		'\u0005',
		'\u0006',
		'\a',
		'\b',
		'\t',
		'\n',
		'\v',
		'\f',
		'\r',
		'\u000e',
		'\u000f',
		'\u0010',
		'\u0011',
		'\u0012',
		'\u0013',
		'\u0014',
		'\u0015',
		'\u0016',
		'\u0017',
		'\u0018',
		'\u0019',
		'\u001a',
		'\u001b',
		'\u001c',
		'\u001d',
		'\u001e',
		'\u001f'
	};

	void Path::CheckInvalidPathChars(const std::string& path, bool checkAdditional)
	{
		
	}
}
