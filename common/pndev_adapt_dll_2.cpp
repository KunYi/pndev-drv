/*****************************************************************************/
/*  Copyright (C) 2018 Siemens Aktiengesellschaft                            */
/*****************************************************************************/
/* This program is free software; you can redistribute it and/or modify      */
/* it under the terms of the GNU General Public License as published by      */
/* the Free Software Foundation; version 2.                                  */
/*                                                                           */
/* This program is distributed in the hope that it will be useful,           */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of            */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             */
/* GNU General Public License for more details.                              */
/*                                                                           */
/* You should have received a copy of the GNU General Public License along   */
/* with this program; if not, write to the Free Software Foundation, Inc.,   */
/* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.               */
/*                                                                           */
/* SPDX-License-Identifier: GPL-2.0                                          */
/*                                                                           */
/*****************************************************************************/
/*                                                                           */
/*  P r o j e c t         &P: PROFINET IO Runtime Software              :P&  */
/*                                                                           */
/*  P a c k a g e         &W: PROFINET IO Runtime Software              :W&  */
/*                                                                           */
/*  C o m p o n e n t     &C: PnDev_Driver                              :C&  */
/*                                                                           */
/*  F i l e               &F: pndev_adapt_dll_2.cpp                     :F&  */
/*                                                                           */
/*  V e r s i o n         &V: BC_PNRUN_P07.01.00.00_00.02.00.05         :V&  */
/*                                                                           */
/*  D a t e  (YYYY-MM-DD) &D: 2018-07-18                                :D&  */
/*                                                                           */
/*****************************************************************************/
//
//  D e s c r i p t i o n:
//
//	Code for user specific adaptions of DLL (language C++)
//
//****************************************************************************/

// Note:
//	don't use precompiled header because stdafx.h does not exist at common directory
//	-> turn it off at ProjectSettings >> C/C++ >> Precompiled Headers of  t h i s  file

#include <precomp.h>														// environment specific IncludeFiles
																			//	- name is fixed for Driver ToolChain, include by conditional compiling not possible!
#include <PnDev_Driver_Inc.h>												// all IncludeFiles of PnDev_Driver

//************************************************************************
//  D e s c r i p t i o n :
//
//	overload C++ operator new / delete
//************************************************************************

//------------------------------------------------------------------------
#if defined (PNDEV_OS_WIN)
//------------------------------------------------------------------------

//------------------------------------------------------------------------
#elif defined (PNDEV_OS_ADONIS)
//------------------------------------------------------------------------

// Note:
//	- if "ADN_NEW_DELETE_USAGE == YES" then C++ operator new / delete are implemented at adonis\user\adonis\adn_new.cpp

#if (ADN_NEW_DELETE_USAGE == NO)
/*
void* operator new(size_t lSizeIn)
{
	UNREFERENCED_PARAMETER(lSizeIn);

	return(NULL);
}

//------------------------------------------------------------------------
void* operator new[](size_t lSizeIn)
{
	UNREFERENCED_PARAMETER(lSizeIn);

	return(NULL);
}

//------------------------------------------------------------------------
void operator delete(void* pIn)
{
	UNREFERENCED_PARAMETER(pIn);
}

//------------------------------------------------------------------------
void operator delete[](void* pIn)
{
	UNREFERENCED_PARAMETER(pIn);
}
*/
#endif

//------------------------------------------------------------------------
#elif defined (PNDEV_OS_LINUX)
//------------------------------------------------------------------------

//------------------------------------------------------------------------
#elif defined (PNDEV_OS_UNKNOWN)
//------------------------------------------------------------------------
#endif
