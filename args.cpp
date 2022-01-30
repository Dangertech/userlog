#include <iostream>
#include "args.h"
#include "util.h"

Args args;

void Args::handle_tag(int &arg_pos, int argc, char * argv[])
{
	arg_pos++;
	tag = argv[arg_pos];
}

void Args::handle_dest(int &arg_pos, int argc, char * argv[])
{
	arg_pos++;
	set_dest = argv[arg_pos];
}

void Args::show_help()
{
	std::cout
		<< "Usage: userlog [OPTION] MESSAGE\n"
		<< "An easy-to-use logger for human beings\n"
		<< "\n"
		<< "OPTIONs:\n"
		<< "    --tag/-t TAG(s)     Puts the given tags in square brackets in front of your message\n"
		<< "    --help/-h           Shows this help text and then terminates the program\n"
		<< "\n"
		<< "EXIT CODES:\n"
		<< "    0                   userlog only returns 0 if a message was written to the log file.\n"
		<< "    1                   This help text was shown\n"
		<< "    -1                  The log destination couldn't be opened;\n"
		<< "                            Check if userlog has the sufficient privileges to write to it\n"
		<< "    -2                  No message was given\n"
		<< "\n"    
		<< "You can choose the directory in which userlog puts the logs at compile time by changing\n"
		<< "the variable 'LOG_LOC' at the top of the Makefile and issuing 'sudo make install' again.\n"
		<< "The default is '/var/log/userlog/'\n"
		<< "\n"
		<< "Additional info and instructions can be found at: <https://github.com/Dangertech/userlog>\n"
		<< "Written by Kjell Nagel, student at STAMA, Bad Kreuznach, Germany\n"
	;
	exit(1);
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
				case 1:
					show_help();
					break;
				case 2:  // --dest
					handle_dest(i, argc, argv);
					break;
			}
		}
		else if (util.begmatch(argv[i], "-"))
		{
			int entry = util.veccmp<std::string>(std::string(argv[i]), sswitches);
			switch(entry)
			{
				case 0: // -t
					handle_tag(i, argc, argv);
					break;
				case 1:
					show_help();
					break;
				case 2: // -d
					handle_dest(i, argc, argv);
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
