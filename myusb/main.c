
#undef __weak

#define __KERNEL__
#define MYBUILD

#include <linux/compiler-version.h>
#include <linux/kconfig.h>
#include <linux/compiler_types.h>

#include "../drivers/scsi/scsi.c"

int main(int argc, char *argv[])
{
	return 0;
}