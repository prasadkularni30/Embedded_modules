/*
>>4 Create child process using fork(), try to observe
    the defferent stats of processes.
    Observe the O/P of ps and top
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>


int main()
{
	int ret;
	
	if((ret=fork())<0)
	{
		printf("Child Process creation failed\n");
		exit(0);
	}
	
	if(ret==0)
	{
		printf("In child Process\nPID: %d, PPID: %d\n",getpid(),getppid());
		
		while(1);
	}
	else if(ret>0)
	{
		printf("In Parent Process\nPID: %d, PPID: %d\n",getpid(),getppid());
		
		while(1);
	}
	
	
	return 0;
}
