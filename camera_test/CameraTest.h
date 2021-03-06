#pragma once

#include "cubey.h"

namespace cubey {
	class CameraTest : public EngineEventsBase, public AutoXmlBase<CameraTest> {
	public:
		void Init() override;
		void Render() override;

	private:

		GLuint t2_shadow_map_;

		GLuint tc_shadow_map_;
		GLuint fb_shadow_pass_;

		GLuint tc_reflection_map_c_;
		GLuint tc_reflection_map_d_;
		GLuint fb_reflection_pass_;

		//MeshInstance* mi_fsq_;
		MeshInstance* mi_plane_;
		MeshInstance* mi_box_;
		MeshInstance* mi_ball_;
		MeshInstance* mi_ball_2_;
		//MeshInstance* mi_tea_pot_;

		ShaderProgram* sp_shadow_pass_;
		ShaderProgram* sp_reflection_pass_;
		ShaderProgram* sp_render_pass_;
		//ShaderProgram* sp_second_;
	};

}


