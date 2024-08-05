#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/ioctl.h> 
#include<stdio_ext.h>

#include "../Kernel/details.h"

#define	DEV_PATH "/dev/details_dev"



//struct details *r_dets;


char path[][10]={{"ab_count"},{"cd_count"},{"ef_count"},{"gh_count"},{"err_count"}};

char command[][5]={" ","AB","CD","EF","GH","ERR"};

void input(int );
void my_read (int);
void counter(int *);
void disp_dmesg(int );

int main()
{
	
	int fd = open(DEV_PATH, O_RDWR); 
	if(fd < 0) 
	{
		printf("Could Not Open Device\n");
		exit(0);
	}

	int choice;  


	
	while(1)
	{
		printf("---------------MENU---------------------\n");
		printf("[1] Add Data \n");
		printf("[2]Display in Dmesg \n");
		printf("[3] Delete All\n");
		printf("[4] Read AB\n");
		printf("[0] Exit\n");
		
		scanf("%d", &choice);
		__fpurge(stdin);

		switch(choice)
		{
			case 1:
				input(fd);
				break;
			case 2:
				disp_dmesg(fd);
				break;
			case 3:
				if( ioctl(fd, CLEANUP, NULL) < 0);
				{
					perror("Linked list cleanup failed\n");
				}
				break;
			case 4:
				my_read(fd);
				break;
			case 0: 
				if( ioctl(fd, CLEANUP, NULL) < 0);
				{
					perror("Linked list cleanup failed\n");
					close(fd);
					exit(EXIT_FAILURE);
				}
				close(fd); 
				exit(0);
				break;
		}
	}
	return 0;
}

void input(int fd)
{
	struct details dets;

	FILE *fp;

	fp=fopen("testcases.txt","r");
	if(fp==NULL)
	{
		printf("failed to open file\n");
		return ;
	}
	printf("Adding data\n");
	while((fscanf(fp,"%s %s %s\n",dets.name,dets.address,dets.id))!=EOF)
	{

		if( write(fd, &dets, sizeof(struct details)) < 0)
		{
			printf("Failed to Write\n");
		}

	}
	printf("Data added successfully\n");

	fclose(fp);

}

/*
void input(int fd)
{
	int i,size;
	printf("Enter size: ");
	scanf("%d",&size);

	for(i=0;i<size;i++)
	{
		printf("Enter Name: ");
		scanf("%[^\n]s", dets.name);
		__fpurge(stdin);

		printf("Enter Address: ");
		scanf("%[^\n]s", dets.address);
		__fpurge(stdin);

		printf("Enter National ID \nNote all characters in ID should be in Capital Letters\nEnter ID:");
		scanf("%[^\n]s", dets.id);
		__fpurge(stdin);
		
		//printf("name: %s\n"dets.name);
		//printf("address: %s\n"dets.address);
		//printf("id: %s\n"dets.id);

	}
}
*/


void disp_dmesg(int fd)
{
	int choice;
	char cmd[10];

	printf("Dsiplay in Dmesg\n");
	printf("[1] Display AB\n");
	printf("[2] Display CD\n");
	printf("[3] Display EF\n");
	printf("[4] Display GH\n");
	printf("[5] Display Error\n");
	printf("Enter Choice: ");
	scanf("%d",&choice);

//	sprintf(cmd,"DISP_%s",command[choice]);


	switch(choice)
	{
		case 1:
			if( ioctl(fd, DISP_AB, NULL) < 0)
			{
				printf("Display failed\n");
			}
			break;
		case 2:
			if( ioctl(fd, DISP_CD, NULL) < 0)
			{
				printf("Display failed\n");
			}
			break;
		case 3:
			if( ioctl(fd, DISP_EF, NULL) < 0)
			{
				printf("Display failed\n");
			}
			break;
		case 4:
			if( ioctl(fd, DISP_GH, NULL) < 0)
			{
				printf("Display failed\n");
			}
			break;
		case 5:
			if( ioctl(fd, DISP_ERR, NULL) < 0)
			{
				printf("Display failed\n");
			}
			break;
		default:
				printf("Invalid Choice\n");
				break;
	}


}

void my_read(int fd)
{
	int len[5]={0};
	int choice;
	struct details *List_data=NULL;
	char cmd[10];

	counter(len);

	printf("Ready List_data\n");
	printf("[1] Read AB\n");
	printf("[2] Read CD\n");
	printf("[3] Read EF\n");
	printf("[4] Read GH\n");
	printf("[5] Read Error\n");
	printf("Enter Choice: ");
	scanf("%d",&choice);


	if(len[choice-1]==0)
	{
		printf("No data in List\n");
		return ;
	}
	if(List_data == NULL) //If not allocated memory yet
	{
		List_data = (struct details *)malloc(sizeof(struct details)*len[choice-1]); // allocate
		if(List_data==NULL){ printf("Memory allocation failed\n"); return ;}
	}

//	sprintf(cmd,"READ_%s",command[choice]);

	switch(choice)
	{
		case 1:
			if( (ioctl(fd, READ_AB,(unsigned int *)List_data))<0)
			{
				perror("IOCTL odd data read failure");
				close(fd);
				free(List_data);
				exit(EXIT_FAILURE);
			}
			break;
		case 2:
			if( (ioctl(fd, READ_CD,(unsigned int *)List_data))<0)
			{
				perror("IOCTL odd data read failure");
				close(fd);
				free(List_data);
				exit(EXIT_FAILURE);
			}
			break;
		case 3:
			if( (ioctl(fd, READ_EF,(unsigned int *)List_data))<0)
			{
				perror("IOCTL odd data read failure");
				close(fd);
				free(List_data);
				exit(EXIT_FAILURE);
			}
			break;
		case 4:
			if( (ioctl(fd, READ_GH,(unsigned int *)List_data))<0)
			{
				perror("IOCTL odd data read failure");
				close(fd);
				free(List_data);
				exit(EXIT_FAILURE);
			}
			break;
		case 5:
			if( (ioctl(fd, READ_ERR,(unsigned int *)List_data))<0)
			{
				perror("IOCTL odd data read failure");
				close(fd);
				free(List_data);
				exit(EXIT_FAILURE);
			}
			break;
		default:
				printf("Invalid Choice\n");
				break;
	}
	printf("Displaying %s List:\n",command[choice]);
	for(int i = 0; i<len[choice-1]; ++i) //print the list
	{
		printf("node [%d]:\n",i+1);
		printf("name: %s\n",List_data[i].name);
		printf("address: %s\n",List_data[i].address);
		printf("id: %s\n",List_data[i].id);
	}
	printf("\n");

	free(List_data);
}

void counter(int *len)
{
	printf("lengths -> \n");
	int i;
	FILE *fd;
	char fpath[50];
	for(i=0;i<4;i++)
	{
		sprintf(fpath,"/sys/module/mod_details/parameters/%s",path[i]);
		fd=fopen(fpath,"r");

		fscanf(fd,"%d",&len[i]);

		printf("%d: %d\n",i,len[i]);

		fclose(fd);

	}

}
