#include <iostream>
#include "timecalc.h"
#include "util.h"
#include "args.h"
#include "file.h"

int main(int argc, char *argv[])
{
	systime.set_current_time();
	args.process_args(argc, argv);
	int opout = file.write_entry(args); // Write to the log
	switch(opout)
	{
		case 0:
			return 0;
			break;
		case ERROR:
			std::cout << "userlog: Couldn't open log file! Please check the privileges of your userlog location: " << LOG_LOC << std::endl;
			return -1;
		case ERR_NO_IPT:
			std::cout << "userlog: A message is required" << std::endl;
			return -2;
			break;
	}
}
