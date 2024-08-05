#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int ret=fork();
	
	if(ret==0)
		printf("In Child process: PID %d,PPID %d\n",getpid(),getppid());
	else if(ret>0)
		printf("In Parent process: PID %d,PPID %d\n",getpid(),getppid());
	else
		printf("Failed to create child process\n");
		
		
	return 0;
		
}
