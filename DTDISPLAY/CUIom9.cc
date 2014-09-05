//
// README: Portions of this file are merged at file generation
// time. Edits can be made *only* in between specified code blocks, look
// for keywords <Begin user code> and <End user code>.
//
/////////////////////////////////////////////////////////////
//
// Source file for CUIom9
//
//    Created by Builder Xcessory Version 5.0.
//    Generated by Code Generator Xcessory 5.0 (05/22/98) .
//
//    This class is a user interface "component", as described
//    in "Object-Oriented Programming with C++ and OSF/Motif",
//    by Douglas Young, Prentice Hall, 1992. ISBN 0-13-630252-1
//
/////////////////////////////////////////////////////////////


// Begin user code block <file_comments>
//
// Copyright (c) 1997 Molecular Structure Corporation
//
// RESTRICTED RIGHTS NOTICE SHORT FORM (JUNE 1987)
//
// Use, reproduction, or disclosure is subject to restrictions set
// forth in Contract No. W-31-109-ENG-38 and Contract No. 
// 943072401 with the University of Chicago, Operator of
// Argonne National Laboratory.
//
// CUIom9.cc           Initial author: J.W. Pflugrath           9-Apr-1997
//    New revised Motif option menu class for use with d*TREK and dtprocess.
/*
 *
 * Copyright (C) 2014 Rigaku Americas Corporation
 *                    9009 New Trails Drive
 *                    The Woodlands, TX, USA  77381
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice(s), this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice(s), this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of the Rigaku Americas Corporation nor the 
 *      names of its contributors may be used to endorse or promote products
 *      derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL RIGAKU AMERICAS CORPORATION BE LIABLE 
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA OR PROFITS; OR BUSINESS INTERUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 *
*/

// End user code block <file_comments>

#include <X11/StringDefs.h>
#include <Xm/Form.h>
#include <Xm/RowColumn.h>
#include <Xm/PushB.h>
#include "CUIom9.h"

//
// Convenience functions from utilities file.
//
extern void RegisterBxConverters(XtAppContext);
extern XtPointer BX_CONVERT(Widget, char *, char *, int, Boolean *);
extern XtPointer BX_DOUBLE(double);
extern XtPointer BX_SINGLE(float);
extern void BX_MENU_POST(Widget, XtPointer, XEvent *, Boolean *);
extern Pixmap XPM_PIXMAP(Widget, char **);
extern void BX_SET_BACKGROUND_COLOR(Widget, ArgList, Cardinal *, Pixel);


// Begin user code block <head>
// End user code block <head>

//
// This table is used to define class resources that are placed
// in app-defaults. This table is necessary so each instance
// of this class has the proper default resource values set.
// This eliminates the need for each instance to have
// its own app-defaults values. This table must be NULL terminated.
//
#if defined(cxx_bx_compat)

Boolean CUIom9::_initAppDefaults = True;
UIAppDefault  CUIom9::_appDefaults[] = {
    {"om9", NULL, "sensitive", NULL},
    {"om9", NULL, "labelString", NULL},
    {"om9", NULL, "orientation", NULL},
    {"pb0", NULL, "sensitive", NULL},
    {"pb0", NULL, "labelString", NULL},
    {"pb1", NULL, "sensitive", NULL},
    {"pb1", NULL, "labelString", NULL},
    {"pb2", NULL, "sensitive", NULL},
    {"pb2", NULL, "labelString", NULL},
    {"pb3", NULL, "sensitive", NULL},
    {"pb3", NULL, "labelString", NULL},
    {"pb4", NULL, "sensitive", NULL},
    {"pb4", NULL, "labelString", NULL},
    {"pb5", NULL, "sensitive", NULL},
    {"pb5", NULL, "labelString", NULL},
    {"pb6", NULL, "sensitive", NULL},
    {"pb6", NULL, "labelString", NULL},
    {"pb7", NULL, "sensitive", NULL},
    {"pb7", NULL, "labelString", NULL},
    {"pb8", NULL, "sensitive", NULL},
    {"pb8", NULL, "labelString", NULL},
    {NULL, NULL, NULL, NULL}
};
#endif

// These are default resources for widgets in objects of this class
// All resources will be prepended by *<name> at instantiation,
// where <name> is the name of the specific instance, as well as the
// name of the baseWidget. These are only defaults, and may be overriden
// in a resource file by providing a more specific resource name

String  CUIom9::_defaultCUIom9Resources[] = {
        NULL
};

//
// Old style constructor, for compatibility only.
//
CUIom9::CUIom9(const char *name, Widget parent) : 
    UIComponent(name)

// Begin user code block <alt_superclass>
// End user code block <alt_superclass>
{
    
    // Begin user code block <alt_constructor>
    // End user code block <alt_constructor>
    create(parent);
}

//
// Class Constructor.
//
CUIom9::CUIom9(const char *name) : UIComponent(name)

// Begin user code block <superclass>
// End user code block <superclass>
{
    
    // Begin user code block <constructor>
  m_pcLabel           = new char [20];
  m_nNumOptions       = 9;
  m_prvCUIom9Callback = NULL;
  m_pObj              = NULL;

    // End user code block <constructor>
}


//
// Minimal Destructor. Base class destroys widgets.
//
CUIom9::~CUIom9() 
{
    
    // Begin user code block <destructor>
  if (m_pcLabel != NULL)
    {
      delete [] m_pcLabel;
      m_pcLabel = NULL;
    }
    // End user code block <destructor>
}

//
// Handle creation of all widgets in the class.
//
void CUIom9::create(Widget parent) 
{
    Cardinal ac = 0;
    Arg      args[256];
    Cardinal cdc = 0;
    Boolean  argok = False;
    //
    // Load any class-defaulted resources for this object.
    //
    setDefaultResources(parent, _defaultCUIom9Resources);
    
#if defined(cxx_bx_compat)
    //
    // Setup app-defaults fallback table if not already done.
    //
    if (_initAppDefaults)
    {
        initAppDefaults(parent, "CUIom9", _appDefaults);
        _initAppDefaults = False;
    }
    //
    // Now set the app-defaults for this instance.
    //
    setAppDefaults(parent, _appDefaults, _name, False);
#endif
    
    //
    // Register the converters for the widgets.
    //
    RegisterBxConverters(XtWidgetToApplicationContext(parent));
    XtInitializeWidgetClass((WidgetClass)xmFormWidgetClass);
    XtInitializeWidgetClass((WidgetClass)xmRowColumnWidgetClass);
    XtInitializeWidgetClass((WidgetClass)xmRowColumnWidgetClass);
    XtInitializeWidgetClass((WidgetClass)xmPushButtonWidgetClass);
    
    //
    // Create an unmanaged widget as the top of the hierarchy.
    //
    
    ac = 0;
    XtSetArg(args[ac], XmNresizePolicy, XmRESIZE_GROW); ac++;
    XtSetArg(args[ac], XmNx, 935); ac++;
    XtSetArg(args[ac], XmNy, 133); ac++;
    XtSetArg(args[ac], XmNwidth, 147); ac++;
    XtSetArg(args[ac], XmNheight, 66); ac++;
    _CUIom9 = XmCreateForm(parent,
        _name,
        args, 
        ac);
    
    _w = _CUIom9;
    //
    // Add a callback to guard against widget destruction..
    //
    installDestroyHandler();
    
    ac = 0;
    XtSetArg(args[ac], XmNx, 0); ac++;
    XtSetArg(args[ac], XmNy, 0); ac++;
    XtSetArg(args[ac], XmNwidth, 147); ac++;
    XtSetArg(args[ac], XmNheight, 66); ac++;
    _om9 = XmCreateOptionMenu(_CUIom9,
        "om9",
        args, 
        ac);
    XtManageChild(_om9);
    
    ac = 0;
    XtSetArg(args[ac], XmNx, 0); ac++;
    XtSetArg(args[ac], XmNy, 0); ac++;
    XtSetArg(args[ac], XmNwidth, 98); ac++;
    XtSetArg(args[ac], XmNheight, 247); ac++;
    _pm9 = XmCreatePulldownMenu(XtParent(_om9),
        "pm9",
        args, 
        ac);
    
    ac = 0;
    XtSetArg(args[ac], XmNuserData, 0); ac++;
    _pb0 = XmCreatePushButton(_pm9,
        "pb0",
        args, 
        ac);
    XtManageChild(_pb0);
    
    ac = 0;
    XtSetArg(args[ac], XmNuserData, 1); ac++;
    _pb1 = XmCreatePushButton(_pm9,
        "pb1",
        args, 
        ac);
    XtManageChild(_pb1);
    
    ac = 0;
    XtSetArg(args[ac], XmNuserData, 2); ac++;
    _pb2 = XmCreatePushButton(_pm9,
        "pb2",
        args, 
        ac);
    XtManageChild(_pb2);
    
    ac = 0;
    XtSetArg(args[ac], XmNuserData, 3); ac++;
    _pb3 = XmCreatePushButton(_pm9,
        "pb3",
        args, 
        ac);
    XtManageChild(_pb3);
    
    ac = 0;
    XtSetArg(args[ac], XmNuserData, 4); ac++;
    _pb4 = XmCreatePushButton(_pm9,
        "pb4",
        args, 
        ac);
    XtManageChild(_pb4);
    
    ac = 0;
    XtSetArg(args[ac], XmNuserData, 5); ac++;
    _pb5 = XmCreatePushButton(_pm9,
        "pb5",
        args, 
        ac);
    XtManageChild(_pb5);
    
    ac = 0;
    XtSetArg(args[ac], XmNuserData, 6); ac++;
    _pb6 = XmCreatePushButton(_pm9,
        "pb6",
        args, 
        ac);
    XtManageChild(_pb6);
    
    ac = 0;
    XtSetArg(args[ac], XmNuserData, 7); ac++;
    _pb7 = XmCreatePushButton(_pm9,
        "pb7",
        args, 
        ac);
    XtManageChild(_pb7);
    
    ac = 0;
    XtSetArg(args[ac], XmNuserData, 8); ac++;
    _pb8 = XmCreatePushButton(_pm9,
        "pb8",
        args, 
        ac);
    XtManageChild(_pb8);
    
    ac = 0;
    XtSetArg(args[ac], XmNsubMenuId, _pm9); ac++;
    XtSetValues(_om9, args, ac);
    ac = 0;
    XtSetArg(args[ac], XmNnavigationType, XmTAB_GROUP); ac++;
    XtSetArg(args[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
    XtSetArg(args[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
    XtSetArg(args[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
    XtSetArg(args[ac], XmNbottomAttachment, XmATTACH_FORM); ac++;
    XtSetArg(args[ac], XmNbottomOffset, 0); ac++;
    XtSetArg(args[ac], XmNleftOffset, 0); ac++;
    XtSetArg(args[ac], XmNrightOffset, 0); ac++;
    XtSetArg(args[ac], XmNtopOffset, 0); ac++;
    XtSetValues(_om9, args, ac);
    
    
    // Begin user code block <endcreate>

    m_a9pPb[0] = &_pb0;
    m_a9pPb[1] = &_pb1;
    m_a9pPb[2] = &_pb2;
    m_a9pPb[3] = &_pb3;
    m_a9pPb[4] = &_pb4;
    m_a9pPb[5] = &_pb5;
    m_a9pPb[6] = &_pb6;
    m_a9pPb[7] = &_pb7;
    m_a9pPb[8] = &_pb8;

    // Setup help stuff
    m_poXhelp = new CXhelp(_w);

    for (ac = 0; ac < 9; ac++)
      {
	_clientDataStructs = new UICallbackStruct;
	_clientDataStructs->object = this;
	_clientDataStructs->client_data = (XtPointer)ac;
	XtAddCallback(*(m_a9pPb[ac]),
		      XmNactivateCallback,
		      CUIom9::vPushCBCallback,
		      (XtPointer)_clientDataStructs);
	_clientDataStructs = new UICallbackStruct;
	_clientDataStructs->object = (UIComponent *)m_poXhelp;
	_clientDataStructs->client_data = (XtPointer) (0);
	XtAddCallback(*(m_a9pPb[ac]),
		      XmNarmCallback,
		      CXhelp::vPostOneLineCBCallback,
		      (XtPointer)_clientDataStructs);

	_clientDataStructs = new UICallbackStruct;
	_clientDataStructs->object = (UIComponent *)m_poXhelp;
	_clientDataStructs->client_data = (XtPointer) (0);
	XtAddCallback(*(m_a9pPb[ac]),
		      XmNdisarmCallback,
		      CXhelp::vUnpostOneLineCBCallback,
		      (XtPointer)_clientDataStructs);
      }


    // Try to set the startup option menu selection from the resource file
    // Use the labelString resource from the optionMenu to get the
    // initial default, then reset the labelString to blank or null

    XmString sxString;
    char    *pcString;
    XtVaGetValues(_om9, XmNlabelString, &sxString, NULL);
    XmStringGetLtoR(sxString,
#if (XmVersion >= 1002)
		    XmFONTLIST_DEFAULT_TAG,
#else
		    XmSTRING_DEFAULT_CHARSET,
#endif
		    &pcString);
    XmStringFree(sxString);
    if (NULL != pcString)
      {
	vSetLabel(pcString);     // vSetLabel works only if the string matches
	XtFree(pcString);        // so it is OK to do this
      }

    // Now reset label to empty string

    pcString = new char [1];
    *pcString = '\0';
#if (XmVersion >= 1002)
    sxString = XmStringCreateLocalized(pcString);
#else
    sxString = XmStringCreateSimple(pcString);
#endif
    XtVaSetValues(_om9, XmNlabelString, sxString, NULL);
    XmStringFree(sxString);
    delete [] pcString;

    // End user code block <endcreate>
}

//
// Classname access.
//
const char *const CUIom9::className()
{
    return ("CUIom9");
}
void
CUIom9::set_pb0_userData(XtPointer value)
{
    Arg	args[10];
    Cardinal ac = 0;
    
    XtSetArg(args[ac], XmNuserData, value); ac++;
    XtSetValues(_pb0, args, ac);
    
    // Begin user code block <set_pb0_userData(XtPointer)>
    // End user code block <set_pb0_userData(XtPointer)>
}
void
CUIom9::set_pb1_userData(XtPointer value)
{
    Arg	args[10];
    Cardinal ac = 0;
    
    XtSetArg(args[ac], XmNuserData, value); ac++;
    XtSetValues(_pb1, args, ac);
    
    // Begin user code block <set_pb1_userData(XtPointer)>
    // End user code block <set_pb1_userData(XtPointer)>
}
void
CUIom9::set_pb2_userData(XtPointer value)
{
    Arg	args[10];
    Cardinal ac = 0;
    
    XtSetArg(args[ac], XmNuserData, value); ac++;
    XtSetValues(_pb2, args, ac);
    
    // Begin user code block <set_pb2_userData(XtPointer)>
    // End user code block <set_pb2_userData(XtPointer)>
}
void
CUIom9::set_pb3_userData(XtPointer value)
{
    Arg	args[10];
    Cardinal ac = 0;
    
    XtSetArg(args[ac], XmNuserData, value); ac++;
    XtSetValues(_pb3, args, ac);
    
    // Begin user code block <set_pb3_userData(XtPointer)>
    // End user code block <set_pb3_userData(XtPointer)>
}
void
CUIom9::set_pb4_userData(XtPointer value)
{
    Arg	args[10];
    Cardinal ac = 0;
    
    XtSetArg(args[ac], XmNuserData, value); ac++;
    XtSetValues(_pb4, args, ac);
    
    // Begin user code block <set_pb4_userData(XtPointer)>
    // End user code block <set_pb4_userData(XtPointer)>
}
void
CUIom9::set_pb5_userData(XtPointer value)
{
    Arg	args[10];
    Cardinal ac = 0;
    
    XtSetArg(args[ac], XmNuserData, value); ac++;
    XtSetValues(_pb5, args, ac);
    
    // Begin user code block <set_pb5_userData(XtPointer)>
    // End user code block <set_pb5_userData(XtPointer)>
}
void
CUIom9::set_pb6_userData(XtPointer value)
{
    Arg	args[10];
    Cardinal ac = 0;
    
    XtSetArg(args[ac], XmNuserData, value); ac++;
    XtSetValues(_pb6, args, ac);
    
    // Begin user code block <set_pb6_userData(XtPointer)>
    // End user code block <set_pb6_userData(XtPointer)>
}
void
CUIom9::set_pb7_userData(XtPointer value)
{
    Arg	args[10];
    Cardinal ac = 0;
    
    XtSetArg(args[ac], XmNuserData, value); ac++;
    XtSetValues(_pb7, args, ac);
    
    // Begin user code block <set_pb7_userData(XtPointer)>
    // End user code block <set_pb7_userData(XtPointer)>
}
void
CUIom9::set_pb8_userData(XtPointer value)
{
    Arg	args[10];
    Cardinal ac = 0;
    
    XtSetArg(args[ac], XmNuserData, value); ac++;
    XtSetValues(_pb8, args, ac);
    
    // Begin user code block <set_pb8_userData(XtPointer)>
    // End user code block <set_pb8_userData(XtPointer)>
}

// Begin user code block <tail>
int
CUIom9::nGetValue(void)
{
  int nUdata;
  XtVaGetValues(_om9, XmNuserData, &nUdata, NULL);
  return (nUdata);
}

const char *const 
CUIom9::pcGetLabel(void)
{
  // Get the label on the option menu and thereby its setting

  XmString sxString;
  char    *pcString;

  XtVaGetValues(XmOptionButtonGadget(_om9), 
		XmNlabelString, &sxString, NULL);
  XmStringGetLtoR(sxString,
#if (XmVersion >= 1002)
		  XmFONTLIST_DEFAULT_TAG,
#else
		  XmSTRING_DEFAULT_CHARSET,
#endif
		  &pcString);
  XmStringFree(sxString);

  delete [] m_pcLabel;
  m_pcLabel = new char [strlen(pcString)+1];
  strcpy(m_pcLabel, pcString);
  m_pcLabel[strlen(pcString)] = '\0';
  XtFree(pcString);
  return(m_pcLabel);
}

void
CUIom9::vSetValue(const int nValue, char *pcNewColor)
{
  Pixel hBackground;

  if ( (nValue >= 0) && (nValue < m_nNumOptions) && (nValue < 9) )
    {
      XtVaSetValues(_om9, XmNmenuHistory, *(m_a9pPb[nValue]),
		          XmNuserData, nValue, NULL);

      // Get color of pushbutton which has that value

      XtVaGetValues(*(m_a9pPb[nValue]), XmNbackground, &hBackground, NULL);
    }

  if (NULL != pcNewColor)
    {
      Boolean argok;

      if ('?' == *pcNewColor)   // Flag to set to background of parent
	XtVaGetValues(XtParent(_om9), XmNbackground, &hBackground, NULL);
      else
	hBackground = (Pixel)BX_CONVERT(_om9, pcNewColor, XmRPixel, 0, &argok);
      
      if (argok)
	{
#if (XmVersion >= 1002)
	  XmChangeColor(_om9, hBackground);
#else
	  XtVaSetValues(_om9, XmNbackground, hBackground, NULL);
#endif
	}
    }
  else
    {
#if (XmVersion >= 1002)
      XmChangeColor(_om9, hBackground);
#else
      XtVaSetValues(_om9, XmNbackground, hBackground, NULL);
#endif
    }
}

void
CUIom9::vSetLabel(const char *pcNewLabel, char *pcNewColor)
{
  // Set the label of the option menu to the one that matches the input

  int i      = 0;
  int nMatch = 1;
  
  XmString sxString;
  char    *pcString;

  if (NULL != pcNewLabel)
    {
      while ( (i < m_nNumOptions) && (nMatch != 0) )
	{
	  XtVaGetValues(*(m_a9pPb[i]), XmNlabelString, &sxString, NULL);
	  XmStringGetLtoR(sxString,
#if (XmVersion >= 1002)
			  XmFONTLIST_DEFAULT_TAG,
#else
                          XmSTRING_DEFAULT_CHARSET,
#endif
			  &pcString);
	  XmStringFree(sxString);
	  nMatch = strcmp(pcNewLabel, pcString);
	  if (0 == nMatch)
	    {
	      // Found a match
	  
	      delete [] m_pcLabel;
	      m_pcLabel = new char [strlen(pcString)+1];
	      strcpy(m_pcLabel, pcString);
	      m_pcLabel[strlen(pcString)] = '\0';
	      vSetValue(i);
	    }
	  XtFree(pcString);
	  i++;
	}
    }

  if (NULL != pcNewColor)
    {
      Pixel hBackground;
      Boolean argok;

      if ('?' == *pcNewColor)   // Flag to set to background of parent
	XtVaGetValues(XtParent(_om9), XmNbackground, &hBackground, NULL);
      else
	hBackground = (Pixel)BX_CONVERT(_om9, (char *) pcNewColor, 
				     XmRPixel, 0, &argok);
      
      if (argok)
	{
#if (XmVersion >= 1002)
	  XmChangeColor(_om9, hBackground);
#else
	  XtVaSetValues(_om9, XmNbackground, hBackground, NULL);
#endif
	}
    }
}

void CUIom9::vPushCBCallback(Widget w, 
		XtPointer clientData, XtPointer callData)
{
    UICallbackStruct *data = (UICallbackStruct *) clientData;
    CUIom9 *obj = (CUIom9 *)data->object;
    obj->vPushCB(w, data->client_data, callData);
}

void CUIom9::vPushCB(Widget w, XtPointer clientData, XtPointer callData)
{
  XtVaSetValues(_om9, XmNuserData, clientData, NULL);

  // Get background color of pushbutton and set om9 color to it

  Pixel hBackground;
  Boolean argok;
  XtVaGetValues(w, XmNbackground, &hBackground, NULL);
#if (XmVersion >= 1002)
  XmChangeColor(_om9, hBackground);
#else
  XtVaSetValues(_om9, XmNbackground, hBackground, NULL);
#endif
  if (NULL != m_prvCUIom9Callback)
    {
      m_prvCUIom9Callback(m_pObj, baseWidget(), (XtPointer)clientData, callData);
    }
}

void CUIom9::vScanUnmanage(void)
{
  int i;
  XmString sxLabel;
  char    *pcLabel;
  XtPointer pnUdata;

  // cout << "Scan-Unmanaging..." << flush;
  for (i = 0; i < 9; i++)
    {
      if (NULL != m_a9pPb[i])
	{
	  XtVaGetValues(*m_a9pPb[i], XmNlabelString, &sxLabel,
			XmNuserData, &pnUdata, NULL);
	  XmStringGetLtoR(sxLabel,
#if (XmVersion >= 1002)
			  XmFONTLIST_DEFAULT_TAG,
#else
			  XmSTRING_DEFAULT_CHARSET,
#endif
			  &pcLabel);
	  XmStringFree(sxLabel);

	  if (   ((Cstring)"" == (Cstring)pcLabel)
	      || (9 < (long)pnUdata) )
	    {
	      XtUnmanageChild(*m_a9pPb[i]);
	      // cout << i << ".." << flush;
	    }
	  if (NULL != pcLabel)
	    XtFree(pcLabel);
	}
    }
  // cout << endl;
}

void
CUIom9::vSetButtonLabel(const int nButton, char *pcNewLabel)
{
  if ((0 <= nButton) && (9 > nButton))
    {
      if (NULL != pcNewLabel)
	{
	  XmString sxLabel;

	  sxLabel = XmStringCreateLtoR(pcNewLabel,
#if (XmVersion >= 1002)
				       XmFONTLIST_DEFAULT_TAG
#else
				       XmSTRING_DEFAULT_CHARSET
#endif
				       );
	  XtVaSetValues(*m_a9pPb[nButton], XmNlabelString, sxLabel, NULL);
      
	  XmStringFree(sxLabel);
	}
    }
}
  
char *
CUIom9::pcGetButtonLabel(const int nButton)
{
  if ((0 <= nButton) && (9 > nButton))
    {
      XmString sxLabel;
      char    *pcLabel;
      
      XtVaGetValues(*m_a9pPb[nButton], XmNlabelString, &sxLabel, NULL);
      XmStringGetLtoR(sxLabel,
#if (XmVersion >= 1002)
		      XmFONTLIST_DEFAULT_TAG,
#else
		      XmSTRING_DEFAULT_CHARSET,
#endif
		      &pcLabel);
      XmStringFree(sxLabel);
      
      return (pcLabel);
    }
  else
    {
      return (NULL);
    }
}

void
CUIom9::vButtonSetSensitive(const int nButton, const Boolean bSensitive)
{
  XtVaSetValues(*m_a9pPb[nButton], XtNsensitive, bSensitive, NULL);
}

Boolean
CUIom9::bButtonGetSensitive(const int nButton)
{
  Boolean bValue;

  XtVaGetValues(*m_a9pPb[nButton], XtNsensitive, &bValue, NULL);

  return (bValue);
}


// End user code block <tail>
