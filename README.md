# userlog
An easy-to-use logger for human beings

## What.
userlog allows you to easily log the activity of your shell scripts in a
simple, human-readable format. It is meant to be used in environments you
leave alone for a long time and want to make sure everything executes correctly.
I personally use it to log the activity of my Raspberry Pi and created it for
exactly that purpose.

## Usage.

You can log something as easy as `userlog "My supercool message"`. This will
create an entry in **today's log**. userlog creates new log file for every
day, in this format:

	USERLOG_HOME (By default /var/log/userlog)
	|
	---2021
	|
	---2022
	   |
	   ---0
	   |
	   ---1
	   |  |
	   |  ---27.log (Log of February the 27th 2022)
	   |  |
	   |  ---28.log
	   |
	   ---...
	   |
	   ---11

A log entry looks like this:

	<hh:mm:ss>: My supercool message

You can also **add a tag (or multiple tags)** to your entry to be able to easily `grep` similare messages
later on: `userlog --tag "My Awesome Tag" "My Awesome Message"

The output then becomes

	<hh:mm:ss> [My Awesome Tag]: My Awesome Message

If you don't want to use this filesystem you can also declare your own file(path):
`userlog --dest /home/user/mylog.log "Amazing Message on my home directory"`

## Install.

Download the source and run `sudo make install`:

	git clone https://github.com/Dangertech/userlog
	cd userlog
	sudo make install

Before installing, you'll maybe want to change your userlog directory by editing the Makefile.
The default is at /var/log/userlog, which is a pretty good location in my opinion, but you
might desire something different. To change the location, change the `LOG_LOC` variable
at the top of the Makefile.

### userlog: Couldn't open log file! Please check the privileges of your userlog location: /var/log/userlog

Your `/var/log/` directory is owned by the root user but userlog tries to write it as an unprivileged user;
Fix this by changing the directory ownership: `sudo chown yourusername /var/log`. This ownership change
will probably change on reboot, so make sure to put it into a startup routine that executes this command on boot.

## Code Structure.

userlog is my first project that makes extensive use of C++ classes. It is really robust and extensible for
a project with such a small scope and I used it to try out new programming techniques. I really like how
much cleaner and more structured everything is and I'll continue to try and code in this way.
