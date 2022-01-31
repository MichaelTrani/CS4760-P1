#ifndef CHAIN_H
#define CHAIN_H

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <fstream>
//#include "processes.h"

//#include <cstring>
//#include <stdio.h>
//#include <stdlib.h>

void processor(int n, int sleepIn) {
	pid_t childpid = 0;
	int i;
	for (i = 1; i < n; i++)
		if ((childpid = fork()))
			break;
	fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
		i, (long)getpid(), (long)getppid(), (long)childpid);
	sleep(sleepIn);
}






#endif
