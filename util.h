#include <vector>
#include <string>
#include "const.h"
#pragma once

class Util
{
	public:
		/* Output the location of a variable in a vector of variables
		 * Return ERROR if it isn't contained within
		 */
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
		 
		bool begmatch(const char* to_comp, const char* against);
} extern util;

