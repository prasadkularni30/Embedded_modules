#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
	printf("Process running through Execl command\nPID: %d,PPID: %d\n",getpid(),getppid());

	while(1);
}
