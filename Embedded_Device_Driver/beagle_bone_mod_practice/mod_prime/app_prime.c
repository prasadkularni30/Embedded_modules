#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/ioctl.h> 

#include "my_ioctl.h"

#define DEV_PATH	"/dev/prime_dev"


int get_count(int );

int main()
{
	int num;
	struct timeval t;

	int fd = open(DEV_PATH, O_RDWR); 
	if(fd < 0) 
	{
		printf("Could Not Open Device\n");
		exit(0);
	}
	gettimeofday(&t, NULL);

	printf("tv_sec: %ld, tv_usec: %ld\n",t.tv_sec,t.tv_usec);

	long srand_input = t.tv_sec % t.tv_usec;

	printf("srand input: %ld\n",srand_input);

	srand(srand_input);

	for(int i=0;i<100;i++)
	{
		num=rand();
		if( write(fd, &num, sizeof(num)) < 0)
		{
			printf("Failed to Write\n");
		}
	}
	
	if( ioctl(fd, DISPLAY, NULL) < 0)
	{
		printf("Display failed\n");
	}
	
}
