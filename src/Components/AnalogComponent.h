// AnalogComponent.h : Classe Reponsável por representar um componente com pino analógico
#pragma once

#include "Component.h"

namespace XGB
{
	class AnalogComponent
		: public Component
	{
	public:
		using Component::Component;

	public:
		inline const uint8_t read() const
		{
			return analogRead(pin());
		}

		inline void write(uint8_t value)
		{
			// TODO: clamp value
			analogWrite(pin(), value);
		}
	};
}