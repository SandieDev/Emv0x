#include "emv0x.h"

int WINAPI WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nShowCmd) {
    App program;

    program.renderer.hInstance = hInstance;
    program.Initialize();

    while (program.renderer.windows_open()) {
        program.Update();
    }

    program.Shutdown();
    return 0;
}