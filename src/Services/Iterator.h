// Iterator.h : Responsável por iterar por uma coleção.
#pragma once
#include "../Collections/Collection.h"


namespace XGB
{
	template <typename T>
    class Iterator
	{
	public:
		Iterator(Collection<T>& collection, size_t pos = 0U) :
			_collection(collection)
			_pos(pos)
		{}

	public:
		inline T operator*() const
		{
			return _collection.get(_pos);
		}

		inline T operator++()
		{
			++pos;
			return **this;
		}

		inline T operator++(int)
		{
			T item;

			item = **this;
			++pos;
			return item;
		}

		inline T operator--()
		{
			--pos;
			return **this;
		}

		inline T operator--(int)
		{
			T item;

			item = **this;
			--pos;
			return item;
		}

		inline void reset()
		{
			_pos = 0U;
		}

	private:
		Collection<T>& _collection;
		size_t _pos;
	};
}