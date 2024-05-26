// Component.h : Classe abstrata que representa um componente em um sistema.
#pragma once
#include <Arduino.h>

namespace XGB
{
	class Component
	{
	public:
		Component() :
			_pin(0xFF)
		{}

		Component(uint8_t pin) :
			_pin(pin)
		{}

		Component(uint8_t pin, uint8_t mode) :
			Component(pin)
		{
			begin(mode);
		}

		virtual ~Component() {}

	public:
		virtual void begin(uint8_t mode)
		{
			pinMode(_pin, mode);
		}

		inline uint8_t pin() const
		{
			return _pin;
		}

		virtual uint8_t read() const = 0;
		virtual void write(uint8_t value) = 0;
		virtual bool isHigh() const = 0;

	private:
		uint8_t _pin;
	};
}