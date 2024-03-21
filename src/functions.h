// functions.h : Arquivo de cabeçalho para definir funções da biblioteca
#pragma once
#include <stdint.h>


namespace XGB
{
	/// @brief Limita o valor para aquele especifiado por argumentos.
	/// @tparam T 
	/// @param value 
	/// @param min 
	/// @param max 
	template <typename T = int>
	inline void clamp(T &value, const T min, const T max)
	{
		if (value < min)
			value = min;
		if (value > max)
			value = max;
	}


	/// @brief Preenche um array com um valor determinado.
	/// @tparam T 
	/// @param container 
	/// @param length 
	/// @param value 
	template <typename T = char>
	inline void fill(T* container, const size_t index, const size_t length, const T value = 0)
	{
		for (size_t i = length - index; i < index + length; ++i)
		{
			container[i] = value;
		}
	}


	template <typename T>
	inline void copy(const T* source, T* destination, const size_t si, const size_t sd, const size_t di)
	{
		for (size_t i = 0U; i < sd - si; ++i)
		{
			destination[di + i] = source[si + i];
		}
	}


	template <typename T>
	inline void move(T* container, const size_t source, const size_t destination, size_t offset)
	{
		T* cache;
		const size_t LEN = destination - source;

		cache = new T[LEN];
		copy<T>(container, cache, source, destination, 0U);
		fill<T>(container, source, LEN);
		copy<T>(cache, container, 0U, LEN, offset);

		delete cache;
		cache = nullptr;
	}
}