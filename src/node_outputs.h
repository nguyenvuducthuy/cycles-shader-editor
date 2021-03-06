#pragma once

#include "node_base.h"

namespace CyclesShaderEditor {

	class FloatPos;

	class MaterialOutputNode : public EditorNode {
	public:
		MaterialOutputNode(FloatPos position);

		virtual bool can_be_deleted() override;
	};

}
