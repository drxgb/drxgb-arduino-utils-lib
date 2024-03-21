// List.h : Representa um lista linear de elementos.
#pragma once
#include "Collection.h"


namespace XGB
{
    template <typename T>
    class List<T> :
        public Collection<T>
    {
    public:
		using Collection::Collection;

	public:
		inline void add(const T item)
		{
			++_size;
			if (_size > _capacity)
			{
				_capacity = _size;
				realloc();
			}
			_container[_size - 1] = item;
		}
		
		inline void remove(const size_t index)
		{
			_container[index] = 0;
			move(_container, index + 1, _size, index);
			--_size;
		}
    };
}