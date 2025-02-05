#include "Common.hpp"

using namespace std;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	
	while (true) if (MessageBox(NULL, "Hello World!", "Press 'OK' to leave", MB_OKCANCEL) == MB_OKCANCEL) break;
	
	return 0;
}
