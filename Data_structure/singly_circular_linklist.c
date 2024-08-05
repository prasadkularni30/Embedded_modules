#include<stdio.h>

struct node{
	int data;
	struct node *next;
	}
	
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


void insert_at_beg(struct node **h)
{
	struct node *temp;
	
	temp=(struct node *)malloc(sizeof(struct node));
	scanf("%d",temp->data);
	
