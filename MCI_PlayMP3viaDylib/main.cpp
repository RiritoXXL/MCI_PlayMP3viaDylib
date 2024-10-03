#include <Windows.h>
#include <iostream>
#include <dylib.hpp>
using namespace std;

int main() 
{
	dylib libwinmm("C:\\Windows\\System32", "winmm");
	auto get_mcisendstrfunc = libwinmm.get_function<DWORD(LPCTSTR, LPTSTR, uint32_t, HANDLE)>("mciSendStringW");
	get_mcisendstrfunc((LPCTSTR)L"play Example.mp3 repeat", NULL, NULL, NULL);
	while (true) {
		Sleep(3000);
	}
	return 0;
}