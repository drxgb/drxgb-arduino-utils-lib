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
	inline void fill(const T* container, const size_t length, const T value = 0)
	{
		for (size_t i = 0U; i < length; ++i)
		{
			container[i] = value;
		}
	}
}