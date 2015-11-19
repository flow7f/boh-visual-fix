#pragma once
#include "main.h"

#define DUMMY_DECLARE_INTERFACE_(cls,base) \
class Dummy##cls : public cls {\
	protected:\
		cls *ptr;\
		static std::unordered_set<cls*> myObjects;\
		Dummy##cls(cls *ptr) : ptr(ptr) { TRACE_NORETURN(ptr); myObjects.insert(this); }\
	public:\
		virtual ~Dummy##cls() {\
			TRACE_NORETURN();\
			myObjects.erase(this);\
			if(ptr) { ptr->Release(); }\
		}\
		BOOL WasInitialized() const { return ptr != nullptr; }\
		static cls *Get(cls *t, BOOL isWrite = false) { \
			if( myObjects.find(t) != myObjects.end() ) { \
				Dummy##cls *p = static_cast<Dummy##cls *>(t);\
				if(isWrite)\
					p->__BeginWrite();\
				return p->ptr;\
			}\
			return t;\
		}\
		virtual void __BeginWrite() {};

#define DUMMY_END_INTEFACE };

#pragma region DUMMY_STDMETHOD macros
#define DUMMY_STDMETHOD_15(type, method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6, t7, v7, t8, v8, t9, v9, t10, v10, t11, v11, t12, v12, t13, v13, t14, v14, t15, v15) \
	virtual __declspec(nothrow) type __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6, t7 v7, t8 v8, t9 v9, t10 v10, t11 v11, t12 v12, t13 v13, t14 v14, t15 v15 ) override \
		{\
			type r = ptr->method(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14,v15);\
			TRACEFUNC(r, v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14,v15);\
		return r;\
		}

#define DUMMY_STDMETHOD_VOID_15(method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6, t7, v7, t8, v8, t9, v9, t10, v10, t11, v11, t12, v12, t13, v13, t14, v14, t15, v15) \
	virtual __declspec(nothrow) void __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6, t7 v7, t8 v8, t9 v9, t10 v10, t11 v11, t12 v12, t13 v13, t14 v14, t15 v15 ) override  \
		{\
			ptr->method(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14,v15);\
			TRACE_NORETURN(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14,v15);\
		}

#define DUMMY_STDMETHOD_14(type, method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6, t7, v7, t8, v8, t9, v9, t10, v10, t11, v11, t12, v12, t13, v13, t14, v14) \
	virtual __declspec(nothrow) type __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6, t7 v7, t8 v8, t9 v9, t10 v10, t11 v11, t12 v12, t13 v13, t14 v14) override \
		{\
			type r = ptr->method(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14);\
			TRACEFUNC(r, v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14);\
		return r;\
		}

#define DUMMY_STDMETHOD_VOID_14(method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6, t7, v7, t8, v8, t9, v9, t10, v10, t11, v11, t12, v12, t13, v13, t14, v14) \
	virtual __declspec(nothrow) void __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6, t7 v7, t8 v8, t9 v9, t10 v10, t11 v11, t12 v12, t13 v13, t14 v14) override \
		{\
			ptr->method(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14);\
			TRACE_NORETURN(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13,v14);\
		}

#define DUMMY_STDMETHOD_13(type, method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6, t7, v7, t8, v8, t9, v9, t10, v10, t11, v11, t12, v12, t13, v13) \
	virtual __declspec(nothrow) type __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6, t7 v7, t8 v8, t9 v9, t10 v10, t11 v11, t12 v12, t13 v13, t14 v14) override \
		{\
			type r = ptr->method(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13);\
			TRACEFUNC(r, v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13);\
		return r;\
		}

#define DUMMY_STDMETHOD_VOID_13(method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6, t7, v7, t8, v8, t9, v9, t10, v10, t11, v11, t12, v12, t13, v13) \
	virtual __declspec(nothrow) void __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6, t7 v7, t8 v8, t9 v9, t10 v10, t11 v11, t12 v12, t13 v13) override \
		{\
			ptr->method(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13);\
			TRACE_NORETURN(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,v13);\
		}

#define DUMMY_STDMETHOD_12(type, method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6, t7, v7, t8, v8, t9, v9, t10, v10, t11, v11, t12, v12) \
	virtual __declspec(nothrow) type __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6, t7 v7, t8 v8, t9 v9, t10 v10, t11 v11, t12 v12) override \
		{\
			type r = ptr->method(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12);\
			TRACEFUNC(r, v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12);\
		return r;\
		}

#define DUMMY_STDMETHOD_VOID_12(method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6, t7, v7, t8, v8, t9, v9, t10, v10, t11, v11, t12, v12) \
	virtual __declspec(nothrow) void __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6, t7 v7, t8 v8, t9 v9, t10 v10, t11 v11, t12 v12) override \
		{\
			ptr->method(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12);\
			TRACE_NORETURN(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12);\
		}


#define DUMMY_STDMETHOD_11(type, method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6, t7, v7, t8, v8, t9, v9, t10, v10, t11, v11) \
	virtual __declspec(nothrow) type __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6, t7 v7, t8 v8, t9 v9, t10 v10, t11 v11) override \
		{\
			type r = ptr->method(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11);\
			TRACEFUNC(r, v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11);\
		return r;\
		}

#define DUMMY_STDMETHOD_VOID_11(method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6, t7, v7, t8, v8, t9, v9, t10, v10, t11, v11) \
	virtual __declspec(nothrow) void __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6, t7 v7, t8 v8, t9 v9, t10 v10, t11 v11) override \
		{\
			ptr->method(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11);\
			TRACE_NORETURN(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11);\
		}

#define DUMMY_STDMETHOD_10(type, method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6, t7, v7, t8, v8, t9, v9, t10, v10) \
	virtual __declspec(nothrow) type __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6, t7 v7, t8 v8, t9 v9, t10 v10) override \
		{\
			type r = ptr->method(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10);\
			TRACEFUNC(r, v1,v2,v3,v4,v5,v6,v7,v8,v9,v10);\
		return r;\
		}

#define DUMMY_STDMETHOD_VOID_10(method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6, t7, v7, t8, v8, t9, v9, t10, v10) \
	virtual __declspec(nothrow) void __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6, t7 v7, t8 v8, t9 v9, t10 v10) override \
		{\
			ptr->method(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10);\
			TRACE_NORETURN(v1,v2,v3,v4,v5,v6,v7,v8,v9,v10);\
		}

#define DUMMY_STDMETHOD_9(type, method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6, t7, v7, t8, v8, t9, v9) \
	virtual __declspec(nothrow) type __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6, t7 v7, t8 v8, t9 v9) override\
		{\
			type r = ptr->method(v1,v2,v3,v4,v5,v6,v7,v8,v9);\
			TRACEFUNC(r, v1,v2,v3,v4,v5,v6,v7,v8,v9);\
		return r;\
		}

#define DUMMY_STDMETHOD_VOID_9(method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6, t7, v7, t8, v8, t9, v9) \
	virtual __declspec(nothrow) void __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6, t7 v7, t8 v8, t9 v9) override\
		{\
			ptr->method(v1,v2,v3,v4,v5,v6,v7,v8,v9);\
			TRACE_NORETURN(v1,v2,v3,v4,v5,v6,v7,v8,v9);\
		}

#define DUMMY_STDMETHOD_8(type, method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6, t7, v7, t8, v8) \
	virtual __declspec(nothrow) type __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6, t7 v7, t8 v8) override\
		{\
			type r = ptr->method(v1,v2,v3,v4,v5,v6,v7,v8);\
			TRACEFUNC(r, v1,v2,v3,v4,v5,v6,v7,v8);\
		return r;\
		}

#define DUMMY_STDMETHOD_VOID_8(method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6, t7, v7, t8, v8) \
	virtual __declspec(nothrow) void __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6, t7 v7, t8 v8) override\
		{\
			ptr->method(v1,v2,v3,v4,v5,v6,v7,v8);\
			TRACE_NORETURN(v1,v2,v3,v4,v5,v6,v7,v8);\
		}

#define DUMMY_STDMETHOD_7(type, method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6, t7, v7) \
	virtual __declspec(nothrow) type __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6, t7 v7) override\
		{ type r = ptr->method(v1,v2,v3,v4,v5,v6,v7); TRACEFUNC(r, v1,v2,v3,v4,v5,v6,v7); return r; }

#define DUMMY_STDMETHOD_VOID_7(method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6, t7, v7) \
	virtual __declspec(nothrow) void __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6, t7 v7) override\
		{ ptr->method(v1,v2,v3,v4,v5,v6,v7); TRACE_NORETURN(v1,v2,v3,v4,v5,v6,v7); }

#define DUMMY_STDMETHOD_6(type, method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6) \
	virtual __declspec(nothrow) type __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6) override\
		{ type r = ptr->method(v1,v2,v3,v4,v5,v6); TRACEFUNC(r, v1,v2,v3,v4,v5,v6); return r; }

#define DUMMY_STDMETHOD_VOID_6(method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5, t6, v6) override\
	virtual __declspec(nothrow) void __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5, t6 v6) \
		{ ptr->method(v1,v2,v3,v4,v5,v6); TRACE_NORETURN(v1,v2,v3,v4,v5,v6); }

#define DUMMY_STDMETHOD_5(type, method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5) \
	virtual __declspec(nothrow) type __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5) override\
		{ type r = ptr->method(v1,v2,v3,v4,v5); TRACEFUNC(r, v1,v2,v3,v4,v5); return r; }

#define DUMMY_STDMETHOD_VOID_5(method, t1, v1, t2, v2, t3, v3, t4, v4, t5, v5) \
	virtual __declspec(nothrow) void __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4, t5 v5) override\
		{ ptr->method(v1,v2,v3,v4,v5); TRACE_NORETURN(v1,v2,v3,v4,v5); }

#define DUMMY_STDMETHOD_4(type, method, t1, v1, t2, v2, t3, v3, t4, v4) \
	virtual __declspec(nothrow) type __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4) override\
		{ type r = ptr->method(v1,v2,v3,v4); TRACEFUNC(r, v1,v2,v3,v4); return r; }

#define DUMMY_STDMETHOD_VOID_4(method, t1, v1, t2, v2, t3, v3, t4, v4) \
	virtual __declspec(nothrow) void __stdcall method(t1 v1, t2 v2, t3 v3, t4 v4) override\
		{ ptr->method(v1,v2,v3,v4); TRACE_NORETURN(v1,v2,v3,v4); }

#define DUMMY_STDMETHOD_3(type, method, t1, v1, t2, v2, t3, v3) \
	virtual __declspec(nothrow) type __stdcall method(t1 v1, t2 v2, t3 v3) override\
		{ type r = ptr->method(v1,v2,v3); TRACEFUNC(r,v1,v2,v3); return r; }

#define DUMMY_STDMETHOD_VOID_3(method, t1, v1, t2, v2, t3, v3) \
	virtual __declspec(nothrow) void __stdcall method(t1 v1, t2 v2, t3 v3) override\
		{ ptr->method(v1,v2,v3); TRACE_NORETURN(v1,v2,v3); }

#define DUMMY_STDMETHOD_2(type, method, t1, v1, t2, v2) \
	virtual __declspec(nothrow) type __stdcall method(t1 v1, t2 v2) override\
		{ type r = ptr->method(v1,v2); TRACEFUNC(r,v1,v2); return r; }

#define DUMMY_STDMETHOD_VOID_2(method, t1, v1, t2, v2) \
	virtual __declspec(nothrow) void __stdcall method(t1 v1, t2 v2) override\
		{ ptr->method(v1,v2); TRACE_NORETURN(v1,v2); }

#define DUMMY_STDMETHOD_1(type, method, t1, v1) \
	virtual __declspec(nothrow) type __stdcall method(t1 v1) override\
		{ type r = ptr->method(v1); TRACEFUNC(r,v1); return r; }

#define DUMMY_STDMETHOD_VOID_1(method, t1, v1) \
	virtual __declspec(nothrow) void __stdcall method(t1 v1) override\
		{ ptr->method(v1); TRACE_NORETURN(v1); }

#define DUMMY_STDMETHOD_0(type, method) \
	virtual __declspec(nothrow) type __stdcall method() override\
		{ type r = ptr->method(); TRACEFUNC(r); return r; }

#define DUMMY_STDMETHOD_VOID_0(method) \
	virtual __declspec(nothrow) void __stdcall method() override\
		{ ptr->method(); TRACE_NORETURN(); }

#pragma endregion


///////////////// DummyIDirect3D8 ////////////////////
#pragma region DummyIDirect3D8
DUMMY_DECLARE_INTERFACE_(IDirect3D8, IUnknown)
/***, IUnknown methods ***/
DUMMY_STDMETHOD_2(HRESULT, QueryInterface, REFIID, riid, void**, ppvObj);
DUMMY_STDMETHOD_0(ULONG, AddRef);
DUMMY_STDMETHOD_0(ULONG, Release);

/***, IDirect3D8 methods ***/
DUMMY_STDMETHOD_1(HRESULT, RegisterSoftwareDevice, void*, pInitializeFunction);
DUMMY_STDMETHOD_0(UINT, GetAdapterCount);
DUMMY_STDMETHOD_3(HRESULT, GetAdapterIdentifier, UINT, Adapter, DWORD, Flags, D3DADAPTER_IDENTIFIER8*, pIdentifier);
DUMMY_STDMETHOD_1(UINT, GetAdapterModeCount, UINT, Adapter);
DUMMY_STDMETHOD_3(HRESULT, EnumAdapterModes, UINT, Adapter, UINT, Mode, D3DDISPLAYMODE*, pMode);
DUMMY_STDMETHOD_2(HRESULT, GetAdapterDisplayMode, UINT, Adapter, D3DDISPLAYMODE*, pMode);
DUMMY_STDMETHOD_5(HRESULT, CheckDeviceType, UINT, Adapter, D3DDEVTYPE, CheckType, D3DFORMAT, DisplayFormat, D3DFORMAT, BackBufferFormat, BOOL, Windowed);
DUMMY_STDMETHOD_6(HRESULT, CheckDeviceFormat, UINT, Adapter, D3DDEVTYPE, DeviceType, D3DFORMAT, AdapterFormat, DWORD, Usage, D3DRESOURCETYPE, RType, D3DFORMAT, CheckFormat);
DUMMY_STDMETHOD_5(HRESULT, CheckDeviceMultiSampleType, UINT, Adapter, D3DDEVTYPE, DeviceType, D3DFORMAT, SurfaceFormat, BOOL, Windowed, D3DMULTISAMPLE_TYPE, MultiSampleType);
DUMMY_STDMETHOD_5(HRESULT, CheckDepthStencilMatch, UINT, Adapter, D3DDEVTYPE, DeviceType, D3DFORMAT, AdapterFormat, D3DFORMAT, RenderTargetFormat, D3DFORMAT, DepthStencilFormat);
DUMMY_STDMETHOD_3(HRESULT, GetDeviceCaps, UINT, Adapter, D3DDEVTYPE, DeviceType, D3DCAPS8*, pCaps);
DUMMY_STDMETHOD_1(HMONITOR, GetAdapterMonitor, UINT, Adapter);
DUMMY_STDMETHOD_6(HRESULT, CreateDevice, UINT, Adapter, D3DDEVTYPE, DeviceType, HWND, hFocusWindow, DWORD, BehaviorFlags, D3DPRESENT_PARAMETERS*, pPresentationParameters, IDirect3DDevice8**, ppReturnedDeviceInterface);
DUMMY_END_INTEFACE
#pragma endregion

///////////////// DummyIDirect3DDevice8 ////////////////////
#pragma region DummyIDirect3DDevice8
DUMMY_DECLARE_INTERFACE_(IDirect3DDevice8, IUnknown)
/***, IUnknown methods ***/
DUMMY_STDMETHOD_2(HRESULT, QueryInterface, REFIID, riid, void**, ppvObj);
DUMMY_STDMETHOD_0(ULONG, AddRef);
DUMMY_STDMETHOD_0(ULONG, Release);

/***, IDirect3DDevice8 methods ***/
DUMMY_STDMETHOD_0(HRESULT, TestCooperativeLevel);
DUMMY_STDMETHOD_0(UINT, GetAvailableTextureMem);
DUMMY_STDMETHOD_1(HRESULT, ResourceManagerDiscardBytes, DWORD, Bytes);
DUMMY_STDMETHOD_1(HRESULT, GetDirect3D, IDirect3D8**, ppD3D8);
DUMMY_STDMETHOD_1(HRESULT, GetDeviceCaps, D3DCAPS8*, pCaps);
DUMMY_STDMETHOD_1(HRESULT, GetDisplayMode, D3DDISPLAYMODE*, pMode);
DUMMY_STDMETHOD_1(HRESULT, GetCreationParameters, D3DDEVICE_CREATION_PARAMETERS*, pParameters);
DUMMY_STDMETHOD_3(HRESULT, SetCursorProperties, UINT, XHotSpot, UINT, YHotSpot, IDirect3DSurface8*, pCursorBitmap);
DUMMY_STDMETHOD_VOID_3(SetCursorPosition, UINT, XScreenSpace, UINT, YScreenSpace, DWORD, Flags);
DUMMY_STDMETHOD_1(BOOL, ShowCursor, BOOL, bShow);
DUMMY_STDMETHOD_2(HRESULT, CreateAdditionalSwapChain, D3DPRESENT_PARAMETERS*, pPresentationParameters, IDirect3DSwapChain8**, pSwapChain);
DUMMY_STDMETHOD_1(HRESULT, Reset, D3DPRESENT_PARAMETERS*, pPresentationParameters);
DUMMY_STDMETHOD_4(HRESULT, Present, CONST RECT*, pSourceRect, CONST RECT*, pDestRect, HWND, hDestWindowOverride, CONST RGNDATA*, pDirtyRegion);
DUMMY_STDMETHOD_3(HRESULT, GetBackBuffer, UINT, BackBuffer, D3DBACKBUFFER_TYPE, Type, IDirect3DSurface8**, ppBackBuffer);
DUMMY_STDMETHOD_1(HRESULT, GetRasterStatus, D3DRASTER_STATUS*, pRasterStatus);
DUMMY_STDMETHOD_VOID_2(SetGammaRamp, DWORD, Flags, CONST D3DGAMMARAMP*, pRamp);
DUMMY_STDMETHOD_VOID_1(GetGammaRamp, D3DGAMMARAMP*, pRamp);
DUMMY_STDMETHOD_7(HRESULT, CreateTexture, UINT, Width, UINT, Height, UINT, Levels, DWORD, Usage, D3DFORMAT, Format, D3DPOOL, Pool, IDirect3DTexture8**, ppTexture);
DUMMY_STDMETHOD_8(HRESULT, CreateVolumeTexture, UINT, Width, UINT, Height, UINT, Depth, UINT, Levels, DWORD, Usage, D3DFORMAT, Format, D3DPOOL, Pool, IDirect3DVolumeTexture8**, ppVolumeTexture);
DUMMY_STDMETHOD_6(HRESULT, CreateCubeTexture, UINT, EdgeLength, UINT, Levels, DWORD, Usage, D3DFORMAT, Format, D3DPOOL, Pool, IDirect3DCubeTexture8**, ppCubeTexture);
DUMMY_STDMETHOD_5(HRESULT, CreateVertexBuffer, UINT, Length, DWORD, Usage, DWORD, FVF, D3DPOOL, Pool, IDirect3DVertexBuffer8**, ppVertexBuffer);
DUMMY_STDMETHOD_5(HRESULT, CreateIndexBuffer, UINT, Length, DWORD, Usage, D3DFORMAT, Format, D3DPOOL, Pool, IDirect3DIndexBuffer8**, ppIndexBuffer);
DUMMY_STDMETHOD_6(HRESULT, CreateRenderTarget, UINT, Width, UINT, Height, D3DFORMAT, Format, D3DMULTISAMPLE_TYPE, MultiSample, BOOL, Lockable, IDirect3DSurface8**, ppSurface);
DUMMY_STDMETHOD_5(HRESULT, CreateDepthStencilSurface, UINT, Width, UINT, Height, D3DFORMAT, Format, D3DMULTISAMPLE_TYPE, MultiSample, IDirect3DSurface8**, ppSurface);
DUMMY_STDMETHOD_4(HRESULT, CreateImageSurface, UINT, Width, UINT, Height, D3DFORMAT, Format, IDirect3DSurface8**, ppSurface);
DUMMY_STDMETHOD_5(HRESULT, CopyRects, IDirect3DSurface8*, pSourceSurface, CONST RECT*, pSourceRectsArray, UINT, cRects, IDirect3DSurface8*, pDestinationSurface, CONST POINT*, pDestPointsArray);
DUMMY_STDMETHOD_2(HRESULT, UpdateTexture, IDirect3DBaseTexture8*, pSourceTexture, IDirect3DBaseTexture8*, pDestinationTexture);
DUMMY_STDMETHOD_1(HRESULT, GetFrontBuffer, IDirect3DSurface8*, pDestSurface);
DUMMY_STDMETHOD_2(HRESULT, SetRenderTarget, IDirect3DSurface8*, pRenderTarget, IDirect3DSurface8*, pNewZStencil);
DUMMY_STDMETHOD_1(HRESULT, GetRenderTarget, IDirect3DSurface8**, ppRenderTarget);
DUMMY_STDMETHOD_1(HRESULT, GetDepthStencilSurface, IDirect3DSurface8**, ppZStencilSurface);
DUMMY_STDMETHOD_0(HRESULT, BeginScene);
DUMMY_STDMETHOD_0(HRESULT, EndScene);
DUMMY_STDMETHOD_6(HRESULT, Clear, DWORD, Count, CONST D3DRECT*, pRects, DWORD, Flags, D3DCOLOR, Color, float, Z, DWORD, Stencil);
DUMMY_STDMETHOD_2(HRESULT, SetTransform, D3DTRANSFORMSTATETYPE, State, CONST D3DMATRIX*, pMatrix);
DUMMY_STDMETHOD_2(HRESULT, GetTransform, D3DTRANSFORMSTATETYPE, State, D3DMATRIX*, pMatrix);
DUMMY_STDMETHOD_2(HRESULT, MultiplyTransform, D3DTRANSFORMSTATETYPE, State, CONST D3DMATRIX*, pMatrix);
DUMMY_STDMETHOD_1(HRESULT, SetViewport, CONST D3DVIEWPORT8*, pViewport);
DUMMY_STDMETHOD_1(HRESULT, GetViewport, D3DVIEWPORT8*, pViewport);
DUMMY_STDMETHOD_1(HRESULT, SetMaterial, CONST D3DMATERIAL8*, pMaterial);
DUMMY_STDMETHOD_1(HRESULT, GetMaterial, D3DMATERIAL8*, pMaterial);
DUMMY_STDMETHOD_2(HRESULT, SetLight, DWORD, Index, CONST D3DLIGHT8*, pLight);
DUMMY_STDMETHOD_2(HRESULT, GetLight, DWORD, Index, D3DLIGHT8*, pLight);
DUMMY_STDMETHOD_2(HRESULT, LightEnable, DWORD, Index, BOOL, Enable);
DUMMY_STDMETHOD_2(HRESULT, GetLightEnable, DWORD, Index, BOOL*, pEnable);
DUMMY_STDMETHOD_2(HRESULT, SetClipPlane, DWORD, Index, CONST float*, pPlane);
DUMMY_STDMETHOD_2(HRESULT, GetClipPlane, DWORD, Index, float*, pPlane);
DUMMY_STDMETHOD_2(HRESULT, SetRenderState, D3DRENDERSTATETYPE, State, DWORD, Value);
DUMMY_STDMETHOD_2(HRESULT, GetRenderState, D3DRENDERSTATETYPE, State, DWORD*, pValue);
DUMMY_STDMETHOD_0(HRESULT, BeginStateBlock);
DUMMY_STDMETHOD_1(HRESULT, EndStateBlock, DWORD*, pToken);
DUMMY_STDMETHOD_1(HRESULT, ApplyStateBlock, DWORD, Token);
DUMMY_STDMETHOD_1(HRESULT, CaptureStateBlock, DWORD, Token);
DUMMY_STDMETHOD_1(HRESULT, DeleteStateBlock, DWORD, Token);
DUMMY_STDMETHOD_2(HRESULT, CreateStateBlock, D3DSTATEBLOCKTYPE, Type, DWORD*, pToken);
DUMMY_STDMETHOD_1(HRESULT, SetClipStatus, CONST D3DCLIPSTATUS8*, pClipStatus);
DUMMY_STDMETHOD_1(HRESULT, GetClipStatus, D3DCLIPSTATUS8*, pClipStatus);
DUMMY_STDMETHOD_2(HRESULT, GetTexture, DWORD, Stage, IDirect3DBaseTexture8**, ppTexture);
DUMMY_STDMETHOD_2(HRESULT, SetTexture, DWORD, Stage, IDirect3DBaseTexture8*, pTexture);
DUMMY_STDMETHOD_3(HRESULT, GetTextureStageState, DWORD, Stage, D3DTEXTURESTAGESTATETYPE, Type, DWORD*, pValue);
DUMMY_STDMETHOD_3(HRESULT, SetTextureStageState, DWORD, Stage, D3DTEXTURESTAGESTATETYPE, Type, DWORD, Value);
DUMMY_STDMETHOD_1(HRESULT, ValidateDevice, DWORD*, pNumPasses);
DUMMY_STDMETHOD_3(HRESULT, GetInfo, DWORD, DevInfoID, void*, pDevInfoStruct, DWORD, DevInfoStructSize);
DUMMY_STDMETHOD_2(HRESULT, SetPaletteEntries, UINT, PaletteNumber, CONST PALETTEENTRY*, pEntries);
DUMMY_STDMETHOD_2(HRESULT, GetPaletteEntries, UINT, PaletteNumber, PALETTEENTRY*, pEntries);
DUMMY_STDMETHOD_1(HRESULT, SetCurrentTexturePalette, UINT, PaletteNumber);
DUMMY_STDMETHOD_1(HRESULT, GetCurrentTexturePalette, UINT*, PaletteNumber);
DUMMY_STDMETHOD_3(HRESULT, DrawPrimitive, D3DPRIMITIVETYPE, PrimitiveType, UINT, StartVertex, UINT, PrimitiveCount);
DUMMY_STDMETHOD_5(HRESULT, DrawIndexedPrimitive, D3DPRIMITIVETYPE, Type, UINT, minIndex, UINT, NumVertices, UINT, startIndex, UINT, primCount);
DUMMY_STDMETHOD_4(HRESULT, DrawPrimitiveUP, D3DPRIMITIVETYPE, PrimitiveType, UINT, PrimitiveCount, CONST void*, pVertexStreamZeroData, UINT, VertexStreamZeroStride);
DUMMY_STDMETHOD_8(HRESULT, DrawIndexedPrimitiveUP, D3DPRIMITIVETYPE, PrimitiveType, UINT, MinVertexIndex, UINT, NumVertexIndices, UINT, PrimitiveCount, CONST void*, pIndexData, D3DFORMAT, IndexDataFormat, CONST void*, pVertexStreamZeroData, UINT, VertexStreamZeroStride);
DUMMY_STDMETHOD_5(HRESULT, ProcessVertices, UINT, SrcStartIndex, UINT, DestIndex, UINT, VertexCount, IDirect3DVertexBuffer8*, pDestBuffer, DWORD, Flags);
DUMMY_STDMETHOD_4(HRESULT, CreateVertexShader, CONST DWORD*, pDeclaration, CONST DWORD*, pFunction, DWORD*, pHandle, DWORD, Usage);
DUMMY_STDMETHOD_1(HRESULT, SetVertexShader, DWORD, Handle);
DUMMY_STDMETHOD_1(HRESULT, GetVertexShader, DWORD*, pHandle);
DUMMY_STDMETHOD_1(HRESULT, DeleteVertexShader, DWORD, Handle);
DUMMY_STDMETHOD_3(HRESULT, SetVertexShaderConstant, DWORD, Register, CONST void*, pConstantData, DWORD, ConstantCount);
DUMMY_STDMETHOD_3(HRESULT, GetVertexShaderConstant, DWORD, Register, void*, pConstantData, DWORD, ConstantCount);
DUMMY_STDMETHOD_3(HRESULT, GetVertexShaderDeclaration, DWORD, Handle, void*, pData, DWORD*, pSizeOfData);
DUMMY_STDMETHOD_3(HRESULT, GetVertexShaderFunction, DWORD, Handle, void*, pData, DWORD*, pSizeOfData);
DUMMY_STDMETHOD_3(HRESULT, SetStreamSource, UINT, StreamNumber, IDirect3DVertexBuffer8*, pStreamData, UINT, Stride);
DUMMY_STDMETHOD_3(HRESULT, GetStreamSource, UINT, StreamNumber, IDirect3DVertexBuffer8**, ppStreamData, UINT*, pStride);
DUMMY_STDMETHOD_2(HRESULT, SetIndices, IDirect3DIndexBuffer8*, pIndexData, UINT, BaseVertexIndex);
DUMMY_STDMETHOD_2(HRESULT, GetIndices, IDirect3DIndexBuffer8**, ppIndexData, UINT*, pBaseVertexIndex);
DUMMY_STDMETHOD_2(HRESULT, CreatePixelShader, CONST DWORD*, pFunction, DWORD*, pHandle);
DUMMY_STDMETHOD_1(HRESULT, SetPixelShader, DWORD, Handle);
DUMMY_STDMETHOD_1(HRESULT, GetPixelShader, DWORD*, pHandle);
DUMMY_STDMETHOD_1(HRESULT, DeletePixelShader, DWORD, Handle);
DUMMY_STDMETHOD_3(HRESULT, SetPixelShaderConstant, DWORD, Register, CONST void*, pConstantData, DWORD, ConstantCount);
DUMMY_STDMETHOD_3(HRESULT, GetPixelShaderConstant, DWORD, Register, void*, pConstantData, DWORD, ConstantCount);
DUMMY_STDMETHOD_3(HRESULT, GetPixelShaderFunction, DWORD, Handle, void*, pData, DWORD*, pSizeOfData);
DUMMY_STDMETHOD_3(HRESULT, DrawRectPatch, UINT, Handle, CONST float*, pNumSegs, CONST D3DRECTPATCH_INFO*, pRectPatchInfo);
DUMMY_STDMETHOD_3(HRESULT, DrawTriPatch, UINT, Handle, CONST float*, pNumSegs, CONST D3DTRIPATCH_INFO*, pTriPatchInfo);
DUMMY_STDMETHOD_1(HRESULT, DeletePatch, UINT, Handle);
DUMMY_END_INTEFACE
#pragma endregion

///////////////// DummyIDirect3DVertexBuffer8 ////////////////////
#pragma region DummyIDirect3DVertexBuffer8
DUMMY_DECLARE_INTERFACE_(IDirect3DVertexBuffer8, IDirect3DResource8)
/***, IUnknown methods ***/
DUMMY_STDMETHOD_2(HRESULT, QueryInterface, REFIID, riid, void**, ppvObj);
DUMMY_STDMETHOD_0(ULONG, AddRef);
DUMMY_STDMETHOD_0(ULONG, Release);

/***, IDirect3DResource8 methods ***/
DUMMY_STDMETHOD_1(HRESULT, GetDevice, IDirect3DDevice8**, ppDevice);
DUMMY_STDMETHOD_4(HRESULT, SetPrivateData, REFGUID, refguid, CONST void*, pData, DWORD, SizeOfData, DWORD, Flags);
DUMMY_STDMETHOD_3(HRESULT, GetPrivateData, REFGUID, refguid, void*, pData, DWORD*, pSizeOfData);
DUMMY_STDMETHOD_1(HRESULT, FreePrivateData, REFGUID, refguid);
DUMMY_STDMETHOD_1(DWORD, SetPriority, DWORD, PriorityNew);
DUMMY_STDMETHOD_0(DWORD, GetPriority);
DUMMY_STDMETHOD_VOID_0(PreLoad);
DUMMY_STDMETHOD_0(D3DRESOURCETYPE, GetType);
DUMMY_STDMETHOD_4(HRESULT, Lock, UINT, OffsetToLock, UINT, SizeToLock, BYTE**, ppbData, DWORD, Flags);
DUMMY_STDMETHOD_0(HRESULT, Unlock);
DUMMY_STDMETHOD_1(HRESULT, GetDesc, D3DVERTEXBUFFER_DESC*, pDesc);
DUMMY_END_INTEFACE
#pragma endregion

///////////////// DummyIDirect3DIndexBuffer8 ////////////////////
#pragma region DummyIDirect3DIndexBuffer8
DUMMY_DECLARE_INTERFACE_(IDirect3DIndexBuffer8, IDirect3DResource8)
/***, IUnknown methods ***/
DUMMY_STDMETHOD_2(HRESULT, QueryInterface, REFIID, riid, void**, ppvObj);
DUMMY_STDMETHOD_0(ULONG, AddRef);
DUMMY_STDMETHOD_0(ULONG, Release);

/***, IDirect3DResource8 methods ***/
DUMMY_STDMETHOD_1(HRESULT, GetDevice, IDirect3DDevice8**, ppDevice);
DUMMY_STDMETHOD_4(HRESULT, SetPrivateData, REFGUID, refguid, CONST void*, pData, DWORD, SizeOfData, DWORD, Flags);
DUMMY_STDMETHOD_3(HRESULT, GetPrivateData, REFGUID, refguid, void*, pData, DWORD*, pSizeOfData);
DUMMY_STDMETHOD_1(HRESULT, FreePrivateData, REFGUID, refguid);
DUMMY_STDMETHOD_1(DWORD, SetPriority, DWORD, PriorityNew);
DUMMY_STDMETHOD_0(DWORD, GetPriority);
DUMMY_STDMETHOD_VOID_0(PreLoad);
DUMMY_STDMETHOD_0(D3DRESOURCETYPE, GetType);
DUMMY_STDMETHOD_4(HRESULT, Lock, UINT, OffsetToLock, UINT, SizeToLock, BYTE**, ppbData, DWORD, Flags);
DUMMY_STDMETHOD_0(HRESULT, Unlock);
DUMMY_STDMETHOD_1(HRESULT, GetDesc, D3DINDEXBUFFER_DESC*, pDesc);
DUMMY_END_INTEFACE
#pragma endregion


///////////////// DummyIDirect3DSurface8 ////////////////////
#pragma region DummyIDirect3DSurface8
DUMMY_DECLARE_INTERFACE_(IDirect3DSurface8, IUnknown)
/***, IUnknown methods ***/
DUMMY_STDMETHOD_2(HRESULT, QueryInterface, REFIID, riid, void**, ppvObj);
DUMMY_STDMETHOD_0(ULONG, AddRef);
DUMMY_STDMETHOD_0(ULONG, Release);

/***, IDirect3DResource8 methods ***/
DUMMY_STDMETHOD_1(HRESULT, GetDevice, IDirect3DDevice8**, ppDevice);
DUMMY_STDMETHOD_4(HRESULT, SetPrivateData, REFGUID, refguid, CONST void*, pData, DWORD, SizeOfData, DWORD, Flags);
DUMMY_STDMETHOD_3(HRESULT, GetPrivateData, REFGUID, refguid, void*, pData, DWORD*, pSizeOfData);
DUMMY_STDMETHOD_1(HRESULT, FreePrivateData, REFGUID, refguid);
DUMMY_STDMETHOD_2(HRESULT, GetContainer, REFIID, riid, void**, ppContainer);
DUMMY_STDMETHOD_1(HRESULT, GetDesc, D3DSURFACE_DESC*, pDesc);
DUMMY_STDMETHOD_3(HRESULT, LockRect, D3DLOCKED_RECT*, pLockedRect, CONST RECT*, pRect, DWORD, Flags);
DUMMY_STDMETHOD_0(HRESULT, UnlockRect);
DUMMY_END_INTEFACE
#pragma endregion
