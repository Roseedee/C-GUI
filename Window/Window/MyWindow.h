#pragma once
#include <Windows.h>

class MyWindow
{

private:

	//properties
	HINSTANCE hInstance;
	HWND hwnd;
	RECT rectWindow;
	LPCSTR wTitle;
	WNDCLASSEX wc;

	//methods
	bool init();



public:

	//methods
	MyWindow(HINSTANCE hInstance);

	void SetTitle(LPCSTR wTtile) {
		this->wTitle = wTtile;
	}

	LPCSTR GetTitle() {
		return this->wTitle;
	}




};

