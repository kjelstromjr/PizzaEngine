#pragma once

#include <iostream>
#include <windows.h>
#include <XInput.h>
#pragma comment(lib, "Xinput.lib")

using namespace std;

class Util {
	public:
	static LPCWSTR stringToLPCWSTR(string str);
};