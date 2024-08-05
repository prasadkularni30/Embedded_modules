/*
Q3. Write a C/C++ program to implement single linked list in sorted
order. Implement below metioned functions. Apply all required
condition check & validation like list empty or not, while
inserting/deleting by position validate the position. Implement a policy
for duplicate value input.
a)insert b) displayList c)listNodeCount d) deleteFromEnd
e) deleteFromBeg f)deleteFromPos g) reverseDisplay
*/

#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node *next;
};

int kount=0;

void sorted_input(struct node **);
void display(struct node *);
void delete_from_end(struct node **);
void delete_from_beg(struct node **);
void delete_from_pos(struct node **);
int list_node_count(struct node *);
void reverse_display(struct node *);

int main()
{
	struct node *head,*t;
	int choice,ret;
	
	head=NULL;
	if(head==NULL)
	{
		printf("linklist is empty\n");
	}
	else
	{
		printf("not empty\n");
		exit(0);
	}
	 
	while(1)
	{
		printf("\n0)Exit \n1)insert \n2) displayList \n3)listNodeCount \n4) deleteFromEnd \n5) deleteFromBeg \n6)deleteFromPos \n7) reverseDisplay\n");
		printf("Enter choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 0:
				while(t!=NULL)
				{
					t=h->next;
					h->next=NULL;
					free(h);
					h=t;
				}
				exit(0);
				
			case 1:
				sorted_input(&head);
				break;
			case 2:
				display(head);
				break;
			case 3:
				ret=list_node_count(head);
				printf("Node count is %d\n",ret);
				printf("node kount : %d",kount);
				break;
			case 4:
				delete_from_end(&head);
				break;
			case 5:
				delete_from_beg(&head);
				break;
			case 6:
				delete_from_pos(&head);
				break;
			case 7:
				reverse_display(head);
				break;
			default:
				printf("Invalid Input\n");
				break;
		}
	}
}

void sorted_input(struct node **h)
{
	struct node *temp,*t;
	int count=1,i=1;
	
	
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter element: ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	
	if(*h==NULL)
	{
		*h=temp;
		kount++;
	}
	else
	{
		if(temp->data < (*h)->data)
		{
			temp->next=*h;
			*h=temp;
			kount++;
		}
		else
		{
			t=(*h);
			while((temp->data>t->data) && (count< kount))
			{
				t=t->next;
				count++;
			}
			if(count==kount)
			{
				t->next=temp;
				kount++;
			}
			else
			{
				t=*h;
				while(i<count-1)
				{
					t=t->next;
					i++;
				}
				temp->next=t->next;
				t->next=temp;
				kount++;
			}
		}
	}
}

void display(struct node *head)
{
	struct node *t=head;
	
	while(t!=NULL)
	{
		printf("-->%d",t->data);
		t=t->next;
	}
	printf("\n");
}

int list_node_count(struct node *h)
{
	int count=0;
	while(h!=NULL)
	{
		count++;
		h=h->next;
	}
	
	return count;
}

void delete_from_end(struct node **h)
{
	struct node *t2,*t1=*h;
	
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
	kount--;
	
}

void delete_from_beg(struct node **h)
{
	struct node *t;
	
	if((*h)->next==NULL)
	{
		free(head);
		head=NULL;
		return;
	}
	t=(*h)->next;
	free(*h);
	*h=t;
	kount--;
	
}

void delete_from_pos(struct node **h)
{
	struct node *t2,*t1;
	t1=*h;
	t2=*h;
	int i=1;
	int pos;
	printf("enter the pos\n");
	scanf("%d",&pos);
	
	int count=list_node_count(*h);
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
	else if((pos>count)||(pos<1))
	{
		printf("Invalid Position\n");
		return;
	}
	else{
	
		while(i<pos)
		{
			t2=t1;
			t1=t1->next;
			i++;
		}
	
		t2->next=t1->next;
		free(t1);
		kount--;
	}
}

void reverse_display(struct node *t)
{
	if(t==NULL)
	{
		return;
	}
	
	reverse_display(t->next);
	printf("-->%d",t->data);
}
