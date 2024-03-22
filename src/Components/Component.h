// Component.h : Classe abstrata que representa um componente em um sistema.
#pragma once
#include <Arduino.h>

namespace XGB
{
	class Component
	{
	public:
		Component(uint8_t pin)
			: _pin(pin)
		{
		}

	public:
		inline void begin(uint8_t mode)
		{
			pinMode(_pin, mode);
		}

		inline uint8_t pin() const
		{
			return _pin;
		}

		virtual inline uint8_t read() const = 0;
		virtual inline void write(uint8_t value) = 0;

	private:
		uint8_t _pin;
	};
}