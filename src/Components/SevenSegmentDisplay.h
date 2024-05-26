#pragma once
#include "SegmentDisplay.h"


namespace XGB
{
	class SevenSegmentDisplay :
		public SegmentDisplay
	{
	public:
		using SegmentDisplay::SegmentDisplay;

	public:
		virtual size_t segments() const
		{
			return 7U;
		}
	};
}