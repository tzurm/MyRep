
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "fs_parsing.h"

int main(void)
{
	const char path[10] = "/dev/ram0";

	PrintSuperBlock(GetSuperBlock(path));
	PrintGroupDesc(GetGroupDesc(path));
	return 0;
}
