/*
Q1: Implement a hotel portal with menu-driven singly linked list with the following options to the user:   
•	Following data should be taken as input from the user
o	Name
o	Id Number
o	Date of check-in (in DD:MM:YYYY)
o	Time of check-in (24-hour format)
•	Implement add_visitor, search, show all, delete and exit a given visitor data from the list.
•	Implement an add_visitor(…) function along with other functions, which should take the input from user and store the node in sorted manner in the list based on time of their checking-in.
•	Make sure there should be no duplicate ID number entry in the list.
•	Implement a counter on the menu page to show how many of visitors are currently present in the list.
•	Code implementation should be neat and logic should be clear, time and space complexity are to be taken into consideration as well.
*/

#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include<stdlib.h>


typedef struct hotel_portal{
	
	char *name;
	int ID;
	struct {
		int dd;
		int mm;
		int yy;
	}day;
	
	struct {
		int hh;
		int mm;
	}time;
	
	struct hotel_portal *next;
	
}portal;

void add(portal **);
void search(portal *);
void display(portal *);
void delete(portal **);
int count(portal *);


int main()
{
	int choice,counter;
	portal *head,*t;
	head=NULL;
	
	if(head!=NULL)
	{
		printf("Head not null\n");
		exit(0);
	}
	
	while(1)
	{
		printf("=========================================================\n");
		counter=count(head);
		printf("Current Visitor count: %d\n",counter);
		printf("=========================================================\n");
		
		printf("[1] Add Visitor\n[2] Search\n[3] Show all\n[4] Delete\n[0] Exit\n");
		printf("Enter Choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				add(&head);
				break;
			case 2:
				search(head);
				break;
			case 3:
				display(head);
				break;
			case 4:
				delete(&head);
				break;
			case 0:
				t=head;
				while(t!=NULL)
				{
					t=head->next;
					free(head->name);
					free(head);
					head=t;
				}
				exit(0);
		}
	}
}

void add(portal **h)
{
	printf("=========================================================\n");
	char buff[30];
	portal *temp=NULL,*t1;
	int flag;

	temp=(portal *)malloc(sizeof(portal));
	
	if(temp==NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}
	
	temp->next=NULL;
	
	
	printf("Enter Name: ");
	__fpurge(stdin);
	scanf("%[^\n]s",buff);
	__fpurge(stdin);
	int l=strlen(buff);
	
	temp->name=(char *)malloc(l+1);
	strcpy(temp->name,buff);
	
	do{
		printf("Enter ID: ");
		scanf("%d",&temp->ID);
		__fpurge(stdin);
		
		t1=*h;
		flag=0;
		
		while(t1!=NULL)
		{
			if(temp->ID==t1->ID)
			{
				printf("ID exists\n");
				flag=1;
				break;
			}
			t1=t1->next;
		}
		
	}while(flag==1);
	
	do{
	
		flag=0;
		
		printf("Enter Year: \n");
		scanf("%d",&temp->day.yy);
		__fpurge(stdin);
		printf("Enter Month: \n");
		scanf("%d",&temp->day.mm);
		__fpurge(stdin);
		printf("Enter Date: \n");
		scanf("%d",&temp->day.dd);
		__fpurge(stdin);
		
		if((temp->day.mm > 12) || (temp->day.dd > 31))
		{
			printf("Invalid Date\n");
			flag=1;
		}
	
	}while(flag==1);
	
	do
	{
		flag=0;
		
		printf("Enter Time \nHour: \n");
		scanf("%d",&temp->time.hh);
		__fpurge(stdin);
		printf("Minutes: \n");
		scanf("%d",&temp->time.mm);
		__fpurge(stdin);
		
		if((temp->time.hh > 24) || (temp->time.mm > 60))
		{
			printf("Invalid Time\n");
			flag=1;
			printf("2hii");
		}
	printf("1hii");
	
	}while(flag==1);
	//printf("hii");
	//long int temp_sum=temp->day.yy+temp->day.mm+temp->day.dd;
	//int sum;
	if(*h==NULL)
	{
		*h=temp;
	}
	else
	{
		//sum=(((*h)->day.yy)*100)+(((*h)->day.mm)*100)+(*h)->day.dd;
		if( temp->time.hh<(*h)->time.hh )
		{
			temp->next=*h;
			*h=temp;
		}
		else
		{
			//t1=(*h)->next;
			//sum=t1->day.yy+t1->day.mm+t1->day.dd;
			t1=(*h);
			while((t1->next!=NULL) && ( temp->time.hh > t1->next->time.hh ))
			{
				t1=t1->next;
				//sum=t1->day.yy+t1->day.mm+t1->day.dd;
			}
			if(t1->next==NULL)
			{	
				t1->next=temp;
			}
			else if (temp->time.hh == t1->next->time.hh )
			{
				if(temp->time.mm > t1->next->time.mm)
				{
					t1=t1->next;
				}
				temp->next=t1->next;
				t1->next=temp;
			}
			else
			{
				temp->next=t1->next;
				t1->next=temp;
			}
		}
		
	}
	printf("=========================================================\n");
}

void search(portal *h)
{
	portal *t=h;
	int id;
	printf("=========================================================\n");
	
	if(h==NULL)
	{
		printf("No Database\n");
		return;
	}
	
	
	printf("Enter ID: ");
	scanf("%d",&id);
	
	while(t!=NULL)
	{
		if(id==t->ID)
		{
			printf("================\n");
			printf("ID: %d\n",t->ID);
			printf("Name: %s\n",t->name);
			printf("Date: %d:%d:%d\n",t->day.dd,t->day.mm,t->day.yy);
			printf("Time: %d:%d\n",t->time.hh,t->time.mm);
			break;
		}
		t=t->next;
	}
	
	printf("=========================================================\n");
}
void display(portal *h)
{
	portal *t=h;
	
	printf("=========================================================\n");
	
	
	if(h==NULL)
	{
		printf("No Database\n");
		return;
	}
	
	while(t!=NULL)
	{
		
		printf("================\n");
		printf("ID: %d\n",t->ID);
		printf("Name: %s\n",t->name);
		printf("Date: %d:%d:%d\n",t->day.dd,t->day.mm,t->day.yy);
		printf("Time: %d:%d\n",t->time.hh,t->time.mm);
		
		t=t->next;
	}
	
	printf("=========================================================\n");
	
}
void delete(portal **h)
{
	portal *t1=*h,*t2;
	int id;
	printf("=========================================================\n");
	
	if(*h==NULL)
	{
		printf("No Database\n");
		return;
	}
	printf("Enter ID: ");
	scanf("%d",&id);
	
	
	if(((*h)->next==NULL) && (id==(*h)->ID))
	{
		//printf("1\n");
		free(*h);
		*h=NULL;
	}
	else if(id==(*h)->ID)
	{	
		//printf("2\n");
		t1=(*h)->next;
		free(*h);
		*h=t1;
	}
	else
	{
		while(t1!=NULL && (id!=t1->ID))
		{
			//printf("3\n");
			t2=t1;
			t1=t1->next;
		}
		//printf("4\n");			
		t2->next=t1->next;
		free(t1);
	}
	printf("=========================================================\n");
	
}

int count(portal *h)
{
	portal *t=h;
	if(h==NULL)
		return 0;
		
	int count=0;
	while(t!=NULL)
	{
		count++;
		t=t->next;
	}
	return count;
}
