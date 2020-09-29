#include "pch.h"
#include "Array.h"



namespace NativeExtensions
{
	template <typename T> Array<T>::Array(std::int32_t count)
	{
		if (count <= 0) throw; // argument out of range;
		this->ptr_ = new T[count];
		this->length_ = count;
		this->dealloc_ = false;
	}

	template <typename T> Array<T>::Array(const Array<T>& safeArray)
	{
		this->dealloc_ = false;
		this->length_ = safeArray.length_;
		this->ptr_ = new T[this->length_];
		std::memcpy(this->ptr_, safeArray.ptr_, this->length_ * sizeof(T));
	}

	template <typename T> Array<T>& Array<T>::operator= (const Array<T>& safeArray)
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

	template <typename T> T& Array<T>::operator[] (std::int32_t index)
	{
		if (index >= this->length_ || index < 0) throw; // out of range
		return this->ptr_[index];
	}

	template <typename T> Array<T>::~Array()
	{
		if (!this->dealloc_)
		{

			delete[] this->ptr_;
			this->dealloc_ = true;

		}
	}

	template <typename T> std::int32_t Array<T>::Add(void* value)
	{
		throw; // not supported exception
	}

	template <typename T> void Array<T>::Clear()
	{
		delete[] this->ptr_;
		this->ptr_ = new T[this->length_];
	}

	template <typename T> void Array<T>::Clone(void* obj)
	{
		auto arr = reinterpret_cast<Array<T>*>(obj);
		Array<T>::Copy(this, arr, this->length_);
	}

	template <typename T> std::int32_t Array<T>::CompareTo(void* other, Collections::IComparer* comparer)
	{
		if (comparer == nullptr) throw ArgumentNullPtrException("IComparer pointer passed is a null pointer");
		return comparer->Compare(this, other);
	}

	template <typename T> bool Array<T>::Contains(void* value)
	{
		return this->IndexOf(value) != -1;
	}

	template <typename T> void Array<T>::Copy(Array* src, Array* dest, std::int32_t count)
	{
		Array<T>::Copy(src, 0, dest, 0, count);
	}

	template <typename T> void Array<T>::Copy(Array* src, std::int32_t srcStart, Array* dest, std::int32_t destStart, std::int32_t count)
	{
		if (src == nullptr) throw ArgumentNullPtrException("Source array pointer passed is a null pointer");
		if (dest == nullptr) throw ArgumentNullPtrException("Destination array pointer passed is a null pointer");
		
		if (srcStart < 0) throw ArgumentOutOfRangeException("Source array index is less than 0");
		else if (srcStart >= src->length_) throw ArgumentOutOfRangeException("Source array index is greater or equals source array length");

		if (destStart < 0) throw ArgumentOutOfRangeException("Destination array index is less than 0");
		else if (destStart >= dest->length_) throw ArgumentOutOfRangeException("Destination array index is greater or equals source array length");
		
		if (srcStart + count >= src->length_) throw ArgumentException("Number of elements to copy in source array from starting index to the end overflows");
		if (destStart + count >= dest->length_) throw ArgumentException("Number of elements available in destination array from starting index to the end underflows");

		std::memcpy(dest->ptr_ + destStart, src->ptr_ + srcStart, count * sizeof(T));
	}

	template <typename T> std::int32_t Array<T>::Count()
	{
		return this->length_;
	}

	template <typename T> bool Array<T>::Equals(void* other, Collections::IEqualityComparer* comparer)
	{
		if (comparer == nullptr) throw ArgumentNullPtrException("IEqualityComparer pointer passed is a null pointer");
		return comparer->Equals(this, other);
	}

	template <typename T> bool Array<T>::Exists(Method<bool __cdecl(T)> method)
	{
		return this->FindIndex(method) != -1;
	}

	template <typename T> T* Array<T>::Find(Method<bool __cdecl(T)> method)
	{
		if (method == nullptr) throw ArgumentNullPtrException("Predicate method passed is a null pointer");

		for (std::int32_t i = 0; i < this->length_; ++i)
		{

			if (method(this->ptr_[i])) return this->ptr_ + i;

		}

		return nullptr;
	}

	template <typename T> T* Array<T>::Find(Method<bool __cdecl(T)> method, std::int32_t startIndex)
	{
		if (method == nullptr) throw ArgumentNullPtrException("Predicate method passed is a null pointer");
		if (startIndex < 0) throw ArgumentOutOfRangeException("Starting index passed is less than 0");
		if (startIndex >= this->length_) throw ArgumentOutOfRangeException("Starting index passed overflows length of the array");

		for (std::int32_t i = startIndex; i < this->length_; ++i)
		{

			if (method(this->ptr_[i])) return this->ptr_ + i;

		}

		return nullptr;
	}

	template <typename T> T* Array<T>::Find(Method<bool __cdecl(T)> method, std::int32_t startIndex, std::int32_t count)
	{
		if (method == nullptr) throw ArgumentNullPtrException("Predicate method passed is a null pointer");
		if (startIndex < 0) throw ArgumentOutOfRangeException("Starting index passed is less than 0");
		if (startIndex >= this->length_) throw ArgumentOutOfRangeException("Starting index passed overflows length of the array");
		if (startIndex + count >= this->length_) throw ArgumentException("Number of elements to search in overflows the array");

		for (std::int32_t i = startIndex; i < startIndex + count; ++i)
		{

			if (method(this->ptr_[i])) return this->ptr_ + i;

		}

		return nullptr;
	}

	template <typename T> T* Array<T>::FindLast(Method<bool __cdecl(T)> method)
	{
		if (method == nullptr) throw ArgumentNullPtrException("Predicate method passed is a null pointer");

		for (std::int32_t i = this->length_ - 1; i >= 0; --i)
		{

			if (method(this->ptr_[i])) return this->ptr_ + i;

		}

		return nullptr;
	}

	template <typename T> std::int32_t Array<T>::FindIndex(Method<bool __cdecl(T)> method)
	{
		if (method == nullptr) throw ArgumentNullPtrException("Predicate method passed is a null pointer");

		for (std::int32_t i = 0; i < this->length_; ++i)
		{

			if (method(this->ptr_[i])) return i;

		}

		return -1;
	}

	template <typename T> void Array<T>::ForEach(Method<void __cdecl(T)> method)
	{
		if (method == nullptr) throw ArgumentNullPtrException("Method passed is a null pointer");
		for (std::int32_t i = 0; i < this->length_; ++i) method(this->ptr_[i]);
	}

	template <typename T> std::int32_t Array<T>::GetHashCode(Collections::IEqualityComparer* comparer)
	{
		if (comparer == nullptr) throw ArgumentNullPtrException("IEqualityComparer pointer passed is a null pointer");
		return comparer->GetHashCode(this);
	}

	template <typename T> Collections::IEnumerator Array<T>::GetEnumerator()
	{
		auto result = Array<T>::Enumerator(this);
		return result;
	}

	template <typename T> T* Array<T>::GetPointer()
	{
		return this->ptr_;
	}




	template <typename T> std::int32_t Array<T>::Length()
	{
		return this->length_;
	}


	

	
	
	template <typename T> void Array<T>::Resize(std::int32_t size)
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






	template <typename T> Array<T>::Enumerator::Enumerator(Array<T>* arr)
	{
		this->array_ = arr;
		this->index_ = index;
		this->current_ = nullptr;
	}

	template <typename T> void Array<T>::Enumerator::Dispose()
	{
	}

	template <typename T> T* Array<T>::Enumerator::Current()
	{
		return this->current_;
	}

	template <typename T> void* Array<T>::Enumerator::CurrentPtr()
	{
		if (this->index == 0 || this->index_ = this->array_->length_ + 1) throw; // invalid operation
		return this->current_;
	}

	template <typename T> bool Array<T>::Enumerator::MoveNext()
	{
		if (this->index_ < this->array_->length_)
		{
			
			this->current_ = this->array_->ptr_[this->index_++];
			return true;

		}
		else
		{

			this->index_ = this->array_->length_ + 1;
			this->current_ = nullptr;
			return false;

		}
	}

	template <typename T> void Array<T>::Enumerator::Reset()
	{
		this->index_ = 0;
		this->current_ = nullptr;
	}
}
