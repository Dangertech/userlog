#include <fstream>
#include <string>
#include <iostream>
#include <sys/stat.h>
#include "timecalc.h"
#include "file.h"
#include "const.h"
#include "util.h"

File file;

std::string File::get_logdir(Time_data time)
{
	/* Take LOG_LOC as base */
	std::string my_loc = LOG_LOC;
	my_loc += "/" + std::to_string(time.get_component("year"));
	my_loc += "/" + std::to_string(time.get_component("month"));
	/* Gives something like:
	 * /var/log/userlog/2022/0/3.log
	 * Log of the third of January 2022
	 */
	return my_loc;
}

std::string File::get_logname(Time_data time)
{
	return std::to_string(time.get_component("mday")) + ".log";
}

int File::make_dirs(std::string dir)
{
	std::cout << dir << std::endl;
	std::vector<std::string> split = util.split(dir, '/');
	std::string cur_path = "/" + split[1];
	mkdir(cur_path.c_str(), 0777);
	for (int i = 2; i<split.size(); i++)
	{
		/* Always try to make the directories, even if they exist
		 * because it doesn't change anything,
		 * mkdir() just silently fails
		 */
		cur_path += "/" + split[i];
		std::cout << cur_path << std::endl;
		mkdir(cur_path.c_str(), 0777);
	}
	return ERROR;
}

int File::write_entry(Args my_arg)
{
	std::string location = get_logdir(systime) + "/" + get_logname(systime);
	/* Create needed directories */
	make_dirs(get_logdir(systime));
	/* Open File in append mode */
	std::ofstream logfile(location, std::ios_base::app);
	if (logfile.is_open())
	{
		/* Write! */
		logfile << my_arg.get_message() << std::endl;
	}
	else
	{
		std::cout << "userlog: Couldn't open logfile under the location " << location << std::endl;
		return ERROR;
	}
	logfile.close();
	return 0;
}
