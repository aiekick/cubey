#pragma once

#include "cubey.h"

namespace cubey {
	class CameraTest : public EngineEventsBase {
	public:
		void Init() override;
		void Render() override;

	private:
		ShaderProgram* prog;
		Mesh* mesh;
		MeshInstance* mesh_instance;
	};

}


