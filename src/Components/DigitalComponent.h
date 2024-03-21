// DigitalComponent.h : Classe responável por representar um componente com pino digital
#pragma once

#include "Component.h"

namespace XGB
{
	class DigitalComponent
		: public Component
	{
	public:
		using Component::Component;

	public:
		inline const uint8_t read() const
		{
			return digitalRead(pin());
		}

		inline void write(uint8_t value)
		{
			digitalWrite(pin(), value);
		}

		inline const bool isHigh() const
		{
			return read() == HIGH;
		}
	};
}