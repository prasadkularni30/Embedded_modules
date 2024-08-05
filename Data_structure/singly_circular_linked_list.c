/*
Q1. Write a C/C++ program to implement single circular linked list
with below metioned functionality.
a) insertAtEnd b) insertAtBeg c) insertAtPos
d) display e) listNodeCount f) deleteFromEnd
g) deleteFromBeg h) deleteFromPos
*/

#include<stdio.h>
#include <stdlib.h>


struct node{
	int data;
	struct node *next;
	};
	
void insert_at_beg(struct node **);
void insert_at_end(struct node **);
void display(struct node *);
void insert_at_pos(struct node **);
void delete_from_pos(struct node **);
void delete_from_beg(struct node **);
void delete_from_end(struct node **);
int list_node_count(struct node *);

int count=0;

int main()
{
	struct node *head,*t;
	int choice,kount;
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
		printf("Enter choice:\n(0)Exit\n(1)Insert at beg\n(2)Insert at end\n(3)display at end\n(4)Insert at pos\n(5)Delete from position\n(6)Delete from beg\n(7)delete from end\n(8)count node\n");
		scanf("%d",&choice);
		
		switch(choice){
		
		case 0:
			while(t!=NULL)
			{
				t=head->next;
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
		case 8:
			kount=list_node_count(head);
			printf("Count : %d",kount);
		default:
			printf("Invalid Choice\n");
			break;
		
		}
	}
	
}


void insert_at_beg(struct node **h)
{
	struct node *temp,*t;
	t=*h;
	
	
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter Element: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	
	if(*h==NULL)
	{
		*h=temp;
		(*h)->next=*h;	
		count++;
	}
	else
	{
		while(t->next!=*h)
		{
			t=t->next;
		}
		temp->next=*h;
		*h=temp;
		t->next=temp;
		count++;
	}
}

void insert_at_end(struct node **h)
{
	struct node *temp,*t;
	t=*h;
	
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter Element: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	
	if(*h==NULL)
	{
		*h=temp;
		temp->next=temp;	
		count++;
	}
	else
	{
		while(t->next!=*h)
		{
			t=t->next;
		}
		t->next=temp;
		temp->next=*h;
		count++;
	}
}
void display(struct node *h)
{
	struct node *t;
	t=h->next;
	if(h==NULL)
	{
		printf("Linklist empty\n");
		return;
	}
	printf("-->%d",h->data);
	while(t!=h)
	{
		printf("-->%d",t->data);
		t=t->next;
	}
	printf("\n");
}
void insert_at_pos(struct node **h)
{
	int pos,i=1;
	struct node *temp,*t;
	t=*h;
	
	if(*h==NULL)
	{
		printf("No lisklist\n");
		return;
	}
	
	do
	{
		printf("Enter Position: ");
		scanf("%d",&pos);
	
		if(pos<1 || pos>count)
		{
			printf("Invalid position\nTotal linkList nodes are %d\n",count);
		
		}
	}while(pos<1 || pos>(count+1));
	
	if(pos==1)
	{
		insert_at_beg(h);
		return;
	}
	else if(pos==(count+1))
	{
		insert_at_end(h);
		return;
	}
	
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter Element: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	
	//printf("Count=%d",count);
	
	
	
	while(i<(pos-1))
	{
		t=t->next;
		i++;	
	}
	temp->next=t->next;
	t->next=temp;
	count++;
	
}
void delete_from_pos(struct node **h)
{
	struct node *t1,*t2;
	t1=*h;
	int pos,i=1;
	
	if(*h==NULL)
	{
		printf("No lisklist\n");
		return;
	}
	
	do
	{
		printf("Enter Position: ");
		scanf("%d",&pos);
	
		if(pos<1 || pos>count)
		{
			printf("Invalid position\nTotal linkList nodes are %d\n",count);
		
		}
	}while(pos<1 || pos>count);
	
	if(pos==1)
	{
		delete_from_beg(h);
		return;
	}
	else if(pos==count)
	{
		delete_from_end(h);
		return;
	}
	
	while(i<pos)
	{
		t2=t1;
		t1=t1->next;
		i++;	
	}
	t2->next=t1->next;
	free(t1);
	count--;
	
	
}

void delete_from_beg(struct node **h)
{
	struct node *t1,*t2;
	
	if(*h==NULL)
	{
		printf("No lisklist\n");
		return;
	}
	
	t1=*h;
	if(t1->next==*h)
	{
		free(*h);
		*h=NULL;
		count--;
	}
	else
	{
		while(t1->next!=*h)
		{
			t1=t1->next;
		}
	
		t2=(*h)->next;
		free(*h);
		*h=t2;
		t1->next=*h;
		count--;
	}
	
}

void delete_from_end(struct node **h)
{
	struct node *t1,*t2;
	t1=*h;
	if(*h==NULL)
	{
		printf("No lisklist\n");
		return;
	}
	
	if((*h)->next==*h)
	{
		free(*h);
		*h=NULL;
		count--;
		return;
	}
	
	while(t1->next!=*h)
	{
		t2=t1;
		t1=t1->next;
	}
	
	t2->next=*h;
	free(t1);
	count--;
}

int list_node_count(struct node *h)
{
	struct node *t;
	if(h==NULL)
	{
		printf("linklist empty\n");
		return 0;
	}
	t=h->next;
	int i=1;
	while(t!=h)
	{
		i++;
		t=t->next;
	}
	
	return i;
}
