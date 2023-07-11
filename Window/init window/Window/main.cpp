#include <Windows.h>
#include "MyWindow.h"


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
	
	MyWindow* win = new MyWindow(hInstance);

	win->setTitle(L"Roseedee");

	win->init();

	ShowWindow(win->Window(), nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	delete win;


	return (int)msg.wParam;
}

