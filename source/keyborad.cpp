#include<windows.h>
#pragma comment(lib,"hacker.lib")

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

extern "C" _declspec(dllexport) BOOL InstallHook();



extern "C" _declspec(dllexport) BOOL UninstallHook();
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdline, int nCmdShow)
{
	TCHAR szAppclassName[] = TEXT("security");
	
	WNDCLASS wc = { 0 };
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WindowProc;
	wc.lpszClassName = szAppclassName;
	wc.style = CS_HREDRAW | CS_VREDRAW;



	RegisterClass(&wc);
  HWND hWnd=CreateWindow(
		szAppclassName,
		TEXT("security"),
		WS_OVERLAPPEDWINDOW,
		400, 200,
		800,600,
		NULL,
		NULL,
		hInstance,
		NULL,
		);
  ShowWindow(hWnd,SW_SHOW);
  UpdateWindow(hWnd);
  MSG msg;
  while (GetMessage(&msg,NULL,0,0))
  {
	  TranslateMessage(&msg);
	  DispatchMessage(&msg);
  }
  system("pause");
	return 0;
}


LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		InstallHook();
		break;
	case WM_CLOSE:
			DestroyWindow(hWnd);
			break;
	case WM_DESTROY:
			UninstallHook();
			PostQuitMessage(0);
			break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}