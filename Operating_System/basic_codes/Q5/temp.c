#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	printf("Execl Process: PID- %d, PPID- %d\n",getpid(),getppid());
	
	while(1);
	
	return 0;
}

