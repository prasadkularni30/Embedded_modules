#include<stdio.h>
#include<stdlib.h>

struct node{
	int x;
	struct node *next;
};


void insert_at_end(struct node **,int);
void insert_at_beg(struct node **,int);
void display(struct node **);
void delete_at_end(struct node **);
void delete_at_beg(struct node **);

int main()
{
	int choice,ele;
	struct node *head;
	struct node *t;

	head=NULL;

	if (head==NULL)
	{
		printf("linkedlist is empty\n");
	}
	else{
		printf("linked is not empty\n");
	}
	while(1)
	{

	printf("Enter choice:\n1: Insert at End \n2: Display \n3: Insert at Beg \n4: Detele at End\n5: Delete from beg\n0: Exit \n");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
			printf("Enter element\n");
			scanf("%d",&ele);
			insert_at_end(&head,ele);
			break;
		case 2:
			display(&head);
			break;
		case 3:
			printf("Enter element\n");
			scanf("%d",&ele);
			insert_at_beg(&head,ele);
			break;
		case 4:
			delete_at_end(&head);
			break;
		case 5:
			delete_at_beg(&head);
			break;
		case 0:
			while(head!=NULL)
			{	
				t=head;
				head=t->next;
				t->next=NULL;
				free(t);
				t=NULL;
			}
			exit(0);
		default:
			printf("Invalid Choice\n");
			break;
	}

	}

}

void display(struct node **head)
{
	printf("----------------------------------------------------------------------------------------\n");
	int i=1;
	struct node *t1=*head;

	if (t1==NULL)
	{
		printf("linkedlist is empty\n");
	}
	else{
		printf("linked is not empty\n");
	}

	while(t1!=NULL)
	{
		printf("%dst element= %d\n",i,t1->x);

		t1=t1->next;

		i++;
	}
	printf("----------------------------------------------------------------------------------------\n");
}

void insert_at_beg(struct node **head,int ele)
{
	struct node *temp;

	temp=(struct node *)malloc(sizeof(struct node));

	temp->x=ele;
	temp->next=NULL;

	if(head==NULL)
	{
		*head=temp;
	}
	else{
		temp->next=*head;
		*head=temp;
	}
}

void insert_at_end(struct node **head, int ele)
{
	struct node *temp;
	struct node *t1=*head;

	temp=(struct node *)malloc(sizeof(struct node));

	temp->x=ele;
	temp->next=NULL;

	if(*head==NULL)
	{
		*head=temp;
	}else{
		while(t1->next!=NULL)
		{
			t1=t1->next;
		}
		t1->next=temp;
	}
}

void delete_at_end(struct node **head)
{
	struct node *t1,*t2;
	t1=*head;

	while(t1->next!=NULL)
	{
		t2=t1;
		t1=t1->next;
	}
	free(t1);
	t2->next=NULL;
}

void delete_at_beg(struct node **head)
{
	struct node *t1=*head;

	*head=t1->next;
	t1->next=NULL;
	free(t1);
}

