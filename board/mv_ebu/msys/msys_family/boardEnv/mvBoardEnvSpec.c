/*******************************************************************************
Copyright (C) Marvell International Ltd. and its affiliates

This software file (the "File") is owned and distributed by Marvell
International Ltd. and/or its affiliates ("Marvell") under the following
alternative licensing terms.  Once you have made an election to distribute the
File under one of the following license alternatives, please (i) delete this
introductory statement regarding license alternatives, (ii) delete the two
license alternatives that you have not elected to use and (iii) preserve the
Marvell copyright notice above.

********************************************************************************
Marvell Commercial License Option

If you received this File from Marvell and you have entered into a commercial
license agreement (a "Commercial License") with Marvell, the File is licensed
to you under the terms of the applicable Commercial License.

********************************************************************************
Marvell GPL License Option

If you received this File from Marvell, you may opt to use, redistribute and/or
modify this File in accordance with the terms and conditions of the General
Public License Version 2, June 1991 (the "GPL License"), a copy of which is
available along with the File in the license.txt file or by writing to the Free
Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 or
on the worldwide web at http://www.gnu.org/licenses/gpl.txt.

THE FILE IS DISTRIBUTED AS-IS, WITHOUT WARRANTY OF ANY KIND, AND THE IMPLIED
WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE ARE EXPRESSLY
DISCLAIMED.  The GPL License provides additional details about this warranty
disclaimer.
********************************************************************************
Marvell BSD License Option

If you received this File from Marvell, you may opt to use, redistribute and/or
modify this File under the following licensing terms.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    *   Redistributions of source code must retain the above copyright notice,
	    this list of conditions and the following disclaimer.

    *   Redistributions in binary form must reproduce the above copyright
	notice, this list of conditions and the following disclaimer in the
	documentation and/or other materials provided with the distribution.

    *   Neither the name of Marvell nor the names of its contributors may be
	used to endorse or promote products derived from this software without
	specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*******************************************************************************/
#include "mvCommon.h"
#include "mvBoardEnvLib.h"
#include "mvBoardEnvSpec.h"
#include "twsi/mvTwsi.h"
#include "pex/mvPexRegs.h"

#define ARRSZ(x)	(sizeof(x)/sizeof(x[0]))

/***************************************** Customer Boards ****************************************/
/*******************************************************************************
	Bobcat2 board - Based on BOBCAT2-DB-DX
*******************************************************************************/
#define BOBCAT2_CUSTOMER_0_BOARD_NAND_READ_PARAMS	0x000C0282
#define BOBCAT2_CUSTOMER_0_BOARD_NAND_WRITE_PARAMS	0x00010305
/*NAND care support for small page chips*/
#define BOBCAT2_CUSTOMER_0_BOARD_NAND_CONTROL		0x01c00543

#define BOBCAT2_CUSTOMER_0_BOARD_NOR_READ_PARAMS	0x403E07CF
#define BOBCAT2_CUSTOMER_0_BOARD_NOR_WRITE_PARAMS	0x000F0F0F

MV_BOARD_TWSI_INFO	bobcat2_customer_board_0_InfoBoardTwsiDev[] = {
/* {{MV_BOARD_DEV_CLASS	devClass, MV_U8	twsiDevAddr, MV_U8 twsiDevAddrType}} */
	{BOARD_DEV_TWSI_PLD, 0x30, ADDR7_BIT},		/* Access to control PLD reg file */
	{BOARD_DEV_TWSI_ZARLINK, 0x18, ADDR7_BIT},		/* Access to Zarlink */
	{BOARD_DEV_TWSI_SATR, 0x4C, ADDR7_BIT},         /* SatR bios 0		*/
	{BOARD_DEV_TWSI_SATR, 0x4D, ADDR7_BIT},         /* SatR bios 1		*/
	{BOARD_DEV_TWSI_SATR, 0x4E, ADDR7_BIT},          /* SatR bios 2		*/
	{BOARD_DEV_TWSI_SATR, 0x4F, ADDR7_BIT},          /* SatR bios 3		*/
	{BOARD_DEV_TWSI_INIT_EPROM, 0x50, ADDR7_BIT},          /* Serial Ini EPROM	*/
	{BOARD_DEV_TWSI_PCA9555_IO_EXPANDER, 0x20, ADDR7_BIT},          /* Qsgmii/sfp mux control PCA9555 IO expander */
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x70, ADDR7_BIT},          /* PCA9548 I2C mux 0	*/
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x71, ADDR7_BIT},          /* PCA9548 I2C mux 1	*/
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x75, ADDR7_BIT}          /* PCA9548 I2C mux 2	*/
};

MV_BOARD_MAC_INFO bobcat2_customer_board_0_InfoBoardMacInfo[] = {
	/* {{MV_BOARD_MAC_SPEED boardMacSpeed, MV_32 boardEthSmiAddr , MV_32 boardEthSmiAddr0;}} */
	{BOARD_MAC_SPEED_AUTO, 0x0, 0x0, MV_TRUE},
	{BOARD_MAC_SPEED_AUTO, 0x1, 0x1, MV_TRUE},
};

MV_BOARD_MODULE_TYPE_INFO bobcat2_customer_board_0_InfoBoardModTypeInfo[] = {
	{
		.boardMppMod		= MV_BOARD_AUTO,
	}
};

MV_DEV_CS_INFO bobcat2_customer_board_0_InfoBoardDeCsInfo[] = {
	/*{deviceCS, params, devType, devWidth, busWidth, busNum, active }*/
#if defined(MV_INCLUDE_SPI)
	{SPI_CS0, N_A, BOARD_DEV_SPI_FLASH, 8, 8, 0, MV_TRUE}, /* SPI DEV */
#endif
#if defined(MV_INCLUDE_NOR) && defined(MV_INCLUDE_NAND)
	{DEVICE_CS0, N_A, BOARD_DEV_NAND_FLASH, 8, 8, 0, MV_TRUE}, /* NAND DEV */
	{DEV_BOOCS, N_A, BOARD_DEV_NOR_FLASH, 16, 16, 0, MV_TRUE} /* NOR DEV */
#elif defined(MV_INCLUDE_NAND)
	{DEVICE_CS0, N_A, BOARD_DEV_NAND_FLASH, 8, 8, 0, MV_TRUE} /* NAND DEV */
#elif defined(MV_INCLUDE_NOR)
	{DEV_BOOCS, N_A, BOARD_DEV_NOR_FLASH, 16, 16, 0, MV_TRUE} /* NOR DEV */
#endif
};

MV_BOARD_MPP_INFO bobcat2_customer_board_0_InfoBoardMppConfigValue[] = {
	{ {
	BOBCAT2_CUSTOMER_0_MPP0_7,
	BOBCAT2_CUSTOMER_0_MPP8_15,
	BOBCAT2_CUSTOMER_0_MPP16_23,
	BOBCAT2_CUSTOMER_0_MPP24_31,
	BOBCAT2_CUSTOMER_0_MPP32_39,
	} },
};

MV_BOARD_INFO bobcat2_customer_board_0_Info = {
	.boardName			= "BOBCAT2-Customer-Board-0",
	.numBoardMppTypeValue		= ARRSZ(bobcat2_customer_board_0_InfoBoardModTypeInfo),
	.pBoardModTypeValue		= bobcat2_customer_board_0_InfoBoardModTypeInfo,
	.numBoardMppConfigValue		= ARRSZ(bobcat2_customer_board_0_InfoBoardMppConfigValue),
	.pBoardMppConfigValue		= bobcat2_customer_board_0_InfoBoardMppConfigValue,
	.intsGppMaskLow			= 0,
	.intsGppMaskMid			= 0,
	.intsGppMaskHigh		= 0,
	.numBoardDeviceIf		= ARRSZ(bobcat2_customer_board_0_InfoBoardDeCsInfo),
	.pDevCsInfo			= bobcat2_customer_board_0_InfoBoardDeCsInfo,
	.numBoardTwsiDev		= ARRSZ(bobcat2_customer_board_0_InfoBoardTwsiDev),
	.pBoardTwsiDev			= bobcat2_customer_board_0_InfoBoardTwsiDev,
	.numBoardMacInfo		= ARRSZ(bobcat2_customer_board_0_InfoBoardMacInfo),
	.pBoardMacInfo			= bobcat2_customer_board_0_InfoBoardMacInfo,
	.numBoardGppInfo		= 0,
	.pBoardGppInfo			= NULL,
	.activeLedsNumber		= 0,
	.pLedGppPin			= NULL,
	.ledsPolarity			= 0,

	/* GPP values */
	.gppOutEnValLow			= BOBCAT2_CUSTOMER_0_GPP_OUT_ENA_LOW,
	.gppOutEnValMid			= BOBCAT2_CUSTOMER_0_GPP_OUT_ENA_MID,
	.gppOutEnValHigh		= 0,
	.gppOutValLow			= BOBCAT2_CUSTOMER_0_GPP_OUT_VAL_LOW,
	.gppOutValMid			= BOBCAT2_CUSTOMER_0_GPP_OUT_VAL_MID,
	.gppOutValHigh			= 0,
	.gppPolarityValLow		= BOBCAT2_CUSTOMER_0_GPP_POL_LOW,
	.gppPolarityValMid		= BOBCAT2_CUSTOMER_0_GPP_POL_MID,
	.gppPolarityValHigh		= 0,

	/* External Switch Configuration */
	.pSwitchInfo = NULL,
	.switchInfoNum = 0,

	/* NAND init params */
	.nandFlashReadParams		= BOBCAT2_CUSTOMER_0_BOARD_NAND_READ_PARAMS,
	.nandFlashWriteParams		= BOBCAT2_CUSTOMER_0_BOARD_NAND_WRITE_PARAMS,
	.nandFlashControl		= BOBCAT2_CUSTOMER_0_BOARD_NAND_CONTROL,
	/* NOR init params */
	.norFlashReadParams		= BOBCAT2_CUSTOMER_0_BOARD_NOR_READ_PARAMS,
	.norFlashWriteParams		= BOBCAT2_CUSTOMER_0_BOARD_NOR_WRITE_PARAMS,
	.configAutoDetect		= MV_FALSE	/* Enable modules auto-detection. */
};

MV_BOARD_INFO *customerBC2BoardInfoTbl[] = {
	&bobcat2_customer_board_0_Info,
	&bobcat2_customer_board_0_Info,
};

/*******************************************************************************
	BobK Cetus customer board - Based on BOBK-CETUS-DB-98DX4235-12XG
*******************************************************************************/
#define BOBK_CETUS_CUSTOMER_0_BOARD_NAND_READ_PARAMS	0x000C0282
#define BOBK_CETUS_CUSTOMER_0_BOARD_NAND_WRITE_PARAMS	0x00010305
/*NAND care support for small page chips*/
#define BOBK_CETUS_CUSTOMER_0_BOARD_NAND_CONTROL		0x01c00543

#define BOBK_CETUS_CUSTOMER_0_BOARD_NOR_READ_PARAMS	0x403E07CF
#define BOBK_CETUS_CUSTOMER_0_BOARD_NOR_WRITE_PARAMS	0x000F0F0F

MV_BOARD_TWSI_INFO	bobk_cetus_customer_board_0_InfoBoardTwsiDev[] = {
/* {{MV_BOARD_DEV_CLASS	devClass, MV_U8	twsiDevAddr, MV_U8 twsiDevAddrType}} */
	{BOARD_DEV_TWSI_PLD, 0x18, ADDR7_BIT},		/* Access to control PLD reg file */
	{BOARD_DEV_TWSI_ZARLINK, 0x1B, ADDR7_BIT},		/* Access to Zarlink	*/
	{BOARD_DEV_TWSI_SATR, 0x4C, ADDR7_BIT},         /* SatR bios 0		*/
	{BOARD_DEV_TWSI_SATR, 0x4D, ADDR7_BIT},         /* SatR bios 1		*/
	{BOARD_DEV_TWSI_SATR, 0x4E, ADDR7_BIT},          /* SatR bios 2		*/
	{BOARD_DEV_TWSI_SATR, 0x4F, ADDR7_BIT},          /* SatR bios 3		*/
	{BOARD_DEV_TWSI_INIT_EPROM, 0x50, ADDR7_BIT},          /* Serial Init EPROM	*/
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x70, ADDR7_BIT},          /* PCA9548 I2C mux 0	*/
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x71, ADDR7_BIT},          /* PCA9548 I2C mux 1	*/
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x75, ADDR7_BIT}          /* PCA9548 I2C mux 2	*/
};

MV_BOARD_MAC_INFO bobk_cetus_customer_board_0_InfoBoardMacInfo[] = {
	/* {{MV_BOARD_MAC_SPEED boardMacSpeed, MV_32 boardEthSmiAddr , MV_32 boardEthSmiAddr0;}} */
	{BOARD_MAC_SPEED_AUTO, -1, -1, MV_FALSE},
	{BOARD_MAC_SPEED_AUTO, 0x0, 0x0, MV_TRUE},
};

MV_BOARD_MODULE_TYPE_INFO bobk_cetus_customer_board_0_InfoBoardModTypeInfo[] = {
	{
		.boardMppMod		= MV_BOARD_AUTO,
	}
};

MV_DEV_CS_INFO bobk_cetus_customer_board_0_InfoBoardDeCsInfo[] = {
	/*{deviceCS, params, devType, devWidth, busWidth, busNum, active }*/
#if defined(MV_INCLUDE_SPI)
		{SPI_CS0, N_A, BOARD_DEV_SPI_FLASH, 8, 8, 0, MV_TRUE}, /* SPI DEV */
#endif
#if defined(MV_INCLUDE_NOR)
		{DEV_BOOCS, N_A, BOARD_DEV_NOR_FLASH, 16, 16, 0, MV_TRUE} /* NOR DEV */
#endif
#if defined(MV_INCLUDE_NAND)
		{DEVICE_CS0, N_A, BOARD_DEV_NAND_FLASH, 8, 8, 0, MV_TRUE} /* NAND DEV */
#endif
};

MV_BOARD_MPP_INFO bobk_cetus_customer_board_0_InfoBoardMppConfigValue[] = {
	{ {
	BOBK_CETUS_CUSTOMER_0_MPP0_7,
	BOBK_CETUS_CUSTOMER_0_MPP8_15,
	BOBK_CETUS_CUSTOMER_0_MPP16_23,
	BOBK_CETUS_CUSTOMER_0_MPP24_31,
	BOBK_CETUS_CUSTOMER_0_MPP32_39,
	} },
};

MV_BOARD_INFO bobk_cetus_customer_board_0_Info = {
	.boardName			= "BOBK-Cetus-Customer-Board-0",
	.numBoardMppTypeValue		= ARRSZ(bobk_cetus_customer_board_0_InfoBoardModTypeInfo),
	.pBoardModTypeValue		= bobk_cetus_customer_board_0_InfoBoardModTypeInfo,
	.numBoardMppConfigValue		= ARRSZ(bobk_cetus_customer_board_0_InfoBoardMppConfigValue),
	.pBoardMppConfigValue		= bobk_cetus_customer_board_0_InfoBoardMppConfigValue,
	.intsGppMaskLow			= 0,
	.intsGppMaskMid			= 0,
	.intsGppMaskHigh		= 0,
	.numBoardDeviceIf		= ARRSZ(bobk_cetus_customer_board_0_InfoBoardDeCsInfo),
	.pDevCsInfo			= bobk_cetus_customer_board_0_InfoBoardDeCsInfo,
	.numBoardTwsiDev		= ARRSZ(bobk_cetus_customer_board_0_InfoBoardTwsiDev),
	.pBoardTwsiDev			= bobk_cetus_customer_board_0_InfoBoardTwsiDev,
	.numBoardMacInfo		= ARRSZ(bobk_cetus_customer_board_0_InfoBoardMacInfo),
	.pBoardMacInfo			= bobk_cetus_customer_board_0_InfoBoardMacInfo,
	.numBoardGppInfo		= 0,
	.pBoardGppInfo			= NULL,
	.activeLedsNumber		= 0,
	.pLedGppPin			= NULL,
	.ledsPolarity			= 0,

	/* GPP values */
	.gppOutEnValLow			= BOBK_CETUS_CUSTOMER_0_GPP_OUT_ENA_LOW,
	.gppOutEnValMid			= BOBK_CETUS_CUSTOMER_0_GPP_OUT_ENA_MID,
	.gppOutEnValHigh		= 0,
	.gppOutValLow			= BOBK_CETUS_CUSTOMER_0_GPP_OUT_VAL_LOW,
	.gppOutValMid			= BOBK_CETUS_CUSTOMER_0_GPP_OUT_VAL_MID,
	.gppOutValHigh			= 0,
	.gppPolarityValLow		= BOBK_CETUS_CUSTOMER_0_GPP_POL_LOW,
	.gppPolarityValMid		= BOBK_CETUS_CUSTOMER_0_GPP_POL_MID,
	.gppPolarityValHigh		= 0,

	/* External Switch Configuration */
	.pSwitchInfo = NULL,
	.switchInfoNum = 0,

	/* NAND init params */
	.nandFlashReadParams		= BOBK_CETUS_CUSTOMER_0_BOARD_NAND_READ_PARAMS,
	.nandFlashWriteParams		= BOBK_CETUS_CUSTOMER_0_BOARD_NAND_WRITE_PARAMS,
	.nandFlashControl		= BOBK_CETUS_CUSTOMER_0_BOARD_NAND_CONTROL,
	/* NOR init params */
	.norFlashReadParams		= BOBK_CETUS_CUSTOMER_0_BOARD_NOR_READ_PARAMS,
	.norFlashWriteParams		= BOBK_CETUS_CUSTOMER_0_BOARD_NOR_WRITE_PARAMS,
	.isSmiExternalPp		= MV_TRUE,
	.smiExternalPpIndex		= 0,
	.isSdMmcConnected		= MV_TRUE,
	.configAutoDetect		= MV_FALSE	/* Enable modules auto-detection. */
};

/*******************************************************************************
	BobK Caelum customer board - Based on BOBK-CAELUM-DB-98DX4203-48G12XG
*******************************************************************************/
#define BOBK_CAELUM_CUSTOMER_1_BOARD_NAND_READ_PARAMS	0x000C0282
#define BOBK_CAELUM_CUSTOMER_1_BOARD_NAND_WRITE_PARAMS	0x00010305
/*NAND care support for small page chips*/
#define BOBK_CAELUM_CUSTOMER_1_BOARD_NAND_CONTROL		0x01c00543

#define BOBK_CAELUM_CUSTOMER_1_BOARD_NOR_READ_PARAMS	0x403E07CF
#define BOBK_CAELUM_CUSTOMER_1_BOARD_NOR_WRITE_PARAMS	0x000F0F0F

MV_BOARD_TWSI_INFO	bobk_caelum_customer_board_1_InfoBoardTwsiDev[] = {
/* {{MV_BOARD_DEV_CLASS	devClass, MV_U8	twsiDevAddr, MV_U8 twsiDevAddrType}} */
	{BOARD_DEV_TWSI_PLD, 0x18, ADDR7_BIT},		/* Access to control PLD reg file */
	{BOARD_DEV_TWSI_ZARLINK, 0x1B, ADDR7_BIT},		/* Access to Zarlink	*/
	{BOARD_DEV_TWSI_SATR, 0x4C, ADDR7_BIT},         /* SatR bios 0		*/
	{BOARD_DEV_TWSI_SATR, 0x4D, ADDR7_BIT},         /* SatR bios 1		*/
	{BOARD_DEV_TWSI_SATR, 0x4E, ADDR7_BIT},          /* SatR bios 2		*/
	{BOARD_DEV_TWSI_SATR, 0x4F, ADDR7_BIT},          /* SatR bios 3		*/
	{BOARD_DEV_TWSI_INIT_EPROM, 0x50, ADDR7_BIT},          /* Serial Init EPROM	*/
	{BOARD_DEV_TWSI_PCA9555_IO_EXPANDER, 0x20, ADDR7_BIT},          /* Qsgmii/sfp mux control PCA9555 IO expander */
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x70, ADDR7_BIT},          /* PCA9548 I2C mux 0	*/
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x71, ADDR7_BIT},          /* PCA9548 I2C mux 1	*/
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x75, ADDR7_BIT}          /* PCA9548 I2C mux 2	*/
};

MV_BOARD_MAC_INFO bobk_caelum_customer_board_1_InfoBoardMacInfo[] = {
	/* {{MV_BOARD_MAC_SPEED boardMacSpeed, MV_32 boardEthSmiAddr , MV_32 boardEthSmiAddr0;}} */
	{BOARD_MAC_SPEED_AUTO, -1, -1, MV_FALSE},
	{BOARD_MAC_SPEED_AUTO, 0x0, 0x0, MV_TRUE},
};

MV_BOARD_MODULE_TYPE_INFO bobk_caelum_customer_board_1_InfoBoardModTypeInfo[] = {
	{
		.boardMppMod		= MV_BOARD_AUTO,
	}
};

MV_DEV_CS_INFO bobk_caelum_customer_board_1_InfoBoardDeCsInfo[] = {
	/*{deviceCS, params, devType, devWidth, busWidth, busNum, active }*/
#if defined(MV_INCLUDE_SPI)
		{SPI_CS0, N_A, BOARD_DEV_SPI_FLASH, 8, 8, 0, MV_TRUE}, /* SPI DEV */
#endif
#if defined(MV_INCLUDE_NOR)
		{DEV_BOOCS, N_A, BOARD_DEV_NOR_FLASH, 16, 16, 0, MV_TRUE} /* NOR DEV */
#endif
#if defined(MV_INCLUDE_NAND)
		{DEVICE_CS0, N_A, BOARD_DEV_NAND_FLASH, 8, 8, 0, MV_TRUE} /* NAND DEV */
#endif
};

MV_BOARD_MPP_INFO bobk_caelum_customer_board_1_InfoBoardMppConfigValue[] = {
	{ {
	BOBK_CAELUM_CUSTOMER_1_MPP0_7,
	BOBK_CAELUM_CUSTOMER_1_MPP8_15,
	BOBK_CAELUM_CUSTOMER_1_MPP16_23,
	BOBK_CAELUM_CUSTOMER_1_MPP24_31,
	BOBK_CAELUM_CUSTOMER_1_MPP32_39,
	} },
};

MV_BOARD_INFO bobk_caelum_customer_board_1_Info = {
	.boardName			= "BOBK-Caelum-Customer-Board-1",
	.numBoardMppTypeValue		= ARRSZ(bobk_caelum_customer_board_1_InfoBoardModTypeInfo),
	.pBoardModTypeValue		= bobk_caelum_customer_board_1_InfoBoardModTypeInfo,
	.numBoardMppConfigValue		= ARRSZ(bobk_caelum_customer_board_1_InfoBoardMppConfigValue),
	.pBoardMppConfigValue		= bobk_caelum_customer_board_1_InfoBoardMppConfigValue,
	.intsGppMaskLow			= 0,
	.intsGppMaskMid			= 0,
	.intsGppMaskHigh		= 0,
	.numBoardDeviceIf		= ARRSZ(bobk_caelum_customer_board_1_InfoBoardDeCsInfo),
	.pDevCsInfo			= bobk_caelum_customer_board_1_InfoBoardDeCsInfo,
	.numBoardTwsiDev		= ARRSZ(bobk_caelum_customer_board_1_InfoBoardTwsiDev),
	.pBoardTwsiDev			= bobk_caelum_customer_board_1_InfoBoardTwsiDev,
	.numBoardMacInfo		= ARRSZ(bobk_caelum_customer_board_1_InfoBoardMacInfo),
	.pBoardMacInfo			= bobk_caelum_customer_board_1_InfoBoardMacInfo,
	.numBoardGppInfo		= 0,
	.pBoardGppInfo			= NULL,
	.activeLedsNumber		= 0,
	.pLedGppPin			= NULL,
	.ledsPolarity			= 0,

	/* GPP values */
	.gppOutEnValLow			= BOBK_CAELUM_CUSTOMER_1_GPP_OUT_ENA_LOW,
	.gppOutEnValMid			= BOBK_CAELUM_CUSTOMER_1_GPP_OUT_ENA_MID,
	.gppOutEnValHigh		= 0,
	.gppOutValLow			= BOBK_CAELUM_CUSTOMER_1_GPP_OUT_VAL_LOW,
	.gppOutValMid			= BOBK_CAELUM_CUSTOMER_1_GPP_OUT_VAL_MID,
	.gppOutValHigh			= 0,
	.gppPolarityValLow		= BOBK_CAELUM_CUSTOMER_1_GPP_POL_LOW,
	.gppPolarityValMid		= BOBK_CAELUM_CUSTOMER_1_GPP_POL_MID,
	.gppPolarityValHigh		= 0,

	/* External Switch Configuration */
	.pSwitchInfo = NULL,
	.switchInfoNum = 0,

	/* NAND init params */
	.nandFlashReadParams		= BOBK_CAELUM_CUSTOMER_1_BOARD_NAND_READ_PARAMS,
	.nandFlashWriteParams		= BOBK_CAELUM_CUSTOMER_1_BOARD_NAND_WRITE_PARAMS,
	.nandFlashControl		= BOBK_CAELUM_CUSTOMER_1_BOARD_NAND_CONTROL,
	/* NOR init params */
	.norFlashReadParams		= BOBK_CAELUM_CUSTOMER_1_BOARD_NOR_READ_PARAMS,
	.norFlashWriteParams		= BOBK_CAELUM_CUSTOMER_1_BOARD_NOR_WRITE_PARAMS,
	.isSmiExternalPp		= MV_TRUE,
	.smiExternalPpIndex		= 1,
	.isSdMmcConnected		= MV_TRUE,
	.configAutoDetect		= MV_FALSE	/* Enable modules auto-detection. */
};


MV_BOARD_INFO *customerBOBKBoardInfoTbl[] = {
	&bobk_cetus_customer_board_0_Info,
	&bobk_caelum_customer_board_1_Info,
};

/*******************************************************************************
	Alleycat3 board - Based on BOBCAT2-DB-DX
*******************************************************************************/
#define ALLEYCAT3_CUSTOMER_0_BOARD_NAND_READ_PARAMS		0x000C0282
#define ALLEYCAT3_CUSTOMER_0_BOARD_NAND_WRITE_PARAMS	0x00010305
/*NAND care support for small page chips*/
#define ALLEYCAT3_CUSTOMER_0_BOARD_NAND_CONTROL			0x01c00543

#define ALLEYCAT3_CUSTOMER_0_BOARD_NOR_READ_PARAMS		0x403E07CF
#define ALLEYCAT3_CUSTOMER_0_BOARD_NOR_WRITE_PARAMS		0x000F0F0F

MV_BOARD_TWSI_INFO	alleycat3_customer_board_0_InfoBoardTwsiDev[] = {
/* {{MV_BOARD_DEV_CLASS	devClass, MV_U8	twsiDevAddr, MV_U8 twsiDevAddrType}} */
	{BOARD_DEV_TWSI_PLD, 0x30, ADDR7_BIT},		/* Access to control PLD reg file */
	{BOARD_DEV_TWSI_ZARLINK, 0x18, ADDR7_BIT},		/* Access to Zarlink */
	{BOARD_DEV_TWSI_SATR, 0x4C, ADDR7_BIT},         /* SatR bios 0		*/
	{BOARD_DEV_TWSI_SATR, 0x4D, ADDR7_BIT},         /* SatR bios 1		*/
	{BOARD_DEV_TWSI_SATR, 0x4E, ADDR7_BIT},          /* SatR bios 2		*/
	{BOARD_DEV_TWSI_SATR, 0x4F, ADDR7_BIT},          /* SatR bios 3		*/
	{BOARD_DEV_TWSI_INIT_EPROM, 0x50, ADDR7_BIT},          /* Serial Ini EPROM	*/
	{BOARD_DEV_TWSI_PCA9555_IO_EXPANDER, 0x20, ADDR7_BIT},          /* Qsgmii/sfp mux control PCA9555 IO expander */
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x70, ADDR7_BIT},          /* PCA9548 I2C mux 0	*/
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x71, ADDR7_BIT},          /* PCA9548 I2C mux 1	*/
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x75, ADDR7_BIT}          /* PCA9548 I2C mux 2	*/
};

MV_BOARD_MAC_INFO alleycat3_customer_board_0_InfoBoardMacInfo[] = {
/* {{MV_BOARD_MAC_SPEED boardMacSpeed, MV_32 boardEthSmiAddr , MV_32 boardEthSmiAddr0;}} */
	{BOARD_MAC_SPEED_AUTO, -1, -1, MV_TRUE},
	{BOARD_MAC_SPEED_AUTO, -1, -1, MV_TRUE}
};

MV_BOARD_MODULE_TYPE_INFO alleycat3_customer_board_0_InfoBoardModTypeInfo[] = {
	{
		.boardMppMod		= MV_BOARD_AUTO,
	}
};

MV_DEV_CS_INFO alleycat3_customer_board_0_InfoBoardDeCsInfo[] = {
	/*{deviceCS, params, devType, devWidth, busWidth, busNum, active }*/
#if defined(MV_INCLUDE_SPI)
	{SPI_CS0, N_A, BOARD_DEV_SPI_FLASH, 8, 8, 0, MV_TRUE}, /* SPI DEV */
#endif
#if defined(MV_INCLUDE_NOR) && defined(MV_INCLUDE_NAND)
	{DEVICE_CS0, N_A, BOARD_DEV_NAND_FLASH, 8, 8, 0, MV_TRUE}, /* NAND DEV */
	{DEV_BOOCS, N_A, BOARD_DEV_NOR_FLASH, 16, 16, 0, MV_TRUE} /* NOR DEV */
#elif defined(MV_INCLUDE_NAND)
	{DEVICE_CS0, N_A, BOARD_DEV_NAND_FLASH, 8, 8, 0, MV_TRUE} /* NAND DEV */
#elif defined(MV_INCLUDE_NOR)
	{DEV_BOOCS, N_A, BOARD_DEV_NOR_FLASH, 16, 16, 0, MV_TRUE} /* NOR DEV */
#endif
};

MV_BOARD_MPP_INFO alleycat3_customer_board_0_InfoBoardMppConfigValue[] = {
	{ {
	ALLEYCAT3_CUSTOMER_0_MPP0_7,
	ALLEYCAT3_CUSTOMER_0_MPP8_15,
	ALLEYCAT3_CUSTOMER_0_MPP16_23,
	ALLEYCAT3_CUSTOMER_0_MPP24_31,
	ALLEYCAT3_CUSTOMER_0_MPP32_39,
	} },
};

MV_BOARD_INFO alleycat3_customer_board_0_Info = {
	.boardName			= "ALLEYCAT3-Customer-Board-0",
	.numBoardMppTypeValue		= ARRSZ(alleycat3_customer_board_0_InfoBoardModTypeInfo),
	.pBoardModTypeValue		= alleycat3_customer_board_0_InfoBoardModTypeInfo,
	.numBoardMppConfigValue		= ARRSZ(alleycat3_customer_board_0_InfoBoardMppConfigValue),
	.pBoardMppConfigValue		= alleycat3_customer_board_0_InfoBoardMppConfigValue,
	.intsGppMaskLow			= 0,
	.intsGppMaskMid			= 0,
	.intsGppMaskHigh		= 0,
	.numBoardDeviceIf		= ARRSZ(alleycat3_customer_board_0_InfoBoardDeCsInfo),
	.pDevCsInfo			= alleycat3_customer_board_0_InfoBoardDeCsInfo,
	.numBoardTwsiDev		= ARRSZ(alleycat3_customer_board_0_InfoBoardTwsiDev),
	.pBoardTwsiDev			= alleycat3_customer_board_0_InfoBoardTwsiDev,
	.numBoardMacInfo		= ARRSZ(alleycat3_customer_board_0_InfoBoardMacInfo),
	.pBoardMacInfo			= alleycat3_customer_board_0_InfoBoardMacInfo,
	.numBoardGppInfo		= 0,
	.pBoardGppInfo			= NULL,
	.activeLedsNumber		= 0,
	.pLedGppPin			= NULL,
	.ledsPolarity			= 0,

	/* GPP values */
	.gppOutEnValLow			= ALLEYCAT3_CUSTOMER_0_GPP_OUT_ENA_LOW,
	.gppOutEnValMid			= ALLEYCAT3_CUSTOMER_0_GPP_OUT_ENA_MID,
	.gppOutEnValHigh		= 0,
	.gppOutValLow			= ALLEYCAT3_CUSTOMER_0_GPP_OUT_VAL_LOW,
	.gppOutValMid			= ALLEYCAT3_CUSTOMER_0_GPP_OUT_VAL_MID,
	.gppOutValHigh			= 0,
	.gppPolarityValLow		= ALLEYCAT3_CUSTOMER_0_GPP_POL_LOW,
	.gppPolarityValMid		= ALLEYCAT3_CUSTOMER_0_GPP_POL_MID,
	.gppPolarityValHigh		= 0,

	/* External Switch Configuration */
	.pSwitchInfo = NULL,
	.switchInfoNum = 0,

	/* NAND init params */
	.nandFlashReadParams		= ALLEYCAT3_CUSTOMER_0_BOARD_NAND_READ_PARAMS,
	.nandFlashWriteParams		= ALLEYCAT3_CUSTOMER_0_BOARD_NAND_WRITE_PARAMS,
	.nandFlashControl		= ALLEYCAT3_CUSTOMER_0_BOARD_NAND_CONTROL,
	/* NOR init params */
	.norFlashReadParams		= ALLEYCAT3_CUSTOMER_0_BOARD_NOR_READ_PARAMS,
	.norFlashWriteParams		= ALLEYCAT3_CUSTOMER_0_BOARD_NOR_WRITE_PARAMS,
	.configAutoDetect		= MV_FALSE	/* Enable modules auto-detection. */
};

MV_BOARD_INFO *customerAC3BoardInfoTbl[] = {
	&alleycat3_customer_board_0_Info,
	&alleycat3_customer_board_0_Info
};

/***************************************** Marvell Boards *****************************************/
/***********************/
/* BOBCAT2-DB-DX BOARD */
/***********************/
#define DB_DX_BC2_BOARD_NAND_READ_PARAMS	0x000C0282
#define DB_DX_BC2_BOARD_NAND_WRITE_PARAMS	0x00010305
/*NAND care support for small page chips*/
#define DB_DX_BC2_BOARD_NAND_CONTROL		0x01c00543

#define DB_DX_BC2_BOARD_NOR_READ_PARAMS	0x403E07CF
#define DB_DX_BC2_BOARD_NOR_WRITE_PARAMS	0x000F0F0F

MV_BOARD_TWSI_INFO	db_dx_bc2InfoBoardTwsiDev[] = {
/* {{MV_BOARD_DEV_CLASS	devClass, MV_U8	twsiDevAddr, MV_U8 twsiDevAddrType}} */
	{BOARD_DEV_TWSI_PLD, 0x30, ADDR7_BIT},		/* Access to control PLD reg file */
	{BOARD_DEV_TWSI_ZARLINK, 0x18, ADDR7_BIT},		/* Access to Zarlink 	*/
	{BOARD_DEV_TWSI_SATR, 0x4C, ADDR7_BIT},         /* SatR bios 0		*/
	{BOARD_DEV_TWSI_SATR, 0x4D, ADDR7_BIT},         /* SatR bios 1		*/
	{BOARD_DEV_TWSI_SATR, 0x4E, ADDR7_BIT},          /* SatR bios 2		*/
	{BOARD_DEV_TWSI_SATR, 0x4F, ADDR7_BIT},          /* SatR bios 3		*/
	{BOARD_DEV_TWSI_INIT_EPROM, 0x50, ADDR7_BIT},          /* Serial Ini EPROM	*/
	{BOARD_DEV_TWSI_PCA9555_IO_EXPANDER, 0x20, ADDR7_BIT},          /* Qsgmii/sfp mux control PCA9555 IO expander */
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x70, ADDR7_BIT},          /* PCA9548 I2C mux 0	*/
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x71, ADDR7_BIT},          /* PCA9548 I2C mux 1	*/
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x75, ADDR7_BIT}          /* PCA9548 I2C mux 2	*/
};

MV_BOARD_MAC_INFO db_dx_bc2InfoBoardMacInfo[] = {
	/* {{MV_BOARD_MAC_SPEED boardMacSpeed, MV_32 boardEthSmiAddr , MV_32 boardEthSmiAddr0;}} */
	{BOARD_MAC_SPEED_AUTO, -1, -1, MV_TRUE},
	{BOARD_MAC_SPEED_AUTO, -1, -1, MV_TRUE},
};

MV_BOARD_MODULE_TYPE_INFO db_dx_bc2InfoBoardModTypeInfo[] = {
	{
		.boardMppMod		= MV_BOARD_AUTO,
	}
};

MV_DEV_CS_INFO db_dx_bc2InfoBoardDeCsInfo[] = {
	/*{deviceCS, params, devType, devWidth, busWidth, busNum, active }*/
#if defined(MV_INCLUDE_SPI)
	{SPI_CS0, N_A, BOARD_DEV_SPI_FLASH, 8, 8, 0, MV_TRUE}, /* SPI DEV */
#endif
#if defined(MV_INCLUDE_NOR) && defined(MV_INCLUDE_NAND)
	{DEVICE_CS0, N_A, BOARD_DEV_NAND_FLASH, 8, 8, 0, MV_TRUE}, /* NAND DEV */
	{DEV_BOOCS, N_A, BOARD_DEV_NOR_FLASH, 16, 16, 0, MV_TRUE} /* NOR DEV */
#elif defined(MV_INCLUDE_NAND)
	{DEVICE_CS0, N_A, BOARD_DEV_NAND_FLASH, 8, 8, 0, MV_TRUE} /* NAND DEV */
#elif defined(MV_INCLUDE_NOR)
	{DEV_BOOCS, N_A, BOARD_DEV_NOR_FLASH, 16, 16, 0, MV_TRUE} /* NOR DEV */
#endif
};

MV_BOARD_MPP_INFO db_dx_bc2InfoBoardMppConfigValue[] = {
	{ {
#if defined(MV_INCLUDE_NOR)
	DB_DX_BC2_NOR_MPP0_7,
	DB_DX_BC2_NOR_MPP8_15,
#else
	DB_DX_BC2_MPP0_7,
	DB_DX_BC2_MPP8_15,
#endif
	DB_DX_BC2_MPP16_23,
	DB_DX_BC2_MPP24_31,
	DB_DX_BC2_MPP32_39,
	} },
};

MV_BOARD_INFO db_dx_bc2Info = {
	.boardName			= "DB-DXBC2-MM",
	.numBoardMppTypeValue		= ARRSZ(db_dx_bc2InfoBoardModTypeInfo),
	.pBoardModTypeValue		= db_dx_bc2InfoBoardModTypeInfo,
	.numBoardMppConfigValue		= ARRSZ(db_dx_bc2InfoBoardMppConfigValue),
	.pBoardMppConfigValue		= db_dx_bc2InfoBoardMppConfigValue,
	.intsGppMaskLow			= 0,
	.intsGppMaskMid			= 0,
	.intsGppMaskHigh		= 0,
	.numBoardDeviceIf		= ARRSZ(db_dx_bc2InfoBoardDeCsInfo),
	.pDevCsInfo			= db_dx_bc2InfoBoardDeCsInfo,
	.numBoardTwsiDev		= ARRSZ(db_dx_bc2InfoBoardTwsiDev),
	.pBoardTwsiDev			= db_dx_bc2InfoBoardTwsiDev,
	.numBoardMacInfo		= ARRSZ(db_dx_bc2InfoBoardMacInfo),
	.pBoardMacInfo			= db_dx_bc2InfoBoardMacInfo,
	.numBoardGppInfo		= 0,
	.pBoardGppInfo			= NULL,
	.activeLedsNumber		= 0,
	.pLedGppPin			= NULL,
	.ledsPolarity			= 0,

	/* GPP values */
	.gppOutEnValLow			= DB_DX_BC2_GPP_OUT_ENA_LOW,
	.gppOutEnValMid			= DB_DX_BC2_GPP_OUT_ENA_MID,
	.gppOutEnValHigh		= 0,
	.gppOutValLow			= DB_DX_BC2_GPP_OUT_VAL_LOW,
	.gppOutValMid			= DB_DX_BC2_GPP_OUT_VAL_MID,
	.gppOutValHigh			= 0,
	.gppPolarityValLow		= DB_DX_BC2_GPP_POL_LOW,
	.gppPolarityValMid		= DB_DX_BC2_GPP_POL_MID,
	.gppPolarityValHigh		= 0,

	/* External Switch Configuration */
	.pSwitchInfo = NULL,
	.switchInfoNum = 0,

	/* NAND init params */
	.nandFlashReadParams		= DB_DX_BC2_BOARD_NAND_READ_PARAMS,
	.nandFlashWriteParams		= DB_DX_BC2_BOARD_NAND_WRITE_PARAMS,
	.nandFlashControl		= DB_DX_BC2_BOARD_NAND_CONTROL,
	/* NOR init params */
	.norFlashReadParams		= DB_DX_BC2_BOARD_NOR_READ_PARAMS,
	.norFlashWriteParams		= DB_DX_BC2_BOARD_NOR_WRITE_PARAMS,
	.modelName			= "BobCat2 Development Board",
	.isSmiExternalPp		= MV_FALSE,
	.isSdMmcConnected		= MV_TRUE,
	.configAutoDetect		= MV_TRUE,	/* Enable modules auto-detection. */
	.isCm3				= MV_TRUE
};

/**********************************************************************************/
/***********************/
/* BOBCAT2-RD-DX BOARD */
/***********************/
#define RD_DX_BC2_BOARD_NAND_READ_PARAMS		0x000C0282
#define RD_DX_BC2_BOARD_NAND_WRITE_PARAMS	0x00010305
/*NAND care support for small page chips*/
#define RD_DX_BC2_BOARD_NAND_CONTROL			0x01c00543

MV_BOARD_MAC_INFO rd_dx_bc2InfoBoardMacInfo[] = {
	/* {{MV_BOARD_MAC_SPEED boardMacSpeed, MV_32 boardEthSmiAddr , MV_32 boardEthSmiAddr0;}} */
	{BOARD_MAC_SPEED_AUTO, 0x0, 0x0, MV_TRUE},
};

MV_BOARD_MODULE_TYPE_INFO rd_dx_bc2InfoBoardModTypeInfo[] = {
	{
		.boardMppMod		= MV_BOARD_AUTO,
	}
};

MV_DEV_CS_INFO rd_dx_bc2InfoBoardDeCsInfo[] = {
	/*{deviceCS, params, devType, devWidth, busNum, active}*/
#if defined(MV_INCLUDE_SPI)
	{SPI_CS0, N_A, BOARD_DEV_SPI_FLASH, 8, 8, 0, MV_TRUE}, /* SPI DEV */
#endif
#if defined(MV_INCLUDE_NAND)
	{DEVICE_CS0, N_A, BOARD_DEV_NAND_FLASH, 8, 8, 0, MV_TRUE} /* NAND DEV */
#endif
};

MV_BOARD_MPP_INFO rd_dx_bc2InfoBoardMppConfigValue[] = {
	{ {
		RD_DX_BC2_MPP0_7,
		RD_DX_BC2_MPP8_15,
		RD_DX_BC2_MPP16_23,
		RD_DX_BC2_MPP24_31,
		RD_DX_BC2_MPP32_39,
	} }
};

MV_BOARD_INFO rd_dx_bc2Info = {
	.boardName			= "RD-DXBC2-48G-12XG2XLG",
	.numBoardMppTypeValue		= ARRSZ(rd_dx_bc2InfoBoardModTypeInfo),
	.pBoardModTypeValue		= rd_dx_bc2InfoBoardModTypeInfo,
	.numBoardMppConfigValue		= ARRSZ(rd_dx_bc2InfoBoardMppConfigValue),
	.pBoardMppConfigValue		= rd_dx_bc2InfoBoardMppConfigValue,
	.intsGppMaskLow			= 0,
	.intsGppMaskMid			= 0,
	.intsGppMaskHigh		= 0,
	.numBoardDeviceIf		= ARRSZ(rd_dx_bc2InfoBoardDeCsInfo),
	.pDevCsInfo			= rd_dx_bc2InfoBoardDeCsInfo,
	.numBoardTwsiDev		= 0,
	.pBoardTwsiDev			= NULL,
	.numBoardMacInfo		= ARRSZ(rd_dx_bc2InfoBoardMacInfo),
	.pBoardMacInfo			= rd_dx_bc2InfoBoardMacInfo,
	.numBoardGppInfo		= 0,
	.pBoardGppInfo			= NULL,
	.activeLedsNumber		= 0,
	.pLedGppPin			= NULL,
	.ledsPolarity			= 0,

	/* GPP values */
	.gppOutEnValLow			= RD_DX_BC2_GPP_OUT_ENA_LOW,
	.gppOutEnValMid			= RD_DX_BC2_GPP_OUT_ENA_MID,
	.gppOutEnValHigh		= 0,
	.gppOutValLow			= RD_DX_BC2_GPP_OUT_VAL_LOW,
	.gppOutValMid			= RD_DX_BC2_GPP_OUT_VAL_MID,
	.gppOutValHigh			= 0,
	.gppPolarityValLow		= RD_DX_BC2_GPP_POL_LOW,
	.gppPolarityValMid		= RD_DX_BC2_GPP_POL_MID,
	.gppPolarityValHigh		= 0,

	/* External Switch Configuration */
	.pSwitchInfo			= NULL,
	.switchInfoNum			= 0,

	 /* NAND init params */
	.nandFlashReadParams		= RD_DX_BC2_BOARD_NAND_READ_PARAMS,
	.nandFlashWriteParams		= RD_DX_BC2_BOARD_NAND_WRITE_PARAMS,
	.nandFlashControl		= RD_DX_BC2_BOARD_NAND_CONTROL,
	.modelName			= "BobCat2 Reference Design Board",
	.isSmiExternalPp		= MV_FALSE,
	.isSdMmcConnected		= MV_TRUE,
	.configAutoDetect		= MV_TRUE,	/* Enable modules auto-detection. */
	.isCm3				= MV_TRUE
};

/**********************************************************************************/
/*****************************/
/* BobCat2 RD BC2_MTL BOARD */
/*****************************/
#define RD_MTL_BC2_BOARD_NAND_READ_PARAMS		0x000C0282
#define RD_MTL_BC2_BOARD_NAND_WRITE_PARAMS	0x00010305
/*NAND care support for small page chips*/
#define RD_MTL_BC2_BOARD_NAND_CONTROL			0x01c00543

MV_BOARD_TWSI_INFO	bc2_rd_mtlInfoBoardTwsiDev[] = {
/* {{MV_BOARD_DEV_CLASS	devClass, MV_U8	twsiDevAddr, MV_U8 twsiDevAddrType}} */
	{BOARD_DEV_TWSI_PLD, 0x77, ADDR7_BIT},				/* Access to control PLD reg file */
	{BOARD_DEV_TWSI_INIT_EPROM, 0x50, ADDR7_BIT},		/* Serial Ini EPROM	*/
};

MV_BOARD_MAC_INFO bc2_rd_mtlInfoBoardMacInfo[] = {
	/* {{MV_BOARD_MAC_SPEED boardMacSpeed, MV_32 boardEthSmiAddr , MV_32 boardEthSmiAddr0;}} */
	{BOARD_MAC_SPEED_AUTO, 0x0, 0x0, MV_TRUE},
};

MV_BOARD_MODULE_TYPE_INFO bc2_rd_mtlInfoBoardModTypeInfo[] = {
	{
		.boardMppMod		= MV_BOARD_AUTO,
	}
};

MV_DEV_CS_INFO bc2_rd_mtlInfoBoardDeCsInfo[] = {
	/*{deviceCS, params, devType, devWidth, busNum, active}*/
#if defined(MV_INCLUDE_SPI)
	{SPI_CS0, N_A, BOARD_DEV_SPI_FLASH, 8, 8, 0, MV_TRUE}, /* SPI DEV */
#endif
#if defined(MV_INCLUDE_NAND)
	{DEVICE_CS0, N_A, BOARD_DEV_NAND_FLASH, 8, 8, 0, MV_TRUE} /* NAND DEV */
#endif
};

MV_BOARD_MPP_INFO bc2_rd_mtlInfoBoardMppConfigValue[] = {
	{ {
		RD_MTL_BC2_MPP0_7,
		RD_MTL_BC2_MPP8_15,
		RD_MTL_BC2_MPP16_23,
		RD_MTL_BC2_MPP24_31,
		RD_MTL_BC2_MPP32_39,
	} }
};

MV_BOARD_INFO bc2_rd_mtlInfo = {
	.boardName					= "RD-MTL-BC2-48G-12XG2XLG",
	.numBoardMppTypeValue		= ARRSZ(bc2_rd_mtlInfoBoardModTypeInfo),
	.pBoardModTypeValue			= bc2_rd_mtlInfoBoardModTypeInfo,
	.numBoardMppConfigValue		= ARRSZ(bc2_rd_mtlInfoBoardMppConfigValue),
	.pBoardMppConfigValue		= bc2_rd_mtlInfoBoardMppConfigValue,
	.intsGppMaskLow			= 0,
	.intsGppMaskMid			= 0,
	.intsGppMaskHigh		= 0,
	.numBoardDeviceIf		= ARRSZ(bc2_rd_mtlInfoBoardDeCsInfo),
	.pDevCsInfo				= bc2_rd_mtlInfoBoardDeCsInfo,
	.numBoardTwsiDev		= ARRSZ(bc2_rd_mtlInfoBoardTwsiDev),
	.pBoardTwsiDev			= bc2_rd_mtlInfoBoardTwsiDev,
	.numBoardMacInfo		= ARRSZ(bc2_rd_mtlInfoBoardMacInfo),
	.pBoardMacInfo			= bc2_rd_mtlInfoBoardMacInfo,
	.numBoardGppInfo		= 0,
	.pBoardGppInfo			= NULL,
	.activeLedsNumber		= 0,
	.pLedGppPin				= NULL,
	.ledsPolarity			= 0,

	/* GPP values */
	.gppOutEnValLow			= RD_MTL_BC2_GPP_OUT_ENA_LOW,
	.gppOutEnValMid			= RD_MTL_BC2_GPP_OUT_ENA_MID,
	.gppOutEnValHigh		= 0,
	.gppOutValLow			= RD_MTL_BC2_GPP_OUT_VAL_LOW,
	.gppOutValMid			= RD_MTL_BC2_GPP_OUT_VAL_MID,
	.gppOutValHigh			= 0,
	.gppPolarityValLow		= RD_MTL_BC2_GPP_POL_LOW,
	.gppPolarityValMid		= RD_MTL_BC2_GPP_POL_MID,
	.gppPolarityValHigh		= 0,

	/* External Switch Configuration */
	.pSwitchInfo = NULL,
	.switchInfoNum = 0,

	/* NAND init params */
	.nandFlashReadParams	= RD_MTL_BC2_BOARD_NAND_READ_PARAMS,
	.nandFlashWriteParams	= RD_MTL_BC2_BOARD_NAND_WRITE_PARAMS,
	.nandFlashControl		= RD_MTL_BC2_BOARD_NAND_CONTROL,
	.modelName			= "BobCat2 Reference Design Board",
	.isSmiExternalPp		= MV_FALSE,
	.isSdMmcConnected		= MV_TRUE,
	.configAutoDetect		= MV_TRUE,	/* Enable modules auto-detection. */
	.isCm3				= MV_TRUE
};

/*********************************************************************************/
/*************************************/
/* BOBK-CETUS-DB-98DX4235-12XG BOARD */
/*************************************/
#define DB_DX_BOBK_BOARD_NAND_READ_PARAMS	0x000C0282
#define DB_DX_BOBK_BOARD_NAND_WRITE_PARAMS	0x00010305
/*NAND care support for small page chips*/
#define DB_DX_BOBK_BOARD_NAND_CONTROL		0x01c00543

#define DB_DX_BOBK_BOARD_NOR_READ_PARAMS	0x403E07CF
#define DB_DX_BOBK_BOARD_NOR_WRITE_PARAMS	0x000F0F0F

/* TODO */
MV_BOARD_TWSI_INFO	db_dx_bobkCetusInfoBoardTwsiDev[] = {
/* {{MV_BOARD_DEV_CLASS	devClass, MV_U8	twsiDevAddr, MV_U8 twsiDevAddrType}} */
	{BOARD_DEV_TWSI_PLD, 0x18, ADDR7_BIT},		/* Access to control PLD reg file */
	{BOARD_DEV_TWSI_ZARLINK, 0x1B, ADDR7_BIT},		/* Access to Zarlink	*/
	{BOARD_DEV_TWSI_SATR, 0x4C, ADDR7_BIT},         /* SatR bios 0		*/
	{BOARD_DEV_TWSI_SATR, 0x4D, ADDR7_BIT},         /* SatR bios 1		*/
	{BOARD_DEV_TWSI_SATR, 0x4E, ADDR7_BIT},          /* SatR bios 2		*/
	{BOARD_DEV_TWSI_SATR, 0x4F, ADDR7_BIT},          /* SatR bios 3		*/
	{BOARD_DEV_TWSI_INIT_EPROM, 0x50, ADDR7_BIT},          /* Serial Init EPROM	*/
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x70, ADDR7_BIT},          /* PCA9548 I2C mux 0	*/
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x71, ADDR7_BIT},          /* PCA9548 I2C mux 1	*/
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x75, ADDR7_BIT}          /* PCA9548 I2C mux 2	*/
};

MV_BOARD_MAC_INFO db_dx_bobkCetusInfoBoardMacInfo[] = {
	/* {{MV_BOARD_MAC_SPEED boardMacSpeed, MV_32 boardEthSmiAddr , MV_32 boardEthSmiAddr0;}} */
	{BOARD_MAC_SPEED_AUTO, -1, -1, MV_FALSE},
	{BOARD_MAC_SPEED_AUTO, 0x0, 0x0, MV_TRUE},
};

MV_BOARD_MODULE_TYPE_INFO db_dx_bobkCetusInfoBoardModTypeInfo[] = {
	{
		.boardMppMod		= MV_BOARD_AUTO,
	}
};

/* TO DE */
MV_DEV_CS_INFO db_dx_bobkCetusInfoBoardDeCsInfo[] = {
	/*{deviceCS, params, devType, devWidth, busWidth }*/
#if defined(MV_INCLUDE_SPI)
	{SPI_CS0, N_A, BOARD_DEV_SPI_FLASH, 8, 8, 0, MV_TRUE}, /* SPI DEV */
#endif
#if defined(MV_INCLUDE_NOR)
	{DEV_BOOCS, N_A, BOARD_DEV_NOR_FLASH, 16, 16, 0, MV_TRUE} /* NOR DEV */
#endif
#if defined(MV_INCLUDE_NAND)
	{DEVICE_CS0, N_A, BOARD_DEV_NAND_FLASH, 8, 8, 0, MV_TRUE} /* NAND DEV */
#endif
};

MV_BOARD_MPP_INFO db_dx_bobkCetusInfoBoardMppConfigValue[] = {
	{ {
#if defined(MV_INCLUDE_NOR)
	DB_DX_BOBK_CETUS_NOR_MPP0_7,
	DB_DX_BOBK_CETUS_NOR_MPP8_15,
#else
	DB_DX_BOBK_CETUS_MPP0_7,
	DB_DX_BOBK_CETUS_MPP8_15,
#endif
	DB_DX_BOBK_CETUS_MPP16_23,
	DB_DX_BOBK_CETUS_MPP24_31,
	DB_DX_BOBK_CETUS_MPP32_39,
	} },
};

MV_BOARD_INFO db_dx_bobkCetusInfo = {
	.boardName			= "DB-98DX4235-12XG",
	.numBoardMppTypeValue		= ARRSZ(db_dx_bobkCetusInfoBoardModTypeInfo),
	.pBoardModTypeValue		= db_dx_bobkCetusInfoBoardModTypeInfo,
	.numBoardMppConfigValue		= ARRSZ(db_dx_bobkCetusInfoBoardMppConfigValue),
	.pBoardMppConfigValue		= db_dx_bobkCetusInfoBoardMppConfigValue,
	.intsGppMaskLow			= 0,
	.intsGppMaskMid			= 0,
	.intsGppMaskHigh		= 0,
	.numBoardDeviceIf		= ARRSZ(db_dx_bobkCetusInfoBoardDeCsInfo),
	.pDevCsInfo			= db_dx_bobkCetusInfoBoardDeCsInfo,
	.numBoardTwsiDev		= ARRSZ(db_dx_bobkCetusInfoBoardTwsiDev),
	.pBoardTwsiDev			= db_dx_bobkCetusInfoBoardTwsiDev,
	.numBoardMacInfo		= ARRSZ(db_dx_bobkCetusInfoBoardMacInfo),
	.pBoardMacInfo			= db_dx_bobkCetusInfoBoardMacInfo,
	.numBoardGppInfo		= 0,
	.pBoardGppInfo			= NULL,
	.activeLedsNumber		= 0,
	.pLedGppPin			= NULL,
	.ledsPolarity			= 0,

	/* GPP values */
	.gppOutEnValLow			= DB_DX_BOBK_CETUS_GPP_OUT_ENA_LOW,
	.gppOutEnValMid			= DB_DX_BOBK_CETUS_GPP_OUT_ENA_MID,
	.gppOutEnValHigh		= 0,
	.gppOutValLow			= DB_DX_BOBK_CETUS_GPP_OUT_VAL_LOW,
	.gppOutValMid			= DB_DX_BOBK_CETUS_GPP_OUT_VAL_MID,
	.gppOutValHigh			= 0,
	.gppPolarityValLow		= DB_DX_BOBK_CETUS_GPP_POL_LOW,
	.gppPolarityValMid		= DB_DX_BOBK_CETUS_GPP_POL_MID,
	.gppPolarityValHigh		= 0,

	/* External Switch Configuration */
	.pSwitchInfo = NULL,
	.switchInfoNum = 0,

	/* NAND init params */
	.nandFlashReadParams		= DB_DX_BOBK_BOARD_NAND_READ_PARAMS,
	.nandFlashWriteParams		= DB_DX_BOBK_BOARD_NAND_WRITE_PARAMS,
	.nandFlashControl		= DB_DX_BOBK_BOARD_NAND_CONTROL,
	/* NOR init params */
	.norFlashReadParams		= DB_DX_BOBK_BOARD_NOR_READ_PARAMS,
	.norFlashWriteParams		= DB_DX_BOBK_BOARD_NOR_WRITE_PARAMS,
	.isSmiExternalPp		= MV_TRUE,
	.smiExternalPpIndex		= 0,
	.modelName			= "BobK Cetus Development Board",
	.isSdMmcConnected		= MV_TRUE,
	.configAutoDetect		= MV_TRUE,	/* Enable modules auto-detection. */
	.isCm3				= MV_TRUE
};

/*********************************************************************************/
/**************************************/
/* BOBK-CAELUM-DB-98DX4203-48G12XG BOARD */
/**************************************/

MV_BOARD_TWSI_INFO	db_dx_bobkCaelumInfoBoardTwsiDev[] = {
/* {{MV_BOARD_DEV_CLASS	devClass, MV_U8	twsiDevAddr, MV_U8 twsiDevAddrType}} */
	{BOARD_DEV_TWSI_PLD, 0x18, ADDR7_BIT},		/* Access to control PLD reg file */
	{BOARD_DEV_TWSI_ZARLINK, 0x1B, ADDR7_BIT},		/* Access to Zarlink	*/
	{BOARD_DEV_TWSI_SATR, 0x4C, ADDR7_BIT},         /* SatR bios 0		*/
	{BOARD_DEV_TWSI_SATR, 0x4D, ADDR7_BIT},         /* SatR bios 1		*/
	{BOARD_DEV_TWSI_SATR, 0x4E, ADDR7_BIT},          /* SatR bios 2		*/
	{BOARD_DEV_TWSI_SATR, 0x4F, ADDR7_BIT},          /* SatR bios 3		*/
	{BOARD_DEV_TWSI_INIT_EPROM, 0x50, ADDR7_BIT},          /* Serial Init EPROM	*/
	{BOARD_DEV_TWSI_PCA9555_IO_EXPANDER, 0x20, ADDR7_BIT},          /* Qsgmii/sfp mux control PCA9555 IO expander */
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x70, ADDR7_BIT},          /* PCA9548 I2C mux 0	*/
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x71, ADDR7_BIT},          /* PCA9548 I2C mux 1	*/
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x75, ADDR7_BIT}          /* PCA9548 I2C mux 2	*/
};

MV_BOARD_MAC_INFO db_dx_bobkCaelumInfoBoardMacInfo[] = {
	/* {{MV_BOARD_MAC_SPEED boardMacSpeed, MV_32 boardEthSmiAddr , MV_32 boardEthSmiAddr0;}} */
	{BOARD_MAC_SPEED_AUTO, -1, -1, MV_FALSE},
	{BOARD_MAC_SPEED_AUTO, 0x0, 0x0, MV_TRUE},
};

MV_BOARD_MODULE_TYPE_INFO db_dx_bobkCaelumInfoBoardModTypeInfo[] = {
	{
		.boardMppMod		= MV_BOARD_AUTO,
	}
};

/* TO DE */
MV_DEV_CS_INFO db_dx_bobkCaelumInfoBoardDeCsInfo[] = {
	/*{deviceCS, params, devType, devWidth, busWidth }*/
#if defined(MV_INCLUDE_SPI)
	{SPI_CS0, N_A, BOARD_DEV_SPI_FLASH, 8, 8, 0, MV_TRUE}, /* SPI DEV */
#endif
#if defined(MV_INCLUDE_NOR)
	{DEV_BOOCS, N_A, BOARD_DEV_NOR_FLASH, 16, 16, 0, MV_TRUE} /* NOR DEV */
#endif
#if defined(MV_INCLUDE_NAND)
	{DEVICE_CS0, N_A, BOARD_DEV_NAND_FLASH, 8, 8, 0, MV_TRUE} /* NAND DEV */
#endif
};

MV_BOARD_MPP_INFO db_dx_bobkCaelumInfoBoardMppConfigValue[] = {
	{ {
#if defined(MV_INCLUDE_NOR)
	DB_DX_BOBK_CAELUM_NOR_MPP0_7,
	DB_DX_BOBK_CAELUM_NOR_MPP8_15,
#else
	DB_DX_BOBK_CAELUM_MPP0_7,
	DB_DX_BOBK_CAELUM_MPP8_15,
#endif
	DB_DX_BOBK_CAELUM_MPP16_23,
	DB_DX_BOBK_CAELUM_MPP24_31,
	DB_DX_BOBK_CAELUM_MPP32_39,
	} },
};

MV_BOARD_INFO db_dx_bobkCaelumInfo = {
	.boardName			= "DB-98DX4203-48G12XG",
	.numBoardMppTypeValue		= ARRSZ(db_dx_bobkCaelumInfoBoardModTypeInfo),
	.pBoardModTypeValue		= db_dx_bobkCaelumInfoBoardModTypeInfo,
	.numBoardMppConfigValue		= ARRSZ(db_dx_bobkCaelumInfoBoardMppConfigValue),
	.pBoardMppConfigValue		= db_dx_bobkCaelumInfoBoardMppConfigValue,
	.intsGppMaskLow			= 0,
	.intsGppMaskMid			= 0,
	.intsGppMaskHigh		= 0,
	.numBoardDeviceIf		= ARRSZ(db_dx_bobkCaelumInfoBoardDeCsInfo),
	.pDevCsInfo			= db_dx_bobkCaelumInfoBoardDeCsInfo,
	.numBoardTwsiDev		= ARRSZ(db_dx_bobkCaelumInfoBoardTwsiDev),
	.pBoardTwsiDev			= db_dx_bobkCaelumInfoBoardTwsiDev,
	.numBoardMacInfo		= ARRSZ(db_dx_bobkCaelumInfoBoardMacInfo),
	.pBoardMacInfo			= db_dx_bobkCaelumInfoBoardMacInfo,
	.numBoardGppInfo		= 0,
	.pBoardGppInfo			= NULL,
	.activeLedsNumber		= 0,
	.pLedGppPin			= NULL,
	.ledsPolarity			= 0,

	/* GPP values */
	.gppOutEnValLow			= DB_DX_BOBK_CAELUM_GPP_OUT_ENA_LOW,
	.gppOutEnValMid			= DB_DX_BOBK_CAELUM_GPP_OUT_ENA_MID,
	.gppOutEnValHigh		= 0,
	.gppOutValLow			= DB_DX_BOBK_CAELUM_GPP_OUT_VAL_LOW,
	.gppOutValMid			= DB_DX_BOBK_CAELUM_GPP_OUT_VAL_MID,
	.gppOutValHigh			= 0,
	.gppPolarityValLow		= DB_DX_BOBK_CAELUM_GPP_POL_LOW,
	.gppPolarityValMid		= DB_DX_BOBK_CAELUM_GPP_POL_MID,
	.gppPolarityValHigh		= 0,

	/* External Switch Configuration */
	.pSwitchInfo = NULL,
	.switchInfoNum = 0,

	/* NAND init params */
	.nandFlashReadParams		= DB_DX_BOBK_BOARD_NAND_READ_PARAMS,
	.nandFlashWriteParams		= DB_DX_BOBK_BOARD_NAND_WRITE_PARAMS,
	.nandFlashControl		= DB_DX_BOBK_BOARD_NAND_CONTROL,
	/* NOR init params */
	.norFlashReadParams		= DB_DX_BOBK_BOARD_NOR_READ_PARAMS,
	.norFlashWriteParams		= DB_DX_BOBK_BOARD_NOR_WRITE_PARAMS,
	.isSmiExternalPp		= MV_TRUE,
	.smiExternalPpIndex		= 1,
	.modelName			= "BobK Caelum Development Board",
	.isSdMmcConnected		= MV_TRUE,
	.configAutoDetect		= MV_TRUE,	/* Enable modules auto-detection. */
	.isCm3				= MV_TRUE
};

/*********************************************************************************/
/**************************************/
/* BOBK-LEWIS-RD-LWS-12XG-A BOARD */
/**************************************/


MV_BOARD_TWSI_INFO	rd_dx_bobkLewisInfoBoardTwsiDev[] = {
/* {{MV_BOARD_DEV_CLASS	devClass, MV_U8	twsiDevAddr, MV_U8 twsiDevAddrType}} */
	{BOARD_DEV_TWSI_INIT_EPROM, 0x50, ADDR7_BIT},	/* Serial Init EPROM	*/
};


MV_BOARD_MAC_INFO rd_dx_bobkLewisInfoBoardMacInfo[] = {
/* {{MV_BOARD_MAC_SPEED boardMacSpeed, MV_32 boardEthSmiAddr , MV_32 boardEthSmiAddr0;}} */
	{BOARD_MAC_SPEED_AUTO, -1, -1, MV_FALSE},
	{BOARD_MAC_SPEED_AUTO, 0x0, 0x0, MV_TRUE},
};

MV_BOARD_MODULE_TYPE_INFO rd_dx_bobkLewisInfoBoardModTypeInfo[] = {
	{
		.boardMppMod		= MV_BOARD_AUTO,
	}
};

/* TO DE */
MV_DEV_CS_INFO rd_dx_bobkLewisInfoBoardDeCsInfo[] = {
	/*{deviceCS, params, devType, devWidth, busWidth }*/
#if defined(MV_INCLUDE_SPI)
	{SPI_CS0, N_A, BOARD_DEV_SPI_FLASH, 8, 8, 0, MV_TRUE}, /* SPI DEV */
#endif
#if defined(MV_INCLUDE_NAND)
	{DEVICE_CS0, N_A, BOARD_DEV_NAND_FLASH, 8, 8, 0, MV_TRUE} /* NAND DEV */
#endif
};

MV_BOARD_MPP_INFO rd_dx_bobkLewisInfoBoardMppConfigValue[] = {
	{ {
	RD_DX_BOBK_LEWIS_MPP0_7,
	RD_DX_BOBK_LEWIS_MPP8_15,
	RD_DX_BOBK_LEWIS_MPP16_23,
	RD_DX_BOBK_LEWIS_MPP24_31,
	RD_DX_BOBK_LEWIS_MPP32_39,
	} },
};

MV_BOARD_INFO rd_dx_bobkLewisInfo = {
	.boardName			= "RD-LWS-12XG-A",
	.numBoardMppTypeValue		= ARRSZ(rd_dx_bobkLewisInfoBoardModTypeInfo),
	.pBoardModTypeValue		= rd_dx_bobkLewisInfoBoardModTypeInfo,
	.numBoardMppConfigValue		= ARRSZ(rd_dx_bobkLewisInfoBoardMppConfigValue),
	.pBoardMppConfigValue		= rd_dx_bobkLewisInfoBoardMppConfigValue,
	.intsGppMaskLow			= 0,
	.intsGppMaskMid			= 0,
	.intsGppMaskHigh		= 0,
	.numBoardDeviceIf		= ARRSZ(rd_dx_bobkLewisInfoBoardDeCsInfo),
	.pDevCsInfo			= rd_dx_bobkLewisInfoBoardDeCsInfo,
	.numBoardTwsiDev		= ARRSZ(rd_dx_bobkLewisInfoBoardTwsiDev),
	.pBoardTwsiDev			= rd_dx_bobkLewisInfoBoardTwsiDev,
	.numBoardMacInfo		= ARRSZ(rd_dx_bobkLewisInfoBoardMacInfo),
	.pBoardMacInfo			= rd_dx_bobkLewisInfoBoardMacInfo,
	.numBoardGppInfo		= 0,
	.pBoardGppInfo			= NULL,
	.activeLedsNumber		= 0,
	.pLedGppPin			= NULL,
	.ledsPolarity			= 0,

	/* GPP values */
	.gppOutEnValLow			= RD_DX_BOBK_LEWIS_GPP_OUT_ENA_LOW,
	.gppOutEnValMid			= RD_DX_BOBK_LEWIS_GPP_OUT_ENA_MID,
	.gppOutEnValHigh		= 0,
	.gppOutValLow			= RD_DX_BOBK_LEWIS_GPP_OUT_VAL_LOW,
	.gppOutValMid			= RD_DX_BOBK_LEWIS_GPP_OUT_VAL_MID,
	.gppOutValHigh			= 0,
	.gppPolarityValLow		= RD_DX_BOBK_LEWIS_GPP_POL_LOW,
	.gppPolarityValMid		= RD_DX_BOBK_LEWIS_GPP_POL_MID,
	.gppPolarityValHigh		= 0,

	/* External Switch Configuration */
	.pSwitchInfo = NULL,
	.switchInfoNum = 0,

	/* NAND init params */
	.nandFlashReadParams		= DB_DX_BOBK_BOARD_NAND_READ_PARAMS,
	.nandFlashWriteParams		= DB_DX_BOBK_BOARD_NAND_WRITE_PARAMS,
	.nandFlashControl		= DB_DX_BOBK_BOARD_NAND_CONTROL,
	/* NOR init params */
	.norFlashReadParams		= DB_DX_BOBK_BOARD_NOR_READ_PARAMS,
	.norFlashWriteParams		= DB_DX_BOBK_BOARD_NOR_WRITE_PARAMS,
	.isSmiExternalPp		= MV_TRUE,
	.smiExternalPpIndex		= 0,
	.modelName			= "BobK Lewis Reference Design Board",
	.isSdMmcConnected		= MV_TRUE
};

/*********************************************************************************/
/**************************************/
/* BOBK-CYGNUS-RD-CYG-48G4XG2XLG-A BOARD */
/**************************************/

MV_BOARD_TWSI_INFO	rd_dx_bobkCygnusInfoBoardTwsiDev[] = {
/* {{MV_BOARD_DEV_CLASS	devClass, MV_U8	twsiDevAddr, MV_U8 twsiDevAddrType , MV_BOOL boardMacEnabled;}} */
	{BOARD_DEV_TWSI_INIT_EPROM, 0x50, ADDR7_BIT},          /* Serial Init EPROM	*/

};

MV_BOARD_MAC_INFO rd_dx_bobkCygnusInfoBoardMacInfo[] = {
	/* {{MV_BOARD_MAC_SPEED boardMacSpeed, MV_32 boardEthSmiAddr , MV_32 boardEthSmiAddr0;}} */
	{BOARD_MAC_SPEED_AUTO, -1, -1, MV_FALSE},
	{BOARD_MAC_SPEED_AUTO, 0x0, 0x0, MV_TRUE},
};

MV_BOARD_MODULE_TYPE_INFO rd_dx_bobkCygnusInfoBoardModTypeInfo[] = {
	{
		.boardMppMod		= MV_BOARD_AUTO,
	}
};

/* TO DE */
MV_DEV_CS_INFO rd_dx_bobkCygnusInfoBoardDeCsInfo[] = {
	/*{deviceCS, params, devType, devWidth, busWidth }*/
#if defined(MV_INCLUDE_SPI)
	{SPI_CS0, N_A, BOARD_DEV_SPI_FLASH, 8, 8, 0, MV_TRUE}, /* SPI DEV */
#endif
#if defined(MV_INCLUDE_NAND)
	{DEVICE_CS0, N_A, BOARD_DEV_NAND_FLASH, 8, 8, 0, MV_TRUE} /* NAND DEV */
#endif
};

MV_BOARD_MPP_INFO rd_dx_bobkCygnusInfoBoardMppConfigValue[] = {
	{ {
	RD_DX_BOBK_CYGNUS_MPP0_7,
	RD_DX_BOBK_CYGNUS_MPP8_15,
	RD_DX_BOBK_CYGNUS_MPP16_23,
	RD_DX_BOBK_CYGNUS_MPP24_31,
	RD_DX_BOBK_CYGNUS_MPP32_39,
	} },
};

MV_BOARD_INFO rd_dx_bobkCygnusInfo = {
	.boardName			= "RD-CYG-48G4XG2XLG-A",
	.numBoardMppTypeValue		= ARRSZ(rd_dx_bobkCygnusInfoBoardModTypeInfo),
	.pBoardModTypeValue		= rd_dx_bobkCygnusInfoBoardModTypeInfo,
	.numBoardMppConfigValue		= ARRSZ(rd_dx_bobkCygnusInfoBoardMppConfigValue),
	.pBoardMppConfigValue		= rd_dx_bobkCygnusInfoBoardMppConfigValue,
	.intsGppMaskLow			= 0,
	.intsGppMaskMid			= 0,
	.intsGppMaskHigh		= 0,
	.numBoardDeviceIf		= ARRSZ(rd_dx_bobkCygnusInfoBoardDeCsInfo),
	.pDevCsInfo			= rd_dx_bobkCygnusInfoBoardDeCsInfo,
	.numBoardTwsiDev		= ARRSZ(rd_dx_bobkCygnusInfoBoardTwsiDev),
	.pBoardTwsiDev			= rd_dx_bobkCygnusInfoBoardTwsiDev,
	.numBoardMacInfo		= ARRSZ(rd_dx_bobkCygnusInfoBoardMacInfo),
	.pBoardMacInfo			= rd_dx_bobkCygnusInfoBoardMacInfo,
	.numBoardGppInfo		= 0,
	.pBoardGppInfo			= NULL,
	.activeLedsNumber		= 0,
	.pLedGppPin			= NULL,
	.ledsPolarity			= 0,

	/* GPP values */
	.gppOutEnValLow			= RD_DX_BOBK_CYGNUS_GPP_OUT_ENA_LOW,
	.gppOutEnValMid			= RD_DX_BOBK_CYGNUS_GPP_OUT_ENA_MID,
	.gppOutEnValHigh		= 0,
	.gppOutValLow			= RD_DX_BOBK_CYGNUS_GPP_OUT_VAL_LOW,
	.gppOutValMid			= RD_DX_BOBK_CYGNUS_GPP_OUT_VAL_MID,
	.gppOutValHigh			= 0,
	.gppPolarityValLow		= RD_DX_BOBK_CYGNUS_GPP_POL_LOW,
	.gppPolarityValMid		= RD_DX_BOBK_CYGNUS_GPP_POL_MID,
	.gppPolarityValHigh		= 0,

	/* External Switch Configuration */
	.pSwitchInfo = NULL,
	.switchInfoNum = 0,

	/* NAND init params */
	.nandFlashReadParams		= DB_DX_BOBK_BOARD_NAND_READ_PARAMS,
	.nandFlashWriteParams		= DB_DX_BOBK_BOARD_NAND_WRITE_PARAMS,
	.nandFlashControl		= DB_DX_BOBK_BOARD_NAND_CONTROL,
	/* NOR init params */
	.norFlashReadParams		= DB_DX_BOBK_BOARD_NOR_READ_PARAMS,
	.norFlashWriteParams		= DB_DX_BOBK_BOARD_NOR_WRITE_PARAMS,
	.isSmiExternalPp		= MV_TRUE,
	.smiExternalPpIndex		= 3,
	.modelName			= "BobK Cygnus Reference Development Board",
	.isSdMmcConnected		= MV_TRUE
};

/*********************************************************************************/
/***********************/
/* ALLEYCAT3-DB-DX BOARD */
/***********************/
#define DB_DX_AC3_BOARD_NAND_READ_PARAMS	0x000C0282
#define DB_DX_AC3_BOARD_NAND_WRITE_PARAMS	0x00010305
/*NAND care support for small page chips*/
#define DB_DX_AC3_BOARD_NAND_CONTROL		0x01c00543

#define DB_DX_AC3_BOARD_NOR_READ_PARAMS		0x403E07CF
#define DB_DX_AC3_BOARD_NOR_WRITE_PARAMS	0x000F0F0F

MV_BOARD_TWSI_INFO db_dx_ac3InfoBoardTwsiDev[] = {
/* {{MV_BOARD_DEV_CLASS	devClass, MV_U8	twsiDevAddr, MV_U8 twsiDevAddrType}} */
	{BOARD_DEV_TWSI_PLD, 0x18, ADDR7_BIT},			/* Access to control PLD reg file */
	{BOARD_DEV_TWSI_SATR, 0x4C, ADDR7_BIT},			/* SatR bios 0		*/
	{BOARD_DEV_TWSI_SATR, 0x4D, ADDR7_BIT},			/* SatR bios 1		*/
	{BOARD_DEV_TWSI_SATR, 0x4E, ADDR7_BIT},			/* SatR bios 2		*/
	{BOARD_DEV_TWSI_SATR, 0x4F, ADDR7_BIT},			/* SatR bios 3		*/
	{BOARD_DEV_TWSI_INIT_EPROM, 0x50, ADDR7_BIT},	/* Serial Ini EPROM	*/
	{BOARD_DEV_TWSI_PCA9555_IO_EXPANDER, 0x20, ADDR7_BIT},	/* Qsgmii/sfp mux control PCA9555 IO expander */
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x70, ADDR7_BIT},		/* PCA9548 I2C mux 0	*/
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x71, ADDR7_BIT},		/* PCA9548 I2C mux 1	*/
	{BOARD_DEV_TWSI_PCA9548_IO_MUX, 0x75, ADDR7_BIT}		/* PCA9548 I2C mux 2	*/
};

MV_BOARD_MAC_INFO db_dx_ac3InfoBoardMacInfo[] = {
/* {{MV_BOARD_MAC_SPEED boardMacSpeed, MV_32 boardEthSmiAddr , MV_32 boardEthSmiAddr0;}} */
	{BOARD_MAC_SPEED_AUTO, -1, -1, MV_TRUE},
	{BOARD_MAC_SPEED_AUTO, -1, -1, MV_TRUE}
};

MV_BOARD_MODULE_TYPE_INFO db_dx_ac3InfoBoardModTypeInfo[] = {
	{
		.boardMppMod		= MV_BOARD_AUTO,
	}
};

MV_DEV_CS_INFO db_dx_ac3InfoBoardDeCsInfo[] = {
	/*{deviceCS, params, devType, devWidth, busWidth, busNum, active }*/
#if defined(MV_INCLUDE_SPI)
	{SPI_CS0, N_A, BOARD_DEV_SPI_FLASH, 8, 8, 0, MV_TRUE}, /* SPI DEV */
#endif
#if defined(MV_INCLUDE_NOR) && defined(MV_INCLUDE_NAND)
	{DEVICE_CS0, N_A, BOARD_DEV_NAND_FLASH, 8, 8, 0, MV_TRUE}, /* NAND DEV */
	{DEV_BOOCS, N_A, BOARD_DEV_NOR_FLASH, 16, 16, 0, MV_TRUE} /* NOR DEV */
#elif defined(MV_INCLUDE_NAND)
	{DEVICE_CS0, N_A, BOARD_DEV_NAND_FLASH, 8, 8, 0, MV_TRUE} /* NAND DEV */
#elif defined(MV_INCLUDE_NOR)
	{DEV_BOOCS, N_A, BOARD_DEV_NOR_FLASH, 16, 16, 0, MV_TRUE} /* NOR DEV */
#endif
};

MV_BOARD_MPP_INFO db_dx_ac3InfoBoardMppConfigValue[] = {
	{ {
	DB_DX_AC3_MPP0_7,
	DB_DX_AC3_MPP8_15,
	DB_DX_AC3_MPP16_23,
	DB_DX_AC3_MPP24_31,
	DB_DX_AC3_MPP32_39,
	} },
};

MV_BOARD_INFO db_dx_ac3Info = {
	.boardName			= "DB-XC3-24G4XG",
	.numBoardMppTypeValue		= ARRSZ(db_dx_ac3InfoBoardModTypeInfo),
	.pBoardModTypeValue		= db_dx_ac3InfoBoardModTypeInfo,
	.numBoardMppConfigValue		= ARRSZ(db_dx_ac3InfoBoardMppConfigValue),
	.pBoardMppConfigValue		= db_dx_ac3InfoBoardMppConfigValue,
	.intsGppMaskLow			= 0,
	.intsGppMaskMid			= 0,
	.intsGppMaskHigh		= 0,
	.numBoardDeviceIf		= ARRSZ(db_dx_ac3InfoBoardDeCsInfo),
	.pDevCsInfo			= db_dx_ac3InfoBoardDeCsInfo,
	.numBoardTwsiDev		= ARRSZ(db_dx_ac3InfoBoardTwsiDev),
	.pBoardTwsiDev			= db_dx_ac3InfoBoardTwsiDev,
	.numBoardMacInfo		= ARRSZ(db_dx_ac3InfoBoardMacInfo),
	.pBoardMacInfo			= db_dx_ac3InfoBoardMacInfo,
	.numBoardGppInfo		= 0,
	.pBoardGppInfo			= NULL,
	.activeLedsNumber		= 0,
	.pLedGppPin			= NULL,
	.ledsPolarity			= 0,

	/* GPP values */
	.gppOutEnValLow			= DB_DX_AC3_GPP_OUT_ENA_LOW,
	.gppOutEnValMid			= DB_DX_AC3_GPP_OUT_ENA_MID,
	.gppOutEnValHigh		= 0,
	.gppOutValLow			= DB_DX_AC3_GPP_OUT_VAL_LOW,
	.gppOutValMid			= DB_DX_AC3_GPP_OUT_VAL_MID,
	.gppOutValHigh			= 0,
	.gppPolarityValLow		= DB_DX_AC3_GPP_POL_LOW,
	.gppPolarityValMid		= DB_DX_AC3_GPP_POL_MID,
	.gppPolarityValHigh		= 0,

	/* External Switch Configuration */
	.pSwitchInfo = NULL,
	.switchInfoNum = 0,

	/* NAND init params */
	.nandFlashReadParams		= DB_DX_AC3_BOARD_NAND_READ_PARAMS,
	.nandFlashWriteParams		= DB_DX_AC3_BOARD_NAND_WRITE_PARAMS,
	.nandFlashControl		= DB_DX_AC3_BOARD_NAND_CONTROL,
	/* NOR init params */
	.norFlashReadParams		= DB_DX_AC3_BOARD_NOR_READ_PARAMS,
	.norFlashWriteParams		= DB_DX_AC3_BOARD_NOR_WRITE_PARAMS,
	.configAutoDetect		= MV_TRUE,	/* Enable modules auto-detection. */
	.modelName			= "AlleyCat3 Development Board",
	.isSmiExternalPp		= MV_FALSE
};

/*********************************************************************************/
/******************************/
/* ALLEYCAT3-RD-MTL-4XG BOARD */
/******************************/
MV_BOARD_MPP_INFO rd_mtl_4xg_ac3InfoBoardMppConfigValue[] = {
	{ {
	RD_MTL_4XG_AC3_MPP0_7,
	RD_MTL_4XG_AC3_MPP8_15,
	RD_MTL_4XG_AC3_MPP16_23,
	RD_MTL_4XG_AC3_MPP24_31,
	RD_MTL_4XG_AC3_MPP32_39,
	} },
};

MV_BOARD_INFO rd_mtl_4xg_ac3Info = {
	.boardName			= "RD-XC3-48G4XG-A",
	.numBoardMppTypeValue		= ARRSZ(db_dx_ac3InfoBoardModTypeInfo),
	.pBoardModTypeValue		= db_dx_ac3InfoBoardModTypeInfo,
	.numBoardMppConfigValue		= ARRSZ(rd_mtl_4xg_ac3InfoBoardMppConfigValue),
	.pBoardMppConfigValue		= rd_mtl_4xg_ac3InfoBoardMppConfigValue,
	.intsGppMaskLow			= 0,
	.intsGppMaskMid			= 0,
	.intsGppMaskHigh		= 0,
	.numBoardDeviceIf		= ARRSZ(db_dx_ac3InfoBoardDeCsInfo),
	.pDevCsInfo				= db_dx_ac3InfoBoardDeCsInfo,
	.numBoardTwsiDev		= ARRSZ(db_dx_ac3InfoBoardTwsiDev),
	.pBoardTwsiDev			= db_dx_ac3InfoBoardTwsiDev,
	.numBoardMacInfo		= ARRSZ(db_dx_ac3InfoBoardMacInfo),
	.pBoardMacInfo			= db_dx_ac3InfoBoardMacInfo,
	.numBoardGppInfo		= 0,
	.pBoardGppInfo			= NULL,
	.activeLedsNumber		= 0,
	.pLedGppPin				= NULL,
	.ledsPolarity			= 0,

	/* GPP values */
	.gppOutEnValLow			= RD_MTL_4XG_AC3_GPP_OUT_ENA_LOW,
	.gppOutEnValMid			= RD_MTL_4XG_AC3_GPP_OUT_ENA_MID,
	.gppOutEnValHigh		= 0,
	.gppOutValLow			= RD_MTL_4XG_AC3_GPP_OUT_VAL_LOW,
	.gppOutValMid			= RD_MTL_4XG_AC3_GPP_OUT_VAL_MID,
	.gppOutValHigh			= 0,
	.gppPolarityValLow		= RD_MTL_4XG_AC3_GPP_POL_LOW,
	.gppPolarityValMid		= RD_MTL_4XG_AC3_GPP_POL_MID,
	.gppPolarityValHigh		= 0,

	/* External Switch Configuration */
	.pSwitchInfo = NULL,
	.switchInfoNum = 0,

	/* NAND init params */
	.nandFlashReadParams		= DB_DX_AC3_BOARD_NAND_READ_PARAMS,
	.nandFlashWriteParams		= DB_DX_AC3_BOARD_NAND_WRITE_PARAMS,
	.nandFlashControl		= DB_DX_AC3_BOARD_NAND_CONTROL,
	/* NOR init params */
	.norFlashReadParams		= DB_DX_AC3_BOARD_NOR_READ_PARAMS,
	.norFlashWriteParams		= DB_DX_AC3_BOARD_NOR_WRITE_PARAMS,
	.configAutoDetect		= MV_TRUE,	/* Enable modules auto-detection. */
	.modelName			= "AlleyCat3 Reference Design Board",
	.isSmiExternalPp		= MV_FALSE
};
/*********************************************************************************/
/***********************************/
/* ALLEYCAT3-RD-MTL-2XXG-2XG BOARD */
/***********************************/
MV_BOARD_MPP_INFO rd_mtl_2xxg_2xg_ac3InfoBoardMppConfigValue[] = {
	{ {
	RD_MTL_4XG_AC3_MPP0_7,
	RD_MTL_4XG_AC3_MPP8_15,
	RD_MTL_4XG_AC3_MPP16_23,
	RD_MTL_4XG_AC3_MPP24_31,
	RD_MTL_4XG_AC3_MPP32_39,
	} },
};

MV_BOARD_INFO rd_mtl_2xxg_2xg_ac3Info = {
	.boardName			= "RD-XC3-48G2XG2XXG-A",
	.numBoardMppTypeValue		= ARRSZ(db_dx_ac3InfoBoardModTypeInfo),
	.pBoardModTypeValue		= db_dx_ac3InfoBoardModTypeInfo,
	.numBoardMppConfigValue		= ARRSZ(rd_mtl_2xxg_2xg_ac3InfoBoardMppConfigValue),
	.pBoardMppConfigValue		= rd_mtl_2xxg_2xg_ac3InfoBoardMppConfigValue,
	.intsGppMaskLow			= 0,
	.intsGppMaskMid			= 0,
	.intsGppMaskHigh		= 0,
	.numBoardDeviceIf		= ARRSZ(db_dx_ac3InfoBoardDeCsInfo),
	.pDevCsInfo				= db_dx_ac3InfoBoardDeCsInfo,
	.numBoardTwsiDev		= ARRSZ(db_dx_ac3InfoBoardTwsiDev),
	.pBoardTwsiDev			= db_dx_ac3InfoBoardTwsiDev,
	.numBoardMacInfo		= ARRSZ(db_dx_ac3InfoBoardMacInfo),
	.pBoardMacInfo			= db_dx_ac3InfoBoardMacInfo,
	.numBoardGppInfo		= 0,
	.pBoardGppInfo			= NULL,
	.activeLedsNumber		= 0,
	.pLedGppPin				= NULL,
	.ledsPolarity			= 0,

	/* GPP values */
	.gppOutEnValLow			= RD_MTL_4XG_AC3_GPP_OUT_ENA_LOW,
	.gppOutEnValMid			= RD_MTL_4XG_AC3_GPP_OUT_ENA_MID,
	.gppOutEnValHigh		= 0,
	.gppOutValLow			= RD_MTL_4XG_AC3_GPP_OUT_VAL_LOW,
	.gppOutValMid			= RD_MTL_4XG_AC3_GPP_OUT_VAL_MID,
	.gppOutValHigh			= 0,
	.gppPolarityValLow		= RD_MTL_4XG_AC3_GPP_POL_LOW,
	.gppPolarityValMid		= RD_MTL_4XG_AC3_GPP_POL_MID,
	.gppPolarityValHigh		= 0,

	/* External Switch Configuration */
	.pSwitchInfo = NULL,
	.switchInfoNum = 0,

	/* NAND init params */
	.nandFlashReadParams		= DB_DX_AC3_BOARD_NAND_READ_PARAMS,
	.nandFlashWriteParams		= DB_DX_AC3_BOARD_NAND_WRITE_PARAMS,
	.nandFlashControl		= DB_DX_AC3_BOARD_NAND_CONTROL,
	/* NOR init params */
	.norFlashReadParams		= DB_DX_AC3_BOARD_NOR_READ_PARAMS,
	.norFlashWriteParams		= DB_DX_AC3_BOARD_NOR_WRITE_PARAMS,
	.configAutoDetect		= MV_TRUE,	/* Enable modules auto-detection. */
	.modelName			= "AlleyCat3 Reference Design Board",
	.isSmiExternalPp		= MV_FALSE
};

/*********************************************************************************/
/***********************************/
/* ALLEYCAT3-RD-MTL-2XXG-2XG BOARD */
/***********************************/
MV_BOARD_MPP_INFO db_misl_24G_46_ac3InfoBoardMppConfigValue[] = {
	{ {
	DB_MISL_24G46_AC3_MPP0_7,
	DB_MISL_24G46_AC3_MPP8_15,
	DB_MISL_24G46_AC3_MPP16_23,
	DB_MISL_24G46_AC3_MPP24_31,
	DB_MISL_24G46_AC3_MPP32_39,
	} },
};

MV_BOARD_INFO db_misl_24G_4xg_ac3Info = {
	.boardName			= "DB-XC3-24G-4G",
	.numBoardMppTypeValue		= ARRSZ(db_dx_ac3InfoBoardModTypeInfo),
	.pBoardModTypeValue		= db_dx_ac3InfoBoardModTypeInfo,
	.numBoardMppConfigValue		= ARRSZ(db_misl_24G_46_ac3InfoBoardMppConfigValue),
	.pBoardMppConfigValue		= db_misl_24G_46_ac3InfoBoardMppConfigValue,
	.intsGppMaskLow			= 0,
	.intsGppMaskMid			= 0,
	.intsGppMaskHigh		= 0,
	.numBoardDeviceIf		= ARRSZ(db_dx_ac3InfoBoardDeCsInfo),
	.pDevCsInfo				= db_dx_ac3InfoBoardDeCsInfo,
	.numBoardTwsiDev		= ARRSZ(db_dx_ac3InfoBoardTwsiDev),
	.pBoardTwsiDev			= db_dx_ac3InfoBoardTwsiDev,
	.numBoardMacInfo		= ARRSZ(db_dx_ac3InfoBoardMacInfo),
	.pBoardMacInfo			= db_dx_ac3InfoBoardMacInfo,
	.numBoardGppInfo		= 0,
	.pBoardGppInfo			= NULL,
	.activeLedsNumber		= 0,
	.pLedGppPin				= NULL,
	.ledsPolarity			= 0,

	/* GPP values */
	.gppOutEnValLow			= DB_MISL_24G46_AC3_GPP_OUT_ENA_LOW,
	.gppOutEnValMid			= DB_MISL_24G46_AC3_GPP_OUT_ENA_MID,
	.gppOutEnValHigh		= 0,
	.gppOutValLow			= DB_MISL_24G46_AC3_GPP_OUT_VAL_LOW,
	.gppOutValMid			= DB_MISL_24G46_AC3_GPP_OUT_VAL_MID,
	.gppOutValHigh			= 0,
	.gppPolarityValLow		= DB_MISL_24G46_AC3_GPP_POL_LOW,
	.gppPolarityValMid		= DB_MISL_24G46_AC3_GPP_POL_MID,
	.gppPolarityValHigh		= 0,

	/* External Switch Configuration */
	.pSwitchInfo = NULL,
	.switchInfoNum = 0,

	/* NAND init params */
	.nandFlashReadParams		= DB_DX_AC3_BOARD_NAND_READ_PARAMS,
	.nandFlashWriteParams		= DB_DX_AC3_BOARD_NAND_WRITE_PARAMS,
	.nandFlashControl			= DB_DX_AC3_BOARD_NAND_CONTROL,
	/* NOR init params */
	.norFlashReadParams			= DB_DX_AC3_BOARD_NOR_READ_PARAMS,
	.norFlashWriteParams		= DB_DX_AC3_BOARD_NOR_WRITE_PARAMS,
	.configAutoDetect		= MV_TRUE,	/* Enable modules auto-detection. */
	.modelName			= "AlleyCat3 Reference Design Board",
	.isSmiExternalPp		= MV_FALSE
};

/*********************************************************************************/
/***********************************/
/* ALLEYCAT3-RD-MTL-24G BOARD     */
/***********************************/
MV_BOARD_MPP_INFO rd_mtl_24G_ac3InfoBoardMppConfigValue[] = {
	{ {
	RD_MTL_24G_AC3_MPP0_7,
	RD_MTL_24G_AC3_MPP8_15,
	RD_MTL_24G_AC3_MPP16_23,
	RD_MTL_24G_AC3_MPP24_31,
	RD_MTL_24G_AC3_MPP32_39,
	} },
};

MV_BOARD_INFO rd_mtl_24G_ac3Info = {
	.boardName				= "RD-XC3-24G-4SFP",
	.numBoardMppTypeValue	= ARRSZ(db_dx_ac3InfoBoardModTypeInfo),
	.pBoardModTypeValue		= db_dx_ac3InfoBoardModTypeInfo,
	.numBoardMppConfigValue	= ARRSZ(rd_mtl_24G_ac3InfoBoardMppConfigValue),
	.pBoardMppConfigValue	= rd_mtl_24G_ac3InfoBoardMppConfigValue,
	.intsGppMaskLow			= 0,
	.intsGppMaskMid			= 0,
	.intsGppMaskHigh		= 0,
	.numBoardDeviceIf		= ARRSZ(db_dx_ac3InfoBoardDeCsInfo),
	.pDevCsInfo				= db_dx_ac3InfoBoardDeCsInfo,
	.numBoardTwsiDev		= ARRSZ(db_dx_ac3InfoBoardTwsiDev),
	.pBoardTwsiDev			= db_dx_ac3InfoBoardTwsiDev,
	.numBoardMacInfo		= ARRSZ(db_dx_ac3InfoBoardMacInfo),
	.pBoardMacInfo			= db_dx_ac3InfoBoardMacInfo,
	.numBoardGppInfo		= 0,
	.pBoardGppInfo			= NULL,
	.activeLedsNumber		= 0,
	.pLedGppPin				= NULL,
	.ledsPolarity			= 0,

	/* GPP values */
	.gppOutEnValLow			= RD_MTL_24G_AC3_GPP_OUT_ENA_LOW,
	.gppOutEnValMid			= RD_MTL_24G_AC3_GPP_OUT_ENA_MID,
	.gppOutEnValHigh		= 0,
	.gppOutValLow			= RD_MTL_24G_AC3_GPP_OUT_VAL_LOW,
	.gppOutValMid			= RD_MTL_24G_AC3_GPP_OUT_VAL_MID,
	.gppOutValHigh			= 0,
	.gppPolarityValLow		= RD_MTL_24G_AC3_GPP_POL_LOW,
	.gppPolarityValMid		= RD_MTL_24G_AC3_GPP_POL_MID,
	.gppPolarityValHigh		= 0,

	/* External Switch Configuration */
	.pSwitchInfo = NULL,
	.switchInfoNum = 0,

	/* NAND init params */
	.nandFlashReadParams		= DB_DX_AC3_BOARD_NAND_READ_PARAMS,
	.nandFlashWriteParams		= DB_DX_AC3_BOARD_NAND_WRITE_PARAMS,
	.nandFlashControl		= DB_DX_AC3_BOARD_NAND_CONTROL,
	/* NOR init params */
	.norFlashReadParams		= DB_DX_AC3_BOARD_NOR_READ_PARAMS,
	.norFlashWriteParams		= DB_DX_AC3_BOARD_NOR_WRITE_PARAMS,
	.configAutoDetect		= MV_TRUE,	/* Enable modules auto-detection. */
	.modelName			= "AlleyCat3 Reference Design Board",
	.isSmiExternalPp		= MV_FALSE
};

/***************************************************************************************/
/* ARMADA-XP AMC BOARD -  only for Linux usage (AXP family is shared with MSYS in LSP) */
/***************************************************************************************/
#define DB_78X60_AMC_BOARD_NAND_READ_PARAMS		0x000C0282
#define DB_78X60_AMC_BOARD_NAND_WRITE_PARAMS		0x00010305
/*NAND care support for small page chips*/
#define DB_78X60_AMC_BOARD_NAND_CONTROL			0x01c00543

MV_U8	db78X60amcInfoBoardDebugLedIf[] = {53, 54, 55, 56}; /* 7 segment MPPs*/

MV_BOARD_TWSI_INFO	db78X60amcInfoBoardTwsiDev[] = {
	/* No TWSI devices on board*/
};

MV_BOARD_MAC_INFO db78X60amcInfoBoardMacInfo[] = {
	/* {{MV_BOARD_MAC_SPEED	boardMacSpeed, MV_U8 boardEthSmiAddr}} */
	{BOARD_MAC_SPEED_AUTO, 0x1, 0x0, MV_TRUE},
	{BOARD_MAC_SPEED_AUTO, 0xD, 0x0, MV_TRUE},
	{BOARD_MAC_SPEED_AUTO, 0xC, 0x0, MV_TRUE},
	{BOARD_MAC_SPEED_AUTO, 0x0, 0x0, MV_TRUE}
};


MV_BOARD_MODULE_TYPE_INFO db78X60amcInfoBoardModTypeInfo[] = {
	/* No Modules */
};

MV_BOARD_GPP_INFO db78X60amcInfoBoardGppInfo[] = {
	/* {{MV_BOARD_GPP_CLASS	devClass, MV_U8	gppPinNum}} */
	{BOARD_GPP_USB_VBUS,    46} /* from MPP map */
};

MV_DEV_CS_INFO db78X60amcInfoBoardDeCsInfo[] = {
	/*{deviceCS, params, devType, devWidth}*/
#if defined(MV_INCLUDE_SPI)
	{SPI_CS0_AXP, N_A, BOARD_DEV_SPI_FLASH, 8, 8, 0, MV_TRUE}, /* SPI DEV */
#endif
#if defined(MV_INCLUDE_NAND)
	{DEVICE_CS0, N_A, BOARD_DEV_NAND_FLASH, 8, 8, 0, MV_TRUE} /* NAND DEV */
#endif
};

MV_BOARD_MPP_INFO db78X60amcInfoBoardMppConfigValue[] = {
	{ {
		DB_78X60_AMC_MPP0_7,
		DB_78X60_AMC_MPP8_15,
		DB_78X60_AMC_MPP16_23,
		DB_78X60_AMC_MPP24_31,
		DB_78X60_AMC_MPP32_39,
		DB_78X60_AMC_MPP40_47,
		DB_78X60_AMC_MPP48_55,
		DB_78X60_AMC_MPP56_63,
		DB_78X60_AMC_MPP64_67,
	} }
};

MV_BOARD_INFO db78X60amcInfo = {
	.boardName			= "DB-78460-AMC",
	.numBoardMppTypeValue		= ARRSZ(db78X60amcInfoBoardModTypeInfo),
	.pBoardModTypeValue		= db78X60amcInfoBoardModTypeInfo,
	.numBoardMppConfigValue		= ARRSZ(db78X60amcInfoBoardMppConfigValue),
	.pBoardMppConfigValue		= db78X60amcInfoBoardMppConfigValue,
	.intsGppMaskLow			= 0,
	.intsGppMaskMid			= 0,
	.intsGppMaskHigh		= 0,
	.numBoardDeviceIf		= ARRSZ(db78X60amcInfoBoardDeCsInfo),
	.pDevCsInfo			= db78X60amcInfoBoardDeCsInfo,
	.numBoardTwsiDev		= ARRSZ(db78X60amcInfoBoardTwsiDev),
	.pBoardTwsiDev			= db78X60amcInfoBoardTwsiDev,
	.numBoardMacInfo		= ARRSZ(db78X60amcInfoBoardMacInfo),
	.pBoardMacInfo			= db78X60amcInfoBoardMacInfo,
	.numBoardGppInfo		= ARRSZ(db78X60amcInfoBoardGppInfo),
	.pBoardGppInfo			= db78X60amcInfoBoardGppInfo,
	.activeLedsNumber		= ARRSZ(db78X60amcInfoBoardDebugLedIf),
	.pLedGppPin			= db78X60amcInfoBoardDebugLedIf,
	.ledsPolarity			= 0,

	/* GPP values */
	.gppOutEnValLow			= DB_78X60_AMC_GPP_OUT_ENA_LOW,
	.gppOutEnValMid			= DB_78X60_AMC_GPP_OUT_ENA_MID,
	.gppOutEnValHigh		= DB_78X60_AMC_GPP_OUT_ENA_HIGH,
	.gppOutValLow			= DB_78X60_AMC_GPP_OUT_VAL_LOW,
	.gppOutValMid			= DB_78X60_AMC_GPP_OUT_VAL_MID,
	.gppOutValHigh			= DB_78X60_AMC_GPP_OUT_VAL_HIGH,
	.gppPolarityValLow		= DB_78X60_AMC_GPP_POL_LOW,
	.gppPolarityValMid		= DB_78X60_AMC_GPP_POL_MID,
	.gppPolarityValHigh		= DB_78X60_AMC_GPP_POL_HIGH,

	/* External Switch Configuration */
	.pSwitchInfo = NULL,
	.switchInfoNum = 0,

	/* NAND init params */
	.nandFlashReadParams		= DB_78X60_AMC_BOARD_NAND_READ_PARAMS,
	.nandFlashWriteParams		= DB_78X60_AMC_BOARD_NAND_WRITE_PARAMS,
	.nandFlashControl		= DB_78X60_AMC_BOARD_NAND_CONTROL,
	.configAutoDetect		= MV_TRUE,	/* Enable modules auto-detection. */
	.modelName			= "AMC Development Board"
};


/*********************************************************************************/

MV_BOARD_INFO *marvellBC2BoardInfoTbl[] = {
	&db_dx_bc2Info,
	&rd_dx_bc2Info,
	&bc2_rd_mtlInfo
};

MV_BOARD_INFO *marvellBOBKBoardInfoTbl[] = {
	&db_dx_bobkCetusInfo,
	&db_dx_bobkCaelumInfo,
	&rd_dx_bobkLewisInfo,
	&rd_dx_bobkCygnusInfo
};

MV_BOARD_INFO *marvellAC3BoardInfoTbl[] = {
	&db_dx_ac3Info,
	&rd_mtl_4xg_ac3Info,
	&rd_mtl_2xxg_2xg_ac3Info,
	&db_misl_24G_4xg_ac3Info,
	&rd_mtl_24G_ac3Info
};

/* only for Linux usage (AXP family is shared with MSYS in LSP) */
MV_BOARD_INFO *marvellAXPboardInfoTbl[] = {
	&db78X60amcInfo
};
