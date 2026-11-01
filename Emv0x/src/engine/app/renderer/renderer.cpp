#include "renderer.h"

void Renderer::set_renderer_api(RendererAPI api) {
	renderer_api = api;
}

Renderer::RendererAPI Renderer::get_renderer_api() {
	return renderer_api;
}

void Renderer::report_renderer_api() {
    MessageBoxW(0,
        get_renderer_api() == RENDERER_API_DX11 ? L"DirectX 11" :
        get_renderer_api() == RENDERER_API_GL ? L"OpenGL" :
        L"None",
        L"Renderer API", MB_OK);
}

