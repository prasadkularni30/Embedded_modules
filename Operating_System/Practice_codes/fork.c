#include<stdio.h>  
#include <sys/types.h>
#include <unistd.h>



int main()
{       
        printf("Before fork\n");
        int ret=fork();
        printf("After fork ret: %d\n",ret);

        if(ret==0)
        {
                printf("In Child Process:  PID- %d, PPID- %d\n",getpid(),getppid());
                printf("In child ret: %d\n",ret);
                printf("Hello world\n");
                //return 0;
                //while(1);
        }
        else if(ret> 0)
        {       
                printf("In Parent Process:  PID- %d, PPID- %d\n",getpid(),getppid());
                while(1);
        }

        printf("Failed\n");
	return 0;

}   
