#include <vector>
#include "const.h"
#pragma once

template <typename T>
int veccmp(T to_comp, std::vector<T> vec)
{
	for (long unsigned int i = 0; i<vec.size(); i++)
	{
		if (to_comp == vec[i])
			return i;
	}
	return ERROR;
}
