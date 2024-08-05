#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
	int ret=fork();
	
	if(ret==0)
	{
		printf("In Child Process: PID %d, PPID %d\n",getpid(),getppid());
		
		execl("/bin/evince","evince","/home/desd/pmarch_2024/Lyra/docs/aries.pdf",NULL);
	}
	else if(ret>0)
		printf("In parent Process: PID %d, PPID %d\n",getpid(),getppid());
	else
		printf("Failed\n");
		
	return 0;

}
