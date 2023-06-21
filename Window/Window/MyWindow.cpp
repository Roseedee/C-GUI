#include "MyWindow.h"

MyWindow::MyWindow(HINSTANCE hInstance) :
	hInstance(hInstance)
{
	if (!this->init())
		MessageBox(NULL, L"Error Register Class Window", L"Register Error", MB_OK);

	if (!this->createWindow())
		MessageBox(NULL, L"Error Create Window", L"Create Window Error", MB_OK);


}

bool MyWindow::init() {

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.hInstance = this->hInstance;
	wc.lpfnWndProc = reinterpret_cast<WNDPROC>(&MyWindow::WindowProc);
	wc.lpszClassName = this->windowClass();
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255));
	wc.style = CS_VREDRAW | CS_HREDRAW;

	return RegisterClass(&this->wc);
}

bool MyWindow::createWindow() {
	this->hwnd = CreateWindow( this->windowClass(), this->windowTitle(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, NULL, NULL);

	return hwnd ? true : false;
}



LRESULT CALLBACK MyWindow::WindowProc(HWND hWnd, int msg, WPARAM wParam, LPARAM lParam)
{
	MyWindow* pWindow = nullptr;

	if (msg == WM_NCCREATE)
	{
		CREATESTRUCT* pCreateStruct = reinterpret_cast<CREATESTRUCT*>(lParam);
		pWindow = static_cast<MyWindow*>(pCreateStruct->lpCreateParams);
		SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWindow));
	}
	else
	{
		pWindow = reinterpret_cast<MyWindow*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
	}

	if (pWindow)
	{
		return pWindow->HandleMessage(hWnd, msg, wParam, lParam);
	}

	if (msg == WM_DESTROY)
		PostQuitMessage(0);

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT CALLBACK MyWindow::HandleMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
	{
		
		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}