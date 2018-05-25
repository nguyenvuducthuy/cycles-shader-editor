#pragma once

#include <vector>

#include "input_box.h"
#include "panel_edit_color.h"
#include "panel_edit_curve.h"
#include "subwindow.h"

namespace CyclesShaderEditor {

	class BoolValueClickTarget;
	class NodeSocket;
	class StringEnumClickTarget;

	class ParamEditorSubwindow : public NodeEditorSubwindow {
	public:
		ParamEditorSubwindow(FloatPos screen_position);

		virtual void pre_draw() override;

		virtual void set_mouse_position(FloatPos local_position, float max_pos_y) override;

		virtual void handle_mouse_button(int button, int action, int mods) override;
		virtual void handle_key(int key, int scancode, int action, int mods) override;
		virtual void handle_character(unsigned int codepoint) override;
		virtual void mouse_left_release() override;

		virtual bool should_capture_input() const override;

		virtual bool is_active() const override;

		virtual bool needs_undo_push() override;

		void set_selected_param(NodeSocket* selected_param);

		void complete_input();


	protected:
		virtual void draw_content(NVGcontext* draw_context) override;

		void select_input(BaseInputBox* input);

		bool is_bool_target_under_mouse();
		bool is_enum_target_under_mouse();
		void click_bool_target_under_mouse();
		void click_enum_target_under_mouse();

		NodeSocket* selected_param = nullptr;

		BaseInputBox* selected_input = nullptr;

		float panel_start_y = 0;

		// Panels
		EditColorPanel panel_color;
		EditCurvePanel panel_curve;

		// Int stuff
		IntInputBox int_input_box;

		// Float stuff
		FloatInputBox float_input_box;

		// Vector stuff
		FloatInputBox vector_x_input_box;
		FloatInputBox vector_y_input_box;
		FloatInputBox vector_z_input_box;

		// Enum stuff
		std::vector<StringEnumClickTarget> enum_targets;

		// Bool stuff
		std::vector<BoolValueClickTarget> bool_targets;

		// Undo state stuff
		bool request_undo_stack_push = false;
	};

}
