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
/*  F i l e               &F: Basic.c                                   :F&  */
/*                                                                           */
/*  V e r s i o n         &V: BC_PNRUN_P07.01.00.00_00.02.00.05         :V&  */
/*                                                                           */
/*  D a t e  (YYYY-MM-DD) &D: 2018-07-18                                :D&  */
/*                                                                           */
/*****************************************************************************/
//
//  D e s c r i p t i o n:
//
//	Code for basic functions
//
//****************************************************************************/

// Note if using VisualStudio:
//	A "C" module doesn't support precompiled header
//	-> turn it off at ProjectSettings >> C/C++ >> Precompiled Headers of  t h i s  file

//------------------------------------------------------------------------
#if defined (PNDEV_OS_WIN)
//------------------------------------------------------------------------
#include <precomp.h>														// environment specific IncludeFiles

																			//	- name is fixed for Driver ToolChain, include by conditional compiling not possible!
#if defined (PNDEV_LINT)
#include "Inc.h"
#else
#include <Inc.h>
#endif
//------------------------------------------------------------------------
#else
//------------------------------------------------------------------------
#include "precomp.h"
#include "Inc.h"
//------------------------------------------------------------------------
#endif

#ifdef PNDEV_DRIVER_SYS														// required for Driver ToolChain
	#ifdef PNDEV_TRACE
		#include "Basic.tmh"
	#endif
#endif

#ifdef ALLOC_PRAGMA
//	- don't permit paging (see...)
//	#pragma alloc_text (PAGE, fnInitList)
//	#pragma alloc_text (PAGE, fnListEmpty)
//	#pragma alloc_text (PAGE, fnPutBlkToList)
//	#pragma alloc_text (PAGE, fnRemoveBlkFromList)
//	#pragma alloc_text (PAGE, fnGetFirstBlkFromList)
//	#pragma alloc_text (PAGE, fnBlkAtList)
//	#pragma alloc_text (PAGE, fnGetAlignedValue)
#endif

//************************************************************************
//  D e s c r i p t i o n :
//
//	initialize list
//************************************************************************

void fnInitList(uLIST_HEADER* pListIn)
{
	// List.next = List
	pListIn->pNext = pListIn;

	// List.prev = List
	pListIn->pPrev = pListIn;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//	check if list empty
//************************************************************************

BOOLEAN fnListEmpty(uLIST_HEADER* pListIn)
{
BOOLEAN bResult = FALSE;

	if	(pListIn->pNext == pListIn)
		// list empty
	{
		bResult = TRUE;
	}

	return(bResult);
}

//************************************************************************
//  D e s c r i p t i o n :
//
//	put block to list
//************************************************************************

void fnPutBlkToList(				uLIST_HEADER*	pListIn,
					PFD_MEM_ATTR	uLIST_HEADER*	pBlockIn)
{
	// Block.next = List
	pBlockIn->pNext = pListIn;

	// List.prev->next = Block
	((uLIST_HEADER*) (pListIn->pPrev))->pNext = pBlockIn;

	// Block.prev = List.prev
	pBlockIn->pPrev = pListIn->pPrev;

	// List.prev = Block
	pListIn->pPrev = pBlockIn;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//	remove desired block from list
//************************************************************************

void fnRemoveBlkFromList(	uLIST_HEADER*	pListIn,
							uLIST_HEADER*	pBlockIn)
{
	if	(pListIn->pNext != pListIn)
		// list not empty
	{
		// Block.prev->next = Block.next
		((uLIST_HEADER*) (pBlockIn->pPrev))->pNext = pBlockIn->pNext;

		// Block.next->prev = Block.prev
		((uLIST_HEADER*) (pBlockIn->pNext))->pPrev = pBlockIn->pPrev;
	}
}

//************************************************************************
//  D e s c r i p t i o n :
//
//	get first block from list
//************************************************************************

void* fnGetFirstBlkFromList(uLIST_HEADER* pListIn)
{
void* pResult = NULL;

	if	(pListIn->pNext != pListIn)
		// list not empty
	{
		// Block = List.next
		pResult = pListIn->pNext;
	}

	return(pResult);
}

//************************************************************************
//  D e s c r i p t i o n :
//
//	verify if list contains desired block
//************************************************************************

BOOLEAN fnBlkAtList(uLIST_HEADER*	pListIn,
					uLIST_HEADER*	pBlockIn)
{
BOOLEAN			bResult		= FALSE;
uLIST_HEADER*	pBlockTmp	= NULL;

	// get first block
	pBlockTmp = (uLIST_HEADER*) pListIn->pNext;

	while	(pBlockTmp != pListIn)
			// end of list not reached
	{
		if	(pBlockTmp == pBlockIn)
			// desired block found
		{
			// success
			bResult = TRUE;

			// leave loop
			break;
		}
		else
		{
			// get next block
			pBlockTmp = (uLIST_HEADER*) pBlockTmp->pNext;
		}
	}

	return(bResult);
}

//************************************************************************
//  D e s c r i p t i o n :
//
//	get aligned value
//************************************************************************

UINT64 fnGetAlignedValue(	UINT64	lValueIn,
							UINT32	lAlignment)
{
#if (PNDEV_PLATFORM ==  PNDEV_KM_PLATFORM_32) && (defined (PNDEV_OS_LINUX))
    
    UINT64 lAlignedValue = lValueIn + (lAlignment-1);
    do_div(lAlignedValue, lAlignment);
    lAlignedValue = lAlignedValue * lAlignment;
    return lAlignedValue;
#else
	return(((lValueIn + (lAlignment-1)) / lAlignment) * lAlignment);
#endif
}

//************************************************************************
//  D e s c r i p t i o n :
//
//	calculate the CRC32 of the given data
//************************************************************************
UINT32	fnCalculateCRC32(	UINT8*	pData,
							UINT32  lLength)
{
UINT32 lShiftReg	= 0xFFFFFFFF;
UINT32 lPolynom		= 0xEDB88320;    // Generatorpolynom
UINT32 i			= 0;
UINT32 j			= 0;

	for (i = 0; i < lLength; i++)
		// Berechne fuer alle Daten
	{
	UINT8 cByte = *(pData + i);

		for (j = 0; j < 8; ++j)
			// Berechne fuer jeweils 8 Bit der Daten
		{
			if ((lShiftReg & 1) != (UINT32)(cByte & 1))
				lShiftReg = (lShiftReg >> 1) ^ lPolynom;
			else
				lShiftReg >>= 1;

			cByte >>= 1;
		}
	}

	return (lShiftReg ^ 0xffffffff);
}