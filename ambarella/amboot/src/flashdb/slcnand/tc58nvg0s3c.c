/**
 * system/src/flashdb/slcnandl/tc58nvg0s3c.c
 *
 * History:
 *    2007/10/03 - [Evan(Kuan-Fu) Chen] created file
 *
 * Copyright (C) 2004-2007, Ambarella, Inc.
 *
 * All rights reserved. No Part of this file may be reproduced, stored
 * in a retrieval system, or transmitted, in any form, or by any means,
 * electronic, mechanical, photocopying, recording, or otherwise,
 * without the prior consent of Ambarella, Inc.
 */

#include <flash/slcnand/tc58nvg0s3c.h>
#include <flash/nanddb.h>

#ifndef NAND_DEVICES
#define NAND_DEVICES	1
#endif

IMPLEMENT_NAND_DB_DEV(tc58nvg0s3c);
