#include "renderer.h"

void Renderer::handle_windows() {
    for (InstantiatedWindow window : instanced_windows) {

    }
}

Renderer::InstantiatedWindow Renderer::create_window_instance(Window window) {
    InstantiatedWindow temp;

    temp.width = window.width;
    temp.height = window.height;
    temp.fullscreen = window.fullscreen;
    temp.resizable = window.fullscreen;
    temp.window_mode = window.window_mode;
    temp.name = window.name;
    temp.window_class_name = temp.name.c_str();

    //Extended Window Class
    temp.wc.cbSize = sizeof(temp.wc);
    temp.wc.style = CS_HREDRAW | CS_VREDRAW;
    temp.wc.lpfnWndProc = WndProc;
    temp.wc.cbClsExtra = NULL;
    temp.wc.cbWndExtra = NULL;
    temp.wc.hInstance = reference_hInstance;
    temp.wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    temp.wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    temp.wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
    temp.wc.lpszClassName = temp.window_class_name;
    temp.wc.lpszMenuName = NULL;
    temp.wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO);


    instanced_windows.push_back(temp);
    return temp;
}

bool Renderer::windows_open() {
    if (instanced_windows.empty()) {
        return false;
    }
    else {
        return true;
    }
}

bool Renderer::initialize_window(HINSTANCE hInstance,
    int ShowWnd,
    int width, int height,
    bool windowed) {

}