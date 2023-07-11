#pragma once
#include <Windows.h>

class MyWindow
{

private:

	//properties
	HINSTANCE hInstance;
	WNDCLASS wc;
	HWND hwnd;
	RECT winRect;

	//methods
	LPCWSTR windowClass() { return L"MyWindow1"; }
	LPCWSTR windowTitle() { return L"Window"; }

	bool init();
	bool createWindow();
	void winSize();

	static LRESULT CALLBACK WindowProc(HWND hwnd, int msg, WPARAM wParam, LPARAM lParam);


public:

	//methods
	MyWindow(HINSTANCE hInstance);



	//---------- methods for Set ----------//


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

