#include <string>
#pragma once

class time_data
{
	private:
		int year;
		int month;
		int mday; // from 0 to 31
		int hour; 
		int minute;
		int second;
	public:
		void set_current_time();
		 
		int get_component(std::string component);
		/* Get the components of the time_data:
		 * "year", "month", "mday", "hour", "minute", "second"
		 */
} extern systime;
