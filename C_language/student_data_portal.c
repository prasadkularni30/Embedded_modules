
#include<stdio.h>
#include<stdio_ext.h>
#include <stdlib.h>
#include <string.h>


int count=0;
int con=0;


typedef struct portal{
	struct student{
		char *name[3];
		int age; 
		int class;
		int rollnum;
		union{
			char aadhar[12];
			char passport[9];
			char dl[10];
		}id;
		int ID_choice;
		}stud;
	struct teacher{
		char *name[2];
		char *subject; 
		int age; 
		int j_year; 
		int regnum;
		union{
			char aadhar[12];
			char passport[9];
			char dl[10];
		}id;
		int ID_choice;
		}teach;
	
}data;

void input(data *);
void display_stud(data *,int );
void display_teach(data *,int );
void update_stud(data *);
void update_teach(data *);
int search_stud(data *);
int search_teach(data *);


int main(){

	int n,temp,t;
	data a, *port;
	
	port=(data *)malloc(sizeof(a)*4);
	
	while(1)
	{
		printf("1:\tData Input\n2:\tDisplay all\n3:\tSearch and display specific data\n4:\tModify user data\n0:\tExit\n");
		printf("Enter Choice:");
		scanf("%d",&temp);
		
		switch(temp){
			case 1:
				if(count<4 || con<4){
				input(port);
				printf("======================================================================\n");
				}
				else
				printf("you have entered all students data\n");
				break;
			case 2:
				printf("Enter Choice:\n1:\tStudent \n2:\tTeacher\n");
				scanf("%d",&t);
				if(t==1){
					for(int i=0;i<count;i++)
					display_stud(port,i);
					printf("======================================================================\n");
				}
				else if(t==2)
				{
					for(int i=0;i<con;i++)
					display_teach(port,i);
					printf("======================================================================\n");
				}
				else
				{
					printf("Invalid Entry\n");
				}
				break;
			case 3:
				printf("Enter Choice:\n1:\tStudent \n2:\tTeacher\n");
				scanf("%d",&t);
				if(t==1){
					search_stud(port);
					printf("======================================================================\n");
				}
				else if(t==2)
				{
					search_teach(port);
					printf("======================================================================\n");
				}
				else
				{
					printf("Invalid Entry\n");
				}
				break;
			case 4:
				printf("Enter Choice:\n1:\tStudent \n2:\tTeacher\n");
				scanf("%d",&t);
				if(t==1){
					update_stud(port);
					printf("======================================================================\n");
				}
				else if(t==2)
				{
					update_teach(port);
					printf("======================================================================\n");
				}
				else
				{
					printf("Invalid Entry\n");
				}
				break;
			case 0:
				for(int i=0;i<count;i++)
				{
					for(int j=0;j<3;j++)
					{
						free((port+i)->stud.name[j]);
					}
				}
				for(int i=0;i<con;i++)
				{
					for(int j=0;j<2;j++)
					{
						free((port+i)->teach.name[j]);
						free((port+i)->teach.subject);
						
					}
				}
				for(int i=0;(i< count || i< con);i++)
				{
					free(port+i);
				}
				exit(0);
			default:
				printf("Invalid Input\n");
				break;
				}
	}

}

void input(data *s)
{	
	char buff[20];
	int temp,i;
	printf("======================================================================\n");
	printf("Enter Choice:\n1:\tStudent \n2:\tTeacher\n");
	scanf("%d",&temp);
	
	if(temp==1)
	{
	printf("======================================================================\n");
	printf("Student Portal\n");
	
	//for(int k=0;k<3;k++)
	
	printf("\nEnter First name: ");
	__fpurge(stdin);
	scanf(" %s",buff);
	__fpurge(stdin);
	
	i=strlen(buff);
	(s+count)->stud.name[0]=(char *)malloc(sizeof(char)*i);
	strcpy((s+count)->stud.name[0],buff);
	
	printf("\nEnter Father's name: ");
	__fpurge(stdin);
	scanf(" %s",buff);
	__fpurge(stdin);
	
	i=strlen(buff);
	(s+count)->stud.name[1]=(char *)malloc(sizeof(char)*i);
	strcpy((s+count)->stud.name[1],buff);
	
	printf("\nEnter Surname: ");
	__fpurge(stdin);
	scanf(" %s",buff);
	__fpurge(stdin);
	
	i=strlen(buff);
	(s+count)->stud.name[2]=(char *)malloc(sizeof(char)*i);
	strcpy((s+count)->stud.name[2],buff);
	
	do{
	printf("Enter age(18-26): ");
	scanf("%d",&(s+count)->stud.age);
	__fpurge(stdin);
	
	if(18 > (s+count)->stud.age || (s+count)-> stud.age > 26)
	printf("Invalid\nage should be between 18-26\n");
	
	}while(18 > (s+count)->stud.age || (s+count)->stud.age > 26);
	
	do{
	printf("Enter student class(1-4): ");
	scanf("%d",&(s+count)->stud.class);
	__fpurge(stdin);
	
	if(1> (s+count)->stud.class || (s+count)->stud.class > 4)
	printf("Invalid Class\nClass are 1-4\n");
	
	}while(1> (s+count)->stud.class || (s+count)->stud.class > 4);
	
	do{
	printf("Enter student roll num(1-550): ");
	scanf("%d",&(s+count)->stud.rollnum);
	__fpurge(stdin);
	
	if(1>(s+count)->stud.rollnum || (s+count)->stud.rollnum >= 550)
	printf("Invalid Roll num\nRange is 0-550\n");
	
	}while(1>(s+count)->stud.rollnum || (s+count)->stud.rollnum >= 550);
	
	printf("Enter choice for Govt ID:\t 1. AadharCard\t 2. Passport\t 3. Driving Lisence : ");
	scanf("%d",&(s+count)->stud.ID_choice);
	__fpurge(stdin);

	switch((s+count)->stud.ID_choice){
		case 1:
			printf("Enter Aadhar Card Id: ");
			scanf("%s",(s+count)->stud.id.aadhar);
			__fpurge(stdin);
			break;
		case 2:
			printf("Enter Passport Id: ");
			scanf("%s",(s+count)->stud.id.passport);
			__fpurge(stdin);
			break;
		case 3:
			printf("Enter Driving Lisence: ");
			scanf("%s",(s+count)->stud.id.dl);
			__fpurge(stdin);
			break;
		default: 
			printf("Invalid option\n");
			break;
		}

	count++;
	printf("======================================================================\n");
	}
	
	
	else if(temp==2)
	{
	printf("======================================================================\n");
	printf("Teacher Portal\n");
	
	//for(int k=0;k<3;k++)
	
	printf("\nEnter First name: ");
	__fpurge(stdin);
	scanf(" %s",buff);
	__fpurge(stdin);
	
	i=strlen(buff);
	(s+con)->teach.name[0]=(char *)malloc(sizeof(char)*i);
	strcpy((s+con)->teach.name[0],buff);
	
	printf("\nEnter Surname: ");
	__fpurge(stdin);
	scanf(" %s",buff);
	__fpurge(stdin);
	
	i=strlen(buff);
	(s+con)->teach.name[1]=(char *)malloc(sizeof(char)*i);
	strcpy((s+con)->teach.name[1],buff);
	
	printf("\nEnter Subject: ");
	__fpurge(stdin);
	scanf(" %s",buff);
	__fpurge(stdin);
	
	i=strlen(buff);
	(s+con)->teach.subject=(char *)malloc(sizeof(char)*i);
	strcpy((s+con)->teach.subject,buff);
	
	
	do{
	printf("Enter age(35-60): ");
	scanf("%d",&(s+con)->teach.age);
	__fpurge(stdin);
	
	if(35 > (s+con)->teach.age || (s+con)->teach.age > 60)
	printf("Invalid\nage should be between 35-60\n");
	
	}while(35 > (s+con)->teach.age || (s+con)->teach.age > 60);
	
	
	printf("Enter Year of joining: ");
	scanf("%d",&(s+con)->teach.j_year);
	__fpurge(stdin);
	
	do{
	printf("Enter Registration No(1-50): ");
	scanf("%d",&(s+con)->teach.regnum);
	__fpurge(stdin);
	if(1> (s+con)->teach.regnum || (s+con)->teach.regnum > 50)
	printf("Invalid\nReg num should be between 1-50\n");
	
	}while(1 > (s+con)->teach.regnum || (s+con)->teach.regnum > 50);
	
	
	
	printf("Enter choice for Govt ID:\t 1. AadharCard\t 2. Passport\t 3. Driving Lisence : ");
	scanf("%d",&(s+con)->teach.ID_choice);
	__fpurge(stdin);

	switch((s+con)->teach.ID_choice){
		case 1:
			printf("Enter Aadhar Card Id: ");
			scanf("%s",(s+con)->teach.id.aadhar);
			__fpurge(stdin);
			break;
		case 2:
			printf("Enter Passport Id: ");
			scanf("%s",(s+con)->teach.id.passport);
		__fpurge(stdin);
			break;
		case 3:
			printf("Enter Driving Lisence: ");
			scanf("%s",(s+con)->teach.id.dl);
			__fpurge(stdin);
			break;
		default: 
			printf("Invalid option\n");
			break;
		}

	
	con++;
	}
		
}

void display_stud(data *s,int i)
{
	printf("======================================================================\n");
	printf("Student Roll no: %d\n",(s+i)->stud.rollnum);
	printf("Student Name: ");
	for(int k=0;k<3;k++)
	printf("%s\n",(s+i)->stud.name[k]);
	
	printf("Class: %d\n",(s+i)->stud.class );
	printf("Age: %d\n",(s+i)->stud.age);
	switch((s+i)->stud.ID_choice){
		case 1:
			printf("Aadhar Id: %s\n",(s+i)->stud.id.aadhar);
			break;
		case 2:
			printf("Passport No: %s\n",(s+i)->stud.id.passport);
			break;
		case 3:
			printf("Driving Lisence Id: %s\n",(s+i)->stud.id.dl);
			break;
		default:
			printf("Invalid Id\n");
			break;
		}
}

void display_teach(data *s,int i)
{
	printf("======================================================================\n");
	printf("Reg no: %d\n",(s+i)->teach.regnum);
	printf("Name: ");
	for(int k=0;k<2;k++)
	printf("%s\n",(s+i)->teach.name[k]);
	
	printf("%s\n",(s+i)->teach.subject);
	printf("Age: %d\n",(s+i)->teach.age);
	printf("Year of joining: %d\n",(s+i)->teach.j_year);
	
	switch((s+i)->teach.ID_choice){
		case 1:
			printf("Aadhar Id: %s\n",(s+i)->teach.id.aadhar);
			break;
		case 2:
			printf("Passport No: %s\n",(s+i)->teach.id.passport);
			break;
		case 3:
			printf("Driving Lisence Id: %s\n",(s+i)->teach.id.dl);
			break;
		default:
			printf("Invalid Id\n");
			break;
		}
}

int search_stud(data *s)
{	
	int temp,flag=0;
	printf("======================================================================\n");
	printf("Enter student roll no: ");
	scanf("%d",&temp);
	
	for(int i=0;i<count;i++)
	{
		if(temp==(s+i)->stud.rollnum)
		{
			flag=1;
			display_stud(s,i);
			return i;
		}
	}
	if(flag==0)
	{	
		printf("No Data match\n");
		printf("======================================================================\n");
	}
}

int search_teach(data *s)
{
	int temp,flag=0;
	printf("======================================================================\n");
	printf("Enter Reg No: ");
	scanf("%d",&temp);
	
	for(int i=0;i<con;i++)
	{
		if(temp==(s+i)->teach.regnum)
		{
			flag=1;
			display_teach(s,i);
			return i;
		}
	}
	if(flag==0)
	{	
		printf("No Data match\n");
		printf("======================================================================\n");
	}
}

void update_stud(data *s)
{	
	
	int i=search_stud(s);
	int n;
	char buff[20];
	printf("======================================================================\n");
	printf("Modification: \n1. Surname\n2. Age\n3. Class\n");
	printf("Enter choice: ");
	scanf("%d",&n);
	
	switch(n){
		case 1:
			printf("\nEnter Surname: ");
			__fpurge(stdin);
			scanf(" %s",buff);
			__fpurge(stdin);
			strcpy((s+i)->stud.name[2],buff);
			break;
		case 2:
			do{
				printf("Enter age(18-26): ");
				scanf("%d",&(s+i)->stud.age);
				__fpurge(stdin);
	
				if(18 > (s+i)->stud.age || (s+i)-> stud.age > 26)
				printf("Invalid\nage should be between 18-26\n");
	
			}while(18 > (s+i)->stud.age || (s+i)->stud.age > 26);
			break;
		case 3:
			do{
				printf("Enter student class(1-4): ");
				scanf("%d",&(s+i)->stud.class);
				__fpurge(stdin);
	
				if(1> (s+i)->stud.class || (s+i)->stud.class > 4)
				printf("Invalid Class\nClass are 1-4\n");
	
			}while(1> (s+i)->stud.class || (s+i)->stud.class > 4);
			break;
		default:
			printf("Invalid Choice");
			break;
		}
	printf("======================================================================\n");
}

void update_teach(data *s)
{	
	
	int i=search_teach(s);
	int n;
	char buff[20];
	printf("======================================================================\n");
	printf("Modification: \n1. Surname\n2. Age\n3. Joining Year\n");
	printf("Enter choice: ");
	scanf("%d",&n);
	
	switch(n){
		case 1:
			printf("\nEnter Surname: ");
			__fpurge(stdin);
			scanf(" %s",buff);
			__fpurge(stdin);
			strcpy((s+i)->teach.name[1],buff);
			break;
		case 2:
			do{
				printf("Enter age(35-60): ");
				scanf("%d",&(s+i)->teach.age);
				__fpurge(stdin);
	
				if(18 > (s+i)->teach.age || (s+i)-> teach.age > 26)
				printf("Invalid\nage should be between 18-26\n");
	
			}while(18 > (s+i)->teach.age || (s+i)->teach.age > 26);
			break;
		case 3:
			printf("Enter Year of joining: ");
			scanf("%d",&(s+i)->teach.j_year);
			__fpurge(stdin);			
			break;
		default:
			printf("Invalid Choice");
			break;
		}
	printf("======================================================================\n");
}
