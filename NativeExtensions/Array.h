#pragma once



namespace NativeExtensions
{
	template <typename T> class Array final :
		public ICloneable,
		public Collections::IList,
		public Collections::IStructuralEquatable,
		public Collections::IStructuralComparable
	{
	public:
		class Enumerator final : public Collections::Generic::IEnumerator<T>
		{
		private:
			Array<T>* array_;
			std::int32_t index_;
			T* current_;

		public:
			/// <summary>Initializes new instance of Enumerator for NativeExtensions::Array.</summary>
			Enumerator(Array<T>* arr);
			/// <summary>Performs application-defined tasks associated with freeing, releasing, or resetting unmanaged resources.</summary>
			void Dispose() override;
			/// <summary>Gets the element in the collection at the current position of the enumerator.</summary>
			/// <returns>The element in the collection at the current position of the enumerator.</returns>
			T* Current() override;
			/// <summary>Gets the element in the collection at the current position of the enumerator.</summary>
			/// <returns>The element in the collection at the current position of the enumerator.</returns>
			void* CurrentPtr() override;
			/// <summary>Advances the enumerator to the next element of the collection.</summary>
			/// <returns>
			///   <see langword="true" /> if the enumerator was successfully advanced to the next element; <see langword="false" /> if the enumerator has passed the end of the collection.</returns>
			/// <exception cref="T:System.InvalidOperationException">The collection was modified after the enumerator was created.</exception>
			bool MoveNext() override;
			/// <summary>Sets the enumerator to its initial position, which is before the first element in the collection.</summary>
			/// <exception cref="T:System.InvalidOperationException">The collection was modified after the enumerator was created.</exception>
			void Reset() override;
		};

	private:
		T* ptr_;
		std::int32_t length_;

	public:
		Array(std::int32_t length);
		Array(const Array& safeArray);
		Array& operator=(const Array& safeArray);
		T& operator[](std::int32_t index);
		~Array();

	public:
		/// <summary>Calling this method always throws a <see cref="T:System.NotSupportedException" /> exception.</summary>
		/// <param name="value">The object to be added to the NativeExtensions::Collections::IList.</param>
		/// <returns>Adding a value to an array is not supported. No value is returned.</returns>
		/// <exception cref="T:System.NotSupportedException">The NativeExtensions::Collections::IList has a fixed size.</exception>
		std::int32_t Add(void* value) override;
		/// <summary>Removes all items from the NativeExtensions::Collections::IList.</summary>
		/// <exception cref="T:System.NotSupportedException">The NativeExtensions::Collections::IList is read-only.</exception>
		void Clear() override;
		/// <summary>Creates a full copy of the Array and returns a void pointer to it.</summary>
		/// <returns>A full copy of this Array casted to a void pointer type.</returns>
		void Clone(void* obj) override;
		/// <summary>Determines whether the current collection object precedes, occurs in the same position as, or follows another object in the sort order.</summary>
		/// <param name="other">The object to compare with the current instance.</param>
		/// <param name="comparer">An object that compares members of the current collection object with the corresponding members of <paramref name="other" />.</param>
		/// <returns>A signed integer that indicates the relationship of the current collection object to <paramref name="other" /> in the sort order: - If less than 0, the current instance precedes <paramref name="other" />. - If 0, the current instance and <paramref name="other" /> are equal. - If greater than 0, the current instance follows <paramref name="other" />.  
		///   Return value  
		///
		///   Description  
		///
		///   -1  
		///
		///   The current instance precedes <paramref name="other" />.  
		///
		///   0  
		///
		///   The current instance and <paramref name="other" /> are equal.  
		///
		///   1  
		///
		///   The current instance follows <paramref name="other" />.</returns>
		/// <exception cref="NativeExtensions::ArgumentNullPtrException">Pointer of the IComparer passed is a null pointer.</exception>
		std::int32_t CompareTo(void* other, Collections::IComparer* comparer) override;
		/// <summary>Determines whether an element is in the NativeExtensions::Collections::IList.</summary>
		/// <param name="value">The object to locate in the current list. The element to locate can be nullptr for pointer types.</param>
		/// <returns>
		///   <see langword="true" /> if <paramref name="value" /> is found in the NativeExtensions::Collections::IList; otherwise, <see langword="false" />.</returns>
		bool Contains(void* value) override;
		/// <summary>Copies a range of elements from a NativeExtensions::Array starting at the first element and pastes them into another NativeExtensions::Array starting at the first element. The length is specified as a 32-bit integer.</summary>
		/// <param name="src">The NativeExtensions::Array that contains the data to copy.</param>
		/// <param name="dest">The NativeExtensions::Array that receives the data.</param>
		/// <param name="count">A 32-bit integer that represents the number of elements to copy.</param>
		/// <exception cref="T:NativeExtensions::ArgumentNullPtrException">
		///   <paramref name="src" /> is <see langword="nullptr" />.  
		/// -or-  
		/// <paramref name="dest" /> is <see langword="nullptr" />.</exception>
		/// <exception cref="T:NativeExtensions::ArgumentOutOfRangeException">
		///   <paramref name="count" /> is less than zero.</exception>
		/// <exception cref="T:NativeExtensions::ArgumentException">
		///   <paramref name="count" /> is greater than the number of elements in <paramref name="src" />.  
		/// -or-  
		/// <paramref name="length" /> is greater than the number of elements in <paramref name="dest" />.</exception>
		static void Copy(Array* src, Array* dest, std::int32_t count);
		/// <summary>Copies a range of elements from an NativeExtensions::Array starting at the specified source index and pastes them to another NativeExtensions::Array starting at the specified destination index. The length and the indexes are specified as 32-bit integers.</summary>
		/// <param name="src">The NativeExtensions::Array that contains the data to copy.</param>
		/// <param name="srcStart">A 32-bit integer that represents the index in the <paramref name="src" /> at which copying begins.</param>
		/// <param name="dest">The NativeExtensions::Array that receives the data.</param>
		/// <param name="destStart">A 32-bit integer that represents the index in the <paramref name="dest" /> at which storing begins.</param>
		/// <param name="count">A 32-bit integer that represents the number of elements to copy.</param>
		/// <exception cref="T:System.ArgumentNullException">
		///   <paramref name="src" /> is <see langword="null" />.  
		/// -or-  
		/// <paramref name="dest" /> is <see langword="null" />.</exception>
		/// <exception cref="T:System.ArgumentOutOfRangeException">
		///   <paramref name="srcStart" /> is less than the 0 or is greater than number of elements in <paramref name="src" />.  
		/// -or-  
		/// <paramref name="destStart" /> is less than the 0 or is greater than number of elements in <paramref name="dest" />.  
		/// -or-  
		/// <paramref name="count" /> is less than zero.</exception>
		/// <exception cref="T:System.ArgumentException">
		///   <paramref name="count" /> is greater than the number of elements from <paramref name="srcStart" /> to the end of <paramref name="src" />.  
		/// -or-  
		/// <paramref name="count" /> is greater than the number of elements from <paramref name="destStart" /> to the end of <paramref name="dest" />.</exception>
		static void Copy(Array* src, std::int32_t srcStart, Array* dest, std::int32_t destStart, std::int32_t count);
		/// <summary>Gets the total number of elements in the NativeExtensions::Array.</summary>
		/// <returns>The total number of elements in all the NativeExtensions::Array; zero if there are no elements in the array.</returns>
		std::int32_t Count() override;
		/// <summary>Determines whether an object is structurally equal to the current instance.</summary>
		/// <param name="other">The object to compare with the current instance.</param>
		/// <param name="comparer">An object that determines whether the current instance and <paramref name="other" /> are equal.</param>
		/// <returns>
		///   <see langword="true" /> if the two objects are equal; otherwise, <see langword="false" />.</returns>
		/// <exception cref="NativeExtensions::ArgumentNullPtrException">Pointer of the IEqualityComparer passed is a null pointer.</exception>
		bool Equals(void* other, Collections::IEqualityComparer* comparer) override;
		/// <summary>Determines whether the specified array contains elements that match the conditions defined by the specified method.</summary>
		/// <param name="method">The NativeExtensions::Method that defines the conditions of the elements to search for.</param>
		/// <typeparam name="T">The type of the elements of the array.</typeparam>
		/// <returns>
		///   <see langword="true" /> if this array contains one or more elements that match the conditions defined by the specified method; otherwise, <see langword="false" />.</returns>
		/// <exception cref="T:System.ArgumentNullPtrException"><paramref name="method" /> is <see langword="nullptr" />.</exception>
		bool Exists(Method<bool __cdecl(T)> method);
		/// <summary>Searches for an element that matches the conditions defined by the specified method, and returns the first occurrence within the entire NativeExtensions::Array.</summary>
		/// <param name="match">The predicate that defines the conditions of the element to search for.</param>
		/// <typeparam name="T">The type of the elements of the array.</typeparam>
		/// <returns>The first element that matches the conditions defined by the specified method, if found; otherwise, the default value for type <paramref name="T" />.</returns>
		/// <exception cref="T:System.ArgumentNullPtrException"><paramref name="method" /> is <see langword="nullptr" />.</exception>
		T* Find(Method<bool __cdecl(T)> method);
		T* Find(Method<bool __cdecl(T)> method, std::int32_t startIndex);
		T* Find(Method<bool __cdecl(T)> method, std::int32_t startIndex, std::int32_t count);
		T* FindLast(Method<bool __cdecl(T)> method);
		std::int32_t FindIndex(Method<bool __cdecl(T)> method);
		void ForEach(Method<void __cdecl(T)> method);
		std::int32_t GetHashCode(Collections::IEqualityComparer* comparer) override;
		Collections::IEnumerator GetEnumerator() override;
		T* GetPointer();
		void* GetObj(std::int32_t index) override;
		T* GetValue(std::int32_t index);
		std::int32_t IndexOf(T* value);
		std::int32_t IndexOf(T* value, std::int32_t startIndex);
		std::int32_t IndexOf(T* value, std::int32_t startIndex, std::int32_t count);
		std::int32_t IndexOf(void* value) override;
		void Insert(std::int32_t index, void* value) override;
		/// <summary>Gets a value indicating whether the NativeExtensions::Array has a fixed size.</summary>
		/// <returns>This property is always <see langword="true" /> for all arrays.</returns>
		bool IsFixedSize() override;
		/// <summary>Gets a value indicating whether the NativeExtensions::Array is read-only.</summary>
		/// <returns>This property is always <see langword="false" /> for all arrays.</returns>
		bool IsReadOnly() override;
		/// <summary>Gets a value indicating whether access to the NativeExtensions::Array is synchronized (thread safe).</summary>
		/// <returns>This property is always <see langword="false" /> for all arrays.</returns>
		bool IsSynchronized() override;
		std::int32_t LastIndexOf(T* value);
		std::int32_t LastIndexOf(T* value, std::int32_t startIndex);
		std::int32_t LastIndexOf(T* value, std::int32_t startIndex, std::int32_t count);
		/// <summary>Gets the total number of elements in the NativeExtensions::Array.</summary>
		/// <returns>The total number of elements in all the NativeExtensions::Array; zero if there are no elements in the array.</returns>
		std::int32_t Length();
		void Remove(void* value) override;
		void RemoveAt(std::int32_t index) override;
		void Resize(std::int32_t size);
		void Reverse();
		void Reverse(std::int32_t startIndex, std::int32_t count);
		void SetObj(void* value, std::int32_t index) override;
		void SetValue(T* value, std::int32_t index);
		void Sort(Method<std::int32_t __cdecl(T, T)> comparisonMethod);
		void* SyncRoot() override;
		bool TrueForAll(Method<bool __cdecl(T)> method);
	};

	using bools = Array<bool>;
	using chars = Array<char>;
	using wchars = Array<wchar_t>;
	using int8s = Array<std::int8_t>;
	using uint8s = Array<std::uint8_t>;
	using int16s = Array<std::int16_t>;
	using uint16s = Array<std::uint16_t>;
	using int32s = Array<std::int32_t>;
	using uint32s = Array<std::uint32_t>;
	using int64s = Array<std::int64_t>;
	using uint64s = Array<std::uint64_t>;
}
