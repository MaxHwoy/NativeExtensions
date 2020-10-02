#pragma once



namespace NativeExtensions
{
	/// <summary>Supports cloning, which creates a new instance of a class with the same value as an existing instance.</summary>
	class ICloneable
	{
	public:
		/// <summary>Copy data of the current instance into the object passed.</summary>
		virtual void Clone(void* obj) = 0;
		virtual ~ICloneable();
	};

	/// <summary>Provides a mechanism for releasing unmanaged resources.</summary>
	class IDisposable
	{
	public:
		/// <summary>Performs application-defined tasks associated with freeing, releasing, or resetting unmanaged resources.</summary>
		virtual void Dispose() = 0;
		virtual ~IDisposable();
	};

	namespace Collections
	{
		/// <summary>Supports a simple iteration over a non-templated collection.</summary>
		class IEnumerator
		{
		public:
			/// <summary>Gets the element in the collection at the current position of the enumerator.</summary>
			/// <returns>The element in the collection at the current position of the enumerator.</returns>
			virtual void* CurrentPtr() = 0;
			/// <summary>Advances the enumerator to the next element of the collection.</summary>
			/// <returns>
			///   <see langword="true" /> if the enumerator was successfully advanced to the next element; <see langword="false" /> if the enumerator has passed the end of the collection.</returns>
			/// <exception cref="T:NativeExtensions::InvalidOperationException">The collection was modified after the enumerator was created.</exception>
			virtual bool MoveNext() = 0;
			/// <summary>Sets the enumerator to its initial position, which is before the first element in the collection.</summary>
			/// <exception cref="T:NativeExtensions::InvalidOperationException">The collection was modified after the enumerator was created.</exception>
			virtual void Reset() = 0;
			virtual ~IEnumerator();
		};

		/// <summary>Exposes an enumerator, which supports a simple iteration over a non-generic collection.</summary>
		class IEnumerable
		{
		public:
			/// <summary>Returns an enumerator that iterates through a collection.</summary>
			/// <returns>An NativeExtensions::IEnumerator object that can be used to iterate through the collection.</returns>
			virtual IEnumerator GetEnumerator() = 0;
			virtual ~IEnumerable();
		};

		/// <summary>Exposes a method that compares two objects.</summary>
		class IComparer
		{
		public:
			/// <summary>Compares two objects and returns a value indicating whether one is less than, equal to, or greater than the other.</summary>
			/// <param name="x">The first object to compare.</param>
			/// <param name="y">The second object to compare.</param>
			/// <returns>A signed integer that indicates the relative values of <paramref name="x" /> and <paramref name="y" />:   - If less than 0, <paramref name="x" /> is less than <paramref name="y" />.   - If 0, <paramref name="x" /> equals <paramref name="y" />.   - If greater than 0, <paramref name="x" /> is greater than <paramref name="y" />.</returns>
			/// <exception cref="T:NativeExtensions::ArgumentException">Neither <paramref name="x" /> nor <paramref name="y" /> implements the <see cref="T:System.IComparable" /> interface.  
			///  -or-  
			///  <paramref name="x" /> and <paramref name="y" /> are of different types and neither one can handle comparisons with the other.</exception>
			virtual std::int32_t Compare(void* x, void* y) = 0;
			virtual ~IComparer();
		};

		/// <summary>Defines size, enumerators, and synchronization methods for all nongeneric collections.</summary>
		class ICollection : public IEnumerable
		{
		public:
			/// <summary>Gets the number of elements contained in the NativeExtensions::ICollection.</summary>
			/// <returns>The number of elements contained in the NativeExtensions::ICollection.</returns>
			virtual std::int32_t Count() = 0;
			/// <summary>Gets a value indicating whether access to the NativeExtensions::ICollection is synchronized (thread safe).</summary>
			/// <returns>
			///   <see langword="true" /> if access to the NativeExtensions::ICollection is synchronized (thread safe); otherwise, <see langword="false" />.</returns>
			virtual bool IsSynchronized() = 0;
			/// <summary>Gets an object that can be used to synchronize access to the NativeExtensions::ICollection.</summary>
			/// <returns>An object that can be used to synchronize access to the NativeExtensions::ICollection.</returns>
			virtual void* SyncRoot() = 0;
			virtual ~ICollection();
		};

		/// <summary>Represents a non-generic collection of objects that can be individually accessed by index.</summary>
		class IList : public ICollection, IEnumerable
		{
		public:
			/// <summary>Gets a value indicating whether the NativeExtensions::Collections::IList is read-only.</summary>
			/// <returns>
			///   <see langword="true" /> if the NativeExtensions::Collections::IList is read-only; otherwise, <see langword="false" />.</returns>
			virtual bool IsReadOnly() = 0;
			/// <summary>Gets a value indicating whether the NativeExtensions::Collections::IList has a fixed size.</summary>
			/// <returns>
			///   <see langword="true" /> if the NativeExtensions::Collections::IList has a fixed size; otherwise, <see langword="false" />.</returns>
			virtual bool IsFixedSize() = 0;
			/// <summary>Adds an item to the NativeExtensions::Collections::IList.</summary>
			/// <param name="value">The object to add to the NativeExtensions::Collections::IList.</param>
			/// <returns>The position into which the new element was inserted, or -1 to indicate that the item was not inserted into the collection.</returns>
			/// <exception cref="T:NativeExtensions::NotSupportedException">The NativeExtensions::Collections::IList is read-only.  
			///  -or-  
			///  The NativeExtensions::Collections::IList has a fixed size.</exception>
			virtual std::int32_t Add(void* value) = 0;
			/// <summary>Determines whether the NativeExtensions::Collections::IList contains a specific value.</summary>
			/// <param name="value">The object to locate in the NativeExtensions::Collections::IList.</param>
			/// <returns>
			///   <see langword="true" /> if the object is found in the NativeExtensions::Collections::IList; otherwise, <see langword="false" />.</returns>
			virtual bool Contains(void* value) = 0;
			/// <summary>Removes all items from the NativeExtensions::Collections::IList.</summary>
			/// <exception cref="T:NativeExtensions::NotSupportedException">The NativeExtensions::Collections::IList is read-only.</exception>
			virtual void Clear() = 0;
			/// <summary>Gets the element at the specified index.</summary>
			/// <param name="index">The zero-based index of the element to get.</param>
			/// <returns>Pointer to the element at the specified index.</returns>
			/// <exception cref="T:NativeExtensions::ArgumentOutOfRangeException">
			///   <paramref name="index" /> is not a valid index in the NativeExtensions::Collections::IList.</exception>
			virtual void* GetObj(std::int32_t index) = 0;
			/// <summary>Determines the index of a specific item in the NativeExtensions::Collections::IList.</summary>
			/// <param name="value">The object to locate in the NativeExtensions::Collections::IList.</param>
			/// <returns>The index of <paramref name="value" /> if found in the list; otherwise, -1.</returns>
			virtual std::int32_t IndexOf(void* value) = 0;
			/// <summary>Inserts an item to the NativeExtensions::Collections::IList at the specified index.</summary>
			/// <param name="index">The zero-based index at which <paramref name="value" /> should be inserted.</param>
			/// <param name="value">The object to insert into the NativeExtensions::Collections::IList.</param>
			/// <exception cref="T:NativeExtensions::ArgumentOutOfRangeException">
			///   <paramref name="index" /> is not a valid index in the NativeExtensions::Collections::IList.</exception>
			/// <exception cref="T:NativeExtensions::NotSupportedException">The NativeExtensions::Collections::IList is read-only.  
			///  -or-  
			///  The NativeExtensions::Collections::IList has a fixed size.</exception>
			/// <exception cref="T:NativeExtensions::NullReferenceException">
			///   <paramref name="value" /> is null reference in the NativeExtensions::Collections::IList.</exception>
			virtual void Insert(std::int32_t index, void* value) = 0;
			/// <summary>Removes the first occurrence of a specific object from the NativeExtensions::Collections::IList.</summary>
			/// <param name="value">The object to remove from the NativeExtensions::Collections::IList.</param>
			/// <exception cref="T:NativeExtensions::NotSupportedException">The NativeExtensions::Collections::IList is read-only.  
			///  -or-  
			///  The NativeExtensions::Collections::IList has a fixed size.</exception>
			virtual void Remove(void* value) = 0;
			/// <summary>Removes the NativeExtensions::Collections::IList item at the specified index.</summary>
			/// <param name="index">The zero-based index of the item to remove.</param>
			/// <exception cref="T:NativeExtensions::ArgumentOutOfRangeException">
			///   <paramref name="index" /> is not a valid index in the NativeExtensions::Collections::IList.</exception>
			/// <exception cref="T:NativeExtensions::NotSupportedException">The NativeExtensions::Collections::IList is read-only.  
			///  -or-  
			///  The NativeExtensions::Collections::IList has a fixed size.</exception>
			virtual void RemoveAt(std::int32_t index) = 0;
			/// <summary>Sets the element at the specified index.</summary>
			/// <param name="index">The zero-based index of the element to set.</param>
			/// <returns>The element at the specified index.</returns>
			/// <exception cref="T:NativeExtensions::ArgumentOutOfRangeException">
			///   <paramref name="index" /> is not a valid index in the NativeExtensions::Collections::IList.</exception>
			/// <exception cref="T:NativeExtensions::NotSupportedException">The property is set and the NativeExtensions::Collections::IList is read-only.</exception>
			virtual void SetObj(void* value, std::int32_t index) = 0;
			virtual ~IList();
		};

		/// <summary>Defines methods to support the comparison of objects for equality.</summary>
		class IEqualityComparer
		{
		public:
			/// <summary>Determines whether the specified objects are equal.</summary>
			/// <param name="x">The first object to compare.</param>
			/// <param name="y">The second object to compare.</param>
			/// <returns>
			///   <see langword="true" /> if the specified objects are equal; otherwise, <see langword="false" />.</returns>
			/// <exception cref="T:NativeExtensions::ArgumentException">
			///   <paramref name="x" /> and <paramref name="y" /> are of different types and neither one can handle comparisons with the other.</exception>
			virtual bool Equals(void* x, void* y) = 0;
			/// <summary>Returns a hash code for the specified object.</summary>
			/// <param name="obj">The object for which a hash code is to be returned.</param>
			/// <returns>A hash code for the specified object.</returns>
			/// <exception cref="T:NativeExtensions::ArgumentNullException">The type of <paramref name="obj" /> is a pointer type and <paramref name="obj" /> is nullptr.</exception>
			virtual std::int32_t GetHashCode(void* obj) = 0;
			virtual ~IEqualityComparer();
		};

		/// <summary>Supports the structural comparison of collection objects.</summary>
		class IStructuralComparable
		{
		public:
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
			/// <exception cref="T:NativeExtensions::ArgumentException">This instance and <paramref name="other" /> are not the same type.</exception>
			virtual std::int32_t CompareTo(void* other, IComparer* comparer) = 0;
			virtual ~IStructuralComparable();
		};

		/// <summary>Defines methods to support the comparison of objects for structural equality.</summary>
		class IStructuralEquatable
		{
		public:
			/// <summary>Determines whether an object is structurally equal to the current instance.</summary>
			/// <param name="other">The object to compare with the current instance.</param>
			/// <param name="comparer">An object that determines whether the current instance and <paramref name="other" /> are equal.</param>
			/// <returns>
			///   <see langword="true" /> if the two objects are equal; otherwise, <see langword="false" />.</returns>
			virtual bool Equals(void* other, IEqualityComparer* comparer) = 0;
			/// <summary>Returns a hash code for the current instance.</summary>
			/// <param name="comparer">An object that computes the hash code of the current object.</param>
			/// <returns>The hash code for the current instance.</returns>
			virtual std::int32_t GetHashCode(IEqualityComparer* comparer) = 0;
			virtual ~IStructuralEquatable();
		};

		namespace Generic
		{
			/// <summary>Defines a method that a type implements to compare two objects, where T is the type of objects to compare.</summary>
			template <typename T> class IComparer
			{
			public:
				/// <summary>Compares two objects and returns a value indicating whether one is less than, equal to, or greater than the other.</summary>
				/// <param name="x">The first object to compare.</param>
				/// <param name="y">The second object to compare.</param>
				/// <returns>A signed integer that indicates the relative values of <paramref name="x" /> and <paramref name="y" />, as shown in the following table.  
				///   Value  
				///
				///   Meaning  
				///
				///   Less than zero  
				///
				///  <paramref name="x" /> is less than <paramref name="y" />.  
				///
				///   Zero  
				///
				///  <paramref name="x" /> equals <paramref name="y" />.  
				///
				///   Greater than zero  
				///
				///  <paramref name="x" /> is greater than <paramref name="y" />.</returns>
				virtual std::int32_t Compare(T* x, T* y) = 0;
				virtual ~IComparer();
			};

			/// <summary>Supports a simple iteration over a generic collection.</summary>
			template <typename T> class IEnumerator : Collections::IEnumerator, IDisposable
			{
			public:
				/// <summary>Gets the element in the collection at the current position of the enumerator.</summary>
				/// <returns>The element in the collection at the current position of the enumerator.</returns>
				virtual T* Current() = 0;
				virtual ~IEnumerator();
			};

			/// <summary>Exposes the enumerator, which supports a simple iteration over a collection of a specified type.</summary>
			template <typename T> class IEnumerable : Collections::IEnumerable
			{
			public:
				/// <summary>Returns an enumerator that iterates through the collection.</summary>
				/// <returns>An enumerator that can be used to iterate through the collection.</returns>
				virtual IEnumerator<T> GetEnumerator() = 0;
				virtual ~IEnumerable();
			};

			/// <summary>Defines methods to manipulate generic collections.</summary>
			template <typename T> class ICollection : IEnumerable<T>, Collections::IEnumerable
			{
			public:
				/// <summary>Gets the number of elements contained in the NativeExtensions::Collections::Generic::ICollection'T'.</summary>
				/// <returns>The number of elements contained in the NativeExtensions::Collections::Generic::ICollection'T'.</returns>
				virtual std::int32_t Count() = 0;
				/// <summary>Gets a value indicating whether the NativeExtensions::Collections::Generic::ICollection'T' is read-only.</summary>
				/// <returns>
				///   <see langword="true" /> if the NativeExtensions::Collections::Generic::ICollection'T' is read-only; otherwise, <see langword="false" />.</returns>
				virtual bool IsReadOnly() = 0;
				/// <summary>Adds an item to the NativeExtensions::Collections::Generic::ICollection'T'.</summary>
				/// <param name="item">The object to add to the NativeExtensions::Collections::Generic::ICollection'T'.</param>
				/// <exception cref="T:NativeExtensions::NotSupportedException">The NativeExtensions::Collections::Generic::ICollection'T' is read-only.</exception>
				virtual void Add(T* item) = 0;
				/// <summary>Removes all items from the NativeExtensions::Collections::Generic::ICollection'T'.</summary>
				/// <exception cref="T:NativeExtensions::NotSupportedException">The NativeExtensions::Collections::Generic::ICollection'T' is read-only.</exception>
				virtual void Clear() = 0;
				/// <summary>Determines whether the NativeExtensions::Collections::Generic::ICollection'T' contains a specific value.</summary>
				/// <param name="item">The object to locate in the NativeExtensions::Collections::Generic::ICollection'T'.</param>
				/// <returns>
				///   <see langword="true" /> if <paramref name="item" /> is found in the NativeExtensions::Collections::Generic::ICollection'T'; otherwise, <see langword="false" />.</returns>
				virtual bool Contains(T* item) = 0;
				/// <summary>Removes the first occurrence of a specific object from the NativeExtensions::Collections::Generic::ICollection'T'.</summary>
				/// <param name="item">The object to remove from the NativeExtensions::Collections::Generic::ICollection'T'.</param>
				/// <returns>
				///   <see langword="true" /> if <paramref name="item" /> was successfully removed from the NativeExtensions::Collections::Generic::ICollection'T'; otherwise, <see langword="false" />. This method also returns <see langword="false" /> if <paramref name="item" /> is not found in the original NativeExtensions::Collections::Generic::ICollection'T'.</returns>
				/// <exception cref="T:NativeExtensions::NotSupportedException">The NativeExtensions::Collections::Generic::ICollection'T' is read-only.</exception>
				virtual bool Remove(T* item) = 0;
				virtual ~ICollection();
			};

			/// <summary>Represents a collection of objects that can be individually accessed by index.</summary>
			template <typename T> class IList : ICollection<T>
			{
			public:
				/// <summary>Gets the element at the specified index.</summary>
				/// <param name="index">The zero-based index of the element to get.</param>
				/// <returns>The element at the specified index.</returns>
				/// <exception cref="T:NativeExtensions::ArgumentOutOfRangeException">
				///   <paramref name="index" /> is not a valid index in the NativeExtensions::Collections::Generic::IList'T'.</exception>
				virtual T* GetValue(std::int32_t index) = 0;
				/// <summary>Determines the index of a specific item in the NativeExtensions::Collections::Generic::IList'T'.</summary>
				/// <param name="item">The object to locate in the NativeExtensions::Collections::Generic::IList'T'.</param>
				/// <returns>The index of <paramref name="item" /> if found in the list; otherwise, -1.</returns>
				virtual std::int32_t IndexOf(T* item) = 0;
				/// <summary>Inserts an item to the NativeExtensions::Collections::Generic::IList'T' at the specified index.</summary>
				/// <param name="index">The zero-based index at which <paramref name="item" /> should be inserted.</param>
				/// <param name="item">The object to insert into the NativeExtensions::Collections::Generic::IList'T'.</param>
				/// <exception cref="T:NativeExtensions::ArgumentOutOfRangeException">
				///   <paramref name="index" /> is not a valid index in the NativeExtensions::Collections::Generic::IList'T'.</exception>
				/// <exception cref="T:NativeExtensions::NotSupportedException">The NativeExtensions::Collections::Generic::IList'T' is read-only.</exception>
				virtual void Insert(std::int32_t index, T* item) = 0;
				/// <summary>Removes the NativeExtensions::Collections::Generic::IList'T' item at the specified index.</summary>
				/// <param name="index">The zero-based index of the item to remove.</param>
				/// <exception cref="T:NativeExtensions::ArgumentOutOfRangeException">
				///   <paramref name="index" /> is not a valid index in the NativeExtensions::Collections::Generic::IList'T'.</exception>
				/// <exception cref="T:NativeExtensions::NotSupportedException">The NativeExtensions::Collections::Generic::IList'T' is read-only.</exception>
				virtual void RemoveAt(std::int32_t index) = 0;
				/// <summary>Sets the element at the specified index.</summary>
				/// <param name="index">The zero-based index of the element to set.</param>
				/// <returns>The element at the specified index.</returns>
				/// <exception cref="T:NativeExtensions::ArgumentOutOfRangeException">
				///   <paramref name="index" /> is not a valid index in the NativeExtensions::Collections::Generic::IList'T'.</exception>
				/// <exception cref="T:NativeExtensions::NotSupportedException">The property is set and the NativeExtensions::Collections::Generic::IList'T' is read-only.</exception>
				virtual void SetValue(T* value, std::int32_t index) = 0;
				virtual ~IList();
			};

			/// <summary>Defines methods to support the comparison of objects for equality.</summary>
			template <typename T> class IEqualityComparer
			{
			public:
				/// <summary>Determines whether the specified objects are equal.</summary>
				/// <param name="x">The first object of type <paramref name="T" /> to compare.</param>
				/// <param name="y">The second object of type <paramref name="T" /> to compare.</param>
				/// <returns>
				///   <see langword="true" /> if the specified objects are equal; otherwise, <see langword="false" />.</returns>
				virtual bool Equals(T* x, T* y) = 0;
				/// <summary>Returns a hash code for the specified object.</summary>
				/// <param name="obj">Pointer to the object for which a hash code is to be returned.</param>
				/// <returns>A hash code for the specified object.</returns>
				/// <exception cref="T:NativeExtensions::ArgumentNullException">The type of <paramref name="obj" /> is a reference type and <paramref name="obj" /> is nullptr.</exception>
				std::int32_t GetHashCode(T* obj) = 0;
				virtual ~IEqualityComparer();
			};
		}
	}
}
