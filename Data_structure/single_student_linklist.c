/*
Q4. Write a C/C++ program to implement single linked list to store
Student Information ( StudentName and StudentPRN).
Implement below metioned functions. Apply all required condition
check & validation like list empty or not, while inserting/deleting by
position validate the position.
a)insertAtEnd b) insertAtBeg c) insertAtPos d) displayList
e)listNodeCount f) deleteFromEnd g) deleteFromBeg
h)deleteFromPos i) deleteByElement j) reverseDisplay
k)freeAllNode
*/


#include<stdio.h>
#include <stdlib.h>
#include <string.h>



struct student{

char *name;
int prn;
struct student *next;

};

void sorted_insert(struct student **);
void displayList(struct student *);
int listNodeCount(struct student *);
void deleteFromEnd(struct student **);
void deleteFromBeg(struct student **);
void deleteFromPos(struct student **);
void deleteByElement(struct student **);
void reverseDisplay(struct student *);
void freeAllNode(struct student **);


int main()
{
	int choice,count;
	struct student *head,*t;
	head=NULL;
	
	if(head!=NULL)
	{
		printf("Linkedlist is not Empty");
		exit(0);
	}
	
	while(1)
	{
		printf("Enter Choice: \n(1) Insert \n(2) displayList\n(3) listNodeCount\n(4) deleteFromEnd\n(5) deleteFromBeg\n(6) deleteFromPos\n(7) deleteByElement\n(8) reverseDisplay\n(9) freeAllNode\n(0)Exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				sorted_insert(&head);
				break;

			case 2:
				displayList(head);
				break;
			case 3:
				count=listNodeCount(head);
				printf("=============================================\n");
				printf("Total student count: %d\n",count);
				break;
			case 4:
				deleteFromEnd(head);
				break;
			case 5:
				deleteFromBeg(&head);
				break;
			case 6:
				deleteFromPos(&head);
				break;
			case 7:
				deleteByElement(&head);
				break;
			case 8:
				t=head;
				reverseDisplay(t);
				break;
			case 9:
				freeAllNode(&head);
				printf("Deleted all data\n");
				break;
			case 0:
				printf("\nExiting.....\n");
				freeAllNode(&head);
				exit(0);
			default:
				printf("Invalid choice\n");
				break;
		}
	}
}

void sorted_insert(struct student **h)
{
	char buff[20];
	
	struct student *temp,*t1;
	t1=*h;
	
	temp=(struct student *)malloc(sizeof(struct student));
	
	printf("Enter Name\n");
	scanf("%s",buff);
	
	int l=strlen(buff);
	temp->name=(char *)malloc(l+1);
	
	strcpy(temp->name,buff);
	
	printf("Enter PRN\n");
	scanf("%d",&temp->prn);
	
	
	temp->next=NULL;
	
	if(*h==NULL)
	{
		*h=temp;
	}
	else
	{
		if((temp->prn)<(t1->prn))
		{
			temp->next=*h;
			*h=temp;
		}
		else
		{
			while((t1->next!=NULL)&&((temp->prn)>(t1->next->prn)))
			{
				t1=t1->next;
			}
			
			if(t1->next==NULL)
			{
				t1->next=temp;
			}
			else
			{
				 temp->next=t1->next;
				 t1->next=temp;
			}
			
			
		}
	}
}


void displayList(struct student *h)
{
	struct student *temp=h;
	if(h==NULL)
	{
		printf("linklist is empty\n");
		return ;
	}
	while(temp!=NULL)
	{
		printf("=============================================\n");
		printf("Name: %s\n",temp->name);
		printf("PRN: %d\n",temp->prn);
		temp=temp->next;
	}
	
	printf("\n");
}


int listNodeCount(struct student *h)
{
	int count=0;
	struct student *temp=h;
	
	if(h==NULL)
	{
		printf("linklist is empty\n");
		return 0;
	}
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}

void deleteFromEnd(struct student **h)
{
	struct student *t1,*t2;
	t1=h;
	
	if(h==NULL)
	{
		printf("linklist is empty\n");
		return;
	}
	if((*h)->next==NULL)
	{
		free(head);
		head=NULL;
		return;
	}
	while(t1->next!=NULL)
	{
		t2=t1;
		t1=t1->next;
	}
	free(t1);
	t2->next=NULL;
}
void deleteFromBeg(struct student **h)
{
	struct student *t;
	
	if(*h==NULL)
	{
		printf("linklist is empty\n");
		return;
	}
	if((*h)->next==NULL)
	{
		free(head);
		head=NULL;
		return;
	}
	t=(*h)->next;
	free(*h);
	*h=t;
}
void deleteFromPos(struct student **h)
{
	struct student *t1,*t2;
	int pos,i=1,flag=0;
	
	t1=*h;
	
	if(*h==NULL)
	{
		printf("linklist is empty\n");
		return ;
	}
	int count=listNodeCount(*h);
	do
	{
	printf("Enter Position: ");
	scanf("%d",&pos);
	
		if(pos<1 && pos>count)
		{
			printf("Enter Valid Position\n");
			flag=1;
		}
	}while(flag=1);
	
	if(pos==count)
	{
		deleteFromEnd(*h);
		return;
	}
	else if(pos==1)
	{
		deleteFromBeg(h);
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
}
	
void deleteByElement(struct student **h)
{
	struct student *t1,*t2;
	int prn,i=1;
	
	t1=*h;
	
	printf("Enter PRN: ");
	scanf("%d",&prn);
	
	while(t1->prn!=prn && t1!=NULL)
	{
		t2=t1;
		t1=t1->next;
	}
	if(t1==NULL)
	{
		printf("Invalid PRN or PRN does not exist\n");
	}
	t2->next=t1->next;
	free(t1);
}
void reverseDisplay(struct student *t)
{
	
	if(t==NULL)
	{
		return;
	}
	
	reverseDisplay(t->next);
	printf("=============================================\n");
	printf("Name: %s\n",t->name);
	printf("PRN: %d\n",t->prn);
}


void freeAllNode(struct student **h)
{	struct student *t;

	while(*h!=NULL)
	{
		t=*h;
		*h=t->next;
		t->next=NULL;
		free(t->name);
		free(t);
		
	}
}


