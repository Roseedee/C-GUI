#pragma once
#include <Windows.h>

class MyWindow
{

private:

	//properties
	HINSTANCE hInstance;
	HWND hwnd;
	WNDCLASS wc;
	RECT rc;

	//methods
	LPCWSTR windowClass = L"MyWindow";
	LPCWSTR windowTitle = L"Window";

	bool createWindow();

	static LRESULT CALLBACK WindowProc(HWND hwnd, int msg, WPARAM wParam, LPARAM lParam);


public:

	//methods
	MyWindow(HINSTANCE hInstance);
	bool init();

	//---------- methods for Set ----------//
	//below method use before init() method, if use after init() method is void
	void setRect(RECT rc) {
		this->rc = rc;
	}

	void setPosition(int x, int y) {
		rc.left = x;
		rc.top = y;
	}

	void setSize(int width, int height) {
		rc.right = width;
		rc.bottom = height;
	}

	void setTitle(LPCWSTR windowTitle) {
		this->windowTitle = windowTitle;
	}


	//---------- end ----------//

	//---------- methods for Get ----------//
	
	HWND Window() {
		return hwnd;
	}

	HINSTANCE Instance() {
		return hInstance;
	}
	
	//---------- end ----------//




};

