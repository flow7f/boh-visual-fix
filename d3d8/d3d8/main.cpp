#include "main.h"

#ifdef _WIN64
#error for battle of heroes there must be 32 bit dll
#endif

extern "C" IDirect3D8 * WINAPI BohaDirect3DCreate8(UINT SDKVersion) {
	return origDirect3DCreate8(SDKVersion);
}

PDirect3DCreate8 origDirect3DCreate8 = nullptr;
HMODULE hD3D8 = 0;

HMODULE LoadOriginalModule(const char *moduleName) {
	BOOL isWow64 = FALSE;
	if (!::IsWow64Process(GetCurrentProcess(), &isWow64))
		isWow64 = FALSE;

	std::unique_ptr<char[]> sysDirectory(new char[MAX_PATH + 1]);
	UINT nCopied = 0;
	if (isWow64)
		nCopied = ::GetSystemWow64DirectoryA(sysDirectory.get(), MAX_PATH);
	else
		nCopied = ::GetSystemDirectoryA(sysDirectory.get(), MAX_PATH);
	if (nCopied == 0)
		return 0;

	::lstrcatA(sysDirectory.get(), "\\");
	::lstrcatA(sysDirectory.get(), moduleName);
	return ::LoadLibraryExA(sysDirectory.get(), 0, LOAD_WITH_ALTERED_SEARCH_PATH);
}

bool LoadD3D8() {
	hD3D8 = ::LoadOriginalModule("d3d8.dll");
	if (!hD3D8) {
		MessageBoxA(nullptr, "Failed to find original d3d8.dll", "Fix failed", MB_OK | MB_ICONERROR);
		return false;
	}

	origDirect3DCreate8 = reinterpret_cast<PDirect3DCreate8>(::GetProcAddress(hD3D8, "Direct3DCreate8"));
	if (!origDirect3DCreate8) {
		MessageBoxA(nullptr, "Failed to find original Direct3DCreate8", "Fix failed", MB_OK | MB_ICONERROR);
		FreeLibrary(hD3D8);
		hD3D8 = 0;
		return false;
	}
	return true;
}
