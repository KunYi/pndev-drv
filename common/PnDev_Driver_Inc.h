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
/*  F i l e               &F: PnDev_Driver_Inc.h                        :F&  */
/*                                                                           */
/*  V e r s i o n         &V: BC_PNRUN_P07.01.00.00_00.02.00.05         :V&  */
/*                                                                           */
/*  D a t e  (YYYY-MM-DD) &D: 2018-07-18                                :D&  */
/*                                                                           */
/*****************************************************************************/
//
//  D e s c r i p t i o n:
//
//	Include files for user interface of PnDev_Driver
//
//****************************************************************************/

#ifndef __PnDev_Driver_Inc_h__
#define __PnDev_Driver_Inc_h__

	#include <PnCore_Inc.h>
	
	//------------------------------------------------------------------------
	#if defined (PNDEV_OS_WIN)
	//------------------------------------------------------------------------
		#ifndef UNICODE															// if CompilerSwitch for Unicode not set
			#define UNICODE
			#define _UNICODE
			
			#define	PNDEV_CHANGED_SETTINGS
		#endif
	#endif

    #include <pndev_np_common.h>												// basic types
	#include <PnDev_DriverU.h>
	#include <pndev_adapt.h>

    #ifdef PNDEV_SUPPORT_OTHERS
	#include <pndev_sbl_s7p.h>
    #endif
	
	//------------------------------------------------------------------------
	#if defined (PNDEV_OS_WIN)
	//------------------------------------------------------------------------
		#ifdef PNDEV_CHANGED_SETTINGS											// if settings changed above
			#undef UNICODE
			#undef _UNICODE
			
			#undef	PNDEV_CHANGED_SETTINGS
		#endif
	#endif
#endif
