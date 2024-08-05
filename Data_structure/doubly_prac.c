#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

void insert_at_beg(struct node **);
void insert_at_end(struct node **);
void display(struct node *);
void insert_at_pos(struct node **);
void delete_from_pos(struct node **);
void delete_from_beg(struct node **);
void delete_from_end(struct node **);

int count=0;

int main()
{
	struct node *head,*t;
	int choice;
	head=NULL;
	
	
	if(head==NULL)
	{
		printf("Linklist is empty\n");
	}
	else
	{
		printf("Linklist is not empty\n");
		exit(0);
	}
	
	
	while(1)
	{
		printf("Enter choice:\n(0)Exit\n(1)Insert at beg\n(2)Insert at end\n(3)display at end\n(4)Insert at pos\n(5)Delete from position\n(6)Delete from beg\n(7)delete from end\n");
		scanf("%d",&choice);
		
		switch(choice){
		
		case 0:
			while(t!=NULL)
			{
				t=head->next;
				head->prev=NULL;
				head->next=NULL;
				free(head);
				head=t;
			}
			head=NULL;
			exit(0);
		case 1:
			insert_at_beg(&head);
			break;
		case 2:
			insert_at_end(&head);
			break;
		case 3:
			display(head);
			break;
		case 4:
			insert_at_pos(&head);
			break;
		case 5:
			delete_from_pos(&head);
			break;
		case 6:
			delete_from_beg(&head);
			break;
		case 7:
			delete_from_end(&head);
			break;
		default:
			printf("Invalid Choice\n");
			break;
		
		}
	}
	
}

void insert_at_beg(struct node **head)
{
	struct node *temp;
	
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter element: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	temp->prev=NULL;
	
	if(*head==NULL)
	{
		*head=temp;
	}
	else
	{
		temp->next=*head;
		*head=temp;
	}
	count++;
}
	
void insert_at_end(struct node **head)
{	
	struct node *temp;
	struct node *t;
	t=*head;
	
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter element: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	temp->prev=NULL;
	
	if(*head==NULL)
	{
		*head=temp;
	}
	else
	{
		while(t->next!=NULL)
		{
			t=t->next;
		}
		
		temp->prev=t;
		t->next=temp;
	}
	count++;
}
		
void display(struct node *head)
{
	struct node *t=head;
	while(t!=NULL)
	{	
		printf("-->%d",t->data);
		t=t->next;
	}
	printf("\n=================================================\n");
}

void insert_at_pos(struct node **head)
{
	struct node *temp,*t;
	int pos=0,i=1;
	t=*head;
	
	printf("Enter Position: ");
	scanf("%d",&pos);
	
	if(pos==1)
	{
		insert_at_beg(head);
	}
	else if(pos==count+1)
	{
		insert_at_end(head);
	}
	else
	{
		temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter Element :");
		scanf("%d",&temp->data);
		temp->prev=NULL;
		temp->next=NULL;
		
		while(i<pos-1)
		{
			t=t->next;
			i++;
		}
		temp->prev=t;
		temp->next=t->next;
		t->next->prev=temp;
		t->next=temp;
	
		count++;
	}
	
}


void delete_from_pos(struct node **h)
{
	struct node *t1,*t2;
	int pos,i=1;
	
	t1=*h;
	
	printf("Enter Position: ");
	scanf("%d",&pos);
	
	while(i<pos)
	{
		t2=t1;
		t1=t1->next;
		i++;
	}
	
	t2->next=t1->next;
	t1->next->prev=t2;
	free(t1);
	
	count--;
	
}

void delete_from_beg(struct node **h)
{
	struct node *t;
	t=*h;
	
	*h=t->next;
	(*h)->prev=NULL;
	free(t);
	count--;
	
}

void delete_from_end(struct node **h)
{
	struct node *t1,*t2;
	
	t1=*h;
	
	while(t1->next!=NULL)
	{
		t2=t1;
		t1=t1->next;
	}
	free(t1);
	t2->next=NULL;
	count--;
}
