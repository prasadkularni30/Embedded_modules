//LIBRARY dECLARATION

#include<stdio.h>
#include<stdio_ext.h>
#include <stdlib.h>
#include<string.h>

//defining size as 50
#define size 50


//structure declaraion and using typedef for structure and aming it portal
typedef struct
{
	char *name;
	char *f_name;
	int age;
	char ward;
	int id;
	long int aadhar;
	
}portal;


int count=-1;

//function declarations

void add(portal *);
int search(portal *);
void modify(portal *);
void display(portal *,int );


int main()
{
	//structure array initialisation
	portal data[size];	//declaring structure array of size(50)
	
	int choice,pos;
	
	while(1)
	{	//creating menu for user to choose
		printf("___________________________MENU___________________________\n");
		printf("[1] Add patient data\t[2] Find patient\t[3] Modify Data\t[4] Display\t[0] Exit\n");
		printf("Enter Choice: ");
		scanf("%d",&choice);
		
		
		switch(choice)
		{
			case 1:
				add(data);
				break;
			case 2:
				pos=search(data);
				if(pos>=0)	//if position is found displaying data
					display(data,pos);
				else		//else printing that user not found
					printf("Not Found\n");
				break;
			case 3:
				modify(data);
				break;
			case 4:
				for(int i=0;i<=count;i++)
					display(data, i);
				if(count==-1)
					printf("Database not created\n");
					
				break;
			case 0:
				for(int i=0;i<=count;i++)	//freeing dynamically allocated memory to Patient's name and father name 
				{
					free(data[i].name);
					free(data[i].f_name);
				}
				exit(0);	//exiting the program
			default:
				printf("Enter Valid Choice\n");
				break;
		}
	}
}

//function definations

void add(portal *data)
{
	printf("====================================================================\n");
	count++;
	int flag;
	char buff[30];
	do
	{
		printf("Enter Patient ID: ");
		scanf("%d",&data[count].id);
		__fpurge(stdin);
		flag=0;
		for(int i=0;i<count;i++)	//loop to check if new entered ID already exists or not
		{
			if(data[count].id==data[i].id)	//if id exists set the flag
			{
				printf("Patient ID Exists\n");
				flag=1;
			}
		}
		
	}while(flag==1);		//if flag is set take id input again
	
	printf("Enter Patient's First name: ");
	scanf("%s",buff);
	__fpurge(stdin);
	
	data[count].name=(char *)malloc(strlen(buff)+1);	//creating dynamic memory for the size of input buff and +1 for char'\0'
	strcpy(data[count].name,buff);	//using strcpy functiong to store the input from buff to dynamically allocated 							memory in name
	
	printf("Enter Patient's Father name: ");
	scanf("%s",buff);
	__fpurge(stdin);
	
	data[count].f_name=(char *)malloc(strlen(buff)+1);	//creating dynamic memory for the size of input buff and +1 for char'\0'
	strcpy(data[count].f_name,buff);	//using strcpy functiong to store the input from buff to dynamically allocated 							memory in name
	
	printf("Enter Patient age: ");
	scanf("%d",&data[count].age);
	__fpurge(stdin);
	
	while(1)
	{
		printf("Enter Patient Ward[A,B,C,D]: ");
		scanf("%c",&data[count].ward);
		__fpurge(stdin);
		//validation for use has given input is from mentioned ward or not 
		if(data[count].ward>='A' && data[count].ward<='D' || data[count].ward>='a' && data[count].ward<='d')
		{
			break;
		}
		printf("Invalid Ward\n");
	}
	
	while(1)
	{
		printf("Enter Patient Aadhar No: ");
		scanf("%ld",&data[count].aadhar);
		__fpurge(stdin);
		
		//validation for aadhar no if user input aadhar no is 12 digit or not
		if(data[count].aadhar>99999999999 && data[count].aadhar<1000000000000)
		{
			break;
		}
		printf("Invalid Aadhar no\n");
	}
	printf("\n");
	printf("====================================================================\n");
	
}
	
int search(portal *data)
{
	//if no input has given print Database empty and return to main
	if(count==-1)
	{
		printf("Database empty\n");
		return -1;
	}
	
	int id;
	
	printf("====================================================================\n");
	
	printf("Enter Patient ID: ");
	scanf("%d",&id);
	printf("SEARCHING.....\n");
	
	for(int i=0;i<=count;i++)	//loop for comparing user input id with all ids in array
	{
		if(id==data[i].id)	//if user id and id in databse is matched then break the loop
		{
			return i;	//here i has position of where id and all other data is stored 
		}
	}
	
	return -1;		//if no data found return -1 
}


void modify(portal *data)
{
	if(count==-1)
	{
		printf("Database not created\n");
		return;
	}
	
	int choice,flag;
	
	int pos=search(data);	//calling search function for search the position of patient's data with help of id and int pos will catch 				the return value from search fun(position)
	
	display(data,pos);	//displaying data to user for verification
	
	//menu for modification
	printf("___________________________MODIFICATION___________________________\n");
	printf("[1] Patient id\t[2] Patient age\t[3] Ward\t[0] Exit\n");
	printf("Enter Choice: ");
	scanf("%d",&choice);
	//taking user choice for modifitcation according to menu
	switch(choice)
	{
		case 1:
			do
			{
				printf("Enter Patient ID: ");
				scanf("%d",&data[pos].id);
				__fpurge(stdin);
				flag=0;
				for(int i=0;i<=count;i++)
				{
				// if i reached to same position as pos and the the id will be same because both are at same pos so to 						skip duplicate check that time
					if(i==pos)
					{ 
						continue;
					}
					
					if(data[pos].id==data[i].id)
					{
						printf("Patient ID Exists\n");
						flag=1;
					}
				}
			
				
			}while(flag==1);
			break;
		case 2:
			printf("Enter Patient age: ");
			scanf("%d",&data[pos].age);
			__fpurge(stdin);
			break;
		case 3:
			while(1)
			{
				printf("Enter Patient Ward[A,B,C,D]: ");
				scanf("%c",&data[pos].ward);
				__fpurge(stdin);
				
				if(data[pos].ward>='A' && data[pos].ward<='D' || data[pos].ward>='a' && data[pos].ward<='a')
				{
					break;
				}
				printf("Invalid Ward\n");
			}
			break;
		case 0:
			return;
		default:
			printf("Enter Valid Choice\n");
			break;
	}
}


//displaying all data according to i(here i holds position) 
void display(portal *data,int i)
{
	
	printf("------------------------------------------------\n");
	printf("Patient ID: %d\n",data[i].id);
	printf("Patient's Name: %s\n",data[i].name);
	printf("Patient's Father Name: %s\n",data[i].name);
	printf("Patient's age: %d\n",data[i].age);
	printf("Patient's Ward: %c\n",data[i].ward);
	printf("Patient's Aadhar no: %ld\n",data[i].aadhar);
	
	printf("\n");
	printf("------------------------------------------------\n");
	
	
}
