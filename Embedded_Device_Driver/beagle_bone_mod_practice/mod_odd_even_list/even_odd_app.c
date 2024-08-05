#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/ioctl.h> 

#include "my_ioctl.h"

#define EVEN_LEN_PATH	"/sys/module/mod_odd_even_list/parameters/even_count"
#define ODD_LEN_PATH	"/sys/module/mod_odd_even_list/parameters/odd_count"
#define DEV_PATH	"/dev/even_odd_dev"


int get_count(int );

int main()
{
	int fd = open(DEV_PATH, O_RDWR); 
	if(fd < 0) 
	{
		printf("Could Not Open Device\n");
		exit(0);
	}

	int choice; 
	int number,ans; 
	int count=0;

	int *List_data = NULL; // To display pointer
	
	while(1)
	{
		printf("[1] Add to List \n[2] Display even List in Dmesg \n[3] Display ODD List in Dmesg \n[4] get even List \n[5] get ODD List \n[6] Delete even list \n[7] Delete ODD list \n[0] Exit\n");

		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("Enter Number: ");
				scanf("%d", &number);
				if( write(fd, &number, sizeof(number)) < 0)
				{
					printf("Failed to Write\n");
				}
				break;
			case 2:
				if( ioctl(fd, DISPLAY_EVEN, NULL) < 0)
				{
					printf("Display failed\n");
				}
				break;
			case 3:
				if( ioctl(fd, DISPLAY_ODD, NULL) < 0)
				{
					printf("Display failed\n");
				}
				break;
			case 4:
				count = get_count(1); 
				printf("Even List Node count: %d\n", count);

				if(count != -1) // If got count's value then only print it otherwise not
				{
					if(List_data == NULL) //If not allocated memory yet
					{
						List_data = (int*)malloc(sizeof(int)*count); // allocate
					}
					else // If already allocated memory
					{
						List_data = (int*)realloc(List_data, sizeof(int)*count);
					}
					ans = ioctl(fd, GET_EVEN,(unsigned int *)List_data);
					if (ans<0)
					{
						perror("IOCTL odd data read failure");
						close(fd);
						free(List_data);
						exit(EXIT_FAILURE);
					}
					
					printf("Even List:\n");
					for(int i = 0; i<count; ++i) //print the list
					{
						printf("Node [%d]: %d \n",i+1, List_data[i]);
					}
					printf("\n");
				}
				break;
			case 5:
				count = get_count(2); 
				printf("Odd List Node count: %d\n", count);

				if(count != -1) // If got count's value then only print it otherwise not
				{
					if(List_data == NULL) //If not allocated memory yet
					{
						List_data = (int*)malloc(sizeof(int)*count); // allocate
					}
					else // If already allocated memory
					{
						List_data = (int*)realloc(List_data, sizeof(int)*count);
					}
					ans = ioctl(fd, GET_ODD,(unsigned int *)List_data);
					if (ans<0)
					{
						perror("IOCTL odd data read failure");
						close(fd);
						free(List_data);
						exit(EXIT_FAILURE);
					}
					
					printf("Odd List:\n");
					for(int i = 0; i<count; ++i) //print the list
					{
						printf("Node [%d]: %d \n",i+1, List_data[i]);
					}
					printf("\n");
				}
				break;
			case 6:
				ans = ioctl(fd, DELETE_EVEN, NULL);
				if (ans<0)
				{
					perror("IOCTL read failure");
					close(fd);
					if(List_data!=NULL) 
					{
						free(List_data);
					}
					exit(EXIT_FAILURE);
				}
				break;
			case 7:
				ans = ioctl(fd, DELETE_ODD, NULL);
				if (ans<0)
				{
					perror("IOCTL read failure");
					close(fd);
					if(List_data!=NULL) 
					{
						free(List_data);
					}
					exit(EXIT_FAILURE);
				}
				break;
			case 0: 
				ans = ioctl(fd, DELETE_EVEN, NULL);
				if (ans<0)
				{
					perror("IOCTL read failure");
					close(fd);
					if(List_data!=NULL) 
					{
						free(List_data);
					}
					exit(EXIT_FAILURE);
				}
				ans = ioctl(fd, DELETE_ODD, NULL);
				if (ans<0)
				{
					perror("IOCTL read failure");
					close(fd);
					if(List_data!=NULL) 
					{
						free(List_data);
					}
					exit(EXIT_FAILURE);
				}
				if(List_data!=NULL) 
				{
					free(List_data);
				}
				close(fd); 
				exit(0);
				break;
		}
	}
	return 0;
}


int get_count(int x)
{
	int len;
	FILE *cound_d;
	if(x==1)
	{
		cound_d=fopen(EVEN_LEN_PATH, "r"); 
		if(cound_d == NULL)
		{
			printf("Could not get counts\n");
			return -1;
		}
	}
	else
	{
		cound_d=fopen(ODD_LEN_PATH, "r"); 
		if(cound_d == NULL)
		{
			printf("Could not get counts\n");
			return -1;
		}
	}
	fscanf(cound_d, "%d\n", &len);
	fclose(cound_d);
	
	return len;
}
