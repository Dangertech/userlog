#include <iostream>
#include <vector>
#include "timecalc.h"
#include "util.h"

int main()
{
	systime.set_current_time();
	std::cout << systime.get_component("mday") << std::endl;
}
