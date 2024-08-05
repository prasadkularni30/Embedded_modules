/*
Q2. Write a C/C++ program to implement single linked list.
Implement below metioned functions. Apply all required condition
check & validation like list empty or not, while inserting/deleting by
position validate the position.
a)insertAtEnd b) insertAtBeg c) insertAtPos d) displayList
e)listNodeCount f) deleteFromEnd g) deleteFromBeg
h)deleteFromPos i) deleteByElement j) reverseDisplay
k)freeAllNode l) reverseList m)sortedList
*/

#include<stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};
	
struct node *head;
int kount=0;

void insert_at_end(int);
void insert_at_beg(int);
void insert_at_pos(int,int);
void display();
void list_node_count();
void delete_at_end();
void delete_at_beg();
void delete_from_pos(int);
void delete_by_element(int);
void sorted_list();
void reverse_list();
void free_all_node();
void reverse_display(struct node *);





int main()
{
	int choice,x,ind;
	struct node *t,*t1;

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

	printf("1: Insert at End \n2: Insert at Beg  \n3: Insert at positon  \n4: Display \n5: Count elements\n6: Detele at End\n7: Delete from beg\n8: Delete From Position\n9: Delete by element\n10: Reverse Display\n11: Free all node\n12: Reverse list\n13: Sorted List\n0: Exit \n");
	printf("Enter choice :\n");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
			printf("Enter element\n");
			scanf("%d",&x);
			
			insert_at_end(x);
			break;
		case 2:
			printf("Enter element\n");
			scanf("%d",&x);
			
			insert_at_beg(x);
			break;
		case 3:
			printf("Enter element\n");
			scanf("%d",&x);
			printf("Enter Index\n");
			scanf("%d",&ind);
			
			insert_at_pos(x,ind);
			break;
		case 4:
			display();
			break;
		case 5:
			list_node_count();
			break;
		case 6:
			delete_at_end();
			break;
		case 7:
			delete_at_beg();
			break;
		case 8:
			printf("Enter Index\n");
			scanf("%d",&ind);
			delete_from_pos(ind);
			break;
		case 9:
			printf("Enter element\n");
			scanf("%d",&x);
			delete_by_element(x);
			break;
		case 10:
			t1=head;
			reverse_display(t1);
			printf("\n==================================================================\n");
			printf("\n");
			break;
		case 11: 
			free_all_node();
			break;
		case 12:
			reverse_list();
			break;
		case 13:
			sorted_list();
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

//a) insertAtEnd

void insert_at_end(int x)
{
	struct node *temp;
	struct node *t1;
	t1=head;
	
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	
	if(head==NULL)
	{
		head=temp;
		kount++;
	}
	else{
		while(t1->next!=NULL)
		{
			t1=t1->next;
		}
		t1->next=temp;
		kount++;
	}
	
}

//b) insertAtBeg 

void insert_at_beg(int x)
{
	struct node *temp;
	
	
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	
	if(head==NULL)
	{
		head=temp;
		kount++;
	}
	else{
		temp->next=head;
		head=temp;
		kount++;
	}
	
}

//c) insertAtPos 

void insert_at_pos(int x,int ind)
{
	
	
	if(head==NULL)
	{
		printf("linkedlist is empty\n");
		return;
	}
	if(ind==1)
	{
		insert_at_beg(x);
		return;
	}
	else if(ind==kount+1)
	{
		insert_at_end(x);
		return;
	}
	else
	{
		struct node *temp;
		struct node *t1;
		t1=head;
		
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=x;
		temp->next=NULL;
	
		int i=1;
		while(i<ind-1)
		{
			t1=t1->next;
			i++;
		}
		temp->next=t1->next;
		t1->next=temp;
		kount++;
	}
}

//d) displayList
                                          
void display()
{
	if(head==NULL)
	{
		printf("linkedlist is empty\n");
		return;
	}
	else
	{
		struct node *t1=head;
		
		while(t1!=NULL)
		{
			printf("%d->",t1->data);
			t1=t1->next;
		}
	}
	printf("\n==================================================================\n");
}

//e) listNodeCount 

void list_node_count()
{
	int count=0;
	
	if(head==NULL)
	{
		printf("linkedlist is empty\n");
		return;
	}
	else
	{
		struct node *t1=head;
		
		while(t1!=NULL)
		{
			count++;
			t1=t1->next;
		}
	}
	printf("count: %d\n",count);
	printf("kount: %d\n",kount);

}

//f) deleteFromEnd

void delete_at_end()
{
	if(head==NULL)
	{
		printf("linkedlist is empty\n");
		return;
	}else{

	struct node *t1,*t2;
	t1=head;
	if(head->next==NULL)
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
}

//g) deleteFromBeg

void delete_at_beg()
{
	if(head==NULL)
	{
		printf("linkedlist is empty\n");
		return;
	}else{
	
		if(head->next==NULL)
		{
			free(head);
			head=NULL;
			return;
		}
	struct node *t1=head;

	head=t1->next;
	t1->next=NULL;
	free(t1);
	kount--;
	
	}
}

//h)deleteFromPos 

void delete_from_pos(int ind)
{
	if(head==NULL)
	{
		printf("linkedlist is empty\n");
		return;
	}
	else
	{
		if(ind==1)
		{
			delete_at_beg();
			return;
		}
		else if(ind==kount)
		{
			delete_at_end();
			return;
		}
		else{
	
			struct node *t1=head;
			struct node *t2;
	
			int i=1;
			while(i<ind)
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
}

//i) deleteByElement

void delete_by_element(int x)
{
	if(head==NULL)
	{
		printf("linkedlist is empty\n");
		return;
	}
	else
	{
		if(x==head->data)
		{
			delete_at_beg();
			return;
		}
		else{
			struct node *t1=head;
			struct node *t2;
	
			
			while(t1->data!=x)
			{
				t2=t1;
				t1=t1->next;
			}
	
			t2->next=t1->next;
			free(t1);
			kount--;
		}
	}
}

//j) reverseDisplay

void reverse_display(struct node *t1)
{
	if(t1==NULL)
	{
		return;
	}
	reverse_display(t1->next);
	printf("%d-->",t1->data);
}

//k)freeAllNode

void free_all_node()
{
	struct node *t;
	while(head!=NULL)
	{	
		t=head;
		head=t->next;
		t->next=NULL;
		free(t);
		t=NULL;
		kount=0;
	}
	if(head==NULL)
	{
		printf("linkedlist is empty\n");
	}

}


//l) reverseList

void reverse_list()
{
	if(head==NULL)
	{
		printf("linkedlist is empty\n");
		return;
	}
	else
	{
		struct node *t1,*t2,*t3;
		t1=NULL;
		t2=NULL;
		t3=NULL;
		t1=head;
		while(t1!=NULL)
		{
			t2=t1->next;
			t1->next=t3;
			t3=t1;
			t1=t2;
		}
		head=t3;
	}
}

//m)sortedList

void sorted_list()
{
	struct node *t1,*t2;
	int temp;
	int i=1,j;
		
	t1=head;
	
	for(;i<kount;i++)
	{
		t2=t1->next;
		for(j=i+1;j<=kount;j++)
		{
			if((t1->data)>(t2->data))
			{
				temp=t1->data;
				t1->data=t2->data;
				t2->data=temp;
			}
			t2=t2->next;
		}
		t1=t1->next;
	}	
}

/*

	t1=head;
	t2=t1->next;
	int i=1,flag=1;
	while(t2!=NULL)
	{	
		for(i;i<kount;i++)
		{
			if((t1->data)<(t2->data))
			{
				flag++;
			}
			t1=t2;
			t2=t1->next;
		}
		
		t1=head;
		t2=t1->next;
		
		if(flag==kount)
		{
			break;
		}		
		while(t2!=NULL)
		{
			if((t1->data)>(t2->data))
			{
				temp=t1->data;
				t1->data=t2->data;
				t2->data=temp;
			}
			t1=t2;
			t2=t1->next;
		}
		
		t1=head;
		t2=t1->next;
		
	}	
*/


