	#include "renderer.h"

	void Renderer::handle_windows() {
		for (InstantiatedWindow& window : instanced_windows) {

		}
	}

	Renderer::InstantiatedWindow Renderer::create_window_instance(Window window) {
		InstantiatedWindow temp;

		temp.width = window.width;
		temp.height = window.height;
		temp.fullscreen = window.fullscreen;
		temp.resizable = window.resizable;
		temp.window_mode = window.window_mode;
		temp.name = window.name;

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
		temp.wc.lpszMenuName = NULL;
		temp.wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO);

		instanced_windows.push_back(temp);
		return temp;
	}

	bool Renderer::windows_open() {
		return !instanced_windows.empty();
	}

	bool Renderer::initialize_windows() {
		if (!instanced_windows.empty()) {
			for (InstantiatedWindow& window : instanced_windows) {
				window.wc.lpszClassName = window.name.c_str();
				if (!RegisterClassEx(&window.wc)) {
					MessageBox(NULL, L"Window Class failed to register, exit code: 001", L"Error", MB_OK | MB_ICONERROR);
					abort();
				}
				DWORD window_style;

				if (window.fullscreen) {
					window_style = WS_POPUP;

					window.width = GetSystemMetrics(SM_CXSCREEN);
					window.height = GetSystemMetrics(SM_CYSCREEN);
				}
				else {
					window_style = WS_OVERLAPPEDWINDOW;

					if (!window.resizable) {
						window_style &= ~(WS_THICKFRAME | WS_MAXIMIZEBOX);
					}
				}

				window.window_handle = CreateWindowEx(
					NULL,
					window.name.c_str(),
					window.name.c_str(),
					window_style,
					CW_USEDEFAULT, CW_USEDEFAULT,
					window.width, window.height,
					NULL,
					NULL,
					reference_hInstance,
					NULL
				);
				if (!window.window_handle) {
					MessageBox(NULL, L"Window failed to register, exit code: 002", L"Error", MB_OK | MB_ICONERROR);
					abort();
				}
				if (window.window_mode == WINDOW_MODE_MAXIMISED) {
					ShowWindow(window.window_handle, SW_SHOWMAXIMIZED);
				}
				else if (window.window_mode == WINDOW_MODE_MINIMISED) {
					ShowWindow(window.window_handle, SW_SHOWMINIMIZED);
				}
				else {
					ShowWindow(window.window_handle, SW_SHOW);
				}

				UpdateWindow(window.window_handle);

			}
		}
		return true;
	}