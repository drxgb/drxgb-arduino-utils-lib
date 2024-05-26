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
		virtual ~DigitalComponent() {}

	public:
		inline uint8_t read() const
		{
			return digitalRead(pin());
		}

		inline void write(uint8_t value)
		{
			digitalWrite(pin(), value ? HIGH : LOW);
		}

		inline bool isHigh() const
		{
			return read() == HIGH;
		}
	};
}