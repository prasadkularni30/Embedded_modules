#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
	int ret;
	
	if((ret=fork()))
	{
		printf("Failed\n");
	}
	
	if(ret==0)
	{
		printf("Before Execl\nIn Child Process 1 PID: %d PPID: %d\n",getpid(),getppid());
		execl("/home/desd/pmarch_2024/Prasad_K/OS/Assi1/Q5/./temp","",NULL);
		
		
	}
	else if(ret>0)
	{
		ret=fork();
		if(ret==0)
		{
			printf("Before Execl\nIn Child Process 2 PID: %d PPID: %d\n",getpid(),getppid());
		
			execl("/bin/gcc","gcc","/home/desd/pmarch_2024/Prasad_K/OS/Assi1/Q5/temp.c","-o","temp",NULL);
			
		}
		else if(ret>0)
		{
			//wait(-1);
			printf("In Parent Process PID: %d,PPID: %d\n",getpid(),getppid());
		}
		
	}

	return 0;
}	
