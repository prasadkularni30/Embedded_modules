#include<stdio.h>		//library declarations
#include<stdio_ext.h>
#include <string.h>
#include <stdlib.h>

int i=0;

typedef struct library{			//defining and declaring structucture as lib.
	long int ISBN;
	char *title;
	char *author;
	char *genre;
	int q_avail;
}lib;

	//function declarations..
void add(lib *);		//fun add having ptr to struct as parameter and returning void
void display(lib *,int );	//fun display having ptr to struct and integer as parameter 
int search(lib *);		//fun search is a int function having ptr to struct as parameter and returning int
void update(lib *);		//fun update is a void function having ptr to struct as parameter
void delete(lib *);		//fun delete is a void function having ptr to struct as parameter

int main()
{
	int c, temp;
	lib arr[10];		//initializing structure array
	lib *ptr;		//assiging structure type ptinter to array of struct
	ptr=arr;
	
	while(1)		//until user choice is 0 program will run
	{
		//menu for user
		printf("------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("Welcome\nPlease Enter Choice\n1:  Add data \n2:  Display all\n3:  search and display\n4:  update data\n5:  delete data\n0:  Exit\n");
	scanf("%d",&c);
	
		//swtich function according to the choice of user
	switch(c)
		{
		case 1:
			add(ptr);		//if user choose 1 then it will jump to add function
			break;
		case 2:
			for(int j=0;j<i;j++)	//if user choose 2 then it will jump to DISPLAY function to display all data
			{
			display(ptr,j);
			}
			break;
		case 3:
			
			temp=search(ptr);	//if user choose 3 then it will jump to search function and display specific data
			break;
		case 4:
			update(ptr);		//if user choose 4 then it will jump to update function
			break;
		case 5: 
			delete(ptr);		//if user choose 5 then it will jump to delete function
			break;
		case 0:
			printf("---------Exiting...................");
			for(int j=0;j<i;j++)
			{
				free(ptr[j].title);		//making dynamically allocated memory free and NULL..
				free(ptr[j].author);
				free(ptr[j].genre);
				ptr[j].title=NULL;
				ptr[j].author=NULL;
				ptr[j].genre=NULL;
			}
			exit (0);		//if user choice is 0 program will end
		default:
			printf("Invalid Choice\n");
			break;
		}
	}
	
	return 0;
}	

void add(lib *a)
{
	//function to take data input
	printf("------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("Enter Data\n");
	
	char buff[20];		//buffer string
	
		
	printf("Enter ISBN: \n");
	scanf("%ld",&a[i].ISBN);
	
	printf("Enter Title: \n");
	scanf("%s",buff);
	
	a[i].title=(char *)malloc(sizeof(buff)+1);	//assigning buff string size to dynamic memory and copying data from buff to heap
	strcpy(a[i].title,buff);		
	
	printf("Enter author: \n");
	scanf("%s",buff);
	
	a[i].author=(char *)malloc(sizeof(buff)+1);	//reuse of buff string for assigning buff string size to dynamic memory and copying data from buff to heap
	strcpy(a[i].author,buff);
	
	printf("Enter Genre: \n");
	scanf("%s",buff);
	
	a[i].genre=(char *)malloc(sizeof(buff)+1); 	//reuse of buff string for assigning buff string size to dynamic memory and copying data from buff to heap
	strcpy(a[i].genre,buff);
	
	printf("Enter Quantity Available: \n");
	scanf("%d",&a[i].q_avail);
	
	i++;
}
void display(lib *a,int j)
{
	//function to display data
	printf("------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("Data display: \n");
	
	
	printf("ISBN:%ld \n",a[j].ISBN);

	
	printf("Title: %s\n",a[j].title);

	
	printf("Author:  %s\n",a[j].author);
	
	
	printf("Genre: %s\n",a[j].genre);
	
	
	printf("Quantity Available: %d\n",a[j].q_avail);
}


int search(lib *a)
{	
	//function to search and display specific data
	printf("------------------------------------------------------------------------------------------------------------------------------------\n");
	
	long int temp;
	int flag=0;
	
	
	printf("Search:\n Enter ISBN: ");
	scanf("%ld",&temp);
	
	for(int j=0;j<i;j++)	//comparing user given ISBN no with data storage
	{	
		if(temp==a[j].ISBN)
		{	
			display(a,j);	//if the ISBN num matched that specific data will be displayed
			flag=1;
			printf("------------------------------------------------------------------------------------------------------------------------------------\n");
			return j;	//return arr num of specific user
		}	
	
	}
	if(flag==0)
	{	
		printf("No Data found\n");
	}
	
}

void update(lib *a)
{
	printf("------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("Data update: \n");
	
	int temp,c;
	temp=search(a);		//to get ISBN number for the update with help of search fun
	char buff[20];
	
	
	printf("Enter Choice\n1:  Title\n2:  Quantity Available\n");		//for choice which data to update
	scanf("%d",&c);
	
	switch(c)
	{
		case 1:
			printf("Re-Enter Title: \n");
			scanf("%s",buff);

			strcpy(a[temp].title,buff);
			break;
		case 2:
			printf("Enter Quantity Available: \n");
			scanf("%d",&a[temp].q_avail);
			break;
		default:
			printf("Invalid Option\n");
			break;
	}
}

void delete(lib *a)
{
	printf("------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("Data deletation: \n");
	
	int temp,c;
	temp=search(a);		//to get ISBN number for the update with help of search fun
		
	for(;temp<i;temp++)
	{
		free(a[temp].title);		//making dynamically allocated memory free and NULL..
		free(a[temp].author);
		free(a[temp].genre);
		a[temp].title=NULL;
		a[temp].author=NULL;
		a[temp].genre=NULL;
		
		
		a[temp]=a[temp+1];		//removing data and assigning next data to previous value
	
	}
	
	/*free(a[temp].title);
	free(a[temp].author);
	free(a[temp].genre);
	a[temp].title=NULL;
	a[temp].author=NULL;
	a[temp].genre=NULL;*/

	i--;
}
