#include <string.h>
#include "util.h"
#include "const.h"

Util util;

bool Util::begmatch(const char* to_comp, const char* against)
{
	if (strncmp(to_comp, against, strlen(against)) == 0)
		return true;
	return false;
}

