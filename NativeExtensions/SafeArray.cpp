#include "pch.h"
#include "SafeArray.h"



namespace NativeExtensions
{
	template <typename T> SafeArray<T>::SafeArray(std::int32_t count)
	{
		if (count <= 0) throw; // argument out of range;
		this->ptr_ = new T[count];
		this->length_ = count;
		this->dealloc_ = false;
	}

	template <typename T> SafeArray<T>::SafeArray(const SafeArray<T>& safeArray)
	{
		this->dealloc_ = false;
		this->length_ = safeArray.length_;
		this->ptr_ = new T[this->length_];
		std::memcpy(this->ptr_, safeArray.ptr_, this->length_ * sizeof(T));
	}

	template <typename T> SafeArray<T>& SafeArray<T>::operator= (const SafeArray<T>& safeArray)
	{
		if (this != &safeArray)
		{

			this->dealloc_ = false;
			this->length_ = safeArray.length_;
			this->ptr_ = new T[this->length_];
			std::memcpy(this->ptr_, safeArray.ptr_, this->length_ * sizeof(T));

		}

		return *this;
	}

	template <typename T> T& SafeArray<T>::operator[] (std::int32_t index)
	{
		if (index >= this->length_ || index < 0) throw; // out of range
		return this->ptr_[index];
	}

	template <typename T> SafeArray<T>::~SafeArray()
	{
		if (!this->dealloc_)
		{

			delete[] this->ptr_;
			this->dealloc_ = true;

		}
	}

	template <typename T> void SafeArray<T>::Dispose()
	{
		if (!this->dealloc_)
		{

			delete[] this->ptr_;
			this->dealloc_ = true;

		}
	}

	template <typename T> std::int32_t SafeArray<T>::Length()
	{
		return this->length_;
	}
}
