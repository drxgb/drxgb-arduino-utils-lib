// AnalogComponent.h : Classe Reponsável por representar um componente com pino analógico
#pragma once
#include "Component.h"
#include "../functions.h"

namespace XGB
{
	class AnalogComponent :
		public Component
	{
	public:
		using Component::Component;

	public:
		inline uint8_t read() const
		{
			return analogRead(pin());
		}

		inline void write(uint8_t value)
		{
			clamp<uint8_t>(value, 0, 255);
			analogWrite(pin(), value);
		}
	};
}