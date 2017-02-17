/**
 * @file system/include/flash/slcnand/mt29f2g08.h
 *
 * History:
 *    2007/05/08 - [Dragon Chiang] created file
 *
 * Copyright (C) 2004-2007, Ambarella, Inc.
 *
 * All rights reserved. No Part of this file may be reproduced, stored
 * in a retrieval system, or transmitted, in any form, or by any means,
 * electronic, mechanical, photocopying, recording, or otherwise,
 * without the prior consent of Ambarella, Inc.
 */

#ifndef __MT29F2G08_H__
#define __MT29F2G08_H__

/**
 * nand control register initial setting
 */
#define __NAND_CONTROL						  \
	(NAND_CTR_C2		|				  \
	 NAND_CTR_P3		|				  \
	 NAND_CTR_I4		|				  \
	 NAND_CTR_RC		|				  \
	 NAND_CTR_CC		|				  \
	 NAND_CTR_IE		|				  \
	 NAND_CTR_SZ_2G		|				  \
	 NAND_CTR_WD_8BIT)

#define NAND_MANID		0x2c
#define NAND_DEVID		0xda
#define NAND_ID3		0x00
#define NAND_ID4		0x00

/**
 * define for device info
 */
#define NAND_MAIN_SIZE		2048
#define NAND_SPARE_SIZE		64
#define NAND_PAGE_SIZE		2112
#define NAND_PAGES_PER_BLOCK	64
#define NAND_BLOCKS_PER_PLANE	2048
#define NAND_BLOCKS_PER_ZONE	2048
#define NAND_BLOCKS_PER_BANK	2048
#define NAND_PLANES_PER_BANK	(NAND_BLOCKS_PER_BANK / NAND_BLOCKS_PER_PLANE)
#define NAND_BANKS_PER_DEVICE	1
#define NAND_TOTAL_BLOCKS	(NAND_BLOCKS_PER_BANK * NAND_BANKS_PER_DEVICE)
#define NAND_TOTAL_ZONES	(NAND_TOTAL_BLOCKS / NAND_BLOCKS_PER_ZONE)
#define NAND_TOTAL_PLANES	(NAND_TOTAL_BLOCKS / NAND_BLOCKS_PER_PLANE)

/* Copyback must be in the same plane, so we have to know the plane address */
#define NAND_BLOCK_ADDR_BIT	16
#define NAND_PLANE_ADDR_BIT	16 /* A16 must be the same for copyback */
#define NAND_PLANE_MASK		0x1
/* Used to mask the plane address according to block address in the same bank */
#define NAND_PLANE_ADDR_MASK	(NAND_PLANE_MASK << (NAND_PLANE_ADDR_BIT - \
						     NAND_BLOCK_ADDR_BIT))

#define NAND_PLANE_MAP		NAND_PLANE_MAP_0
#define NAND_COLUMN_CYCLES	2
#define NAND_PAGE_CYCLES	3
#define NAND_ID_CYCLES		1
#define NAND_CHIP_WIDTH		8
#define NAND_CHIP_SIZE_MB	256
#define NAND_BUS_WIDTH		8

#define NAND_NAME	"Micron MT29F2G08"

#if defined(CONFIG_NAND_1DEVICE)
#define NAND_DEVICES		1
#elif defined(CONFIG_NAND_2DEVICE)
#define NAND_DEVICES		2
#elif defined(CONFIG_NAND_4DEVICE)
#define NAND_DEVICES		4
#endif

#define NAND_TOTAL_BANKS	(NAND_DEVICES * NAND_BANKS_PER_DEVICE)

#if (NAND_TOTAL_BANKS == 1)
#define NAND_CONTROL		(__NAND_CONTROL | NAND_CTR_1BANK)
#elif (NAND_TOTAL_BANKS == 2)
#define NAND_CONTROL		(__NAND_CONTROL | NAND_CTR_2BANK)
#elif (NAND_TOTAL_BANKS == 4)
#define NAND_CONTROL		(__NAND_CONTROL | NAND_CTR_4BANK)
#elif (NAND_TOTAL_BANKS > 4)
#error Unsupport nand flash banks
#endif

#define NAND_BB_MARKER_OFFSET	0	/* bad block information */

/**
 * define for partition info
 */
#define NAND_RSV_BLKS_PER_ZONE	24

/**
 * timing parameter in ns
 */
#define NAND_TCLS		25
#define NAND_TALS		25
#define NAND_TCS		35
#define NAND_TDS		20
#define NAND_TCLH		10
#define NAND_TALH		10
#define NAND_TCH		10
#define NAND_TDH		10
#define NAND_TWP		25
#define NAND_TWH		15
#define NAND_TWB		150
#define NAND_TRR		20
#define NAND_TRP		25
#define NAND_TREH		15
#define NAND_TRB		100	/* not in spec, use the same as TWB */
#define NAND_TCEH		45	/* TRHZ - TCHZ =  */
#define NAND_TRDELAY		30	/* tREA */
#define NAND_TCLR		10
#define NAND_TWHR		80
#define NAND_TIR		0
#define NAND_TWW		20	/* not in spec, use the same as TRR */
#define NAND_TRHZ		30
#define NAND_TAR		10

#endif
