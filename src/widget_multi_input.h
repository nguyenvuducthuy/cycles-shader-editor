#pragma once

#include "float_pos.h"

namespace CyclesShaderEditor {
	// Widget that can accept input for multiple socket values
	class MultiInputWidget {
	public:
		MultiInputWidget(float width);

	private:
		FloatPos position;

		const float width;
	};
}
