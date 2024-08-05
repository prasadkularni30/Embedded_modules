#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
	int ret=fork();
	
	if(ret==0)
	{
		printf("In Child Process 1: PID %d, PPID %d\n",getpid(),getppid());
		execl("/home/desd/pmarch_2024/Prasad_K/OS/practice/./fork_execl_trial","",NULL);
		
	}
	else if(ret>0)
	{
		ret=fork();
		if(ret==0)
		{
			printf("In Child Process 2: PID %d, PPID %d\n",getpid(),getppid());
			
			execl("/bin/gcc","gcc","/home/desd/pmarch_2024/Prasad_K/OS/practice/fork_trial.c","-o","fork_execl_trial",NULL);
//			execl("/home/desd/pmarch_2024/Prasad_K/OS/practice/./fork_trial.out","",NULL);
		}
		else
		printf("In parent Process: PID %d, PPID %d\n",getpid(),getppid());
	}
	else
		printf("Failed\n");
		
	return 0;

}
