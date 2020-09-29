#include "pch.h"
#include "Interface.h"



namespace NativeExtensions
{
	ICloneable::~ICloneable()
	{
	}

	IDisposable::~IDisposable()
	{
	}

	namespace Collections
	{
		IEnumerator::~IEnumerator()
		{
		}

		IEnumerable::~IEnumerable()
		{
		}

		IComparer::~IComparer()
		{
		}

		ICollection::~ICollection()
		{
		}

		IList::~IList()
		{
		}

		IEqualityComparer::~IEqualityComparer()
		{
		}

		IStructuralComparable::~IStructuralComparable()
		{
		}

		IStructuralEquatable::~IStructuralEquatable()
		{
		}

		namespace Generic
		{
			template <typename T> IComparer<T>::~IComparer()
			{
			}

			template <typename T> IEnumerator<T>::~IEnumerator()
			{
			}

			template <typename T> IEnumerable<T>::~IEnumerable()
			{
			}

			template <typename T> ICollection<T>::~ICollection()
			{
			}

			template <typename T> IList<T>::~IList()
			{
			}

			template <typename T> IEqualityComparer<T>::~IEqualityComparer()
			{
			}
		}
	}
}
