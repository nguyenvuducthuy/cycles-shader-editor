#pragma once

#include <list>

#include "subwindow.h"

namespace CyclesShaderEditor {

	class NodeCategoryButton;
	class NodeCreationButton;

	class NodeListSubwindow : public NodeEditorSubwindow {
	public:
		NodeListSubwindow(FloatPos screen_position);
		virtual ~NodeListSubwindow();

		virtual void pre_draw() override;

		virtual void handle_mouse_button(int button, int action, int mods) override;
		virtual void mouse_left_release() override;

		NodeCategoryButton* get_category_button_under_mouse();
		NodeCreationButton* get_button_under_mouse();

		NodeCreationButton* active_button;

	protected:
		virtual void draw_content(NVGcontext* draw_context) override;

		std::list<NodeCategoryButton*> category_buttons;

		NodeCategoryButton* active_category = nullptr;
	};

}
