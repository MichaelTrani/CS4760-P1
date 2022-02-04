CHAIN(P1)						User Commands

NAME
	chain - creates a chain of children processes and logs PIDs to output file.
COMPILE
	$ make

Decomplile:
	$ make clean

SYNOPSIS
	./chain [-h] [-p nprocs] [-c nchars] [-s sleeptime] [-i niters] < textfile

DESCRIPTION
	Linux System Calls and Library Functions

	nprocs Number of processes [default 4]
	nchars Number of characters read into the buffer [default 80]
	sleeptime Time to sleep in each iteration [default 3s]
	niters Number of iterations in the loop
	textfile File containing text to be read through stdin
	-h prints help message

Author
	Written by Michael Trani for CMP SCI 4760
	January 2022

NOTE
	Buffer variable not used since made in c++.