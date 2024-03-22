// List.h : Representa um lista linear de elementos.
#pragma once
#include "Collection.h"


namespace XGB
{
    template <typename T>
    class List :
        public Collection<T>
    {
    public:
		using Collection<T>::Collection;

	public:
		inline void add(const T item)
		{
			++this->_size;
			if (this->_size > this->capacity())
			{
				this->_capacity = this->size();
				this->realloc();
			}
			this->_container[this->size() - 1] = item;
		}
		
		inline void remove(const size_t index)
		{
			this->_container[index] = 0;
			move<T>(this->_container, index + 1, this->size(), index);
			--this->_size;
		}
    };
}