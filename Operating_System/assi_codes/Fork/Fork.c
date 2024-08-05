#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int ret1,ret2;

	if((ret1=fork())<0){ perror("Child 1 creation failed"); exit(1);}	//function to create child process

	if(ret1==0)
	{
		printf("------In Child Process 1------\nPID: %d\nPPID: %d\n",getpid(),getppid());
		//printing Process ID and Parent Process ID to verify PPID of child process should be PID of Parent process

		return 0;
	}
	if(ret1>0)
	{
		if((ret2=fork())<0){ perror("Child 2 creation failed"); exit(2);}
		
		if(ret2==0)
		{
			printf("------In Child Process 2------\nPID: %d\nPPID: %d\n",getpid(),getppid());
			//printing Process ID and Parent Process ID to verify PPID of child process should be PID of Parent process

			return 0;
		}
		if(ret2>0)
		{
			printf("------In Parent Process------\nPID: %d\nPPID: %d\n",getpid(),getppid());
			//printing Process ID and Parent Process ID
			
			//function to wait for a specified child process to stop or terminate
			//ret1 and ret2 contains the PID of child 1 process and Child 2 Process
			waitpid(ret1,NULL,0);	
			waitpid(ret2,NULL,0);
			return 0;
		}
	}

	return 0;
}
