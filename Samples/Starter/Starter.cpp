/*********************************************************************

 Copyright (C) 2010 Foxit Corporation
 All rights reserved.

 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.

 ---------------------------------------------------------------------

Starter.cpp

 - Defines the entry point for the DLL application, the entry point is PlugInMain.

 - Skeleton .cpp file for a plug-in. It implements the basic
   handshaking methods required for all plug-ins.

*********************************************************************/


#include "stdafx.h"
#include "Starter.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CStarterApp

BEGIN_MESSAGE_MAP(CStarterApp, CWinApp)
	//{{AFX_MSG_MAP(CStarterApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStarterApp construction

CStarterApp::CStarterApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CStarterApp object

CStarterApp theApp;

/** 
	Starter is a plug-in template that provides a minimal 
	implementation for a plug-in. Developers may use this plug-in a 
	basis for their plug-ins.
*/



/* PIExportHFTs
** ------------------------------------------------------
**/
/** 
** Create and Add the extension HFT's.
**
** @return true to continue loading plug-in,
** false to cause plug-in loading to stop.
*/
FS_BOOL PIExportHFTs(void)
{
	return TRUE;
}

/** 
The application calls this function to allow it to
<ul>
<li> Import HFTs supplied by other plug-ins.
<li> Replace functions in the HFTs you're using (where allowed).
<li> Register to receive notification events.
</ul>
*/
FS_BOOL PIImportReplaceAndRegister(void)
{
	return TRUE;
}

////////////////////////////////////////////////////////////////////
/* Plug-ins can use their Initialization procedures to hook into Foxit Reader's 
	 * user interface by adding menu items, toolbar buttons, windows, and so on.
	 * It is also acceptable to modify Foxit Reader's user interface later when the plug-in is running.
	 */

void PILoadRibbonUI(void* pParentWnd)
{
	//FRSysShowMessageBox((FS_LPCWSTR)L"Hello World", MB_OK | MB_ICONINFORMATION, NULL, NULL, FRAppGetMainFrameWnd());
}

void PILoadStatusBarUI(void* pParentWnd)
{
	//FRSysShowMessageBox((FS_LPCWSTR)L"PILoadStatusBarUI", MB_OK | MB_ICONINFORMATION, NULL, NULL, FRAppGetMainFrameWnd());
}

/* PIInit
** ------------------------------------------------------
**/
/** 
	The main initialization routine.
	
	@return true to continue loading the plug-in, 
	false to cause plug-in loading to stop.
*/
FS_BOOL PIInit(void)
{
	return TRUE;
}

/* PIUnload
** ------------------------------------------------------
**/
/** 
	The unload routine.
	Called when your plug-in is being unloaded when the application quits.
	Use this routine to release any system resources you may have
	allocated.

	Returning false will cause an alert to display that unloading failed.
	@return true to indicate the plug-in unloaded.
*/
FS_BOOL PIUnload(void)
{
	return TRUE;
}
void TranslateAction(void* clientData) {
	FR_Document frDocument = FRAppGetActiveDocOfPDDoc();
	FR_DocView frDocView = FRDocGetCurrentDocView(frDocument);
	FR_PageView frPageView = FRDocViewGetCurrentPageView(frDocView);

	// Store selected text
	FR_TextSelectTool textSelectTool = FRDocGetTextSelectTool(frDocument);
	FS_WideString outText = FSWideStringNew();
	FRTextSelectToolGetSelectedText(textSelectTool, &outText);
	FRSysShowMessageBox(FSWideStringCastToLPCWSTR(outText), MB_OK | MB_ICONINFORMATION, NULL, NULL, FRAppGetMainFrameWnd());
}
void TranslateMenu(void *pClientData, FR_Menu popUpMenu)
{
	int nMenuItemCount = FRMenuGetMenuItemCount(popUpMenu);

	FR_Document frDocument = FRAppGetActiveDocOfPDDoc();
	FR_DocView frDocView = FRDocGetCurrentDocView(frDocument);
	FR_PageView frPageView = FRDocViewGetCurrentPageView(frDocView);

	// Store selected text
	FR_TextSelectTool textSelectTool = FRDocGetTextSelectTool(frDocument);
	FS_WideString outText = FSWideStringNew();

	// Strip selected text and construct menu text
	FS_WideString menuText1 = FSWideStringNew3((FS_LPCWSTR)L"Translate \"", -1);
	FS_WideString menuText2;
	FRTextSelectToolGetSelectedText(textSelectTool, &outText);
	FSWideStringRemove(outText, '\r');
	FSWideStringReplace(outText, FSWideStringNew2('\n'), FSWideStringNew2(' '));
	FS_WideString outTextTrunc = FSWideStringNew();
	FSWideStringLeft(outText, sizeof(WCHAR) * 15, &outTextTrunc);
	FSWideStringConcat(menuText1, outTextTrunc);
	if (FSWideStringCompare2(outTextTrunc, outText) == 0) {
		menuText2 = FSWideStringNew2('\"');
	}
	else {
		menuText2 = FSWideStringNew3((FS_LPCWSTR)L"...\"", -1);
	}
	FSWideStringConcat(menuText1, menuText2);

	// Add menu item and set action
	FR_MenuItem menuItem = FRMenuItemNew((const char *)L"Translate", FSWideStringCastToLPCWSTR(menuText1), NULL, false, NULL);
	FRMenuAddMenuItem(popUpMenu, menuItem, nMenuItemCount);
	FRMenuItemSetExecuteProc(menuItem, &TranslateAction);
}

/** PIHandshake
	function provides the initial interface between your plug-in and the application.
	This function provides the callback functions to the application that allow it to 
	register the plug-in with the application environment.

	Required Plug-in handshaking routine:
	
	@param handshakeVersion the version this plug-in works with. 
	@param handshakeData OUT the data structure used to provide the primary entry points for the plug-in. These
	entry points are used in registering the plug-in with the application and allowing the plug-in to register for 
	other plug-in services and offer its own.
	@return true to indicate success, false otherwise (the plug-in will not load).
*/
FS_BOOL PIHandshake(FS_INT32 handshakeVersion, void *handshakeData)
{
	if(handshakeVersion != HANDSHAKE_V0100)
		return FALSE;
	
	/* Cast handshakeData to the appropriate type */
	PIHandshakeData_V0100* pData = (PIHandshakeData_V0100*)handshakeData;
	
	/* Set the name we want to go by */
	pData->PIHDRegisterPlugin(pData, "Starter", (FS_LPCWSTR)L"Starter");

	/* If you export your own HFT, do so in here */
	pData->PIHDSetExportHFTsCallback(pData, &PIExportHFTs);
		
	/*
	** If you import plug-in HFTs, replace functionality, and/or want to register for notifications before
	** the user has a chance to do anything, do so in here.
	*/
	pData->PIHDSetImportReplaceAndRegisterCallback(pData, &PIImportReplaceAndRegister);

	/* Perform your plug-in's initialization in here */
	pData->PIHDSetInitDataCallback(pData, &PIInit);

	PIInitUIProcs initUIProcs;
	INIT_CALLBACK_STRUCT(&initUIProcs, sizeof(PIInitUIProcs));
	initUIProcs.lStructSize = sizeof(PIInitUIProcs);
	initUIProcs.PILoadRibbonUI = PILoadRibbonUI;
	initUIProcs.PILoadStatusBarUI = PILoadStatusBarUI;
	pData->PIHDSetInitUICallbacks(pData, &initUIProcs);
	FRAppRegisterForContextMenuAddition("Select", &TranslateMenu, "clientData");
	/* Perform any memory freeing or state saving on "quit" in here */
	pData->PIHDSetUnloadCallback(pData, &PIUnload);

	return TRUE;
}

