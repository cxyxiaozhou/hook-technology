#include<windows.h>

HHOOK g_hHock;
extern "C" _declspec(dllexport) BOOL InstallHock();



extern "C" _declspec(dllexport) BOOL UninstallHock();

LRESULT CALLBACK KeyboardProc(int code, WPARAM wParam, LPARAM lParam);