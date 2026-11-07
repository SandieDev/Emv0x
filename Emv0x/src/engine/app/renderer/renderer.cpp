#include "renderer.h"

renderer_gl glBackend;

int Renderer::setupRenderAPI() {
	if (renderer_api == RENDERER_API_GL && !instanced_windows.empty()) {
		glBackend.initGL(instanced_windows, instanced_windows[0].window_handle);
	}
	return 0;
}

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

LRESULT CALLBACK Renderer::WndProc(HWND hWnd,
	UINT msg,
	WPARAM wParam,
	LPARAM lParam) {
	switch (msg)
	{
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) {
			DestroyWindow(hWnd);
		}
		return 0;

	case WM_DESTROY:
		destroyed_window = hWnd;
		PostQuitMessage(0);
		return 0;
	
	case WM_SIZE:
		int width = LOWORD(lParam);
		int height = HIWORD(lParam);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
};
