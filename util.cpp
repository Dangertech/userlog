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

std::vector<std::string> Util::split(std::string input, char breaker, 
		bool exclude_breaker /*= true*//*, bool right_breaker /*= false*/)
{
	std::vector<std::string> splitvec;
	std::vector<int> marks = {-1}; // Pos 0 is the first breaker
	/* Get marks on where to break up */
	for (long unsigned int i = 0; i<input.size()-1; i++)
	{
		if (input[i] == breaker)
			marks.push_back(i); 
	}
	marks.push_back(input.size());
	/* Put the stuff along the marks into the splitvec */
	for (long unsigned int i = 1; i<marks.size(); i++)
	{
		std::string part;
		for (long unsigned int j = marks[i-1]+exclude_breaker; j<marks[i]; j++)
		{
			part += input[j];
		}
		splitvec.push_back(part);
	}
	return splitvec;
}
