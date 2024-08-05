#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
        int ret=fork();

        if(ret==0)
        {
        	int ret1=fork();
        	
        	if(ret1==0)
        	{
        		printf("In Child Process 2: PID- %d, PPID- %d\n",getpid(),getppid());
        		//execl("/home/desd/pmarch_2024/Prasad_K/OS/./temp1.out","",NULL);
        		execl("/home/desd/pmarch_2024/Prasad_K/OS/./temp1.out","",NULL);
        		
        	}
        	else if(ret1>0)
        	{
                	printf("In Child Process 1: PID- %d, PPID- %d\n",getpid(),getppid());
                	execl("/usr/bin/gcc","gcc","temp.c","-o","temp1.out",NULL);
                }
                //return 0;
        }
        else if(ret>0)
               printf("In Parent Process : PID- %d, PPID- %d\n",getpid(),getppid());
        else
                printf("Failed\n");

        return 0;
}
