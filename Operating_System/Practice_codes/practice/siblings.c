#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int ret=fork();
	
	if(ret==0)
		printf("In Child process 1: PID %d,PPID %d\n",getpid(),getppid());
	else if(ret>0)
	{
		ret=fork();
		
		if(ret==0)
			printf("In Child process 2: PID %d,PPID %d\n",getpid(),getppid());
		else if(ret>0)
			printf("In Parent process: PID %d,PPID %d\n",getpid(),getppid());
		else
		printf("Failed to create child process 2\n");
	}
	else
		printf("Failed to create child process 1\n");
		
		
	return 0;
		
}
