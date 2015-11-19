#pragma once
#include <memory>
#include <unordered_set>

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <windowsx.h>
#include <d3d8.h>

#include "DebugOut.h"
#include "DummyD3D8Interfaces.h"

extern "C" IDirect3D8 * WINAPI BohaDirect3DCreate8(UINT SDKVersion);
extern "C" typedef IDirect3D8* (WINAPI *PDirect3DCreate8)(UINT);

extern PDirect3DCreate8 origDirect3DCreate8;

extern HMODULE hD3D8;

// Load default dll module from system32 / SysWOW64 directory
HMODULE LoadOriginalModule(const char *moduleName);

// Load original D3D8.dll and initialize origDirect3DCreate8
bool LoadD3D8();
