/************************************************************************
    filename:   FalModule.h
    created:    Wed Jun 22 2005
    author:     Paul D Turner <paul@cegui.org.uk>
*************************************************************************/
/*************************************************************************
    Crazy Eddie's GUI System (http://www.cegui.org.uk)
    Copyright (C)2004 - 2005 Paul D Turner (paul@cegui.org.uk)
 
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.
 
    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.
 
    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*************************************************************************/
#ifndef _FalModule_h_
#define _FalModule_h_

/*************************************************************************
    Import / Export control macros
*************************************************************************/
#if defined( __WIN32__ ) || defined( _WIN32 )
#   ifdef FALAGARDWRBASE_EXPORTS
#       define FALAGARDBASE_API __declspec(dllexport)
#       define CEGUIWRMODULE_EXPORTS
#   else
#       define FALAGARDBASE_API __declspec(dllimport)
#   endif
#else
#   define FALAGARDBASE_API
#endif

#include "CEGUIWindowRendererModule.h"

CEGUI_DECLARE_WR_MODULE( Falagard )

#endif  // end of guard _FalModule_h_
