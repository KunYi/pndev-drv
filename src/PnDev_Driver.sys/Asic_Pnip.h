/*****************************************************************************/
/*  Copyright (C) 2018 Siemens Aktiengesellschaft. All rights reserved.      */
/*****************************************************************************/
/* This program is free software; you can redistribute it and/or             */
/* modify it under the terms of the GNU General Public License version 2     */
/* as published by the Free Software Foundation; or, when distributed        */
/* separately from the Linux kernel or incorporated into other               */
/* software packages, subject to the following license:                      */
/*                                                                           */
/*  This program is protected by German copyright law and international      */
/*  treaties. The use of this software including but not limited to its      */
/*  Source Code is subject to restrictions as agreed in the license          */
/*  agreement between you and Siemens.                                       */
/*  Copying or distribution is not allowed unless expressly permitted        */
/*  according to your license agreement with Siemens.                        */
/*                                                                           */
/*****************************************************************************/
/*                                                                           */
/*  P r o j e c t         &P: PROFINET IO Runtime Software              :P&  */
/*                                                                           */
/*  P a c k a g e         &W: PROFINET IO Runtime Software              :W&  */
/*                                                                           */
/*  C o m p o n e n t     &C: PnDev_Driver                              :C&  */
/*                                                                           */
/*  F i l e               &F: Asic_Pnip.h                               :F&  */
/*                                                                           */
/*  V e r s i o n         &V: BC_PNRUN_P07.01.00.00_00.02.00.05         :V&  */
/*                                                                           */
/*  D a t e  (YYYY-MM-DD) &D: 2018-07-18                                :D&  */
/*                                                                           */
/*****************************************************************************/
//
//  D e s c r i p t i o n:
//
//	Declarations for Asics with PNIP (Ertec200P)
//
//****************************************************************************/

#ifndef __Asic_Pnip_h__
#define __Asic_Pnip_h__

	//########################################################################
	//  Defines
	//########################################################################

	//========================================================================
	//	AHB addresses/sizes
	//========================================================================

	//========================================================================
	// Eb200P
	//========================================================================
	
	#define ERTEC200P_AHB_ADR__KRISC32_TCM			0x04000000
	#define ERTEC200P_AHB_ADR__ARM926_TCM			0x08000000
	#define ERTEC200P_AHB_ADR__ARM_ICU				0x10000000
	#define ERTEC200P_AHB_ADR__PNIP					0x10600000
 	#define ERTEC200P_AHB_ADR__PERIF				0x10800000
 	#define ERTEC200P_AHB_ADR__GDMA					0x10a00000
 	#define ERTEC200P_AHB_ADR__TTU					0x10b00000
 	#define ERTEC200P_AHB_ADR__SD_MMC				0x10c00000
 	#define ERTEC200P_AHB_ADR__EMC_REG				0x10d00000
 	#define ERTEC200P_AHB_ADR__EMC_SDRAM			0x20000000
 	#define ERTEC200P_AHB_ADR__EMC_ASYNC_BANK0		0x30000000
	#define ERTEC200P_AHB_ADR__EMC_ASYNC_BANK1		0x34000000
	#define ERTEC200P_AHB_ADR__EMC_ASYNC_BANK2		0x38000000
	#define ERTEC200P_AHB_ADR__EMC_ASYNC_BANK3		0x3c000000
	#define ERTEC200P_AHB_ADR__APB_PER				0x40000000

	#define ERTEC200P_AHB_SIZE__KRISC32_TCM_REV1	(1024*128)
	#define ERTEC200P_AHB_SIZE__KRISC32_TCM_REV2	(1024*256)
	#define ERTEC200P_AHB_SIZE__ARM926_TCM			(1024*256)
	#define ERTEC200P_AHB_SIZE__ARM_ICU				(1024*1024*5)
	#define ERTEC200P_AHB_SIZE__PNIP				(1024*1024*2)
 	#define ERTEC200P_AHB_SIZE__PERIF				(1024*64)
 	#define ERTEC200P_AHB_SIZE__GDMA				(1024*1024*1)
 	#define ERTEC200P_AHB_SIZE__TTU					(64)
 	#define ERTEC200P_AHB_SIZE__SD_MMC				(1024*1024*1)
 	#define ERTEC200P_AHB_SIZE__EMC_REG				(1024*1024*1)
	#define ERTEC200P_AHB_SIZE__APB_PER				(1024*116)
	// sizes of EMC_SDRAM and EMC_ASYNC_BANKx do not depend on Asic but on board

	//------------------------------------------------------------------------
	//	APB-Peripherals
	//------------------------------------------------------------------------

 	#define ERTEC200P_APB_PER__OFFSET_PERIF		0x00000000
 	#define ERTEC200P_APB_PER__OFFSET_UART1		0x0000a000
	#define ERTEC200P_APB_PER__OFFSET_UART2		0x0000b000
	#define ERTEC200P_APB_PER__OFFSET_UART3		0x0000c000
	#define ERTEC200P_APB_PER__OFFSET_UART4		0x0000d000
 	#define ERTEC200P_APB_PER__OFFSET_I2C		0x0000e000
 	#define ERTEC200P_APB_PER__OFFSET_SCRB		0x0000f000
 	#define ERTEC200P_APB_PER__OFFSET_SPI1		0x00010000
 	#define ERTEC200P_APB_PER__OFFSET_SPI2		0x00011000
 	#define ERTEC200P_APB_PER__OFFSET_TIMER0_5	0x00012000
 	#define ERTEC200P_APB_PER__OFFSET_WATCHDOG	0x00013000
 	#define ERTEC200P_APB_PER__OFFSET_GPIO		0x00018000
 	#define ERTEC200P_APB_PER__OFFSET_HOSTIF	0x0001A000

 	#define ERTEC200P_APB_PER__SIZE_PERIF		(1024*32)
 	#define ERTEC200P_APB_PER__SIZE_UART1		(1024*4)
	#define ERTEC200P_APB_PER__SIZE_UART2		(1024*4)
	#define ERTEC200P_APB_PER__SIZE_UART3		(1024*4)
	#define ERTEC200P_APB_PER__SIZE_UART4		(1024*4)
 	#define ERTEC200P_APB_PER__SIZE_I2C			(256)
 	#define ERTEC200P_APB_PER__SIZE_SCRB		(256)
 	#define ERTEC200P_APB_PER__SIZE_SPI1		(1024*4)
 	#define ERTEC200P_APB_PER__SIZE_SPI2		(1024*4)
 	#define ERTEC200P_APB_PER__SIZE_TIMER0_5	(256)
 	#define ERTEC200P_APB_PER__SIZE_WATCHDOG	(32)
 	#define ERTEC200P_APB_PER__SIZE_GPIO		(256)
 	#define ERTEC200P_APB_PER__SIZE_HOSTIF		(256)

	//------------------------------------------------------------------------
	// SCRB Register:
 	#define ERTEC200P_SCRB_REG__ID					0x00
 	#define ERTEC200P_SCRB_REG__CONFIG				0x08
 	#define ERTEC200P_SCRB_REG__AHB_BURST_BREAKER	0x44
 	#define ERTEC200P_SCRB_REG__XHIF_MODE			0xb8
	#define	ERTEC200P_SCRB_REG__TCM926_MAP			0x5c
	#define	ERTEC200P_SCRB_REG__DRIVE_EMC			0x78

	// Register SCRB-ID
	#define ERTEC200P_SCRB_ID__REV1		0x40280100
	#define ERTEC200P_SCRB_ID__REV2		0x40280200
    #define ERTEC200P_SCRB_ID__REV2_HW2	0x40280201

	//------------------------------------------------------------------------
	// GPIO Register for for General Purpose IOs (31:0):
 	#define	ERTEC200P_GPIO_REG__IOCTRL_0		0x00
 	#define	ERTEC200P_GPIO_REG__OUT_0			0x04
 	#define	ERTEC200P_GPIO_REG__OUT_SET_0		0x08
 	#define	ERTEC200P_GPIO_REG__OUT_CLEAR_0		0x0c
 	#define	ERTEC200P_GPIO_REG__RES_DIS_0		0x10
 	#define	ERTEC200P_GPIO_REG__IN_0			0x14
 	#define	ERTEC200P_GPIO_REG__PORT_MODE_0_L	0x18
 	#define	ERTEC200P_GPIO_REG__PORT_MODE_0_H	0x1c

	//------------------------------------------------------------------------
	// HOSTIF/XHIF Register:
	//	- addressing by CS-R: only XHIF-PageCfg Register visible
	#define ERTEC200P_XHIF_REG_CSR__PAGE0_RANGE		0x00
 	#define ERTEC200P_XHIF_REG_CSR__PAGE0_OFFSET	0x04
 	#define ERTEC200P_XHIF_REG_CSR__PAGE0_CFG		0x08
 	#define ERTEC200P_XHIF_REG_CSR__PAGE1_RANGE		0x10
 	#define ERTEC200P_XHIF_REG_CSR__PAGE1_OFFSET	0x14
 	#define ERTEC200P_XHIF_REG_CSR__PAGE1_CFG		0x18
 	#define ERTEC200P_XHIF_REG_CSR__PAGE2_RANGE		0x20
 	#define ERTEC200P_XHIF_REG_CSR__PAGE2_OFFSET	0x24
 	#define ERTEC200P_XHIF_REG_CSR__PAGE2_CFG		0x28
 	#define ERTEC200P_XHIF_REG_CSR__PAGE3_RANGE		0x30
 	#define ERTEC200P_XHIF_REG_CSR__PAGE3_OFFSET	0x34
 	#define ERTEC200P_XHIF_REG_CSR__PAGE3_CFG		0x38
 	#define ERTEC200P_XHIF_REG_CSR__VERSION_BLOCK0	0x3c
 	#define ERTEC200P_XHIF_REG_CSR__PAGE4_RANGE		0x40
 	#define ERTEC200P_XHIF_REG_CSR__PAGE4_OFFSET	0x44
 	#define ERTEC200P_XHIF_REG_CSR__PAGE4_CFG		0x48
 	#define ERTEC200P_XHIF_REG_CSR__PAGE5_RANGE		0x50
 	#define ERTEC200P_XHIF_REG_CSR__PAGE5_OFFSET	0x54
 	#define ERTEC200P_XHIF_REG_CSR__PAGE5_CFG		0x58
 	#define ERTEC200P_XHIF_REG_CSR__PAGE6_RANGE		0x60
 	#define ERTEC200P_XHIF_REG_CSR__PAGE6_OFFSET	0x64
 	#define ERTEC200P_XHIF_REG_CSR__PAGE6_CFG		0x68
 	#define ERTEC200P_XHIF_REG_CSR__PAGE7_RANGE		0x70
 	#define ERTEC200P_XHIF_REG_CSR__PAGE7_OFFSET	0x74
 	#define ERTEC200P_XHIF_REG_CSR__PAGE7_CFG		0x78
 	#define ERTEC200P_XHIF_REG_CSR__VERSION_BLOCK1	0x7c

	//	- addressing by CS-M: all HOSTIF Register (SPI, XHIF) visible
 	#define ERTEC200P_XHIF_REG_MEM__IP_VERSION		0x40
 	#define ERTEC200P_XHIF_REG_MEM__IP_DEVELOPMENT	0x44
 	#define ERTEC200P_XHIF_REG_MEM__ACCESS_ERROR	0x48
 	#define ERTEC200P_XHIF_REG_MEM__XHIF_CONTROL	0x70
 	#define ERTEC200P_XHIF_REG_MEM__PAGE0_RANGE		0x80
 	#define ERTEC200P_XHIF_REG_MEM__PAGE0_OFFSET	0x84
 	#define ERTEC200P_XHIF_REG_MEM__PAGE0_CFG		0x88
 	#define ERTEC200P_XHIF_REG_MEM__PAGE1_RANGE		0x90
 	#define ERTEC200P_XHIF_REG_MEM__PAGE1_OFFSET	0x94
 	#define ERTEC200P_XHIF_REG_MEM__PAGE1_CFG		0x98
 	#define ERTEC200P_XHIF_REG_MEM__PAGE2_RANGE		0xa0
 	#define ERTEC200P_XHIF_REG_MEM__PAGE2_OFFSET	0xa4
 	#define ERTEC200P_XHIF_REG_MEM__PAGE2_CFG		0xa8
 	#define ERTEC200P_XHIF_REG_MEM__PAGE3_RANGE		0xb0
 	#define ERTEC200P_XHIF_REG_MEM__PAGE3_OFFSET	0xb4
 	#define ERTEC200P_XHIF_REG_MEM__PAGE3_CFG		0xb8
 	#define ERTEC200P_XHIF_REG_MEM__VERSION_BLOCK0	0xbc
 	#define ERTEC200P_XHIF_REG_MEM__PAGE4_RANGE		0xc0
 	#define ERTEC200P_XHIF_REG_MEM__PAGE4_OFFSET	0xc4
 	#define ERTEC200P_XHIF_REG_MEM__PAGE4_CFG		0xc8
 	#define ERTEC200P_XHIF_REG_MEM__PAGE5_RANGE		0xd0
 	#define ERTEC200P_XHIF_REG_MEM__PAGE5_OFFSET	0xd4
 	#define ERTEC200P_XHIF_REG_MEM__PAGE5_CFG		0xd8
 	#define ERTEC200P_XHIF_REG_MEM__PAGE6_RANGE		0xe0
 	#define ERTEC200P_XHIF_REG_MEM__PAGE6_OFFSET	0xe4
 	#define ERTEC200P_XHIF_REG_MEM__PAGE6_CFG		0xe8
 	#define ERTEC200P_XHIF_REG_MEM__PAGE7_RANGE		0xf0
 	#define ERTEC200P_XHIF_REG_MEM__PAGE7_OFFSET	0xf4
 	#define ERTEC200P_XHIF_REG_MEM__PAGE7_CFG		0xf8
 	#define ERTEC200P_XHIF_REG_MEM__VERSION_BLOCK1	0xfc

	#define ERTEC200P_DTCM_OFFSET__BLOCK0		0x00000000
	#define ERTEC200P_DTCM_OFFSET__BLOCK1		0x00010000
	#define ERTEC200P_DTCM_OFFSET__BLOCK2		0x00020000
	#define ERTEC200P_DTCM_OFFSET__BLOCK3		0x00030000

	#define ERTEC200P_DTCM_OFFSET__SEMAPHORE	0x00030040
	#define ERTEC200P_DTCM_OFFSET__CODE			0x00030044

	//------------------------------------------------------------------------
	// Hera
	//------------------------------------------------------------------------
	
	#define HERA_AHB_SIZE__DDR3SDRAM			(1024*1024*127)
	#define HERA_AHB_SIZE__KRISC_DDR3SDRAM		((1024*1024*128) - HERA_AHB_SIZE__DDR3SDRAM)
	#define HERA_AHB_SIZE__PNIP					(1024*1024*2)
	#define HERA_AHB_SIZE__XGDMA				(1024*1024*1)
	#define HERA_AHB_SIZE__APB_PER				(1024*128)

	#define HERA_MSIX_VECTOR_TABLE_OFFSET		0x2000
	#define HERA_MSIX_VECTOR_COUNT_MAX			32

	#define HERA_AHB_ADR__DDR3SDRAM				0x00000000
	#define HERA_AHB_ADR__KRISC_DDR3SDRAM		0x07f00000

	//__________________________

	// Inc 9
	#define HERA_AHB_ADR__XGDMA					0xA0800000
	#define HERA_AHB_ADR__APB_PER				0xC0000000	

	// PNIP_A / CORE_A Inc 9
	#define HERA_AHB_ADR__PNIP_A				0xA0400000
	#define HERA_AHB_ADR__R4_CORE_A_BTCM		0x00000000	// will be defined at StartUp of Krisc
	#define HERA_AHB_ADR__R4_CORE_A_TIMER		0x00000000
	#define HERA_AHB_ADR__R4_CORE_A_VIC			0x00000000
	#define HERA_AHB_ADR__R4_CORE_A_ATCM		0x00000000
	#define HERA_AHB_SIZE__R4_CORE_A_BTCM		(1024*32)
	#define HERA_AHB_SIZE__R4_CORE_A_TIMER		(1024*16)
	#define HERA_AHB_SIZE__R4_CORE_A_VIC		(1024*16)
	#define HERA_AHB_SIZE__R4_CORE_A_ATCM		(1024*4)

    // PNIP_B / CORE_B Inc 9
	#define HERA_AHB_ADR__PNIP_B				0xA0600000
	#define HERA_AHB_ADR__R4_CORE_B_BTCM		0x00000000	// will be defined at StartUp of Krisc
	#define HERA_AHB_ADR__R4_CORE_B_TIMER		0x00000000
	#define HERA_AHB_ADR__R4_CORE_B_VIC			0x00000000
	#define HERA_AHB_ADR__R4_CORE_B_ATCM		0x00000000
	#define HERA_AHB_SIZE__R4_CORE_B_BTCM		(HERA_AHB_SIZE__R4_CORE_A_BTCM)
	#define HERA_AHB_SIZE__R4_CORE_B_TIMER		(HERA_AHB_SIZE__R4_CORE_A_TIMER)
	#define HERA_AHB_SIZE__R4_CORE_B_VIC		(HERA_AHB_SIZE__R4_CORE_A_VIC)
	#define HERA_AHB_SIZE__R4_CORE_B_ATCM		(HERA_AHB_SIZE__R4_CORE_A_ATCM)

	//------------------------------------------------------------------------
	//	APB-Peripherals
	//------------------------------------------------------------------------

	#define HERA_APB_PER__OFFSET_PCIE_UL		0x00000000
 	#define HERA_APB_PER__OFFSET_SCRB			0x00004000

	//_________________________________________________________

	// Inc 12 - just temporary
	#define HERA_APB_PER__OFFSET_SEC_SCRB		0x00004400
	#define HERA_APB_PER__SIZE_SEC_SCRB			(1024*1)

	// Inc 9
 	#define HERA_APB_PER__OFFSET_GPIO			0x00005000

	#define HERA_APB_PER__OFFSET_CTC			0x00006000

	#define HERA_APB_PER__OFFSET_TIMER_A_0_5	0x0000B000
	#define HERA_APB_PER__OFFSET_TIMER_B_0_5	0x0000C000
	#define HERA_APB_PER__OFFSET_TIMER_C_0_5	0x0000D000

	#define HERA_APB_PER__OFFSET_WATCHDOG_A		0x0000E000
	#define HERA_APB_PER__OFFSET_WATCHDOG_B		0x0000F000
	#define HERA_APB_PER__OFFSET_WATCHDOG_C		0x00010000
	#define HERA_APB_PER__OFFSET_WATCHDOG_D		0x00011000
	#define HERA_APB_PER__OFFSET_WATCHDOG_E		0x00012000

	#define HERA_APB_PER__OFFSET_FTIMER			0x00013000

	#define HERA_APB_PER__OFFSET_I2C1_1			0x00014000
	#define HERA_APB_PER__OFFSET_I2C1_2			0x00015000
	#define HERA_APB_PER__OFFSET_I2C1_3			0x00016000

	#define HERA_APB_PER__OFFSET_UART1_3		0x00017000

 	#define HERA_APB_PER__OFFSET_SPI1			0x0001A000
	#define HERA_APB_PER__OFFSET_SPI2			0x0001B000
 	#define HERA_APB_PER__OFFSET_SPI3			0x0001C000
	#define HERA_APB_PER__OFFSET_SPI4			0x0001D000

	#define HERA_APB_PER__OFFSET_GTB			0x0001F000
	//_________________________________________________________

	#define HERA_APB_PER__SIZE_PCIE_UL				(1024*12)
 	#define HERA_APB_PER__SIZE_SCRB					(1024*1)
 	#define HERA_APB_PER__SIZE_GPIO					(1024*1)

	#define HERA_APB_PER__SIZE_TIMER_A_0_5			(256)
	#define HERA_APB_PER__SIZE_TIMER_B_0_5			(256)
	#define HERA_APB_PER__SIZE_TIMER_C_0_5			(256)

	#define HERA_APB_PER__SIZE_WATCHDOG_A			(32)
	#define HERA_APB_PER__SIZE_WATCHDOG_B			(32)
	#define HERA_APB_PER__SIZE_WATCHDOG_C			(32)
	#define HERA_APB_PER__SIZE_WATCHDOG_D			(32)
	#define HERA_APB_PER__SIZE_WATCHDOG_E			(32)

	#define HERA_APB_PER__SIZE_FTIMER				(16)

	#define HERA_APB_PER__SIZE_I2C1_1				(256)
	#define HERA_APB_PER__SIZE_I2C1_2				(256)
	#define HERA_APB_PER__SIZE_I2C1_3				(256)

	#define HERA_APB_PER__SIZE_UART1_3				(1024*12)

	#define HERA_APB_PER__SIZE_SPI1					(1024*2)
	#define HERA_APB_PER__SIZE_SPI2					(1024*2)
	#define HERA_APB_PER__SIZE_SPI3					(1024*2)
	#define HERA_APB_PER__SIZE_SPI4					(1024*2)

	#define HERA_APB_PER__SIZE_GTB					(1024*4)


	//------------------------------------------------------------------------
	//	PCIE_UL Register
	//------------------------------------------------------------------------
	// Inc9 - TODO Remove
	#define HERA_PCIE_UL_REG__ADDR0_LOW_INC9		0x0c20
	#define HERA_PCIE_UL_REG__ADDR0_HIGH_INC9		0x0c24
	#define HERA_PCIE_UL_REG__ADDR1_LOW_INC9		0x0c28
	#define HERA_PCIE_UL_REG__ADDR1_HIGH_INC9		0x0c2c
	#define HERA_PCIE_UL_REG__ADDR2_LOW_INC9		0x0c30
	#define HERA_PCIE_UL_REG__ADDR2_HIGH_INC9		0x0c34
	#define HERA_PCIE_UL_REG__ADDR3_LOW_INC9		0x0c38
	#define HERA_PCIE_UL_REG__ADDR3_HIGH_INC9		0x0c3c
	#define HERA_PCIE_UL_REG__ADDR4_LOW_INC9		0x0c40
	#define HERA_PCIE_UL_REG__ADDR4_HIGH_INC9		0x0c44
	#define HERA_PCIE_UL_REG__ADDR5_LOW_INC9		0x0c48
	#define HERA_PCIE_UL_REG__ADDR5_HIGH_INC9		0x0c4c
	#define HERA_PCIE_UL_REG__ADDR6_LOW_INC9		0x0c50
	#define HERA_PCIE_UL_REG__ADDR6_HIGH_INC9		0x0c54
	#define HERA_PCIE_UL_REG__ADDR7_LOW_INC9		0x0c58
	#define HERA_PCIE_UL_REG__ADDR7_HIGH_INC9		0x0c5c
	// ---------------------------------------------------------------

	#define HERA_PCIE_UL_REG__UL_CONTROL_2		0x0c24

	#define HERA_PCIE_UL_REG__ADDR0_LOW			0x0c50
	#define HERA_PCIE_UL_REG__ADDR0_HIGH		0x0c54
	#define HERA_PCIE_UL_REG__ADDR1_LOW			0x0c58
	#define HERA_PCIE_UL_REG__ADDR1_HIGH		0x0c5c
	#define HERA_PCIE_UL_REG__ADDR2_LOW			0x0c60
	#define HERA_PCIE_UL_REG__ADDR2_HIGH		0x0c64
	#define HERA_PCIE_UL_REG__ADDR3_LOW			0x0c68
	#define HERA_PCIE_UL_REG__ADDR3_HIGH		0x0c6c
	#define HERA_PCIE_UL_REG__ADDR4_LOW			0x0c70
	#define HERA_PCIE_UL_REG__ADDR4_HIGH		0x0c74
	#define HERA_PCIE_UL_REG__ADDR5_LOW			0x0c78
	#define HERA_PCIE_UL_REG__ADDR5_HIGH		0x0c7c
	#define HERA_PCIE_UL_REG__ADDR6_LOW			0x0c80
	#define HERA_PCIE_UL_REG__ADDR6_HIGH		0x0c84
	#define HERA_PCIE_UL_REG__ADDR7_LOW			0x0c88
	#define HERA_PCIE_UL_REG__ADDR7_HIGH		0x0c8c
	#define HERA_PCIE_UL_REG__ADDR8_LOW			0x0c90
	#define HERA_PCIE_UL_REG__ADDR8_HIGH		0x0c94
	#define HERA_PCIE_UL_REG__ADDR9_LOW			0x0c98
	#define HERA_PCIE_UL_REG__ADDR9_HIGH		0x0c9c
	#define HERA_PCIE_UL_REG__ADDR10_LOW		0x0ca0
	#define HERA_PCIE_UL_REG__ADDR10_HIGH		0x0ca4
	#define HERA_PCIE_UL_REG__ADDR11_LOW		0x0ca8
	#define HERA_PCIE_UL_REG__ADDR11_HIGH		0x0cac
	#define HERA_PCIE_UL_REG__ADDR12_LOW		0x0cb0
	#define HERA_PCIE_UL_REG__ADDR12_HIGH		0x0cb4
	#define HERA_PCIE_UL_REG__ADDR13_LOW		0x0cb8
	#define HERA_PCIE_UL_REG__ADDR13_HIGH		0x0cbc

	#define HERA_PCIE_UL_REG__ADDR0_LOW_RESET	0xC0000000
	#define HERA_PCIE_UL_REG__ADDR1_LOW_RESET	0xC4000000
	#define HERA_PCIE_UL_REG__ADDR2_LOW_RESET	0xC8000000
	#define HERA_PCIE_UL_REG__ADDR3_LOW_RESET	0xCC000000
	#define HERA_PCIE_UL_REG__ADDR4_LOW_RESET	0xD0000000
	#define HERA_PCIE_UL_REG__ADDR5_LOW_RESET	0xD4000000
	#define HERA_PCIE_UL_REG__ADDR6_LOW_RESET	0xD8000000
	#define HERA_PCIE_UL_REG__ADDR7_LOW_RESET	0xDC000000
	#define HERA_PCIE_UL_REG__ADDR8_LOW_RESET	0xE0000000
	#define HERA_PCIE_UL_REG__ADDR9_LOW_RESET	0xE1000000
	#define HERA_PCIE_UL_REG__ADDR10_LOW_RESET	0xE2000000
	#define HERA_PCIE_UL_REG__ADDR11_LOW_RESET	0xE3000000
	#define HERA_PCIE_UL_REG__ADDR12_LOW_RESET	0xE4000000
	#define HERA_PCIE_UL_REG__ADDR13_LOW_RESET	0xE5000000

	#define HERA_PCIE_UL_REG__MSIX_PRIO_0		0x0CC0
	#define HERA_PCIE_UL_REG__MSIX_PRIO_1		0x0CC4
	#define HERA_PCIE_UL_REG__MSIX_PRIO_2		0x0CC8
	#define HERA_PCIE_UL_REG__MSIX_PRIO_3		0x0CCC

	#define HERA_PCIE_UL_REG__ACCESS_ERROR		0x0D68

	#define HERA_PCIE_MEM__WINDOW_SIZE_LIMIT			(1024*1024*64)
	#define HERA_PCIE_MEM__WINDOW_ALIGNMENT				(0x1000)

	//------------------------------------------------------------------------
	//	SCRB Register
	//------------------------------------------------------------------------
	#define	HERA_SCRB_REG__SERVICE_REG1_REG			0x0034
	#define	HERA_SCRB_REG__SERVICE_REG2_REG			0x0038
	
	// Inc 9 - TODO Remove
	#define	HERA_SCRB_REG__SW_INT_REG_INC9				0x0080
	#define	HERA_SCRB_REG__SW_INT_SET_REG_INC9			0x0084
	#define	HERA_SCRB_REG__SW_INT_CLEAR_REG_INC9		0x0088

	// Inc 12
	#define	HERA_SCRB_REG__ACC_ERR_MASTER					0x0044
	#define	HERA_SCRB_REG__ACC_ERR_MASTER_RESET_VAL			0x0
	#define	HERA_SCRB_REG__ACC_ERR_SLAVE					0x0048
	#define	HERA_SCRB_REG__ACC_ERR_SLAVE_RESET_VAL			0x0
	#define	HERA_SCRB_REG__ACC_ERR_AHB_APB_BRIDGE			0x004C
	#define	HERA_SCRB_REG__ACC_ERR_AHB_APB_BRIDGE_RESET_VAL	0x0
	#define	HERA_SCRB_REG__ACC_ERR_SCRB						0x0050
	#define	HERA_SCRB_REG__ACC_ERR_SCRB_RESET_VAL			0x8000000

	#define	HERA_SCRB_REG__SW_INT_REG				0x008C
	#define	HERA_SCRB_REG__SW_INT_SET_REG			0x0090
	#define	HERA_SCRB_REG__SW_INT_CLEAR_REG			0x0094


	//------------------------------------------------------------------------
	//	MSIX
	//------------------------------------------------------------------------
	// Vector 31:0
	#define HERA_MSIX__VECTOR_0		0
	#define HERA_MSIX__VECTOR_1     1
	#define HERA_MSIX__VECTOR_2     2
	#define HERA_MSIX__VECTOR_3     3
	#define HERA_MSIX__VECTOR_4     4
	#define HERA_MSIX__VECTOR_5     5
	#define HERA_MSIX__VECTOR_6     6
	#define HERA_MSIX__VECTOR_7     7
	#define HERA_MSIX__VECTOR_8     8
	#define HERA_MSIX__VECTOR_9     9
	#define HERA_MSIX__VECTOR_10    10
	#define HERA_MSIX__VECTOR_11    11
	#define HERA_MSIX__VECTOR_12    12
	#define HERA_MSIX__VECTOR_13    13
	#define HERA_MSIX__VECTOR_14    14
	#define HERA_MSIX__VECTOR_15    15
	#define HERA_MSIX__VECTOR_16    16
	#define HERA_MSIX__VECTOR_17    17
	#define HERA_MSIX__VECTOR_18    18
	#define HERA_MSIX__VECTOR_19    19
	#define HERA_MSIX__VECTOR_20    20
	#define HERA_MSIX__VECTOR_21    21
	#define HERA_MSIX__VECTOR_22    22
	#define HERA_MSIX__VECTOR_23    23
	#define HERA_MSIX__VECTOR_24    24
	#define HERA_MSIX__VECTOR_25    25
	#define HERA_MSIX__VECTOR_26    26
	#define HERA_MSIX__VECTOR_27    27
	#define HERA_MSIX__VECTOR_28    28
	#define HERA_MSIX__VECTOR_29    29
	#define HERA_MSIX__VECTOR_30    30
	#define HERA_MSIX__VECTOR_31    31

	//========================================================================
	//	PNIP
	//========================================================================

	#define PNIP_REG__IP_VERSION				0x00000000
	#define PNIP_REG__IP_DEVELOPMENT			0x00000004
	#define PNIP_REG__STATISTIC_CTRL			0x0000d000

	// Register IP-Development
	#define PNIP_IP_DEVELOPMENT_BIT31_21__ID	0x00000025

	//------------------------------------------------------------------------
	// common for PNIP-ICU123/MUX123
	//------------------------------------------------------------------------
	#define PNIP_REG__ICU_EXT_EVENT		0x00040000
	#define PNIP_REG__ICU_TIME_VALUE	0x00040004

	#define PNIP_ICU__EOI_MAX_VALUE		0x00003fff								// 14Bit -> 16383*1024nsec = 16,78msec
	#define PNIP_MUX__EOI_MAX_VALUE		0x000001ff								// 9Bit  -> 511*32,768usec = 16,74msec

	//------------------------------------------------------------------------
	// PNIP-ICU2/MUX2: connected to ARM-ICU
	//------------------------------------------------------------------------
	#define PNIP_REG__ICU2_CONTROL			0x00042000
	#define PNIP_REG__ICU2_ACTIVATE			0x00042004
	#define PNIP_REG__ICU2_TIME_STAMP		0x00042008

	#define PNIP_REG__ICU2_IRQ0_EVENT_LOW	0x00042100
	#define PNIP_REG__ICU2_IRQ0_EVENT_MID	0x00042104
	#define PNIP_REG__ICU2_IRQ0_EVENT_HIGH	0x00042108
	#define PNIP_REG__ICU2_IRQ0_MASK_LOW	0x0004210c
	#define PNIP_REG__ICU2_IRQ0_MASK_MID	0x00042110
	#define PNIP_REG__ICU2_IRQ0_MASK_HIGH	0x00042114
	#define PNIP_REG__ICU2_IRQ0_LOW			0x00042118
	#define PNIP_REG__ICU2_IRQ0_MID			0x0004211c
	#define PNIP_REG__ICU2_IRQ0_HIGH		0x00042120
	#define PNIP_REG__ICU2_IRQ0_ACK_LOW		0x00042124
	#define PNIP_REG__ICU2_IRQ0_ACK_MID		0x00042128
	#define PNIP_REG__ICU2_IRQ0_ACK_HIGH	0x0004212c
	#define PNIP_REG__ICU2_IRQ0_EOI			0x00042130

	#define PNIP_REG__ICU2_IRQ1_EVENT_LOW	0x00042200
	#define PNIP_REG__ICU2_IRQ1_EVENT_MID	0x00042204
	#define PNIP_REG__ICU2_IRQ1_EVENT_HIGH	0x00042208
	#define PNIP_REG__ICU2_IRQ1_MASK_LOW	0x0004220c
	#define PNIP_REG__ICU2_IRQ1_MASK_MID	0x00042210
	#define PNIP_REG__ICU2_IRQ1_MASK_HIGH	0x00042214
	#define PNIP_REG__ICU2_IRQ1_LOW			0x00042218
	#define PNIP_REG__ICU2_IRQ1_MID			0x0004221c
	#define PNIP_REG__ICU2_IRQ1_HIGH		0x00042220
	#define PNIP_REG__ICU2_IRQ1_ACK_LOW		0x00042224
	#define PNIP_REG__ICU2_IRQ1_ACK_MID		0x00042228
	#define PNIP_REG__ICU2_IRQ1_ACK_HIGH	0x0004222c
	#define PNIP_REG__ICU2_IRQ1_EOI			0x00042230

	#define PNIP_REG__MUX2_IRQ2_CONTROL		0x00042300
	#define PNIP_REG__MUX2_IRQ3_CONTROL		0x00042304
	#define PNIP_REG__MUX2_IRQ4_CONTROL		0x00042308
	#define PNIP_REG__MUX2_IRQ5_CONTROL		0x0004230c
	#define PNIP_REG__MUX2_IRQ6_CONTROL		0x00042310
	#define PNIP_REG__MUX2_IRQ7_CONTROL		0x00042314
	#define PNIP_REG__MUX2_IRQ8_CONTROL		0x00042318
	#define PNIP_REG__MUX2_IRQ9_CONTROL		0x0004231c
	#define PNIP_REG__MUX2_IRQ10_CONTROL	0x00042320
	#define PNIP_REG__MUX2_IRQ11_CONTROL	0x00042324
	#define PNIP_REG__MUX2_IRQ12_CONTROL	0x00042328
	#define PNIP_REG__MUX2_IRQ13_CONTROL	0x0004232c
	#define PNIP_REG__MUX2_IRQ14_CONTROL	0x00042330
	#define PNIP_REG__MUX2_IRQ15_CONTROL	0x00042334

	//------------------------------------------------------------------------
	// PNIP-ICU3/MUX3: connected to PERIF-ICU
	//------------------------------------------------------------------------
	#define PNIP_REG__ICU3_CONTROL			0x00043000
	#define PNIP_REG__ICU3_ACTIVATE			0x00043004
	#define PNIP_REG__ICU3_TIME_STAMP		0x00043008

	#define PNIP_REG__ICU3_IRQ0_EVENT_LOW	0x00043100
	#define PNIP_REG__ICU3_IRQ0_EVENT_MID	0x00043104
	#define PNIP_REG__ICU3_IRQ0_EVENT_HIGH	0x00043108
	#define PNIP_REG__ICU3_IRQ0_MASK_LOW	0x0004310c
	#define PNIP_REG__ICU3_IRQ0_MASK_MID	0x00043110
	#define PNIP_REG__ICU3_IRQ0_MASK_HIGH	0x00043114
	#define PNIP_REG__ICU3_IRQ0_LOW			0x00043118
	#define PNIP_REG__ICU3_IRQ0_MID			0x0004311c
	#define PNIP_REG__ICU3_IRQ0_HIGH		0x00043120
	#define PNIP_REG__ICU3_IRQ0_ACK_LOW		0x00043124
	#define PNIP_REG__ICU3_IRQ0_ACK_MID		0x00043128
	#define PNIP_REG__ICU3_IRQ0_ACK_HIGH	0x0004312c
	#define PNIP_REG__ICU3_IRQ0_EOI			0x00043130

	#define PNIP_REG__ICU3_IRQ1_EVENT_LOW	0x00043200
	#define PNIP_REG__ICU3_IRQ1_EVENT_MID	0x00043204
	#define PNIP_REG__ICU3_IRQ1_EVENT_HIGH	0x00043208
	#define PNIP_REG__ICU3_IRQ1_MASK_LOW	0x0004320c
	#define PNIP_REG__ICU3_IRQ1_MASK_MID	0x00043210
	#define PNIP_REG__ICU3_IRQ1_MASK_HIGH	0x00043214
	#define PNIP_REG__ICU3_IRQ1_LOW			0x00043218
	#define PNIP_REG__ICU3_IRQ1_MID			0x0004321c
	#define PNIP_REG__ICU3_IRQ1_HIGH		0x00043220
	#define PNIP_REG__ICU3_IRQ1_ACK_LOW		0x00043224
	#define PNIP_REG__ICU3_IRQ1_ACK_MID		0x00043228
	#define PNIP_REG__ICU3_IRQ1_ACK_HIGH	0x0004322c
	#define PNIP_REG__ICU3_IRQ1_EOI			0x00043230

	#define PNIP_REG__MUX3_IRQ2_CONTROL		0x00043300
	#define PNIP_REG__MUX3_IRQ3_CONTROL		0x00043304
	#define PNIP_REG__MUX3_IRQ4_CONTROL		0x00043308
	#define PNIP_REG__MUX3_IRQ5_CONTROL		0x0004330c
	#define PNIP_REG__MUX3_IRQ6_CONTROL		0x00043310
	#define PNIP_REG__MUX3_IRQ7_CONTROL		0x00043314
	#define PNIP_REG__MUX3_IRQ8_CONTROL		0x00043318
	#define PNIP_REG__MUX3_IRQ9_CONTROL		0x0004331c
	#define PNIP_REG__MUX3_IRQ10_CONTROL	0x00043320
	#define PNIP_REG__MUX3_IRQ11_CONTROL	0x00043324
	#define PNIP_REG__MUX3_IRQ12_CONTROL	0x00043328
	#define PNIP_REG__MUX3_IRQ13_CONTROL	0x0004332c
	#define PNIP_REG__MUX3_IRQ14_CONTROL	0x00043330
	#define PNIP_REG__MUX3_IRQ15_CONTROL	0x00043334

	//========================================================================
	//	PNIP RAM
	//========================================================================

	#define PNIP_RAM__OFFSET_STATISTIC32	0x0000e000
	#define PNIP_RAM__OFFSET_STATISTIC64	0x0000e800
	#define PNIP_RAM__OFFSET_SYNC			0x0003c000
	#define PNIP_RAM__OFFSET_PACK_CTRL		0x00051000
	#define PNIP_RAM__OFFSET_PACK_DATA		0x00058000
	#define PNIP_RAM__OFFSET_CMD			0x00068000
	#define PNIP_RAM__OFFSET_API_CTRL		0x00080000

	// sizes must be divisible by 4!
	#define PNIP_RAM__SIZE_STATISTIC	(512)
	#define PNIP_RAM__SIZE_SYNC			(768)									
	#define PNIP_RAM__SIZE_PACK_CTRL	(0)
	#define PNIP_RAM__SIZE_PACK_DATA	(0)
	#define PNIP_RAM__SIZE_CMD			(1024*8)
	#define PNIP_RAM__SIZE_API_CTRL		(1024*16)

	// sizes must be divisible by 4!
	// only for PNIP Ram Reset after SoftwareReset
	#define PNIP_RAM_HERA__SIZE_STATISTIC	(1024*4)
	#define PNIP_RAM_HERA__SIZE_SYNC		(1024*16)									
	#define PNIP_RAM_HERA__SIZE_CMD			(1024*32)
	#define PNIP_RAM_HERA__SIZE_API_CTRL	(1024*512)

																	// see PNIP or PNComp spec for values
	#define PNIP_RAM_HERA__USED_SIZE_STATISTIC32_IFA	0x480		// (0xE480 - 0xE000)
	#define PNIP_RAM_HERA__USED_SIZE_STATISTIC32_IFB	0x280		// (0xE280 - 0xE000)
	#define PNIP_RAM_HERA__USED_SIZE_STATISTIC64_IFA	0x480		// (0xEC80 - 0xE800)
	#define PNIP_RAM_HERA__USED_SIZE_STATISTIC64_IFB	0x280		// (0xEA80 - 0xE800)
	#define PNIP_RAM_HERA__USED_SIZE_SYNC_IFA			0x500		// (0x3C500 - 0x3C000)
	#define PNIP_RAM_HERA__USED_SIZE_SYNC_IFB			0x300		// (0x3C300 - 0x3C000)
	#define PNIP_RAM_HERA__USED_SIZE_CMD_IFA			0x2800		// (0x6A800 - 0x68000)
	#define PNIP_RAM_HERA__USED_SIZE_CMD_IFB			0x2800		// (0x6A800 - 0x68000)
	#define PNIP_RAM_HERA__USED_SIZE_API_CTRL_IFA		0x28800		// (0xA8800 - 0x80000)
	#define PNIP_RAM_HERA__USED_SIZE_API_CTRL_IFB		0x25800		// (0xA5800 - 0x80000)

	//========================================================================
	//	EMC
	//========================================================================

	#define ERTEC200P_EMC_REG__REV						0x00000000
	#define ERTEC200P_EMC_REG__ASYNC_WAIT_CYCLE			0x00000004
	#define ERTEC200P_EMC_REG__SDRAM_CONFIG				0x00000008
	#define ERTEC200P_EMC_REG__SDRAM_REFRESH			0x0000000c
	#define ERTEC200P_EMC_REG__ASYNC_BANK0				0x00000010
	#define ERTEC200P_EMC_REG__ASYNC_BANK1				0x00000014
	#define ERTEC200P_EMC_REG__ASYNC_BANK2				0x00000018
	#define ERTEC200P_EMC_REG__ASYNC_BANK3				0x0000001c
	#define ERTEC200P_EMC_REG__EXTENDED					0x00000020
	#define ERTEC200P_EMC_REG__ASYNC_TIMEOUT_ADR		0x00000024
	#define ERTEC200P_EMC_REG__LOW_POWER_EXTENDED_MODE	0x00000028
	#define ERTEC200P_EMC_REG__BURST_MODE				0x0000002c
	#define ERTEC200P_EMC_REG__PAGE_MODE				0x00000030
	#define ERTEC200P_EMC_REG__RECOV					0x00000034

	// Register RevisionCode
	#define ERTEC200P_EMC_REV_BIT31_21__ID				0x21


	// Register SDRAM-Refresh
	#define ERTEC200P_EMC_SDRAM_REFRESH__INIT_DONE		(1<<29)

	//========================================================================
	//	ARM-ICU
	//========================================================================

	#define ERTEC200P_ARM_ICU_REG__ID					0x00004000
	#define ERTEC200P_ARM_ICU_REG__IRVEC				0x00004004
	#define ERTEC200P_ARM_ICU_REG__ACK					0x00004008
	#define ERTEC200P_ARM_ICU_REG__IRCLVEC				0x0000400c
	#define ERTEC200P_ARM_ICU_REG__MASKALL				0x00004010
	#define ERTEC200P_ARM_ICU_REG__EOI					0x00004014
	#define ERTEC200P_ARM_ICU_REG__UNLOCK_RD_ONLY_ACK	0x00004018
	#define ERTEC200P_ARM_ICU_REG__MASK_ALL_INPUT_EN	0x0000401c
	#define ERTEC200P_ARM_ICU_REG__LOCK					0x00004020
	#define ERTEC200P_ARM_ICU_REG__MASK0				0x00005000
	#define ERTEC200P_ARM_ICU_REG__MASK1				0x00005004
	#define ERTEC200P_ARM_ICU_REG__MASK2				0x00005008
	#define ERTEC200P_ARM_ICU_REG__IRR0					0x00005100
	#define ERTEC200P_ARM_ICU_REG__IRR1					0x00005104
	#define ERTEC200P_ARM_ICU_REG__IRR2					0x00005108
	#define ERTEC200P_ARM_ICU_REG__ISR0					0x00005200
	#define ERTEC200P_ARM_ICU_REG__ISR1					0x00005204
	#define ERTEC200P_ARM_ICU_REG__ISR2					0x00005208
	#define ERTEC200P_ARM_ICU_REG__TRIG0				0x00005300
	#define ERTEC200P_ARM_ICU_REG__TRIG1				0x00005304
	#define ERTEC200P_ARM_ICU_REG__TRIG2				0x00005308
	#define ERTEC200P_ARM_ICU_REG__EDGE0				0x00005400
	#define ERTEC200P_ARM_ICU_REG__EDGE1				0x00005404
	#define ERTEC200P_ARM_ICU_REG__EDGE2				0x00005408
	#define ERTEC200P_ARM_ICU_REG__SWIIR0				0x00005500
	#define ERTEC200P_ARM_ICU_REG__SWIIR1				0x00005504
	#define ERTEC200P_ARM_ICU_REG__SWIIR2				0x00005508
	#define ERTEC200P_ARM_ICU_REG__PRIO0				0x00006000
	#define ERTEC200P_ARM_ICU_REG__PRIO1				0x00006004
	#define ERTEC200P_ARM_ICU_REG__PRIO2				0x00006008
	#define ERTEC200P_ARM_ICU_REG__PRIO3				0x0000600c
	#define ERTEC200P_ARM_ICU_REG__PRIO4				0x00006010
	#define ERTEC200P_ARM_ICU_REG__PRIO5				0x00006014
	#define ERTEC200P_ARM_ICU_REG__PRIO6				0x00006018
	#define ERTEC200P_ARM_ICU_REG__PRIO7				0x0000601c
	#define ERTEC200P_ARM_ICU_REG__PRIO8				0x00006020
	#define ERTEC200P_ARM_ICU_REG__PRIO9				0x00006024
	#define ERTEC200P_ARM_ICU_REG__PRIO10				0x00006028
	#define ERTEC200P_ARM_ICU_REG__PRIO11				0x0000602c
	#define ERTEC200P_ARM_ICU_REG__PRIO12				0x00006030
	#define ERTEC200P_ARM_ICU_REG__PRIO13				0x00006034
	#define ERTEC200P_ARM_ICU_REG__PRIO14				0x00006038
	#define ERTEC200P_ARM_ICU_REG__PRIO15				0x0000603c
	#define ERTEC200P_ARM_ICU_REG__PRIO16				0x00006040
	#define ERTEC200P_ARM_ICU_REG__PRIO17				0x00006044
	#define ERTEC200P_ARM_ICU_REG__PRIO18				0x00006048
	#define ERTEC200P_ARM_ICU_REG__PRIO19				0x0000604c
	#define ERTEC200P_ARM_ICU_REG__PRIO20				0x00006050
	#define ERTEC200P_ARM_ICU_REG__PRIO21				0x00006054
	#define ERTEC200P_ARM_ICU_REG__PRIO22				0x00006058
	#define ERTEC200P_ARM_ICU_REG__PRIO23				0x0000605c
	#define ERTEC200P_ARM_ICU_REG__PRIO24				0x00006060
	#define ERTEC200P_ARM_ICU_REG__PRIO25				0x00006064
	#define ERTEC200P_ARM_ICU_REG__PRIO26				0x00006068
	#define ERTEC200P_ARM_ICU_REG__PRIO27				0x0000606c
	#define ERTEC200P_ARM_ICU_REG__PRIO28				0x00006070
	#define ERTEC200P_ARM_ICU_REG__PRIO29				0x00006074
	#define ERTEC200P_ARM_ICU_REG__PRIO30				0x00006078
	#define ERTEC200P_ARM_ICU_REG__PRIO31				0x0000607c
	#define ERTEC200P_ARM_ICU_REG__PRIO32				0x00006080
	#define ERTEC200P_ARM_ICU_REG__PRIO33				0x00006084
	#define ERTEC200P_ARM_ICU_REG__PRIO34				0x00006088
	#define ERTEC200P_ARM_ICU_REG__PRIO35				0x0000608c
	#define ERTEC200P_ARM_ICU_REG__PRIO36				0x00006090
	#define ERTEC200P_ARM_ICU_REG__PRIO37				0x00006094
	#define ERTEC200P_ARM_ICU_REG__PRIO38				0x00006098
	#define ERTEC200P_ARM_ICU_REG__PRIO39				0x0000609c
	#define ERTEC200P_ARM_ICU_REG__PRIO40				0x000060a0
	#define ERTEC200P_ARM_ICU_REG__PRIO41				0x000060a4
	#define ERTEC200P_ARM_ICU_REG__PRIO42				0x000060a8
	#define ERTEC200P_ARM_ICU_REG__PRIO43				0x000060ac
	#define ERTEC200P_ARM_ICU_REG__PRIO44				0x000060b0
	#define ERTEC200P_ARM_ICU_REG__PRIO45				0x000060b4
	#define ERTEC200P_ARM_ICU_REG__PRIO46				0x000060b8
	#define ERTEC200P_ARM_ICU_REG__PRIO47				0x000060bc
	#define ERTEC200P_ARM_ICU_REG__PRIO48				0x000060c0
	#define ERTEC200P_ARM_ICU_REG__PRIO49				0x000060c4
	#define ERTEC200P_ARM_ICU_REG__PRIO50				0x000060c8
	#define ERTEC200P_ARM_ICU_REG__PRIO51				0x000060cc
	#define ERTEC200P_ARM_ICU_REG__PRIO52				0x000060d0
	#define ERTEC200P_ARM_ICU_REG__PRIO53				0x000060d4
	#define ERTEC200P_ARM_ICU_REG__PRIO54				0x000060d8
	#define ERTEC200P_ARM_ICU_REG__PRIO55				0x000060dc
	#define ERTEC200P_ARM_ICU_REG__PRIO56				0x000060e0
	#define ERTEC200P_ARM_ICU_REG__PRIO57				0x000060e4
	#define ERTEC200P_ARM_ICU_REG__PRIO58				0x000060e8
	#define ERTEC200P_ARM_ICU_REG__PRIO59				0x000060ec
	#define ERTEC200P_ARM_ICU_REG__PRIO60				0x000060f0
	#define ERTEC200P_ARM_ICU_REG__PRIO61				0x000060f4
	#define ERTEC200P_ARM_ICU_REG__PRIO62				0x000060f8
	#define ERTEC200P_ARM_ICU_REG__PRIO63				0x000060fc
	#define ERTEC200P_ARM_ICU_REG__PRIO64				0x00006100
	#define ERTEC200P_ARM_ICU_REG__PRIO65				0x00006104
	#define ERTEC200P_ARM_ICU_REG__PRIO66				0x00006108
	#define ERTEC200P_ARM_ICU_REG__PRIO67				0x0000610c
	#define ERTEC200P_ARM_ICU_REG__PRIO68				0x00006110
	#define ERTEC200P_ARM_ICU_REG__PRIO69				0x00006114
	#define ERTEC200P_ARM_ICU_REG__PRIO70				0x00006118
	#define ERTEC200P_ARM_ICU_REG__PRIO71				0x0000611c
	#define ERTEC200P_ARM_ICU_REG__PRIO72				0x00006120
	#define ERTEC200P_ARM_ICU_REG__PRIO73				0x00006124
	#define ERTEC200P_ARM_ICU_REG__PRIO74				0x00006128
	#define ERTEC200P_ARM_ICU_REG__PRIO75				0x0000612c
	#define ERTEC200P_ARM_ICU_REG__PRIO76				0x00006130
	#define ERTEC200P_ARM_ICU_REG__PRIO77				0x00006134
	#define ERTEC200P_ARM_ICU_REG__PRIO78				0x00006138
	#define ERTEC200P_ARM_ICU_REG__PRIO79				0x0000613c
	#define ERTEC200P_ARM_ICU_REG__PRIO80				0x00006140
	#define ERTEC200P_ARM_ICU_REG__PRIO81				0x00006144
	#define ERTEC200P_ARM_ICU_REG__PRIO82				0x00006148
	#define ERTEC200P_ARM_ICU_REG__PRIO83				0x0000614c
	#define ERTEC200P_ARM_ICU_REG__PRIO84				0x00006150
	#define ERTEC200P_ARM_ICU_REG__PRIO85				0x00006154
	#define ERTEC200P_ARM_ICU_REG__PRIO86				0x00006158
	#define ERTEC200P_ARM_ICU_REG__PRIO87				0x0000615c
	#define ERTEC200P_ARM_ICU_REG__PRIO88				0x00006160
	#define ERTEC200P_ARM_ICU_REG__PRIO89				0x00006164
	#define ERTEC200P_ARM_ICU_REG__PRIO90				0x00006168
	#define ERTEC200P_ARM_ICU_REG__PRIO91				0x0000616c
	#define ERTEC200P_ARM_ICU_REG__PRIO92				0x00006170
	#define ERTEC200P_ARM_ICU_REG__PRIO93				0x00006174
	#define ERTEC200P_ARM_ICU_REG__PRIO94				0x00006178
	#define ERTEC200P_ARM_ICU_REG__PRIO95				0x0000617c
	//------------------------------------------------------------------------
	// Vector31:0
	//	- fixed mapping: Vector=InputSignal
	//	- 0=DefaultVector -> Vector0 not supported
	#define ERTEC200P_ARM_ICU_VECTOR_LOW__SPI1_COMBINED				13
	#define ERTEC200P_ARM_ICU_VECTOR_LOW__SPI1_OVERRUN_ERROR		14
	#define ERTEC200P_ARM_ICU_VECTOR_LOW__SPI2_COMBINED				15
	#define ERTEC200P_ARM_ICU_VECTOR_LOW__SPI2_OVERRUN_ERROR		16
	#define ERTEC200P_ARM_ICU_VECTOR_LOW__SPI12_PARITY_ERROR		17
	#define ERTEC200P_ARM_ICU_VECTOR_LOW__SPI1_SEND_FIFO_EMPTY		28
	#define ERTEC200P_ARM_ICU_VECTOR_LOW__SPI1_RCVE_FIFO_NOT_EMPTY	29
	#define ERTEC200P_ARM_ICU_VECTOR_LOW__SPI2_SEND_FIFO_EMPTY		30
	#define ERTEC200P_ARM_ICU_VECTOR_LOW__SPI2_RCVE_FIFO_NOT_EMPTY	31

	// Vector63:32
	//	- fixed mapping: Vector=InputSignal
	#define ERTEC200P_ARM_ICU_VECTOR_MID__EXT_GPIO1					33
	#define ERTEC200P_ARM_ICU_VECTOR_MID__EXT_GPIO2					34
	#define ERTEC200P_ARM_ICU_VECTOR_MID__PERIF						54
	#define ERTEC200P_ARM_ICU_VECTOR_MID__PNIP_ICU_IRQ0				56
	#define ERTEC200P_ARM_ICU_VECTOR_MID__PNIP_ICU_IRQ1				57
	#define ERTEC200P_ARM_ICU_VECTOR_MID__PNIP_MUX_IRQ2				58
	#define ERTEC200P_ARM_ICU_VECTOR_MID__PNIP_MUX_IRQ3				59
	#define ERTEC200P_ARM_ICU_VECTOR_MID__PNIP_MUX_IRQ4				60
	#define ERTEC200P_ARM_ICU_VECTOR_MID__PNIP_MUX_IRQ5				61
	#define ERTEC200P_ARM_ICU_VECTOR_MID__PNIP_MUX_IRQ6				62
	#define ERTEC200P_ARM_ICU_VECTOR_MID__PNIP_MUX_IRQ7				63

	// Vector95:64
	//	- fixed mapping: Vector=InputSignal
	#define ERTEC200P_ARM_ICU_VECTOR_HIGH__PNIP_MUX_IRQ8			64
	#define ERTEC200P_ARM_ICU_VECTOR_HIGH__PNIP_MUX_IRQ9			65
	#define ERTEC200P_ARM_ICU_VECTOR_HIGH__PNIP_MUX_IRQ10			66
	#define ERTEC200P_ARM_ICU_VECTOR_HIGH__PNIP_MUX_IRQ11			67
	#define ERTEC200P_ARM_ICU_VECTOR_HIGH__PNIP_MUX_IRQ12			68
	#define ERTEC200P_ARM_ICU_VECTOR_HIGH__PNIP_MUX_IRQ13			69
	#define ERTEC200P_ARM_ICU_VECTOR_HIGH__PNIP_MUX_IRQ14			70
	#define ERTEC200P_ARM_ICU_VECTOR_HIGH__PNIP_MUX_IRQ15			71
	#define ERTEC200P_ARM_ICU_VECTOR_HIGH__PNPLL_OUT9				72
	#define ERTEC200P_ARM_ICU_VECTOR_HIGH__PNPLL_OUT10				73
	#define ERTEC200P_ARM_ICU_VECTOR_HIGH__PNPLL_OUT11				74
	#define ERTEC200P_ARM_ICU_VECTOR_HIGH__PNPLL_OUT12				75
	#define ERTEC200P_ARM_ICU_VECTOR_HIGH__PNPLL_OUT13				76
	#define ERTEC200P_ARM_ICU_VECTOR_HIGH__PNPLL_OUT14				77
	#define ERTEC200P_ARM_ICU_VECTOR_HIGH__95						95
	//------------------------------------------------------------------------
	// Event31:0
	//	- Event=HexValue of Bit x with x=Vector
	#define ERTEC200P_ARM_ICU_EVENT0__SPI1_COMBINED				(1u<<(ERTEC200P_ARM_ICU_VECTOR_LOW__SPI1_COMBINED			-0))
	#define ERTEC200P_ARM_ICU_EVENT0__SPI1_OVERRUN_ERROR		(1u<<(ERTEC200P_ARM_ICU_VECTOR_LOW__SPI1_OVERRUN_ERROR		-0))
	#define ERTEC200P_ARM_ICU_EVENT0__SPI2_COMBINED				(1u<<(ERTEC200P_ARM_ICU_VECTOR_LOW__SPI2_COMBINED			-0))
	#define ERTEC200P_ARM_ICU_EVENT0__SPI2_OVERRUN_ERROR		(1u<<(ERTEC200P_ARM_ICU_VECTOR_LOW__SPI2_OVERRUN_ERROR		-0))
	#define ERTEC200P_ARM_ICU_EVENT0__SPI12_PARITY_ERROR		(1u<<(ERTEC200P_ARM_ICU_VECTOR_LOW__SPI12_PARITY_ERROR		-0))
	#define ERTEC200P_ARM_ICU_EVENT0__SPI1_SEND_FIFO_EMPTY		(1u<<(ERTEC200P_ARM_ICU_VECTOR_LOW__SPI1_SEND_FIFO_EMPTY	-0))
	#define ERTEC200P_ARM_ICU_EVENT0__SPI1_RCVE_FIFO_NOT_EMPTY	(1u<<(ERTEC200P_ARM_ICU_VECTOR_LOW__SPI1_RCVE_FIFO_NOT_EMPTY-0))
	#define ERTEC200P_ARM_ICU_EVENT0__SPI2_SEND_FIFO_EMPTY		(1u<<(ERTEC200P_ARM_ICU_VECTOR_LOW__SPI2_SEND_FIFO_EMPTY	-0))
	#define ERTEC200P_ARM_ICU_EVENT0__SPI2_RCVE_FIFO_NOT_EMPTY	(1u<<(ERTEC200P_ARM_ICU_VECTOR_LOW__SPI2_RCVE_FIFO_NOT_EMPTY-0))

	// Event63:32
	#define ERTEC200P_ARM_ICU_EVENT1__EXT_GPIO1					(1u<<(ERTEC200P_ARM_ICU_VECTOR_MID__EXT_GPIO1		-32))
	#define ERTEC200P_ARM_ICU_EVENT1__EXT_GPIO2					(1u<<(ERTEC200P_ARM_ICU_VECTOR_MID__EXT_GPIO2		-32))
	#define ERTEC200P_ARM_ICU_EVENT1__PERIF						(1u<<(ERTEC200P_ARM_ICU_VECTOR_MID__PERIF			-32))
	#define ERTEC200P_ARM_ICU_EVENT1__PNIP_ICU_IRQ0				(1u<<(ERTEC200P_ARM_ICU_VECTOR_MID__PNIP_ICU_IRQ0	-32))
	#define ERTEC200P_ARM_ICU_EVENT1__PNIP_ICU_IRQ1				(1u<<(ERTEC200P_ARM_ICU_VECTOR_MID__PNIP_ICU_IRQ1	-32))
	#define ERTEC200P_ARM_ICU_EVENT1__PNIP_MUX_IRQ2				(1u<<(ERTEC200P_ARM_ICU_VECTOR_MID__PNIP_MUX_IRQ2	-32))
	#define ERTEC200P_ARM_ICU_EVENT1__PNIP_MUX_IRQ3				(1u<<(ERTEC200P_ARM_ICU_VECTOR_MID__PNIP_MUX_IRQ3	-32))
	#define ERTEC200P_ARM_ICU_EVENT1__PNIP_MUX_IRQ4				(1u<<(ERTEC200P_ARM_ICU_VECTOR_MID__PNIP_MUX_IRQ4	-32))
	#define ERTEC200P_ARM_ICU_EVENT1__PNIP_MUX_IRQ5				(1u<<(ERTEC200P_ARM_ICU_VECTOR_MID__PNIP_MUX_IRQ5	-32))
	#define ERTEC200P_ARM_ICU_EVENT1__PNIP_MUX_IRQ6				(1u<<(ERTEC200P_ARM_ICU_VECTOR_MID__PNIP_MUX_IRQ6	-32))
	#define ERTEC200P_ARM_ICU_EVENT1__PNIP_MUX_IRQ7				(1u<<(ERTEC200P_ARM_ICU_VECTOR_MID__PNIP_MUX_IRQ7	-32))

	// Event95:64
	#define ERTEC200P_ARM_ICU_EVENT2__PNIP_MUX_IRQ8				(1u<<(ERTEC200P_ARM_ICU_VECTOR_HIGH__PNIP_MUX_IRQ8	-64))
	#define ERTEC200P_ARM_ICU_EVENT2__PNIP_MUX_IRQ9				(1u<<(ERTEC200P_ARM_ICU_VECTOR_HIGH__PNIP_MUX_IRQ9	-64))
	#define ERTEC200P_ARM_ICU_EVENT2__PNIP_MUX_IRQ10			(1u<<(ERTEC200P_ARM_ICU_VECTOR_HIGH__PNIP_MUX_IRQ10	-64))
	#define ERTEC200P_ARM_ICU_EVENT2__PNIP_MUX_IRQ11			(1u<<(ERTEC200P_ARM_ICU_VECTOR_HIGH__PNIP_MUX_IRQ11	-64))
	#define ERTEC200P_ARM_ICU_EVENT2__PNIP_MUX_IRQ12			(1u<<(ERTEC200P_ARM_ICU_VECTOR_HIGH__PNIP_MUX_IRQ12	-64))
	#define ERTEC200P_ARM_ICU_EVENT2__PNIP_MUX_IRQ13			(1u<<(ERTEC200P_ARM_ICU_VECTOR_HIGH__PNIP_MUX_IRQ13	-64))
	#define ERTEC200P_ARM_ICU_EVENT2__PNIP_MUX_IRQ14			(1u<<(ERTEC200P_ARM_ICU_VECTOR_HIGH__PNIP_MUX_IRQ14	-64))
	#define ERTEC200P_ARM_ICU_EVENT2__PNIP_MUX_IRQ15			(1u<<(ERTEC200P_ARM_ICU_VECTOR_HIGH__PNIP_MUX_IRQ15	-64))
	#define ERTEC200P_ARM_ICU_EVENT2__PNPLL_OUT9				(1u<<(ERTEC200P_ARM_ICU_VECTOR_HIGH__PNPLL_OUT9		-64))
	#define ERTEC200P_ARM_ICU_EVENT2__PNPLL_OUT10				(1u<<(ERTEC200P_ARM_ICU_VECTOR_HIGH__PNPLL_OUT10	-64))
	#define ERTEC200P_ARM_ICU_EVENT2__PNPLL_OUT11				(1u<<(ERTEC200P_ARM_ICU_VECTOR_HIGH__PNPLL_OUT11	-64))
	#define ERTEC200P_ARM_ICU_EVENT2__PNPLL_OUT12				(1u<<(ERTEC200P_ARM_ICU_VECTOR_HIGH__PNPLL_OUT12	-64))
	#define ERTEC200P_ARM_ICU_EVENT2__PNPLL_OUT13				(1u<<(ERTEC200P_ARM_ICU_VECTOR_HIGH__PNPLL_OUT13	-64))
	#define ERTEC200P_ARM_ICU_EVENT2__PNPLL_OUT14				(1u<<(ERTEC200P_ARM_ICU_VECTOR_HIGH__PNPLL_OUT14	-64))

	//========================================================================
	//	PERIF
	//========================================================================

	// Command-IF Register
	#define	ERTEC200P_PERIF_REG__CMD_IF_CTRL			0x0000
	#define	ERTEC200P_PERIF_REG__CMD_IF_STATUS			0x0004

	// registers for signaling interrupts to Host
	#define	ERTEC200P_PERIF_REG__HOST_IRQ_EVENT_LOW		0x003C
	#define	ERTEC200P_PERIF_REG__HOST_IRQ_EVENT_HIGH	0x0040
	#define	ERTEC200P_PERIF_REG__HOST_IRQ_LOW			0x0008
	#define	ERTEC200P_PERIF_REG__HOST_IRQ_HIGH			0x000C
	#define	ERTEC200P_PERIF_REG__HOST_IRQ_MASK_LOW		0x0010
	#define	ERTEC200P_PERIF_REG__HOST_IRQ_MASK_HIGH		0x0014
	#define	ERTEC200P_PERIF_REG__HOST_IRQ_ACK_LOW		0x0020
	#define	ERTEC200P_PERIF_REG__HOST_IRQ_ACK_HIGH		0x0024
	#define	ERTEC200P_PERIF_REG__HOST_IRQ_EOI			0x0028

	// registers for signaling interrupts to Arm926
	#define	ERTEC200P_PERIF_REG__ARM_IRQ_EVENT_LOW		0x0018
	#define	ERTEC200P_PERIF_REG__ARM_IRQ_EVENT_HIGH		0x001C
	#define	ERTEC200P_PERIF_REG__ARM_IRQ_LOW			0x002C
	#define	ERTEC200P_PERIF_REG__ARM_IRQ_HIGH			0x0030
	#define	ERTEC200P_PERIF_REG__ARM_IRQ_MASK_LOW		0x0034
	#define	ERTEC200P_PERIF_REG__ARM_IRQ_MASK_HIGH		0x0038
	#define	ERTEC200P_PERIF_REG__ARM_IRQ_ACK_LOW		0x0044
	#define	ERTEC200P_PERIF_REG__ARM_IRQ_ACK_HIGH		0x0048
	#define	ERTEC200P_PERIF_REG__ARM_IRQ_EOI			0x004C

	//------------------------------------------------------------------------
	// Register xx0: Event31:0
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__ERR_AHB_HOSTIF		(1u<<0)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__ERR_XHIF_HOSTIF		(1u<<1)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__ERR_SPI_HOSTIF		(1u<<2)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__ERR_BUF_ADR_APP		(1u<<3)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__ERR_BUF_ADR_PNIP		(1u<<4)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__ERR_BUF_STATE_APP	(1u<<5)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__ERR_BUF_STATE_PNIP	(1u<<6)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__NEW_DATA1			(1u<<7)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__NEW_DATA2			(1u<<8)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__NEW_DATA3			(1u<<9)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__NEW_DATA4			(1u<<10)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__NEW_DATA5			(1u<<11)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__NEW_DATA6			(1u<<12)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__NEW_DATA7			(1u<<13)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__NEW_DATA8			(1u<<14)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__NEW_DATA9			(1u<<15)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__PNIP_ICU_IRQ0		(1u<<16)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__PNIP_ICU_IRQ1		(1u<<17)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__PNIP_MUX_IRQ2		(1u<<18)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__PNIP_MUX_IRQ3		(1u<<19)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__PNIP_MUX_IRQ4		(1u<<20)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__PNIP_MUX_IRQ5		(1u<<21)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__PNIP_MUX_IRQ6		(1u<<22)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__PNIP_MUX_IRQ7		(1u<<23)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__PNIP_MUX_IRQ8		(1u<<24)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__PNIP_MUX_IRQ9		(1u<<25)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__PNIP_MUX_IRQ10		(1u<<26)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__PNIP_MUX_IRQ11		(1u<<27)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__PNIP_MUX_IRQ12		(1u<<28)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__PNIP_MUX_IRQ13		(1u<<29)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__PNIP_MUX_IRQ14		(1u<<30)
	#define ERTEC200P_PERIF_ICU_EVENT_LOW__PNIP_MUX_IRQ15		(1u<<31)

	// Register xx1: Event63:32
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT0			(1u<<0)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT1			(1u<<1)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT2			(1u<<2)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT3			(1u<<3)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT4			(1u<<4)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT5			(1u<<5)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT6			(1u<<6)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT7			(1u<<7)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT8			(1u<<8)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT9			(1u<<9)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT10			(1u<<10)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT11			(1u<<11)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT12			(1u<<12)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT13			(1u<<13)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT14			(1u<<14)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT15			(1u<<15)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT16			(1u<<16)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT17			(1u<<17)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT18			(1u<<18)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT19			(1u<<19)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT20			(1u<<20)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT21			(1u<<21)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT22			(1u<<22)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT23			(1u<<23)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT24			(1u<<24)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT25			(1u<<25)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT26			(1u<<26)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT27			(1u<<27)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT28			(1u<<28)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT29			(1u<<29)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT30			(1u<<30)
	#define ERTEC200P_PERIF_ICU_EVENT_HIGH__SW_EVENT31			(1u<<31)



	//########################################################################
	//  Structures
	//########################################################################

	// Note:
	//	- ensure that driver and Asic use the same alignment!
//	#pragma pack(show)
	#pragma pack(push)															// save current packing alignment 
	#pragma pack(1)																// set packing alignment 
//	#pragma pack(show)

	typedef struct _uERTEC200P_SEND_DESC
	{
		UINT32 lTest;
	}
	uERTEC200P_SEND_DESC;

	//------------------------------------------------------------------------
	typedef struct _uERTEC200P_RCVE_DESC
	{
		UINT32	lTest;
	}
	uERTEC200P_RCVE_DESC;

	//------------------------------------------------------------------------
	typedef struct _uERTEC200P_NRT_TABLE
	{
		uERTEC200P_SEND_DESC	uSendDesc[16];
		uERTEC200P_RCVE_DESC	uRcveDesc[32];
	}
	uERTEC200P_NRT_TABLE;

	//------------------------------------------------------------------------
	#pragma pack(pop)															// restore packing alignment 
//	#pragma pack(show)

#endif
