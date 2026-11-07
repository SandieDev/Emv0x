#include "emv0x.h"

int WINAPI WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nShowCmd) {
    App program;

    program.renderer.reference_hInstance = hInstance;
    program.Initialize();
    program.renderer.initialize_windows();
    program.renderer.setupRenderAPI();

    while (program.renderer.windows_open()) {
        program.Update();
    }

    program.Shutdown();
    return 0;
}