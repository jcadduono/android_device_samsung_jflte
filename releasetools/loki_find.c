#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

#include "loki.h"

#define BOOT_PATTERN "\x4f\xf4\x70\x40\xb3\x49\x2d\xe9"	/* Samsung GS4 */

int loki_find(const char* aboot_image)
{
	int aboot_fd;
	struct stat st;
	void *aboot, *ptr;
	unsigned long aboot_base, check_sigs, boot_mmc;

	aboot_fd = open(aboot_image, O_RDONLY);
	if (aboot_fd < 0) {
		printf("[-] Failed to open %s for reading.\n", aboot_image);
		return 1;
	}

	if (fstat(aboot_fd, &st)) {
		printf("[-] fstat() failed.\n");
		return 1;
	}

	aboot = mmap(0, (st.st_size + 0xfff) & ~0xfff, PROT_READ, MAP_PRIVATE, aboot_fd, 0);
	if (aboot == MAP_FAILED) {
		printf("[-] Failed to mmap aboot.\n");
		return 1;
	}

	check_sigs = 0;
	aboot_base = *(unsigned int *)(aboot + 12) - 0x28;

	/* Do a pass to find signature checking function */
	for (ptr = aboot; ptr < aboot + st.st_size - 0x1000; ptr++) {
		if (!memcmp(ptr, PATTERN1, 8) ||
			!memcmp(ptr, PATTERN2, 8) ||
			!memcmp(ptr, PATTERN3, 8) ||
			!memcmp(ptr, PATTERN4, 8) ||
			!memcmp(ptr, PATTERN5, 8)) {

			check_sigs = (unsigned long)ptr - (unsigned long)aboot + aboot_base;
			break;
		}

		if (!memcmp(ptr, PATTERN6, 8)) {

			check_sigs = (unsigned long)ptr - (unsigned long)aboot + aboot_base;

			/* Don't break, because the other LG patterns override this one */
			continue;
		}
	}

	if (!check_sigs) {
		printf("[-] Could not find signature checking function.\n");
		return 1;
	}

	printf("[+] Signature check function: %.08lx\n", check_sigs);

	boot_mmc = 0;

	/* Do a second pass for the boot_linux_from_emmc function */
	for (ptr = aboot; ptr < aboot + st.st_size - 0x1000; ptr++) {
		if (!memcmp(ptr, BOOT_PATTERN, 8)) {
			boot_mmc = (unsigned long)ptr - (unsigned long)aboot + aboot_base;
			break;
		}
	}

	if (!boot_mmc) {
		printf("[-] Could not find boot_linux_from_mmc.\n");
		return 1;
	}

	printf("[+] boot_linux_from_mmc: %.08lx\n", boot_mmc);

	return 0;
}