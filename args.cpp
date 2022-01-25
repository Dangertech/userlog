#include <iostream>
#include "args.h"
#include "util.h"

Args args;

void Args::handle_tag(int &arg_pos, int argc, char * argv[])
{
	arg_pos++;
	tag = argv[arg_pos];
}

void Args::process_args(int argc, char *argv[])
{
	for (int i = 1; i<argc; i++)
	{
		if (util.begmatch(argv[i], "--"))
		{
			int entry = util.veccmp<std::string>(std::string(argv[i]), lswitches);
			switch(entry)
			{
				case 0: // --tag
					handle_tag(i, argc, argv);
					break;
			}
		}
		else if (util.begmatch(argv[i], "-"))
		{
			int entry = util.veccmp<std::string>(std::string(argv[i]), lswitches);
			switch(entry)
			{
				case 0: // -t
					handle_tag(i, argc, argv);
					break;
			}
		}
		else
		{
			/* Argument MUST be log content (at least right now) */
			if (message == "")
				message = argv[i];
			else
				std::cout << "userlog: Setting more than one message is not allowed;" << std::endl;
		}
	}
}
