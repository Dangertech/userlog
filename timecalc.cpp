#include <time.h>
#include <vector>
#include "util.h"
#include "timecalc.h"

time_data systime;

void time_data::set_current_time()
{
	time_t epoch = time(NULL);
	struct tm *s = localtime(&epoch);

	year = s->tm_year;
	month = s->tm_mon;
	mday = s->tm_mday;
	hour = s->tm_hour;
	minute = s->tm_min;
	second = s->tm_sec;
}

int time_data::get_component(std::string cname)
{
	std::vector<std::string> poss = {"year", "month", "mday", "hour", "minute", "second"};
	int val = veccmp<std::string>(cname, poss);
	 
	switch (val)
	{
		case 0:
			return year;
		case 1:
			return month;
		case 2:
			return mday;
		case 3:
			return hour;
		case 4: 
			return minute;
		case 5:
			return second;
		case ERROR:
			return ERROR;
	}
	return ERROR;
}
