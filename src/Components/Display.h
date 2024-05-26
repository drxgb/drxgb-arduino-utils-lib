// Display.h : Representa um componente de visor
#pragma once
#include "DigitalComponent.h"
#include "../functions.h"


namespace XGB
{
    class Display :
        public DigitalComponent
    {
	public:
		Display(uint8_t pins[], Component* extra = nullptr) :
			_pins(pins),
			_extra(extra)
		{}

        explicit Display(uint8_t pins[], uint8_t mode, Component* extra = nullptr) :
			Display(pins, extra)
		{
			begin(mode);
		}

		virtual ~Display()
		{
			delete _extra;
			_extra = nullptr;
		}

    public:
        void begin(int mode)
        {
            for (size_t i = 0U; i < segments(); ++i)
            {
				pinMode(_pins[i], mode);
            }
        }

		inline Component* extra() const
		{
			return _extra;
		}

		virtual void clear(const bool active = false);
        virtual size_t segments() const
		{
			return 0U;
		}

		inline uint8_t pin(size_t index)
		{
			clamp<size_t>(index, 0U, segments());
			return _pins[index];
		}


		uint8_t pin() = delete;

    private:
        uint8_t* _pins;
		Component* _extra;
    };


	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	// 					IMPLEMENTAÇÃO
	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

	void Display::clear(const bool active)
	{
		for (size_t i = 0U; i < segments(); ++i)
		{
			digitalWrite(_pins[i], active ? HIGH : LOW);
		}
	}
}