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
/*  F i l e               &F: precomp.h                                 :F&  */
/*                                                                           */
/*  V e r s i o n         &V: BC_PNRUN_P07.01.00.00_00.02.00.05         :V&  */
/*                                                                           */
/*  D a t e  (YYYY-MM-DD) &D: 2018-07-18                                :D&  */
/*                                                                           */
/*****************************************************************************/
//
//  D e s c r i p t i o n:
//
//	Environment specific include file required by C files of directory "common"
//
//****************************************************************************/

#ifndef __precomp_h__
#define __precomp_h__

	//------------------------------------------------------------------------
	#if defined (PNDEV_OS_WIN)
	//------------------------------------------------------------------------
	#pragma once

	#ifndef UNICODE
		#define	UNICODE
		#define	_UNICODE
	#endif

	#define WIN32_LEAN_AND_MEAN													// exclude rarely-used stuff from Windows headers

	#if defined (PNDEV_TOOL_GCC_MINGW)
		#ifndef WINVER
			#define WINVER	0x502												// required for SetDllDirectory()
		#endif
	#else																		// Microsoft
		#include "pndev_targetver.h"
	#endif

	#include <stdio.h>
	#include <stdlib.h>
	#include <tchar.h>
	#include <windows.h>
	#include "Shlwapi.h"

	//------------------------------------------------------------------------
	#elif defined (PNDEV_OS_ADONIS)
	//------------------------------------------------------------------------
	#include <Adonis_Inc.h>

	//------------------------------------------------------------------------
	#elif defined (PNDEV_OS_LINUX)
	//------------------------------------------------------------------------
	#if defined PNDEV_DRIVER_SYS
		#include <linux/module.h>
		#include <linux/init.h>
		#include <linux/kernel.h>	/* printk() */
		#include <linux/fs.h>
	#else
		#include <stdint.h>
		#include <stddef.h>
		#include <unistd.h>       //Get Path of executable
		#include <dlfcn.h>        //dynamic loading of shared objects
    	#include <pthread.h>      //setting Thread priority
	#endif
	//------------------------------------------------------------------------
	#elif defined (PNDEV_OS_UNKNOWN)
	//------------------------------------------------------------------------
	#endif

#endif
