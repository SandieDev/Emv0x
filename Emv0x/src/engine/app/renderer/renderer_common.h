#pragma once
#include <vector>
#include <string>

class Renderer {
public:
	//Do not reference the hInstance
	HINSTANCE reference_hInstance;

	//Window mode when opening the application
	enum WindowMode : int {
		WINDOW_MODE_MAXIMISED,
		WINDOW_MODE_MINIMISED,
		WINDOW_MODE_REGULAR
	};

	//Render APIs, defaults to DX11
	enum RendererAPI : int {
		RENDERER_API_DX11,
		RENDERER_API_GL,
		RENDERER_API_NULL
	};

	int setupRenderAPI();

	//Window, used to set settings before instantiating it
	class Window {
	public:
		int width = 800;
		int height = 600;
		bool fullscreen = false;
		bool resizable = false;
		std::wstring name = L"Emv0x App";
		WindowMode window_mode = WINDOW_MODE_REGULAR;
	};

	//Instance of a window, ready to be loaded
	class InstantiatedWindow {
	public:
		int width;
		int height;
		bool fullscreen;
		bool resizable;
		std::wstring name;
		WindowMode window_mode;
		HWND window_handle = NULL;
		WNDCLASSEX wc;
	};

	//Creates a window instance
	InstantiatedWindow create_window_instance(Window window);

	//Functions relating to render apis
	void set_renderer_api(RendererAPI api);
	RendererAPI get_renderer_api();
	void report_renderer_api();

	//Helper func to check if the windows are still open
	bool windows_open();
	

	//Handles window events
	int handle_windows();

	//Helper func to instantiate the window
	bool initialize_windows();

	//A vector of all instantiated windows
	std::vector<InstantiatedWindow> instanced_windows;
private:
	RendererAPI renderer_api = RENDERER_API_NULL;

	inline static HWND destroyed_window = nullptr;

	static LRESULT CALLBACK WndProc(HWND hWnd,
		UINT msg,
		WPARAM wParam,
		LPARAM lParam);

};
