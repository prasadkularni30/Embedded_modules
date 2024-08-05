#include<stdio.h>
#include<stdio_ext.h>
#include <stdlib.h>

struct node {
	char *ownerName;
	char buildName;
	char flatNo[5];
	char *societyName;
	int pin;
	
	struct node *next;
};

int count=0;

void add(struct node **);
void display(struct node *);
void search(struct node *);
void delete(struct node **);

int main()
{
	struct node *head;
	head=NULL;
	int choice;
	while(1)
	{
		printf("\n---Menu---\n0:exit\n1:Add\n2:display\n3:search\n4:delete\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				add(&head);
				break;
			case 2:
				display(head);
				break;
			case 3:
				search(head);
				break;
			case 4:
				delete(&head);
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("invalid choice\n");
				break;
		}
	}
}

void add(struct node **p)
{
	struct node *temp;
	struct node *t1;
	t1=*p;
	temp=(struct node *)malloc(sizeof(struct node));
	__fpurge(stdin);
	printf("enter the owner name\n");
	scanf("%[^\n]s",temp->ownerName);

	__fpurge(stdin);
	printf("enter the building name\n");
	scanf("%c",temp->buildName);
	
	do
	{
	__fpurge(stdin);
	printf("Enter the flat number\n");
	scanf("%s",temp->flatNo);
	}while((temp->flatNo > 9999) || (temp->flatNo <999));

	__fpurge(stdin);
	printf("enter the society name\n");
	scanf("%[^\n]s",temp->societyName);

	do{
	__fpurge(stdin);
	printf("enter the pincode\n");
	scanf("%d",&(temp->pin));
	__fpurge(stdin);
	}while((temp->pin > 999999) || (temp->pin < 99999));
	
	temp->next=NULL;
	if(*p==NULL)
	{
		*p=temp;
	}
	else
	{
		while(t1->next!=NULL)
		{
			t1=t1->next;
		}
		t1->next=temp;
	}
	count++;
}
void display(struct node *p)
{
	struct node *t1;
	t1=p;
	while(t1!=NULL)
	{
		printf("owner name :%s\n",t1->ownerName);
		printf("building name:%s\n",t1->buildName);
		printf("flat Number:%d\n",t1->flatNo);
		printf("society name :%s\n",t1->societyName);
		printf("pincode :%d\n",t1->pin);
		t1=t1->next;
	}
}



void search(struct node *p)
{
	int n;
	struct node *t1;
	t1=p;
	printf("enter the flat number to search\n");
	scanf("%d",&n);
	while(t1!=NULL)
	{
		if(n==t1->flatNo)
		{
			printf("owner name :%s\n",t1->ownerName);
			printf("building name:%s\n",t1->buildName);
			printf("flat Number:%d\n",t1->flatNo);
			printf("society name :%s\n",t1->societyName);
			printf("pincode :%d\n",t1->pin);
		}
		t1=t1->next;
	}
}
void delete(struct node **p)
{
	int n;
	struct node *t1,*t2;
	t1=*p;
	printf("enter the flat number to search\n");
	scanf("%d",&n);
	while(t1!=NULL)
	{
		if(n==t1->flatNo)
		{
			*p=t1->next;
			free(t1);
			return;
		}
		while(t1!=NULL)
		{
			t2=t1;
			t1=t1->next;
			if(n==t1->flatNo){
				t2->next=t1->next;
				free(t1);
				return;
			}
		}
	}
}











