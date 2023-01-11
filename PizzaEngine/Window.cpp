#include "Window.h"

bool running = true;

Render_State render_state;

HDC* something = NULL;

int Window::width = 0;
int Window::height = 0;

LRESULT CALLBACK window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	LRESULT result = 0;

	switch (uMsg) {
		case WM_CLOSE:
		case WM_DESTROY: {
			running = false;
		} break;

		case WM_SIZE: {
			RECT rect;
			GetClientRect(hwnd, &rect);
			render_state.width = rect.right - rect.left;
			render_state.height = rect.bottom - rect.top;

			int size = render_state.width * render_state.height * sizeof(unsigned int);

			if (render_state.memory) VirtualFree(render_state.memory, 0, MEM_RELEASE);
			render_state.memory = VirtualAlloc(0, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

			render_state.bitmap_info.bmiHeader.biSize = sizeof(render_state.bitmap_info.bmiHeader);
			render_state.bitmap_info.bmiHeader.biWidth = render_state.width;
			render_state.bitmap_info.bmiHeader.biHeight = render_state.height;
			render_state.bitmap_info.bmiHeader.biPlanes = 1;
			render_state.bitmap_info.bmiHeader.biBitCount = 32;
			render_state.bitmap_info.bmiHeader.biCompression = BI_RGB;

			//Hello there

		} break;

		default: {
			result = DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
	}
	return result;
}


Window::Window(LPCWSTR title, Handler* handler) : m_hInstance(GetModuleHandle(nullptr)) {
	// Create Window Class
	WNDCLASS window_class = {};
	// Able to be redrawn vertically and horizontally
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	// Identifier for class
	window_class.lpszClassName = title;
	// Callback for messages from window
	window_class.lpfnWndProc = window_callback;
	// Register Class
	RegisterClass(&window_class);
	Window::width = 1280;
	Window::height = 720;
	// Create Window
	//  WS_VISIBLE | WS_MAXIMIZE | WS_POPUPWINDOW - fullscreen
	HWND window = CreateWindow(window_class.lpszClassName, title, WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, Window::width, Window::height, 0, 0, m_hInstance, 0);
	HDC hdc = GetDC(window);

	this->handler = handler;
	std::cout << this->handler;
	setup(window, hdc);
}

Window::Window(LPCWSTR title, bool fullscreen, Handler* handler) {
	// Create Window Class
	WNDCLASS window_class = {};
	// Able to be redrawn vertically and horizontally
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	// Identifier for class
	window_class.lpszClassName = title;
	// Callback for messages from window
	window_class.lpfnWndProc = window_callback;
	// Register Class
	RegisterClass(&window_class);
	Window::width = 1280;
	Window::height = 720;
	// Create Window
	//  WS_VISIBLE | WS_MAXIMIZE | WS_POPUPWINDOW - fullscreen

	HWND window;

	if (fullscreen) {
		window = CreateWindow(window_class.lpszClassName, title, WS_VISIBLE | WS_MAXIMIZE | WS_POPUPWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, Window::width, Window::height, 0, 0, m_hInstance, 0);
	} else {
		window = CreateWindow(window_class.lpszClassName, title, WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, Window::width, Window::height, 0, 0, m_hInstance, 0);
	}

	HDC hdc = GetDC(window);

	this->handler = handler;
	setup(window, hdc);
}

Window::Window(LPCWSTR title, int width, int height, Handler* handler) {
	// Create Window Class
	WNDCLASS window_class = {};
	// Able to be redrawn vertically and horizontally
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	// Identifier for class
	window_class.lpszClassName = title;
	// Callback for messages from window
	window_class.lpfnWndProc = window_callback;
	// Register Class
	RegisterClass(&window_class);
	Window::width = width;
	Window::height = height;
	// Create Window
	//  WS_VISIBLE | WS_MAXIMIZE | WS_POPUPWINDOW - fullscreen
	HWND window = CreateWindow(window_class.lpszClassName, title, WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, Window::width, Window::height, 0, 0, m_hInstance, 0);
	HDC hdc = GetDC(window);

	this->handler = handler;
	setup(window, hdc);
}

Window::Window(LPCWSTR title, int width, int height, bool fullscreen, Handler* handler) {
	// Create Window Class
	WNDCLASS window_class = {};
	// Able to be redrawn vertically and horizontally
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	// Identifier for class
	window_class.lpszClassName = title;
	// Callback for messages from window
	window_class.lpfnWndProc = window_callback;
	// Register Class
	RegisterClass(&window_class);
	Window::width = width;
	Window::height = height;
	// Create Window
	//  WS_VISIBLE | WS_MAXIMIZE | WS_POPUPWINDOW - fullscreen
	HWND window;

	if (fullscreen) {
		window = CreateWindow(window_class.lpszClassName, title, WS_VISIBLE | WS_MAXIMIZE | WS_POPUPWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, Window::width, Window::height, 0, 0, m_hInstance, 0);
	} else {
		window = CreateWindow(window_class.lpszClassName, title, WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, Window::width, Window::height, 0, 0, m_hInstance, 0);
	}
	HDC hdc = GetDC(window);

	this->handler = handler;
	setup(window, hdc);
}

Window::~Window() {
	const wchar_t* CLASS_NAME = L"Hugos Window Class";

	UnregisterClass(CLASS_NAME, m_hInstance);
}

int Window::getWidth() {
	return Window::width;
}

int Window::getHeight() {
	return Window::height;
}

void render(bool* run, Handler* h, int frames) {
	Renderer::setRenderState(render_state);
	Render_State nextFrame;
	while (*run) {
		Sleep(1000 / frames);
		Renderer::clearScreen(0xffffff);
		h->draw();
		nextFrame = render_state;
		StretchDIBits(*something, 0, 0, nextFrame.width, nextFrame.height, 0, 0, nextFrame.width, nextFrame.height, nextFrame.memory, &nextFrame.bitmap_info, DIB_RGB_COLORS, SRCCOPY);
	}
}

void Window::start() {

	Input* input = KeyBoard::getInput();

	something = &(Window::thisHDC);

	std::thread t(std::bind(render, &running, handler, fps));

	auto start = std::chrono::system_clock::now();
	auto end = std::chrono::system_clock::now();
	auto elapsed = end - start;

	double elapsed_seconds = 0.0;

	POINT p;

	while (running) {

		start = std::chrono::system_clock::now();

		Sleep(1);

		// Input
		MSG message;

		for (int i = 0; i < COUNT; i++) {
			input->buttons[i].changed = false;
		}

		while (PeekMessage(&message, Window::thisWindow, 0, 0, PM_REMOVE)) {
			switch (message.message) {
				case WM_KEYUP:
				case WM_KEYDOWN: {
					unsigned int vk_code = (unsigned int)message.wParam;
					bool is_down = ((message.lParam & (1 << 31)) == 0);
					KeyBoard::processKey(vk_code, is_down);
					
					/*
					switch (vk_code) {
						case VK_UP: {
							input.buttons[UP].isDown = is_down;
							input.buttons[UP].changed = true;
						} break;
					}
					*/
				} break;

				default: {
					TranslateMessage(&message);
					DispatchMessage(&message);
				}
			}
		}

		if (GetCursorPos(&p)) {
			ScreenToClient(Window::thisWindow, &p);
			Mouse::setPos(p.x, p.y);
			//std::cout << "X: " << p.x << " Y: " << p.y << std::endl;
		}

		// Simulate

		handler->update();

		//std::cout << input.buttons[UP].isDown;

		//drawRectInPixels(10, render_state.height - 10, 200, 200, 0xabcdef);
		//Renderer::drawRect(10, 10, 100, 100, 0xabcdef);
		//Renderer::drawPixel(10, 10, 0x00);
		//count += 0.1f;

		// Render
		//StretchDIBits(Window::thisHDC, 0, 0, render_state.width, render_state.height, 0, 0, render_state.width, render_state.height, render_state.memory, &render_state.bitmap_info, DIB_RGB_COLORS, SRCCOPY);

		end = std::chrono::system_clock::now();

		// Calculate the elapsed time
		elapsed = end - start;

		// Convert the elapsed time to a floating-point value in seconds
		elapsed_seconds = std::chrono::duration<double>(elapsed).count();
		//double elapsed_seconds = 0;

		Timer::setTimeElapsed(elapsed_seconds * 1000);

	}

	t.join();
}

void Window::setup(HWND window, HDC hdc) {
	Window::thisWindow = window;
	Window::thisHDC = hdc;
}

void Window::hideConsole() {
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

void Window::showConsole() {
	::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}

int Window::getFPS() {
	return fps;
}

void Window::setFPS(int fps) {
	this->fps = fps;
}