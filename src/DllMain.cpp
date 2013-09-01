#include "Globals.h"
#include "ChewingEngine.h"

static ChewingEngine* g_ChewingEngine = NULL;

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID pvReserved)
{
    switch (dwReason)
    {
        case DLL_PROCESS_ATTACH:
			g_ChewingEngine = new ChewingEngine();
			return ::InitTsfHelper(hInstance, g_ChewingEngine);
            break;

        case DLL_PROCESS_DETACH:
			::FreeTsfHelper();
			if(g_ChewingEngine) {
				delete g_ChewingEngine;
				g_ChewingEngine = NULL;
			}
            break;
    }

    return TRUE;
}

STDAPI DllCanUnloadNow(void)
{
	return TsfDllCanUnloadNow();
}

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, void **ppvObj)
{
	return TsfDllGetClassObject(rclsid, riid, ppvObj);
}

STDAPI DllUnregisterServer(void)
{
	return TsfDllUnregisterServer();
}

STDAPI DllRegisterServer(void)
{
	return TsfDllRegisterServer();
}
