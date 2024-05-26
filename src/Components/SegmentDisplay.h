#pragma once
#include "Display.h"
#include "../IO/Decoders/DisplayDecoder.h"


namespace XGB
{
	class SegmentDisplay :
		public Display
	{
	public:
		SegmentDisplay(uint8_t pins[], DisplayDecoder* decoder, Component* extra = nullptr) :
			Display(pins, extra),
			_decoder(decoder)
		{}
		explicit SegmentDisplay(uint8_t pins[], DisplayDecoder* decoder, uint8_t mode, Component* extra = nullptr) :
			Display(pins, mode, extra),
			_decoder(decoder)
		{}
		~SegmentDisplay() {}

	public:
		inline uint8_t read() const
		{
			return _value;
		}

		inline bool decimalState() const
		{
			return extra() ? extra()->isHigh() : false;
		}

		inline void setDecimal(const bool state)
		{
			if (extra())
				extra()->write(state);
		}

		inline void clear(const bool active = false) override
		{
			Display::clear(active);
			_value = 0xFF;
		}

		void write(uint8_t value) override;

	private:
		DisplayDecoder* _decoder;
		uint8_t _value;
	};


	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	// 					IMPLEMENTAÇÃO
	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

	void SegmentDisplay::write(uint8_t value)
	{
		uint32_t result;		

		if (_decoder)
		{
			result = _decoder->decode(value);
			for (size_t i = 0U; i < segments(); ++i)
			{
				digitalWrite(pin(i), result & 1U ? HIGH : LOW);
				result >>= 1U;
			}
		}
		_value = value;
	}
}