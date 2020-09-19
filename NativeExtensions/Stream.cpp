#include "pch.h"
#include "Stream.h"



namespace NativeExtensions
{
	void Stream::CopyTo(Stream* destination)
	{
		if (destination == nullptr) throw; // throw null reference exception
		if (!this->CanRead() && !this->CanWrite()) throw; // throw object disposed exception
		if (!destination->CanRead() && !this->CanWrite()) throw; // throw object disposed exception
		if (!this->CanRead()) throw; // throw not supported exception
		if (!destination->CanWrite()) throw; // throw not supported exception
		this->InternalCopyTo(destination, 81920);
	}

	void Stream::CopyTo(Stream* destination, std::int32_t buffer_size)
	{
		if (destination == nullptr) throw; // throw null reference exception
		if (!this->CanRead() && !this->CanWrite()) throw; // throw object disposed exception
		if (!destination->CanRead() && !this->CanWrite()) throw; // throw object disposed exception
		if (!this->CanRead()) throw; // throw not supported exception
		if (!destination->CanWrite()) throw; // throw not supported exception
		this->InternalCopyTo(destination, buffer_size);
	}

	void Stream::InternalCopyTo(Stream* destination, std::int32_t buffer_size)
	{
		auto arr = reinterpret_cast<std::uint8_t*>(std::malloc(buffer_size));
		std::int32_t count;

		while ((count = this->Read(arr, 0, buffer_size)) != 0)
		{

			destination->Write(arr, 0, buffer_size);

		}

		std::free(arr);
	}
}
