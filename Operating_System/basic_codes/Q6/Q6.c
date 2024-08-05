/*
>>6 Create child process using fork(), then call execl() from that
    child process and run aother command from that. Check the PID, PPID
    Share your observation.
*/

#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<stdio.h>


int main()
{
	int ret;
	
	if((ret=fork())<0)
	{
		printf("Child process creation failed\n");
		exit(0);
	}
	
	if(ret==0)
	{
		printf("In child Process Before Execl\nPID: %d PPID: %d\n",getpid(),getppid());
		
		
		execl("/bin/evince","evince","/home/desd/pmarch_2024/Lyra/docs/aries.pdf",NULL);
	}
	else if(ret>0)
	{
		printf("In Parent process\nPID: %d,PPID: %d\n",getpid(),getppid());
		
	}
}
