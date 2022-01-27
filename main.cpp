#include <iostream>
#include <vector>
#include "timecalc.h"
#include "util.h"
#include "args.h"
#include "file.h"

int main(int argc, char *argv[])
{
	systime.set_current_time();
	args.process_args(argc, argv);
	std::cout << "Message: " << args.get_message() << "; Tag: " << args.get_tag() << std::endl;
	file.write_entry(args);
}
