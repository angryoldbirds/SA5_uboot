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


#ifndef __INCmvBoardEnvSpech
#define __INCmvBoardEnvSpech

#include "mvSysHwConfig.h"


/* Board specific ID configuration */
/* ============================ */
/* Bobcat2 Customer Boards */
#define BC2_CUSTOMER_BOARD_ID_BASE	0x0
#define BC2_CUSTOMER_BOARD_ID0		(BC2_CUSTOMER_BOARD_ID_BASE + 0)
#define BC2_CUSTOMER_BOARD_ID1		(BC2_CUSTOMER_BOARD_ID_BASE + 1)
#define BC2_CUSTOMER_MAX_BOARD_ID	(BC2_CUSTOMER_BOARD_ID_BASE + 2)
#define BC2_CUSTOMER_BOARD_NUM		(BC2_CUSTOMER_MAX_BOARD_ID - BC2_CUSTOMER_BOARD_ID_BASE)

/* Bobcat2 Marvell boards */
#define BC2_MARVELL_BOARD_ID_BASE	0x10
#define DB_DX_BC2_ID			(BC2_MARVELL_BOARD_ID_BASE + 0)
#define RD_DX_BC2_ID			(BC2_MARVELL_BOARD_ID_BASE + 1)
#define RD_MTL_BC2			(BC2_MARVELL_BOARD_ID_BASE + 2)
#define BC2_MARVELL_MAX_BOARD_ID	(BC2_MARVELL_BOARD_ID_BASE + 3)
#define BC2_MARVELL_BOARD_NUM		(BC2_MARVELL_MAX_BOARD_ID - BC2_MARVELL_BOARD_ID_BASE)


/* AlleyCat3 Customer Boards */
#define AC3_CUSTOMER_BOARD_ID_BASE	0x20
#define AC3_CUSTOMER_BOARD_ID0		(AC3_CUSTOMER_BOARD_ID_BASE + 0)
#define AC3_CUSTOMER_BOARD_ID1		(AC3_CUSTOMER_BOARD_ID_BASE + 1)
#define AC3_CUSTOMER_MAX_BOARD_ID	(AC3_CUSTOMER_BOARD_ID_BASE + 2)
#define AC3_CUSTOMER_BOARD_NUM		(AC3_CUSTOMER_MAX_BOARD_ID - AC3_CUSTOMER_BOARD_ID_BASE)

/* AlleyCat3 Marvell boards */
#define AC3_MARVELL_BOARD_ID_BASE	0x30
#define DB_AC3_ID			(AC3_MARVELL_BOARD_ID_BASE + 0)
#define RD_MTL_4XG_AC3_ID		(AC3_MARVELL_BOARD_ID_BASE + 1)
#define RD_MTL_2XXG_2XG_AC3_ID		(AC3_MARVELL_BOARD_ID_BASE + 2)
#define DB_MISL_24G4G_AC3_ID		(AC3_MARVELL_BOARD_ID_BASE + 3)
#define RD_MTL_24G_AC3_ID		(AC3_MARVELL_BOARD_ID_BASE + 4)
#define AC3_MARVELL_MAX_BOARD_ID	(AC3_MARVELL_BOARD_ID_BASE + 5)
#define AC3_MARVELL_BOARD_NUM		(AC3_MARVELL_MAX_BOARD_ID - AC3_MARVELL_BOARD_ID_BASE)

/* BobK Customer Boards */
#define BOBK_CUSTOMER_BOARD_ID_BASE	0x40
#define BOBK_CETUS_CUSTOMER_BOARD_ID0		(BOBK_CUSTOMER_BOARD_ID_BASE + 0)
#define BOBK_CAELUM_CUSTOMER_BOARD_ID1		(BOBK_CUSTOMER_BOARD_ID_BASE + 1)
#define BOBK_CUSTOMER_MAX_BOARD_ID			(BOBK_CUSTOMER_BOARD_ID_BASE + 2)
#define BOBK_CUSTOMER_BOARD_NUM			(BOBK_CUSTOMER_MAX_BOARD_ID - BOBK_CUSTOMER_BOARD_ID_BASE)

/* BobK Marvell Boards */
#define BOBK_MARVELL_BOARD_ID_BASE	0x50
#define BOBK_CETUS_DB_ID			(BOBK_MARVELL_BOARD_ID_BASE + 0)
#define BOBK_CAELUM_DB_ID			(BOBK_MARVELL_BOARD_ID_BASE + 1)
#define BOBK_LEWIS_RD_ID			(BOBK_MARVELL_BOARD_ID_BASE + 2)
#define BOBK_CYGNUS_RD_ID			(BOBK_MARVELL_BOARD_ID_BASE + 3)
#define BOBK_MARVELL_MAX_BOARD_ID		(BOBK_MARVELL_BOARD_ID_BASE + 4)
#define BOBK_MARVELL_BOARD_NUM		(BOBK_MARVELL_MAX_BOARD_ID - BOBK_MARVELL_BOARD_ID_BASE)

/* AXP-AMC board: for Linux 2.6/3.4 usage only (AXP family is shared with MSYS in LSP) */
#define DB_78X60_AMC_ID			0x6

#define INVALID_BOARD_ID		0xFFFF
#define BOARD_ID_INDEX_MASK		0x10	/* Mask used to return board index via board Id */
#define RD_MTL_BC2_PCB_ID		0x70

#if defined CONFIG_ALLEYCAT3
	#define MARVELL_BOARD_ID_BASE		AC3_MARVELL_BOARD_ID_BASE
	#define MV_MAX_MARVELL_BOARD_ID		AC3_MARVELL_MAX_BOARD_ID
	#define MV_MARVELL_BOARD_NUM		AC3_MARVELL_BOARD_NUM
	#define MV_DEFAULT_BOARD_ID		DB_AC3_ID
#elif defined CONFIG_BOBCAT2
	#define MARVELL_BOARD_ID_BASE		BC2_MARVELL_BOARD_ID_BASE
	#define MV_MAX_MARVELL_BOARD_ID		BC2_MARVELL_MAX_BOARD_ID
	#define MV_MARVELL_BOARD_NUM		BC2_MARVELL_BOARD_NUM
	#define MV_DEFAULT_BOARD_ID		DB_DX_BC2_ID
#else
	#define MARVELL_BOARD_ID_BASE		BOBK_MARVELL_BOARD_ID_BASE
	#define MV_MAX_MARVELL_BOARD_ID		BOBK_MARVELL_MAX_BOARD_ID
	#define MV_MARVELL_BOARD_NUM		BOBK_MARVELL_BOARD_NUM
	#define MV_DEFAULT_BOARD_ID		BOBK_CETUS_DB_ID
#endif

/********************************************
*		Bobcat2 Boards
*********************************************/
/*******************************************************************************
* Bobcat2 Customer board - Based on DB_DX_BC2
*******************************************************************************/

#define BOBCAT2_CUSTOMER_0_MPP0_7		0x22242222
#define BOBCAT2_CUSTOMER_0_MPP8_15		0x11122222
#define BOBCAT2_CUSTOMER_0_MPP16_23		0x44444044
#define BOBCAT2_CUSTOMER_0_MPP24_31		0x14444444
#define BOBCAT2_CUSTOMER_0_MPP32_39		0x00000001

#define BOBCAT2_CUSTOMER_0_GPP_OUT_ENA_LOW	(~(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12\
						 | BIT13 | BIT16 | BIT17 | BIT20 | BIT29  | BIT30))
#define BOBCAT2_CUSTOMER_0_GPP_OUT_ENA_MID	(~(0))

#define BOBCAT2_CUSTOMER_0_GPP_OUT_VAL_LOW	(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12\
						| BIT13 | BIT16 | BIT17 | BIT20 | BIT29  | BIT30)
#define BOBCAT2_CUSTOMER_0_GPP_OUT_VAL_MID	0x0

#define BOBCAT2_CUSTOMER_0_GPP_POL_LOW		0x0
#define BOBCAT2_CUSTOMER_0_GPP_POL_MID		0x0

/******************/
/*   RD_DX_BC2    */
/******************/
#define DB_DX_BC2_MPP0_7	0x22242222
#define DB_DX_BC2_MPP8_15	0x11122222
#define DB_DX_BC2_MPP16_23	0x44444044
#define DB_DX_BC2_MPP24_31	0x14444444
#define DB_DX_BC2_MPP32_39	0x00000001

#define DB_DX_BC2_NOR_MPP0_7	0x44444444
#define DB_DX_BC2_NOR_MPP8_15	0x11122244

/* GPPs
MPP#	NAME			IN/OUT
----------------------------------------------
0	SPI_MOSI		(out)
1	SPI_MISO		(in)
2	SPI_SCK			(out)
3	SPI_CS0n		(out)
4	DEV_CSn[0]		(out) NF CS (Boot)
5	SD_CMD			(in/out)
6	SD_CLK			(out)
7	SD_D[0]			(in/out)
8	SD_D[1]			(in/out)
9	SD_D[2]			(in/out)
10	SD_D[3]			(in/out)
11	UART1_RXD		(in)
12	UART1_TXD		(out)
13	INTERRUPT_OUTn		(out)
14	I2C_SCL			(in/out)
15	I2C_SDA			(in/out)

16	DEV_Oen_NF_Ren		(out)
17	DEV_CLK_OUT		(out) Test point
18	GPIO[18]		(in/out) INT_in / SD_WP / VC2_GPP
19	NF_RBn			(in)
20	DEV_WEn[0]		(out)
21	DEV_AD[0]		(in/out)
22	DEV_AD[1]		(in/out)
23	DEV_AD[2]		(in/out)
24	DEV_AD[3]		(in/out)
25	DEV_AD[4]		(in/out)
26	DEV_AD[5]		(in/out)
27	DEV_AD[6]		(in/out)
28	DEV_AD[7]		(in/out)
29	NF_CLE_DEV_A[0]		(out)
30	NF_ALE_DEV_A[1]		(out)
31	SLV_SMI_MDC		(in)
32	SLV_SMI_MDIO		(in/out)

*/
#define DB_DX_BC2_GPP_OUT_ENA_LOW	(~(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12\
					| BIT13 | BIT16 | BIT17 | BIT20 | BIT29  | BIT30))
#define DB_DX_BC2_GPP_OUT_ENA_MID	(~(0))

#define DB_DX_BC2_GPP_OUT_VAL_LOW	(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12\
					| BIT13 | BIT16 | BIT17 | BIT20 | BIT29  | BIT30)
#define DB_DX_BC2_GPP_OUT_VAL_MID	0x0

#define DB_DX_BC2_GPP_POL_LOW		0x0
#define DB_DX_BC2_GPP_POL_MID		0x0

/*******************/
/* RD_DX_BC2 */
/*******************/
#define RD_DX_BC2_MPP0_7		0x22242222
#define RD_DX_BC2_MPP8_15		0x11022222
#define RD_DX_BC2_MPP16_23		0x44444044
#define RD_DX_BC2_MPP24_31		0x34444444
#define RD_DX_BC2_MPP32_39		0x00000003

/* GPPs
MPP#	NAME		IN/OUT
----------------------------------------------
0	SPI_MOSI	(out)
1	SPI_MISO	(in)
2	SPI_SCK		(out)
3	SPI_CS0n	(out)
4	DEV_CSn[0]	(out)
5	SD_CMD		(in/out)
6	SD_CLK		(out)
7	SD_D[0]		(in/out)
8	SD_D[1]		(in/out)
9	SD_D[2]		(in/out)
10	SD_D[3]		(in/out)
11	UART1_RXD	(in)
12	UART1_TXD	(out)
13	GPIO[13]	(in/out)
14	I2C_SCL		(in/out)
15	I2C_SDA		(in/out)

16	DEV_Oen_NF_Ren	(out)
17	GPIO[17]	(in/out)
18	GPIO[18]	(in/out)
19	GPIO[19]	(in/out)
20	DEV_WEn[0]	(out)
21	DEV_AD[0]	(in/out)
22	DEV_AD[1]	(in/out)
23	DEV_AD[2]	(in/out)
24	DEV_AD[3]	(in/out)
25	DEV_AD[4]	(in/out)
26	DEV_AD[5]	(in/out)
27	DEV_AD[6]	(in/out)
28	DEV_AD[7]	(in/out)
29	NF_CLE_DEV_A[0] (out)
30	NF_ALE_DEV_A[1] (out)
31	MST_SMI_MDC	(out)
32	MST_SMI_MDIO	(in/out)
*/

#define RD_DX_BC2_GPP_OUT_ENA_LOW	(~(BIT1 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12\
					| BIT16 | BIT20 | BIT29 | BIT30 | BIT31))
#define RD_DX_BC2_GPP_OUT_ENA_MID	(~(0))

#define RD_DX_BC2_GPP_OUT_VAL_LOW	(BIT1 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12\
					| BIT16 | BIT20 | BIT29 | BIT30 | BIT31)
#define RD_DX_BC2_GPP_OUT_VAL_MID	(0)

#define RD_DX_BC2_GPP_POL_LOW		0x0
#define RD_DX_BC2_GPP_POL_MID		0x0

/*******************/
/* RD_MTL_BC2 */
/*******************/
#define RD_MTL_BC2_MPP0_7		0x22242222
#define RD_MTL_BC2_MPP8_15		0x11022222
#define RD_MTL_BC2_MPP16_23		0x44444044
#define RD_MTL_BC2_MPP24_31		0x34444444
#define RD_MTL_BC2_MPP32_39		0x00000003

#define RD_MTL_BC2_GPP_OUT_ENA_LOW	(~(BIT1 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12\
					| BIT16 | BIT20 | BIT29 | BIT30 | BIT31))
#define RD_MTL_BC2_GPP_OUT_ENA_MID		(~(0))

#define RD_MTL_BC2_GPP_OUT_VAL_LOW	(BIT1 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12\
					| BIT16 | BIT20 | BIT29 | BIT30 | BIT31)
#define RD_MTL_BC2_GPP_OUT_VAL_MID	(0)

#define RD_MTL_BC2_GPP_POL_LOW		0x0
#define RD_MTL_BC2_GPP_POL_MID		0x0

/********************************************
*		Bobk Boards
*********************************************/
/*******************************************************************************
* BobK Cetus Customer board - Based on BOBK-CETUS-DB-98DX4235-12XG
*******************************************************************************/

#define BOBK_CETUS_CUSTOMER_0_MPP0_7		0x22242222
#define BOBK_CETUS_CUSTOMER_0_MPP8_15		0x11122222
#define BOBK_CETUS_CUSTOMER_0_MPP16_23		0x44444044
#define BOBK_CETUS_CUSTOMER_0_MPP24_31		0x14444444
#define BOBK_CETUS_CUSTOMER_0_MPP32_39		0x00000001

#define BOBK_CETUS_CUSTOMER_0_GPP_OUT_ENA_LOW	(~(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12\
							 | BIT13 | BIT16 | BIT17 | BIT20 | BIT29  | BIT30))
#define BOBK_CETUS_CUSTOMER_0_GPP_OUT_ENA_MID	(~(0))

#define BOBK_CETUS_CUSTOMER_0_GPP_OUT_VAL_LOW	(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12\
							| BIT13 | BIT16 | BIT17 | BIT20 | BIT29  | BIT30)
#define BOBK_CETUS_CUSTOMER_0_GPP_OUT_VAL_MID	0x0

#define BOBK_CETUS_CUSTOMER_0_GPP_POL_LOW		0x0
#define BOBK_CETUS_CUSTOMER_0_GPP_POL_MID		0x0

/*******************************************************************************
* BobK Caelum Customer board - Based on BOBK-CAELUM-DB-98DX4203-48G12XG
*******************************************************************************/

#define BOBK_CAELUM_CUSTOMER_1_MPP0_7		0x22242222
#define BOBK_CAELUM_CUSTOMER_1_MPP8_15		0x11122222
#define BOBK_CAELUM_CUSTOMER_1_MPP16_23		0x44444044
#define BOBK_CAELUM_CUSTOMER_1_MPP24_31		0x14444444
#define BOBK_CAELUM_CUSTOMER_1_MPP32_39		0x00000001

#define BOBK_CAELUM_CUSTOMER_1_GPP_OUT_ENA_LOW	(~(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12\
							 | BIT13 | BIT16 | BIT17 | BIT20 | BIT29  | BIT30))
#define BOBK_CAELUM_CUSTOMER_1_GPP_OUT_ENA_MID	(~(0))

#define BOBK_CAELUM_CUSTOMER_1_GPP_OUT_VAL_LOW	(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12\
							| BIT13 | BIT16 | BIT17 | BIT20 | BIT29  | BIT30)
#define BOBK_CAELUM_CUSTOMER_1_GPP_OUT_VAL_MID	0x0

#define BOBK_CAELUM_CUSTOMER_1_GPP_POL_LOW		0x0
#define BOBK_CAELUM_CUSTOMER_1_GPP_POL_MID		0x0


/************************************/
/*   BOBK-CETUS-DB-98DX4235-12XG    */
/************************************/
#define DB_DX_BOBK_CETUS_MPP0_7	0x22242222
#define DB_DX_BOBK_CETUS_MPP8_15	0x11122222
#define DB_DX_BOBK_CETUS_MPP16_23	0x44444044
#define DB_DX_BOBK_CETUS_MPP24_31	0x14444444
#define DB_DX_BOBK_CETUS_MPP32_39	0x00000001

#define DB_DX_BOBK_CETUS_NOR_MPP0_7	0x44444444
#define DB_DX_BOBK_CETUS_NOR_MPP8_15	0x11122244

/* GPPs
MPP#	NAME			IN/OUT
----------------------------------------------
0	SPI_MOSI		(out)
1	SPI_MISO		(in)
2	SPI_SCK			(out)
3	SPI_CS0n		(out)
4	DEV_CSn[0]		(out) NF CS (Boot)
5	SD_CMD			(in/out)
6	SD_CLK			(out)
7	SD_D[0]			(in/out)
8	SD_D[1]			(in/out)
9	SD_D[2]			(in/out)
10	SD_D[3]			(in/out)
11	UART1_RXD		(in)
12	UART1_TXD		(out)
13	INTERRUPT_OUTn		(out)
14	I2C_SCL			(in/out)
15	I2C_SDA			(in/out)

16	DEV_Oen_NF_Ren		(out)
17	DEV_CLK_OUT		(out) Test point
18	GPIO[18]		(in/out) INT_in / SD_WP / VC2_GPP
19	NF_RBn			(in)
20	DEV_WEn[0]		(out)
21	DEV_AD[0]		(in/out)
22	DEV_AD[1]		(in/out)
23	DEV_AD[2]		(in/out)
24	DEV_AD[3]		(in/out)
25	DEV_AD[4]		(in/out)
26	DEV_AD[5]		(in/out)
27	DEV_AD[6]		(in/out)
28	DEV_AD[7]		(in/out)
29	NF_CLE_DEV_A[0]		(out)
30	NF_ALE_DEV_A[1]		(out)
31	SLV_SMI_MDC		(in)
32	SLV_SMI_MDIO		(in/out)

*/
#define DB_DX_BOBK_CETUS_GPP_OUT_ENA_LOW	(~(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12\
					| BIT13 | BIT16 | BIT17 | BIT20 | BIT29  | BIT30))
#define DB_DX_BOBK_CETUS_GPP_OUT_ENA_MID	(~(0))

#define DB_DX_BOBK_CETUS_GPP_OUT_VAL_LOW	(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12\
					| BIT13 | BIT16 | BIT17 | BIT20 | BIT29  | BIT30)
#define DB_DX_BOBK_CETUS_GPP_OUT_VAL_MID	0x0

#define DB_DX_BOBK_CETUS_GPP_POL_LOW		0x0
#define DB_DX_BOBK_CETUS_GPP_POL_MID		0x0

/*************************************/
/*   BOBK-CAELUM-DB-98DX4203-48G12XG    */
/*************************************/
#define DB_DX_BOBK_CAELUM_MPP0_7	0x22242222
#define DB_DX_BOBK_CAELUM_MPP8_15	0x11122222
#define DB_DX_BOBK_CAELUM_MPP16_23	0x44444044
#define DB_DX_BOBK_CAELUM_MPP24_31	0x14444444
#define DB_DX_BOBK_CAELUM_MPP32_39	0x00000001

#define DB_DX_BOBK_CAELUM_NOR_MPP0_7	0x44444444
#define DB_DX_BOBK_CAELUM_NOR_MPP8_15	0x11122244

/* GPPs
MPP#	NAME			IN/OUT
----------------------------------------------
0	SPI_MOSI		(out)
1	SPI_MISO		(in)
2	SPI_SCK			(out)
3	SPI_CS0n		(out)
4	DEV_CSn[0]		(out) NF CS (Boot)
5	SD_CMD			(in/out)
6	SD_CLK			(out)
7	SD_D[0]			(in/out)
8	SD_D[1]			(in/out)
9	SD_D[2]			(in/out)
10	SD_D[3]			(in/out)
11	UART1_RXD		(in)
12	UART1_TXD		(out)
13	INTERRUPT_OUTn		(out)
14	I2C_SCL			(in/out)
15	I2C_SDA			(in/out)

16	DEV_Oen_NF_Ren		(out)
17	DEV_CLK_OUT		(out) Test point
18	GPIO[18]		(in/out) INT_in / SD_WP / VC2_GPP
19	NF_RBn			(in)
20	DEV_WEn[0]		(out)
21	DEV_AD[0]		(in/out)
22	DEV_AD[1]		(in/out)
23	DEV_AD[2]		(in/out)
24	DEV_AD[3]		(in/out)
25	DEV_AD[4]		(in/out)
26	DEV_AD[5]		(in/out)
27	DEV_AD[6]		(in/out)
28	DEV_AD[7]		(in/out)
29	NF_CLE_DEV_A[0]		(out)
30	NF_ALE_DEV_A[1]		(out)
31	SLV_SMI_MDC		(in)
32	SLV_SMI_MDIO		(in/out)

*/
#define DB_DX_BOBK_CAELUM_GPP_OUT_ENA_LOW	(~(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12\
					| BIT13 | BIT16 | BIT17 | BIT20 | BIT29  | BIT30))
#define DB_DX_BOBK_CAELUM_GPP_OUT_ENA_MID	(~(0))

#define DB_DX_BOBK_CAELUM_GPP_OUT_VAL_LOW	(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12\
					| BIT13 | BIT16 | BIT17 | BIT20 | BIT29  | BIT30)
#define DB_DX_BOBK_CAELUM_GPP_OUT_VAL_MID	0x0

#define DB_DX_BOBK_CAELUM_GPP_POL_LOW		0x0
#define DB_DX_BOBK_CAELUM_GPP_POL_MID		0x0


/************************************/
/*   BOBK-LEWIS-RD-LWS-12XG-A    */
/************************************/
#define RD_DX_BOBK_LEWIS_MPP0_7	0x00042222 /* 0-3:SPI, 4:NF_CEn, 5:SFP_Data, 6:DIAG LED, 7:TWSI_SEL1 */
#define RD_DX_BOBK_LEWIS_MPP8_15	0x11000000 /* 8:TWSI_SEL2,9:SFP_TX,10,TMP_INT,11:INIT_Done,12:MPP12,
							13:USB_OC,14-15:I2C_[SCLK,SDA] */
#define RD_DX_BOBK_LEWIS_MPP16_23	0x44444004 /* 16:NF_REn, 17:TWSI_SEL0, 18:NA, 19-23:NF_[Busy,WEn,IO[0,1,2]] */
#define RD_DX_BOBK_LEWIS_MPP24_31	0x14444444 /* 24-30: NF_IO[3,4,5,6,7],NF_CLE,NF_ALE, 31: SMI_MST_MDC(SMI) */
#define RD_DX_BOBK_LEWIS_MPP32_39	0x00000001 /* 32: SMI_MST_MDIO(SMI) */


/* GPPs
MPP#	NAME			IN/OUT
----------------------------------------------
0	SPI_SI			(in/out)
1	SPI_SO			(in/out)
2	SPI_SCK			(in/out)
3	SPI_CS0n			(in/out)
4	NF_CEn			(in/out) NAND Flash
5	SFP_Data			(in)
6	DIAG LED			(out)
7	TWSI_SEL1		(out)
8	TWSI_SEL2		(out)
9	SFP_TX_DIS		(out)
10	TMP_INT			(in)
11	INIT_Done		(in)
12	MPP12			(N/A)
13	USB_OC			(in)
14	I2C_SCLK			(out)
15	I2C_SDA			(in/out)

16	NF_REn			(in/out)NAND Flash
17	TWSI_SEL0		(out)
18	NA			(NA)
19	NF_Busy			(in/out)NAND Flash
20	NF_WEn			(in/out)NAND Flash
21	NF_IO[0]			(in/out)NAND Flash
22	NF_IO[1]			(in/out)NAND Flash
23	NF_IO[2]			(in/out)NAND Flash
24	NF_IO[3]			(in/out)NAND Flash
25	NF_IO[4]			(in/out)NAND Flash
26	NF_IO[5]			(in/out)NAND Flash
27	NF_IO[6]			(in/out)NAND Flash
28	NF_IO[7]			(in/out)NAND Flash
29	NF_CLE			(in/out)NAND Flash
30	NF_ALE			(in/out)NAND Flash
31	SMI_MST_MDC		(out)
32	SMI_MST_MDIO		(in/out)

*/
#define RD_DX_BOBK_LEWIS_GPP_OUT_ENA_LOW	(~(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT7 | BIT8\
					| BIT9 | BIT14 | BIT17 | BIT31))
#define RD_DX_BOBK_LEWIS_GPP_OUT_ENA_MID	(~(0))

#define RD_DX_BOBK_LEWIS_GPP_OUT_VAL_LOW	(~(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT9\
					| BIT14 | BIT17 | BIT31))
#define RD_DX_BOBK_LEWIS_GPP_OUT_VAL_MID	0x0

#define RD_DX_BOBK_LEWIS_GPP_POL_LOW		0x0
#define RD_DX_BOBK_LEWIS_GPP_POL_MID		0x0

/*************************************/
/*   BOBK-CYGNUS-RD-CYG-48G4XG2XLG-A    */
/*************************************/
#define RD_DX_BOBK_CYGNUS_MPP0_7	0x00042222	/* 0-3:SPI, 4:NF_CEn, 5-7:GPIO */
#define RD_DX_BOBK_CYGNUS_MPP8_15	0x11200000	/* 8-12:GPIO, 13-14:I2C_SCK[1:0 ], 15-7:I2C_SDA[0] */
#define RD_DX_BOBK_CYGNUS_MPP16_23	0x44444204	/* 16:NF_CEn, 17:GPIO, 18:I2C_SDA[1], 19:NF_RBn, 20:NF_WEn,
										21-23:NF_IO[0:2] */
#define RD_DX_BOBK_CYGNUS_MPP24_31	0x04444444	/* 24-28:NF_IO[3:7], 29-30:NF_C/ALE, 31:GPIO */
#define RD_DX_BOBK_CYGNUS_MPP32_39	0x00000000	/* 31:GPIO */

/* GPPs
MPP#	NAME			IN/OUT
----------------------------------------------
0	SPI_MOSI		(out)
1	SPI_MISO		(in)
2	SPI_SCK			(out)
3	SPI_CS0n		(out)
4	NF_CEn		(out) NF CS (Boot)
5	GPIO[5]			(in)
6	GPIO[6]			(out)
7	GPIO[7]			(out)
8	GPIO[8]			(out)
9	GPIO[9]			(out)
10	GPIO[10]			(in)
11	GPIO[11]			(in)
12	GPIO[12]			(out)
13	I2C_SCK[1]		(out)
14	I2C_SCL[0]		(in/out)
15	I2C_SDA[0]		(out)

16	NF_REn			(out)
17	GPIO[17]			(in/out)
18	I2C_SDA[1]		(out)
19	NF_RBn			(in)
20	DEV_WEn		(out)
21	NF_IO[0]			(in/out)
22	NF_IO[1]			(in/out)
23	NF_IO[2]			(in/out)
24	NF_IO[3]			(in/out)
25	NF_IO[4]			(in/out)
26	NF_IO[5]			(in/out)
27	NF_IO[6]			(in/out)
28	NF_IO[7]			(in/out)
29	NF_CLE			(out)
30	NF_ALE			(out)
31	GPIO[31]			(in)
32	GPIO[32]			(in)

*/
#define RD_DX_BOBK_CYGNUS_GPP_OUT_ENA_LOW	(~(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT7 \
						| BIT8 | BIT9 | BIT12 | BIT17))
#define RD_DX_BOBK_CYGNUS_GPP_OUT_ENA_MID	(~(0))

#define RD_DX_BOBK_CYGNUS_GPP_OUT_VAL_LOW	(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT7 \
						| BIT8 | BIT9 | BIT12 | BIT17)
#define RD_DX_BOBK_CYGNUS_GPP_OUT_VAL_MID	0x0

#define RD_DX_BOBK_CYGNUS_GPP_POL_LOW		0x0
#define RD_DX_BOBK_CYGNUS_GPP_POL_MID		0x0

/********************************************
*		AlleyCat3 Boards
*********************************************/
/*******************************************************************************
* Alleycat3 Customer board - Based on DB_DX_AC3
*******************************************************************************/

#define ALLEYCAT3_CUSTOMER_0_MPP0_7		0x22242222
#define ALLEYCAT3_CUSTOMER_0_MPP8_15		0x11122222
#define ALLEYCAT3_CUSTOMER_0_MPP16_23		0x44444044
#define ALLEYCAT3_CUSTOMER_0_MPP24_31		0x14444444
#define ALLEYCAT3_CUSTOMER_0_MPP32_39		0x00000001

#define ALLEYCAT3_CUSTOMER_0_GPP_OUT_ENA_LOW	(~(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12\
						 | BIT13 | BIT16 | BIT17 | BIT20 | BIT29  | BIT30))
#define ALLEYCAT3_CUSTOMER_0_GPP_OUT_ENA_MID	(~(0))

#define ALLEYCAT3_CUSTOMER_0_GPP_OUT_VAL_LOW	(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12\
						| BIT13 | BIT16 | BIT17 | BIT20 | BIT29  | BIT30)
#define ALLEYCAT3_CUSTOMER_0_GPP_OUT_VAL_MID	0x0

#define ALLEYCAT3_CUSTOMER_0_GPP_POL_LOW	0x0
#define ALLEYCAT3_CUSTOMER_0_GPP_POL_MID	0x0

/******************/
/*   DB_DX_AC3    */
/******************/
#define DB_DX_AC3_MPP0_7		0x00142222 /* 0-3:SPI, 4:NF_CEn, 5:PEX_RSTOUT, 6-7:GPIO */
#define DB_DX_AC3_MPP8_15		0x11122000 /* 8-10:GPIO, 11-12:UART1, 13:INTERRUPT_OUT, 14-15:I2C*/
#define DB_DX_AC3_MPP16_23		0x44444004 /* 16:NF_REn, 17-18:GPIO, 19-23:NF_[RBn,EWn,IO[0,2,3]]*/
#define DB_DX_AC3_MPP24_31		0x14444444 /* 24-30: NF_[IO{4,5,6,7],CLE,ALE], 31: SLV_MDC(SMI) */
#define DB_DX_AC3_MPP32_39		0x00000001 /* 31: SLV_MDIO(SMI) */

#define DB_DX_AC3_NOR_MPP0_7		0x44442222 /* 0-3:SPI, 4-7:DEV_xx (NOR)	 */
#define DB_DX_AC3_NOR_MPP8_15		0x11122044 /* 8-9:DEV_xx(NOR),10:GPIO, 11-12:UART1, 13:INT_OUT, 14-15:I2C */
#define DB_DX_AC3_NOR_MPP16_23		0x44443344 /* 16-17:DEV_xx (NOR),18:GPIO, 20-23:DEV_xx (NOR) */
#define DB_DX_AC3_NOR_MPP24_31		0x14444444 /* 24-30:DEV_xx (NOR),31: SLV_MDC(SMI) */

/* GPPs
MPP#	NAME			IN/OUT
----------------------------------------------
0	SPI_MOSI		(out)
1	SPI_MISO		(in)
2	SPI_SCK			(out)
3	SPI_CS0n		(out)
4	NF_CEn			(out) DEV_CSn[0]
5	PEX_RSTOUTn		(out) DEV_BOOTCSn
6	GPIO[6]			(in/out)
7	GPIO[7]			(in/out)
8	GPIO[8]			(in/out)
9	GPIO[9]			(in/out)
10	GPIO[10]		(in/out)
11	UART1_RXD		(in)
12	UART1_TXD		(out)
13	INTERRUPT_OUTn	(out)
14	I2C_SCL			(in/out)
15	I2C_SDA			(in/out)

16	DEV_Oen_NF_Ren	(out)
17	GPIO[17]		(out) DEV_CLK_OUT
18	GPIO[18]		(in/out) INT_in / SD_WP / VC2_GPP
19	NF_RBn			(in)
20	NF_WEn			(out)    DEV_WEn[0]
21	NF_IO[0]		(in/out) DEV_AD[0]
22	NF_IO[1]		(in/out) DEV_AD[1]
23	NF_IO[2]		(in/out) DEV_AD[2]
24	NF_IO[3]		(in/out) DEV_AD[3]
25	NF_IO[4]		(in/out) DEV_AD[4]
26	NF_IO[5]		(in/out) DEV_AD[5]
27	NF_IO[6]		(in/out) DEV_AD[6]
28	NF_IO[7]		(in/out) DEV_AD[7]
29	NF_CLE			(out) DEV_A[0]
30	NF_ALE			(out) DEV_A[1]
31	SLV_SMI_MDC		(in)
32	SLV_SMI_MDIO	(in/out)

*/
#define DB_DX_AC3_GPP_OUT_ENA_LOW	(~(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12 \
				| BIT13 | BIT16 | BIT17 | BIT20 | BIT29  | BIT30))
#define DB_DX_AC3_GPP_OUT_ENA_MID	(~(0))

#define DB_DX_AC3_GPP_OUT_VAL_LOW	(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12 \
				| BIT13 | BIT16 | BIT17 | BIT20 | BIT29  | BIT30)
#define DB_DX_AC3_GPP_OUT_VAL_MID	0x0

#define DB_DX_AC3_GPP_POL_LOW		0x0
#define DB_DX_AC3_GPP_POL_MID		0x0

/*****************************/
/*   RD_DX_4XG_AC3 (MTL1)    */
/*****************************/
#define RD_MTL_4XG_AC3_MPP0_7		0x00042222 /* 0-3:SPI, 4:NF_CEn, 5:CPU Awake, 6-7:GPIO */
#define RD_MTL_4XG_AC3_MPP8_15		0x11122000 /* 8-12:GPIO, TODO: set to 0 bits 11-12 13:INTERRUPT_OUT, 14-15:I2C*/
#define RD_MTL_4XG_AC3_MPP16_23		0x44444004 /* 16:NF_REn, 17-18:GPIO, 19-23:NF_[RBn,EWn,IO[0,2,3]]*/
#define RD_MTL_4XG_AC3_MPP24_31		0x14444444 /* 24-30: NF_[IO{4,5,6,7],CLE,ALE], 31: SLV_MDC(SMI) */
#define RD_MTL_4XG_AC3_MPP32_39		0x00000001 /* 31: SLV_MDIO(SMI) */

/* GPPs
MPP#	NAME			IN/OUT
----------------------------------------------
0	SPI_MOSI		(out)
1	SPI_MISO		(in)
2	SPI_SCK			(out)
3	SPI_CS0n		(out)
4	NF_CEn			(out) DEV_CSn[0]
5	PEX_RSTOUTn		(out) DEV_BOOTCSn
6	GPIO[6]			(in/out)
7	GPIO[7]			(in/out)
8	GPIO[8]			(in/out)
9	GPIO[9]			(in/out)
10	GPIO[10]		(in/out)
11	UART1_RXD		(in)
12	UART1_TXD		(out)
13	INTERRUPT_OUTn	(out)
14	I2C_SCL			(in/out)
15	I2C_SDA			(in/out)

16	DEV_Oen_NF_Ren	(out)
17	GPIO[17]		(out) DEV_CLK_OUT
18	GPIO[18]		(in/out) INT_in / SD_WP / VC2_GPP
19	NF_RBn			(in)
20	NF_WEn			(out)    DEV_WEn[0]
21	NF_IO[0]		(in/out) DEV_AD[0]
22	NF_IO[1]		(in/out) DEV_AD[1]
23	NF_IO[2]		(in/out) DEV_AD[2]
24	NF_IO[3]		(in/out) DEV_AD[3]
25	NF_IO[4]		(in/out) DEV_AD[4]
26	NF_IO[5]		(in/out) DEV_AD[5]
27	NF_IO[6]		(in/out) DEV_AD[6]
28	NF_IO[7]		(in/out) DEV_AD[7]
29	NF_CLE			(out) DEV_A[0]
30	NF_ALE			(out) DEV_A[1]
31	SLV_SMI_MDC		(in)
32	SLV_SMI_MDIO	(in/out)

*/
#define RD_MTL_4XG_AC3_GPP_OUT_ENA_LOW	(~(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12 \
		| BIT13 | BIT16 | BIT17 | BIT20 | BIT29  | BIT30))
#define RD_MTL_4XG_AC3_GPP_OUT_ENA_MID	(~(0))

#define RD_MTL_4XG_AC3_GPP_OUT_VAL_LOW	(BIT0 | BIT2 | BIT3 | BIT4 | BIT6 | BIT12 \
		| BIT13 | BIT16 | BIT17 | BIT20 | BIT29  | BIT30)
#define RD_MTL_4XG_AC3_GPP_OUT_VAL_MID	0x0

#define RD_MTL_4XG_AC3_GPP_POL_LOW		0x0
#define RD_MTL_4XG_AC3_GPP_POL_MID		0x0


/*********************************/
/*   RD_DX_2XXG_2XG_AC3 (MTL2)   */
/*********************************/
#define RD_MTL_2XXG_2XG_AC3_MPP0_7			RD_MTL_4XG_AC3_MPP0_7
#define RD_MTL_2XXG_2XG_AC3_MPP8_15			RD_MTL_4XG_AC3_MPP8_15
#define RD_MTL_2XXG_2XG_AC3_MPP16_23			RD_MTL_4XG_AC3_MPP16_23
#define RD_MTL_2XXG_2XG_AC3_MPP24_31			RD_MTL_4XG_AC3_MPP24_31
#define RD_MTL_2XXG_2XG_AC3_MPP32_39			RD_MTL_4XG_AC3_MPP32_39

#define RD_MTL_2XXG_2XG_AC3_GPP_OUT_ENA_LOW		RD_MTL_4XG_AC3_GPP_OUT_ENA_LOW
#define RD_MTL_2XXG_2XG_AC3_GPP_OUT_ENA_MID		RD_MTL_4XG_AC3_GPP_OUT_ENA_MID
#define RD_MTL_2XXG_2XG_AC3_GPP_OUT_VAL_LOW		RD_MTL_4XG_AC3_GPP_OUT_VAL_LOW
#define RD_MTL_2XXG_2XG_AC3_GPP_OUT_VAL_MID		RD_MTL_4XG_AC3_GPP_OUT_VAL_MID
#define RD_MTL_2XXG_2XG_AC3_GPP_POL_LOW		RD_MTL_4XG_AC3_GPP_POL_LOW
#define RD_MTL_2XXG_2XG_AC3_GPP_POL_MID		RD_MTL_4XG_AC3_GPP_POL_MID

/**************************************/
/*   DB-XC3-24G4G_2XG_AC3  (RD_MISL)  */
/**************************************/
#define DB_MISL_24G46_AC3_MPP0_7			RD_MTL_4XG_AC3_MPP0_7
#define DB_MISL_24G46_AC3_MPP8_15			RD_MTL_4XG_AC3_MPP8_15
#define DB_MISL_24G46_AC3_MPP16_23			RD_MTL_4XG_AC3_MPP16_23
#define DB_MISL_24G46_AC3_MPP24_31			RD_MTL_4XG_AC3_MPP24_31
#define DB_MISL_24G46_AC3_MPP32_39			RD_MTL_4XG_AC3_MPP32_39

#define DB_MISL_24G46_AC3_GPP_OUT_ENA_LOW	RD_MTL_4XG_AC3_GPP_OUT_ENA_LOW
#define DB_MISL_24G46_AC3_GPP_OUT_ENA_MID	RD_MTL_4XG_AC3_GPP_OUT_ENA_MID
#define DB_MISL_24G46_AC3_GPP_OUT_VAL_LOW	RD_MTL_4XG_AC3_GPP_OUT_VAL_LOW
#define DB_MISL_24G46_AC3_GPP_OUT_VAL_MID	RD_MTL_4XG_AC3_GPP_OUT_VAL_MID
#define DB_MISL_24G46_AC3_GPP_POL_LOW		RD_MTL_4XG_AC3_GPP_POL_LOW
#define DB_MISL_24G46_AC3_GPP_POL_MID		RD_MTL_4XG_AC3_GPP_POL_MID

/**************************************/
/*   RD-XC3-24G_AC3  (RD_MTL)        */
/**************************************/
#define RD_MTL_24G_AC3_MPP0_7				RD_MTL_4XG_AC3_MPP0_7
#define RD_MTL_24G_AC3_MPP8_15				RD_MTL_4XG_AC3_MPP8_15
#define RD_MTL_24G_AC3_MPP16_23				RD_MTL_4XG_AC3_MPP16_23
#define RD_MTL_24G_AC3_MPP24_31				RD_MTL_4XG_AC3_MPP24_31
#define RD_MTL_24G_AC3_MPP32_39				RD_MTL_4XG_AC3_MPP32_39

#define RD_MTL_24G_AC3_GPP_OUT_ENA_LOW		RD_MTL_4XG_AC3_GPP_OUT_ENA_LOW
#define RD_MTL_24G_AC3_GPP_OUT_ENA_MID		RD_MTL_4XG_AC3_GPP_OUT_ENA_MID
#define RD_MTL_24G_AC3_GPP_OUT_VAL_LOW		RD_MTL_4XG_AC3_GPP_OUT_VAL_LOW
#define RD_MTL_24G_AC3_GPP_OUT_VAL_MID		RD_MTL_4XG_AC3_GPP_OUT_VAL_MID
#define RD_MTL_24G_AC3_GPP_POL_LOW			RD_MTL_4XG_AC3_GPP_POL_LOW
#define RD_MTL_24G_AC3_GPP_POL_MID			RD_MTL_4XG_AC3_GPP_POL_MID

/**********************************************************************************/
/* ArmadaXP Boards : only for Linux usage (AXP family is shared with MSYS in LSP) */
/**********************************************************************************/
/********************/
/* DB-78460-AMC     */
/********************/

#define DB_78X60_AMC_MPP0_7			0x11111111
#define DB_78X60_AMC_MPP8_15			0x00001111
#define DB_78X60_AMC_MPP16_23			0x00000000
#define DB_78X60_AMC_MPP24_31			0x00000000
#define DB_78X60_AMC_MPP32_39			0x11110000
#define DB_78X60_AMC_MPP40_47			0x00004000
#define DB_78X60_AMC_MPP48_55			0x00001113
#define DB_78X60_AMC_MPP56_63			0x11111110
#define DB_78X60_AMC_MPP64_67			0x00000111

/* GPPs
MPP#	NAME		IN/OUT
----------------------------------------------
16	MB_INT#		IN
17	Phy1_INT#	IN
18	Phy2_INT#	IN
19	Brd_Led_0	IN (for next board)
21	Brd_Led_1	OUT
23	Brd_Led_2	OUT
29	Brd_Led_3	OUT
30	Brd_Led_4	OUT
34	Dbg_JP0		IN
35	Dbg_JP1		IN
40	Dbg_JP2		IN
41	Dbg_JP3		IN
42	Dbg_JP4		IN
53	7 Segment 0	OUT
54	7 Segment 1	OUT
55	7 Segment 2	OUT
56	7 Segment 3	OUT
*/

#define DB_78X60_AMC_GPP_OUT_ENA_LOW		(~(BIT19 | BIT21 | BIT22 | BIT23 | BIT29 | BIT30))
#define DB_78X60_AMC_GPP_OUT_ENA_MID		(~(BIT21 | BIT22 | BIT23 | BIT24))
#define DB_78X60_AMC_GPP_OUT_ENA_HIGH		(~(0x0))

#define DB_78X60_AMC_GPP_OUT_VAL_LOW		0x0
#define DB_78X60_AMC_GPP_OUT_VAL_MID		0x0
#define DB_78X60_AMC_GPP_OUT_VAL_HIGH		0x0

#define DB_78X60_AMC_GPP_POL_LOW		0x0
#define DB_78X60_AMC_GPP_POL_MID		0x0
#define DB_78X60_AMC_GPP_POL_HIGH		0x0

#endif /* __INCmvBoardEnvSpech */

