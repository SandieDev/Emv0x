#pragma once
#include "gl/include/glad/glad.h"
#include "../../logger/logger.h"
#include "windowsheader.h"
#include "../renderer_common.h"

class renderer_gl {
public:
	enum OPENGL_VERSION {
		GL_46,
		GL_45,
		GL_44,
		GL_43,
		GL_42,
		GL_41,
		GL_40,
		GL_33
	};

	int initGL(std::vector<Renderer::InstantiatedWindow>& windows, HWND window_handle);

	std::vector<Renderer::InstantiatedWindow>* windowListRef = nullptr;
};