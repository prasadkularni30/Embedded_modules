#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
	int ret=fork();
	
	if(ret==0)
	{
		printf("In Child Process: PID %d, PPID %d\n",getpid(),getppid());
		
		execl("/home/desd/pmarch_2024/Prasad_K/OS/practice/./fork_execl_trial","",NULL);
	}
	else if(ret>0)
		printf("In parent Process: PID %d, PPID %d\n",getpid(),getppid());
	else
		printf("Failed\n");
		
	return 0;

}
