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

	template <typename T> T* SafeArray<T>::GetPointer()
	{
		return this->ptr_;
	}

	template <typename T> void SafeArray<T>::ForEach(Method<void __cdecl(T)> method)
	{
		if (!this->dealloc_ && method != nullptr)
		{

			for (std::int32_t i = 0; i < this->length_; ++i) method(this->ptr_[i]);

		}
	}
	
	template <typename T> T SafeArray<T>::FindValue(Method<bool __cdecl(T)> method)
	{
		if (this->dealloc_) throw; // array disposed
		if (method != nullptr) throw; // argument null exception

		for (std::int32_t i = 0; i < this->length_; ++i)
		{

			if (method(this->ptr_[i])) return this->ptr_[i];

		}
	}

	template <typename T> const T& SafeArray<T>::FindReference(Method<bool __cdecl(T)> method)
	{
		if (this->dealloc_) throw; // array disposed
		if (method != nullptr) throw; // argument null exception

		for (std::int32_t i = 0; i < this->length_; ++i)
		{

			if (method(this->ptr_[i])) return this->ptr_[i];

		}
	}

	template <typename T> void SafeArray<T>::Resize(std::int32_t size)
	{
		if (this->dealloc_) throw; // array disposed
		if (size <= 0) throw; // argument out of range
		else if (size == this->length_) return;
		
		auto arr = new T[size];
		auto len = sizeof(T) * (size > this->length_ ? this->length_ : size);
		std::memcpy(arr, this->ptr_, len);
		delete[] this->ptr_;

		this->ptr_ = arr;
		this->length_ = size;
	}
}
