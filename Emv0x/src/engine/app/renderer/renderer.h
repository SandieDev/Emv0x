#pragma once
#include <windows.h>
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

	//Window, used to set settings before instantiating it/
	class Window {
	public:
		int width;
		int height;
		bool fullscreen;
		bool resizable;
		std::wstring name;
		WindowMode window_mode;
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
		LPCTSTR window_class_name;
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
	void handle_windows();
	

private:
	RendererAPI renderer_api = RENDERER_API_NULL;
	
	//A vector of all instantiated windows
	std::vector<InstantiatedWindow> instanced_windows;
	
	//Helper func to instantiate the window
	bool initialize_window(HINSTANCE hInstance,
		int ShowWnd,
		int width, int height,
		bool windowed);

	static LRESULT CALLBACK WndProc(HWND hWnd,
		UINT msg,
		WPARAM wParam,
		LPARAM lParam);
	
};
