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

		std::vector<std::string> split(std::string input, char breaker, 
				bool exclude_breaker = true/*, bool right_breaker = false*/);
		 
		// Match against the beginning of a string: Is against at the beginning of to_comp?
		bool begmatch(const char* to_comp, const char* against);
} extern util;

