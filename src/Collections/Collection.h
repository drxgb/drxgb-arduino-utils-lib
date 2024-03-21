// Collection.h : Representa uma coleção de dados
#pragma once
#include "../functions.h"

using XGB::fill;

namespace XGB
{
	template <typename T>
	class Collection<T>
	{
	public:
		Collection(size_t capacity = 0) :
			_capacity(capacity),
			_size(0)
		{
			realloc();
		}

	public:
		virtual inline void add(const T item) = 0;
		virtual inline void remove() = 0;

	protected:
		inline void realloc()
		{
			if (_container)
			{
				delete _container;
			}

			_container = new T[capacity];
			fill(_container, capacity);
		}

	private:
		T* _container;
		size_t _size;
		size_t _capacity;
	};
}