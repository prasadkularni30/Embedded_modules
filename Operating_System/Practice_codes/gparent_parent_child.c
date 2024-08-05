#include<stdio.h>  
#include <sys/types.h>
#include <unistd.h>



int main()
{       
       // printf("Before fork\n");
        int ret=fork();
	int ret1,ret2;
       // printf("After fork ret: %d\n",ret);

        if(ret==0)
        {
		 ret1= fork();
                 if(ret1==0)
                {
                        printf("In Child Process 2:  PID- %d, PPID- %d\n",getpid(),getppid());
	      //          while(1);
                }
                else if(ret1> 0)
                {
                        printf("In Parent Process (Child 1) of child 2:  PID- %d, PPID- %d\n",getpid(),getppid());
                //        while(1);
                }

                //printf("In Child Process 1:  PID- %d, PPID- %d\n",getpid(),getppid());
                //return 0;
                //while(1);
        }
        else if(ret> 0)
      	{
	         printf("In Parent Process of child 1:  PID- %d, PPID- %d\n",getpid(),getppid());	
          //      while(1);
        }

        //printf("Failed\n");
	return 0;

}  
