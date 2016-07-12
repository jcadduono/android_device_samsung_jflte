/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "util.h"

#include "init_msm.h"

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
	char bootloader[PROP_VALUE_MAX];

	UNUSED(msm_id);
	UNUSED(msm_ver);
	UNUSED(board_type);

	property_get("ro.bootloader", bootloader);

	if (strstr(bootloader, "I337M")) {
		/* jfltecan */
		property_set("ro.product.model", "SGH-I337M");
		property_set("ro.product.name", "jfltecan");
	} else if (strstr(bootloader, "M919V")) {
		/* jfltecan */
		property_set("ro.product.model", "SGH-M919V");
		property_set("ro.product.name", "jfltecan");
	} else if (strstr(bootloader, "I337")) {
		/* jflteatt */
		property_set("ro.product.model", "SM-I337");
		property_set("ro.product.name", "jflteatt");
	} else if (strstr(bootloader, "M919")) {
		/* jfltetmo */
		property_set("ro.product.model", "SGH-M919");
		property_set("ro.product.name", "jfltetmo");
	} else if (strstr(bootloader, "L720")) {
		/* jfltespr */
		property_set("ro.product.model", "SPH-L720");
		property_set("ro.product.name", "jfltespr");
	} else if (strstr(bootloader, "R970")) {
		/* jflteusc */
		property_set("ro.product.model", "SCH-R970");
		property_set("ro.product.name", "jflteusc");
	} else if (strstr(bootloader, "I545")) {
		/* jfltevzw */
		property_set("ro.product.model", "SCH-I545");
		property_set("ro.product.name", "jfltevzw");
	} else if (strstr(bootloader, "R970C")) {
		/* jfltecri */
		property_set("ro.product.model", "SCH-R970C");
		property_set("ro.product.name", "jfltecri");
	} else if (strstr(bootloader, "R970X")) {
		/* jfltespi */
		property_set("ro.product.model", "SCH-R970X");
		property_set("ro.product.name", "jfltespi");
	} else if (strstr(bootloader, "SC04E")) {
		/* jfltedcm */
		property_set("ro.product.model", "SC-04E");
		property_set("ro.product.name", "jfltedcm");
	} else if (strstr(bootloader, "I9508")) {
		/* jfltezm */
		property_set("ro.product.model", "GT-I9508");
		property_set("ro.product.name", "jfltezm");
	} else if (strstr(bootloader, "I9505G")) {
		/* jgedlte */
		property_set("ro.product.model", "GT-I9505G");
		property_set("ro.product.name", "jgedlte");
	} else if (strstr(bootloader, "I9505VJ")) {
		/* jfltevj */
		property_set("ro.product.model", "GT-I9505");
		property_set("ro.product.name", "jfltevj");
	} else {
		/* all other variants become jfltexx */
		property_set("ro.product.model", "SM-I9505");
		property_set("ro.product.name", "jfltexx");
	}
	property_set("ro.product.device", "jflte");
}
