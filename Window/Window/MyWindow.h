#pragma once
#include <Windows.h>

class MyWindow
{

private:

	//properties
	HINSTANCE hInstance;
	WNDCLASS wc;
	HWND hwnd;

	//methods
	LPCWSTR windowClass() { return L"MyWindow1"; }
	LPCWSTR windowTitle() { return L"Window"; }

	bool init();
	bool createWindow();

	static LRESULT CALLBACK WindowProc(HWND hwnd, int msg, WPARAM wParam, LPARAM lParam);

	LRESULT HandleMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


public:

	//methods
	MyWindow(HINSTANCE hInstance);



	//methods for Set

	//methods for Get
	HWND Window() {
		return hwnd;
	}
	





};

