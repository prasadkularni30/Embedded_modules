#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include <unistd.h>

void signal_handler();


int main()
{
	
	printf("Program Started\n");
	
	signal(SIGINT,signal_handler);
	
	printf("Waiting for signal SIGINT \n");
	//while(1);
	pause();

}

void signal_handler()
{
	printf("\nIn Signal Handler\n");
	
	exit(0);

}
