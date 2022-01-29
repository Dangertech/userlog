#include "args.h"
#include "timecalc.h"
#pragma once

class File
{
	private:
		std::string get_logdir(Time_data time); // /var/log/userlog/2022/0
		std::string get_logname(Time_data time); // 27.log
		/* Format the stuff in the argument to the format in which they
		 * appear in the log
		 */
		std::string format(Args my_arg, Time_data my_time);
		/* Make as many directories as needed to 
		 * make the specified dir possible, e.g:
		 * make_dirs("/home/username/dir_one/dir_two/dir_three")
		 * -> Provided that dir_two and dir_three don't exist yet, create them
		 */
		int make_dirs(std::string dir);
	public:
		// Write the entry to a file
		int write_entry(Args my_arg);
};

extern File file;
