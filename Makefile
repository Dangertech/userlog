# Logging folder
LOG_LOC=/home/dangertech/userlog
BINNAME=userlog

CC=g++

SRC=main.cpp timecalc.cpp util.cpp args.cpp file.cpp

build:
	${CC} -o ${BINNAME} ${SRC} -DLOG_LOC=\"${LOG_LOC}\"


install: build
	cp -f ${BINNAME} /usr/local/bin
