#include "MyWindow.h"

MyWindow::MyWindow(HINSTANCE hInstance) :
	hInstance(hInstance)
{
	if (this->init())
		MessageBox(NULL, L"Error Register Class Window", L"Register Error", MB_OK);

}

bool MyWindow::init() {

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.hInstance = this->hInstance;

	return RegisterClassEx(&this->wc);
}
