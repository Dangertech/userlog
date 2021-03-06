#include <string>
#include <vector>
#pragma once

class Args
{
	private:
		std::string message;
		std::string tag;
		std::string set_dest;
		std::vector <std::string> lswitches =
		{
			"--tag",
			"--help",
			"--dest"
		};
		 
		std::vector <std::string> sswitches =
		{
			"-t",
			"-h",
			"-d"
		};
		 
		/* Argument handlers: Get attached arguments to argument and dispatch the
		 * functions that solve them; Increase the position by the arguments you
		 * processed
		 */
		void handle_tag(int &arg_pos, int argc, char * argv[]);
		void handle_dest(int &arg_pos, int argc, char * argv[]);
		void show_help();
	public:
		// Goes through all given arguments, called from main
		void process_args(int argc, char *argv[]);
		inline std::string get_message() { return message; };
		inline std::string get_tag() { return tag; };
		inline std::string get_set_dest() { return set_dest; };

};

extern Args args;
