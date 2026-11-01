#include "engine/emv0x.h"
#include <iostream>



void App::Initialize() {
	renderer.set_renderer_api(renderer.RENDERER_API_DX11);
	renderer.report_renderer_api();
	
}

void App::Update() {
	renderer.handle_windows();
}

void App::Shutdown() {

}