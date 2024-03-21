// Collection.h : Representa uma coleção de dados
#pragma once
#include "../functions.h"

using XGB::fill;

namespace XGB
{
	template <typename T>
	class Collection
	{
	public:
		Collection(size_t capacity = 0U) :
			_capacity(capacity)
		{
			_size = 0U;
			_container = new T[_capacity];
			fill<T>(_container, 0U, capacity);
		}
		virtual ~Collection()
		{
			delete _container;
			_container = nullptr;
		}

	public:
		inline T operator[](int index) const
		{
			if (index > _size)
				return 0;
			return _container[index];
		}

		inline void clear()
		{
			fill<T>(_container, _capacity);
		}

		inline size_t size() const
		{
			return _size;
		}

		inline size_t capacity() const
		{
			return _capacity;
		}

		virtual inline void add(const T item) = 0;
		virtual inline void remove(const size_t index) = 0;

	protected:
		inline void realloc()
		{
			T* newContainer;
			
			if (_container)
			{
				newContainer = new T[_capacity];
				fill<T>(newContainer, 0U, _capacity);
				copy<T>(_container, newContainer, 0, _capacity, 0);
				delete _container;
				_container = newContainer;
			}
		}

	protected:
		T* _container;
		size_t _size;
		size_t _capacity;
	};
}