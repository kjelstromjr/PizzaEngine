#include "Util.h"

LPCWSTR Util::stringToLPCWSTR(string str) {
	wstring temp = wstring(str.begin(), str.end());
	// Applying c_str() method on temp
	LPCWSTR wideString = temp.c_str();

	return wideString;
}
