# Logging folder
LOG_LOC=/var/log/userlog
BINNAME=userlog

CC=g++

SRC=main.cpp timecalc.cpp util.cpp

build:
	${CC} -o ${BINNAME} ${SRC} -DLOG_LOC=\"${LOG_LOC}\"


install: build
	cp -f ${BINNAME} /usr/local/bin
