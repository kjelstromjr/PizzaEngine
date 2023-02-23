#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <chrono>
#include "Handler.h"
#include "KeyBoard.h"
#include "Timer.h"
#include "Mouse.h"
#include "Clickable.h"
#include <thread>
#include <functional>
#include "Windows.h"

#define _WIN32_WINNT 0x0500

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class Window {
	public:
		Window(LPCWSTR title, Handler* hander);
		Window(LPCWSTR title, bool fullscreen, Handler* hander);
		Window(LPCWSTR title, int width, int height, Handler* hander);
		Window(LPCWSTR title, int width, int height, bool fullscreen, Handler* hander);
		Window(const Window&) = delete;
		Window& operator = (const Window) = delete;
		~Window();
		static int getWidth();
		static int getHeight();
		void start();
		void hideConsole();
		void showConsole();
		void setFPS(int fps);
		int getFPS();

	private:
		HINSTANCE m_hInstance;
		static int width, height;
		void gameLoop(HWND window, HDC hdc);
		void setup(HWND window, HDC hdc);
		HWND thisWindow;
		HDC thisHDC;
		Handler* handler;
		bool hasSetup;
		int fps = 60;
		static bool isFull;
};

#endif