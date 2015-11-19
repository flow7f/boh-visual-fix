#include "main.h"

// Direct3DCreate8 implementation, that will return fake object for fix bugs
extern "C" IDirect3D8 * WINAPI Direct3DCreate8(UINT SDKVersion) {
	return BohaDirect3DCreate8(SDKVersion);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) {
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		LoadD3D8();
		//settings.load();
		//hooks.Install();
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;

	case DLL_PROCESS_DETACH:
		//hooks.Uninstall();
		if (hD3D8) {
			FreeLibrary(hD3D8);
			hD3D8 = 0;
		}
		break;
	}
	return TRUE;
}
