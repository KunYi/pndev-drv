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
/*  F i l e               &F: pndev_adapt.h                              :F&  */
/*                                                                           */
/*  V e r s i o n         &V: BC_PNRUN_P07.01.00.00_00.02.00.05         :V&  */
/*                                                                           */
/*  D a t e  (YYYY-MM-DD) &D: 2018-07-18                                :D&  */
/*                                                                           */
/*****************************************************************************/
//
//  D e s c r i p t i o n:
//
//	Declarations for user specific adaptions
//
//****************************************************************************/

#ifndef __pndev_adapt_h__
#define __pndev_adapt_h__

	#ifdef __cplusplus		// if C++ compiler: Use C linkage
	extern "C"
	{
	#endif
	
	//########################################################################
	//  Defines
	//########################################################################
	
	typedef enum _ePNDEV_TRACE_LEVEL
	{
		ePNDEV_TRACE_LEVEL_INVALID	= 0,
		ePNDEV_TRACE_LEVEL_ERROR	= 1,
		ePNDEV_TRACE_LEVEL_INFO		= 2
	}
	ePNDEV_TRACE_LEVEL;

	//------------------------------------------------------------------------
	typedef enum _ePNDEV_TRACE_CONTEXT
	{
		ePNDEV_TRACE_CONTEXT_INVALID	= 0,
		ePNDEV_TRACE_CONTEXT_BASIC		= 1,
		ePNDEV_TRACE_CONTEXT_DPC		= 2,
		ePNDEV_TRACE_CONTEXT_ISR		= 3
	}
	ePNDEV_TRACE_CONTEXT;

	//########################################################################
	//  Structures
	//########################################################################
	//------------------------------------------------------------------------

	//########################################################################
	//  Function prototypes
	//########################################################################
	
	//------------------------------------------------------------------------
	// pndev_adapt_dll_1.c
	//------------------------------------------------------------------------
	void fnSetTraceDll(const PNDEV_CHAR* sTraceIn);
	
	//------------------------------------------------------------------------
	// pndev_adapt_sys.c
	//------------------------------------------------------------------------
	void fnSetTraceSys(	const ePNDEV_TRACE_LEVEL	eLevelIn,
						const ePNDEV_TRACE_CONTEXT	eContextIn,
						const BOOLEAN				bLogIn,
						char*						sTraceIn);
							
	//------------------------------------------------------------------------
	#ifdef __cplusplus		// if C++ compiler: End of C linkage
	}
	#endif

#endif
