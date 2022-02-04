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
	for (i = 1; i < n; i++)
		if (childpid = fork()){
			if(childpid < 0){
				perror("Chain: Error forking child");
				return;
			}
			break;
		}

	fprintf(pFile, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
		i, (long)getpid(), (long)getppid(), (long)childpid);
	fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
		i, (long)getpid(), (long)getppid(), (long)childpid);


	return;

}



	//pid_t childpid = 0;
	//pid_t mypid;
	//pid_t parentpid;
	//pid_t waitreturn;
	//int i;
	//for (i = 1; i < n; i++) {
	//	mypid = getpid();
	//	parentpid = getppid();

	//	if ((childpid = fork()) < 0)
	//	{
	//		perror("Error forking child");
	//		//return (1);			// Terminate code
	//	}
	//	else
	//		break;
	//}

	//while (childpid != (waitreturn = wait(NULL)))
	//	if ((waitreturn == -1) && (errno != EINTR))
	//		break;


	//fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
	//		i, mypid, parentpid, childpid);

	//sleep(sleepIn);

	//fprintf(stderr, "i:%i my ID:%ld parent ID:%ld\n",
	//	i,(long)getpid(), (long)getppid() );




#endif

//
//pid_t childpid, cpid;		// Process id for child
//char command[] = "ls";		// Command to be executed
//char path[] = "/bin/ls";		// Path for the command
//int status;				// Return value from child
//
//// Fork child
//
//if ((childpid = fork()) < 0)
//{
//	perror("Error forking child");
//	return (1);			// Terminate code
//}
//
//if (childpid)			// Code for parent
//{
//	printf("In parent\n");
//	printf("Process id %ld Parent id %ld\n", (long)getpid(), (long)getppid());
//	printf("Waiting for child to terminate ...\n");
//
//	cpid = wait(&status);
//
//	printf("Child %ld returned %d\n", cpid, WEXITSTATUS(status));
//
//	return (0);			// Parent terminates
//}
//
//// This is the code for child
//
//sleep(10);		// Wait for 10 sec before executing child
//execl(path, command, (char)(NULL));
//
//// We come to this point only if execl failed.
//
//perror("Problem with execl: ");
//
//return (1);
//}