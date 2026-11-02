#include "engine/emv0x.h"
#include <iostream>q 



void App::Initialize() {
	renderer.set_renderer_api(renderer.RENDERER_API_DX11);
	renderer.report_renderer_api();
	Renderer::Window window;
	window.fullscreen = false;
	window.name = L"Emv0x Demo";
	window.height = 600;
	window.width = 800;
	window.resizable = false;
	window.window_mode = Renderer::WINDOW_MODE_REGULAR;

	Renderer::InstantiatedWindow window_instance = renderer.create_window_instance(window);
	//window.name = L"Other Window";
	//Renderer::InstantiatedWindow window_instance2 = renderer.create_window_instance(window);
}

void App::Update() {
	renderer.handle_windows();
}

void App::Shutdown() {

}