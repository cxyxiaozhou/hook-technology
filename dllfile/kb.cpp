#include "kb.h"

BOOL InstallHock()
{
	g_hHock = SetWindowsHookEx(WH_KEYBOARD, KeyboardProc, GetModuleHandle(L"kb"), 0);
	if (g_hHock == NULL);
		return FALSE;
	return TRUE;
}


BOOL UninstallHock()
{
	return UnhookWindowsHookEx(g_hHock);
}

LRESULT CALLBACK KeyboardProc(int code, WPARAM wParam, LPARAM lParam)
{
	return 1;
}