// Button.h : Representa um botão táctil
#pragma once
#include "DigitalComponent.h"
#include "../Contracts/Listenable.h"


namespace XGB
{
	enum ButtonState
	{
		IDLE,
		PRESS,
		HOLD,
		RELEASE,
	};


	class Button :
		public DigitalComponent,
		public Listenable
	{
	public:
		using DigitalComponent::DigitalComponent;

	public:
		void listen();

		inline bool isIdle() const
		{
			return _state == IDLE;
		}

		inline bool isPressed() const
		{
			return _state == PRESS;
		}

		inline bool isHeld() const
		{
			return _state == HOLD;
		}

		inline bool isReleased() const
		{
			return _state == RELEASE;
		}
		inline ButtonState state() const
		{
			return _state;
		}

	private:
		ButtonState _state = IDLE;
	};


	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	// 					IMPLEMENTAÇÃO
	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

	void Button::listen()
	{
		if (isHigh())
		{
			switch (_state)
			{
				case IDLE:
				case RELEASE:
					_state = PRESS;
					break;
				case PRESS:
					_state = HOLD;
					break;
				default:
					break;
			}
		}
		else
		{
			switch (_state)
			{
				case PRESS:
				case HOLD:
					_state = RELEASE;
					break;
				case RELEASE:
					_state = IDLE;
					break;
				default:
					break;
			}
		}
	}
}