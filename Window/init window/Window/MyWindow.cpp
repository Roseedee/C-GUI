#include "MyWindow.h"

MyWindow::MyWindow(HINSTANCE hInstance)
{
	this->hInstance = hInstance;
	this->hwnd = NULL;

	SetRect(&rc, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT);

	ZeroMemory(&wc, sizeof(WNDCLASS));
	wc.hInstance = hInstance;
	wc.lpfnWndProc = reinterpret_cast<WNDPROC>(&MyWindow::WindowProc);
	wc.lpszClassName = windowClass;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255));
	wc.style = CS_VREDRAW | CS_HREDRAW;
}

bool MyWindow::init() {

	if (!RegisterClass(&wc)) {
		MessageBox(NULL, L"Error Register Class Window", L"Register Error", MB_OK);
		return false;
	}

	if (!createWindow()) {
		MessageBox(NULL, L"Error Create Window", L"Create Window Error", MB_OK);
		return false;
	}

	return true;
}

bool MyWindow::createWindow() {
	hwnd = CreateWindow(windowClass, windowTitle, WS_OVERLAPPEDWINDOW, rc.left, rc.top, rc.right, rc.bottom, NULL, NULL, hInstance, NULL);
	return hwnd ? true : false;
}



LRESULT CALLBACK MyWindow::WindowProc(HWND hWnd, int msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
