#pragma once
#include "DisplayDecoder.h"
#include "../../functions.h"


namespace XGB
{
	class DecimalDisplayDecoder :
		public DisplayDecoder
	{
	public:
		inline uint32_t decode(uint8_t& value);
	};


	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	// 					IMPLEMENTAÇÃO
	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

	uint32_t DecimalDisplayDecoder::decode(uint8_t& value)
	{
		bool a, b, c, d;
		uint32_t result;

		clamp<uint8_t>(value, 0, 9);
		a = (value >> 3) & 1;
		b = (value >> 2) & 1;
		c = (value >> 1) & 1;
		d = value & 1;

		result  = (!b & !d) | c | (b & d) | a;										// A
		result += ((!b) | (!c & !d) | (c & d)) << 1;								// B
		result += ((!c) | d | b) << 2;												// C
		result += ((!b & !d) | (!b & c) | (b & !c & d) | (c & !d) | a) << 3;		// D
		result += ((!b & !d) | (c & !d)) << 4;										// E
		result += ((!c & !d) | (b & !c) | (b & !d) | a) << 5;						// F
		result += ((!b & c) | (b & !c) | a | (b & !d)) << 6;						// G

		return result;
	}
}