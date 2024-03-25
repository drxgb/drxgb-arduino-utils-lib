// Listenable.h : Contrato para classes que podem ouvir algum evento ou ação.
#pragma once


namespace XGB
{
	class Listenable
	{
	public:
		virtual void listen() = 0;
	};
}