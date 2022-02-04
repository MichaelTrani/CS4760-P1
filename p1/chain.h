#ifndef CHAIN_H
#define CHAIN_H

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sys/wait.h>

FILE* pFile;


void processor(int n, int sleepIn) {

	pid_t childpid = 0;
	int i;
	for (i = 1; i <= n; i++) {
		if ((childpid = fork())< 0) {
			perror("Chain: Error forking child");
			return;
		}

		if (childpid)	// Code for parent
		{
			// This section is useless for more than 
			//fprintf(pFile, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
			//	i, (long)getpid(), (long)getppid(), (long)childpid);

			fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
				i, (long)getpid(), (long)getppid(), (long)childpid);
			
		}

		else		// Code for child
		{
			std::cout << "child has exited: " << getpid() << std::endl;
			break;
		}
	}

}



#endif