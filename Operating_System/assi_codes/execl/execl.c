#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/* OBSERVATION*/
// after successful execution
// with help of execl we executed new process with same Process ID and Parent Process ID
// proved same in top command
// here in this program used execl for 2 different tasks
//	[1]after calling execl in child 2 it is executing a process of creating executable file of execl_temp.c file
//	[2]execl in child 1 is exectuing the file with was created by execl function in child 2


int main()
{
	int ret1,ret2;
	
	if((ret1=fork())<0){perror("Child Creation Failed"); exit(1);}	//function to create a child
	
	if(ret1==0)
	{
		printf("In Child Process 1: PID %d, PPID %d\n",getpid(),getppid());	//printing PID and PPID to verify with PID and PPID of new process created 
											//with fork
		sleep(1);	//sleep until child 2 process creates a executing file of trial file
		
		execl("/home/desd/Desktop/240340130035(Prasad_Kulkarni)OS/Q2/./execl_temp","",NULL);
				//calling or executing another file using execl
		
	}
	else if(ret1>0)
	{
		if((ret2=fork())<0){perror("Child Creation Failed"); exit(2);}	//funnction to create child process
		if(ret2==0)
		{
			printf("In Child Process 2: PID %d, PPID %d\n",getpid(),getppid());
			
				
				//calling and exectuing commands of creating executable file using execl function
			execl("/bin/gcc","gcc","/home/desd/Desktop/240340130035(Prasad_Kulkarni)OS/Q2/execl_temp.c","-o","execl_temp",NULL);
				/* NOTE: if executing in any other system or folder PATH should be modified and temp file should be present there */

				
		}
		if(ret2>0)
		{
			printf("In parent Process: PID %d, PPID %d\n",getpid(),getppid());
			while(1);	//while to to keep running the process for top observations
		}
	}
		
	return 0;

}
