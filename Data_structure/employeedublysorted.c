#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>

struct node
{
	int empid;
	char name[20];
	char gen;
	char desgn[10];
	struct node *prev;
	struct node *next; 
};

int count=0;

void add(struct node **);
void modify(struct node **);
void display(struct node *);
void search(struct node*);
void deleteall(struct node **);

int main()
{
	struct node *head=NULL;
	int choice;
	
       while(1)
       {
	       printf("\nEnter the choice\n 1.Add\n 2.Search\n 3.Modify\n 4.Dsiplay\n 5.Delete\n 0.Exit\n");
		__fpurge(stdin);
	       scanf("%d",&choice);
	       printf("\ncurrent employees count:%d\n",count);
	       switch(choice)
	       {
		       case 1:
			       add(&head);
			       break;
		       case 2:
			       search(head);
			       break;
		       case 3:
			       modify(&head);
			       break;
		       case 4:
			       display(head);
			       break;
		       case 5:
			       deleteall(&head);
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
	struct node *t1;
	t1=*p;
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node ));
	do{
	printf("enter the empid:\n");
	__fpurge(stdin);
	scanf("%d",&(temp->empid));
	}while((temp->empid)>9999 || (temp->empid)<999);
	__fpurge(stdin);
	printf("enter the employee name:\n");
	scanf("%[^\n]s",(temp->name));
	__fpurge(stdin);
	printf("enter the gen(either F or M):\n");
	__fpurge(stdin);
	scanf("%c",&(temp->gen));
	__fpurge(stdin);
	printf("enter the designation:\n");
	scanf("%[^\n]s",(temp->desgn));
	__fpurge(stdin);
	temp->prev=NULL;
	temp->next=NULL;
	if(*p==NULL)
	{
		*p=temp;
	}else
	{
		if((temp->empid)<(t1->empid)){
			temp->next=t1;
			t1->prev=temp;
			*p=temp;
		}else
		{
			while((t1->next!=NULL)&&((temp->empid)>(t1->next->empid)))
			{
				t1=t1->next;
			}
			if(t1->next==NULL)
			{
				t1->next=temp;
				temp->prev=t1;
			}
			else
			{
				temp->prev=t1;
				temp->next=t1->next;
				t1->next->prev=temp;
				t1->next=temp;
			}
		}
	}
	count++;
}
void display(struct node *p)
{
	struct node *t1;
	t1=p;
	if(p==NULL)
	{
		printf("\nEmployee database is empty\n");
		return;
	}
	while(t1!=NULL)
	{
		printf("employee id:%d\n",t1->empid);
		printf("employee name:%s\n",t1->name);
		printf("employee gender:%c\n",t1->gen);
		printf("employee designation:%s\n",t1->desgn);
		t1=t1->next;
	}
}

void modify(struct node **p)
{
	int id;
	struct node *t1;
	t1=*p;
	printf("enter the employee id for search\n");
	scanf("%d",&id);

	while(t1!=NULL){
		if(t1->empid==id)
		{
			__fpurge(stdin);
			printf("enter the employee name:\n");
			scanf("%[^\n]s",(t1->name));
			__fpurge(stdin);
			printf("enter the gen(either F or M):\n");
			__fpurge(stdin);
			scanf("%c",&(t1->gen));
			__fpurge(stdin);
			printf("enter the designation:\n");
			scanf("%[^\n]s",(t1->desgn));
			__fpurge(stdin);
		}
		t1=t1->next;
	}
	printf("invalid id\n");
}

void search (struct node *p)
{
	int id;
	struct node *t1;
	t1=p;
	printf("Enter the id to be search\n");
	scanf("%d",&id);
	while(t1!=NULL)
	{
		if(t1->empid==id)
		{
			printf("employee id:%d\n",t1->empid);
			printf("employee name:%s\n",t1->name);
			printf("employee gender:%c\n",t1->gen);
			printf("employee designation:%s\n",t1->desgn);
		}
		t1=t1->next;
	}
	printf("invalid id for search\n");
}
void deleteall(struct node**p)
{
	struct node *t1;
	t1=*p;
	struct node *t2;
	while(t1!=NULL)
	{
		t2=t1;
		t1=t1->next;
		*p=t1;
		free(t2);
	}
	count=0;
}
