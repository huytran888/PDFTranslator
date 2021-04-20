﻿/*****************************************************************************

Copyright (C) 2010 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

//----------_V1----------
//*****************************
/* ToolButton HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRToolButtonNew
 * @details Creates a toolbar button or a separator with the specified name.
 * @param[in]  name The button's name.
 * @param[in]  bSeparate A flag indicate whether a button or a separator is to be created.
 * @param[in]  pParentWnd A pointer to the parent window. It represents the <Italic>MFC CWnd*</Italic>. Sets it to NULL as default.
	* You can get the parent window through <a>FRDocGetUIParentWnd</a>.
	* If <a>TRUE</a>, the new button is a separator used to leave space between groups of related buttons.
	* If <a>FALSE</a>, the button is a normal button.
 * @return   The newly toolbar button.
 * @note 
 * @see FRToolButtonRelease
 * @see FRToolButtonSetExcuteProc
 * @see FRToolButtonSetEnableProc
 * @see FRToolButtonSetMarkedProc
 */
INTERFACE(FR_ToolButton, FRToolButtonNew, (const FS_CHAR* name,  FS_BOOL bSeparate,  void* pParentWnd))

/**
 * @brief FRToolButtonRelease
 * @details Removes a specified toolbar button and releases it. Call <a>FRToolButtonUpdateButtonStates</a>()
	* after removing a button to update the toolbar.
 * @param[in]  btn The button to release.
 * @param[in]  pParentWnd A pointer to the parent window that you must specify. It represents the <Italic>MFC CWnd*</Italic>.
	* You can get the parent window through <a>FRDocGetUIParentWnd</a>.
 * @return   void
 * @note 
 * @see FRToolButtonNew
 */
INTERFACE(void, FRToolButtonRelease, (FR_ToolButton btn,  void* pParentWnd))

/**
 * @brief FRToolButtonGetName
 * @details Gets the name of the specified button.
 * @param[in]  btn The button whose name is obtained.
 * @param[out]  outName (Filled by the method) A string buffer to receive the name.
 * @return   <a>TRUE</a> if the <param>outName</param> is filled successfully, otherwise not.
 * @note 
 * @see FRToolBarGetButtonByName
 */
INTERFACE(FS_BOOL, FRToolButtonGetName, (FR_ToolButton btn,  FS_ByteString* outName))

/**
 * @brief FRToolButtonGetLabelText
 * @details Gets the label text of specified button.
 * @param[in]  btn The button whose label is obtained.
 * @param[out]  outLableText (Filled by the method) A Unicode string buffer to receive
	* the button's label text.
 * @return   <a>TRUE</a> if the <param>outLableText</param> is filled successfully, otherwise not.
 * @note 
 * @see FRToolButtonSetLableText
 */
INTERFACE(FS_BOOL, FRToolButtonGetLabelText, (FR_ToolButton btn,  FS_WideString* outLableText))

/**
 * @brief FRToolButtonSetLabelText
 * @details Sets the label text of the specified button.
 * @param[in]  btn The button whose label text is set.
 * @param[in]  labelText A pointer to a wide string buffer. The string buffer is read-only.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @see FRToolButtonGetLabelText
 * @see FRToolButtonSetHelpText
 */
INTERFACE(FS_BOOL, FRToolButtonSetLabelText, (FR_ToolButton btn,  FS_LPCWSTR labelText))

/**
 * @brief FRToolButtonSetHelpText
 * @details Sets the help text of the specified button.
 * @param[in]  btn The button to which a tooltip is added.
 * @param[in]  helpText The text to show.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @see FRToolButtonSetLabelText
 */
INTERFACE(FS_BOOL, FRToolButtonSetHelpText, (FR_ToolButton btn,  FS_LPCWSTR helpText))

/**
 * @brief FRToolButtonSetIcon
 * @details Sets a new bitmap for a toolbar button.	The size of bitmap which to be set to a button is different between
	*			common toolbar mode and tabbed toolbar mode, with common mode, the size of bitmap is 24 * 24, but 32 * 32 with
	*			tabbed mode.
 * @param[in]  btn The button whose icon is set.
 * @param[in]  bitmap The icon to set.
 * @param[in]  flyToolbar If this button is used for fly toolbar, input the fly toolbar. Otherwise, set it to NULL.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note The bitmap to set for a toolbar button will be maintained and released by the toolbar.
	* So client can not release it.
 */
INTERFACE(FS_BOOL, FRToolButtonSetIcon, (FR_ToolButton btn,  FS_DIBitmap bitmap,  FR_ToolBar flyToolbar))

/**
 * @brief FRToolButtonIsSeparator
 * @details Tests whether a toolbar button is a separator or a normal button.
 * @param[in]  btn The button to test.
 * @return   <a>TRUE</a> if a button is a separator, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRToolButtonIsSeparator, (FR_ToolButton btn))

/**
 * @brief FRToolButtonIsVisible
 * @details Tests whether a toolbar button is visible.
 * @param[in]  btn The button to test.
 * @return   <a>TRUE</a> if a button is visible, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRToolButtonIsVisible, (FR_ToolButton btn))

/**
 * @brief FRToolButtonSetExecuteProc
 * @details Sets the user-supplied procedure to call to perform the button's intended function.
 * @param[in]  btn The button whose intended function is set.
 * @param[in]  proc The user-supplied procedure to call when <param>btn</param> is clicked.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note The user-supplied data to pass to FRExecuteProc() must be set if the callback 
	* FRExecuteProc() needs. Using FRToolButtonSetClientDate() to set it.
 * @see FRToolButtonNew
 * @see FRToolButtonSetEnableProc
 * @see FRToolButtonSetMarkedProc
 * @see FRToolButtonSetClientData
 */
INTERFACE(FS_BOOL, FRToolButtonSetExecuteProc, (FR_ToolButton btn,  FRExecuteProc proc))

/**
 * @brief FRToolButtonSetEnableProc
 * @details Sets a <a>FRBtnEnableProc</a>() associated with a button. This rountine determines whether
	* a toolbar button can be selected.
 * @param[in]  btn The button whose <a>FRBtnEnableProc</a>() is set.
 * @param[in]  proc A user-supplied procedure to call whenever Reader needs to know whether
	* a button should be enabled.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note The user-supplied data to pass to FRBtnEnableProc() must be set if the callback 
	* FRBtnEnableProc() need. Using FRToolButtonSetClientDate() to set it.
 * @see FRToolButtonNew
 * @see FRToolButtonSetExecuteProc
 * @see FRToolButtonSetMarkedProc
 * @see FRToolButtonSetClientData
 */
INTERFACE(FS_BOOL, FRToolButtonSetEnableProc, (FR_ToolButton btn,  FRComputeEnabledProc proc))

/**
 * @brief FRToolButtonSetMarkedProc
 * @details Sets a <a>FRBtnCheckProc</a>() associated with a button.
 * @param[in]  btn The button whose <a>FRBtnCheckProc</a>() is set.
 * @param[in]  proc A user-supplied procedure to call whenever Reader needs to know whether
	* the specified button should be marked.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note The user-supplied data passed to FRBtnCheckProc() must be set if the callback 
	* FRBtnCheckProc() need. Using FRToolButtonSetClientDate() to set it.
 * @see FRToolButtonNew
 * @see FRToolButtonSetExecuteProc
 * @see FRToolButtonSetEnableProc
 * @see FRToolButtonSetClientData
 */
INTERFACE(FS_BOOL, FRToolButtonSetMarkedProc, (FR_ToolButton btn,  FRComputeMarkedProc proc))

/**
 * @brief FRToolButtonSetDropDownProc
 * @details Sets a <a>FRBtnDropDownProc</a>() associated with a button.
 * @param[in]  btn The button whose <a>FRBtnDropDownProc</a>() is set.
 * @param[in]  proc A user-supplied procedure to call when user click the drop-down arrow 
	* displayed next to the button image or text.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note The user-supplied data passed to FRBtnDropDownProc() must be set if the callback 
	* FRBtnDropDownProc() need. Using FRToolButtonSetClientDate() to set it.
 * @see FRToolButtonSetClientData
 */
INTERFACE(FS_BOOL, FRToolButtonSetDropDownProc, (FR_ToolButton btn,  FRBtnDropDownProc proc))

/**
 * @brief FRToolButtonGetClientData
 * @details Gets the user-supplied data structure set to tool button using <a>FRToolButtonSetClientData</a>().
 * @param[in]  btn The button whose client-data is got.
 * @return   A pointer to a user-supplied data structure. It returns <a>NULL</a>
	* if no client data to be set.
 * @note 
 * @see FRToolButtonSetClientData
 */
INTERFACE(void*, FRToolButtonGetClientData, (FR_ToolButton btn))

/**
 * @brief FRToolButtonExecuteProc
 * @details Executes the <a>FRExecuteProc</a>() associated with button. It does nothing if 
	* <a>FRBtnEnableProc</a>() returns <a>FALSE</a>.
 * @param[in]  btn The button whose execute proc is executed.
 * @return   void
 * @note 
 * @see FRToolButtonSetExecuteProc
 */
INTERFACE(void, FRToolButtonExecuteProc, (FR_ToolButton btn))

/**
 * @brief FRToolButtonSetFlyoutToolBar
 * @details Sets the fly-out toolbar to a specified button.
 * @param[in]  btn The button to which the flyout toolbar is appended.
 * @param[in]  flyout The flyout toolbar which to be appended to the <param>btn</param>.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @see FRToolBarNewFlyout
 */
INTERFACE(FS_BOOL, FRToolButtonSetFlyoutToolBar, (FR_ToolButton btn,  FR_ToolBar flyout))

/**
 * @brief FRToolButtonGetMapId
 * @details Gets the map id of the button.
 * @param[in]  btn The input button.
 * @return   The map id of the button.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRWndProviderOnCmdMsg
 */
INTERFACE(FS_DWORD, FRToolButtonGetMapId, (FR_ToolButton btn))

/**
 * @brief FRToolButtonSetClientData
 * @details Sets the user-supplied data for each  user-supplied procedure.
 * @param[in]  btn The button whose client-data is set.
 * @param[in]  clientData A pointer to user-supplied data to pass to <a>FRExecuteProc</a>(),
	* <a>FRBtnEnableProc</a>(), <a>FRBtnCheckProc</a>(), or <a>FRBtnDropDownProc</a>(). The data type 
	* may be a class or a struct that contain each client data to pass to each user-supplied procedure.
 * @param[in]  callback It will be called when the tool button is to be destroyed.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 */
INTERFACE(FS_BOOL, FRToolButtonSetClientData, (FR_ToolButton btn,  void* clientData,  FRFreeDataProc callback))

NumOfSelector(FRToolButton)
ENDENUM

//*****************************
/* ToolBar HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRToolBarNew
 * @details Creates a new named toolbar, or <a>NULL</a> if a toolbar with the <param>name</param> exists.
 * @param[in]  name The name of the toolbar. It may not be <a>NULL</a>.
 * @param[in]  title The title of the toolbar. It may not be <a>NULL</a>.
 * @param[in]  pParentWnd A pointer to the parent window. It represents the <Italic>MFC CWnd*</Italic>. Sets it to NULL as default.
	* You can get the parent window through <a>FRDocGetUIParentWnd</a>.
 * @return   The new <a>FR_ToolBar</a> object.
 * @note 
 * @see FRToolBarRelease
 * @see FRToolButtonNew
 * @see FRToolBarCountButtons
 */
INTERFACE(FR_ToolBar, FRToolBarNew, (const FS_CHAR* name,  FS_LPCWSTR title,  void* pParentWnd))

/**
 * @brief FRToolBarNewFlyout
 * @details Creates a new named flyout toolbar, or <a>NULL</a> if a toolbar with the <param>name</param> exists. 
	* A fly-out toolbar is used to append to a toolbar's button with the drop-down style.
 * @param[in]  name The name of the flyout toolbar. It may not be <a>NULL</a>.
 * @param[in]  title The title of the flyout toolbar. It may not be <a>NULL</a>.
 * @param[in]  pParentWnd A pointer to the parent window. It represents the <Italic>MFC CWnd*</Italic>. Sets it to NULL as default.
	* You can get the parent window through <a>FRDocGetUIParentWnd</a>.
 * @return   The newly created fly-out toolbar.
 * @note 
 * @see FRToolBarRelease
 * @see FRToolButtonNew
 * @see FRToolBarCountButtons
 * @see FRToolButtonSetFlyoutToolBar
 */
INTERFACE(FR_ToolBar, FRToolBarNewFlyout, (const FS_CHAR* name,  FS_LPCWSTR title,  void* pParentWnd))

/**
 * @brief FRToolBarRelease
 * @details Removes a specified toolbar and releases it.
 * @param[in]  toolbar The toolbar to be released.
 * @param[in]  pParentWnd A pointer to the parent window that you must specify. It represents the <Italic>MFC CWnd*</Italic>.
	* You can get the parent window through <a>FRDocGetUIParentWnd</a>.
 * @return   void
 * @note 
 * @see FRToolBarNew
 */
INTERFACE(void, FRToolBarRelease, (FR_ToolBar toolbar,  void* pParentWnd))

/**
 * @brief FRToolBarGetName
 * @details Gets the toolbar's name.
 * @param[in]  toolbar The toolbar whose name is obtained.
 * @param[out]  outName (Filled by this method) The string buffer to receive the 
	* toolbar's name.
 * @return   <a>TRUE</a> if the <param>outName</param> is filled successfully, otherwise not.
 * @note 
 * @see FRAppGetToolBarByName
 */
INTERFACE(FS_BOOL, FRToolBarGetName, (FR_ToolBar toolbar,  FS_ByteString* outName))

/**
 * @brief FRToolBarCountButtons
 * @details Counts the button number of the a toolbar.
 * @param[in]  toolbar The toolbar whose button count is obtained.
 * @return   The button number of the specified toolbar.
 * @note 
 * @see FRToolBarGetButton
 */
INTERFACE(FS_INT32, FRToolBarCountButtons, (FR_ToolBar toolbar))

/**
 * @brief FRToolBarGetButton
 * @details Gets the specified button.
 * @param[in]  toolbar The toolbar whose button is obtained.
 * @param[in]  index The index of the button. The index range is 0 to (<a>FRToolBarCountButton</a>()-1).
 * @return   The specified button.
 * @note 
 * @see FRToolBarCountButtons
 * @see FRToolBarGetButtonByName
 */
INTERFACE(FR_ToolButton, FRToolBarGetButton, (FR_ToolBar toolbar,  FS_INT32 index))

/**
 * @brief FRToolBarGetTitle
 * @details Gets the title of the specified toolbar.
 * @param[in]  toolbar The toolbar whose title is obtained.
 * @param[out]  outTitle (Filled by this method) A wide string buffer to receive the toolbar's title.
 * @return   <a>TRUE</a> if the <param>outTitle</param> is filled successfully, otherwise not.
 * @note 
 * @see FRToolBarSetTitle
 */
INTERFACE(FS_BOOL, FRToolBarGetTitle, (FR_ToolBar toolbar,  FS_WideString* outTitle))

/**
 * @brief FRToolBarSetTitle
 * @details Sets the title of specified toolbar.
 * @param[in]  toolbar The toolbar whose title is set.
 * @param[in]  title The title to set.
 * @return   void
 * @note 
 * @see FRToolBarGetTitle
 */
INTERFACE(void, FRToolBarSetTitle, (FR_ToolBar toolbar,  FS_LPCWSTR title))

/**
 * @brief FRToolBarGetButtonByName
 * @details Gets the toolbar button that has the specified name.
 * @param[in]  toolbar The input toolbar.
 * @param[in]  name The name for the button to get.
 * @return   The button with the specified name, if the name is not found, the return value
	* is <a>NULL</a>.
 * @note 
 */
INTERFACE(FR_ToolButton, FRToolBarGetButtonByName, (FR_ToolBar toolbar,  const FS_CHAR* name))

/**
 * @brief FRToolBarAddButton
 * @details Adds a button to the end of the toolbar. Using <a>FRToolBarAddButton</a>()
	* to insert a button into the toolbar.
 * @param[in]  toolbar The toolbar into which a button is added.
 * @param[in]  btn The button to add to the toolbar.
 * @return   <a>TRUE</a> if success, otherwise not.
 * @note 
 * @see FRToolBarInsertButton
 * @see FRToolBarRemoveButton
 */
INTERFACE(FS_BOOL, FRToolBarAddButton, (FR_ToolBar toolbar,  FR_ToolButton btn))

/**
 * @brief FRToolBarInsertButton
 * @details Inserts a button into a toolbar.
 * @param[in]  toolbar The toolbar into which a button is inserted.
 * @param[in]  btn The button to insert into the toolbar.
 * @param[in]  iInsertAt The specified index for inserting.
 * @return   <a>TRUE</a> if success, otherwise <a>FALSE</a>.
 * @note 
 * @see FTToolBarAddButton
 * @see FRToolBarRemoveButton
 */
INTERFACE(FS_BOOL, FRToolBarInsertButton, (FR_ToolBar toolbar,  FR_ToolButton btn,  FS_INT32 iInsertAt))

/**
 * @brief FRToolBarShowToolBar
 * @details Shows a toolbar.
 * @param[in]  toolbar The toolbar to show.
 * @return   void
 * @note 
 * @see FTToolBarHideToolBar
 */
INTERFACE(void, FRToolBarShowToolBar, (FR_ToolBar toolbar))

/**
 * @brief FRToolBarHideToolBar
 * @details Hides a toolbar.
 * @param[in]  toolbar The toolbar to hide.
 * @return   void
 * @note 
 * @see FTToolBarShowToolBar
 */
INTERFACE(void, FRToolBarHideToolBar, (FR_ToolBar toolbar))

/**
 * @brief FRToolBarShowToolButton
 * @details Shows a existing toolbar button.
 * @param[in]  toolbar The toolbar whose button is showed.
 * @param[in]  btn The button to show.
 * @return   void
 * @note 
 * @see FRToolBarHideToolButton
 */
INTERFACE(void, FRToolBarShowToolButton, (FR_ToolBar toolbar,  FR_ToolButton btn))

/**
 * @brief FRToolBarHideToolButton
 * @details Hides a existing toolbar button.
 * @param[in]  toolbar The toolbar whose button is hided.
 * @param[in]  btn The button to hide.
 * @return   void
 * @note 
 * @see FRToolBarShowToolButton
 */
INTERFACE(void, FRToolBarHideToolButton, (FR_ToolBar toolbar,  FR_ToolButton btn))

/**
 * @brief FRToolBarRemoveButton
 * @details Removes the specified button from the toolbar, but does not destroy the button. Call 
	* <a>FRToolBarUpdateButtonStates</a>() after removing a button to update the toolbar.
 * @param[in]  toolbar The toolbar whose button is removed.
 * @param[in]  btn The button to remove.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @see FRToolBarUpdateButtonStates
 * @see FRToolBarAddButton
 * @see FRToolBarInsertButton
 */
INTERFACE(FS_BOOL, FRToolBarRemoveButton, (FR_ToolBar toolbar,  FR_ToolButton btn))

/**
 * @brief FRToolBarUpdateButtonStates
 * @details Updates the states of buttons when the toolbar is modified.
 * @param[in]  toolbar The input toolbar.
 * @return   void
 * @note 
 */
INTERFACE(void, FRToolBarUpdateButtonStates, (FR_ToolBar toolbar))

/**
 * @brief FRToolBarIsFlyOutToolbar
 * @details Whether the toolbar is a fly-out toolbar or not.
 * @param[in]  toolbar The input toolbar.
 * @return   <a>TRUE</a> means that the toolbar is a fly-out toolbar, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRToolBarIsFlyOutToolbar, (FR_ToolBar toolbar))

/**
 * @brief FRToolBarSetMenuTitle
 * @details Sets the menu title.
 * @param[in]  toolbar The input toolbar.
 * @param[in]  menutitle The input menu title.
 * @return   void.
 * @note 
 */
INTERFACE(void, FRToolBarSetMenuTitle, (FR_ToolBar toolbar,  FS_LPCWSTR menutitle))

/**
 * @brief FRToolBarSetDefaultToolbar
 * @details Sets the toolbar as a default toolbar that will be shown when application starts up.
 * @param[in]  toolbar The input toolbar.
 * @return   void.
 * @note 
 */
INTERFACE(void, FRToolBarSetDefaultToolbar, (FR_ToolBar toolbar))

/**
 * @brief FRToolBarHideButtonInBrowser
 * @details Hides the specified button in browser mode or not.
 * @param[in]  toolbar The input toolbar.
 * @param[in]  csName The specified button name.
 * @param[in]  bHide Sets it TRUE if you want to hide the button in browser mode, otherwise FALSE.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRToolBarHideButtonInBrowser, (FR_ToolBar toolbar,  FS_LPCSTR csName,  FS_BOOL bHide))

/**
 * @brief FRToolBarIsVisible
 * @details Checks whether the toolbar is visible or not.
 * @param[in]  toolbar The input toolbar.
 * @return   <a>TRUE</a> if the toolbar is visible, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 */
INTERFACE(FS_BOOL, FRToolBarIsVisible, (FR_ToolBar toolbar))

/**
 * @brief FRToolBarIsDisable
 * @details Checks whether the toolbar is disabled or not.
 * @param[in]  toolbar The input toolbar.
 * @return   <a>TRUE</a> if the toolbar is disabled, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 */
INTERFACE(FS_BOOL, FRToolBarIsDisable, (FR_ToolBar toolbar))

/**
 * @brief FRToolBarSetDisable
 * @details Disables the toolbar.
 * @param[in]  toolbar The input toolbar.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 */
INTERFACE(void, FRToolBarSetDisable, (FR_ToolBar toolbar))

/**
 * @brief FRToolBarDock
 * @details Docks the toolbar.
 * @param[in]  toolbar The input toolbar.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 */
INTERFACE(void, FRToolBarDock, (FR_ToolBar toolbar))

NumOfSelector(FRToolBar)
ENDENUM

//*****************************
/* MessageBar HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRMessageBarCreate
 * @details Creates a new message bar, or <a>NULL</a> if fails. Plug-in can create a message bar in the 
	* <a>FRDocOnFrameCreate</a>() callback.
 * @param[in]  bShowCloseBtn Whether to show the <Italic>"Close"</Italic> button on the message bar or not.
 * @param[in]  hFrameWnd The input parent frame window.
 * @param[]  in] eType			The icon type.
 * @return   The new <a>FR_MessageBar</a> object.
 * @note 
 */
INTERFACE(FR_MessageBar, FRMessageBarCreate, (FS_BOOL bShowCloseBtn,  HWND hFrameWnd,  FRMessageBarIconType eType))

/**
 * @brief FRMessageBarDestroy
 * @details Destroys the message bar. Plug-in can destroy a message bar in the <a>FRDocOnFrameDestroy</a>() callback.
 * @param[in]  msgBar The input message bar to be destroyed.
 * @return   void
 * @note 
 */
INTERFACE(void, FRMessageBarDestroy, (FR_MessageBar msgBar))

/**
 * @brief FRMessageBarShow
 * @details Shows the message bar or hides it.
 * @param[in]  msgBar The input message bar.
 * @param[in]  bShow Whether to show the message bar or not.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRMessageBarShow, (FR_MessageBar msgBar,  FS_BOOL bShow))

/**
 * @brief FRMessageBarIsVisible
 * @details Checks whether the message bar is visible or not.
 * @param[in]  msgBar The input message bar.
 * @return   <a>TRUE</a> means the message bar is visible, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRMessageBarIsVisible, (FR_MessageBar msgBar))

/**
 * @brief FRMessageBarSetText
 * @details Sets text to the message bar.
 * @param[in]  msgBar The input message bar.
 * @param[in]  wsText The input text to be set to the message bar.
 * @param[in]  textAlignment The input text alignment type.
 * @return   void
 * @note 
 */
INTERFACE(void, FRMessageBarSetText, (FR_MessageBar msgBar,  FS_WideString wsText,  FRMessageBarElementAlignment textAlignment))

/**
 * @brief FRMessageBarSetBitmap
 * @details Sets bitmap to the message bar.
 * @param[in]  msgBar The input message bar.
 * @param[in]  bitmap The input bitmap to be set to the message bar.
 * @param[in]  bStretch Whether to stretch the bitmap or not.
 * @param[in]  bmpAlignment The input bitmap alignment type.
 * @return   void
 * @note 
 */
INTERFACE(void, FRMessageBarSetBitmap, (FR_MessageBar msgBar,  FS_DIBitmap bitmap,  FS_BOOL bStretch,  FRMessageBarElementAlignment bmpAlignment))

/**
 * @brief FRMessageBarAddButton
 * @details Adds a new button to the message bar.
 * @param[in]  msgBar The input message bar.
 * @param[in]  lpsName The input name of the button.
 * @param[in]  lpwsText The input text displayed on the button.
 * @param[in]  btnBitmap The input bitmap showed on the button.
 * @param[in]  bHasDropDownArrow Whether the button has the dropped down arrow or not.
 * @param[in]  bNeedLayout Whether the button need to be laid out.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRMessageBarAddButton, (FR_MessageBar msgBar,  FS_LPCSTR lpsName,  FS_LPCWSTR lpwsText,  FS_DIBitmap btnBitmap,  FS_BOOL bHasDropDownArrow,  FS_BOOL bNeedLayout))

/**
 * @brief FRMessageBarSetButtonAlignment
 * @details Sets the alignment type of the buttons.
 * @param[in]  msgBar The input message bar.
 * @param[in]  bmpAlignment The input alignment type.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRMessageBarSetButtonAlignment, (FR_MessageBar msgBar,  FRMessageBarElementAlignment bmpAlignment))

/**
 * @brief FRMessageBarSetButtonDropDownProc
 * @details Sets the drop-down callback function.
 * @param[in]  msgBar The input message bar.
 * @param[in]  lpsName Specifies the button name.
 * @param[in]  proc The input drop-down callback function.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRMessageBarSetButtonDropDownProc, (FR_MessageBar msgBar,  FS_LPCSTR lpsName,  FRBtnDropDownProc proc))

/**
 * @brief FRMessageBarSetButtonExecuteProc
 * @details Sets the user-supplied procedure to call to perform the button's intended function.
 * @param[in]  msgBar The input message bar.
 * @param[in]  lpsName The button you want to set.
 * @param[in]  proc The user-supplied procedure to call when the button on the message bar is clicked.
 * @return   <a>TRUE</a> means success, otherwise failure.
 * @note The user-supplied data to pass to FRExecuteProc() must be set if the callback 
	* FRExecuteProc() needs. Using FRMessageBarSetClientData() to set it.
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRMessageBarSetButtonExecuteProc, (FR_MessageBar msgBar,  FS_LPCSTR lpsName,  FRExecuteProc proc))

/**
 * @brief FRMessageBarSetButtonHelpText
 * @details Sets the help text to the message bar.
 * @param[in]  msgBar The input message bar.
 * @param[in]  lpsName The button you want to set.
 * @param[in]  wsHelpText The input help text to be set to the message bar.
 * @return   <a>TRUE</a> means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRMessageBarSetButtonHelpText, (FR_MessageBar msgBar,  FS_LPCSTR lpsName,  FS_WideString wsHelpText))

/**
 * @brief FRMessageBarEnableButton
 * @details If the <param>bEnable</param> is <a>TRUE</a>, the button is enabled. Otherwise not.
 * @param[in]  msgBar The input message bar.
 * @param[in]  lpsName The button you want to set.
 * @param[in]  bEnable Whether the button is enable or not.
 * @return   <a>TRUE</a> means success, otherwise failure.
 * @note Using FRMessageBarIsButtonEnable() to get it.
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRMessageBarEnableButton, (FR_MessageBar msgBar,  FS_LPCSTR lpsName,  FS_BOOL bEnable))

/**
 * @brief FRMessageBarSetButtonPressed
 * @details Sets the pressed type to the button.
 * @param[in]  msgBar The input message bar.
 * @param[in]  lpsName The button you want to set.
 * @param[in]  bPressed Whether the button has the pressed type.
 * @return   <a>TRUE</a> means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRMessageBarSetButtonPressed, (FR_MessageBar msgBar,  FS_LPCSTR lpsName,  FS_BOOL bPressed))

/**
 * @brief FRMessageBarSetClientData
 * @details Sets the user-supplied data for each  user-supplied procedure.
 * @param[in]  msgBar The input message bar.
 * @param[in]  lpsName The button you want to set.
 * @param[in]  clientData A pointer to user-supplied data to pass to <a>FRExecuteProc</a>(),
	* The data type may be a class or a struct that contain each client data to pass to each user-supplied procedure.
 * @return   <a>TRUE</a> means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRMessageBarSetClientData, (FR_MessageBar msgBar,  FS_LPCSTR lpsName,  void* clientData))

/**
 * @brief FRMessageBarAddButtonImage
 * @details Adds a bitmap to the button image list.
 * @param[in]  msgBar The input message bar.
 * @param[in]  pBtnBitmap Adds a bitmap to the button image list.
 * @return   The bitmap index in the button image list.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_INT32, FRMessageBarAddButtonImage, (FR_MessageBar msgBar,  FS_DIBitmap pBtnBitmap))

/**
 * @brief FRMessageBarGetButtonImage
 * @details Gets the image index.
 * @param[in]  msgBar The input message bar.
 * @param[in]  lpsName The input specified button name.
 * @return   The bitmap index in the button image list.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_INT32, FRMessageBarGetButtonImage, (FR_MessageBar msgBar,  FS_LPCSTR lpsName))

/**
 * @brief FRMessageBarChangeButton
 * @details Changes the button information.
 * @param[in]  msgBar The input message bar.
 * @param[in]  lpsName The input specified button name.
 * @param[in]  lpwsText The text you want to change to.
 * @param[in]  nImageIndex The image index you want to change to.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRMessageBarChangeButton, (FR_MessageBar msgBar,  FS_LPCSTR lpsName,  FS_LPCWSTR lpwsText,  FS_INT32 nImageIndex))

/**
 * @brief FRMessageBarIsButtonEnable
 * @details Whether the button is enable or not.
 * @param[in]  msgBar The input message bar.
 * @param[in]  lpsName The input specified button name.
 * @return   <a>TRUE</a> means button is enable , otherwise not.
 * @note Using FRMessageBarEnableButon() to set it.
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRMessageBarIsButtonEnable, (FR_MessageBar msgBar,  FS_LPCSTR lpsName))

/**
 * @brief FRMessageBarCountVisibleMessageBars
 * @details Gets the count of visible message bars.
 * @return   The count of visible message bars.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 */
INTERFACE(FS_INT32, FRMessageBarCountVisibleMessageBars, ())

/**
 * @brief FRMessageBarGetVisibleMessageBar
 * @details Gets the specified visible message bar by index.
 * @param[in]  nIndex Specifies the index of the visible message bars.
 * @return   The specified visible message bar.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 */
INTERFACE(FR_MessageBar, FRMessageBarGetVisibleMessageBar, (FS_INT32 nIndex))

/**
 * @brief FRMessageBarSetBitmap2
 * @details Sets bitmap to the message bar.
 * @param[in]  msgBar The input message bar.
 * @param[in]  bitmap The input bitmap to be set to the message bar.
 * @param[in]  bStretch Whether to stretch the bitmap or not.
 * @param[in]  bmpAlignment The input bitmap alignment type.
 * @param[in]  bNeedLayout Whether to lay out the message bar when setting bitmap.
 * @param[in]  cx The width of the bitmap when the DPI is 100%. The default value is -1.
 * @param[in]  cy The height of the bitmap when the DPI is 100%. The default value is -1.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 */
INTERFACE(void, FRMessageBarSetBitmap2, (FR_MessageBar msgBar,  FS_DIBitmap bitmap,  FS_BOOL bStretch,  FRMessageBarElementAlignment bmpAlignment,  FS_BOOL bNeedLayout,  FS_INT32 cx,  FS_INT32 cy))

/**
 * @brief FRMessageBarAddButton2
 * @details Adds a new button to the message bar.
 * @param[in]  msgBar The input message bar.
 * @param[in]  lpsName The input name of the button.
 * @param[in]  lpwsText The input text displayed on the button.
 * @param[in]  btnBitmap The input bitmap showed on the button.
 * @param[in]  bHasDropDownArrow Whether the button has the dropped down arrow or not.
 * @param[in]  bNeedLayout Whether the button need to be laid out.
 * @param[in]  cx The width of the bitmap when the DPI is 100%. The default value is -1.
 * @param[in]  cy The height of the bitmap when the DPI is 100%. The default value is -1.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 */
INTERFACE(void, FRMessageBarAddButton2, (FR_MessageBar msgBar,  FS_LPCSTR lpsName,  FS_LPCWSTR lpwsText,  FS_DIBitmap btnBitmap,  FS_BOOL bHasDropDownArrow,  FS_BOOL bNeedLayout,  FS_INT32 cx,  FS_INT32 cy))

/**
 * @brief FRMessageBarAddButtonImage2
 * @details Adds a bitmap to the button image list.
 * @param[in]  msgBar The input message bar.
 * @param[in]  pBtnBitmap Adds a bitmap to the button image list.
 * @param[in]  cx The width of the bitmap when the DPI is 100%. The default value is -1.
 * @param[in]  cy The height of the bitmap when the DPI is 100%. The default value is -1.
 * @return   The bitmap index in the button image list.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 */
INTERFACE(FS_INT32, FRMessageBarAddButtonImage2, (FR_MessageBar msgBar,  FS_DIBitmap pBtnBitmap,  FS_INT32 cx,  FS_INT32 cy))

NumOfSelector(FRMessageBar)
ENDENUM

//----------_V2----------
//----------_V3----------
//----------_V4----------
//*****************************
/* TabBand HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRTabBandGet
 * @details Gets the tab band. The tab band is used to place and manage the document tabs. A tab is associated with a window.
 * @return   The tab band.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FR_TabBand, FRTabBandGet, ())

/**
 * @brief FRTabBandGetTabWnd
 * @details Gets the window handle associated with the tab.
 * @param[in]  tabBand The input tab band.
 * @param[in]  iTab The specified index.
 * @return   The window handle associated with the tab.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRTabBandGetActiveTabWnd
 */
INTERFACE(HWND, FRTabBandGetTabWnd, (FR_TabBand tabBand,  FS_INT32 iTab))

/**
 * @brief FRTabBandGetActiveTabWnd
 * @details Gets the window handle associated with the active tab.
 * @param[in]  tabBand The input tab band.
 * @return   The window handle associated with the active tab.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(HWND, FRTabBandGetActiveTabWnd, (FR_TabBand tabBand))

/**
 * @brief FRTabBandGetTabsNum
 * @details Gets the numbers of the tabs.
 * @param[in]  tabBand The input tab band.
 * @return   The numbers of the tabs.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRTabBandGetTabsNum, (FR_TabBand tabBand))

/**
 * @brief FRTabBandCloseTabWnd
 * @details Closes the specified tab window.
 * @param[in]  tabBand The input tab band.
 * @param[in]  hTabWnd The specified window handle.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRTabBandCloseTabWnd, (FR_TabBand tabBand,  HWND hTabWnd))

/**
 * @brief FRTabBandGetActiveTab
 * @details Gets the index of the active tab window.
 * @param[in]  tabBand The input tab band.
 * @return   The index of the active tab window.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRTabBandGetActiveTab, (FR_TabBand tabBand))

/**
 * @brief FRTabBandSetActiveTab
 * @details Sets the active tab window.
 * @param[in]  tabBand The input tab band.
 * @param[in]  hTabWnd The specified tab window.
 * @return   <a>TRUE</a> if success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRTabBandGetActiveTab
 */
INTERFACE(FS_BOOL, FRTabBandSetActiveTab, (FR_TabBand tabBand,  HWND hTabWnd))

/**
 * @brief FRTabBandRegisterAddBtnHandler
 * @details Registers the callbacks for adding button to the tab band.
 * @param[in]  callbacks The input callbacks for adding button to the tab band.
 * @return   <a>TRUE</a> if success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(FS_BOOL, FRTabBandRegisterAddBtnHandler, (FR_TabBandAddBtnCallbacks callbacks))

/**
 * @brief FRTabBandSetTabTitle
 * @details Sets the specified tab title.
 * @param[in]  hChildHwnd The input child frame window associated with the tab.
 * @param[in]  lpwsTitle The input title.
 * @return   <a>TRUE</a> if success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
 */
INTERFACE(FS_BOOL, FRTabBandSetTabTitle, (HWND hChildHwnd,  FS_LPCWSTR lpwsTitle))

/**
 * @brief FRTabBandSetTabIcon
 * @details Sets the specified tab icon.
 * @param[in]  hChildFrame The input child frame window associated with the tab.
 * @param[in]  hIcon The input icon set to the tab.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
 */
INTERFACE(void, FRTabBandSetTabIcon, (HWND hChildFrame,  HICON hIcon))

/**
 * @brief FRTabBandGet2
 * @details Gets the tab band. The tab band is used to place and manage the document tabs. A tab is associated with a window.
 * @param[in]  hParent The input mainframe window associated with the tab.
 * @return   The tab band.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FR_TabBand, FRTabBandGet2, (HWND hParent))

NumOfSelector(FRTabBand)
ENDENUM

//----------_V5----------
//*****************************
/* RibbonBar HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRRibbonBarAddCategory
 * @details Adds a new category to the ribbon bar. A category object can be used to manage the operation categories.
	* For example, all the commenting tools are included in the COMMENT category.
 * @param[in]  ribbonBar The input ribbon bar.
 * @param[in]  name The input name of the category.
 * @param[in]  lpwsTitle The input title of the category.
 * @return   The category added to the ribbon bar.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppGetRibbonBar
 */
INTERFACE(FR_RibbonCategory, FRRibbonBarAddCategory, (FR_RibbonBar ribbonBar,  const FS_CHAR* name,  FS_LPCWSTR lpwsTitle))

/**
 * @brief FRRibbonBarAddRibbonContextCategory
 * @details Adds a new context category to the ribbon bar.
 * @param[in]  ribbonBar The input ribbon bar.
 * @param[in]  uiContextID The context category ID.
 * @param[in]  categoryName The name of the category.
 * @param[in]  lpwsCategoryTitle The title of the category.
 * @param[in]  lpwsContextTitle The title of the context category.
 * @param[in]  lpwsShorcutKey The shortcut key of the context category.
 * @return   The context category added to the ribbon bar.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRRibbonBarAddCategory
 * @see FRRibbonBarActivateContextCategory
 */
INTERFACE(FR_RibbonCategory, FRRibbonBarAddRibbonContextCategory, (FR_RibbonBar ribbonBar,  unsigned int uiContextID,  const FS_CHAR* categoryName,  FS_LPCWSTR lpwsCategoryTitle,  FS_LPCWSTR lpwsContextTitle,  FS_LPCWSTR lpwsShorcutKey))

/**
 * @brief FRRibbonBarActivateContextCategory
 * @details Activates the specified context category.
 * @param[in]  ribbonBar The input ribbon bar.
 * @param[in]  uiContextID The specified ID of context category.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRRibbonBarShowContextCategories
 */
INTERFACE(FS_BOOL, FRRibbonBarActivateContextCategory, (FR_RibbonBar ribbonBar,  unsigned int uiContextID))

/**
 * @brief FRRibbonBarShowContextCategories
 * @details Shows or hides the specified context category.
 * @param[in]  ribbonBar The input ribbon bar.
 * @param[in]  uiContextID The specified ID of context category.
 * @param[in]  bShow Whether to show or hide the context category.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRRibbonBarAddCategory
 */
INTERFACE(void, FRRibbonBarShowContextCategories, (FR_RibbonBar ribbonBar,  unsigned int uiContextID,  FS_BOOL bShow))

/**
 * @brief FRRibbonBarGetCategoryCount
 * @details Gets the count of categories.
 * @param[in]  ribbonBar The input ribbon bar.
 * @return   The count of categories.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonBarGetCategoryCount, (FR_RibbonBar ribbonBar))

/**
 * @brief FRRibbonBarGetCategoryByIndex
 * @details Gets the specified ribbon category object.
 * @param[in]  ribbonBar The input ribbon bar.
 * @param[in]  nIndex The specified index.
 * @return   The specified ribbon category object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_RibbonCategory, FRRibbonBarGetCategoryByIndex, (FR_RibbonBar ribbonBar,  FS_INT32 nIndex))

/**
 * @brief FRRibbonBarGetCategoryByName
 * @details Gets the specified ribbon category object.
 * @param[in]  ribbonBar The input ribbon bar.
 * @param[in]  categoryName The specified name of the the category.
 * @return   The specified ribbon category object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_RibbonCategory, FRRibbonBarGetCategoryByName, (FR_RibbonBar ribbonBar,  const FS_CHAR* categoryName))

/**
 * @brief FRRibbonBarAddAsQAT
 * @details Adds the specified ribbon button to the quick access toolbar. The quick access toolbar is located at the left-top corner.
 * @param[in]  ribbonBar The input ribbon bar.
 * @param[in]  uiBtnID The specified ID of ribbon button.
 * @param[in]  bVisible Whether the ribbon button on the quick access toolbar is visible or not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonBarAddAsQAT, (FR_RibbonBar ribbonBar,  unsigned int uiBtnID,  BOOL bVisible))

/**
 * @brief FRRibbonBarAddToTabs
 * @details Adds a new ribbon button. The ribbon button will be added to the right-top corner of the ribbon bar.
 * @param[in]  ribbonBar The input ribbon bar.
 * @param[in]  nElementType The input type of the ribbon button.
 * @param[in]  name The input name of the ribbon button.
 * @param[in]  lpwsTitle The input title of the ribbon button.
 * @param[in]  nPos The input position of the ribbon button.
 * @return   A new ribbon button.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void*, FRRibbonBarAddToTabs, (FR_RibbonBar ribbonBar,  FR_Ribbon_Element_Type nElementType,  const FS_CHAR* name,  FS_LPCWSTR lpwsTitle,  FS_INT32 nPos))

/**
 * @brief FRRibbonBarAddHidden
 * @details Adds a hidden ribbon button. It can be added to QAT by <a>FRRibbonBarAddAsQAT</a>.
 * @param[in]  ribbonBar The input ribbon bar.
 * @param[in]  name The input name of the ribbon button.
 * @param[in]  lpwsTitle The input title of the ribbon button.
 * @return   The new ribbon button.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_RibbonButton, FRRibbonBarAddHidden, (FR_RibbonBar ribbonBar,  const FS_CHAR* name,  FS_LPCWSTR lpwsTitle))

/**
 * @brief FRRibbonBarAddBackStageViewItem
 * @details Adds a new back stage view item under FILE category. The back stage view item is associated with a view.
	* You can add your own dialog or property sheet page on the view.
 * @param[in]  ribbonBar The input ribbon bar.
 * @param[in]  name The input name of the back stage view item.
 * @param[in]  lpwsTitle The input title of the back stage view item.
 * @param[in]  nPos The input position of the back stage view item.
 * @return   The new back stage view item object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRRibbonBackStageViewItemAddDialog
 * @see FRRibbonBackStageViewItemAddPropertySheetPage
 */
INTERFACE(FR_RibbonBackStageViewItem, FRRibbonBarAddBackStageViewItem, (FR_RibbonBar ribbonBar,  const FS_CHAR* name,  FS_LPCWSTR lpwsTitle,  FS_INT32 nPos))

/**
 * @brief FRRibbonBarGetBackStageViewItem
 * @details Gets the specified back stage view item object.
 * @param[in]  ribbonBar The input ribbon bar.
 * @param[in]  name The specified name of back stage view item.
 * @return   The specified back stage view item object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRRibbonBarAddBackStageViewItem
 */
INTERFACE(FR_RibbonBackStageViewItem, FRRibbonBarGetBackStageViewItem, (FR_RibbonBar ribbonBar,  const FS_CHAR* name))

/**
 * @brief FRRibbonBarSelectBackStageViewItem
 * @details Selects the specified back stage view item object.
 * @param[in]  ribbonBar The input ribbon bar.
 * @param[in]  name The specified name of back stage view item.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRRibbonBarAddBackStageViewItem
 * @see FRRibbonBarGetBackStageViewItem
 * @see FRRibbonBarIsBackStageViewActive
 */
INTERFACE(void, FRRibbonBarSelectBackStageViewItem, (FR_RibbonBar ribbonBar,  const FS_CHAR* name))

/**
 * @brief FRRibbonBarAddButtonToAddPlace
 * @details There are two back stage view items under FILE category, <Italic>Open</Italic> and <Italic>Save As</Italic>. You can add a
	* place under these two back stage view items. So the user can open file from other places such as the file server.
 * @param[in]  ribbonBar The input ribbon bar.
 * @param[in]  name The name of the button.
 * @param[in]  lpwsTitle The title of the button.
 * @param[in]  proc This callback will be called when the user clicks the button.
 * @param[in]  pImage The input bitmap of the button
 * @param[in]  bToSaveAsItem Whether the button need to be added to <Italic>Save As</Italic> item under FILE category.
 * @param[in]  pClientData The user-supplied data.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonBarAddButtonToAddPlace, (FR_RibbonBar ribbonBar,  const FS_CHAR* name,  FS_LPCWSTR lpwsTitle,  FRExecuteProc proc,  FS_DIBitmap pImage,  FS_BOOL bToSaveAsItem,  void* pClientData))

/**
 * @brief FRRibbonBarCloseFilePage
 * @details Closes the page that is shown by clicking the FILE category.
 * @param[in]  ribbonBar The input ribbon bar.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonBarCloseFilePage, (FR_RibbonBar ribbonBar))

/**
 * @brief FRRibbonBarFindElementByName
 * @details Gets the specified element.
 * @param[in]  ribbonBar The input ribbon bar.
 * @param[in]  categoryName The specified name of the category.
 * @param[in]  panelName The specified name of the panel.
 * @param[in]  btnName The specified name of the element.
 * @return   The specified element.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_RibbonElement, FRRibbonBarFindElementByName, (FR_RibbonBar ribbonBar,  const FS_CHAR* categoryName,  const FS_CHAR* panelName,  const FS_CHAR* btnName))

/**
 * @brief FRRibbonBarIsBackStageViewActive
 * @details Checks whether the back view is active or not.
 * @param[in]  ribbonBar The input ribbon bar.
 * @return   <a>TRUE</a> if the back view is active, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRRibbonBarSelectBackStageViewItem
 */
INTERFACE(FS_BOOL, FRRibbonBarIsBackStageViewActive, (FR_RibbonBar ribbonBar))

/**
 * @brief FRRibbonBarRecalcLayout
 * @details Whether to recalc the layout of the panels or not.
 * @param[in]  ribbonBar The input ribbon bar.
 * @param[in]  bRecalcPanels Whether to recalc the layout of the panels.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonBarRecalcLayout, (FR_RibbonBar ribbonBar,  FS_BOOL bRecalcPanels))

/**
 * @brief FRRibbonBarGetActiveCategory
 * @details Gets the active category object.
 * @param[in]  ribbonBar The input ribbon bar.
 * @return   The active category object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRRibbonBarAddCategory
 * @see FRRibbonBarSetActiveCategory
 */
INTERFACE(FR_RibbonCategory, FRRibbonBarGetActiveCategory, (FR_RibbonBar ribbonBar))

/**
 * @brief FRRibbonBarSetActiveCategory
 * @details Sets the active category.
 * @param[in]  ribbonBar The input ribbon bar.
 * @param[in]  categoryName The specified name of the category.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRRibbonBarAddCategory
 * @see FRRibbonBarGetActiveCategory
 * @see FRRibbonBarSetActiveCategory2
 */
INTERFACE(FS_BOOL, FRRibbonBarSetActiveCategory, (FR_RibbonBar ribbonBar,  const FS_CHAR* categoryName))

/**
 * @brief FRRibbonBarSetActiveCategory2
 * @details Sets the active category.
 * @param[in]  ribbonBar The input ribbon bar.
 * @param[in]  ribbonCategory The specified category object.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRRibbonBarSetActiveCategory
 */
INTERFACE(FS_BOOL, FRRibbonBarSetActiveCategory2, (FR_RibbonBar ribbonBar,  FR_RibbonCategory ribbonCategory))

/**
 * @brief FRRibbonBarIsMinimize
 * @details Checks whether the ribbon bar is minimized or not.
 * @param[in]  ribbonBar The input ribbon bar.
 * @return   <a>TRUE</a> means the ribbon bar is minimized, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonBarIsMinimize, (FR_RibbonBar ribbonBar))

/**
 * @brief FRRibbonBarAddCaptionButton
 * @details Adds a ribbon button to the caption bar on the right.
 * @param[in]  ribbonBar The input ribbon bar.
 * @param[in]  name The input name of the button.
 * @param[in]  lpwsTitle The input title of the button.
 * @param[in]  nIndex The input position of the button. Sets it -1 as default.
 * @return   The ribbon button added to the caption bar on the right.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(FR_RibbonButton, FRRibbonBarAddCaptionButton, (FR_RibbonBar ribbonBar,  const FS_CHAR* name,  FS_LPCWSTR lpwsTitle,  FS_INT32 nIndex))

/**
 * @brief FRRibbonBarRegisterFilePageEventHandler
 * @details Registers a callbacks set for ribbon file page event handler.
 * @param[in]  callbacks The input callbacks for ribbon file page event handler.
 * @return   The pointer to ribbon file page event handler can be destroyed by <a>FRRibbonBarDestroyFilePageEventHandler</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see FRRibbonBarDestroyFilePageEventHandler
 */
INTERFACE(void*, FRRibbonBarRegisterFilePageEventHandler, (FR_RibbonFilePageEventCallbacks callbacks))

/**
 * @brief FRRibbonBarDestroyFilePageEventHandler
 * @details Destroys the ribbon file page event handler returned by <a>FRRibbonBarRegisterFilePageEventHandler</a>.
 * @param[in]  eventHandler The pointer to ribbon file page event handler returned by <a>FRRibbonBarRegisterFilePageEventHandler</a>.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see FRRibbonBarRegisterFilePageEventHandler
 */
INTERFACE(void, FRRibbonBarDestroyFilePageEventHandler, (void* eventHandler))

/**
 * @brief FRRibbonBarAddCategory2
 * @details Adds a new category to the ribbon bar. A category object can be used to manage the operation categories.
	* For example, all the commenting tools are included in the COMMENT category.
 * @param[in]  ribbonBar The input ribbon bar.
 * @param[in]  name The input name of the category.
 * @param[in]  lpwsTitle The input title of the category.
 * @param[in]  nPos The position of the category in the ribbon bar.
 * @return   The category added to the ribbon bar.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRAppGetRibbonBar
 */
INTERFACE(FR_RibbonCategory, FRRibbonBarAddCategory2, (FR_RibbonBar ribbonBar,  const FS_CHAR* name,  FS_LPCWSTR lpwsTitle,  FS_INT32 nPos))

/**
 * @brief FRRibbonBarShowButtonInAddPlace
 * @details There are two back stage view items under FILE category, <Italic>Open</Italic> and <Italic>Save As</Italic>. You can add a
	* place under these two back stage view items. So the user can open file from other places such as the file server. You can show or hide
	* the buttons in the Add-a-Place.
 * @param[in]  ribbonBar The input ribbon bar.
 * @param[in]  name The name of the button.
 * @param[in]  bShow T	Whether to show the button or not.
 * @param[in]  bToSaveAsItem Whether the button is under <Italic>Save As</Italic> item under FILE category.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 * @see FRRibbonBarAddButtonToAddPlace
 */
INTERFACE(FS_BOOL, FRRibbonBarShowButtonInAddPlace, (FR_RibbonBar ribbonBar,  const FS_CHAR* name,  FS_BOOL bShow,  FS_BOOL bToSaveAsItem))

/**
 * @brief FRRibbonBarUpdateCmdUI
 * @details Updates the UI state of ribbon button.
 * @param[in]  ribbonBar The input ribbon bar.
 * @param[in]  name The name of the button.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 */
INTERFACE(void, FRRibbonBarUpdateCmdUI, (FR_RibbonBar ribbonBar,  const FS_CHAR* name))

NumOfSelector(FRRibbonBar)
ENDENUM

//*****************************
/* RibbonCategory HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRRibbonCategorySetTitle
 * @details Sets the title of the ribbon category.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @param[in]  lpwsTitle The input title of the ribbon category.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRRibbonBarAddCategory
 */
INTERFACE(void, FRRibbonCategorySetTitle, (FR_RibbonCategory ribbonCategory,  FS_LPCWSTR lpwsTitle))

/**
 * @brief FRRibbonCategoryGetTitle
 * @details Gets the title of the ribbon category.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @param[out]  wsTitle It receives the title of the ribbon category.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonCategoryGetTitle, (FR_RibbonCategory ribbonCategory,  FS_WideString* wsTitle))

/**
 * @brief FRRibbonCategorySetContextTitle
 * @details Sets the title of the ribbon context category.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @param[in]  lpwsTitle The input title of the ribbon context category.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonCategorySetContextTitle, (FR_RibbonCategory ribbonCategory,  FS_LPCWSTR lpwsTitle))

/**
 * @brief FRRibbonCategoryGetContextTitle
 * @details Gets the title of the ribbon context category.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @param[out]  wsTitle It receives the title of the ribbon context category.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonCategoryGetContextTitle, (FR_RibbonCategory ribbonCategory,  FS_WideString* wsTitle))

/**
 * @brief FRRibbonCategorySetKey
 * @details Sets the shortcut key of the ribbon category.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @param[in]  lpwsShorcutKey The input shortcut key of the ribbon category.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonCategorySetKey, (FR_RibbonCategory ribbonCategory,  FS_LPCWSTR lpwsShorcutKey))

/**
 * @brief FRRibbonCategoryGetKey
 * @details Gets the shortcut key of the ribbon category.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @param[out]  wsKey It receives the shortcut key of the ribbon category.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonCategoryGetKey, (FR_RibbonCategory ribbonCategory,  FS_WideString* wsKey))

/**
 * @brief FRRibbonCategorySetVisible
 * @details Sets the ribbon category to visible or invisible.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @param[in]  bVisible <a>TRUE</a> if the ribbon category is visible, otherwise is invisible.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonCategorySetVisible, (FR_RibbonCategory ribbonCategory,  FS_BOOL bVisible))

/**
 * @brief FRRibbonCategoryGetVisible
 * @details Checks whether the ribbon category is visible or not.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @return   <a>TRUE</a> if the ribbon category is visible, otherwise invisible.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonCategoryGetVisible, (FR_RibbonCategory ribbonCategory))

/**
 * @brief FRRibbonCategoryAddPanel
 * @details Adds a new ribbon panel to the ribbon category. A ribbon category may contain several ribbon panels.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @param[in]  name The input name of the ribbon panel.
 * @param[in]  lpwsTitle The input title of the ribbon panel.
 * @param[in]  defBtnBitmap The default icon of the ribbon panel.
 * @return   The new ribbon panel added to the ribbon category.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRRibbonCategoryGetPanelCount
 * @see FRRibbonCategoryGetPanelByIndex
 */
INTERFACE(FR_RibbonPanel, FRRibbonCategoryAddPanel, (FR_RibbonCategory ribbonCategory,  const FS_CHAR* name,  FS_LPCWSTR lpwsTitle,  FS_DIBitmap defBtnBitmap))

/**
 * @brief FRRibbonCategoryGetPanelCount
 * @details Gets the count of ribbon panels.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @return   The count of ribbon panels
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonCategoryGetPanelCount, (FR_RibbonCategory ribbonCategory))

/**
 * @brief FRRibbonCategoryGetPanelByIndex
 * @details Gets the ribbon panel by index.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @param[in]  nIndex The specified index.
 * @return   The specified ribbon panel.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRRibbonCategoryGetPanelByName
 */
INTERFACE(FR_RibbonPanel, FRRibbonCategoryGetPanelByIndex, (FR_RibbonCategory ribbonCategory,  FS_INT32 nIndex))

/**
 * @brief FRRibbonCategoryGetPanelByName
 * @details Gets the ribbon panel by name.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @param[in]  panelName The specified name.
 * @return   The specified ribbon panel.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRRibbonCategoryGetPanelByIndex
 */
INTERFACE(FR_RibbonPanel, FRRibbonCategoryGetPanelByName, (FR_RibbonCategory ribbonCategory,  const FS_CHAR* panelName))

/**
 * @brief FRRibbonCategoryGetName
 * @details Gets the name of the ribbon category.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @param[out]  bsName It receives the name of the ribbon category.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonCategoryGetName, (FR_RibbonCategory ribbonCategory,  FS_ByteString* bsName))

/**
 * @brief FRRibbonCategoryShowInQATCustomizeToolsDlg
 * @details Sets whether the category can be shown in the QAT customize tools dialog.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @param[in]  bShow It indicates whether the category can be shown in the QAT customize tools dialog.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @see 
 */
INTERFACE(void, FRRibbonCategoryShowInQATCustomizeToolsDlg, (FR_RibbonCategory ribbonCategory,  FS_BOOL bShow))

/**
 * @brief FRRibbonCategoryCopyPanel
 * @details Gets a copy of the specified ribbon panel object.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @param[in]  ribbonPanel The specified ribbon panel object to be copied.
 * @return   A copy of the specified ribbon panel object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(FR_RibbonPanel, FRRibbonCategoryCopyPanel, (FR_RibbonCategory ribbonCategory,  FR_RibbonPanel ribbonPanel))

/**
 * @brief FRRibbonCategoryRecalcLayout
 * @details Whether to recalc the layout of the panels or not.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @param[in]  bRecalcPanels Whether to recalc the layout of the panels.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(void, FRRibbonCategoryRecalcLayout, (FR_RibbonCategory ribbonCategory,  FS_BOOL bRecalcPanels))

/**
 * @brief FRRibbonCategoryAddPanel2
 * @details Adds a new ribbon panel to the ribbon category. A ribbon category may contain several ribbon panels.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @param[in]  name The input name of the ribbon panel.
 * @param[in]  lpwsTitle The input title of the ribbon panel.
 * @param[in]  defBtnBitmap The default icon of the ribbon panel.
 * @param[in]  nPos The position of the ribbon panel.
 * @return   The new ribbon panel added to the ribbon category.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
 * @see FRRibbonCategoryGetPanelCount
 * @see FRRibbonCategoryGetPanelByIndex
 * @see FRRibbonCategoryAddPanel
 */
INTERFACE(FR_RibbonPanel, FRRibbonCategoryAddPanel2, (FR_RibbonCategory ribbonCategory,  const FS_CHAR* name,  FS_LPCWSTR lpwsTitle,  FS_DIBitmap defBtnBitmap,  FS_INT32 nPos))

/**
 * @brief FRRibbonCategoryAddDialog
 * @details You can create your own dialog under the category. You have to invoke <a>FRRibbonCategoryPreTranslateMessage</a> in the dialog's 
	* <Italic>PreTranslateMessage</Italic> function to dispatch the message.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @param[in]  createProc The callback function is called to notify the plug-in to create the dialog attached to the category.
 * @param[in]  destroyProc The callback function is called to notify the plug-in to destroy the dialog attached to the category.
 * @param[in]  pDialog The input pointer to a <Italic>MFC CDialog</Italic> attached to the category. It will be passed to the <param>createProc</param> and <param>destroyProc</param>.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonCategoryAddDialog, (FR_RibbonCategory ribbonCategory,  FRCategoryDlgCreateProc createProc,  FRCategoryDlgDestoryProc destroyProc,  void* pDialog))

/**
 * @brief FRRibbonCategoryPreTranslateMessage
 * @details When you create a dialog under the category, you have to invoke <a>FRRibbonCategoryPreTranslateMessage</a> in the dialog's 
	* <Italic>PreTranslateMessage</Italic> function to dispatch the message.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @param[in]  pMsg Pointer to a <Italic>MFC MSG</Italic> structure that contains the message to process.
 * @return   <a>TRUE</a> if the message was fully processed and should not be processed further. <a>FALSE</a> if the message should be processed in the normal way.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see FRRibbonCategoryAddDialog
 */
INTERFACE(FS_BOOL, FRRibbonCategoryPreTranslateMessage, (FR_RibbonCategory ribbonCategory,  void* pMsg))

/**
 * @brief FRRibbonCategoryAddDialogToRight
 * @details You can create your own dialog under the category on the right. You have to invoke <a>FRRibbonCategoryPreTranslateMessage</a> in the dialog's 
	* <Italic>PreTranslateMessage</Italic> function to dispatch the message.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @param[in]  createProc The callback function is called to notify the plug-in to create the dialog attached to the category.
 * @param[in]  destroyProc The callback function is called to notify the plug-in to destroy the dialog attached to the category.
 * @param[in]  pDialog The input pointer to a <Italic>MFC CDialog</Italic> attached to the category. It will be passed to the <param>createProc</param> and <param>destroyProc</param>.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRRibbonCategoryAddDialog
 */
INTERFACE(FS_BOOL, FRRibbonCategoryAddDialogToRight, (FR_RibbonCategory ribbonCategory,  FRCategoryDlgCreateProc createProc,  FRCategoryDlgDestoryProc destroyProc,  void* pDialog))

/**
 * @brief FRRibbonCategoryGetPos
 * @details Gets the position of the ribbon category in the ribbon bar.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @return   The position of the ribbon category in the ribbon bar.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonCategoryGetPos, (FR_RibbonCategory ribbonCategory))

/**
 * @brief FRRibbonCategorySetPos
 * @details Sets the position of the ribbon category in the ribbon bar.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @param[in]  nPos The position of the ribbon category in the ribbon bar.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see 
 */
INTERFACE(void, FRRibbonCategorySetPos, (FR_RibbonCategory ribbonCategory,  FS_INT32 nPos))

/**
 * @brief FRRibbonCategorySetHighlight
 * @details Sets the category to be highlight. Invokes <a>FRRibbonCategoryRecalcLayout</a> to take it effect.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @param[in]  color The color when the category is highlight.
 * @param[in]  bOnceOnly If TRUE, the highlight will disappear when the category is activated.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRRibbonCategoryGetHighlightColor
 */
INTERFACE(void, FRRibbonCategorySetHighlight, (FR_RibbonCategory ribbonCategory,  FS_COLORREF color,  FS_BOOL bOnceOnly))

/**
 * @brief FRRibbonCategoryGetHighlightColor
 * @details Gets the color when the category is highlight.
 * @param[in]  ribbonCategory The input ribbon category object.
 * @return   The color when the category is highlight.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRRibbonCategorySetHighlight
 */
INTERFACE(FS_COLORREF, FRRibbonCategoryGetHighlightColor, (FR_RibbonCategory ribbonCategory))

NumOfSelector(FRRibbonCategory)
ENDENUM

//*****************************
/* RibbonPanel HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRRibbonPanelAddElement
 * @details Adds a new ribbon element to the ribbon panel
 * @param[in]  ribbonPanel The input ribbon panel object.
 * @param[in]  nElementType The specified type of the element to be added.
 * @param[in]  name The specified name of the element to be added.
 * @param[in]  lpwsTitle The specified title of the element to be added.
 * @param[in]  nPos The specified position of the element to be added.
 * @return   The new ribbon element. For example, if sets <param>nElementType</param> as <a>FR_RIBBON_BUTTON</a>,
	* the returned value can be converted to <a>FR_RibbonButton</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void*, FRRibbonPanelAddElement, (FR_RibbonPanel ribbonPanel,  FR_Ribbon_Element_Type nElementType,  const FS_CHAR* name,  FS_LPCWSTR lpwsTitle,  FS_INT32 nPos))

/**
 * @brief FRRibbonPanelChangeElementType
 * @details Changes the specified element to other types.
 * @param[in]  ribbonPanel The input ribbon panel object.
 * @param[in]  name The specified name of the ribbon element.
 * @param[in]  nElementType The specified type you want to change to.
 * @return   The ribbon element with new type.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void*, FRRibbonPanelChangeElementType, (FR_RibbonPanel ribbonPanel,  const FS_CHAR* name,  FR_Ribbon_Element_Type nElementType))

/**
 * @brief FRRibbonPanelAddElementToGroup
 * @details Adds a new ribbon element to the  specified group.
 * @param[in]  ribbonPanel The input ribbon panel object.
 * @param[in]  groupName The specified group name.
 * @param[in]  nElementType The type of ribbon element added to the group.
 * @param[in]  elementName The input name of the ribbon element.
 * @param[in]  lpwsTitle The input title of the ribbon element.
 * @return   The new ribbon element added to the specified group. For example, if sets <param>elementName</param> as <a>FR_RIBBON_BUTTON</a>,
	* the returned value can be converted to <a>FR_RibbonButton</a>. The element belongs to the group will not display the title.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void*, FRRibbonPanelAddElementToGroup, (FR_RibbonPanel ribbonPanel,  const FS_CHAR* groupName,  FR_Ribbon_Element_Type nElementType,  const FS_CHAR* elementName,  FS_LPCWSTR lpwsTitle))

/**
 * @brief FRRibbonPanelSetLaunchButton
 * @details Sets the launch button.
 * @param[in]  ribbonPanel The input ribbon panel object.
 * @param[in]  name The input name of the launch button.
 * @param[in]  lpwsTitle The input title of the launch button.
 * @return   The launch button.
 * @note This interface is reserved.
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_RibbonButton, FRRibbonPanelSetLaunchButton, (FR_RibbonPanel ribbonPanel,  const FS_CHAR* name,  FS_LPCWSTR lpwsTitle))

/**
 * @brief FRRibbonPanelCopyElementToPanel
 * @details Copies an existing ribbon element to the panel.
 * @param[in]  ribbonPanel The input ribbon panel object.
 * @param[in]  pSrcRibbonElement The existing ribbon element.
 * @return   The corresponding ribbon button. For example, if the type is <a>FR_RIBBON_BUTTON</a>,
	* the returned value can be converted to <a>FR_RibbonButton</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void*, FRRibbonPanelCopyElementToPanel, (FR_RibbonPanel ribbonPanel,  FR_RibbonElement pSrcRibbonElement))

/**
 * @brief FRRibbonPanelSetTitle
 * @details Sets the title of the ribbon panel.
 * @param[in]  ribbonPanel The input ribbon panel object.
 * @param[in]  lpwsTitle The input title of the ribbon panel.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPanelSetTitle, (FR_RibbonPanel ribbonPanel,  FS_LPCWSTR lpwsTitle))

/**
 * @brief FRRibbonPanelGetTitle
 * @details Gets the title of the ribbon panel.
 * @param[in]  ribbonPanel The input ribbon panel object.
 * @param[out]  wsTitle It receives the title of the ribbon panel.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPanelGetTitle, (FR_RibbonPanel ribbonPanel,  FS_WideString* wsTitle))

/**
 * @brief FRRibbonPanelSetVisible
 * @details Sets the ribbon panel to visible or not.
 * @param[in]  ribbonPanel The input ribbon panel object.
 * @param[in]  bVisible <a>TRUE</a> if sets the ribbon panel to visible.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPanelSetVisible, (FR_RibbonPanel ribbonPanel,  FS_BOOL bVisible))

/**
 * @brief FRRibbonPanelGetVisible
 * @details CHecks whether the ribbon panel is visible or not.
 * @param[in]  ribbonPanel The input ribbon panel object.
 * @return   <a>TRUE</a> if the ribbon panel is visible, otherwise <a>FALSE</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonPanelGetVisible, (FR_RibbonPanel ribbonPanel))

/**
 * @brief FRRibbonPanelGetElementByName
 * @details Gets the The specified ribbon element by name.
 * @param[in]  ribbonPanel The input ribbon panel object.
 * @param[in]  elementName The specified name of the ribbon element.
 * @return   The specified ribbon element.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_RibbonElement, FRRibbonPanelGetElementByName, (FR_RibbonPanel ribbonPanel,  const FS_CHAR* elementName))

/**
 * @brief FRRibbonPanelGetElementCount
 * @details Get the count of the ribbon element.
 * @param[in]  ribbonPanel The input ribbon panel object.
 * @return   The count of the ribbon element.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonPanelGetElementCount, (FR_RibbonPanel ribbonPanel))

/**
 * @brief FRRibbonPanelGetElementByIndex
 * @details Gets the the specified ribbon element by index.
 * @param[in]  ribbonPanel The input ribbon panel object.
 * @param[in]  nIndex The specified index.
 * @return   The specified ribbon element.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_RibbonElement, FRRibbonPanelGetElementByIndex, (FR_RibbonPanel ribbonPanel,  FS_INT32 nIndex))

/**
 * @brief FRRibbonPanelSetPanelImage
 * @details Sets the bitmap when the ribbon panel is narrowed.
 * @param[in]  ribbonPanel The input ribbon panel object.
 * @param[in]  pSmallBitmap The input bitmap when the ribbon panel is narrowed.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPanelSetPanelImage, (FR_RibbonPanel ribbonPanel,  FS_DIBitmap pSmallBitmap))

/**
 * @brief FRRibbonPanelGetName
 * @details Gets the name of the ribbon panel.
 * @param[in]  ribbonPanel The input ribbon panel object.
 * @param[out]  bsName It receives the name of the ribbon panel.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPanelGetName, (FR_RibbonPanel ribbonPanel,  FS_ByteString* bsName))

/**
 * @brief FRRibbonPanelShowInQATCustomizeToolsDlg
 * @details Sets whether the panel can be shown in the QAT customize tools dialog.
 * @param[in]  ribbonPanel The input ribbon panel object.
 * @param[in]  bShow It indicates whether the panel can be shown in the QAT customize tools dialog.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @see 
 */
INTERFACE(void, FRRibbonPanelShowInQATCustomizeToolsDlg, (FR_RibbonPanel ribbonPanel,  FS_BOOL bShow))

/**
 * @brief FRRibbonPanelSetImageInitProc
 * @details Sets the callback invoked by Foxit Reader to init the visible image.
 * @param[in]  ribbonPanel The input ribbon panel object.
 * @param[in]  proc The callback invoked by Foxit Reader to init the visible image.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(void, FRRibbonPanelSetImageInitProc, (FR_RibbonPanel ribbonPanel,  FRRibbonPanelImageInitProc proc))

/**
 * @brief FRRibbonPanelSetKey
 * @details Sets the shortcut key of the ribbon panel
 * @param[in]  ribbonPanel The input ribbon panel object.
 * @param[in]  lpwsShorcutKey The input shortcut key.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
 * @see 
 */
INTERFACE(void, FRRibbonPanelSetKey, (FR_RibbonPanel ribbonPanel,  FS_LPCWSTR lpwsShorcutKey))

/**
 * @brief FRRibbonPanelAddDialog
 * @details You can create your own dialog under the panel. You have to invoke <a>FRRibbonPanelPreTranslateMessage</a> in the dialog's 
	* <Italic>PreTranslateMessage</Italic> function to dispatch the message.
 * @param[in]  ribbonPanel The input ribbon panel object.
 * @param[in]  createProc The callback function is called to notify the plug-in to create the dialog attached to the panel.
 * @param[in]  destroyProc The callback function is called to notify the plug-in to destroy the dialog attached to the panel.
 * @param[in]  pDialog The input pointer to a <Italic>MFC CDialog</Italic> attached to the panel. It will be passed to the <param>createProc</param> and <param>destroyProc</param>.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonPanelAddDialog, (FR_RibbonPanel ribbonPanel,  FRPanelDlgCreateProc createProc,  FRPanelDlgDestoryProc destroyProc,  void* pDialog))

/**
 * @brief FRRibbonPanelPreTranslateMessage
 * @details When you create a dialog under the panel, you have to invoke <a>FRRibbonPanelPreTranslateMessage</a> in the dialog's 
	* <Italic>PreTranslateMessage</Italic> function to dispatch the message.
 * @param[in]  ribbonPanel The input ribbon panel object.
 * @param[in]  pMsg Pointer to a <Italic>MFC MSG</Italic> structure that contains the message to process.
 * @return   <a>TRUE</a> if the message was fully processed and should not be processed further. <a>FALSE</a> if the message should be processed in the normal way.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see FRRibbonPanelAddDialog
 */
INTERFACE(FS_BOOL, FRRibbonPanelPreTranslateMessage, (FR_RibbonPanel ribbonPanel,  void* pMsg))

/**
 * @brief FRRibbonPanelEnableAddToCustomizeDlg
 * @details Sets whether the panel can be added to the custom setting dialog or not.
 * @param[in]  ribbonPanel The input ribbon panel object.
 * @param[in]  bEnable Whether the panel can be added to the custom setting dialog or not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(void, FRRibbonPanelEnableAddToCustomizeDlg, (FR_RibbonPanel ribbonPanel,  FS_BOOL bEnable))

/**
 * @brief FRRibbonPanelSetShowDefaultButtonAtLast
 * @details Sets whether the panel will show the default button at last or not.
 * @param[in]  ribbonPanel The input ribbon panel object.
 * @param[in]  bLast Whether the panel will show the default button at last or not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(void, FRRibbonPanelSetShowDefaultButtonAtLast, (FR_RibbonPanel ribbonPanel,  FS_BOOL bLast))

NumOfSelector(FRRibbonPanel)
ENDENUM

//*****************************
/* RibbonElement HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRRibbonElementAddSubItem
 * @details Add a new sub item to the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  nElementType The input type of ribbon element.
 * @param[in]  name The input name of ribbon element.
 * @param[in]  lpwsTitle The input title of ribbon element.
 * @param[in]  nPos The input position of ribbon element.
 * @param[in]  bOnTop Whether the added sub item is on the top or not.
 * @param[in]  bChangeFun When the user clicks the sub item, whether the parent's function should be change to the sub item's. Sets it FALSE as default.
 * @param[in]  bChangeImage When the user clicks the sub item, whether the parent's icon should be change to the sub item's. Sets it FALSE as default.
 * @return   The new sub item of the ribbon element. For example, if sets <param>nElementType</param> as <a>FR_RIBBON_BUTTON</a>,
	* the returned value can be converted to <a>FR_RibbonButton</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void*, FRRibbonElementAddSubItem, (FR_RibbonElement ribbonElement,  FR_Ribbon_Element_Type nElementType,  const FS_CHAR* name,  FS_LPCWSTR lpwsTitle,  FS_INT32 nPos,  FS_BOOL bOnTop,  FS_BOOL bChangeFun,  FS_BOOL bChangeImage))

/**
 * @brief FRRibbonElementSetExecuteProc
 * @details Sets the callback function that will be called when the user clicks the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  proc The callback will be called when the user clicks the ribbon element.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementSetExecuteProc, (FR_RibbonElement ribbonElement,  FRExecuteProc proc))

/**
 * @brief FRRibbonElementSetComputeEnabledProc
 * @details Sets the callback function that will be called to determine whether the ribbon element is enabled or not.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  proc The callback will be called to determine whether the ribbon element is enabled or not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementSetComputeEnabledProc, (FR_RibbonElement ribbonElement,  FRComputeEnabledProc proc))

/**
 * @brief FRRibbonElementSetComputeMarkedProc
 * @details Sets the callback function that will be called to determine whether the ribbon element is marked or not.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  proc The callback will be called to determine whether the ribbon element is marked or not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementSetComputeMarkedProc, (FR_RibbonElement ribbonElement,  FRComputeMarkedProc proc))

/**
 * @brief FRRibbonElementDoExecuteProc
 * @details Executes the <a>FRExecuteProc</a>() associated with the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementDoExecuteProc, (FR_RibbonElement ribbonElement))

/**
 * @brief FRRibbonElementIsEnabled
 * @details Checks whether the ribbon element is enabled or not.
 * @param[in]  ribbonElement The input ribbon element object.
 * @return   <a>TRUE</a> if the ribbon element is enabled, otherwise <a>FALSE</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonElementIsEnabled, (FR_RibbonElement ribbonElement))

/**
 * @brief FRRibbonElementIsMarked
 * @details Checks whether the ribbon element is marked or not.
 * @param[in]  ribbonElement The input ribbon element object.
 * @return   <a>TRUE</a> if the ribbon element is marked, otherwise <a>FALSE</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonElementIsMarked, (FR_RibbonElement ribbonElement))

/**
 * @brief FRRibbonElementSetClientData
 * @details Sets the client data to the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  clientData The input client data.
 * @param[in]  callback The callback function will be called when the ribbon element is to be released.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementSetClientData, (FR_RibbonElement ribbonElement,  void* clientData,  FRFreeDataProc callback))

/**
 * @brief FRRibbonElementGetClientData
 * @details Gets the client data.
 * @param[in]  ribbonElement The input ribbon element object.
 * @return   The client data.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void*, FRRibbonElementGetClientData, (FR_RibbonElement ribbonElement))

/**
 * @brief FRRibbonElementSetAccel
 * @details Sets the accelerator key of the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  bAlt Whether the <Italic>Alt</Italic> key is pressed down or not.
 * @param[in]  bShift Whether the <Italic>Shift</Italic> key is pressed down or not.
 * @param[in]  bCtrl Whether the <Italic>Ctrl</Italic> key is pressed down or not.
 * @param[in]  key The input accelerator key.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementSetAccel, (FR_RibbonElement ribbonElement,  FS_BOOL bAlt,  FS_BOOL bShift,  FS_BOOL bCtrl,  FS_CHAR key))

/**
 * @brief FRRibbonElementGetAccel
 * @details Gets the accelerator key of the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[out]  bAlt It receives <a>TRUE</a> if the <Italic>Alt</Italic> key is pressed down.
 * @param[out]  bShift It receives <a>TRUE</a> if the <Italic>Shift</Italic> key is pressed down.
 * @param[out]  bCtrl It receives <a>TRUE</a> if the <Italic>Ctrl</Italic> key is pressed down.
 * @param[out]  key It receives the accelerator key
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementGetAccel, (FR_RibbonElement ribbonElement,  FS_BOOL* bAlt,  FS_BOOL* bShift,  FS_BOOL* bCtrl,  FS_CHAR* key))

/**
 * @brief FRRibbonElementSetKey
 * @details Sets the shortcut key of the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  lpwsShorcutKey The input shortcut key.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementSetKey, (FR_RibbonElement ribbonElement,  FS_LPCWSTR lpwsShorcutKey))

/**
 * @brief FRRibbonElementGetKey
 * @details Gets the shortcut key of the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[out]  wsKey It receives the shortcut key of the ribbon element.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementGetKey, (FR_RibbonElement ribbonElement,  FS_WideString* wsKey))

/**
 * @brief FRRibbonElementSetTooltip
 * @details Sets the tooltip of the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  lpwsTooltip The input tooltip of the ribbon element.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementSetTooltip, (FR_RibbonElement ribbonElement,  FS_LPCWSTR lpwsTooltip))

/**
 * @brief FRRibbonElementGetTooltip
 * @details Gets the tooltip of the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[out]  wsTooltip It receives the tooltip of the ribbon element.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementGetTooltip, (FR_RibbonElement ribbonElement,  FS_WideString* wsTooltip))

/**
 * @brief FRRibbonElementSetDescription
 * @details Sets the description of the ribbon element..
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  lpwsDes The input description of the ribbon element.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementSetDescription, (FR_RibbonElement ribbonElement,  FS_LPCWSTR lpwsDes))

/**
 * @brief FRRibbonElementGetDescription
 * @details Gets the description of the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[out]  wsDes It receives the description of the ribbon element.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementGetDescription, (FR_RibbonElement ribbonElement,  FS_WideString* wsDes))

/**
 * @brief FRRibbonElementSetTitle
 * @details Sets the title of the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  lpwsTitle The input title of the ribbon element.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementSetTitle, (FR_RibbonElement ribbonElement,  FS_LPCWSTR lpwsTitle))

/**
 * @brief FRRibbonElementGetTitle
 * @details Gets the title of the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[out]  wsTitle It receives the title of the ribbon element.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementGetTitle, (FR_RibbonElement ribbonElement,  FS_WideString* wsTitle))

/**
 * @brief FRRibbonElementSetImage
 * @details Sets the icon of the ribbon element. The ribbon element contains a large icon and a small icon.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  largeBitmap The input 32*32 bitmap.
 * @param[in]  smallBitmap The input 16*16 bitmap.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementSetImage, (FR_RibbonElement ribbonElement,  FS_DIBitmap largeBitmap,  FS_DIBitmap smallBitmap))

/**
 * @brief FRRibbonElementAddChangeImage
 * @details Adds the 32*32 bitmap and the 16*16 bitmap to the bitmap list that can be used to change the icon of the ribbon element.
	* This interface is only applicable for <a>FR_RIBBON_BUTTON</a>, <a>FR_RIBBON_EDIT</a>, <a>FR_RIBBON_LISTBUTTON</a>, 
	* <a>FR_RIBBON_COLORBUTTON</a>, and <a>FR_RIBBON_PALETTEBUTTON</a>.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  largeBitmap The input 32*32 bitmap list.
 * @param[in]  smallBitmap The input 16*16 bitmap list.
 * @param[out]  nLargeIndex It receives the index of large bitmap added to the bitmap list.
 * @param[out]  nSmallIndex It receives the index of small bitmap added to the bitmap list.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRRibbonElementChangeImage
 */
INTERFACE(void, FRRibbonElementAddChangeImage, (FR_RibbonElement ribbonElement,  FS_DIBitmap largeBitmap,  FS_DIBitmap smallBitmap,  FS_INT32* nLargeIndex,  FS_INT32* nSmallIndex))

/**
 * @brief FRRibbonElementChangeImage
 * @details Changes the icon of the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  bUseDefault <a>TRUE</a> if uses the original icon, otherwise uses the icon of specified index.
 * @param[in]  nLargeIndex The specified index of the large icon.
 * @param[in]  nSmallIndex The specified index of the small icon.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRRibbonElementAddChangeImage
 */
INTERFACE(void, FRRibbonElementChangeImage, (FR_RibbonElement ribbonElement,  FS_BOOL bUseDefault,  FS_INT32 nLargeIndex,  FS_INT32 nSmallIndex))

/**
 * @brief FRRibbonElementSetTooltipImage
 * @details Sets the icon of the tooltip of the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  bitmap The input icon of the tooltip.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRRibbonElementSetTooltipImageII
 */
INTERFACE(void, FRRibbonElementSetTooltipImage, (FR_RibbonElement ribbonElement,  FS_DIBitmap bitmap))

/**
 * @brief FRRibbonElementSetTooltipImageII
 * @details Sets the icon of the tooltip of the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  hInstance The instance handle of the plug-in.
 * @param[in]  nImageID The resource ID of the bitmap.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRRibbonElementSetTooltipImage
 */
INTERFACE(void, FRRibbonElementSetTooltipImageII, (FR_RibbonElement ribbonElement,  HINSTANCE hInstance,  unsigned int nImageID))

/**
 * @brief FRRibbonElementSetVisible
 * @details Sets the ribbon element to be visible or not.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  bVisible <a>TRUE</a> if the ribbon element is visible, otherwise <a>FALSE</a>.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementSetVisible, (FR_RibbonElement ribbonElement,  BOOL bVisible))

/**
 * @brief FRRibbonElementGetVisible
 * @details Checks whether the ribbon element is visible or not.
 * @param[in]  ribbonElement The input ribbon element object.
 * @return   <a>TRUE</a> if the ribbon element is visible, otherwise <a>FALSE</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonElementGetVisible, (FR_RibbonElement ribbonElement))

/**
 * @brief FRRibbonElementRemove
 * @details Removes the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonElementRemove, (FR_RibbonElement ribbonElement))

/**
 * @brief FRRibbonElementGetType
 * @details Gets the type of the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @return   The type of the ribbon element.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_Ribbon_Element_Type, FRRibbonElementGetType, (FR_RibbonElement ribbonElement))

/**
 * @brief FRRibbonElementGetOriginalID
 * @details Gets the original ID of the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @return   The original ID of the ribbon element.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_DWORD, FRRibbonElementGetOriginalID, (FR_RibbonElement ribbonElement))

/**
 * @brief FRRibbonElementGetName
 * @details Gets the name of the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[out]  outName It receives the name of the ribbon element.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementGetName, (FR_RibbonElement ribbonElement,  FS_ByteString* outName))

/**
 * @brief FRRibbonElementGetSubItemCount
 * @details Gets the count of the sub items.
 * @param[in]  ribbonElement The input ribbon element object.
 * @return   The count of the sub items.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonElementGetSubItemCount, (FR_RibbonElement ribbonElement))

/**
 * @brief FRRibbonElementFindSubElementByIndex
 * @details Gets the ribbon element by index.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  nIndex The specified index.
 * @return   The found ribbon element.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_RibbonElement, FRRibbonElementFindSubElementByIndex, (FR_RibbonElement ribbonElement,  FS_INT32 nIndex))

/**
 * @brief FRRibbonElementGetSubElementByName
 * @details Gets the ribbon element by name.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  name The specified name.
 * @return   The found ribbon element.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_RibbonElement, FRRibbonElementGetSubElementByName, (FR_RibbonElement ribbonElement,  const FS_CHAR* name))

/**
 * @brief FRRibbonElementCopyElementAsSubItem
 * @details Copies an existing ribbon element as the sub item.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  srcElement The input ribbon element to be copied.
 * @param[in]  bChangeFun When the user clicks the sub item, whether the parent's function should be change to the sub item's. Sets it FALSE as default.
 * @param[in]  bChangeImage When the user clicks the sub item, whether the parent's icon should be change to the sub item's. Sets it FALSE as default.
 * @param[in]  bAlwaysSmall Sets it as <a>TRUE</a> if the sub item is always shown as small.
 * @return   The sub item of the ribbon element. If the type is <a>FR_RIBBON_BUTTON</a>, the returned value can be converted to <a>FR_RibbonButton</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void*, FRRibbonElementCopyElementAsSubItem, (FR_RibbonElement ribbonElement,  FR_RibbonElement srcElement,  FS_BOOL bChangeFun,  FS_BOOL bChangeImage,  FS_BOOL bAlwaysSmall))

/**
 * @brief FRRibbonElementGetCorrespondingButton
 * @details Gets the corresponding button according to the type.
 * @param[in]  ribbonElement The input ribbon element object.
 * @return   The ribbon button. If the type is <a>FR_RIBBON_BUTTON</a>, the returned value can be converted to <a>FR_RibbonButton</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void*, FRRibbonElementGetCorrespondingButton, (FR_RibbonElement ribbonElement))

/**
 * @brief FRRibbonElementSetAsSubElement
 * @details Sets that the ribbon element uses the specified sub item's response function.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  subElementName The specified name.
 * @param[in]  bChangeImage Whether the parent's icon should be change to the sub item's.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementSetAsSubElement, (FR_RibbonElement ribbonElement,  const FS_CHAR* subElementName,  FS_BOOL bChangeImage))

/**
 * @brief FRRibbonElementSetImplicitLargeBitmap
 * @details Sets the implicit large icon. It is the default large icon, when the icon needs to be changed by 
	* <a>FRRibbonElementSetAsSubElement</a>. If the ribbon element already has the large icon, this interface is ignored.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  largeBitmap The input implicit large icon.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementSetImplicitLargeBitmap, (FR_RibbonElement ribbonElement,  FS_DIBitmap largeBitmap))

/**
 * @brief FRRibbonElementSetShowMode
 * @details Sets the showing mode.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  bLarge <a>TRUE</a> if the ribbon element is shown using the large icon.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementSetShowMode, (FR_RibbonElement ribbonElement,  FS_BOOL bLarge))

/**
 * @brief FRRibbonElementSetDropdownProc
 * @details Sets the drop-down callback function.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  proc The callback function is called when the user clicks the ribbon element drop-down arrow.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonElementSetDropdownProc, (FR_RibbonElement ribbonElement,  FRDropDownProc proc))

/**
 * @brief FRRibbonElementGetClientRect
 * @details Gets the client rectangle of the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[out]  rcClient It receives the client rectangle.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @see FRRibbonElementGetWindowRect
 */
INTERFACE(FS_BOOL, FRRibbonElementGetClientRect, (FR_RibbonElement ribbonElement,  FS_Rect* rcClient))

/**
 * @brief FRRibbonElementGetWindowRect
 * @details Gets the window rectangle of the ribbon element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[out]  rcScreen It receives the window rectangle.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @see FRRibbonElementGetClientRect
 */
INTERFACE(FS_BOOL, FRRibbonElementGetWindowRect, (FR_RibbonElement ribbonElement,  FS_Rect* rcScreen))

/**
 * @brief FRRibbonElementShowInQATCustomizeToolsDlg
 * @details Sets whether the ribbon element can be shown in the QAT customize tools dialog.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  bShow It indicates whether the ribbon element can be shown in the QAT customize tools dialog.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @see 
 */
INTERFACE(void, FRRibbonElementShowInQATCustomizeToolsDlg, (FR_RibbonElement ribbonElement,  FS_BOOL bShow))

/**
 * @brief FRRibbonElementSetImageInitProc
 * @details Sets the callback invoked by Foxit Reader to init the visible image.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  proc The callback invoked by Foxit Reader to init the visible image.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(void, FRRibbonElementSetImageInitProc, (FR_RibbonElement ribbonElement,  FRRibbonElementImageInitProc proc))

/**
 * @brief FRRibbonElementGetButtonMapId
 * @details Gets the map ID.
 * @param[in]  ribbonElement The input ribbon element object.
 * @return   The map ID.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
 * @see 
 */
INTERFACE(DWORD, FRRibbonElementGetButtonMapId, (FR_RibbonElement ribbonElement))

/**
 * @brief FRRibbonElementSetBackstageViewTabElementKeepState
 * @details Sets to keep the state of element when the back stage view is open.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  bKeepState Whether keeps the state of element when the back stage view is open.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
 * @see 
 */
INTERFACE(void, FRRibbonElementSetBackstageViewTabElementKeepState, (FR_RibbonElement ribbonElement,  FS_BOOL bKeepState))

/**
 * @brief FRRibbonElementIsBackstageViewTabElementKeepState
 * @details Checks whether to keep the state of element when the back stage view is open.
 * @param[in]  ribbonElement The input ribbon element object.
 * @return   Whether to keep the state of element when the back stage view is open.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonElementIsBackstageViewTabElementKeepState, (FR_RibbonElement ribbonElement))

/**
 * @brief FRRibbonElementSetSelectOnly
 * @details Sets whether the element is just only for selecting or not.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[in]  bSelectOnly Whether the element is just only for selecting or not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(void, FRRibbonElementSetSelectOnly, (FR_RibbonElement ribbonElement,  FS_BOOL bSelectOnly))

/**
 * @brief FRRibbonElementGetCategoryName
 * @details Gets the category name of the specified element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[out]  outName (Filled by the method) A string buffer to receive the name.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see 
 */
INTERFACE(void, FRRibbonElementGetCategoryName, (FR_RibbonElement ribbonElement,  FS_ByteString* outName))

/**
 * @brief FRRibbonElementGetPanelName
 * @details Gets the panel name of the specified element.
 * @param[in]  ribbonElement The input ribbon element object.
 * @param[out]  outName (Filled by the method) A string buffer to receive the name.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see 
 */
INTERFACE(void, FRRibbonElementGetPanelName, (FR_RibbonElement ribbonElement,  FS_ByteString* outName))

NumOfSelector(FRRibbonElement)
ENDENUM

//*****************************
/* RibbonButton HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRRibbonButtonGetElement
 * @details Gets the ribbon element associated with the ribbon button. All types of buttons associate with a ribbon element.
	* The ribbon element manipulates the common properties of all types of buttons.
 * @param[in]  ribbonButton The input ribbon button object.
 * @return   The ribbon element associated with the ribbon button.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_RibbonElement, FRRibbonButtonGetElement, (FR_RibbonButton ribbonButton))

/**
 * @brief FRRibbonButtonSetDefaultCommand
 * @details When the button has the drop-down style, sets <param>bSet</param> as <a>TRUE</a> if you wan to both click the button 
	* to execute and drop down the button, sets <param>bSet</param> as <a>FALSE</a> if you just want to drop down the button.
 * @param[in]  ribbonButton The input ribbon button object.
 * @param[in]  bSet When the button has the drop-down style, sets it as <a>TRUE</a> if you wan to both click 
	* the button to execute and drop down the button, sets it as <a>FALSE</a> if you just want to drop down the button.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonButtonSetDefaultCommand, (FR_RibbonButton ribbonButton,  FS_BOOL bSet))

/**
 * @brief FRRibbonButtonSetAlwaysShowDescription
 * @details Whether to show the description always like the title or not.
 * @param[in]  ribbonButton The input ribbon button object.
 * @param[in]  bAlwaysShowDescription <a>TRUE</a> if you want to show the description always like the title.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonButtonSetAlwaysShowDescription, (FR_RibbonButton ribbonButton,  FS_BOOL bAlwaysShowDescription))

/**
 * @brief FRRibbonButtonSetButtonPopupWnd
 * @details If a ribbon button has the drop-down style, you can pop up a window when it is dropped down. Sets <param>hWnd</param> as
	* NULL to make the ribbon button has the drop-down arrow. When the <a>FRDropDownProc</a> callback is invoked, calls this interface 
	* in the callback function to pass the window handle to the ribbon button.
 * @param[in]  ribbonButton The input ribbon button object.
 * @param[in]  hWnd The window handle.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonButtonSetButtonPopupWnd, (FR_RibbonButton ribbonButton,  HWND hWnd))

/**
 * @brief FRRibbonButtonCloseButtonPopupWnd
 * @details Closes the pop-up window created by <a>FRRibbonButtonSetButtonPopupWnd</a>
 * @param[in]  ribbonButton The input ribbon button object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonButtonCloseButtonPopupWnd, (FR_RibbonButton ribbonButton))

NumOfSelector(FRRibbonButton)
ENDENUM

//*****************************
/* RibbonEdit HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRRibbonEditGetElement
 * @details Gets the ribbon element associated with the ribbon edit. All types of buttons associate with a ribbon element.
	* The ribbon element manipulates the common properties of all types of buttons.
 * @param[in]  ribbonEdit The input ribbon edit object.
 * @return   The ribbon element associated with the ribbon edit.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_RibbonElement, FRRibbonEditGetElement, (FR_RibbonEdit ribbonEdit))

/**
 * @brief FRRibbonEditGetText
 * @details Gets the text of the ribbon edit.
 * @param[in]  ribbonEdit The input ribbon edit object.
 * @param[out]  wsText It receives the text of the ribbon edit.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonEditGetText, (FR_RibbonEdit ribbonEdit,  FS_WideString* wsText))

/**
 * @brief FRRibbonEditSetText
 * @details Sets the text of the ribbon edit.
 * @param[in]  ribbonEdit The input ribbon edit object.
 * @param[in]  lpwsText The input text.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonEditSetText, (FR_RibbonEdit ribbonEdit,  FS_LPCWSTR lpwsText))

/**
 * @brief FRRibbonEditEnableSpinButtons
 * @details Enables the spin buttons of the ribbon edit.
 * @param[in]  ribbonEdit The input ribbon edit object.
 * @param[in]  nMin The minimum value of the spin button.
 * @param[in]  nMax The maximum value of the spin button.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonEditEnableSpinButtons, (FR_RibbonEdit ribbonEdit,  FS_INT32 nMin,  FS_INT32 nMax))

/**
 * @brief FRRibbonEditSetSearchMode
 * @details Whether to enable the search mode of the ribbon edit.
 * @param[in]  ribbonEdit The input ribbon edit object.
 * @param[in]  lpwsPrompt Then text displayed in the ribbon edit.
 * @param[in]  bEnable <a>TRUE</a> to enable the search mode.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonEditSetSearchMode, (FR_RibbonEdit ribbonEdit,  FS_LPCWSTR lpwsPrompt,  FS_BOOL bEnable))

/**
 * @brief FRRibbonEditSetWidth
 * @details Sets the width of the ribbon edit.
 * @param[in]  ribbonEdit The input ribbon edit object.
 * @param[in]  nWidth The input width of the ribbon edit.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonEditSetWidth, (FR_RibbonEdit ribbonEdit,  FS_INT32 nWidth))

/**
 * @brief FRRibbonEditGetHWnd
 * @details Gets the window handle of the ribbon edit object.
 * @param[in]  ribbonEdit The input ribbon edit object.
 * @return   The window handle of the ribbon edit object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 * @see 
 */
INTERFACE(HWND, FRRibbonEditGetHWnd, (FR_RibbonEdit ribbonEdit))

/**
 * @brief FRRibbonEditSetTextFlag
 * @details Sets the type you can input into the ribbon edit. 0 for no restriction, 1 for float, 2 for integer.
 * @param[in]  ribbonEdit The input ribbon edit object.
 * @param[in]  nTextFlag The type you can input into the ribbon edit. 0 for no restriction, 1 for float, 2 for integer.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 * @see 
 */
INTERFACE(void, FRRibbonEditSetTextFlag, (FR_RibbonEdit ribbonEdit,  FS_DWORD nTextFlag))

/**
 * @brief FRRibbonEditSetFocus
 * @details Sets the focus to the ribbon edit or not.
 * @param[in]  ribbonEdit The input ribbon edit object.
 * @param[in]  bFocus Inputs TRUE to set the focus to the ribbon edit.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
 * @see 
 */
INTERFACE(void, FRRibbonEditSetFocus, (FR_RibbonEdit ribbonEdit,  FS_BOOL bFocus))

NumOfSelector(FRRibbonEdit)
ENDENUM

//*****************************
/* RibbonLabel HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRRibbonLabelGetElement
 * @details Gets the ribbon element associated with the ribbon label. All types of buttons associate with a ribbon element.
	* The ribbon element manipulates the common properties of all types of buttons.
 * @param[in]  ribbonLabel The input ribbon label object.
 * @return   The ribbon element associated with the ribbon label.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_RibbonElement, FRRibbonLabelGetElement, (FR_RibbonLabel ribbonLabel))

NumOfSelector(FRRibbonLabel)
ENDENUM

//*****************************
/* RibbonCheckBox HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRRibbonCheckBoxGetElement
 * @details Gets the ribbon element associated with the ribbon check box. All types of buttons associate with a ribbon element.
	* The ribbon element manipulates the common properties of all types of buttons.
 * @param[in]  ribbonCheckBox The input ribbon check box object.
 * @return   The ribbon element associated with the ribbon check box.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_RibbonElement, FRRibbonCheckBoxGetElement, (FR_RibbonCheckBox ribbonCheckBox))

/**
 * @brief FRRibbonCheckBoxIsChecked
 * @details Checks whether the ribbon check box is checked or not.
 * @param[in]  ribbonCheckBox The input ribbon check box object.
 * @return   <a>TRUE</a> if the ribbon check box is checked, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonCheckBoxIsChecked, (FR_RibbonCheckBox ribbonCheckBox))

/**
 * @brief FRRibbonCheckBoxSetCheck
 * @details Whether to set the ribbon check box to be checked or not.
 * @param[in]  ribbonCheckBox The input ribbon check box object.
 * @param[in]  bCheck <a>TRUE</a> if you want to set the ribbon check box to be checked.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonCheckBoxSetCheck, (FR_RibbonCheckBox ribbonCheckBox,  FS_BOOL bCheck))

NumOfSelector(FRRibbonCheckBox)
ENDENUM

//*****************************
/* RibbonRadioButton HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRRibbonRadioButtonGetElement
 * @details Gets the ribbon element associated with the ribbon radio button. All types of buttons associate with a ribbon element.
	* The ribbon element manipulates the common properties of all types of buttons.
 * @param[in]  ribbonRadioButton The input ribbon radio button object.
 * @return   The ribbon element associated with the ribbon radio button.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_RibbonElement, FRRibbonRadioButtonGetElement, (FR_RibbonRadioButton ribbonRadioButton))

/**
 * @brief FRRibbonRadioButtonIsChecked
 * @details Checks whether the ribbon radio button is checked or not.
 * @param[in]  ribbonRadioButton The input ribbon radio button object.
 * @return   <a>TRUE</a> if the ribbon radio button is checked, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonRadioButtonIsChecked, (FR_RibbonRadioButton ribbonRadioButton))

/**
 * @brief FRRibbonRadioButtonSetCheck
 * @details Whether to set the ribbon radio button to be checked or not.
 * @param[in]  ribbonRadioButton The input ribbon radio button object.
 * @param[in]  bCheck <a>TRUE</a> if you want to set the ribbon radio button to be checked.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonRadioButtonSetCheck, (FR_RibbonRadioButton ribbonRadioButton,  FS_BOOL bCheck))

NumOfSelector(FRRibbonRadioButton)
ENDENUM

//*****************************
/* RibbonComboBox HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRRibbonComboBoxGetElement
 * @details Gets the ribbon element associated with the ribbon combo box. All types of buttons associate with a ribbon element.
	* The ribbon element manipulates the common properties of all types of buttons.
 * @param[in]  ribbonComboBox The input ribbon combo box.
 * @return   The ribbon element associated with the ribbon combo box.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_RibbonElement, FRRibbonComboBoxGetElement, (FR_RibbonComboBox ribbonComboBox))

/**
 * @brief FRRibbonComboBoxAddItem
 * @details Adds a new item to the ribbon combo box.
 * @param[in]  ribbonComboBox The input ribbon combo box.
 * @param[in]  lpwsItemText The input text of the new item.
 * @return   The index of the new item.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonComboBoxAddItem, (FR_RibbonComboBox ribbonComboBox,  FS_LPCWSTR lpwsItemText))

/**
 * @brief FRRibbonComboBoxInsertItem
 * @details Inserts a new item to the ribbon combo box by position.
 * @param[in]  ribbonComboBox The input ribbon combo box.
 * @param[in]  nPos The specified position.
 * @param[in]  lpwsItemText The input text of the new item.
 * @return   The index of the new item.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonComboBoxInsertItem, (FR_RibbonComboBox ribbonComboBox,  FS_INT32 nPos,  FS_LPCWSTR lpwsItemText))

/**
 * @brief FRRibbonComboBoxGetItemCount
 * @details Gets the item count of the ribbon combo box.
 * @param[in]  ribbonComboBox The input ribbon combo box.
 * @return   The item count.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonComboBoxGetItemCount, (FR_RibbonComboBox ribbonComboBox))

/**
 * @brief FRRibbonComboBoxGetItem
 * @details Gets the text of the ribbon combo box by index.
 * @param[in]  ribbonComboBox The input ribbon combo box.
 * @param[in]  nIndex The specified index.
 * @param[out]  wsText It receives the text of the ribbon combo box.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonComboBoxGetItem, (FR_RibbonComboBox ribbonComboBox,  FS_INT32 nIndex,  FS_WideString* wsText))

/**
 * @brief FRRibbonComboBoxGetCurSel
 * @details Gets the currently selected item index.
 * @param[in]  ribbonComboBox The input ribbon combo box.
 * @return   The currently selected item index.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonComboBoxGetCurSel, (FR_RibbonComboBox ribbonComboBox))

/**
 * @brief FRRibbonComboBoxRemoveAllItems
 * @details Removes all the items.
 * @param[in]  ribbonComboBox The input ribbon combo box.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonComboBoxRemoveAllItems, (FR_RibbonComboBox ribbonComboBox))

/**
 * @brief FRRibbonComboBoxSelectItem
 * @details Selects the specified items by index.
 * @param[in]  ribbonComboBox The input ribbon combo box.
 * @param[in]  nItemIndex The specified index.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonComboBoxSelectItem, (FR_RibbonComboBox ribbonComboBox,  FS_INT32 nItemIndex))

/**
 * @brief FRRibbonComboBoxDeleteItem
 * @details Deletes the specified item by index.
 * @param[in]  ribbonComboBox The input ribbon combo box.
 * @param[in]  nItemIndex The specified index.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonComboBoxDeleteItem, (FR_RibbonComboBox ribbonComboBox,  FS_INT32 nItemIndex))

/**
 * @brief FRRibbonComboBoxFindItem
 * @details Finds the item by text.
 * @param[in]  ribbonComboBox The input ribbon combo box.
 * @param[in]  lpwsItemText The specified text.
 * @return   The index of found item.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonComboBoxFindItem, (FR_RibbonComboBox ribbonComboBox,  FS_LPCWSTR lpwsItemText))

/**
 * @brief FRRibbonComboBoxSetWidth
 * @details Sets the width of the ribbon combo box.
 * @param[in]  ribbonComboBox The input ribbon combo box.
 * @param[in]  nWidth The input width of the ribbon combo box.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonComboBoxSetWidth, (FR_RibbonComboBox ribbonComboBox,  FS_INT32 nWidth))

/**
 * @brief FRRibbonComboBoxSetEditBox
 * @details Sets whether the ribbon combo box has the edit box or not.
 * @param[in]  ribbonComboBox The input ribbon combo box.
 * @param[in]  bHasEditBox <a>TRUE</a> if the combo box has the edit box.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonComboBoxSetEditBox, (FR_RibbonComboBox ribbonComboBox,  FS_BOOL bHasEditBox))

/**
 * @brief FRRibbonComboBoxGetEditText
 * @details Gets the text of the edit text.
 * @param[in]  ribbonComboBox The input ribbon combo box.
 * @param[out]  wsText It receives the text of the edit.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonComboBoxGetEditText, (FR_RibbonComboBox ribbonComboBox,  FS_WideString* wsText))

/**
 * @brief FRRibbonComboBoxSetEditText
 * @details Sets the edit text of the ribbon combo box.
 * @param[in]  ribbonComboBox The input ribbon combo box.
 * @param[in]  lpwsText The input text.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonComboBoxSetEditText, (FR_RibbonComboBox ribbonComboBox,  FS_LPCWSTR lpwsText))

/**
 * @brief FRRibbonComboBoxEnableDropDownListResize
 * @details Sets whether the dropped down list can be resized or not.
 * @param[in]  ribbonComboBox The input ribbon combo box.
 * @param[in]  bEnable <a>TRUE</a> if the dropped down list can be resized.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonComboBoxEnableDropDownListResize, (FR_RibbonComboBox ribbonComboBox,  FS_BOOL bEnable))

/**
 * @brief FRRibbonComboBoxGetHWnd
 * @details Gets the window handle of the ribbon combo box.
 * @param[in]  ribbonComboBox The input ribbon combo box.
 * @return   The window handle of the ribbon combo box.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 * @see 
 */
INTERFACE(HWND, FRRibbonComboBoxGetHWnd, (FR_RibbonComboBox ribbonComboBox))

/**
 * @brief FRRibbonComboBoxSetTextFlag
 * @details Sets the type you can input into the combo box. 0 for no restriction, 1 for float, 2 for integer.
 * @param[in]  ribbonComboBox The input ribbon combo box.
 * @param[in]  nTextFlag The type you can input into the combo box. 0 for no restriction, 1 for float, 2 for integer.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 * @see 
 */
INTERFACE(void, FRRibbonComboBoxSetTextFlag, (FR_RibbonComboBox ribbonComboBox,  FS_DWORD nTextFlag))

/**
 * @brief FRRibbonComboBoxSetFocus
 * @details Sets the focus to the ribbon combo box or not.
 * @param[in]  ribbonComboBox The input ribbon combo box.
 * @param[in]  bFocus Inputs TRUE to set the focus to the ribbon combo box.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
 * @see 
 */
INTERFACE(void, FRRibbonComboBoxSetFocus, (FR_RibbonComboBox ribbonComboBox,  FS_BOOL bFocus))

NumOfSelector(FRRibbonComboBox)
ENDENUM

//*****************************
/* RibbonFontComboBox HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRRibbonFontComboBoxGetElement
 * @details Gets the ribbon element associated with the ribbon font combo box. All types of buttons associate with a ribbon element.
	* The ribbon element manipulates the common properties of all types of buttons.
 * @param[in]  ribbonFontComboBox The input ribbon font combo box.
 * @return   The ribbon element associated with the ribbon font combo box.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_RibbonElement, FRRibbonFontComboBoxGetElement, (FR_RibbonFontComboBox ribbonFontComboBox))

/**
 * @brief FRRibbonFontComboBoxGetItem
 * @details Gets the text of the item by index.
 * @param[in]  ribbonFontComboBox The input ribbon font combo box.
 * @param[in]  nIndex The specified index.
 * @param[out]  wsText It receives the text of the item.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonFontComboBoxGetItem, (FR_RibbonFontComboBox ribbonFontComboBox,  FS_INT32 nIndex,  FS_WideString* wsText))

/**
 * @brief FRRibbonFontComboBoxGetCurSel
 * @details Gets the index of the currently selected item.
 * @param[in]  ribbonFontComboBox The input ribbon font combo box.
 * @return   The index of the currently selected item.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonFontComboBoxGetCurSel, (FR_RibbonFontComboBox ribbonFontComboBox))

/**
 * @brief FRRibbonFontComboBoxSelectItem
 * @details Selects the specified item by index.
 * @param[in]  ribbonFontComboBox The input ribbon font combo box.
 * @param[in]  nItemIndex The specified index.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonFontComboBoxSelectItem, (FR_RibbonFontComboBox ribbonFontComboBox,  FS_INT32 nItemIndex))

/**
 * @brief FRRibbonFontComboBoxSetWidth
 * @details Sets the width of the ribbon font combo box.
 * @param[in]  ribbonFontComboBox The input ribbon font combo box.
 * @param[in]  nWidth The input width of the ribbon font combo box.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonFontComboBoxSetWidth, (FR_RibbonFontComboBox ribbonFontComboBox,  FS_INT32 nWidth))

/**
 * @brief FRRibbonFontComboBoxSetEditBox
 * @details Sets whether the font combo box to have edit box or not.
 * @param[in]  ribbonFontComboBox The input ribbon font combo box.
 * @param[in]  bHasEditBox TRUE if you want to set the font combo box to have edit box.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonFontComboBoxSetEditBox, (FR_RibbonFontComboBox ribbonFontComboBox,  FS_BOOL bHasEditBox))

/**
 * @brief FRRibbonFontComboBoxGetEditText
 * @details Gets the edit text of the ribbon font combo box.
 * @param[in]  ribbonFontComboBox The input ribbon font combo box.
 * @param[out]  wsText It receives the edit text.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonFontComboBoxGetEditText, (FR_RibbonFontComboBox ribbonFontComboBox,  FS_WideString* wsText))

/**
 * @brief FRRibbonFontComboBoxSetEditText
 * @details Sets the edit text of the ribbon font combo box.
 * @param[in]  ribbonFontComboBox The input ribbon font combo box.
 * @param[in]  lpwsText The input edit text.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonFontComboBoxSetEditText, (FR_RibbonFontComboBox ribbonFontComboBox,  FS_LPCWSTR lpwsText))

/**
 * @brief FRRibbonFontComboBoxEnableDropDownListResize
 * @details Sets whether the dropped down list can be resized or not.
 * @param[in]  ribbonFontComboBox The input ribbon font combo box.
 * @param[in]  bEnable <a>TRUE</a> if the dropped down list can be resized.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonFontComboBoxEnableDropDownListResize, (FR_RibbonFontComboBox ribbonFontComboBox,  FS_BOOL bEnable))

/**
 * @brief FRRibbonFontComboBoxGetHWnd
 * @details Gets the window handle of the ribbon font combo box.
 * @param[in]  ribbonFontComboBox The input ribbon font combo box.
 * @return   The window handle of the ribbon font combo box.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 * @see 
 */
INTERFACE(HWND, FRRibbonFontComboBoxGetHWnd, (FR_RibbonFontComboBox ribbonFontComboBox))

/**
 * @brief FRRibbonFontComboBoxAddFont
 * @details Adds a font into the ribbon font combo box.
 * @param[in]  ribbonFontComboBox The input ribbon font combo box.
 * @param[in]  lpwsFaceName The input font face name.
 * @param[in]  bSort Whether to sort the font name or not.
 * @param[in]  nCharSet The input charset. Sets it DEFAULT_CHARSET as default.
 * @return   The index of the font added into the ribbon font combo box.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonFontComboBoxAddFont, (FR_RibbonFontComboBox ribbonFontComboBox,  FS_LPCWSTR lpwsFaceName,  FS_BOOL bSort,  FS_BYTE nCharSet))

/**
 * @brief FRRibbonFontComboBoxInsertFont
 * @details Inserts a font into the ribbon font combo box.
 * @param[in]  ribbonFontComboBox The input ribbon font combo box.
 * @param[in]  lpwsFaceName The input font face name.
 * @param[in]  nIndex The position where the font will be inserted.
 * @param[in]  nCharSet The input charset. Sets it DEFAULT_CHARSET as default.
 * @return   The index of the font inserted into the ribbon font combo box.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonFontComboBoxInsertFont, (FR_RibbonFontComboBox ribbonFontComboBox,  FS_LPCWSTR lpwsFaceName,  FS_INT32 nIndex,  FS_BYTE nCharSet))

/**
 * @brief FRRibbonFontComboBoxGetFontIndex
 * @details Gets the index of the font.
 * @param[in]  ribbonFontComboBox The input ribbon font combo box.
 * @param[in]  lpwsFaceName The input font face name.
 * @return   The index of the font.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonFontComboBoxGetFontIndex, (FR_RibbonFontComboBox ribbonFontComboBox,  FS_LPCWSTR lpwsFaceName))

/**
 * @brief FRRibbonFontComboBoxGetFontName
 * @details Gets the font name.
 * @param[in]  ribbonFontComboBox The input ribbon font combo box.
 * @param[in]  nIndex The input font index.
 * @param[out]  outName It receives the font name.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(void, FRRibbonFontComboBoxGetFontName, (FR_RibbonFontComboBox ribbonFontComboBox,  FS_INT32 nIndex,  FS_WideString* outName))

/**
 * @brief FRRibbonFontComboBoxGetScriptName
 * @details Gets the font script name.
 * @param[in]  ribbonFontComboBox The input ribbon font combo box.
 * @param[in]  nIndex The input font index.
 * @param[out]  outName It receives the font script name.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(void, FRRibbonFontComboBoxGetScriptName, (FR_RibbonFontComboBox ribbonFontComboBox,  FS_INT32 nIndex,  FS_WideString* outName))

/**
 * @brief FRRibbonFontComboBoxSelectItem2
 * @details Selects the item by font name.
 * @param[in]  ribbonFontComboBox The input ribbon font combo box.
 * @param[in]  lpwsFaceName The input font face name.
 * @return   TRUE for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonFontComboBoxSelectItem2, (FR_RibbonFontComboBox ribbonFontComboBox,  FS_LPCWSTR lpwsFaceName))

/**
 * @brief FRRibbonFontComboBoxRemoveFont
 * @details Remove the font by font name.
 * @param[in]  ribbonFontComboBox The input ribbon font combo box.
 * @param[in]  lpwsFaceName The input font face name.
 * @return   TRUE for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonFontComboBoxRemoveFont, (FR_RibbonFontComboBox ribbonFontComboBox,  FS_LPCWSTR lpwsFaceName))

/**
 * @brief FRRibbonFontComboBoxRemoveFont2
 * @details Remove the font by font index.
 * @param[in]  ribbonFontComboBox The input ribbon font combo box.
 * @param[in]  nIndex The input font index.
 * @return   TRUE for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonFontComboBoxRemoveFont2, (FR_RibbonFontComboBox ribbonFontComboBox,  FS_INT32 nIndex))

/**
 * @brief FRRibbonFontComboBoxGetFontCount
 * @details Gets the font count of the ribbon font combo box.
 * @param[in]  ribbonFontComboBox The input ribbon font combo box.
 * @return   The font count of the ribbon font combo box.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonFontComboBoxGetFontCount, (FR_RibbonFontComboBox ribbonFontComboBox))

/**
 * @brief FRRibbonFontComboBoxSetFocus
 * @details Sets the focus to the ribbon font combo box or not.
 * @param[in]  ribbonFontComboBox The input ribbon font combo box.
 * @param[in]  bFocus Inputs TRUE to set the focus to the ribbon font combo box.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
 * @see 
 */
INTERFACE(void, FRRibbonFontComboBoxSetFocus, (FR_RibbonFontComboBox ribbonFontComboBox,  FS_BOOL bFocus))

NumOfSelector(FRRibbonFontComboBox)
ENDENUM

//*****************************
/* RibbonPaletteButton HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRRibbonPaletteButtonGetElement
 * @details Gets the ribbon element associated with the ribbon palette button. All types of buttons associate with a ribbon element.
	* The ribbon element manipulates the common properties of all types of buttons.
 * @param[in]  ribbonPaletteButton 
 * @return   The ribbon element associated with the ribbon palette button.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_RibbonElement, FRRibbonPaletteButtonGetElement, (FR_RibbonPaletteButton ribbonPaletteButton))

/**
 * @brief FRRibbonPaletteButtonAddGroup
 * @details Adds a new group of  ribbon palette button.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  name The input name of the group.
 * @param[in]  lpwsGroupTitle The input title of the group.
 * @param[in]  paletteImages The input bitmap list of the group.
 * @param[in]  nWidthForEachImage The width of each bitmap.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonAddGroup, (FR_RibbonPaletteButton ribbonPaletteButton,  const FS_CHAR* name,  FS_LPCWSTR lpwsGroupTitle,  FS_DIBitmap paletteImages,  FS_INT32 nWidthForEachImage))

/**
 * @brief FRRibbonPaletteButtonSetGroupTitle
 * @details Sets the title of the group.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  name The input name of the group.
 * @param[in]  lpwsGroupTitle The input title of the group.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonSetGroupTitle, (FR_RibbonPaletteButton ribbonPaletteButton,  const FS_CHAR* name,  FS_LPCWSTR lpwsGroupTitle))

/**
 * @brief FRRibbonPaletteButtonSetItemToolTip
 * @details Sets the tooltip of the item.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  name The input name of the group.
 * @param[in]  nItemIndex The specified index of the item.
 * @param[in]  lpwsToolTip The input tooltip of the item.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonSetItemToolTip, (FR_RibbonPaletteButton ribbonPaletteButton,  const FS_CHAR* name,  FS_INT32 nItemIndex,  FS_LPCWSTR lpwsToolTip))

/**
 * @brief FRRibbonPaletteButtonSetScrollButtonTooltip
 * @details Sets the tooltip of the scroll button.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  lpwsTooltip The input tooltip of the scroll button.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonSetScrollButtonTooltip, (FR_RibbonPaletteButton ribbonPaletteButton,  FS_LPCWSTR lpwsTooltip))

/**
 * @brief FRRibbonPaletteButtonSetMenuButtonTooltip
 * @details Sets the tooltip of the drop-down button on the palette.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  lpwsTooltip The input tooltip of the drop-down button on the palette.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonSetMenuButtonTooltip, (FR_RibbonPaletteButton ribbonPaletteButton,  FS_LPCWSTR lpwsTooltip))

/**
 * @brief FRRibbonPaletteButtonGetGroupTitle
 * @details Gets the title of the group.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  groupName The input name of the group.
 * @param[out]  wsTitle It receives the title of the group.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonGetGroupTitle, (FR_RibbonPaletteButton ribbonPaletteButton,  const FS_CHAR* groupName,  FS_WideString* wsTitle))

/**
 * @brief FRRibbonPaletteButtonGetItemToolTip
 * @details Gets the tooltip of the item.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  groupName The input name of the group.
 * @param[in]  nItemIndex The specified index of the item.
 * @param[out]  wsTooltip It receives the tooltip of the item.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonGetItemToolTip, (FR_RibbonPaletteButton ribbonPaletteButton,  const FS_CHAR* groupName,  FS_INT32 nItemIndex,  FS_WideString* wsTooltip))

/**
 * @brief FRRibbonPaletteButtonGetScrollButtonTooltip
 * @details Gets the tooltip of the scroll button.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[out]  wsTooltip It receives the tooltip of the scroll button.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonGetScrollButtonTooltip, (FR_RibbonPaletteButton ribbonPaletteButton,  FS_WideString* wsTooltip))

/**
 * @brief FRRibbonPaletteButtonGetMenuButtonTooltip
 * @details Gets the tooltip of the drop-down button on the palette.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[out]  wsTooltip It receives the tooltip of the drop-down button on the palette.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonGetMenuButtonTooltip, (FR_RibbonPaletteButton ribbonPaletteButton,  FS_WideString* wsTooltip))

/**
 * @brief FRRibbonPaletteButtonGetGroupItemCount
 * @details Gets the item count of the group.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  groupName The input name of the group.
 * @return   The item count of the group.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonPaletteButtonGetGroupItemCount, (FR_RibbonPaletteButton ribbonPaletteButton,  const FS_CHAR* groupName))

/**
 * @brief FRRibbonPaletteButtonGetGroupCount
 * @details Gets the group count.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @return   The group count.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonPaletteButtonGetGroupCount, (FR_RibbonPaletteButton ribbonPaletteButton))

/**
 * @brief FRRibbonPaletteButtonIsGroupNameExist
 * @details Checks whether the name of the group exists or not.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  groupName The input name of the group.
 * @return   <a>TRUE</a> if the name of the group exists, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonPaletteButtonIsGroupNameExist, (FR_RibbonPaletteButton ribbonPaletteButton,  const FS_CHAR* groupName))

/**
 * @brief FRRibbonPaletteButtonSetButtonMode
 * @details Whether to set the drop-down button mode or not.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  bDropDown TRUE if you want to set the drop-down button mode.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonSetButtonMode, (FR_RibbonPaletteButton ribbonPaletteButton,  FS_BOOL bDropDown))

/**
 * @brief FRRibbonPaletteButtonSetIconsInRow
 * @details Sets the count of icons in a row.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  nIconsInRow The input count of icons in a row.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonSetIconsInRow, (FR_RibbonPaletteButton ribbonPaletteButton,  FS_INT32 nIconsInRow))

/**
 * @brief FRRibbonPaletteButtonEnableResize
 * @details Sets whether the palette button can be resized or not.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  bEnable TRUE if the palette button can be resized.
 * @param[in]  bVertcalOnly TRUE if the palette button can be resized in vertical direction only.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonEnableResize, (FR_RibbonPaletteButton ribbonPaletteButton,  FS_BOOL bEnable,  FS_BOOL bVertcalOnly))

/**
 * @brief FRRibbonPaletteButtonGetSelectedItem
 * @details Gets the info of the selected item.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[out]  outGroupName It receives the group name of the selected item.
 * @param[out]  nItemIndex It receives the index of the selected item.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonGetSelectedItem, (FR_RibbonPaletteButton ribbonPaletteButton,  FS_ByteString* outGroupName,  FS_INT32* nItemIndex))

/**
 * @brief FRRibbonPaletteButtonInsertItemToGroupLast
 * @details Inserts a new item to the existing group. If the group does not exist, it will be created.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  groupName The specified group name.
 * @param[in]  lpwsGroupTitle The input group title if the group name does not exist.
 * @param[in]  pBitmap The input bitmap list of the group.
 * @param[in]  cxPaletteImage The width of each bitmap.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonInsertItemToGroupLast, (FR_RibbonPaletteButton ribbonPaletteButton,  const FS_CHAR* groupName,  FS_LPCWSTR lpwsGroupTitle,  FS_DIBitmap pBitmap,  FS_INT32 cxPaletteImage))

/**
 * @brief FRRibbonPaletteButtonSetDefaultGroup
 * @details Sets the default group.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  pBitmap The input bitmap list of the default group.
 * @param[in]  cxPaletteImage The width of each bitmap.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonSetDefaultGroup, (FR_RibbonPaletteButton ribbonPaletteButton,  FS_DIBitmap pBitmap,  FS_INT32 cxPaletteImage))

/**
 * @brief FRRibbonPaletteButtonRemoveGroup
 * @details Removes the specified group.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  groupName The specified name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonRemoveGroup, (FR_RibbonPaletteButton ribbonPaletteButton,  const FS_CHAR* groupName))

/**
 * @brief FRRibbonPaletteButtonRemoveItemFromGroup
 * @details Removes the specified item from the group.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  groupName The specified group name.
 * @param[in]  nIndex The specified index of the item.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonRemoveItemFromGroup, (FR_RibbonPaletteButton ribbonPaletteButton,  const FS_CHAR* groupName,  FS_INT32 nIndex))

/**
 * @brief FRRibbonPaletteButtonSetItemData
 * @details Sets the item data.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  groupName The specified group name.
 * @param[in]  nIndex The specified index of the item.
 * @param[in]  dwData The input item data.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonSetItemData, (FR_RibbonPaletteButton ribbonPaletteButton,  const FS_CHAR* groupName,  FS_INT32 nIndex,  FS_DWORD dwData))

/**
 * @brief FRRibbonPaletteButtonGetItemData
 * @details Gets the item data.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  groupName The specified group name.
 * @param[in]  nIndex The specified index of the item.
 * @return   The item data.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_DWORD, FRRibbonPaletteButtonGetItemData, (FR_RibbonPaletteButton ribbonPaletteButton,  const FS_CHAR* groupName,  FS_INT32 nIndex))

/**
 * @brief FRRibbonPaletteButtonSetGroupItemEnable
 * @details Enables the item or not.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  groupName The specified group name.
 * @param[in]  nIndex The specified index of the item.
 * @param[in]  bEnable Sets TRUE to enable the item, otherwise FALSE.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonSetGroupItemEnable, (FR_RibbonPaletteButton ribbonPaletteButton,  const FS_CHAR* groupName,  FS_INT32 nIndex,  FS_BOOL bEnable))

/**
 * @brief FRRibbonPaletteButtonSetSelectedItem
 * @details Sets the selected item.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  csGroupName The specified group name.
 * @param[in]  nItemIndex The specified index of the item.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonSetSelectedItem, (FR_RibbonPaletteButton ribbonPaletteButton,  const FS_CHAR* csGroupName,  FS_INT32 nItemIndex))

/**
 * @brief FRRibbonPaletteButtonSetRows
 * @details Sets the rows.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  nRows The input rows.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonSetRows, (FR_RibbonPaletteButton ribbonPaletteButton,  FS_INT32 nRows))

/**
 * @brief FRRibbonPaletteButtonRemoveAllGroup
 * @details Removes all the groups.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonRemoveAllGroup, (FR_RibbonPaletteButton ribbonPaletteButton))

/**
 * @brief FRRibbonPaletteButtonSetInitSize
 * @details Sets the init size.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  cx The width in x-coordinate.
 * @param[in]  cy The height in y-coordinate.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonSetInitSize, (FR_RibbonPaletteButton ribbonPaletteButton,  FS_INT32 cx,  FS_INT32 cy))

/**
 * @brief FRRibbonPaletteButtonGetItemInfo
 * @details Gets the item info in the group.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  nIndex The input index of the the item.
 * @param[out]  outGroupName It receives the name of the group that the item belongs to.
 * @param[out]  outItemIndex It receives the index in the group that the item belongs to.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonGetItemInfo, (FR_RibbonPaletteButton ribbonPaletteButton,  FS_INT32 nIndex,  FS_ByteString* outGroupName,  FS_INT32* outItemIndex))

/**
 * @brief FRRibbonPaletteButtonSetHighlightItemProc
 * @details Sets the callback invoked when the item is highlight.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  proc The callback invoked when the item is highlight.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonSetHighlightItemProc, (FR_RibbonPaletteButton ribbonPaletteButton,  FRRibbonPaletteButtonHighlightItemProc proc))

/**
 * @brief FRRibbonPaletteButtonSetItemAccNameTitle
 * @details Sets the callback invoked when the item is highlight.
 * @param[in]  ribbonPaletteButton The input ribbon palette button object.
 * @param[in]  bsGroupName The name of the group that the item belongs to.
 * @param[in]  nIndex The index in the group that the item belongs to.
 * @param[in]  wsAccName The name provided to the Third party reading tool
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1.0.0
 * @see 
 */
INTERFACE(void, FRRibbonPaletteButtonSetItemAccNameTitle, (FR_RibbonPaletteButton ribbonPaletteButton,  FS_ByteString bsGroupName,  FS_INT32 nIndex,  FS_WideString wsAccName))

NumOfSelector(FRRibbonPaletteButton)
ENDENUM

//*****************************
/* RibbonColorButton HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRRibbonColorButtonGetElement
 * @details Gets the ribbon element associated with the ribbon color button. All types of buttons associate with a ribbon element.
	* The ribbon element manipulates the common properties of all types of buttons.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @return   The ribbon element associated with the ribbon color button.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_RibbonElement, FRRibbonColorButtonGetElement, (FR_RibbonColorButton ribbonColorButton))

/**
 * @brief FRRibbonColorButtonEnableAutomaticButton
 * @details Enables the automatic button or not.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @param[in]  lpwsLabel The input label of the automatic button.
 * @param[in]  colorAutomatic The input automatic color.
 * @param[in]  bEnable Sets TRUE to enable the automatic button.
 * @param[in]  lpwsToolTip The input tooltip of the automatic button.
 * @param[in]  bOnTop Sets TRUE to set the automatic button on the top.
 * @param[in]  bDrawBorder Sets TRUE to draw the border.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonColorButtonEnableAutomaticButton, (FR_RibbonColorButton ribbonColorButton,  FS_LPCWSTR lpwsLabel,  FS_COLORREF colorAutomatic,  FS_BOOL bEnable,  FS_LPCWSTR lpwsToolTip,  FS_BOOL bOnTop,  FS_BOOL bDrawBorder))

/**
 * @brief FRRibbonColorButtonSetAutomaticButtonLabel
 * @details Sets the label of the automatic button.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @param[in]  lpwsLabel The input label of the automatic button.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonColorButtonSetAutomaticButtonLabel, (FR_RibbonColorButton ribbonColorButton,  FS_LPCWSTR lpwsLabel))

/**
 * @brief FRRibbonColorButtonSetAutomaticButtonToolTip
 * @details Sets the tooltip of the automatic button.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @param[in]  lpwsToolTip The input tooltip of the automatic button.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonColorButtonSetAutomaticButtonToolTip, (FR_RibbonColorButton ribbonColorButton,  FS_LPCWSTR lpwsToolTip))

/**
 * @brief FRRibbonColorButtonEnableOtherButton
 * @details Enables the button to select other color.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @param[in]  lpwsLabel The input label.
 * @param[in]  lpwsToolTip The input tooltip.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonColorButtonEnableOtherButton, (FR_RibbonColorButton ribbonColorButton,  FS_LPCWSTR lpwsLabel,  FS_LPCWSTR lpwsToolTip))

/**
 * @brief FRRibbonColorButtonSetOtherButtonLabel
 * @details Sets the label of the button used to select other color.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @param[in]  lpwsLabel The input label.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonColorButtonSetOtherButtonLabel, (FR_RibbonColorButton ribbonColorButton,  FS_LPCWSTR lpwsLabel))

/**
 * @brief FRRibbonColorButtonSetOtherButtonToolTip
 * @details Sets the tooltip of the button used to select other color.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @param[in]  lpwsToolTip The input tooltip.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonColorButtonSetOtherButtonToolTip, (FR_RibbonColorButton ribbonColorButton,  FS_LPCWSTR lpwsToolTip))

/**
 * @brief FRRibbonColorButtonGetAutomaticButtonLabel
 * @details Gets the label of the automatic button.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @param[out]  wsLabel It receives the label of the automatic button.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonColorButtonGetAutomaticButtonLabel, (FR_RibbonColorButton ribbonColorButton,  FS_WideString* wsLabel))

/**
 * @brief FRRibbonColorButtonGetAutomaticButtonToolTip
 * @details Gets the tooltip of the automatic button.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @param[out]  wsTooltip It receives the tooltip of the automatic button.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonColorButtonGetAutomaticButtonToolTip, (FR_RibbonColorButton ribbonColorButton,  FS_WideString* wsTooltip))

/**
 * @brief FRRibbonColorButtonGetOtherButtonLabel
 * @details Gets the label of the button use to select other color.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @param[out]  wsLabel It receives the label of the button.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonColorButtonGetOtherButtonLabel, (FR_RibbonColorButton ribbonColorButton,  FS_WideString* wsLabel))

/**
 * @brief FRRibbonColorButtonGetOtherButtonToolTip
 * @details Gets the tooltip of the button use to select other color.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @param[out]  wsTooltip It receives the tooltip of the button.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonColorButtonGetOtherButtonToolTip, (FR_RibbonColorButton ribbonColorButton,  FS_WideString* wsTooltip))

/**
 * @brief FRRibbonColorButtonAddColorsGroup
 * @details Adds a new group of colors.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @param[in]  name The name of the group.
 * @param[in]  lpwsLabel The label of the group.
 * @param[in]  colors The specified colors of the group.
 * @param[in]  nColorCount The count of the colors.
 * @param[in]  bContiguousColumns Sets TRUE if the columns are continuous.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonColorButtonAddColorsGroup, (FR_RibbonColorButton ribbonColorButton,  const FS_CHAR* name,  FS_LPCWSTR lpwsLabel,  FS_COLORREF* colors,  FS_INT32 nColorCount,  FS_BOOL bContiguousColumns))

/**
 * @brief FRRibbonColorButtonAddStandardColor
 * @details Adds the group of the standard colors.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @param[in]  name The name of the group.
 * @param[in]  lpwsLabel The label of the group.
 * @param[in]  bContiguousColumns Sets TRUE if the columns are continuous.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonColorButtonAddStandardColor, (FR_RibbonColorButton ribbonColorButton,  const FS_CHAR* name,  FS_LPCWSTR lpwsLabel,  FS_BOOL bContiguousColumns))

/**
 * @brief FRRibbonColorButtonAddAdditionalColor
 * @details Adds the group of the additional colors.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @param[in]  name The name of the group.
 * @param[in]  lpwsLabel The label of the group.
 * @param[in]  bContiguousColumns Sets TRUE if the columns are continuous.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonColorButtonAddAdditionalColor, (FR_RibbonColorButton ribbonColorButton,  const FS_CHAR* name,  FS_LPCWSTR lpwsLabel,  FS_BOOL bContiguousColumns))

/**
 * @brief FRRibbonColorButtonAddMainColor
 * @details Adds the group of the main colors.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @param[in]  name The name of the group.
 * @param[in]  lpwsLabel The label of the group.
 * @param[in]  bContiguousColumns Sets TRUE if the columns are continuous.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonColorButtonAddMainColor, (FR_RibbonColorButton ribbonColorButton,  const FS_CHAR* name,  FS_LPCWSTR lpwsLabel,  FS_BOOL bContiguousColumns))

/**
 * @brief FRRibbonColorButtonSetGroupLabel
 * @details Sets the group label.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @param[in]  name The name of the group.
 * @param[in]  lpwsLabel The input label of the group.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonColorButtonSetGroupLabel, (FR_RibbonColorButton ribbonColorButton,  const FS_CHAR* name,  FS_LPCWSTR lpwsLabel))

/**
 * @brief FRRibbonColorButtonGetGroupLabel
 * @details Gets the label of the group.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @param[in]  name The name of the group.
 * @param[out]  wsLabel It receives the label of the group.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonColorButtonGetGroupLabel, (FR_RibbonColorButton ribbonColorButton,  const FS_CHAR* name,  FS_WideString* wsLabel))

/**
 * @brief FRRibbonColorButtonSetColor
 * @details Sets the selected color of the ribbon color button.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @param[in]  color The input color.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonColorButtonSetColor, (FR_RibbonColorButton ribbonColorButton,  FS_COLORREF color))

/**
 * @brief FRRibbonColorButtonGetColor
 * @details Gets the selected color of the ribbon color button.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @return   The color.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_COLORREF, FRRibbonColorButtonGetColor, (FR_RibbonColorButton ribbonColorButton))

/**
 * @brief FRRibbonColorButtonSetColumns
 * @details Sets the column numbers.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @param[in]  nColumns The input column numbers.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonColorButtonSetColumns, (FR_RibbonColorButton ribbonColorButton,  FS_INT32 nColumns))

/**
 * @brief FRRibbonColorButtonSetColorBoxSize
 * @details Sets the size of the color box.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @param[in]  nWidth The input width. The default value is 22.
 * @param[in]  nHeight The input height. The default value is 22.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonColorButtonSetColorBoxSize, (FR_RibbonColorButton ribbonColorButton,  FS_INT32 nWidth,  FS_INT32 nHeight))

/**
 * @brief FRRibbonColorButtonSetDefaultCommand
 * @details When the button has the drop-down style, sets <param>bDefaultCommand</param> as <a>TRUE</a> if you wan to both click the button 
	* to execute and drop down the button, sets <param>bDefaultCommand</param> as <a>FALSE</a> if you just want to drop down the button.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @param[in]  bDefaultCommand When the button has the drop-down style, sets it as <a>TRUE</a> if you wan to both click 
	* the button to execute and drop down the button, sets it as <a>FALSE</a> if you just want to drop down the button.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonColorButtonSetDefaultCommand, (FR_RibbonColorButton ribbonColorButton,  FS_BOOL bDefaultCommand))

/**
 * @brief FRRibbonColorButtonIsAutomaticButtonClick
 * @details Checks whether the automatic button is clicked or not.
 * @param[in]  ribbonColorButton The input ribbon color button object.
 * @return   <a>TRUE</a> if the automatic button is clicked, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonColorButtonIsAutomaticButtonClick, (FR_RibbonColorButton ribbonColorButton))

NumOfSelector(FRRibbonColorButton)
ENDENUM

//*****************************
/* RibbonSlider HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRRibbonSliderGetElement
 * @details Gets the ribbon element associated with the ribbon slider. All types of buttons associate with a ribbon element.
	* The ribbon element manipulates the common properties of all types of buttons.
 * @param[in]  ribbonSlider The input ribbon slider object.
 * @return   The ribbon element associated with the ribbon slider.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_RibbonElement, FRRibbonSliderGetElement, (FR_RibbonSlider ribbonSlider))

/**
 * @brief FRRibbonSliderSetZoomButtons
 * @details Sets whether to add the zoom buttons or not.
 * @param[in]  ribbonSlider The input ribbon slider object.
 * @param[in]  bSet Sets TRUE to add the zoom buttons.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonSliderSetZoomButtons, (FR_RibbonSlider ribbonSlider,  FS_BOOL bSet))

/**
 * @brief FRRibbonSliderSetRange
 * @details Sets the range of the slider.
 * @param[in]  ribbonSlider The input ribbon slider object.
 * @param[in]  nMin The minimum value of the range.
 * @param[in]  nMax The maximum value of the range.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonSliderSetRange, (FR_RibbonSlider ribbonSlider,  FS_INT32 nMin,  FS_INT32 nMax))

/**
 * @brief FRRibbonSliderGetRangeMin
 * @details Gets the minimum value of the range.
 * @param[in]  ribbonSlider The input ribbon slider object.
 * @return   The minimum value of the range.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonSliderGetRangeMin, (FR_RibbonSlider ribbonSlider))

/**
 * @brief FRRibbonSliderGetRangeMax
 * @details Gets the maximum value of the range.
 * @param[in]  ribbonSlider The input ribbon slider object.
 * @return   The maximum value of the range.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonSliderGetRangeMax, (FR_RibbonSlider ribbonSlider))

/**
 * @brief FRRibbonSliderSetPos
 * @details Sets the position of the slider.
 * @param[in]  ribbonSlider The input ribbon slider object.
 * @param[in]  nPos The input position.
 * @param[in]  bRedraw Sets TRUE to redraw the slider, otherwise not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonSliderSetPos, (FR_RibbonSlider ribbonSlider,  FS_INT32 nPos,  FS_BOOL bRedraw))

/**
 * @brief FRRibbonSliderGetPos
 * @details Gets the position of the slider.
 * @param[in]  ribbonSlider The input ribbon slider object.
 * @return   The position of the slider.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonSliderGetPos, (FR_RibbonSlider ribbonSlider))

/**
 * @brief FRRibbonSliderSetWidth
 * @details Sets the width of the ribbon slider.
 * @param[in]  ribbonSlider The input ribbon slider object.
 * @param[in]  nWidth The input width of the ribbon slider.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonSliderSetWidth, (FR_RibbonSlider ribbonSlider,  FS_INT32 nWidth))

/**
 * @brief FRRibbonSliderSetStyle
 * @details Sets the style of the ribbon slider.
 * @param[in]  ribbonSlider The input ribbon slider object.
 * @param[in]  dwStyle The input style of the ribbon slider. References to <Italic>MFC CSliderCtrl</Italic>.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonSliderSetStyle, (FR_RibbonSlider ribbonSlider,  FS_DWORD dwStyle))

/**
 * @brief FRRibbonSliderGetMouseStatus
 * @details Gets the mouse status. -1 - none, 0 - LButtonDown, 1 - LButtonUp, 2 - LButtonDown & MouseMove.
 * @param[in]  ribbonSlider The input ribbon slider object.
 * @return   The mouse status. -1 - none, 0 - LButtonDown, 1 - LButtonUp, 2 - LButtonDown & MouseMove.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonSliderGetMouseStatus, (FR_RibbonSlider ribbonSlider))

NumOfSelector(FRRibbonSlider)
ENDENUM

//*****************************
/* RibbonListButton HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRRibbonListButtonGetElement
 * @details Gets the ribbon element associated with the ribbon list button. All types of buttons associate with a ribbon element.
	* The ribbon element manipulates the common properties of all types of buttons.
 * @param[in]  ribbonListButton The input ribbon list button object.
 * @return   The ribbon element associated with the ribbon list button.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_RibbonElement, FRRibbonListButtonGetElement, (FR_RibbonListButton ribbonListButton))

/**
 * @brief FRRibbonListButtonAddGroup
 * @details Add a new group to the ribbon list button.
 * @param[in]  ribbonListButton The input ribbon list button object.
 * @param[in]  name The input group name.
 * @param[in]  lpwsGroupTitle The input group title.
 * @param[in]  paletteImages The input bitmap list of the group.
 * @param[in]  nWidthForEachImage The width of each bitmap.
 * @param[in]  arrLabels It contains labels of all the items.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonListButtonAddGroup, (FR_RibbonListButton ribbonListButton,  const FS_CHAR* name,  FS_LPCWSTR lpwsGroupTitle,  FS_DIBitmap paletteImages,  FS_INT32 nWidthForEachImage,  FS_WideStringArray arrLabels))

/**
 * @brief FRRibbonListButtonGetGroupCount
 * @details Gets the group count of the ribbon list button.
 * @param[in]  ribbonListButton The input ribbon list button object.
 * @return   The group count of the ribbon list button.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonListButtonGetGroupCount, (FR_RibbonListButton ribbonListButton))

/**
 * @brief FRRibbonListButtonIsGroupNameExist
 * @details Checks whether the group name exists or not.
 * @param[in]  ribbonListButton The input ribbon list button object.
 * @param[in]  name The name of the group.
 * @return   <a>TRUE</a> if the group name exists, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonListButtonIsGroupNameExist, (FR_RibbonListButton ribbonListButton,  const FS_CHAR* name))

/**
 * @brief FRRibbonListButtonEnableResize
 * @details Sets whether the ribbon list button can be resized or not.
 * @param[in]  ribbonListButton The input ribbon list button object.
 * @param[in]  bEnable TRUE if the ribbon list button can be resized.
 * @param[in]  bVertcalOnly TRUE if the ribbon list button can be resized in vertical direction only.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonListButtonEnableResize, (FR_RibbonListButton ribbonListButton,  FS_BOOL bEnable,  FS_BOOL bVertcalOnly))

/**
 * @brief FRRibbonListButtonSetGroupTitle
 * @details Sets the title of the group.
 * @param[in]  ribbonListButton The input ribbon list button object.
 * @param[in]  name The name of the group.
 * @param[out]  lpwsGroupTitle It receives the title of the group.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonListButtonSetGroupTitle, (FR_RibbonListButton ribbonListButton,  const FS_CHAR* name,  FS_LPCWSTR lpwsGroupTitle))

/**
 * @brief FRRibbonListButtonSetItemToolTip
 * @details Sets the tooltip of the item.
 * @param[in]  ribbonListButton The input ribbon list button object.
 * @param[in]  name The name of the group.
 * @param[in]  nItemIndex The specified index.
 * @param[in]  lpwsToolTip The input tooltip of the item.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonListButtonSetItemToolTip, (FR_RibbonListButton ribbonListButton,  const FS_CHAR* name,  FS_INT32 nItemIndex,  FS_LPCWSTR lpwsToolTip))

/**
 * @brief FRRibbonListButtonSetItemTitle
 * @details Sets the title of the item.
 * @param[in]  ribbonListButton The input ribbon list button object.
 * @param[in]  name The name of the group.
 * @param[in]  nItemIndex The specified index.
 * @param[in]  lpwsItemTitle The input title of the item.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonListButtonSetItemTitle, (FR_RibbonListButton ribbonListButton,  const FS_CHAR* name,  FS_INT32 nItemIndex,  FS_LPCWSTR lpwsItemTitle))

/**
 * @brief FRRibbonListButtonGetGroupTitle
 * @details Gets the title of the group.
 * @param[in]  ribbonListButton The input ribbon list button object.
 * @param[in]  groupName The name of the group.
 * @param[out]  wsTitle It receives the title of the group.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonListButtonGetGroupTitle, (FR_RibbonListButton ribbonListButton,  const FS_CHAR* groupName,  FS_WideString* wsTitle))

/**
 * @brief FRRibbonListButtonGetItemToolTip
 * @details Gets the tooltip of the item.
 * @param[in]  ribbonListButton The input ribbon list button object.
 * @param[in]  groupName The name of the group.
 * @param[in]  nItemIndex The specified index of the item.
 * @param[out]  wsTooltip It receives the tooltip of the item.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonListButtonGetItemToolTip, (FR_RibbonListButton ribbonListButton,  const FS_CHAR* groupName,  FS_INT32 nItemIndex,  FS_WideString* wsTooltip))

/**
 * @brief FRRibbonListButtonGetItemTitle
 * @details Gets the title of the item.
 * @param[in]  ribbonListButton The input ribbon list button object.
 * @param[in]  groupName The name of the group.
 * @param[in]  nItemIndex The specified index of the item.
 * @param[out]  wsTitle It receives the title of the item.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonListButtonGetItemTitle, (FR_RibbonListButton ribbonListButton,  const FS_CHAR* groupName,  FS_INT32 nItemIndex,  FS_WideString* wsTitle))

/**
 * @brief FRRibbonListButtonGetItemCount
 * @details Get the item count.
 * @param[in]  ribbonListButton The input ribbon list button object.
 * @param[in]  groupName The name of the group.
 * @return   The item count.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonListButtonGetItemCount, (FR_RibbonListButton ribbonListButton,  const FS_CHAR* groupName))

/**
 * @brief FRRibbonListButtonGetSelectedItem
 * @details Gets the info of the selected item.
 * @param[in]  ribbonListButton The input ribbon list button object.
 * @param[out]  outGroupName It receives the name of the group.
 * @param[out]  nItemIndex It receives the index of the selected item.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonListButtonGetSelectedItem, (FR_RibbonListButton ribbonListButton,  FS_ByteString* outGroupName,  FS_INT32* nItemIndex))

/**
 * @brief FRRibbonListButtonSetAlignedSide
 * @details Sets the alignment type.
 * @param[in]  ribbonListButton The input ribbon list button object.
 * @param[in]  nAlignedSide The alignment type.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonListButtonSetAlignedSide, (FR_RibbonListButton ribbonListButton,  FR_RIBBON_LISTBUTTON_ALIGNEDSIDE nAlignedSide))

/**
 * @brief FRRibbonListButtonSetIconsInRow
 * @details Sets the count of icons in a row.
 * @param[in]  ribbonListButton The input ribbon list button object.
 * @param[in]  nIconsInRow The input count of icons in a row.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonListButtonSetIconsInRow, (FR_RibbonListButton ribbonListButton,  FS_INT32 nIconsInRow))

/**
 * @brief FRRibbonListButtonSetSelectedItem
 * @details Sets the selected item.
 * @param[in]  ribbonListButton The input ribbon list button object.
 * @param[in]  csGroupName The name of the group.
 * @param[in]  nItemIndex The specified index.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonListButtonSetSelectedItem, (FR_RibbonListButton ribbonListButton,  const FS_CHAR* csGroupName,  FS_INT32 nItemIndex))

NumOfSelector(FRRibbonListButton)
ENDENUM

//*****************************
/* RibbonBackStageViewItem HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRRibbonBackStageViewItemSetTitle
 * @details Sets the title of the back stage view item.
 * @param[in]  item The input back stage view item object.
 * @param[in]  lpwsTitle The input title of the back stage view item.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRRibbonBarAddBackStageViewItem
 * @see FRRibbonBarGetBackStageViewItem
 */
INTERFACE(void, FRRibbonBackStageViewItemSetTitle, (FR_RibbonBackStageViewItem item,  FS_LPCWSTR lpwsTitle))

/**
 * @brief FRRibbonBackStageViewItemAddDialog
 * @details You can create your own dialog on the back stage view when it is shown. You can either add a dialog or a property sheet on 
	* the back stage view.
 * @param[in]  item The input back stage view item object.
 * @param[in]  createProc The callback function is called to notify the plug-in to create the dialog when the back stage view is shown.
 * @param[in]  destroyProc The callback function is called to notify the plug-in to destroy the dialog when the back stage view is closed.
 * @param[in]  pClientData The user-supplied data passed to the callback function.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonBackStageViewItemAddDialog, (FR_RibbonBackStageViewItem item,  FRRibbonBackstageCreateProc createProc,  FRRibbonBackstageDestoryProc destroyProc,  void* pClientData))

/**
 * @brief FRRibbonBackStageViewItemAddPropertySheetPage
 * @details You can create your own property sheet page on the back stage view when it is shown. You can either add a dialog or a property sheet on 
	* the back stage view.
 * @param[in]  item The input back stage view item object.
 * @param[in]  lpsName The input name of the property sheet page.
 * @param[in]  lpwsPageTitle The input title of the property sheet page.
 * @param[in]  pBitmap The input bitmap of the property sheet page.
 * @param[in]  nPos The input position of the property sheet page.
 * @param[in]  createProc The callback function is called to notify the plug-in to create the dialog when the back stage view is shown.
 * @param[in]  destroyProc The callback function is called to notify the plug-in to destroy the dialog when the back stage view is closed.
 * @param[in]  pClientData The user-supplied data passed to the callback function.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonBackStageViewItemAddPropertySheetPage, (FR_RibbonBackStageViewItem item,  FS_LPCSTR lpsName,  FS_LPCWSTR lpwsPageTitle,  FS_DIBitmap pBitmap,  FS_INT32 nPos,  FRRibbonBackstageCreateProc createProc,  FRRibbonBackstageDestoryProc destroyProc,  void* pClientData))

/**
 * @brief FRRibbonBackStageViewItemRemovePropertySheetPage
 * @details Removes the specified property sheet page.
 * @param[in]  item The input back stage view item object.
 * @param[in]  lpsName The specified name of the property sheet page.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonBackStageViewItemRemovePropertySheetPage, (FR_RibbonBackStageViewItem item,  FS_LPCSTR lpsName))

/**
 * @brief FRRibbonBackStageViewItemAddPropertySheetGroup
 * @details Adds a new property sheet group.
 * @param[in]  item The input back stage view item object.
 * @param[in]  lpsName The input name of the property sheet group.
 * @param[in]  lpwsGroupTitle The input title of the property sheet group.
 * @param[in]  nPos The input position of the property sheet group.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonBackStageViewItemAddPropertySheetGroup, (FR_RibbonBackStageViewItem item,  FS_LPCSTR lpsName,  FS_LPCWSTR lpwsGroupTitle,  FS_INT32 nPos))

/**
 * @brief FRRibbonBackStageViewItemSetGroupTitle
 * @details Sets the title of the property sheet group.
 * @param[in]  item The input back stage view item object.
 * @param[in]  lpwsGroupTitle The input title of the property sheet group.
 * @param[in]  nGroupIndex The specified index.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonBackStageViewItemSetGroupTitle, (FR_RibbonBackStageViewItem item,  FS_LPCWSTR lpwsGroupTitle,  int nGroupIndex))

/**
 * @brief FRRibbonBackStageViewItemSetVisible
 * @details Sets the back stage view item to be visible or not.
 * @param[in]  item The input back stage view item object.
 * @param[in]  bVisible <a>TRUE</a> if the back stage view item is visible, otherwise not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonBackStageViewItemSetVisible, (FR_RibbonBackStageViewItem item,  FS_BOOL bVisible))

/**
 * @brief FRRibbonBackStageViewItemSetDisable
 * @details Sets the back stage view item to be disabled or not.
 * @param[in]  item The input back stage view item object.
 * @param[in]  bDisable <a>TRUE</a> if the back stage view item is disabled, otherwise not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonBackStageViewItemSetDisable, (FR_RibbonBackStageViewItem item,  FS_BOOL bDisable))

/**
 * @brief FRRibbonBackStageViewItemAddAnchor
 * @details This interface is used to adjust the control position of the dialog added on the back stage view.
 * @param[in]  hParentWnd The parent window handle of the dialog.
 * @param[in]  hWnd The window handle of the dialog.
 * @param[in]  typeMove The input movement type.
 * @param[in]  typeSize The input size type.
 * @param[in]  percMove Sets it 100,100 as default.
 * @param[in]  percSize Sets it 100,100 as default.
 * @param[in]  pParentWnd A pointer to the main frame UI parent window. It represents the <Italic>MFC CWnd*</Italic>. Sets it to NULL as default.
	* You can get the parent window through <a>FRDocGetUIParentWnd</a>.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonBackStageViewItemAddAnchor, (HWND hParentWnd,  HWND hWnd,  FRRibbonBackStageViewItemXMoveType typeMove,  FRRibbonBackStageViewItemXSizeType typeSize,  FS_DevicePoint percMove,  FS_DevicePoint percSize,  void* pParentWnd))

/**
 * @brief FRRibbonBackStageViewItemModifiedToRibbonStyleButton
 * @details Modifies the MFC controls to ribbon style button.
 * @param[in]  pWnd The pointer to the MFC control.
 * @param[in]  nID The control ID.
 * @param[in]  typeButton The specified ribbon style type.
 * @param[in]  pParentWnd A pointer to the main frame UI parent window. It represents the <Italic>MFC CWnd*</Italic>. Sets it to NULL as default.
	* You can get the parent window through <a>FRDocGetUIParentWnd</a>.
 * @return   The ribbon style button. For example, if sets <param>typeButton</param> as <a>FR_RibbonStyle_Button</a>, the returned value
	* can be converted to <a>FR_RibbonStyleButton</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void*, FRRibbonBackStageViewItemModifiedToRibbonStyleButton, (void* pWnd,  unsigned int nID,  FRRibbonStyleButtonType typeButton,  void* pParentWnd))

/**
 * @brief FRRibbonBackStageViewItemSetPropertyActivePage
 * @details Sets the active property sheet page.
 * @param[in]  item The input back stage view item object.
 * @param[in]  lpsPageName The specified name of the property sheet page.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonBackStageViewItemSetPropertyActivePage, (FR_RibbonBackStageViewItem item,  FS_LPCSTR lpsPageName))

/**
 * @brief FRRibbonBackStageViewItemSetPageTitle
 * @details Sets the title of the property sheet page.
 * @param[in]  item The input back stage view item object.
 * @param[in]  lpsPageName The specified name of the property sheet page.
 * @param[in]  lpwsTitle The input title you want to set.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.1
 * @see FRRibbonBackStageViewItemAddPropertySheetPage
 */
INTERFACE(FS_BOOL, FRRibbonBackStageViewItemSetPageTitle, (FR_RibbonBackStageViewItem item,  FS_LPCSTR lpsPageName,  FS_LPCWSTR lpwsTitle))

/**
 * @brief FRRibbonBackStageViewItemIsPropertySheetPageExist
 * @details Checks whether the property sheet page exists or not.
 * @param[in]  item The input back stage view item object.
 * @param[in]  lpsPageName The specified name of the property sheet page.
 * @return   <a>TRUE</a> means the property sheet page exists, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see FRRibbonBackStageViewItemAddPropertySheetPage
 */
INTERFACE(FS_BOOL, FRRibbonBackStageViewItemIsPropertySheetPageExist, (FR_RibbonBackStageViewItem item,  FS_LPCSTR lpsPageName))

/**
 * @brief FRRibbonBackStageViewItemIsDialogExist
 * @details Checks whether the dialog exists or not.
 * @param[in]  item The input back stage view item object.
 * @return   <a>TRUE</a> means the dialog exists, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonBackStageViewItemIsDialogExist, (FR_RibbonBackStageViewItem item))

/**
 * @brief FRRibbonBackStageViewItemGetElement
 * @details Gets the ribbon element associated with the back stage view item. All types of buttons associate with a ribbon element.
	* The ribbon element manipulates the common properties of all types of buttons.
 * @param[in]  item The input back stage view item object.
 * @return   The ribbon element associated with the back stage view item.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(FR_RibbonElement, FRRibbonBackStageViewItemGetElement, (FR_RibbonBackStageViewItem item))

/**
 * @brief FRRibbonBackStageViewItemEnablePropertyPageRemove
 * @details Sets whether the property page can be removed or not.
 * @param[in]  item The input back stage view item object.
 * @param[in]  lpsName The specified name of the property sheet page.
 * @param[in]  bEnable Whether the property page can be removed or not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(void, FRRibbonBackStageViewItemEnablePropertyPageRemove, (FR_RibbonBackStageViewItem item,  FS_LPCSTR lpsName,  FS_BOOL bEnable))

/**
 * @brief FRRibbonBackStageViewItemRedrawPropertySheet
 * @details Redraws the property sheet.
 * @param[in]  item The input back stage view item object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(void, FRRibbonBackStageViewItemRedrawPropertySheet, (FR_RibbonBackStageViewItem item))

/**
 * @brief FRRibbonBackStageViewItemSetDlgItemMaxSize
 * @details Sets the max size of the dialog item in the back stage view.
 * @param[in]  hParentWnd The parent window of the dialog item.
 * @param[in]  hWnd The window handle of the dialog item.
 * @param[in]  cx The horizon size.
 * @param[in]  cy The vertical size.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(void, FRRibbonBackStageViewItemSetDlgItemMaxSize, (HWND hParentWnd,  HWND hWnd,  FS_INT32 cx,  FS_INT32 cy))

/**
 * @brief FRRibbonBackStageViewItemSetPageSelectProc
 * @details Sets the callback function called to notify the plug-in that the specified property page is selected.
 * @param[in]  item The input back stage view item object.
 * @param[in]  lpsPageName The specified property page of the back stage view item.
 * @param[in]  selectPageProc The callback function is called to notify the plug-in that the specified property page is selected.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see 
 */
INTERFACE(void, FRRibbonBackStageViewItemSetPageSelectProc, (FR_RibbonBackStageViewItem item,  FS_LPCSTR lpsPageName,  FRRibbonBackstageSelectPageProc selectPageProc))

INTERFACE(FS_BOOL, FRRibbonBackStageViewItemBCGPreTranslateMessage, (void* pWnd,  void* pMsg))

NumOfSelector(FRRibbonBackStageViewItem)
ENDENUM

//*****************************
/* RibbonStyleButton HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRRibbonStyleButtonSetImage
 * @details Sets the icon of the ribbon style button.
 * @param[in]  button The input ribbon style button object.
 * @param[in]  pBitmap The input icon of the ribbon style button.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonStyleButtonSetImage, (FR_RibbonStyleButton button,  FS_DIBitmap pBitmap))

/**
 * @brief FRRibbonStyleButtonSetAlignStyle
 * @details Sets the alignment type of the ribbon style button.
 * @param[in]  button The input ribbon style button object.
 * @param[in]  nAlignType The input alignment type of the ribbon style button.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonStyleButtonSetAlignStyle, (FR_RibbonStyleButton button,  FRRibbonStyleTextAlignType nAlignType))

/**
 * @brief FRRibbonStyleButtonSetImageSide
 * @details Sets the icon side of the ribbon style button.
 * @param[in]  button The input ribbon style button object.
 * @param[in]  nImageSide The input icon side of the ribbon style button.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonStyleButtonSetImageSide, (FR_RibbonStyleButton button,  FRRibbonStyleImageSide nImageSide))

/**
 * @brief FRRibbonStyleButtonSetFlatStyle
 * @details Sets the flat style of the ribbon style button.
 * @param[in]  button The input ribbon style button object.
 * @param[in]  nFlatStyle The input flat style of the ribbon style button.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonStyleButtonSetFlatStyle, (FR_RibbonStyleButton button,  FRRibbonStyleFlatType nFlatStyle))

/**
 * @brief FRRibbonStyleButtonSetVertMargin
 * @details Sets the margin in the vertical direction.
 * @param[in]  button The input ribbon style button object.
 * @param[in]  nVerMargin The input margin in the vertical direction.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonStyleButtonSetVertMargin, (FR_RibbonStyleButton button,  FS_INT32 nVerMargin))

/**
 * @brief FRRibbonStyleButtonGetMFCButton
 * @details Gets the pointer to the MFC class.
 * @param[in]  button The input ribbon style button object.
 * @return   The pointer to the MFC class.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void*, FRRibbonStyleButtonGetMFCButton, (FR_RibbonStyleButton button))

/**
 * @brief FRRibbonStyleButtonRelease
 * @details Releases the ribbon style button.
 * @param[in]  button The input ribbon style button object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonStyleButtonRelease, (FR_RibbonStyleButton button))

/**
 * @brief FRRibbonStyleButtonSetImage2
 * @details Sets the icon of the ribbon style button.
 * @param[in]  button The input ribbon style button object.
 * @param[in]  pBitmap The input icon of the ribbon style button.
 * @param[in]  cx The width of the bitmap when the DPI is 100%. The default value is 32.
 * @param[in]  cy The height of the bitmap when the DPI is 100%. The default value is 32.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 * @see 
 */
INTERFACE(void, FRRibbonStyleButtonSetImage2, (FR_RibbonStyleButton button,  FS_DIBitmap pBitmap,  FS_INT32 cx,  FS_INT32 cy))

NumOfSelector(FRRibbonStyleButton)
ENDENUM

//*****************************
/* RibbonStyleListBox HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRRibbonStyleListBoxAddImage
 * @details Adds a 16*16 icon list to the ribbon style list box.
 * @param[in]  listBox The input ribbon style list box object.
 * @param[in]  bitmap The input 16*16 icon list of the ribbon style list box.
 * @return   The count of the icons.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonStyleListBoxAddImage, (FR_RibbonStyleListBox listBox,  FS_DIBitmap bitmap))

/**
 * @brief FRRibbonStyleListBoxAddString
 * @details Adds a new string item to the ribbon style list box.
 * @param[in]  listBox The input ribbon style list box object.
 * @param[in]  lpwsItem The input string separated by '\n'. For example, "Foxit Reader\nThe Best PDF Reader\nOne of the most popular PDF reader",
	* the string item will show two lines and the tooltip will be "One of the most popular PDF reader".
 * @param[in]  nImageIndex The specified index of the icon list.
 * @return   The index of the string item.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonStyleListBoxAddString, (FR_RibbonStyleListBox listBox,  FS_LPCWSTR lpwsItem,  FS_INT32 nImageIndex))

/**
 * @brief FRRibbonStyleListBoxAddCaption
 * @details Adds the  caption of the ribbon style list box.
 * @param[in]  listBox The input ribbon style list box object.
 * @param[in]  lpwsCaption The input caption of the ribbon style list box.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonStyleListBoxAddCaption, (FR_RibbonStyleListBox listBox,  FS_LPCWSTR lpwsCaption))

/**
 * @brief FRRibbonStyleListBoxDeleteString
 * @details Deletes the string item by index.
 * @param[in]  listBox The input ribbon style list box object.
 * @param[in]  nIndex The specified index.
 * @return   The index of the currently selected item.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonStyleListBoxDeleteString, (FR_RibbonStyleListBox listBox,  unsigned int nIndex))

/**
 * @brief FRRibbonStyleListBoxInsertString
 * @details Inserts a string into the ribbon style list box.
 * @param[in]  listBox The input ribbon style list box object.
 * @param[in]  nIndex Specifies the zero-based index of the position to insert the string. If this parameter is �C1, the string is added to the end of the list.
 * @param[in]  lpwsItem The input string separated by '\n'. For example, "Foxit Reader\nThe Best PDF Reader\nOne of the most popular PDF reader",
	* the string item will show two lines and the tooltip will be "One of the most popular PDF reader".
 * @param[in]  nImageIndex The specified index of the icon list.
 * @return   The zero-based index of the position at which the string was inserted.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonStyleListBoxInsertString, (FR_RibbonStyleListBox listBox,  FS_INT32 nIndex,  FS_LPCWSTR lpwsItem,  FS_INT32 nImageIndex))

/**
 * @brief FRRibbonStyleListBoxGetItemData
 * @details Gets the item data of the  ribbon style list box.
 * @param[in]  listBox The input ribbon style list box object.
 * @param[in]  nIndex The specified index.
 * @return   The item data of the  ribbon style list box.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_DWORD, FRRibbonStyleListBoxGetItemData, (FR_RibbonStyleListBox listBox,  FS_INT32 nIndex))

/**
 * @brief FRRibbonStyleListBoxSetItemData
 * @details Sets a 32-bit value associated with the specified item in a ribbon style list box.
 * @param[in]  listBox The input ribbon style list box object.
 * @param[in]  nIndex The specified index.
 * @param[in]  dwItemData The input item data.
 * @return   LB_ERR if an error occurs.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonStyleListBoxSetItemData, (FR_RibbonStyleListBox listBox,  FS_INT32 nIndex,  FS_DWORD dwItemData))

/**
 * @brief FRRibbonStyleListBoxGetMFCListBox
 * @details Gets the pointer to the MFC class.
 * @param[in]  listBox The input ribbon style list box object.
 * @return   The pointer to the MFC class.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void*, FRRibbonStyleListBoxGetMFCListBox, (FR_RibbonStyleListBox listBox))

/**
 * @brief FRRibbonStyleListBoxRelease
 * @details Releases the ribbon style list box.
 * @param[in]  listBox The input ribbon style list box object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonStyleListBoxRelease, (FR_RibbonStyleListBox listBox))

/**
 * @brief FRRibbonStyleListBoxAddImage2
 * @details Adds a 16*16 icon list to the ribbon style list box.
 * @param[in]  listBox The input ribbon style list box object.
 * @param[in]  bitmap The input 16*16 icon list of the ribbon style list box.
 * @param[in]  cx The width of the bitmap when the DPI is 100%. The default value is 32.
 * @param[in]  cy The height of the bitmap when the DPI is 100%. The default value is 32.
 * @return   The count of the icons.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonStyleListBoxAddImage2, (FR_RibbonStyleListBox listBox,  FS_DIBitmap bitmap,  FS_INT32 cx,  FS_INT32 cy))

/**
 * @brief FRRibbonStyleListBoxEnablePins
 * @details Whether to enable the pin buttons or not.
 * @param[in]  listBox The input ribbon style list box object.
 * @param[in]  bEnable TRUE means enable the pin buttons, otherwise not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(void, FRRibbonStyleListBoxEnablePins, (FR_RibbonStyleListBox listBox,  FS_BOOL bEnable))

/**
 * @brief FRRibbonStyleListBoxHasPins
 * @details Whether the ribbon style list box has pins or not.
 * @param[in]  listBox The input ribbon style list box object.
 * @return   TRUE means the ribbon style list box has pins, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonStyleListBoxHasPins, (FR_RibbonStyleListBox listBox))

/**
 * @brief FRRibbonStyleListBoxSetItemPinned
 * @details Sets the status of the pin of the specified item.
 * @param[in]  listBox The input ribbon style list box object.
 * @param[in]  nIndex The specified index of the item.
 * @param[in]  nPin The status of the pin, 0 for not pinned, 1 for pinned, 2 for not display the pin button.
 * @param[in]  bRedraw Whether to redraw the list box or not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(void, FRRibbonStyleListBoxSetItemPinned, (FR_RibbonStyleListBox listBox,  FS_INT32 nIndex,  FS_INT32 nPin,  FS_BOOL bRedraw))

/**
 * @brief FRRibbonStyleListBoxGetItemPinnedState
 * @details Gets the status of the pin of the specified item.
 * @param[in]  listBox The input ribbon style list box object.
 * @param[in]  nIndex The specified index of the item.
 * @return   The status of the pin, 0 for not pinned, 1 for pinned, 2 for not display the pin button.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(FS_INT32, FRRibbonStyleListBoxGetItemPinnedState, (FR_RibbonStyleListBox listBox,  FS_INT32 nIndex))

/**
 * @brief FRRibbonStyleListBoxIsSeparatorItem
 * @details Checks whether the item is a separator or not.
 * @param[in]  listBox The input ribbon style list box object.
 * @param[in]  nIndex The specified index of the item.
 * @return   TRUE if the item is a separator, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(FS_BOOL, FRRibbonStyleListBoxIsSeparatorItem, (FR_RibbonStyleListBox listBox,  FS_INT32 nIndex))

/**
 * @brief FRRibbonStyleListBoxRedrawList
 * @details Redraws the ribbon style list box.
 * @param[in]  listBox The input ribbon style list box object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(void, FRRibbonStyleListBoxRedrawList, (FR_RibbonStyleListBox listBox))

/**
 * @brief FRRibbonStyleListBoxSetClickItemProc
 * @details Sets the callback which is called when the item of the Ribbon style list box is clicked.
 * @param[in]  listBox The input ribbon style list box object.
 * @param[in]  proc A callback for Ribbon style list box.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(void, FRRibbonStyleListBoxSetClickItemProc, (FR_RibbonStyleListBox listBox,  FRClickItemProc proc))

/**
 * @brief FRRibbonStyleListBoxSetClickPinProc
 * @details Sets the callback which is called when the item pin button of the Ribbon style list box is clicked.
 * @param[in]  listBox The input ribbon style list box object.
 * @param[in]  proc A callback for Ribbon style list box.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(void, FRRibbonStyleListBoxSetClickPinProc, (FR_RibbonStyleListBox listBox,  FRClickPinProc proc))

/**
 * @brief FRRibbonStyleListBoxSetClientData
 * @details Sets the client data.
 * @param[in]  listBox The input ribbon style list box object.
 * @param[in]  pData The input client data.
 * @param[in]  callback The callback will be invoked to free the client data.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(void, FRRibbonStyleListBoxSetClientData, (FR_RibbonStyleListBox listBox,  void* pData,  FRFreeDataProc callback))

/**
 * @brief FRRibbonStyleListBoxClear
 * @details Clears the ribbon style list box.
 * @param[in]  listBox The input ribbon style list box object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(void, FRRibbonStyleListBoxClear, (FR_RibbonStyleListBox listBox))

NumOfSelector(FRRibbonStyleListBox)
ENDENUM

//*****************************
/* RibbonStyleStatic HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRRibbonStyleStaticSetImage
 * @details Sets the icon of the ribbon style static box.
 * @param[in]  stcObj The input ribbon style static box object.
 * @param[in]  pBitmap The input icon of the ribbon style static box.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonStyleStaticSetImage, (FR_RibbonStyleStatic stcObj,  FS_DIBitmap pBitmap))

/**
 * @brief FRRibbonStyleStaticGetMFCStatic
 * @details Gets the pointer to the corresponding MFC class.
 * @param[in]  stcObj The input ribbon style static box object.
 * @return   The pointer to the corresponding MFC class.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void*, FRRibbonStyleStaticGetMFCStatic, (FR_RibbonStyleStatic stcObj))

/**
 * @brief FRRibbonStyleStaticSetFontStyle
 * @details Sets the font and the style of the ribbon style static box.
 * @param[in]  stcObj The input ribbon style static box object.
 * @param[in]  nFontSize The input font size of the ribbon style static box.
 * @param[in]  bBold TRUE if the ribbon style static box uses the bold, otherwise not.
 * @param[in]  bItalic TRUE if the ribbon style static box uses the italic, otherwise not.
 * @param[in]  bUnderlined TRUE if the ribbon style static box is underlined, otherwise not.
 * @param[in]  bStrikethrough TRUE if the ribbon style static box is stricken through, otherwise not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonStyleStaticSetFontStyle, (FR_RibbonStyleStatic stcObj,  FS_INT32 nFontSize,  FS_BOOL bBold,  FS_BOOL bItalic,  FS_BOOL bUnderlined,  FS_BOOL bStrikethrough))

/**
 * @brief FRRibbonStyleStaticSetTextColor
 * @details Sets the color of the ribbon style static box.
 * @param[in]  stcObj The input ribbon style static box object.
 * @param[in]  dwTextColor The input color value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonStyleStaticSetTextColor, (FR_RibbonStyleStatic stcObj,  FS_DWORD dwTextColor))

/**
 * @brief FRRibbonStyleStaticSetBackgroundColor
 * @details Sets the background color of the ribbon style static box.
 * @param[in]  stcObj The input ribbon style static box object.
 * @param[in]  dwBgColor The input background color value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonStyleStaticSetBackgroundColor, (FR_RibbonStyleStatic stcObj,  FS_DWORD dwBgColor))

/**
 * @brief FRRibbonStyleStaticSetTextDrawFormat
 * @details Sets the text format of the ribbon style static box.
 * @param[in]  stcObj The input ribbon style static box object.
 * @param[in]  nFormat The input format. References to MFC description such as DT_BOTTOM.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonStyleStaticSetTextDrawFormat, (FR_RibbonStyleStatic stcObj,  unsigned int nFormat))

/**
 * @brief FRRibbonStyleStaticRelease
 * @details Releases the ribbon style static box.
 * @param[in]  stcObj The input ribbon style static box object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRRibbonStyleStaticRelease, (FR_RibbonStyleStatic stcObj))

/**
 * @brief FRRibbonStyleStaticSetImage2
 * @details Sets the icon of the ribbon style static box.
 * @param[in]  stcObj The input ribbon style static box object.
 * @param[in]  pBitmap The input icon of the ribbon style static box.
 * @param[in]  cx The width of the bitmap when the DPI is 100%. The default value is 32.
 * @param[in]  cy The height of the bitmap when the DPI is 100%. The default value is 32.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 * @see 
 */
INTERFACE(void, FRRibbonStyleStaticSetImage2, (FR_RibbonStyleStatic stcObj,  FS_DIBitmap pBitmap,  FS_INT32 cx,  FS_INT32 cy))

NumOfSelector(FRRibbonStyleStatic)
ENDENUM

//*****************************
/* FormatTools HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRFormatToolsGet
 * @details Gets the format tool object. The format tool is used to set the format of the PDF object and text. You can set the format
	* like font name, font size, color and so on.
 * @return   The format tool object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_FormatTools, FRFormatToolsGet, ())

/**
 * @brief FRFormatToolsSetEvent
 * @details Sets the callback functions that are called by Foxit Reader when the events occur.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  callbacks The callback functions. They are called by Foxit Reader when the events occur.
 * @return   The returned event handle. Releases it by <a>FRFormatToolsReleaseEvent</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void*, FRFormatToolsSetEvent, (FR_FormatTools formatTools,  FR_FormatToolCallbacks callbacks))

/**
 * @brief FRFormatToolsSetFontName
 * @details Sets the font name of the format tools.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  lpwsFontName The input font name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsSetFontName, (FR_FormatTools formatTools,  FS_LPCWSTR lpwsFontName))

/**
 * @brief FRFormatToolsSetFontNameFirst
 * @details Sets whether you set the font name the first time or not.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  bFirst Indicates whether you set the font name the first time.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsSetFontNameFirst, (FR_FormatTools formatTools,  FS_BOOL bFirst))

/**
 * @brief FRFormatToolsSetFontSize
 * @details Sets the font size of the format tools.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  flFontSize The input font size.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsSetFontSize, (FR_FormatTools formatTools,  FS_FLOAT flFontSize))

/**
 * @brief FRFormatToolsSetFontSizeFirst
 * @details Sets whether you set the font size the first time or not.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  bFirst Indicates whether you set the font size the first time.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsSetFontSizeFirst, (FR_FormatTools formatTools,  FS_BOOL bFirst))

/**
 * @brief FRFormatToolsSetTextColor
 * @details Sets the text color of the format tools.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  textColor The input color value of the text.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsSetTextColor, (FR_FormatTools formatTools,  COLORREF textColor))

/**
 * @brief FRFormatToolsSetLineColor
 * @details Sets the line color of the format tools.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  lineColor The input line color.
 * @param[in]  bTransparent Indicates whether the line is transparent.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsSetLineColor, (FR_FormatTools formatTools,  COLORREF lineColor,  FS_BOOL bTransparent))

/**
 * @brief FRFormatToolsSetFillColor
 * @details Sets the fill color of the format tools.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  fillColor The input fill color.
 * @param[in]  bTransparent Indicates whether the line is transparent.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsSetFillColor, (FR_FormatTools formatTools,  COLORREF fillColor,  FS_BOOL bTransparent))

/**
 * @brief FRFormatToolsSetBold
 * @details Sets whether uses the bold and whether the bold setting button is enabled.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  bBold Indicates whether uses the bold.
 * @param[in]  bEnabled Indicates whether the bold setting button is enabled or not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsSetBold, (FR_FormatTools formatTools,  FS_BOOL bBold,  FS_BOOL bEnabled))

/**
 * @brief FRFormatToolsSetItalic
 * @details Sets whether uses the italic and whether the italic setting button is enabled.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  bItalic Indicates whether uses the italic.
 * @param[in]  bEnabled Indicates whether the italic setting button is enabled or not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsSetItalic, (FR_FormatTools formatTools,  FS_BOOL bItalic,  FS_BOOL bEnabled))

/**
 * @brief FRFormatToolsSetAlign
 * @details Sets the alignment of the format tools.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  dwAlign The input alignment.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsSetAlign, (FR_FormatTools formatTools,  FS_DWORD dwAlign))

/**
 * @brief FRFormatToolsSetCharSpace
 * @details Sets the character space of the format tools.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  flSpace The input character space.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsSetCharSpace, (FR_FormatTools formatTools,  FS_FLOAT flSpace))

/**
 * @brief FRFormatToolsSetCharHorzScale
 * @details Sets the character horizon scale of the format tools.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  nScale The input character horizon scale.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsSetCharHorzScale, (FR_FormatTools formatTools,  FS_INT32 nScale))

/**
 * @brief FRFormatToolsSetLineLeading
 * @details Sets whether uses the leading line setting.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  flLineLeading Indicates whether uses the leading line setting.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsSetLineLeading, (FR_FormatTools formatTools,  FS_FLOAT flLineLeading))

/**
 * @brief FRFormatToolsSetSuperScript
 * @details Sets whether uses the superscript setting.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  bSuperScript Indicates whether uses the superscript setting.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsSetSuperScript, (FR_FormatTools formatTools,  FS_BOOL bSuperScript))

/**
 * @brief FRFormatToolsSetSubScript
 * @details Sets whether uses the subscript setting.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  bSubScript Indicates whether uses the subscript setting.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsSetSubScript, (FR_FormatTools formatTools,  FS_BOOL bSubScript))

/**
 * @brief FRFormatToolsSetUnderline
 * @details Sets whether uses the underline setting.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  bUnderline Indicates whether uses the underline setting.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsSetUnderline, (FR_FormatTools formatTools,  FS_BOOL bUnderline))

/**
 * @brief FRFormatToolsSetCross
 * @details Sets whether uses the cross setting.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  bCross Indicates whether uses the cross setting.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsSetCross, (FR_FormatTools formatTools,  FS_BOOL bCross))

/**
 * @brief FRFormatToolsSetWordSpace
 * @details Sets the word space of the format tools.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  fWordSpace Indicates whether uses the word space setting.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsSetWordSpace, (FR_FormatTools formatTools,  FS_FLOAT fWordSpace))

/**
 * @brief FRFormatToolsGetFontName
 * @details Gets the font name of the format tools.
 * @param[in]  formatTools The input format tools object.
 * @param[out]  outFontName It receives the font name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsGetFontName, (FR_FormatTools formatTools,  FS_WideString* outFontName))

/**
 * @brief FRFormatToolsGetFontSize
 * @details Gets the font size of the format fools.
 * @param[in]  formatTools The input format tools object.
 * @return   The font size.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_FLOAT, FRFormatToolsGetFontSize, (FR_FormatTools formatTools))

/**
 * @brief FRFormatToolsGetTextColor
 * @details Gets the text color of the format tools.
 * @param[in]  formatTools The input format tools object.
 * @param[out]  outTextColor It receives the text color.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRFormatToolsGetTextColor, (FR_FormatTools formatTools,  COLORREF* outTextColor))

/**
 * @brief FRFormatToolsGetLineColor
 * @details Gets the line color of the format tools.
 * @param[in]  formatTools The input format tools object.
 * @param[out]  outLineColor It receives the line color.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRFormatToolsGetLineColor, (FR_FormatTools formatTools,  COLORREF* outLineColor))

/**
 * @brief FRFormatToolsGetFillColor
 * @details Gets fill color of the format tools.
 * @param[in]  formatTools The input format tools object.
 * @param[out]  outFillColor It receives the fill color.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRFormatToolsGetFillColor, (FR_FormatTools formatTools,  COLORREF* outFillColor))

/**
 * @brief FRFormatToolsGetAlign
 * @details Gets the alignment of the format tools.
 * @param[in]  formatTools The input format tools object.
 * @return   The alignment of the format tools.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_DWORD, FRFormatToolsGetAlign, (FR_FormatTools formatTools))

/**
 * @brief FRFormatToolsGetCharSpace
 * @details Gets the character space of the format tools.
 * @param[in]  formatTools The input format tools object.
 * @return   The character space of the format tools.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_FLOAT, FRFormatToolsGetCharSpace, (FR_FormatTools formatTools))

/**
 * @brief FRFormatToolsGetCharHorzScale
 * @details Gets the character horizon scale of the format tools.
 * @param[in]  formatTools The input format tools object.
 * @return   The character horizon scale of the format tools.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRFormatToolsGetCharHorzScale, (FR_FormatTools formatTools))

/**
 * @brief FRFormatToolsGetLineLeading
 * @details Checks whether uses the leading line setting or not.
 * @param[in]  formatTools The input format tools object.
 * @return   <a>TRUE</a> if uses the leading line setting, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_FLOAT, FRFormatToolsGetLineLeading, (FR_FormatTools formatTools))

/**
 * @brief FRFormatToolsGetUnderline
 * @details Checks whether uses the underline line setting or not.
 * @param[in]  formatTools The input format tools object.
 * @return   <a>TRUE</a> if uses the underline setting, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRFormatToolsGetUnderline, (FR_FormatTools formatTools))

/**
 * @brief FRFormatToolsGetCross
 * @details Checks whether uses the cross setting or not.
 * @param[in]  formatTools The input format tools object.
 * @return   <a>TRUE</a> if uses the cross setting, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRFormatToolsGetCross, (FR_FormatTools formatTools))

/**
 * @brief FRFormatToolsGetSuperScript
 * @details Checks whether uses the superscript setting or not.
 * @param[in]  formatTools The input format tools object.
 * @return   <a>TRUE</a> if uses the superscript setting, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRFormatToolsGetSuperScript, (FR_FormatTools formatTools))

/**
 * @brief FRFormatToolsGetSubScript
 * @details Checks whether uses the subscript setting or not.
 * @param[in]  formatTools The input format tools object.
 * @return   <a>TRUE</a> if uses the subscript setting, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRFormatToolsGetSubScript, (FR_FormatTools formatTools))

/**
 * @brief FRFormatToolsIsBold
 * @details Checks whether uses the bold setting or not.
 * @param[in]  formatTools The input format tools object.
 * @return   <a>TRUE</a> if uses the bold setting, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRFormatToolsIsBold, (FR_FormatTools formatTools))

/**
 * @brief FRFormatToolsIsItalic
 * @details Checks whether uses the italic setting or not.
 * @param[in]  formatTools The input format tools object.
 * @return   <a>TRUE</a> if uses the italic setting, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRFormatToolsIsItalic, (FR_FormatTools formatTools))

/**
 * @brief FRFormatToolsGetWordSpace
 * @details Gets the word space of the format tools.
 * @param[in]  formatTools The input format tools object.
 * @return   The word space.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_FLOAT, FRFormatToolsGetWordSpace, (FR_FormatTools formatTools))

/**
 * @brief FRFormatToolsIsVisibled
 * @details Checks whether the format tools are visible or not.
 * @param[in]  formatTools The input format tools object.
 * @return   <a>TRUE</a> if the format tools are visible, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRFormatToolsIsVisibled, (FR_FormatTools formatTools))

/**
 * @brief FRFormatToolsShow
 * @details Sets to show or hide the format tools.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  bShow Sets TRUE to show the format tools and sets FALSE to hide it.
 * @param[in]  eCateType Sets the type of format to be operated.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsShow, (FR_FormatTools formatTools,  FS_BOOL bShow,  FRFormatToolContextCategoryType eCateType))

/**
 * @brief FRFormatToolsIsEnabled
 * @details Checks whether the format tools is enabled or not.
 * @param[in]  formatTools The input format tools object.
 * @return   <a>TRUE</a> if the format tools is enabled, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRFormatToolsIsEnabled, (FR_FormatTools formatTools))

/**
 * @brief FRFormatToolsEnable
 * @details Sets to enable the format tools or not.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  bEnable Sets TRUE to enable the format tools, otherwise not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsEnable, (FR_FormatTools formatTools,  FS_BOOL bEnable))

/**
 * @brief FRFormatToolsIsButtonVisibled
 * @details Checks whether the specified button is visible or not.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  nID The specified ID.
 * @return   <a>TRUE</a> if the button is visible, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRFormatToolsIsButtonVisibled, (FR_FormatTools formatTools,  FS_INT32 nID))

/**
 * @brief FRFormatToolsHideButton
 * @details Sets to hide the specified ID or not.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  nID The specified ID.
 * @param[in]  bHide Sets TRUE to hide the specified ID, otherwise not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsHideButton, (FR_FormatTools formatTools,  FS_INT32 nID,  FS_BOOL bHide))

/**
 * @brief FRFormatToolsIsButtonEnabled
 * @details Checks whether the specified button is enabled or not.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  nID The specified ID.
 * @return   <a>TRUE</a> if the button is enabled, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRFormatToolsIsButtonEnabled, (FR_FormatTools formatTools,  FS_INT32 nID))

/**
 * @brief FRFormatToolsEnableButton
 * @details Sets to enable the specified button or not.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  nID The specified ID.
 * @param[in]  bEnabled Sets TRUE to enable the button, otherwise not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsEnableButton, (FR_FormatTools formatTools,  FS_INT32 nID,  FS_BOOL bEnabled))

/**
 * @brief FRFormatToolsSetOwnerFontNameArr
 * @details Sets the owner font names except for the system font name.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  array The input font name array.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsSetOwnerFontNameArr, (FR_FormatTools formatTools,  FS_WideStringArray array))

/**
 * @brief FRFormatToolsCleanOwnerFontNameArr
 * @details Cleans the owner font names.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  array The input font name array.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRFormatToolsSetOwnerFontNameArr
 */
INTERFACE(void, FRFormatToolsCleanOwnerFontNameArr, (FR_FormatTools formatTools,  FS_WideStringArray array))

/**
 * @brief FRFormatToolsFindFontName
 * @details Get the index of the specified font name.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  lpwsFontName The specified font name.
 * @return   The index of the font name.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRFormatToolsFindFontName, (FR_FormatTools formatTools,  FS_LPCWSTR lpwsFontName))

/**
 * @brief FRFormatToolsCountFontList
 * @details Gets the count of the font.
 * @param[in]  formatTools The input format tools object.
 * @return   The count of the font.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRFormatToolsCountFontList, (FR_FormatTools formatTools))

/**
 * @brief FRFormatToolsGetFontListItem
 * @details Gets the font name by index.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  nIndex The specified index.
 * @param[out]  outItemName It receives the font name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsGetFontListItem, (FR_FormatTools formatTools,  FS_INT32 nIndex,  FS_WideString* outItemName))

/**
 * @brief FRFormatToolsSetFormatContextTitle
 * @details Sets the title of the format context category. This interface is valid in ribbon mode.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  lpwsContextTitle The input title of the format context category.
 * @param[in]  eCateType Sets the type of format to be operated.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsSetFormatContextTitle, (FR_FormatTools formatTools,  FS_LPCWSTR lpwsContextTitle,  FRFormatToolContextCategoryType eCateType))

/**
 * @brief FRFormatToolsActivateFormatCategory
 * @details Activates the format context category.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  eCateType Sets the type of format to be operated.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRFormatToolsActivateFormatCategory, (FR_FormatTools formatTools,  FRFormatToolContextCategoryType eCateType))

/**
 * @brief FRFormatToolsSetWritingDirection
 * @details Sets the writing direction on the format tools.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  eDir The input writing direction.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(void, FRFormatToolsSetWritingDirection, (FR_FormatTools formatTools,  FRFormatToolWritingDirection eDir))

/**
 * @brief FRFormatToolsGetWritingDirection
 * @details Gets the writing direction on the format tools.
 * @param[in]  formatTools The input format tools object.
 * @param[out]  outDir It receives the writing direction.
 * @return   True for success, otherwise for failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(FS_BOOL, FRFormatToolsGetWritingDirection, (FR_FormatTools formatTools,  FRFormatToolWritingDirection* outDir))

/**
 * @brief FRFormatToolsGetFontFaceName
 * @details Gets the font face name of the format tools.
 * @param[in]  formatTools The input format tools object.
 * @param[in]  lpwsScriptName The input font script name.
 * @param[out]  outFontFaceName It receives the font face name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(void, FRFormatToolsGetFontFaceName, (FR_FormatTools formatTools,  FS_LPCWSTR lpwsScriptName,  FS_WideString* outFontFaceName))

/**
 * @brief FRFormatToolsReleaseEvent
 * @details Releases the event handle returned by <a>FRFormatToolsSetEvent</a>.
 * @param[in]  eventHandle The input event handle returned by <a>FRFormatToolsSetEvent</a>.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see FRFormatToolsSetEvent
 */
INTERFACE(void, FRFormatToolsReleaseEvent, (void* eventHandle))

NumOfSelector(FRFormatTools)
ENDENUM

//*****************************
/* PropertyTools HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRPropertyToolsGet
 * @details Gets the property tools. The property tools is used to set line color and opacity of the PDF object in classic mode.
 * @return   The property tools object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_PropertyTools, FRPropertyToolsGet, ())

/**
 * @brief FRPropertyToolsSetEvent
 * @details Sets the callback functions that are called by Foxit Reader when the events occur.
 * @param[in]  propertyTools The input property tools object.
 * @param[in]  callbacks The callback functions. They are called by Foxit Reader when the events occur.
 * @return   The returned value is reserved.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void*, FRPropertyToolsSetEvent, (FR_PropertyTools propertyTools,  FR_PropertyToolCallbacks callbacks))

/**
 * @brief FRPropertyToolsSetColor
 * @details Sets the color of the property tools.
 * @param[in]  propertyTools The input property tools object.
 * @param[in]  color The input color of the property tools.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRPropertyToolsSetColor, (FR_PropertyTools propertyTools,  COLORREF color))

/**
 * @brief FRPropertyToolsSetOpacity
 * @details Sets the opacity of the property tools.
 * @param[in]  propertyTools The input property tools object.
 * @param[in]  nOpacity The input opacity of the property tools.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRPropertyToolsSetOpacity, (FR_PropertyTools propertyTools,  FS_INT32 nOpacity))

/**
 * @brief FRPropertyToolsIsVisibled
 * @details Checks whether the property tools are visible or not.
 * @param[in]  propertyTools The input property tools object.
 * @return   <a>TRUE</a> if the property tools are visible, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRPropertyToolsIsVisibled, (FR_PropertyTools propertyTools))

/**
 * @brief FRPropertyToolsShow
 * @details Sets to show the property tools or not.
 * @param[in]  propertyTools The input property tools object.
 * @param[in]  bShow Indicates whether shows the property tools or not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRPropertyToolsShow, (FR_PropertyTools propertyTools,  FS_BOOL bShow))

/**
 * @brief FRPropertyToolsIsEnabled
 * @details Checks whether the property tools are enabled or not.
 * @param[in]  propertyTools The input property tools object.
 * @return   <a>TRUE</a> if the property tools are enabled.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRPropertyToolsIsEnabled, (FR_PropertyTools propertyTools))

/**
 * @brief FRPropertyToolsEnable
 * @details Sets to enable the property tools or not.
 * @param[in]  propertyTools The input property tools object.
 * @param[in]  bEnable Sets TRUE to enable the property tools, otherwise not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRPropertyToolsEnable, (FR_PropertyTools propertyTools,  FS_BOOL bEnable))

/**
 * @brief FRPropertyToolsReleaseEvent
 * @details Releases the event handle returned by <a>FRPropertyToolsSetEvent</a>.
 * @param[in]  eventHandle The input event handle returned by <a>FRPropertyToolsSetEvent</a>.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see FRPropertyToolsSetEvent
 */
INTERFACE(void, FRPropertyToolsReleaseEvent, (void* eventHandle))

NumOfSelector(FRPropertyTools)
ENDENUM

//----------_V6----------
//----------_V7----------
//*****************************
/* FuncBtn HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRFuncBtnCreate
 * @details Creates a function button object. Then invoke <a>FRFuncBtnAddToPanel</a> to show the function button.
 * @param[in]  pParentWnd The parent window passed from <a>PILoadStatusBarUI</a>.
 * @param[in]  lpsName Specifies the name of the function button.
 * @param[in]  lpwsToolTip Specifies the tooltip of the function button.
 * @param[in]  pBitmap Specifies the icon of the function button.
 * @return   A function button object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see FRFuncBtnAddToPanel
 */
INTERFACE(FR_FuncBtn, FRFuncBtnCreate, (void* pParentWnd,  FS_LPCSTR lpsName,  FS_LPCWSTR lpwsToolTip,  FS_DIBitmap pBitmap))

/**
 * @brief FRFuncBtnAddToPanel
 * @details Adds the function button to the left navigation panel bar.
 * @param[in]  pFuncBtn The input function button object.
 * @param[in]  bShowBottom Shows the function button to the bottom or not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see FRFuncBtnCreate
 */
INTERFACE(void, FRFuncBtnAddToPanel, (FR_FuncBtn pFuncBtn,  FS_BOOL bShowBottom))

/**
 * @brief FRFuncBtnGetClientData
 * @details Gets the pointer to the client data.
 * @param[in]  pFuncBtn The input function button object.
 * @return   Pointer to the client data.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(void*, FRFuncBtnGetClientData, (FR_FuncBtn pFuncBtn))

/**
 * @brief FRFuncBtnSetClientData
 * @details Sets the client data.
 * @param[in]  pFuncBtn The input function button object.
 * @param[in]  pData The input client data.
 * @param[in]  callback The callback will be invoked to free the client data.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(void, FRFuncBtnSetClientData, (FR_FuncBtn pFuncBtn,  void* pData,  FRFreeDataProc callback))

/**
 * @brief FRFuncBtnGetToolTip
 * @details Gets the tooltip of the function button.
 * @param[in]  pFuncBtn The input function button object.
 * @param[out]  outTooltip It receives the tooltip of the function button.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(void, FRFuncBtnGetToolTip, (FR_FuncBtn pFuncBtn,  FS_WideString* outTooltip))

/**
 * @brief FRFuncBtnSetToolTip
 * @details Sets the tooltip of the function button.
 * @param[in]  pFuncBtn The input function button object.
 * @param[in]  lpwsToolTip The input tooltip of the function button.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(void, FRFuncBtnSetToolTip, (FR_FuncBtn pFuncBtn,  FS_LPCWSTR lpwsToolTip))

/**
 * @brief FRFuncBtnSetName
 * @details Sets the name of the function button.
 * @param[in]  pFuncBtn The input function button object.
 * @param[in]  lpsButtonName The input name of the function button.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(void, FRFuncBtnSetName, (FR_FuncBtn pFuncBtn,  FS_LPCSTR lpsButtonName))

/**
 * @brief FRFuncBtnGetName
 * @details Gets the name of the function button.
 * @param[in]  pFuncBtn The input function button object.
 * @param[out]  outName It receives the name of the function button.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(void, FRFuncBtnGetName, (FR_FuncBtn pFuncBtn,  FS_ByteString* outName))

/**
 * @brief FRFuncBtnSetExecuteProc
 * @details Sets the callback that will be invoked when the button is clicked.
 * @param[in]  pFuncBtn The input function button object.
 * @param[in]  proc It callback will be invoked when the button is clicked.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(void, FRFuncBtnSetExecuteProc, (FR_FuncBtn pFuncBtn,  FRExecuteProc proc))

/**
 * @brief FRFuncBtnSetComputeEnabledProc
 * @details Sets a <a>FRComputeEnabledProc</a>() associated with the function button. This rountine determines whether
	* a function button can be selected.
 * @param[in]  pFuncBtn The input function button object.
 * @param[in]  proc A user-supplied procedure to call whenever Reader needs to know whether
	* a button should be enabled.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(void, FRFuncBtnSetComputeEnabledProc, (FR_FuncBtn pFuncBtn,  FRComputeEnabledProc proc))

/**
 * @brief FRFuncBtnSetComputeMarkedProc
 * @details Sets a <a>FRComputeMarkedProc</a>() associated with the function button. This rountine determines whether
	* a function button can be marked.
 * @param[in]  pFuncBtn The input function button object.
 * @param[in]  proc A user-supplied procedure to call whenever Reader needs to know whether
	* a button should be marked.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(void, FRFuncBtnSetComputeMarkedProc, (FR_FuncBtn pFuncBtn,  FRComputeMarkedProc proc))

/**
 * @brief FRFuncBtnUpdateImage
 * @details Updates the icon of the function button.
 * @param[in]  pFuncBtn The input function button object.
 * @param[in]  pBitmap The input bitmap you want to update.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(void, FRFuncBtnUpdateImage, (FR_FuncBtn pFuncBtn,  FS_DIBitmap pBitmap))

/**
 * @brief FRFuncBtnGetRect
 * @details Gets the rectangle of the function button.
 * @param[in]  pFuncBtn The input function button object.
 * @param[out]  outRt It receives the rectangle of the function button.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(void, FRFuncBtnGetRect, (FR_FuncBtn pFuncBtn,  FS_Rect* outRt))

/**
 * @brief FRFuncBtnAddToTabBand
 * @details Adds the function button to the tab band.
 * @param[in]  pFuncBtn The input function button object.
 * @param[in]  bLeft Shows the function button to the left or not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see FRFuncBtnCreate
 */
INTERFACE(void, FRFuncBtnAddToTabBand, (FR_FuncBtn pFuncBtn,  FS_BOOL bLeft))

NumOfSelector(FRFuncBtn)
ENDENUM

//*****************************
/* StatusBar HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRStatusBarAddWndEx
 * @details Adds a windows to the status bar.
 * @param[in]  pParentWnd The parent window passed from <a>PILoadStatusBarUI</a>.
 * @param[in]  callbacks The callback used to create the status bar window.
 * @param[in]  nLocation Specifies the location in the status bar.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(void, FRStatusBarAddWndEx, (void* pParentWnd,  FR_StatusBarWndExCallbacks callbacks,  FRStatusBarLocation nLocation))

/**
 * @brief FRStatusBarReset
 * @details Resets the status bar.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(void, FRStatusBarReset, ())

/**
 * @brief FRStatusBarSetZoomSliderRange
 * @details Sets the zoom slider range.
 * @param[in]  nMin The minimum value of the zoom slider range.
 * @param[in]  nMax The maximum value of the zoom slider range.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(void, FRStatusBarSetZoomSliderRange, (FS_INT32 nMin,  FS_INT32 nMax))

/**
 * @brief FRStatusBarSetZoomSliderPos
 * @details Sets the position of the zoom slider.
 * @param[in]  nPos The position of the zoom slider.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(void, FRStatusBarSetZoomSliderPos, (FS_INT32 nPos))

/**
 * @brief FRStatusBarGetZoomSliderPos
 * @details Gets the position of the zoom slider.
 * @return   The position of the zoom slider.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(FS_INT32, FRStatusBarGetZoomSliderPos, ())

/**
 * @brief FRStatusBarSetZoomPaneText
 * @details Sets the text of the zoom pane.
 * @param[in]  lpwsZoomPaneText The text of the zoom pane.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(void, FRStatusBarSetZoomPaneText, (FS_LPCWSTR lpwsZoomPaneText))

/**
 * @brief FRStatusBarSetComboBoxPageCount
 * @details Sets the page count of the page combo box.
 * @param[in]  nCount The page count of the page combo box.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(void, FRStatusBarSetComboBoxPageCount, (FS_INT32 nCount))

/**
 * @brief FRStatusBarSelectComboBoxItem
 * @details Selects the specified page combo box item.
 * @param[in]  nIndex The index of the page combo box item.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(void, FRStatusBarSelectComboBoxItem, (FS_INT32 nIndex))

/**
 * @brief FRStatusBarGetComboBoxPageIndex
 * @details Gets the page index of the page combo box.
 * @return   The page index of the page combo box.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(FS_INT32, FRStatusBarGetComboBoxPageIndex, ())

/**
 * @brief FRStatusBarGetComboBoxPageText
 * @details Gets the text of the page combo box.
 * @param[out]  outText It receives the text of the page combo box.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(void, FRStatusBarGetComboBoxPageText, (FS_WideString* outText))

/**
 * @brief FRStatusBarGetBkGroundColor
 * @details Gets the back ground color of status bar in ribbon mode.
 * @return   The back ground color of status bar.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(FS_COLORREF, FRStatusBarGetBkGroundColor, ())

/**
 * @brief FRStatusBarGetBkGroundPath
 * @details Gets the path of the back ground color picture of the status bar in classic mode.
 * @param[out]  outPath It receives the path of the back ground color picture of the status bar in classic mode.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(void, FRStatusBarGetBkGroundPath, (FS_WideString* outPath))

/**
 * @brief FRStatusBarRecalcLayout
 * @details Recalculates the layout of the status bar.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1.0.0
 */
INTERFACE(void, FRStatusBarRecalcLayout, ())

/**
 * @brief FRStatusBarSetComboBoxPageCount2
 * @details Sets the page count of the page combo box.
 * @param[in]  nCount The page count of the page combo box.
 * @param[in]  hMainframeWnd The current mainframe handle.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.4.0
 */
INTERFACE(void, FRStatusBarSetComboBoxPageCount2, (FS_INT32 nCount,  HWND hMainframeWnd))

/**
 * @brief FRStatusBarSelectComboBoxItem2
 * @details Selects the specified page combo box item.
 * @param[in]  nIndex The index of the page combo box item.
 * @param[in]  hMainframeWnd The current mainframe handle.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.4.0
 */
INTERFACE(void, FRStatusBarSelectComboBoxItem2, (FS_INT32 nIndex,  HWND hMainframeWnd))

NumOfSelector(FRStatusBar)
ENDENUM

//----------_V8----------
//----------_V9----------
//*****************************
/* BulbMsgCenter HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRBulbMsgCenterAddMessage
 * @details Adds a bulb message to the bulb message center.
 * @param[in]  frDoc The associated document of the bulb message.
 * @param[in]  pMsgInfo The input bulb message information.
 * @return   TRUE for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see 
 */
INTERFACE(FS_BOOL, FRBulbMsgCenterAddMessage, (FR_Document frDoc,  FRBULBMESSAGEINFO msgInfo))

/**
 * @brief FRBulbMsgCenterShowMessage
 * @details Shows the specified bulb message or not.
 * @param[in]  frDoc The associated document of the bulb message.
 * @param[in]  lpsMsgName The specified name of the bulb message.
 * @param[in]  bShow Whether to show the bulb message or not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see 
 */
INTERFACE(void, FRBulbMsgCenterShowMessage, (FR_Document frDoc,  FS_LPCSTR lpsMsgName,  FS_BOOL bShow))

/**
 * @brief FRBulbMsgCenterSetCheck
 * @details Whether to check the check box or not.
 * @param[in]  frDoc The associated document of the bulb message.
 * @param[in]  lpsMsgName The specified name of the bulb message.
 * @param[in]  bCheck Whether to check the check box or not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see 
 */
INTERFACE(void, FRBulbMsgCenterSetCheck, (FR_Document frDoc,  FS_LPCSTR lpsMsgName,  FS_BOOL bCheck))

/**
 * @brief FRBulbMsgCenterSetOpBtnEnable
 * @details Whether to enable the specified operation button or not.
 * @param[in]  frDoc The associated document of the bulb message.
 * @param[in]  lpsMsgName The specified name of the bulb message.
 * @param[in]  opBtnName The specified name of the operation button.
 * @param[in]  bEnable Whether to enable the specified operation button or not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see 
 */
INTERFACE(void, FRBulbMsgCenterSetOpBtnEnable, (FR_Document frDoc,  FS_LPCSTR lpsMsgName,  FS_LPCSTR opBtnName,  FS_BOOL bEnable))

/**
 * @brief FRBulbMsgCenterIsMessageExist
 * @details Checks whether the bulb message exists or not.
 * @param[in]  frDoc The associated document of the bulb message.
 * @param[in]  lpsMsgName The specified name of the bulb message.
 * @return   TRUE if the bulb message exists, otherwise FALSE.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see 
 */
INTERFACE(FS_BOOL, FRBulbMsgCenterIsMessageExist, (FR_Document frDoc,  FS_LPCSTR lpsMsgName))

/**
 * @brief FRBulbMsgCenterIsOpBtnEnable
 * @details Checks whether the operation button is enabled or not.
 * @param[in]  frDoc The associated document of the bulb message.
 * @param[in]  lpsMsgName The specified name of the bulb message.
 * @param[in]  opBtnName The specified name of the operation button.
 * @return   TRUE if the operation button is enabled, otherwise FALSE.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see 
 */
INTERFACE(FS_BOOL, FRBulbMsgCenterIsOpBtnEnable, (FR_Document frDoc,  FS_LPCSTR lpsMsgName,  FS_LPCSTR opBtnName))

/**
 * @brief FRBulbMsgCenterSetOpBtnTitle
 * @details Sets the title of the operation button.
 * @param[in]  frDoc The associated document of the bulb message.
 * @param[in]  lpsMsgName The specified name of the bulb message.
 * @param[in]  opBtnName The specified name of the operation button.
 * @param[in]  opBtnTitle The input title of the operation button.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see 
 */
INTERFACE(void, FRBulbMsgCenterSetOpBtnTitle, (FR_Document frDoc,  FS_LPCSTR lpsMsgName,  FS_LPCSTR opBtnName,  FS_LPCWSTR opBtnTitle))

/**
 * @brief FRBulbMsgCenterSetMessageContent
 * @details Sets the content of the bulb message.
 * @param[in]  frDoc The associated document of the bulb message.
 * @param[in]  lpsMsgName The specified name of the bulb message.
 * @param[in]  lpwsMsgContent The input content of the bulb message.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see 
 */
INTERFACE(void, FRBulbMsgCenterSetMessageContent, (FR_Document frDoc,  FS_LPCSTR lpsMsgName,  FS_LPCWSTR lpwsMsgContent))

/**
 * @brief FRBulbMsgCenterGetButtonRect
 * @details Gets the rectangle of the specified operation button.
 * @param[in]  frDoc The associated document of the bulb message.
 * @param[in]  lpsMsgName The specified name of the bulb message.
 * @param[in]  opBtnName The specified name of the operation button.
 * @param[out]  outRect It receives the rectangle of the specified operation button.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see 
 */
INTERFACE(void, FRBulbMsgCenterGetButtonRect, (FR_Document frDoc,  FS_LPCSTR lpsMsgName,  FS_LPCSTR opBtnName,  FS_Rect* outRect))

/**
 * @brief FRBulbMsgCenterAddMessage2
 * @details Adds a bulb message to the bulb message center.
 * @param[in]  hView The associated window of the bulb message.
 * @param[in]  pMsgInfo The input bulb message information.
 * @return   TRUE for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see 
 */
INTERFACE(FS_BOOL, FRBulbMsgCenterAddMessage2, (HWND hView,  FRBULBMESSAGEINFO msgInfo))

/**
 * @brief FRBulbMsgCenterShowMessage2
 * @details Shows the specified bulb message or not.
 * @param[in]  hView The associated window of the bulb message.
 * @param[in]  lpsMsgName The specified name of the bulb message.
 * @param[in]  bShow Whether to show the bulb message or not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see 
 */
INTERFACE(void, FRBulbMsgCenterShowMessage2, (HWND hView,  FS_LPCSTR lpsMsgName,  FS_BOOL bShow))

/**
 * @brief FRBulbMsgCenterAddMessage3
 * @details Adds a bulb message to the bulb message center.
 * @param[in]  frDoc The associated document of the bulb message.
 * @param[in]  msgInfo2 The input bulb message information.
 * @return   TRUE for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0.2
 * @see 
 */
INTERFACE(FS_BOOL, FRBulbMsgCenterAddMessage3, (FR_Document frDoc,  FRBULBMESSAGEINFO2 msgInfo2))

/**
 * @brief FRBulbMsgCenterAddMessage4
 * @details Adds a bulb message to the bulb message center.
 * @param[in]  hView The associated window of the bulb message.
 * @param[in]  msgInfo2 The input bulb message information.
 * @return   TRUE for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0.2
 * @see 
 */
INTERFACE(FS_BOOL, FRBulbMsgCenterAddMessage4, (HWND hView,  FRBULBMESSAGEINFO2 msgInfo2))

NumOfSelector(FRBulbMsgCenter)
ENDENUM

//----------_V10----------
