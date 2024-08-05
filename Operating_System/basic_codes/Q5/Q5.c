/*
>>5 Create a process and implement execl() to run another command.
    Observe the O/P in top and ps. Check the PID and PPID and share
    your observation.
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>


int main()
{
	printf("Before execution of execl \nProcess PID: %d PPID: %d\n",getpid(),getppid());
	
	execl("/home/desd/pmarch_2024/Prasad_K/OS/Assi1/Q5/./temp.out","",NULL);
	
	
	return 0;
}
