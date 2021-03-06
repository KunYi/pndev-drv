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
/*  F i l e               &F: Board_Micrel.h                            :F&  */
/*                                                                           */
/*  V e r s i o n         &V: BC_PNRUN_P07.01.00.00_00.02.00.05         :V&  */
/*                                                                           */
/*  D a t e  (YYYY-MM-DD) &D: 2018-07-18                                :D&  */
/*                                                                           */
/*****************************************************************************/
//
//  D e s c r i p t i o n:
//
//	Declarations for boards with Micrel
//
//****************************************************************************/

#ifndef __Board_Micrel_h__
#define __Board_Micrel_h__

	//########################################################################
	//  Defines
	//########################################################################
	//========================================================================
	//	Micrel KSZ8841 / KSZ8842
	//========================================================================

	// GRR Global Reset Register
	#define BOARD_MICREL_KSZ88XX__GRR		0x0216

	// Port1 Control Register
	#define BOARD_MICREL_KSZ88XX__P1CR4		0x0512

	// SIDER Switch Id and Enable Register
	// CIDER Chip Id and Enable Register
	#define BOARD_MICREL_KSZ88XX__SCIDER	0x0400

	// INTEN Interrupt Enable Register
	#define BOARD_MICREL_KSZ88XX__INTEN		0x0028

	// INTST Interrupt Statut Register
	#define BOARD_MICREL_KSZ88XX__INTST		0x002C

	// MARL Mac Address Register Low
	#define BOARD_MICREL_KSZ88XX__MARL		0x0200
	
	// MARM Mac Address Register Middle
	#define BOARD_MICREL_KSZ88XX__MARM		0x0202

	// MARH Mac Address Register High
	#define BOARD_MICREL_KSZ88XX__MARH		0x0204

	//========================================================================
	//	KSZ8842 (2 ports)
	//========================================================================

	// Port2 Control Register
	#define BOARD_MICREL_KSZ88XX__P2CR4		0x0532

	//------------------------------------------------------------------------
	//	BAR0-5
	//------------------------------------------------------------------------

	#define	BOARD_MICREL_KSZ884X__BAR0_SIZE	(1024*2)
	#define	BOARD_MICREL_KSZ884X__BAR1_SIZE	(1024*0)
	#define	BOARD_MICREL_KSZ884X__BAR2_SIZE	(1024*0)
	#define	BOARD_MICREL_KSZ884X__BAR3_SIZE	(1024*0)
	#define	BOARD_MICREL_KSZ884X__BAR4_SIZE	(1024*0)
	#define	BOARD_MICREL_KSZ884X__BAR5_SIZE	(1024*0)

	//------------------------------------------------------------------------
	//	BAR0
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	//	BAR1
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	//	BAR2
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	//	BAR3
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	//	BAR4
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	//	BAR5
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	//	PCI-Bridge Register
	//------------------------------------------------------------------------


	//------------------------------------------------------------------------
	//	FLASH
	//------------------------------------------------------------------------


	//------------------------------------------------------------------------
	//	SDRAM
	//------------------------------------------------------------------------

	//########################################################################
	//  Structures
	//########################################################################
	//------------------------------------------------------------------------

#endif
