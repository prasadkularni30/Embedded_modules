#include<stdio.h>       
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int ret=fork();

	if(ret==0)
	{
		printf("In Child Process : PID- %d, PPID- %d\n",getpid(),getppid());
		execl("/home/desd/pmarch_2024/Prasad_K/OS/./temp.out","",NULL);
		//return 0;

	}
	else if(ret>0)
	{
		printf("In Parent Process : PID- %d, PPID- %d\n",getpid(),getppid());
	}
	else
		printf("Failed\n");

	return 0;
}

