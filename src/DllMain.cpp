//////////////////////////////////////////////////////////////////////
//
//  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//  ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
//  TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//  PARTICULAR PURPOSE.
//
//  Copyright (C) Microsoft Corporation.  All rights reserved.
//
//  DllMain.cpp
//
//          DllMain module entry point.
//
//////////////////////////////////////////////////////////////////////

#include "Globals.h"
#include "ImeEngine.h"

class ChewingImeEngine: public CImeEngine {
public:
	ChewingImeEngine() {
	}

	~ChewingImeEngine() {
	}
};

static ChewingImeEngine* g_ChewingEngine = NULL;

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID pvReserved)
{
    switch (dwReason)
    {
        case DLL_PROCESS_ATTACH:
			g_ChewingEngine = new ChewingImeEngine();
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
