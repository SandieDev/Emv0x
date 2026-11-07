#include "../gl.h"


//random stackoverflow solution
void* getGLfuncAddress(const char* name)
{
    void* p = (void*)wglGetProcAddress(name);
    if (p == 0 ||
        (p == (void*)0x1) || (p == (void*)0x2) || (p == (void*)0x3) ||
        (p == (void*)-1))
    {
        HMODULE module = LoadLibraryA("opengl32.dll");
        p = (void*)GetProcAddress(module, name);
    }

    return p;
}

int renderer_gl::initGL(std::vector<Renderer::InstantiatedWindow>& windows, HWND window_handle) {
    //Create Device context
    HDC hdc = GetDC(window_handle);
    
    //Create a framebuffer description
    PIXELFORMATDESCRIPTOR pfd{};
    
    //Set pfd flags
    pfd.nSize = sizeof(pfd); //size
    pfd.nVersion = 1; //version
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER; //what it is allowed to do
    pfd.iPixelType = PFD_TYPE_RGBA; //pixel type
    pfd.cColorBits = 32; //how many bits for the color channels
    pfd.cDepthBits = 24;
    pfd.cStencilBits = 8;
    pfd.iLayerType = PFD_MAIN_PLANE; //use the reg rendering layer

    int format = ChoosePixelFormat(hdc, &pfd); //Set best graphics setup

    SetPixelFormat(hdc, format, &pfd); //Apply chosen format
    
    HGLRC glContext = wglCreateContext(hdc); //create the gl context

    wglMakeCurrent(hdc, glContext);

    if (!gladLoadGLLoader((GLADloadproc)getGLfuncAddress))
    {
        MessageBox(NULL, L"OpenGL failed to initialize, exit code: 003", L"Error", MB_OK | MB_ICONERROR);
        abort();
    }
    windowListRef = &windows;
    RECT rect{};
    GetClientRect(window_handle, &rect);

    int clientWidth = rect.right - rect.left;
    int clientHeight = rect.bottom - rect.top;

    glViewport(0, 0, clientWidth, clientHeight);
    return 0;
}