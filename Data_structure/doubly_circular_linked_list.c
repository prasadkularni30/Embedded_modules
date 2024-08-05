/*
Q3. Write a C/C++ program to implement doubly circular linked list
with below metioned functionality.
a) insertAtEnd b) insertAtBeg c) insertAtPos
d) display e) listNodeCount f) deleteFromEnd
g) deleteFromBeg h) deleteFromPos
*/

#include<stdio.h>
#include <stdlib.h>


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
			/*t=head;
			while(t!=NULL)
			{
				t=head->next;
				head->next=NULL;
				free(head);
				head=t;
			}*/
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
			printf("Count : %d\n",kount);
		default:
			printf("Invalid Choice\n");
			break;
		
		}
	}
	
}

void insert_at_beg(struct node **h)
{
	struct node *temp;
	
	
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter Element: ");
	scanf("%d",&temp->data);
	temp->prev=NULL;
	temp->next=NULL;
	
	if(*h==NULL)
	{
		*h=temp;
		temp->next=temp;
		temp->prev=temp;
		count++;
	}
	else
	{

		temp->next=*h;
		temp->prev=(*h)->prev;
		(*h)->prev->next=temp;
		(*h)->prev=temp;
		*h=temp;
		count++;
	}
}


void insert_at_end(struct node **h)
{
	struct node *temp;
	
	
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter Element: ");
	scanf("%d",&temp->data);
	temp->prev=NULL;
	temp->next=NULL;
	
	if(*h==NULL)
	{
		*h=temp;
		temp->next=temp;
		temp->prev=temp;
		count++;
	}
	else
	{

		temp->next=*h;
		temp->prev=(*h)->prev;
		(*h)->prev->next=temp;
		(*h)->prev=temp;
		count++;
	}
}
void display(struct node *h)
{
	struct node *t=h;
	if(h==NULL)
	{	
		printf("Linklist Empty\n");
		return;
	}
	do
	{
		printf("-->%d",t->data);
		t=t->next;
	}while(t!=h);
	printf("\n");
}
void insert_at_pos(struct node **h)
{
	struct node *temp,*t;
	t=*h;
	int pos,i=1;
	
	if(*h==NULL)
	{
		printf("Linked List is empty\n");
		return;
		
	}
	int kount=list_node_count(*h);
	do
	{
		printf("Enter Position: ");
		scanf("%d",&pos);
	
		if(pos<1 || pos>kount)
		{
			printf("Invalid position\nTotal linkList nodes are %d\n",kount);
		
		}
	}while(pos<1 || pos>(kount+1));
	
	if(pos==1)
	{
		insert_at_beg(h);
		return;
	}
	else if(pos==(kount+1))
	{
		insert_at_end(h);
		return;
	}
	
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter Element: ");
	scanf("%d",&temp->data);
	temp->prev=NULL;
	temp->next=NULL;
	
	
		while(i<(pos-1))
		{
			t=t->next;
			i++;
		}
		
		temp->next=t->next;
		t->next->prev=temp;
		temp->prev=t;
		t->next=temp;
		count++;
		
}
void delete_from_pos(struct node **h)
{
	struct node *t1=*h;
	struct node *t2;
	int i=1,pos;
	
	if(*h==NULL)
	{
		printf("No lisklist\n");
		return;
	}
	
	int kount=list_node_count(*h);
	do
	{
		printf("Enter Position: ");
		scanf("%d",&pos);
	
		if(pos<1 || pos>kount)
		{
			printf("Invalid position\nTotal linkList nodes are %d\n",kount);
		
		}
	}while(pos<1 || pos>kount);
	
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
	t1->next->prev=t2;
	t2->next=t1->next;
	free(t1);
	count--;
}
void delete_from_beg(struct node **h)
{
	struct node *t1 ;
	
	if(*h==NULL)
	{
		printf("No lisklist\n");
		return;
	}
	if((*h)->next==*h)
	{
		free(*h);
		*h=NULL;
		return;
	}
	t1=(*h)->next;
	t1->prev=(*h)->prev;
	(*h)->prev->next=t1;
	free(*h);
	*h=t1;
	
	
}
void delete_from_end(struct node **h)
{
	struct node *t1;
	
	if(*h==NULL)
	{
		printf("No lisklist\n");
		return;
	}
	if((*h)->next==*h)
	{
		free(*h);
		*h=NULL;
		return;
	}
	t1=(*h)->prev;
	
	t1->prev->next=*h;
	(*h)->prev=t1->prev;
	free(t1);
	
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
