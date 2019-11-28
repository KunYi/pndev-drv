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
/*  F i l e               &F: Flash_SPI.c                               :F&  */
/*                                                                           */
/*  V e r s i o n         &V: BC_PNRUN_P07.01.00.00_00.02.00.05         :V&  */
/*                                                                           */
/*  D a t e  (YYYY-MM-DD) &D: 2018-07-18                                :D&  */
/*                                                                           */
/*****************************************************************************/
//
//  D e s c r i p t i o n:
//
//	Code for boards with SPI Flash
//
//****************************************************************************/

#include "precomp.h"			        // environment specific IncludeFiles
#include "Inc.h"


//************************************************************************
//  D e s c r i p t i o n :
//
//  initializes the SSP (serializer) and GPIOs
//************************************************************************

BOOLEAN fnFlashSPI_SSPInit( DEVICE_EXTENSION*	pDevExtIn,			
                            uPNDEV_FLASH_PAR*	pFlashParIn,
                            const UINT32		lDimErrorIn,
                            _TCHAR*				sErrorOut)
{
_TCHAR	sErrorDetail[PNDEV_SIZE_STRING_BUF] = {0};
BOOLEAN bResult                             = TRUE;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        {
            // <--------------- Init GPIOs -------------------->  
        	
        	if	(pDevExtIn->lBitStreamId == 0x09)
				// Inc 9 - TODO Remove
        	{
				// Reg GPIO_IOCTRL_0 -> Set GPIO[0] to 0 = Output
				WRITE_REG_UINT32(	(pDevExtIn->uHwResKm.uBoard.as.uHera.uApbPer.pPtr + HERA_APB_PER__OFFSET_GPIO + BOARD_FPGA1_HERA__GPIO_IOCTRL_0),
									(READ_REG_UINT32(pDevExtIn->uHwResKm.uBoard.as.uHera.uApbPer.pPtr + HERA_APB_PER__OFFSET_GPIO + BOARD_FPGA1_HERA__GPIO_IOCTRL_0)) & PNDEV_UINT32_CLR_BIT_31);
	
				// Reg GPIO_OUT_SET_0 -> Set GPIO[0] to HIGH
				WRITE_REG_UINT32(	(pDevExtIn->uHwResKm.uBoard.as.uHera.uApbPer.pPtr + HERA_APB_PER__OFFSET_GPIO + BOARD_FPGA1_HERA__GPIO_OUT_SET_0),
									(READ_REG_UINT32(pDevExtIn->uHwResKm.uBoard.as.uHera.uApbPer.pPtr + HERA_APB_PER__OFFSET_GPIO + BOARD_FPGA1_HERA__GPIO_OUT_SET_0)) | PNDEV_UINT32_SET_BIT_31);
	
				// Reg GPIO_PORT_MODE_0_L -> GPIOs[28:30] alternate function A (SPI_3); GPIO[0] gpio function for CS
				WRITE_REG_UINT32(	(pDevExtIn->uHwResKm.uBoard.as.uHera.uApbPer.pPtr + HERA_APB_PER__OFFSET_GPIO + BOARD_FPGA1_HERA__GPIO_PORT_MODE_0_H),
									(READ_REG_UINT32(pDevExtIn->uHwResKm.uBoard.as.uHera.uApbPer.pPtr + HERA_APB_PER__OFFSET_GPIO + BOARD_FPGA1_HERA__GPIO_PORT_MODE_0_H)) | BOARD_FPGA1_HERA__GPIO_PORT_MODE_0_H_SETTINGS);
        	}

			if (pDevExtIn->lBitStreamId >= 0x0c)
				// Inc 12
			{
				// Reg GPIO_IOCTRL_0 -> Set GPIO[57] to 0 = Output
				WRITE_REG_UINT32((pDevExtIn->uHwResKm.uBoard.as.uHera.uApbPer.pPtr + HERA_APB_PER__OFFSET_GPIO + BOARD_FPGA1_HERA__GPIO_IOCTRL_1),
					(READ_REG_UINT32(pDevExtIn->uHwResKm.uBoard.as.uHera.uApbPer.pPtr + HERA_APB_PER__OFFSET_GPIO + BOARD_FPGA1_HERA__GPIO_IOCTRL_1)) & PNDEV_UINT32_CLR_BIT_25);

				// Reg GPIO_OUT_SET_0 -> Set GPIO[57] to HIGH
				WRITE_REG_UINT32((pDevExtIn->uHwResKm.uBoard.as.uHera.uApbPer.pPtr + HERA_APB_PER__OFFSET_GPIO + BOARD_FPGA1_HERA__GPIO_OUT_SET_1),
					(READ_REG_UINT32(pDevExtIn->uHwResKm.uBoard.as.uHera.uApbPer.pPtr + HERA_APB_PER__OFFSET_GPIO + BOARD_FPGA1_HERA__GPIO_OUT_SET_1)) | PNDEV_UINT32_SET_BIT_25);

				// Reg GPIO_PORT_MODE_0_L -> GPIOs[54:56] alternate function A (SPI_3); GPIO[57] gpio function for CS
				WRITE_REG_UINT32((pDevExtIn->uHwResKm.uBoard.as.uHera.uApbPer.pPtr + HERA_APB_PER__OFFSET_GPIO + BOARD_FPGA1_HERA__GPIO_PORT_MODE_1_H),
					(READ_REG_UINT32(pDevExtIn->uHwResKm.uBoard.as.uHera.uApbPer.pPtr + HERA_APB_PER__OFFSET_GPIO + BOARD_FPGA1_HERA__GPIO_PORT_MODE_1_H)) | BOARD_FPGA1_HERA__GPIO_PORT_MODE_1_H_SETTINGS);
			}

            // <--------------- Init SSP -------------------->    
            // serial clock rate 0x31 (=49), Motorola frame format, SPH/SPO = 0, data width 8 Bit
            WRITE_REG_UINT32(	(pFlashParIn->pFlash + BOARD_FPGA1_HERA__SSP_CR0),
						        (READ_REG_UINT32(pFlashParIn->pFlash + BOARD_FPGA1_HERA__SSP_CR0)) | BOARD_FPGA1_HERA__SSP_CR0_SETTINGS);

            // Clock Prescale Devisor 0x2; results in a 500 kHz clock
            WRITE_REG_UINT32(	(pFlashParIn->pFlash + BOARD_FPGA1_HERA__SSP_CPSR),
						        (READ_REG_UINT32(pFlashParIn->pFlash + BOARD_FPGA1_HERA__SSP_CPSR)) | BOARD_FPGA1_HERA__SSP_CPSR_SETTINGS);

            // SSP as SPI-Master, Operation enabled
            WRITE_REG_UINT32(	(pFlashParIn->pFlash + BOARD_FPGA1_HERA__SSP_CR1),
						        (READ_REG_UINT32(pFlashParIn->pFlash + BOARD_FPGA1_HERA__SSP_CR1)) | PNDEV_UINT32_SET_BIT_4);

            pFlashParIn->uSPI.bIsSSPInitialized = TRUE;

            break;
        }
        
        case ePNDEV_BOARD_TI_AM5728:
        {
			// <--------------- Init CM_CORE (Clocks) ------------------->  

			WRITE_REG_UINT32(	(pDevExtIn->uHwResKm.uBoard.as.uAM5728.uCmCore.pPtr + BOARD_TI_AM5728__CM_CORE_OFFSET_CM_L3INSTR_L3_MAIN_2_CLKCTRL),
								(READ_REG_UINT32(pDevExtIn->uHwResKm.uBoard.as.uAM5728.uCtrlModuleCore.pPtr + BOARD_TI_AM5728__CM_CORE_OFFSET_CM_L3INSTR_L3_MAIN_2_CLKCTRL)) | PNDEV_UINT32_SET_BIT_0);

			WRITE_REG_UINT32(	(pDevExtIn->uHwResKm.uBoard.as.uAM5728.uCmCore.pPtr + BOARD_TI_AM5728__CM_CORE_OFFSET_CM_L3INSTR_L3_INSTR_CLKCTRL),
								(READ_REG_UINT32(pDevExtIn->uHwResKm.uBoard.as.uAM5728.uCtrlModuleCore.pPtr + BOARD_TI_AM5728__CM_CORE_OFFSET_CM_L3INSTR_L3_INSTR_CLKCTRL)) | PNDEV_UINT32_SET_BIT_0);

            // <--------------- Init CONTROL_CORE (Pad Multiplexing) ------------------->  
            // This is a multiplexing and has to be set to activate the signals of the QSPI

            // GPMC_A13 --> set 0x0001 --> qspi1_rtclk
            WRITE_REG_UINT32(	(pDevExtIn->uHwResKm.uBoard.as.uAM5728.uCtrlModuleCore.pPtr + BOARD_TI_AM5728__CTRL_CORE_PAD_GPMC_A13), 0x00040001);
            
            // GPMC_A16 --> set 0x0001 --> qspi1_d0
            WRITE_REG_UINT32(	(pDevExtIn->uHwResKm.uBoard.as.uAM5728.uCtrlModuleCore.pPtr + BOARD_TI_AM5728__CTRL_CORE_PAD_GPMC_A16), 0x00040001);

            // GPMC_A17 --> set 0x0001 --> qspi1_d1
            WRITE_REG_UINT32(	(pDevExtIn->uHwResKm.uBoard.as.uAM5728.uCtrlModuleCore.pPtr + BOARD_TI_AM5728__CTRL_CORE_PAD_GPMC_A17), 0x00040001);

            // GPMC_A18 --> set 0x0001 --> qspi1_sclk
            WRITE_REG_UINT32(	(pDevExtIn->uHwResKm.uBoard.as.uAM5728.uCtrlModuleCore.pPtr + BOARD_TI_AM5728__CTRL_CORE_PAD_GPMC_A18), 0x00040001);

            // GPMC_CS2 --> set 0x0001 --> qspi1_cs0
            WRITE_REG_UINT32(	(pDevExtIn->uHwResKm.uBoard.as.uAM5728.uCtrlModuleCore.pPtr + BOARD_TI_AM5728__CTRL_CORE_PAD_GPMC_CS2), 0x00060001);

            // since we are not using qspi_d1/qspi_d2 for dual/quad reads, they are used as SPI Flash HOLD and WP (Write Protect)
            // since we are not using this functionality either, we use the GPIOs to set both signals to a HIGH value, so they do not harm us in any way
            // GPMC_A14 --> set 0x000E --> gpio2_4
            // GPMC_A15 --> set 0x000E --> gpio2_5
			WRITE_REG_UINT32(	(pDevExtIn->uHwResKm.uBoard.as.uAM5728.uCtrlModuleCore.pPtr + BOARD_TI_AM5728__CTRL_CORE_PAD_GPMC_A14), 0x0004000E);

			WRITE_REG_UINT32(	(pDevExtIn->uHwResKm.uBoard.as.uAM5728.uCtrlModuleCore.pPtr + BOARD_TI_AM5728__CTRL_CORE_PAD_GPMC_A15), 0x0004000E);

			WRITE_REG_UINT32(	(pDevExtIn->uHwResKm.uBoard.as.uAM5728.uApbPer.pPtr + BOARD_TI_AM5728__APB_OFFSET_GPIO2_OE),
								(READ_REG_UINT32(pDevExtIn->uHwResKm.uBoard.as.uAM5728.uCtrlModuleCore.pPtr + BOARD_TI_AM5728__APB_OFFSET_GPIO2_OE)) & PNDEV_UINT32_CLR_BIT_5 & PNDEV_UINT32_CLR_BIT_4);

			WRITE_REG_UINT32(	(pDevExtIn->uHwResKm.uBoard.as.uAM5728.uApbPer.pPtr + BOARD_TI_AM5728__APB_OFFSET_GPIO2_DATAOUT),
								(READ_REG_UINT32(pDevExtIn->uHwResKm.uBoard.as.uAM5728.uCtrlModuleCore.pPtr + BOARD_TI_AM5728__APB_OFFSET_GPIO2_DATAOUT)) | PNDEV_UINT32_SET_BIT_5 | PNDEV_UINT32_SET_BIT_4);

            // <--------------- Init QSPI ------------------->  

            // enable QSPI clock generation
			WRITE_REG_UINT32(	(pFlashParIn->pFlash + BOARD_TI_AM5728__QSPI_SPI_CLOCK_CNTRL_REG),
								(READ_REG_UINT32(pFlashParIn->pFlash + BOARD_TI_AM5728__QSPI_SPI_CLOCK_CNTRL_REG)) | PNDEV_UINT32_SET_BIT_31 | PNDEV_UINT32_SET_BIT_8);

            // preset QSPI cmd register, later we just have to set the length in this register
			WRITE_REG_UINT32(	(pFlashParIn->pFlash + BOARD_TI_AM5728__QSPI_SPI_CMD_REG),
								(READ_REG_UINT32(pFlashParIn->pFlash + BOARD_TI_AM5728__QSPI_SPI_CMD_REG)) & 0x00000000 );

			WRITE_REG_UINT32(	(pFlashParIn->pFlash + BOARD_TI_AM5728__QSPI_SPI_CMD_REG),
								(READ_REG_UINT32(pFlashParIn->pFlash + BOARD_TI_AM5728__QSPI_SPI_CMD_REG)) | BOARD_TI_AM5728__QSPI_CMD_REG_DEFAULT );

			pFlashParIn->uSPI.bIsSSPInitialized = TRUE;

            break;
        }

		case ePNDEV_BOARD_CP1625:
		{
			// <--------------- Init GPIOs -------------------->  

			// Reg GPIO_IOCTRL_1 -> Set GPIO[61] to 0 = Output
			WRITE_REG_UINT32((pDevExtIn->uHwResKm.uBoard.as.uSoc1.uApbPer.pPtr + SOC1_APB_PER__OFFSET_GPIO + BOARD_CP1625__GPIO_IOCTRL_1),
				(READ_REG_UINT32(pDevExtIn->uHwResKm.uBoard.as.uSoc1.uApbPer.pPtr + SOC1_APB_PER__OFFSET_GPIO + BOARD_CP1625__GPIO_IOCTRL_1)) & PNDEV_UINT32_CLR_BIT_29);

			// Reg GPIO_OUT_SET_1 -> Set GPIO[61] to HIGH
			WRITE_REG_UINT32((pDevExtIn->uHwResKm.uBoard.as.uSoc1.uApbPer.pPtr + SOC1_APB_PER__OFFSET_GPIO + BOARD_CP1625__GPIO_OUT_SET_1),
				(READ_REG_UINT32(pDevExtIn->uHwResKm.uBoard.as.uSoc1.uApbPer.pPtr + SOC1_APB_PER__OFFSET_GPIO + BOARD_CP1625__GPIO_OUT_SET_1)) | PNDEV_UINT32_SET_BIT_29);

			// Reg GPIO_PORT_MODE_1_H -> GPIOs[58:60] alternate function 0 (SPI); GPIO[61] gpio function for CS
			WRITE_REG_UINT32((pDevExtIn->uHwResKm.uBoard.as.uSoc1.uApbPer.pPtr + SOC1_APB_PER__OFFSET_GPIO + BOARD_CP1625__GPIO_PORT_MODE_1_H),
				(READ_REG_UINT32(pDevExtIn->uHwResKm.uBoard.as.uSoc1.uApbPer.pPtr + SOC1_APB_PER__OFFSET_GPIO + BOARD_CP1625__GPIO_PORT_MODE_1_H)) | BOARD_CP1625__GPIO_PORT_MODE_1_H_SETTINGS);

			// <--------------- Init SSP -------------------->    
			// serial clock rate 0x31 (=49), Motorola frame format, SPH/SPO = 0, data width 8 Bit
			WRITE_REG_UINT32((pFlashParIn->pFlash + BOARD_CP1625__SSP_CR0),
				(READ_REG_UINT32(pFlashParIn->pFlash + BOARD_CP1625__SSP_CR0)) | BOARD_CP1625__SSP_CR0_SETTINGS);

			// Clock Prescale Devisor 0x2; results in a 500 kHz clock
			WRITE_REG_UINT32((pFlashParIn->pFlash + BOARD_CP1625__SSP_CPSR),
				(READ_REG_UINT32(pFlashParIn->pFlash + BOARD_CP1625__SSP_CPSR)) | BOARD_CP1625__SSP_CPSR_SETTINGS);

			// SSP as SPI-Master, Operation enabled
			WRITE_REG_UINT32((pFlashParIn->pFlash + BOARD_CP1625__SSP_CR1),
				(READ_REG_UINT32(pFlashParIn->pFlash + BOARD_CP1625__SSP_CR1)) | PNDEV_UINT32_SET_BIT_4);

			pFlashParIn->uSPI.bIsSSPInitialized = TRUE;

			break;
		}

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_SSPInit - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Enables the chip select for the SPI Flash
//************************************************************************

BOOLEAN	fnFlashSPI_SSPChipSelectEnable( DEVICE_EXTENSION*	pDevExtIn,			
                                        uPNDEV_FLASH_PAR*	pFlashParIn,
                                        const UINT32		lDimErrorIn,
                                        _TCHAR*				sErrorOut)
{
_TCHAR	sErrorDetail[PNDEV_SIZE_STRING_BUF] = {0};
BOOLEAN bResult                             = TRUE;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        {
         
        	if	(pDevExtIn->lBitStreamId == 0x09)
				// Inc 9 - TODO Remove
        	{
                // Reg GPIO_OUT_CLEAR_0 -> set CS (GPIO[0]) LOW
                WRITE_REG_UINT32(	(pDevExtIn->uHwResKm.uBoard.as.uHera.uApbPer.pPtr + HERA_APB_PER__OFFSET_GPIO + BOARD_FPGA1_HERA__GPIO_OUT_CLEAR_0),
    					            (READ_REG_UINT32(pDevExtIn->uHwResKm.uBoard.as.uHera.uApbPer.pPtr + HERA_APB_PER__OFFSET_GPIO + BOARD_FPGA1_HERA__GPIO_OUT_CLEAR_0)) | PNDEV_UINT32_SET_BIT_31);
        	}

			if (pDevExtIn->lBitStreamId >= 0x0c)
				// Inc 12
			{
				// Reg GPIO_OUT_CLEAR_0 -> set CS (GPIO[57]) LOW
				WRITE_REG_UINT32((pDevExtIn->uHwResKm.uBoard.as.uHera.uApbPer.pPtr + HERA_APB_PER__OFFSET_GPIO + BOARD_FPGA1_HERA__GPIO_OUT_CLEAR_1),
					(READ_REG_UINT32(pDevExtIn->uHwResKm.uBoard.as.uHera.uApbPer.pPtr + HERA_APB_PER__OFFSET_GPIO + BOARD_FPGA1_HERA__GPIO_OUT_CLEAR_1)) | PNDEV_UINT32_SET_BIT_25);
			}
           
            break;
        }
        
        case ePNDEV_BOARD_TI_AM5728:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_SSPChipSelectEnable - ePNDEV_BOARD_TI_AM5728 not supported!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);

            break;
        }

		case ePNDEV_BOARD_CP1625:
		{
			// Reg GPIO_OUT_CLEAR_1 -> set CS (GPIO[61]) LOW
			WRITE_REG_UINT32((pDevExtIn->uHwResKm.uBoard.as.uSoc1.uApbPer.pPtr + SOC1_APB_PER__OFFSET_GPIO + BOARD_CP1625__GPIO_OUT_CLEAR_1),
				(READ_REG_UINT32(pDevExtIn->uHwResKm.uBoard.as.uSoc1.uApbPer.pPtr + SOC1_APB_PER__OFFSET_GPIO + BOARD_CP1625__GPIO_OUT_CLEAR_1)) | PNDEV_UINT32_SET_BIT_29);

			break;
		}

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_SSPChipSelectEnable - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Disables the chip select for the SPI Flash
//************************************************************************

BOOLEAN	fnFlashSPI_SSPChipSelectDisable(DEVICE_EXTENSION*	pDevExtIn,			
                                        uPNDEV_FLASH_PAR*	pFlashParIn,
                                        const UINT32		lDimErrorIn,
                                        _TCHAR*				sErrorOut)
{
_TCHAR	sErrorDetail[PNDEV_SIZE_STRING_BUF] = {0};
BOOLEAN bResult                             = TRUE;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        {
        	if	(pDevExtIn->lBitStreamId == 0x09)
        		// Inc 9 - TODO Remove
        	{
        		// Reg GPIO_OUT_0 -> set CS (GPIO[0]) HIGH
        		WRITE_REG_UINT32((pDevExtIn->uHwResKm.uBoard.as.uHera.uApbPer.pPtr + HERA_APB_PER__OFFSET_GPIO + BOARD_FPGA1_HERA__GPIO_OUT_SET_0), PNDEV_UINT32_SET_BIT_31);
        	}

			if (pDevExtIn->lBitStreamId >= 0x0c)
				// Inc 12
			{
				// Reg GPIO_OUT_1 -> set CS (GPIO[57]) HIGH
				WRITE_REG_UINT32((pDevExtIn->uHwResKm.uBoard.as.uHera.uApbPer.pPtr + HERA_APB_PER__OFFSET_GPIO + BOARD_FPGA1_HERA__GPIO_OUT_SET_1), PNDEV_UINT32_SET_BIT_25);
			}
           
            break;
        }

        case ePNDEV_BOARD_TI_AM5728:
        {
			bResult = FALSE;

            // set ErrorDetail
			_RtlStringCchPrintf(sErrorDetail,
								_countof(sErrorDetail),
								_TEXT("(): Error at fnFlashSPI_SSPChipSelectDisable - ePNDEV_BOARD_TI_AM5728 not supported!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);

            break;
        }

		case ePNDEV_BOARD_CP1625:
		{
			// Reg GPIO_OUT_1 -> set CS (GPIO[61]) HIGH
			WRITE_REG_UINT32((pDevExtIn->uHwResKm.uBoard.as.uSoc1.uApbPer.pPtr + SOC1_APB_PER__OFFSET_GPIO + BOARD_CP1625__GPIO_OUT_SET_1), PNDEV_UINT32_SET_BIT_29);

			break;
		}

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_SSPChipSelectDisable - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Waits until the SSP is ready or a timeout occurs
//************************************************************************

BOOLEAN	fnFlashSPI_SSPWaitForReady( DEVICE_EXTENSION*	pDevExtIn,			
                                    uPNDEV_FLASH_PAR*	pFlashParIn,
                                    UINT32              lTimeOutMSIn,
                                    const UINT32		lDimErrorIn,
                                    _TCHAR*				sErrorOut)
{
_TCHAR	sErrorDetail[PNDEV_SIZE_STRING_BUF] = {0};
BOOLEAN bResult                             = TRUE;
UINT32  lTimeOutCounter                     = 0;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        {
            // Read the SSP status register and check if its busy

            if  (lTimeOutMSIn == 0)
                // wait endless
            {
                while ((READ_REG_UINT32(pFlashParIn->pFlash + BOARD_FPGA1_HERA__SSP_SR) & PNDEV_UINT32_SET_BIT_4) == PNDEV_UINT32_SET_BIT_4) 
                {
                    // do nothing
                }
            }
            else
            {
                for ( lTimeOutCounter = 0; lTimeOutCounter < lTimeOutMSIn; lTimeOutCounter++)
                    // timeout max count not reached
                {
                    if ((READ_REG_UINT32(pFlashParIn->pFlash + BOARD_FPGA1_HERA__SSP_SR) & PNDEV_UINT32_SET_BIT_4) == PNDEV_UINT32_SET_BIT_4)
                        // busy bit is set
                    {
                        // wait one millisecond
                        if(!fnDelayThread(  pDevExtIn,
                                            1,
                                            lDimErrorIn,
                                            sErrorOut))
                        {
                            // error
                            bResult = FALSE;
                            break;
                        }
                    }
                    else
                        // SSP is not busy anymore
                    {
                        break;
                    }
                }

                if(lTimeOutCounter == lTimeOutMSIn)
                    // timeout occured
                {
                    bResult = FALSE;
                }
            }

            if  (bResult == FALSE)
                // timeout occured
            {
                // set ErrorDetail
		        _RtlStringCchPrintf(sErrorDetail,
							        _countof(sErrorDetail),
							        _TEXT("(): TimeOut occured at fnFlashSPI_SSPWaitForReady!"));

		        // set ErrorString
		        fnBuildString(	_TEXT(__FUNCTION__),
						        sErrorDetail,
						        NULL,
						        lDimErrorIn,
						        sErrorOut);
            }

            break;
        }
        
        case ePNDEV_BOARD_TI_AM5728:
        {
            // Read the QSPI status register and check if its busy

            if  (lTimeOutMSIn == 0)
                // wait endless
            {
                while ((READ_REG_UINT32(pFlashParIn->pFlash + BOARD_TI_AM5728__QSPI_SPI_STATUS_REG) & PNDEV_UINT32_SET_BIT_0) == PNDEV_UINT32_SET_BIT_0) 
                {
                    // do nothing
                }
            }
            else
            {
                for ( lTimeOutCounter = 0; lTimeOutCounter < lTimeOutMSIn; lTimeOutCounter++)
                    // timeout max count not reached
                {
                    if ((READ_REG_UINT32(pFlashParIn->pFlash + BOARD_TI_AM5728__QSPI_SPI_STATUS_REG) & PNDEV_UINT32_SET_BIT_0) == PNDEV_UINT32_SET_BIT_0)
                        // busy bit is set
                    {
                        // wait one millisecond
                        if(!fnDelayThread(  pDevExtIn,
                                            1,
                                            lDimErrorIn,
                                            sErrorOut))
                        {
                            // error
                            bResult = FALSE;
                            break;
                        }
                    }
                    else
                        // SSP is not busy anymore
                    {
                        break;
                    }
                }

                if(lTimeOutCounter == lTimeOutMSIn)
                    // timeout occured
                {
                    bResult = FALSE;
                }
            }

            if  (bResult == FALSE)
                // timeout occured
            {
                // set ErrorDetail
		        _RtlStringCchPrintf(sErrorDetail,
							        _countof(sErrorDetail),
							        _TEXT("(): TimeOut occured at fnFlashSPI_SSPWaitForReady!"));

		        // set ErrorString
		        fnBuildString(	_TEXT(__FUNCTION__),
						        sErrorDetail,
						        NULL,
						        lDimErrorIn,
						        sErrorOut);
            }

            break;
        }

		case ePNDEV_BOARD_CP1625:
        {
            // Read the SSP status register and check if its busy

            if  (lTimeOutMSIn == 0)
                // wait endless
            {
                while ((READ_REG_UINT32(pFlashParIn->pFlash + BOARD_CP1625__SSP_SR) & PNDEV_UINT32_SET_BIT_4) == PNDEV_UINT32_SET_BIT_4) 
                {
                    // do nothing
                }
            }
            else
            {
                for ( lTimeOutCounter = 0; lTimeOutCounter < lTimeOutMSIn; lTimeOutCounter++)
                    // timeout max count not reached
                {
                    if ((READ_REG_UINT32(pFlashParIn->pFlash + BOARD_CP1625__SSP_SR) & PNDEV_UINT32_SET_BIT_4) == PNDEV_UINT32_SET_BIT_4)
                        // busy bit is set
                    {
                        // wait one millisecond
                        if(!fnDelayThread(  pDevExtIn,
                                            1,
                                            lDimErrorIn,
                                            sErrorOut))
                        {
                            // error
                            bResult = FALSE;
                            break;
                        }
                    }
                    else
                        // SSP is not busy anymore
                    {
                        break;
                    }
                }

                if(lTimeOutCounter == lTimeOutMSIn)
                    // timeout occured
                {
                    bResult = FALSE;
                }
            }

            if  (bResult == FALSE)
                // timeout occured
            {
                // set ErrorDetail
		        _RtlStringCchPrintf(sErrorDetail,
							        _countof(sErrorDetail),
							        _TEXT("(): TimeOut occured at fnFlashSPI_SSPWaitForReady!"));

		        // set ErrorString
		        fnBuildString(	_TEXT(__FUNCTION__),
						        sErrorDetail,
						        NULL,
						        lDimErrorIn,
						        sErrorOut);
            }

            break;
        }

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_SSPWaitForReady - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Configures the SSP before and after a Transmit/Receive
//************************************************************************

BOOLEAN	fnFlashSPI_SSPSetConfiguration( DEVICE_EXTENSION*	pDevExtIn,			
                                        uPNDEV_FLASH_PAR*	pFlashParIn,
                                        SSP_CONFIG_OPTION   optionIn,
                                        const UINT32		lDimErrorIn,
                                        _TCHAR*				sErrorOut)
{
_TCHAR	sErrorDetail[PNDEV_SIZE_STRING_BUF] = {0};
BOOLEAN bResult                             = TRUE;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
		case ePNDEV_BOARD_CP1625:
        {
            switch ( optionIn )
                    // SSP config option
            {
                case SSP_OptionEnableChipSelect:
                {
                    if(!fnFlashSPI_SSPWaitForReady( pDevExtIn,
                                                    pFlashParIn,
                                                    SPI_FLASH_ALL__TIMEOUT_MAX_COUNT,
                                                    lDimErrorIn,
                                                    sErrorOut))
                    {
                        // error
                        bResult = FALSE;
                        break;
                    }
                    else
                    {
                        if(!fnFlashSPI_SSPChipSelectEnable( pDevExtIn,
                                                            pFlashParIn,
                                                            lDimErrorIn,
                                                            sErrorOut))
                        {
                            // error
                            bResult = FALSE;
                            break;
                        }
                    }
            
                    break;
                }
                case SSP_OptionKeepUpChipSelect:
                {
                    // do nothing
                    break;
                }
                case SSP_OptionDisableChipSelect:
                {
                    if(!fnFlashSPI_SSPWaitForReady( pDevExtIn,
                                                    pFlashParIn,
                                                    SPI_FLASH_ALL__TIMEOUT_MAX_COUNT,
                                                    lDimErrorIn,
                                                    sErrorOut))
                    {
                        // error
                        bResult = FALSE;
                        break;
                    }
                    else
                    {
                        if(!fnFlashSPI_SSPChipSelectDisable(pDevExtIn,
                                                            pFlashParIn,
                                                            lDimErrorIn,
                                                            sErrorOut))
                        {
                            // error
                            bResult = FALSE;
                            break;
                        }
                    }
            
                    break;
                }
                case SSP_OptionNull:
                {
                    // do nothing
                    break;
                }
                default:
                {                    
                    bResult = FALSE;

                    // set ErrorDetail
		            _RtlStringCchPrintf(sErrorDetail,
							            _countof(sErrorDetail),
							            _TEXT("(): Error at fnFlashSPI_SSPSetConfiguration - unknown configuration case!"));

		            // set ErrorString
		            fnBuildString(	_TEXT(__FUNCTION__),
						            sErrorDetail,
						            NULL,
						            lDimErrorIn,
						            sErrorOut);
                    break;
                }
            }

            break;
        }        

        case ePNDEV_BOARD_TI_AM5728:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_SSPSetConfiguration - ePNDEV_BOARD_TI_AM5728 not supported!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);

            break;
        }

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_SSPSetConfiguration - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Flushes remaining useless data from Transmit/Receive FIFO
//************************************************************************

BOOLEAN	fnFlashSPI_SSPFlushTransmitReceive( DEVICE_EXTENSION*	pDevExtIn,			
                                            uPNDEV_FLASH_PAR*	pFlashParIn,
                                            const UINT32		lDimErrorIn,
                                            _TCHAR*				sErrorOut)
{
_TCHAR	sErrorDetail[PNDEV_SIZE_STRING_BUF] = {0};
BOOLEAN bResult                             = TRUE;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        {
            // Read data of receive FIFO while the FIFO is not empty
            while((READ_REG_UINT32(pFlashParIn->pFlash + BOARD_FPGA1_HERA__SSP_SR) & 0x0004) != 0x0000)
            {
                WRITE_REG_UINT16((pFlashParIn->pFlash + BOARD_FPGA1_HERA__SSP_DR), BOARD_FPGA1_HERA__SSP_DUMMY_SEND);   // Dummy write necessary to get receive buffer
        
                if(!fnFlashSPI_SSPWaitForReady( pDevExtIn,
                                                pFlashParIn,
                                                SPI_FLASH_ALL__TIMEOUT_MAX_COUNT,
                                                lDimErrorIn,
                                                sErrorOut))
                {
                    // error
                    bResult = FALSE;
                    break;
                }

				// Dummy Read necessary to clear receive buffer
                (void)READ_REG_UINT16(pFlashParIn->pFlash + BOARD_FPGA1_HERA__SSP_DR);   
            }
            
            break;
        }

        case ePNDEV_BOARD_TI_AM5728:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_SSPSetConfiguration - ePNDEV_BOARD_TI_AM5728 not supported!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);

            break;
        }

		case ePNDEV_BOARD_CP1625:
		{
			(void)READ_REG_UINT32(pFlashParIn->pFlash + BOARD_CP1625__SSP_SR);

			// Read data of receive FIFO while the FIFO is not empty
			while ((READ_REG_UINT32(pFlashParIn->pFlash + BOARD_CP1625__SSP_SR) & 0x0004) != 0x0000)
			{
				WRITE_REG_UINT16((pFlashParIn->pFlash + BOARD_CP1625__SSP_DR), BOARD_CP1625__SSP_DUMMY_SEND);   // Dummy write necessary to get receive buffer

				if (!fnFlashSPI_SSPWaitForReady(pDevExtIn,
												pFlashParIn,
												SPI_FLASH_ALL__TIMEOUT_MAX_COUNT,
												lDimErrorIn,
												sErrorOut))
				{
					// error
					bResult = FALSE;
					break;
				}

				// Dummy Read necessary to clear receive buffer
				(void)READ_REG_UINT16(pFlashParIn->pFlash + BOARD_CP1625__SSP_DR);
			}

			break;
		}

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_SSPSetConfiguration - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Transmits/receives data to/from a SPI Flash
//************************************************************************

BOOLEAN	fnFlashSPI_SSPTransmitReceive(  DEVICE_EXTENSION*	pDevExtIn,			
                                        uPNDEV_FLASH_PAR*	pFlashParIn,
                                        SSP_CHARSTREAM*     pStreamTransmitIn,
                                        SSP_CHARSTREAM*     pStreamReceiveOut,
                                        SSP_CONFIG_OPTION   optionBeforeTransmitReceiveIn,
                                        SSP_CONFIG_OPTION   optionAfterTransmitReceiveIn,
                                        const UINT32		lDimErrorIn,
                                        _TCHAR*				sErrorOut)
{
_TCHAR	sErrorDetail[PNDEV_SIZE_STRING_BUF] = {0};
UINT8*  pBufferTransmit                     = NULL; 
UINT8*  pBufferReceive                      = NULL;
UINT32  lLengthTransmit                     = 0;
UINT32  lLengthReceive                      = 0;
BOOLEAN bResult                             = TRUE;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        {
            // Step 1: Initialize SSP
            if(pFlashParIn->uSPI.bIsSSPInitialized == FALSE)
                // SSP is not initialized
            {
                if(!fnFlashSPI_SSPInit( pDevExtIn,
                                        pFlashParIn,
                                        lDimErrorIn,
                                        sErrorOut))
                {
                    // error
                    bResult = FALSE;
                    break;
                }
            }

            // Step 2: Set SSP configuration before Transmit
            if(!fnFlashSPI_SSPSetConfiguration( pDevExtIn,
                                                pFlashParIn,
                                                optionBeforeTransmitReceiveIn,
                                                lDimErrorIn, 
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 3: Prepare data before transmitting
            lLengthTransmit = pStreamTransmitIn->lLength;
            pBufferTransmit = pStreamTransmitIn->pBuffer;

            if (NULL != pStreamReceiveOut)
	        {
                lLengthReceive = pStreamReceiveOut->lLength;
                pBufferReceive = pStreamReceiveOut->pBuffer;
	        }

            // Step 4: Transmit data
            while(lLengthTransmit-- > 0)
            {
                WRITE_REG_UINT16((pFlashParIn->pFlash + BOARD_FPGA1_HERA__SSP_DR), *(pBufferTransmit++));    

                if(!fnFlashSPI_SSPWaitForReady( pDevExtIn,
                                                pFlashParIn,
                                                SPI_FLASH_ALL__TIMEOUT_MAX_COUNT,
                                                lDimErrorIn,
                                                sErrorOut))
                {
                    // error
                    bResult = FALSE;
                    break;
                }

				// Dummy Read necessary to clear receive buffer
                (void)READ_REG_UINT16(pFlashParIn->pFlash + BOARD_FPGA1_HERA__SSP_DR);
            }
    
            // Step 5: Receive data
            if(bResult)
                // transmit ok
            {
                while(lLengthReceive-- > 0)
                {
                    WRITE_REG_UINT16((pFlashParIn->pFlash + BOARD_FPGA1_HERA__SSP_DR), BOARD_FPGA1_HERA__SSP_DUMMY_SEND);   // Dummy write necessary to get receive buffer
        
                    if(!fnFlashSPI_SSPWaitForReady( pDevExtIn,
                                                    pFlashParIn,
                                                    SPI_FLASH_ALL__TIMEOUT_MAX_COUNT,
                                                    lDimErrorIn,
                                                    sErrorOut))
                    {
                        // error
                        bResult = FALSE;
                        break;
                    }

                    if( (READ_REG_UINT32(pFlashParIn->pFlash + BOARD_FPGA1_HERA__SSP_SR) & 0x0004) == 0x0000 )
                        // Receive queue is empty
                    {
                        // increase counter because we have not read anything
                        lLengthReceive++;
                    }
                    else
                    {
                        // receive
                        *pBufferReceive++ = (UINT8)READ_REG_UINT16(pFlashParIn->pFlash + BOARD_FPGA1_HERA__SSP_DR);   
                    }
                }
            }

            // Step 6: Cleanup
            if(bResult)
                // Receive ok
            {
                if(!fnFlashSPI_SSPSetConfiguration( pDevExtIn,
                                                    pFlashParIn,
                                                    optionAfterTransmitReceiveIn,
                                                    lDimErrorIn, 
                                                    sErrorOut))
                {
                    // error
                    bResult = FALSE;
                    break;
                }

                if(!fnFlashSPI_SSPFlushTransmitReceive( pDevExtIn,
                                                        pFlashParIn,
                                                        lDimErrorIn, 
                                                        sErrorOut))
                {
                    // error
                    bResult = FALSE;
                    break;
                }
            }

            break;
        }

        case ePNDEV_BOARD_TI_AM5728:
        {
        UINT32 lLengthSendReceive   = 0;
        UINT32 lCmdRegValue         = 0;

            // Step 1: Initialize SSP
            if(pFlashParIn->uSPI.bIsSSPInitialized == FALSE)
                // SSP is not initialized
            {
                if(!fnFlashSPI_SSPInit( pDevExtIn,
                                        pFlashParIn,
                                        lDimErrorIn,
                                        sErrorOut))
                {
                    // error
                    bResult = FALSE;
                    break;
                }
            }

            // Step 2: Set SSP configuration before Transmit
            // not needed for this flash

            // Step 3: Prepare data before transmitting
            lLengthTransmit = pStreamTransmitIn->lLength;
            pBufferTransmit = pStreamTransmitIn->pBuffer;

            if (NULL != pStreamReceiveOut)
	        {
                lLengthReceive = pStreamReceiveOut->lLength;
                pBufferReceive = pStreamReceiveOut->pBuffer;
	        }

            // calculate all the Byte-Transfers, -1 because in cmd-reg a value of 0x0 = 1 byte
            lLengthSendReceive = (lLengthTransmit + lLengthReceive) - 1;

            // generate the value for the CMD register
            lCmdRegValue = BOARD_TI_AM5728__QSPI_CMD_REG_DEFAULT | lLengthSendReceive;

            // Step 4: Transmit data
            while(lLengthTransmit-- > 0)
            {            
                if(!fnFlashSPI_SSPWaitForReady( pDevExtIn,
                                                pFlashParIn,
                                                SPI_FLASH_ALL__TIMEOUT_MAX_COUNT,
                                                lDimErrorIn,
                                                sErrorOut))
                {
                    // error
                    bResult = FALSE;
                    break;
                }

                // write value to data register
                WRITE_REG_UINT8((pFlashParIn->pFlash + BOARD_TI_AM5728__QSPI_SPI_DATA_REG), *(pBufferTransmit++));    

                if(!fnFlashSPI_SSPWaitForReady( pDevExtIn,
                                                pFlashParIn,
                                                SPI_FLASH_ALL__TIMEOUT_MAX_COUNT,
                                                lDimErrorIn,
                                                sErrorOut))
                {
                    // error
                    bResult = FALSE;
                    break;
                }

                // set cmd register to enable transfer
                WRITE_REG_UINT32((pFlashParIn->pFlash + BOARD_TI_AM5728__QSPI_SPI_CMD_REG), lCmdRegValue);
            }
    
            // Step 5: Receive data
            if(bResult)
                // transmit ok
            {
            UINT32 lTimeOutCounter = 0;

                while(lLengthReceive-- > 0)
                {        
                    if(!fnFlashSPI_SSPWaitForReady( pDevExtIn,
                                                    pFlashParIn,
                                                    SPI_FLASH_ALL__TIMEOUT_MAX_COUNT,
                                                    lDimErrorIn,
                                                    sErrorOut))
                    {
                        // error
                        bResult = FALSE;
                        break;
                    }

                    // set cmd register to enable transfer
                    WRITE_REG_UINT32((pFlashParIn->pFlash + BOARD_TI_AM5728__QSPI_SPI_CMD_REG), lCmdRegValue);

                    for ( lTimeOutCounter = 0; lTimeOutCounter < SPI_FLASH_ALL__TIMEOUT_MAX_COUNT; lTimeOutCounter++)
                    // timeout max count not reached
                    {
                        if( (READ_REG_UINT32(pFlashParIn->pFlash + BOARD_TI_AM5728__QSPI_SPI_STATUS_REG) & 0x0002) == 0x0000 )
                            // Receive queue is empty
                        { 
                            // wait one millisecond
                            if(!fnDelayThread(  pDevExtIn,
                                                1,
                                                lDimErrorIn,
                                                sErrorOut))
                            {
                                // error
                                bResult = FALSE;
                                break;
                            }
                        }
                        else
                        {
                            // receive
                            *pBufferReceive++ = (UINT8)READ_REG_UINT8(pFlashParIn->pFlash + BOARD_TI_AM5728__QSPI_SPI_DATA_REG);   
                            bResult = TRUE;
                            break;
                        }
                    }

                    if(lTimeOutCounter == SPI_FLASH_ALL__TIMEOUT_MAX_COUNT)
                        // timeout occured
                    {
                        bResult = FALSE;
                    }

                    if  (bResult == FALSE)
                        // timeout occured
                    {
                        // set ErrorDetail
		                _RtlStringCchPrintf(sErrorDetail,
							                _countof(sErrorDetail),
							                _TEXT("(): TimeOut occured at fnFlashSPI_SSPTransmitReceive!"));

		                // set ErrorString
		                fnBuildString(	_TEXT(__FUNCTION__),
						                sErrorDetail,
						                NULL,
						                lDimErrorIn,
						                sErrorOut);

                        break;
                    }
                }
            }

            // Step 6: Cleanup
            // not needed for this flash

            break;
        }

		case ePNDEV_BOARD_CP1625:
        {
            // Step 1: Initialize SSP
            if(pFlashParIn->uSPI.bIsSSPInitialized == FALSE)
                // SSP is not initialized
            {
                if(!fnFlashSPI_SSPInit( pDevExtIn,
                                        pFlashParIn,
                                        lDimErrorIn,
                                        sErrorOut))
                {
                    // error
                    bResult = FALSE;
                    break;
                }
            }

            // Step 2: Set SSP configuration before Transmit
            if(!fnFlashSPI_SSPSetConfiguration( pDevExtIn,
                                                pFlashParIn,
                                                optionBeforeTransmitReceiveIn,
                                                lDimErrorIn, 
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 3: Prepare data before transmitting
            lLengthTransmit = pStreamTransmitIn->lLength;
            pBufferTransmit = pStreamTransmitIn->pBuffer;

            if (NULL != pStreamReceiveOut)
	        {
                lLengthReceive = pStreamReceiveOut->lLength;
                pBufferReceive = pStreamReceiveOut->pBuffer;
	        }

            // Step 4: Transmit data
            while(lLengthTransmit-- > 0)
            {
                UINT32	lSRTemp		= 0;
            
                WRITE_REG_UINT16((pFlashParIn->pFlash + BOARD_CP1625__SSP_DR), *(pBufferTransmit++));    

				lSRTemp = READ_REG_UINT32(pFlashParIn->pFlash + BOARD_CP1625__SSP_SR);

				while ((lSRTemp & PNDEV_UINT32_SET_BIT_4) == PNDEV_UINT32_SET_BIT_4)
				{
					lSRTemp = READ_REG_UINT32(pFlashParIn->pFlash + BOARD_CP1625__SSP_SR);
				}

				// Dummy Read necessary to clear receive buffer
                (void)READ_REG_UINT16(pFlashParIn->pFlash + BOARD_CP1625__SSP_DR);
            }
    
            // Step 5: Receive data
            if(bResult)
                // transmit ok
            {
				UINT32 lSRTemp = 0;

                while(lLengthReceive-- > 0)
                {
                    WRITE_REG_UINT16((pFlashParIn->pFlash + BOARD_CP1625__SSP_DR), BOARD_CP1625__SSP_DUMMY_SEND);   // Dummy write necessary to get receive buffer
        
					lSRTemp = READ_REG_UINT32(pFlashParIn->pFlash + BOARD_CP1625__SSP_SR);
                    
					while ((lSRTemp & PNDEV_UINT32_SET_BIT_4) == PNDEV_UINT32_SET_BIT_4)
					{
						lSRTemp = READ_REG_UINT32(pFlashParIn->pFlash + BOARD_CP1625__SSP_SR);
					}	

                    if( (lSRTemp & 0x0004) == 0x0000 )
                        // Receive queue is empty
                    {
                        // increase counter because we have not read anything
                        lLengthReceive++;
                    }
                    else
                    {
                        // receive
                        *pBufferReceive++ = (UINT8)READ_REG_UINT16(pFlashParIn->pFlash + BOARD_CP1625__SSP_DR);   
                    }
                }
            }

            // Step 6: Cleanup
            if(bResult)
                // Receive ok
            {
                if(!fnFlashSPI_SSPSetConfiguration( pDevExtIn,
                                                    pFlashParIn,
                                                    optionAfterTransmitReceiveIn,
                                                    lDimErrorIn, 
                                                    sErrorOut))
                {
                    // error
                    bResult = FALSE;
                    break;
                }

                if(!fnFlashSPI_SSPFlushTransmitReceive( pDevExtIn,
                                                        pFlashParIn,
                                                        lDimErrorIn, 
                                                        sErrorOut))
                {
                    // error
                    bResult = FALSE;
                    break;
                }
            }

            break;
        }

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_SSPTransmitReceive - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Read the ID from SPI Flash
//************************************************************************

BOOLEAN	fnFlashSPI_ReadID(  DEVICE_EXTENSION*	pDevExtIn,
							uPNDEV_FLASH_PAR*	pFlashParIn,
							const UINT32		lOffsetDestIn,
							const UINT32		lSizeBytesIn,
							const BOOLEAN		bEncodedRscIn,
							const UINT32		lDimErrorIn,
							UINT8*				pDataOut,
							_TCHAR*				sErrorOut)
{
_TCHAR	        sErrorDetail[PNDEV_SIZE_STRING_BUF] = { 0 };
SSP_CHARSTREAM  StreamTransmit                      = { 0, NULL };
SSP_CHARSTREAM  StreamReceive                       = { 0, NULL };
UINT8           lArrayInstruction[1]                = { 0 };
BOOLEAN         bResult                             = TRUE;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        {
            // Step 1: Initialize the data (i.e. Instruction) packet to be sent serially

            lArrayInstruction[0]        = SPI_FLASH_N25Q128A__INS_RDID_ALT;

            StreamTransmit.lLength      = 1;
            StreamTransmit.pBuffer      = lArrayInstruction;

            StreamReceive.lLength       = lSizeBytesIn;
            StreamReceive.pBuffer       = pDataOut;

            // Step 2: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                &StreamReceive,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

        case ePNDEV_BOARD_TI_AM5728:
        {
            // Step 1: Initialize the data (i.e. Instruction) packet to be sent serially

            lArrayInstruction[0]        = SPI_FLASH_A25LQ032__INS_RDID;

            StreamTransmit.lLength      = 1;
            StreamTransmit.pBuffer      = lArrayInstruction;

            StreamReceive.lLength       = lSizeBytesIn;
            StreamReceive.pBuffer       = pDataOut;

            // Step 2: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                &StreamReceive,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

		case ePNDEV_BOARD_CP1625:
        {
            // Step 1: Initialize the data (i.e. Instruction) packet to be sent serially

            lArrayInstruction[0]        = SPI_FLASH_M25P10A__INS_RDID;

            StreamTransmit.lLength      = 1;
            StreamTransmit.pBuffer      = lArrayInstruction;

            StreamReceive.lLength       = lSizeBytesIn;
            StreamReceive.pBuffer       = pDataOut;

            // Step 2: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                &StreamReceive,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_ReadID - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Read from SPI Flash
//************************************************************************

BOOLEAN	fnFlashSPI_Read(    DEVICE_EXTENSION*	pDevExtIn,
							uPNDEV_FLASH_PAR*	pFlashParIn,
							const UINT32		lOffsetDestIn,
							const UINT32		lSizeBytesIn,
							const BOOLEAN		bEncodedRscIn,
							const UINT32		lDimErrorIn,
							UINT8*				pDataOut,
							_TCHAR*				sErrorOut)
{
_TCHAR	        sErrorDetail[PNDEV_SIZE_STRING_BUF] = { 0 };
SSP_CHARSTREAM  StreamTransmit                      = { 0, NULL };
SSP_CHARSTREAM  StreamReceive                       = { 0, NULL };
UINT8           lArrayInstruction[4]                = { 0,0,0,0 };
BOOLEAN         bResult                             = TRUE;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        {
            // Step 1: Initialize the data (i.e. Instruction) packet to be sent serially

            // command + 3 byte address
            StreamTransmit.lLength      = 4;
            StreamTransmit.pBuffer      = lArrayInstruction;

            lArrayInstruction[0]        = SPI_FLASH_N25Q128A__INS_READ;
	        lArrayInstruction[1]        = (UINT8)(lOffsetDestIn>>16);
	        lArrayInstruction[2]        = (UINT8)(lOffsetDestIn>>8);
	        lArrayInstruction[3]        = (UINT8)(lOffsetDestIn>>0);

            StreamReceive.lLength       = lSizeBytesIn;
            StreamReceive.pBuffer       = pDataOut;

            // Step 2: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                &StreamReceive,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

        case ePNDEV_BOARD_TI_AM5728:
        {
            // Step 1: Initialize the data (i.e. Instruction) packet to be sent serially

            // command + 3 byte address
            StreamTransmit.lLength      = 4;
            StreamTransmit.pBuffer      = lArrayInstruction;

            lArrayInstruction[0]        = SPI_FLASH_A25LQ032__INS_READ;
	        lArrayInstruction[1]        = (UINT8)(lOffsetDestIn>>16);
	        lArrayInstruction[2]        = (UINT8)(lOffsetDestIn>>8);
	        lArrayInstruction[3]        = (UINT8)(lOffsetDestIn>>0);

            StreamReceive.lLength       = lSizeBytesIn;
            StreamReceive.pBuffer       = pDataOut;

            // Step 2: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                &StreamReceive,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }
            
            break;
        }

		case ePNDEV_BOARD_CP1625:
        {
            // Step 1: Initialize the data (i.e. Instruction) packet to be sent serially

            // command + 3 byte address
            StreamTransmit.lLength      = 4;
            StreamTransmit.pBuffer      = lArrayInstruction;

            lArrayInstruction[0]        = SPI_FLASH_M25P10A__INS_READ;
	        lArrayInstruction[1]        = (UINT8)(lOffsetDestIn>>16);
	        lArrayInstruction[2]        = (UINT8)(lOffsetDestIn>>8);
	        lArrayInstruction[3]        = (UINT8)(lOffsetDestIn>>0);

            StreamReceive.lLength       = lSizeBytesIn;
            StreamReceive.pBuffer       = pDataOut;

            // Step 2: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                &StreamReceive,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_Read - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Read Flag Status Register from SPI Flash
//************************************************************************

BOOLEAN	fnFlashSPI_ReadFlagStatusRegister(  DEVICE_EXTENSION*	pDevExtIn,
							                uPNDEV_FLASH_PAR*	pFlashParIn,
							                const UINT32		lDimErrorIn,
							                UINT8*				pDataOut,
							                _TCHAR*				sErrorOut)
{
_TCHAR	        sErrorDetail[PNDEV_SIZE_STRING_BUF] = { 0 };
SSP_CHARSTREAM  StreamTransmit                      = { 0, NULL };
SSP_CHARSTREAM  StreamReceive                       = { 0, NULL };
UINT8           lArrayInstruction[1]                = { 0 };
BOOLEAN         bResult                             = TRUE;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        {
            // Step 1: Initialize the data (i.e. Instruction) packet to be sent serially
            StreamTransmit.lLength      = 1;
            StreamTransmit.pBuffer      = lArrayInstruction;
            lArrayInstruction[0]        = SPI_FLASH_N25Q128A__INS_RFSR;

            StreamReceive.lLength       = 1;
            StreamReceive.pBuffer       = pDataOut;

            // Step 2: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                &StreamReceive,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

        case ePNDEV_BOARD_TI_AM5728:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_ReadFlagStatusRegister - ePNDEV_BOARD_TI_AM5728 not supported!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);

            break;
        }

		case ePNDEV_BOARD_CP1625:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_ReadFlagStatusRegister - ePNDEV_BOARD_CP1625 not supported!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);

            break;
        }

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_ReadFlagStatusRegister - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Clear Flag Status Register from SPI Flash
//************************************************************************

BOOLEAN	fnFlashSPI_ClearFlagStatusRegister( DEVICE_EXTENSION*	pDevExtIn,
							                uPNDEV_FLASH_PAR*	pFlashParIn,
							                const UINT32		lDimErrorIn,
							                _TCHAR*				sErrorOut)
{
_TCHAR	        sErrorDetail[PNDEV_SIZE_STRING_BUF] = { 0 };
SSP_CHARSTREAM  StreamTransmit                      = { 0, NULL };
UINT8           lArrayInstruction[1]                = { 0 };
BOOLEAN         bResult                             = TRUE;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        {
            // Step 1: Initialize the data (i.e. Instruction) packet to be sent serially
            StreamTransmit.lLength      = 1;
            StreamTransmit.pBuffer      = lArrayInstruction;
            lArrayInstruction[0]        = SPI_FLASH_N25Q128A__INS_CLFSR;

            // Step 2: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                NULL,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

        case ePNDEV_BOARD_TI_AM5728:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_ClearFlagStatusRegister - ePNDEV_BOARD_TI_AM5728 not supported!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);

            break;
        }

		case ePNDEV_BOARD_CP1625:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_ClearFlagStatusRegister - ePNDEV_BOARD_CP1625 not supported!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);

            break;
        }

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_ClearFlagStatusRegister - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Read Flag Status Register from SPI Flash and check for errors
//************************************************************************

BOOLEAN	fnFlashSPI_CheckForErrors(  DEVICE_EXTENSION*	pDevExtIn,
							        uPNDEV_FLASH_PAR*	pFlashParIn,
                                    const UINT32		lDimErrorIn,
							        _TCHAR*				sErrorOut)
{
_TCHAR	        sErrorDetail[PNDEV_SIZE_STRING_BUF] = { 0 };
UINT8           cFlagStatusRegister                 = 0;
BOOLEAN         bResult                             = TRUE;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        {
            // Step 1: Read the Flags
            if(!fnFlashSPI_ReadFlagStatusRegister(  pDevExtIn,
                                                    pFlashParIn,
                                                    lDimErrorIn,
                                                    &cFlagStatusRegister,
                                                    sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 2: Clear the Flags
            if(!fnFlashSPI_ClearFlagStatusRegister( pDevExtIn,
                                                    pFlashParIn,
                                                    lDimErrorIn,
                                                    sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 3: Check all the flags for possible errors
            if((cFlagStatusRegister & SPI_FLASH_N25Q128A__FSR_PROT) == SPI_FLASH_N25Q128A__FSR_PROT)
                // Protection error
            {
                bResult = FALSE;

                // set ErrorDetail
		        _RtlStringCchPrintf(sErrorDetail,
							        _countof(sErrorDetail),
							        _TEXT("(): fnFlashSPI_CheckForErrors - Flash Protection Error!"));

		        // set ErrorString
		        fnBuildString(	_TEXT(__FUNCTION__),
						        sErrorDetail,
						        NULL,
						        lDimErrorIn,
						        sErrorOut);
            }
            else
            {
                if((cFlagStatusRegister & SPI_FLASH_N25Q128A__FSR_VPP) == SPI_FLASH_N25Q128A__FSR_VPP)
                    // Voltage error
                {
                    bResult = FALSE;

                    // set ErrorDetail
		            _RtlStringCchPrintf(sErrorDetail,
							            _countof(sErrorDetail),
							            _TEXT("(): fnFlashSPI_CheckForErrors - Flash Voltage Error!"));

		            // set ErrorString
		            fnBuildString(	_TEXT(__FUNCTION__),
						            sErrorDetail,
						            NULL,
						            lDimErrorIn,
						            sErrorOut);
                }
                else
                {
                    if((cFlagStatusRegister & SPI_FLASH_N25Q128A__FSR_PROGRAM) == SPI_FLASH_N25Q128A__FSR_PROGRAM)
                        // Program error
                    {
                        bResult = FALSE;

                        // set ErrorDetail
		                _RtlStringCchPrintf(sErrorDetail,
							                _countof(sErrorDetail),
							                _TEXT("(): fnFlashSPI_CheckForErrors - Flash Program failed!"));

		                // set ErrorString
		                fnBuildString(	_TEXT(__FUNCTION__),
						                sErrorDetail,
						                NULL,
						                lDimErrorIn,
						                sErrorOut);
                    }
                    else
                    {
                        if((cFlagStatusRegister & SPI_FLASH_N25Q128A__FSR_ERASE) == SPI_FLASH_N25Q128A__FSR_ERASE)
                            // Erase error
                        {
                            bResult = FALSE;

                            // set ErrorDetail
		                    _RtlStringCchPrintf(sErrorDetail,
							                    _countof(sErrorDetail),
							                    _TEXT("(): fnFlashSPI_CheckForErrors - Flash Erase failed!"));

		                    // set ErrorString
		                    fnBuildString(	_TEXT(__FUNCTION__),
						                    sErrorDetail,
						                    NULL,
						                    lDimErrorIn,
						                    sErrorOut);
                        }
                    }
                }
            }

            break;
        }

        case ePNDEV_BOARD_TI_AM5728:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_CheckForErrors - ePNDEV_BOARD_TI_AM5728 not supported!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);

            break;
        }

		case ePNDEV_BOARD_CP1625:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_CheckForErrors - ePNDEV_BOARD_CP1625 not supported!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);

            break;
        }

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_CheckForErrors - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Read Status Register from SPI Flash
//************************************************************************

BOOLEAN	fnFlashSPI_ReadStatusRegister(  DEVICE_EXTENSION*	pDevExtIn,
							            uPNDEV_FLASH_PAR*	pFlashParIn,
							            const UINT32		lDimErrorIn,
							            UINT8*				pDataOut,
							            _TCHAR*				sErrorOut)
{
_TCHAR	        sErrorDetail[PNDEV_SIZE_STRING_BUF] = { 0 };
SSP_CHARSTREAM  StreamTransmit                      = { 0, NULL };
SSP_CHARSTREAM  StreamReceive                       = { 0, NULL };
UINT8           lArrayInstruction[1]                = { 0 };
BOOLEAN         bResult                             = TRUE;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        {
            // Step 1: Initialize the data (i.e. Instruction) packet to be sent serially
            StreamTransmit.lLength      = 1;
            StreamTransmit.pBuffer      = lArrayInstruction;
            lArrayInstruction[0]        = SPI_FLASH_N25Q128A__INS_RDSR;

            StreamReceive.lLength       = 1;
            StreamReceive.pBuffer       = pDataOut;

            // Step 2: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                &StreamReceive,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

        case ePNDEV_BOARD_TI_AM5728:
        {
            // Step 1: Initialize the data (i.e. Instruction) packet to be sent serially
            StreamTransmit.lLength      = 1;
            StreamTransmit.pBuffer      = lArrayInstruction;
            lArrayInstruction[0]        = SPI_FLASH_A25LQ032__INS_RDSR1;

            StreamReceive.lLength       = 1;
            StreamReceive.pBuffer       = pDataOut;

            // Step 2: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                &StreamReceive,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

		case ePNDEV_BOARD_CP1625:
        {
            // Step 1: Initialize the data (i.e. Instruction) packet to be sent serially
            StreamTransmit.lLength      = 1;
            StreamTransmit.pBuffer      = lArrayInstruction;
            lArrayInstruction[0]        = SPI_FLASH_M25P10A__INS_RDSR;

            StreamReceive.lLength       = 1;
            StreamReceive.pBuffer       = pDataOut;

            // Step 2: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                &StreamReceive,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_ReadStatusRegister - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Write to Status Register of SPI Flash
//************************************************************************

BOOLEAN	fnFlashSPI_WriteStatusRegister( DEVICE_EXTENSION*	pDevExtIn,
							            uPNDEV_FLASH_PAR*	pFlashParIn,
							            const UINT32		lDimErrorIn,
							            UINT8				lDataIn,
							            _TCHAR*				sErrorOut)
{
_TCHAR	        sErrorDetail[PNDEV_SIZE_STRING_BUF] = { 0 };
SSP_CHARSTREAM  StreamTransmit                      = { 0, NULL };
UINT8           lArrayInstruction[2]                = { 0,0 };
BOOLEAN         bResult                             = TRUE;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        {            
            // Step 1: Enable writing on chip
            if(!fnFlashSPI_WriteEnable( pDevExtIn,
                                        pFlashParIn,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 2: Initialize the data (i.e. Instruction) packet to be sent serially
            StreamTransmit.lLength      = 2;
            StreamTransmit.pBuffer      = lArrayInstruction;
            lArrayInstruction[0]        = SPI_FLASH_N25Q128A__INS_WRSR;
            lArrayInstruction[1]        = lDataIn;

            // Step 3: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                NULL,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 4: Wait for completion
            if(!fnFlashSPI_WaitForReady(pDevExtIn,
                                        pFlashParIn,
                                        SPI_FLASH_ALL__TIMEOUT_MAX_COUNT,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

        case ePNDEV_BOARD_TI_AM5728:
        {
            // Step 1: Enable writing on chip
            if(!fnFlashSPI_WriteEnable( pDevExtIn,
                                        pFlashParIn,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 2: Initialize the data (i.e. Instruction) packet to be sent serially
            StreamTransmit.lLength      = 2;
            StreamTransmit.pBuffer      = lArrayInstruction;
            lArrayInstruction[0]        = SPI_FLASH_A25LQ032__INS_WRSR;
            lArrayInstruction[1]        = lDataIn;

            // Step 3: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                NULL,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 4: Wait for completion
            if(!fnFlashSPI_WaitForReady(pDevExtIn,
                                        pFlashParIn,
                                        SPI_FLASH_ALL__TIMEOUT_MAX_COUNT,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

		case ePNDEV_BOARD_CP1625:
        {            
            // Step 1: Enable writing on chip
            if(!fnFlashSPI_WriteEnable( pDevExtIn,
                                        pFlashParIn,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 2: Initialize the data (i.e. Instruction) packet to be sent serially
            StreamTransmit.lLength      = 2;
            StreamTransmit.pBuffer      = lArrayInstruction;
            lArrayInstruction[0]        = SPI_FLASH_M25P10A__INS_WRSR;
            lArrayInstruction[1]        = lDataIn;

            // Step 3: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                NULL,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 4: Wait for completion
            if(!fnFlashSPI_WaitForReady(pDevExtIn,
                                        pFlashParIn,
                                        SPI_FLASH_ALL__TIMEOUT_MAX_COUNT,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_WriteStatusRegister - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Try to enable the write latch bit of SPI Flash or a timeout occurs
//************************************************************************

BOOLEAN	fnFlashSPI_WriteEnable( DEVICE_EXTENSION*	pDevExtIn,
							    uPNDEV_FLASH_PAR*	pFlashParIn,
							    const UINT32		lDimErrorIn,
							    _TCHAR*				sErrorOut)
{
_TCHAR	        sErrorDetail[PNDEV_SIZE_STRING_BUF] = { 0 };
SSP_CHARSTREAM  StreamTransmit                      = { 0, NULL };
UINT8           lArrayInstruction[1]                = { 0 };
BOOLEAN         bResult                             = TRUE;
UINT8           cStatusRegister                     = 0;
UINT32          lTimeOutCounter                     = 0;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        {
            // Step 1: Initialize the data (i.e. Instruction) packet to be sent serially
            StreamTransmit.lLength      = 1;
            StreamTransmit.pBuffer      = lArrayInstruction;
            lArrayInstruction[0]        = SPI_FLASH_N25Q128A__INS_WREN;

            // Step 2: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                NULL,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 3: Read the Status Register if write enable latch is set and set a timeout
            for ( lTimeOutCounter = 0; lTimeOutCounter < SPI_FLASH_ALL__TIMEOUT_MAX_COUNT; lTimeOutCounter++)
                // timeout max count not reached
            {
                if(!fnFlashSPI_ReadStatusRegister(  pDevExtIn,
                                                    pFlashParIn,
                                                    lDimErrorIn,
                                                    &cStatusRegister,
                                                    sErrorOut))
                {
                    // error
                    bResult = FALSE;
                    break;
                }

                if (~cStatusRegister & SPI_FLASH_N25Q128A__SR_WEL)
                    // write enable latch bit is not set
                {
                    // wait one millisecond
                    if(!fnDelayThread(  pDevExtIn,
                                        1,
                                        lDimErrorIn,
                                        sErrorOut))
                    {
                        // error
                        bResult = FALSE;
                        break;
                    }
                }
                else
                    // write enable latch bit is set
                {
                    break;
                }
            }

            if  (bResult == FALSE)
                // timeout occured
            {
                // set ErrorDetail
		        _RtlStringCchPrintf(sErrorDetail,
							        _countof(sErrorDetail),
							        _TEXT("(): TimeOut occured at fnFlashSPI_WriteEnable!"));

		        // set ErrorString
		        fnBuildString(	_TEXT(__FUNCTION__),
						        sErrorDetail,
						        NULL,
						        lDimErrorIn,
						        sErrorOut);
            }

            break;
        }

        case ePNDEV_BOARD_TI_AM5728:
        {
            // Step 1: Initialize the data (i.e. Instruction) packet to be sent serially
            StreamTransmit.lLength      = 1;
            StreamTransmit.pBuffer      = lArrayInstruction;
            lArrayInstruction[0]        = SPI_FLASH_A25LQ032__INS_WREN;

            // Step 2: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                NULL,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 3: Read the Status Register if write enable latch is set and set a timeout
            for ( lTimeOutCounter = 0; lTimeOutCounter < SPI_FLASH_ALL__TIMEOUT_MAX_COUNT; lTimeOutCounter++)
                // timeout max count not reached
            {
                if(!fnFlashSPI_ReadStatusRegister(  pDevExtIn,
                                                    pFlashParIn,
                                                    lDimErrorIn,
                                                    &cStatusRegister,
                                                    sErrorOut))
                {
                    // error
                    bResult = FALSE;
                    break;
                }

                if (~cStatusRegister & SPI_FLASH_A25LQ032__SR_WEL)
                    // write enable latch bit is not set
                {
                    // wait one millisecond
                    if(!fnDelayThread(  pDevExtIn,
                                        1,
                                        lDimErrorIn,
                                        sErrorOut))
                    {
                        // error
                        bResult = FALSE;
                        break;
                    }
                }
                else
                    // write enable latch bit is set
                {
                    break;
                }
            }

            if  (bResult == FALSE)
                // timeout occured
            {
                // set ErrorDetail
		        _RtlStringCchPrintf(sErrorDetail,
							        _countof(sErrorDetail),
							        _TEXT("(): TimeOut occured at fnFlashSPI_WriteEnable!"));

		        // set ErrorString
		        fnBuildString(	_TEXT(__FUNCTION__),
						        sErrorDetail,
						        NULL,
						        lDimErrorIn,
						        sErrorOut);
            }

            break;
        }

		case ePNDEV_BOARD_CP1625:
        {
            // Step 1: Initialize the data (i.e. Instruction) packet to be sent serially
            StreamTransmit.lLength      = 1;
            StreamTransmit.pBuffer      = lArrayInstruction;
            lArrayInstruction[0]        = SPI_FLASH_M25P10A__INS_WREN;

            // Step 2: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                NULL,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 3: Read the Status Register if write enable latch is set and set a timeout
            for ( lTimeOutCounter = 0; lTimeOutCounter < SPI_FLASH_ALL__TIMEOUT_MAX_COUNT; lTimeOutCounter++)
                // timeout max count not reached
            {
                if(!fnFlashSPI_ReadStatusRegister(  pDevExtIn,
                                                    pFlashParIn,
                                                    lDimErrorIn,
                                                    &cStatusRegister,
                                                    sErrorOut))
                {
                    // error
                    bResult = FALSE;
                    break;
                }

                if (~cStatusRegister & SPI_FLASH_M25P10A__SR_WEL)
                    // write enable latch bit is not set
                {
                    // wait one millisecond
                    if(!fnDelayThread(  pDevExtIn,
                                        1,
                                        lDimErrorIn,
                                        sErrorOut))
                    {
                        // error
                        bResult = FALSE;
                        break;
                    }
                }
                else
                    // write enable latch bit is set
                {
                    break;
                }
            }

            if  (bResult == FALSE)
                // timeout occured
            {
                // set ErrorDetail
		        _RtlStringCchPrintf(sErrorDetail,
							        _countof(sErrorDetail),
							        _TEXT("(): TimeOut occured at fnFlashSPI_WriteEnable!"));

		        // set ErrorString
		        fnBuildString(	_TEXT(__FUNCTION__),
						        sErrorDetail,
						        NULL,
						        lDimErrorIn,
						        sErrorOut);
            }

            break;
        }

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_WriteEnable - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Try to disable the write latch bit of SPI Flash or a timeout occurs
//************************************************************************

BOOLEAN	fnFlashSPI_WriteDisable(DEVICE_EXTENSION*	pDevExtIn,
							    uPNDEV_FLASH_PAR*	pFlashParIn,
							    const UINT32		lDimErrorIn,
							    _TCHAR*				sErrorOut)
{
_TCHAR	        sErrorDetail[PNDEV_SIZE_STRING_BUF] = { 0 };
SSP_CHARSTREAM  StreamTransmit                      = { 0, NULL };
UINT8           lArrayInstruction[1]                = { 0 };
BOOLEAN         bResult                             = TRUE;
UINT8           cStatusRegister                     = 0;
UINT32          lTimeOutCounter                     = 0;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        {
            // Step 1: Initialize the data (i.e. Instruction) packet to be sent serially
            StreamTransmit.lLength      = 1;
            StreamTransmit.pBuffer      = lArrayInstruction;
            lArrayInstruction[0]        = SPI_FLASH_N25Q128A__INS_WRDI;

            // Step 2: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                NULL,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 3: Read the Status Register if write enable latch is set and set a timeout
            for ( lTimeOutCounter = 0; lTimeOutCounter < SPI_FLASH_ALL__TIMEOUT_MAX_COUNT; lTimeOutCounter++)
                // timeout max count not reached
            {
                if(!fnFlashSPI_ReadStatusRegister(  pDevExtIn,
                                                    pFlashParIn,
                                                    lDimErrorIn,
                                                    &cStatusRegister,
                                                    sErrorOut))
                {
                    // error
                    bResult = FALSE;
                    break;
                }

                if (cStatusRegister & SPI_FLASH_N25Q128A__SR_WEL)
                    // write enable latch bit is set
                {
                    // wait one millisecond
                    if(!fnDelayThread(  pDevExtIn,
                                        1,
                                        lDimErrorIn,
                                        sErrorOut))
                    {
                        // error
                        bResult = FALSE;
                        break;
                    }
                }
                else
                    // write enable latch bit is not set
                {
                    break;
                }
            }

            if  (bResult == FALSE)
                // timeout occured
            {
                // set ErrorDetail
		        _RtlStringCchPrintf(sErrorDetail,
							        _countof(sErrorDetail),
							        _TEXT("(): TimeOut occured at fnFlashSPI_WriteDisable!"));

		        // set ErrorString
		        fnBuildString(	_TEXT(__FUNCTION__),
						        sErrorDetail,
						        NULL,
						        lDimErrorIn,
						        sErrorOut);
            }

            break;
        }

        case ePNDEV_BOARD_TI_AM5728:
        {
            // Step 1: Initialize the data (i.e. Instruction) packet to be sent serially
            StreamTransmit.lLength      = 1;
            StreamTransmit.pBuffer      = lArrayInstruction;
            lArrayInstruction[0]        = SPI_FLASH_A25LQ032__INS_WRDI;

            // Step 2: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                NULL,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 3: Read the Status Register if write enable latch is set and set a timeout
            for ( lTimeOutCounter = 0; lTimeOutCounter < SPI_FLASH_ALL__TIMEOUT_MAX_COUNT; lTimeOutCounter++)
                // timeout max count not reached
            {
                if(!fnFlashSPI_ReadStatusRegister(  pDevExtIn,
                                                    pFlashParIn,
                                                    lDimErrorIn,
                                                    &cStatusRegister,
                                                    sErrorOut))
                {
                    // error
                    bResult = FALSE;
                    break;
                }

                if (cStatusRegister & SPI_FLASH_A25LQ032__SR_WEL)
                    // write enable latch bit is set
                {
                    // wait one millisecond
                    if(!fnDelayThread(  pDevExtIn,
                                        1,
                                        lDimErrorIn,
                                        sErrorOut))
                    {
                        // error
                        bResult = FALSE;
                        break;
                    }
                }
                else
                    // write enable latch bit is not set
                {
                    break;
                }
            }

            if  (bResult == FALSE)
                // timeout occured
            {
                // set ErrorDetail
		        _RtlStringCchPrintf(sErrorDetail,
							        _countof(sErrorDetail),
							        _TEXT("(): TimeOut occured at fnFlashSPI_WriteDisable!"));

		        // set ErrorString
		        fnBuildString(	_TEXT(__FUNCTION__),
						        sErrorDetail,
						        NULL,
						        lDimErrorIn,
						        sErrorOut);
            }

            break;
        }

		case ePNDEV_BOARD_CP1625:
        {
            // Step 1: Initialize the data (i.e. Instruction) packet to be sent serially
            StreamTransmit.lLength      = 1;
            StreamTransmit.pBuffer      = lArrayInstruction;
            lArrayInstruction[0]        = SPI_FLASH_M25P10A__INS_WRDI;

            // Step 2: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                NULL,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 3: Read the Status Register if write enable latch is set and set a timeout
            for ( lTimeOutCounter = 0; lTimeOutCounter < SPI_FLASH_ALL__TIMEOUT_MAX_COUNT; lTimeOutCounter++)
                // timeout max count not reached
            {
                if(!fnFlashSPI_ReadStatusRegister(  pDevExtIn,
                                                    pFlashParIn,
                                                    lDimErrorIn,
                                                    &cStatusRegister,
                                                    sErrorOut))
                {
                    // error
                    bResult = FALSE;
                    break;
                }

                if (cStatusRegister & SPI_FLASH_M25P10A__SR_WEL)
                    // write enable latch bit is set
                {
                    // wait one millisecond
                    if(!fnDelayThread(  pDevExtIn,
                                        1,
                                        lDimErrorIn,
                                        sErrorOut))
                    {
                        // error
                        bResult = FALSE;
                        break;
                    }
                }
                else
                    // write enable latch bit is not set
                {
                    break;
                }
            }

            if  (bResult == FALSE)
                // timeout occured
            {
                // set ErrorDetail
		        _RtlStringCchPrintf(sErrorDetail,
							        _countof(sErrorDetail),
							        _TEXT("(): TimeOut occured at fnFlashSPI_WriteDisable!"));

		        // set ErrorString
		        fnBuildString(	_TEXT(__FUNCTION__),
						        sErrorDetail,
						        NULL,
						        lDimErrorIn,
						        sErrorOut);
            }

            break;
        }

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_WriteDisable - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Waits until the SPI Flash is ready or a timeout occurs
//************************************************************************

BOOLEAN	fnFlashSPI_WaitForReady( DEVICE_EXTENSION*	pDevExtIn,
							    uPNDEV_FLASH_PAR*	pFlashParIn,
                                UINT32              lTimeOutMSIn,
							    const UINT32		lDimErrorIn,
							    _TCHAR*				sErrorOut)
{
_TCHAR	        sErrorDetail[PNDEV_SIZE_STRING_BUF] = { 0 };
BOOLEAN         bResult                             = TRUE;
UINT8           cStatusRegister                     = 0;
UINT32          lTimeOutCounter                     = 0;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        {
            // Read the Status Register if write in progress bit is set and set a timeout

            if  (lTimeOutMSIn == 0)
                // wait endless
            {
                do
                {
                    if(!fnFlashSPI_ReadStatusRegister(  pDevExtIn,
                                                        pFlashParIn,
                                                        lDimErrorIn,
                                                        &cStatusRegister,
                                                        sErrorOut))
                    {
                        // error
                        bResult = FALSE;
                        break;
                    }
                }
                while (cStatusRegister & SPI_FLASH_N25Q128A__SR_WIP);
            }
            else
            {
                for ( lTimeOutCounter = 0; lTimeOutCounter < lTimeOutMSIn; lTimeOutCounter++)
                    // timeout max count not reached
                {
                    if(!fnFlashSPI_ReadStatusRegister(  pDevExtIn,
                                                        pFlashParIn,
                                                        lDimErrorIn,
                                                        &cStatusRegister,
                                                        sErrorOut))
                    {
                        // error
                        bResult = FALSE;
                        break;
                    }

                    if (cStatusRegister & SPI_FLASH_N25Q128A__SR_WIP)
                        // write in progress bit is set
                    {
                        // wait one millisecond
                        if(!fnDelayThread(  pDevExtIn,
                                            1,
                                            lDimErrorIn,
                                            sErrorOut))
                        {
                            // error
                            bResult = FALSE;
                            break;
                        }
                    }
                    else
                        // write in progress bit is not set
                    {
                        break;
                    }
                }
            }

            if  (bResult == FALSE)
                // timeout occured
            {
                // set ErrorDetail
		        _RtlStringCchPrintf(sErrorDetail,
							        _countof(sErrorDetail),
							        _TEXT("(): TimeOut occured at fnFlashSPI_WaitForReady!"));

		        // set ErrorString
		        fnBuildString(	_TEXT(__FUNCTION__),
						        sErrorDetail,
						        NULL,
						        lDimErrorIn,
						        sErrorOut);
            }

            break;
        }

        case ePNDEV_BOARD_TI_AM5728:
        {
            // Read the Status Register if write in progress bit is set and set a timeout

            if  (lTimeOutMSIn == 0)
                // wait endless
            {
                do
                {
                    if(!fnFlashSPI_ReadStatusRegister(  pDevExtIn,
                                                        pFlashParIn,
                                                        lDimErrorIn,
                                                        &cStatusRegister,
                                                        sErrorOut))
                    {
                        // error
                        bResult = FALSE;
                        break;
                    }
                }
                while (cStatusRegister & SPI_FLASH_A25LQ032__SR_WIP);
            }
            else
            {
                for ( lTimeOutCounter = 0; lTimeOutCounter < lTimeOutMSIn; lTimeOutCounter++)
                    // timeout max count not reached
                {
                    if(!fnFlashSPI_ReadStatusRegister(  pDevExtIn,
                                                        pFlashParIn,
                                                        lDimErrorIn,
                                                        &cStatusRegister,
                                                        sErrorOut))
                    {
                        // error
                        bResult = FALSE;
                        break;
                    }

                    if (cStatusRegister & SPI_FLASH_A25LQ032__SR_WIP)
                        // write in progress bit is set
                    {
                        // wait one millisecond
                        if(!fnDelayThread(  pDevExtIn,
                                            1,
                                            lDimErrorIn,
                                            sErrorOut))
                        {
                            // error
                            bResult = FALSE;
                            break;
                        }
                    }
                    else
                        // write in progress bit is not set
                    {
                        break;
                    }
                }
            }

            if  (bResult == FALSE)
                // timeout occured
            {
                // set ErrorDetail
		        _RtlStringCchPrintf(sErrorDetail,
							        _countof(sErrorDetail),
							        _TEXT("(): TimeOut occured at fnFlashSPI_WaitForReady!"));

		        // set ErrorString
		        fnBuildString(	_TEXT(__FUNCTION__),
						        sErrorDetail,
						        NULL,
						        lDimErrorIn,
						        sErrorOut);
            }

            break;
        }

		case ePNDEV_BOARD_CP1625:
        {
            // Read the Status Register if write in progress bit is set and set a timeout

            if  (lTimeOutMSIn == 0)
                // wait endless
            {
                do
                {
                    if(!fnFlashSPI_ReadStatusRegister(  pDevExtIn,
                                                        pFlashParIn,
                                                        lDimErrorIn,
                                                        &cStatusRegister,
                                                        sErrorOut))
                    {
                        // error
                        bResult = FALSE;
                        break;
                    }
                }
                while (cStatusRegister & SPI_FLASH_M25P10A__SR_WIP);
            }
            else
            {
                for ( lTimeOutCounter = 0; lTimeOutCounter < lTimeOutMSIn; lTimeOutCounter++)
                    // timeout max count not reached
                {
                    if(!fnFlashSPI_ReadStatusRegister(  pDevExtIn,
                                                        pFlashParIn,
                                                        lDimErrorIn,
                                                        &cStatusRegister,
                                                        sErrorOut))
                    {
                        // error
                        bResult = FALSE;
                        break;
                    }

                    if (cStatusRegister & SPI_FLASH_M25P10A__SR_WIP)
                        // write in progress bit is set
                    {
                        // wait one millisecond
                        if(!fnDelayThread(  pDevExtIn,
                                            1,
                                            lDimErrorIn,
                                            sErrorOut))
                        {
                            // error
                            bResult = FALSE;
                            break;
                        }
                    }
                    else
                        // write in progress bit is not set
                    {
                        break;
                    }
                }
            }

            if  (bResult == FALSE)
                // timeout occured
            {
                // set ErrorDetail
		        _RtlStringCchPrintf(sErrorDetail,
							        _countof(sErrorDetail),
							        _TEXT("(): TimeOut occured at fnFlashSPI_WaitForReady!"));

		        // set ErrorString
		        fnBuildString(	_TEXT(__FUNCTION__),
						        sErrorDetail,
						        NULL,
						        lDimErrorIn,
						        sErrorOut);
            }

            break;
        }

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_WaitForReady - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Bulk erase of Flash
//************************************************************************

BOOLEAN	fnFlashSPI_EraseChip(   DEVICE_EXTENSION*	pDevExtIn,
                                uPNDEV_FLASH_PAR*	pFlashParIn,
								const UINT32		lDimErrorIn,
							    _TCHAR*				sErrorOut)
{
_TCHAR	        sErrorDetail[PNDEV_SIZE_STRING_BUF] = { 0 };
SSP_CHARSTREAM  StreamTransmit                      = { 0, NULL };
UINT8           lArrayInstruction[1]                = { 0 };
BOOLEAN         bResult                             = TRUE;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        {
            // Step 1: Remove all sector locks
            if(!fnFlashSPI_UnlockAllSectors(pDevExtIn,
                                            pFlashParIn,
                                            lDimErrorIn,
                                            sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 2: Enable writing on chip
            if(!fnFlashSPI_WriteEnable( pDevExtIn,
                                        pFlashParIn,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 3: Initialize the data (i.e. Instruction) packet to be sent serially
            StreamTransmit.lLength      = 1;
            StreamTransmit.pBuffer      = lArrayInstruction;
            lArrayInstruction[0]        = SPI_FLASH_N25Q128A__INS_BE;

            // Step 4: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                NULL,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 5: Wait for completion
            if(!fnFlashSPI_WaitForReady(pDevExtIn,
                                    pFlashParIn,
                                    0,
                                    lDimErrorIn,
                                    sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 6: check for errors
            if(!fnFlashSPI_CheckForErrors(  pDevExtIn,
                                            pFlashParIn,
                                            lDimErrorIn,
                                            sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

        case ePNDEV_BOARD_TI_AM5728:
        {
            // Step 1: Remove all sector locks
            if(!fnFlashSPI_UnlockAllSectors(pDevExtIn,
                                            pFlashParIn,
                                            lDimErrorIn,
                                            sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 2: Enable writing on chip
            if(!fnFlashSPI_WriteEnable( pDevExtIn,
                                        pFlashParIn,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 3: Initialize the data (i.e. Instruction) packet to be sent serially
            StreamTransmit.lLength      = 1;
            StreamTransmit.pBuffer      = lArrayInstruction;
            lArrayInstruction[0]        = SPI_FLASH_A25LQ032__INS_CE;

            // Step 4: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                NULL,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 5: Wait for completion
            if(!fnFlashSPI_WaitForReady(pDevExtIn,
                                    pFlashParIn,
                                    0,
                                    lDimErrorIn,
                                    sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 6: check for errors
            // not supported

            break;
        }

		case ePNDEV_BOARD_CP1625:
        {
            // Step 1: Remove all sector locks
            if(!fnFlashSPI_UnlockAllSectors(pDevExtIn,
                                            pFlashParIn,
                                            lDimErrorIn,
                                            sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 2: Enable writing on chip
            if(!fnFlashSPI_WriteEnable( pDevExtIn,
                                        pFlashParIn,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 3: Initialize the data (i.e. Instruction) packet to be sent serially
            StreamTransmit.lLength      = 1;
            StreamTransmit.pBuffer      = lArrayInstruction;
            lArrayInstruction[0]        = SPI_FLASH_M25P10A__INS_BE;

            // Step 4: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                NULL,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 5: Wait for completion
            if(!fnFlashSPI_WaitForReady(pDevExtIn,
                                        pFlashParIn,
                                        0,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_EraseChip - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Erase of Sector
//************************************************************************

BOOLEAN	fnFlashSPI_EraseSector( DEVICE_EXTENSION*	pDevExtIn,
                                uPNDEV_FLASH_PAR*	pFlashParIn,
                                const UINT32		lOffsetDestIn,
								const UINT32		lDimErrorIn,
							    _TCHAR*				sErrorOut)
{
_TCHAR	        sErrorDetail[PNDEV_SIZE_STRING_BUF] = { 0 };
SSP_CHARSTREAM  StreamTransmit                      = { 0, NULL };
UINT8           lArrayInstruction[4]                = { 0,0,0,0 };
BOOLEAN         bResult                             = TRUE;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        {
            // Step 1: Remove all sector locks
            if(!fnFlashSPI_UnlockAllSectors(pDevExtIn,
                                            pFlashParIn,
                                            lDimErrorIn,
                                            sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 2: Enable writing on chip
            if(!fnFlashSPI_WriteEnable( pDevExtIn,
                                        pFlashParIn,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 3: Initialize the data (i.e. Instruction) packet to be sent serially
            StreamTransmit.lLength      = 4;
            StreamTransmit.pBuffer      = lArrayInstruction;
            lArrayInstruction[0]        = SPI_FLASH_N25Q128A__INS_SE;
	        lArrayInstruction[1]        = (UINT8)(lOffsetDestIn>>16);
	        lArrayInstruction[2]        = (UINT8)(lOffsetDestIn>>8);
	        lArrayInstruction[3]        = (UINT8)(lOffsetDestIn>>0);

            // Step 4: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                NULL,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 5: Wait for completion
            if(!fnFlashSPI_WaitForReady(pDevExtIn,
                                        pFlashParIn,
                                        0,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 6: check for errors
            if(!fnFlashSPI_CheckForErrors(  pDevExtIn,
                                            pFlashParIn,
                                            lDimErrorIn,
                                            sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

        case ePNDEV_BOARD_TI_AM5728:
        {
            // Step 1: Remove all sector locks
            if(!fnFlashSPI_UnlockAllSectors(pDevExtIn,
                                            pFlashParIn,
                                            lDimErrorIn,
                                            sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 2: Enable writing on chip
            if(!fnFlashSPI_WriteEnable( pDevExtIn,
                                        pFlashParIn,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 3: Initialize the data (i.e. Instruction) packet to be sent serially
            StreamTransmit.lLength      = 4;
            StreamTransmit.pBuffer      = lArrayInstruction;
            lArrayInstruction[0]        = SPI_FLASH_A25LQ032__INS_SE;
	        lArrayInstruction[1]        = (UINT8)(lOffsetDestIn>>16);
	        lArrayInstruction[2]        = (UINT8)(lOffsetDestIn>>8);
	        lArrayInstruction[3]        = (UINT8)(lOffsetDestIn>>0);

            // Step 4: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                NULL,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 5: Wait for completion
            if(!fnFlashSPI_WaitForReady(pDevExtIn,
                                        pFlashParIn,
                                        0,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 6: check for errors
            // not supported

            break;
        }

		case ePNDEV_BOARD_CP1625:
        {
            // Step 1: Remove all sector locks
            if(!fnFlashSPI_UnlockAllSectors(pDevExtIn,
                                            pFlashParIn,
                                            lDimErrorIn,
                                            sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 2: Enable writing on chip
            if(!fnFlashSPI_WriteEnable( pDevExtIn,
                                        pFlashParIn,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 3: Initialize the data (i.e. Instruction) packet to be sent serially
            StreamTransmit.lLength      = 4;
            StreamTransmit.pBuffer      = lArrayInstruction;
            lArrayInstruction[0]        = SPI_FLASH_M25P10A__INS_SE;
	        lArrayInstruction[1]        = (UINT8)(lOffsetDestIn>>16);
	        lArrayInstruction[2]        = (UINT8)(lOffsetDestIn>>8);
	        lArrayInstruction[3]        = (UINT8)(lOffsetDestIn>>0);

            // Step 4: Send the packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                NULL,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 5: Wait for completion
            if(!fnFlashSPI_WaitForReady(pDevExtIn,
                                        pFlashParIn,
                                        0,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_EraseChip - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Lock sector with remanent data
//************************************************************************

BOOLEAN	fnFlashSPI_LockDataSector(  DEVICE_EXTENSION*	pDevExtIn,
                                    uPNDEV_FLASH_PAR*	pFlashParIn,
								    const UINT32		lDimErrorIn,
							        _TCHAR*				sErrorOut)
{
_TCHAR	        sErrorDetail[PNDEV_SIZE_STRING_BUF] = { 0 };
BOOLEAN         bResult                             = TRUE;
UINT8           lStatusRegisterSet                  = 0;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        {
            // Set BP0 (Block protect bit) to 1 -> Sector 255 is locked
            lStatusRegisterSet |= PNDEV_UINT32_SET_BIT_2;

            // Write to status register
            if(!fnFlashSPI_WriteStatusRegister( pDevExtIn,
                                                pFlashParIn,
                                                lDimErrorIn,
                                                lStatusRegisterSet,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

        case ePNDEV_BOARD_TI_AM5728:
        {
            // Set BP0 (Block protect bit) and SEC (Sector Protect) to 1 -> Sector 255 is locked
            lStatusRegisterSet |= PNDEV_UINT32_SET_BIT_2;
            lStatusRegisterSet |= PNDEV_UINT32_SET_BIT_6;

            // Write to status register
            if(!fnFlashSPI_WriteStatusRegister( pDevExtIn,
                                                pFlashParIn,
                                                lDimErrorIn,
                                                lStatusRegisterSet,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

		case ePNDEV_BOARD_CP1625:
        {
            // Set BP0 (Block protect bit) to 1 -> Sector 4 is locked
            lStatusRegisterSet |= PNDEV_UINT32_SET_BIT_2;

            // Write to status register
            if(!fnFlashSPI_WriteStatusRegister( pDevExtIn,
                                                pFlashParIn,
                                                lDimErrorIn,
                                                lStatusRegisterSet,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_LockDataSector - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Unlock all sectors at Flash
//************************************************************************

BOOLEAN	fnFlashSPI_UnlockAllSectors(DEVICE_EXTENSION*	pDevExtIn,
                                    uPNDEV_FLASH_PAR*	pFlashParIn,
								    const UINT32		lDimErrorIn,
							        _TCHAR*				sErrorOut)
{
_TCHAR	        sErrorDetail[PNDEV_SIZE_STRING_BUF] = { 0 };
BOOLEAN         bResult                             = TRUE;
UINT8           lStatusRegisterSet                  = 0;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        case ePNDEV_BOARD_TI_AM5728:
		case ePNDEV_BOARD_CP1625:
        {
            // Write a 0 to status register to unlock all sectors
            if(!fnFlashSPI_WriteStatusRegister( pDevExtIn,
                                                pFlashParIn,
                                                lDimErrorIn,
                                                lStatusRegisterSet,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_UnlockAllSectors - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Programming of data to the Flash
//************************************************************************

BOOLEAN	fnFlashSPI_ProgramPage(	DEVICE_EXTENSION*	pDevExtIn,
							    uPNDEV_FLASH_PAR*	pFlashParIn,
							    const UINT32		lOffsetDestIn,
							    volatile UINT8*		pDataSrcIn,
							    const UINT32		lSizeBytesSrcIn,
							    const UINT32		lDimErrorIn,
							    _TCHAR*				sErrorOut)
{
_TCHAR	        sErrorDetail[PNDEV_SIZE_STRING_BUF] = { 0 };
BOOLEAN         bResult		                        = TRUE;
SSP_CHARSTREAM  StreamTransmit                      = { 0, NULL };
UINT8           pInstruct[4]                        = { 0,0,0,0 };

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        {
            // Step 1: Enable writing on chip
            if(!fnFlashSPI_WriteEnable( pDevExtIn,
                                        pFlashParIn,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            StreamTransmit.lLength  = 4;
            StreamTransmit.pBuffer  = pInstruct;

            pInstruct[0]            = SPI_FLASH_N25Q128A__INS_PP;
	        pInstruct[1]            = (UINT8)(lOffsetDestIn>>16);
	        pInstruct[2]            = (UINT8)(lOffsetDestIn>>8);
	        pInstruct[3]            = (UINT8)(lOffsetDestIn>>0);

            // Step 2: Send the command packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                NULL,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionKeepUpChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 3: Send the data packet serially
            StreamTransmit.lLength  = lSizeBytesSrcIn;
            StreamTransmit.pBuffer  = (UINT8*)pDataSrcIn;

            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                NULL,
                                                SSP_OptionNull,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 4: Wait for completion
            if(!fnFlashSPI_WaitForReady(pDevExtIn,
                                        pFlashParIn,
                                        0,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }
    
            // Step 5: check for errors
            if(!fnFlashSPI_CheckForErrors(  pDevExtIn,
                                            pFlashParIn,
                                            lDimErrorIn,
                                            sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

        case ePNDEV_BOARD_TI_AM5728:
        {
        UINT8* pFlashDataSPI;

            // Note:
			// - Linux Kernel Threads Stack Size is limited to 8k, use kernel heap for big data structures!
			pFlashDataSPI = (UINT8*) fnAllocMemNonPaged(	(sizeof(uPNDEV_FLASH_DATA) + (4 * sizeof(UINT8))),
															TAG('S','P','I','F'));

			if (pFlashDataSPI == NULL)
			{
				bResult = FALSE;

				// set ErrorDetail
				_RtlStringCchPrintf(sErrorDetail,
									_countof(sErrorDetail),
									_TEXT("(): Error at fnFlashSPI_ProgramPage - could not allocate uPNDEV_FLASH_DATA!"));

				// set ErrorString
				fnBuildString(	_TEXT(__FUNCTION__),
								sErrorDetail,
								NULL,
								lDimErrorIn,
								sErrorOut);

				break;
			}

            RtlZeroMemory(	pFlashDataSPI,
							(sizeof(uPNDEV_FLASH_DATA) + (4 * sizeof(UINT8))));

            // Step 1: Enable writing on chip
            if(!fnFlashSPI_WriteEnable( pDevExtIn,
                                        pFlashParIn,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            StreamTransmit.lLength  = 4 + lSizeBytesSrcIn;
            StreamTransmit.pBuffer  = pFlashDataSPI;

            pFlashDataSPI[0]            = SPI_FLASH_A25LQ032__INS_PP;
	        pFlashDataSPI[1]            = (UINT8)(lOffsetDestIn>>16);
	        pFlashDataSPI[2]            = (UINT8)(lOffsetDestIn>>8);
	        pFlashDataSPI[3]            = (UINT8)(lOffsetDestIn>>0);

            RtlCopyMemory(	(void*) &(pFlashDataSPI[4]),
							(void*) (pDataSrcIn),
							sizeof(uPNDEV_FLASH_DATA));

            // Step 2: Send the command packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                NULL,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionKeepUpChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 4: Wait for completion
            if(!fnFlashSPI_WaitForReady(pDevExtIn,
                                        pFlashParIn,
                                        0,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // delete memory of big data structure
			fnFreeMemNonPaged(	pFlashDataSPI,
								TAG('S','P','I','F'));
    
            // Step 5: check for errors
            // not supported

            break;
        }

		case ePNDEV_BOARD_CP1625:
        {
            // Step 1: Enable writing on chip
            if(!fnFlashSPI_WriteEnable( pDevExtIn,
                                        pFlashParIn,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            StreamTransmit.lLength  = 4;
            StreamTransmit.pBuffer  = pInstruct;

            pInstruct[0]            = SPI_FLASH_M25P10A__INS_PP;
	        pInstruct[1]            = (UINT8)(lOffsetDestIn>>16);
	        pInstruct[2]            = (UINT8)(lOffsetDestIn>>8);
	        pInstruct[3]            = (UINT8)(lOffsetDestIn>>0);

            // Step 2: Send the command packet serially
            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                NULL,
                                                SSP_OptionEnableChipSelect,
                                                SSP_OptionKeepUpChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 3: Send the data packet serially
            StreamTransmit.lLength  = lSizeBytesSrcIn;
            StreamTransmit.pBuffer  = (UINT8*)pDataSrcIn;

            if(!fnFlashSPI_SSPTransmitReceive(  pDevExtIn,
                                                pFlashParIn,
                                                &StreamTransmit,
                                                NULL,
                                                SSP_OptionNull,
                                                SSP_OptionDisableChipSelect,
                                                lDimErrorIn,
                                                sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 4: Wait for completion
            if(!fnFlashSPI_WaitForReady(pDevExtIn,
                                        pFlashParIn,
                                        0,
                                        lDimErrorIn,
                                        sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            break;
        }

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_ProgramPage - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Programming of data to the Flash -> calls ProgramPage
//************************************************************************

BOOLEAN	fnFlashSPI_ProgramData(	DEVICE_EXTENSION*	pDevExtIn,
							    uPNDEV_FLASH_PAR*	pFlashParIn,
							    const UINT32		lOffsetDestIn,
							    volatile UINT8*		pDataSrcIn,
							    const UINT32		lSizeBytesSrcIn,
							    const UINT32		lDimErrorIn,
							    _TCHAR*				sErrorOut)
{
_TCHAR	sErrorDetail[PNDEV_SIZE_STRING_BUF] = { 0 };
BOOLEAN bResult		                        = TRUE;
UINT32  lFirstPageSize                      = 0;
UINT32  lRemainingSize                      = 0;
UINT32  lPages                              = 0;
UINT32  i                                   = 0;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        case ePNDEV_BOARD_TI_AM5728:
		case ePNDEV_BOARD_CP1625:
        {
            // Step 1: Remove all sector locks
            if(!fnFlashSPI_UnlockAllSectors(pDevExtIn,
                                            pFlashParIn,
                                            lDimErrorIn,
                                            sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // Step 3: Computing the needed calls of ProgramPage
                        
            lRemainingSize = lSizeBytesSrcIn;

            // calculate available size in first page if start address is not page boundary
            lFirstPageSize = pFlashParIn->uSPI.lSizePage - ( lOffsetDestIn  & pFlashParIn->uSPI.lAddressMask );

            if(!fnFlashSPI_ProgramPage(	pDevExtIn,
										pFlashParIn,
										lOffsetDestIn,
										pDataSrcIn,
										lFirstPageSize,
										lDimErrorIn, 
										sErrorOut))
            {
                // error
                bResult = FALSE;
                break;
            }

            // calculate remaining size and full apges to write
            lRemainingSize = lRemainingSize - lFirstPageSize;

            lPages = lRemainingSize / pFlashParIn->uSPI.lSizePage;    
    
            for(i = 0; i < lPages; i++)
            {   
                if(!fnFlashSPI_ProgramPage(	pDevExtIn,
										    pFlashParIn,
										    lOffsetDestIn + lFirstPageSize + (i * pFlashParIn->uSPI.lSizePage),
										    pDataSrcIn  + lFirstPageSize + (i * pFlashParIn->uSPI.lSizePage),
										    pFlashParIn->uSPI.lSizePage,
										    lDimErrorIn, 
										    sErrorOut))
                {
                    // error
                    bResult = FALSE;
                    break;
                }
            }    

            // write last page
            if  (bResult)
                // Writing so far ok
            {
                lRemainingSize = lSizeBytesSrcIn - (lPages * pFlashParIn->uSPI.lSizePage) - lFirstPageSize; 

                if(lRemainingSize != 0)
                {
                    if(!fnFlashSPI_ProgramPage(	pDevExtIn,
										        pFlashParIn,
										        lOffsetDestIn + lFirstPageSize + (i * pFlashParIn->uSPI.lSizePage),
										        pDataSrcIn  + lFirstPageSize + (i * pFlashParIn->uSPI.lSizePage),
										        lRemainingSize,
										        lDimErrorIn, 
										        sErrorOut))
                    {
                        // error
                        bResult = FALSE;
                        break;
                    }
                }
            }

            break;
        }

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_ProgramData - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}

//************************************************************************
//  D e s c r i p t i o n :
//
//  Performs the Flash actions provided by PnDev_Driver
//************************************************************************

BOOLEAN	fnFlashSPI_Program(	DEVICE_EXTENSION*	pDevExtIn,
							uPNDEV_FLASH_PAR*	pFlashParIn,
							const UINT32		lOffsetDestIn,
							volatile UINT8*		pDataSrcIn,
							const UINT32		lSizeBytesSrcIn,
							const BOOLEAN		bEraseChipIn,
							const UINT32		lDimErrorIn,
							_TCHAR*				sErrorOut)
{
_TCHAR	sErrorDetail[PNDEV_SIZE_STRING_BUF] = { 0 };
BOOLEAN bResult		                        = TRUE;

    switch ( pDevExtIn->eBoard )
    {
        case ePNDEV_BOARD_FPGA1_HERA:
        case ePNDEV_BOARD_TI_AM5728:
		case ePNDEV_BOARD_CP1625:
        {
	        if	(bEraseChipIn)
		        // erase chip
	        {
		        // call erase chip
		        if(!fnFlashSPI_EraseChip(   pDevExtIn,
										    pFlashParIn,
										    lDimErrorIn,
										    sErrorOut))
                {
                    // error
                    bResult = FALSE;
                    break;
                }
	        }
	
	        if	(lOffsetDestIn == 0)
		        // no SBL to program
	        {
                // do nothing
	        }
	        else	// flash RemanentData
	        {
	            // erase used flash sector before programming
	            //	- must be done if flash is not empty
                if(!fnFlashSPI_EraseSector( pDevExtIn,
										    pFlashParIn,
                                            lOffsetDestIn,
										    lDimErrorIn,
										    sErrorOut))
                {
                    // error
                    bResult = FALSE;
                    break;
                }

                // program data
		        if	(lSizeBytesSrcIn != 0)
			        // SrcData exists
		        {
			        if(!fnFlashSPI_ProgramData(	pDevExtIn,
												pFlashParIn,
												lOffsetDestIn,
												pDataSrcIn,
												lSizeBytesSrcIn,
												lDimErrorIn, 
												sErrorOut))
                    {
                        // error
                        bResult = FALSE;
                        break;
                    }

                    // lock our sector with the remanent data to prevent it from overwrite
                    if(!fnFlashSPI_LockDataSector(  pDevExtIn,
										            pFlashParIn,
										            lDimErrorIn,
										            sErrorOut))
                    {
                        // error
                        bResult = FALSE;
                        break;
                    }
		        }
	        }

            break;
        }

        default:
        {
            bResult = FALSE;

            // set ErrorDetail
		    _RtlStringCchPrintf(sErrorDetail,
							    _countof(sErrorDetail),
							    _TEXT("(): Error at fnFlashSPI_Program - unknown board!"));

		    // set ErrorString
		    fnBuildString(	_TEXT(__FUNCTION__),
						    sErrorDetail,
						    NULL,
						    lDimErrorIn,
						    sErrorOut);
        }
    }

    return bResult;
}
