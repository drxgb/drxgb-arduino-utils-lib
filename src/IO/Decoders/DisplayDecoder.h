#pragma once
#include <stdint.h>


namespace XGB
{
	class DisplayDecoder
	{
	public:
		virtual ~DisplayDecoder() {}

	public:
		virtual uint32_t decode(uint8_t& value) = 0;
	};
}