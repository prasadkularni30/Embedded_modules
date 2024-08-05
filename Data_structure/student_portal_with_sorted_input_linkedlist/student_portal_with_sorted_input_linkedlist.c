
//Program for Student Record Management System

//Library Inlcudes

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>


// Defining size as 50

#define size 50

//structure declararations

struct node
{
    int roll_nu;
    char *name;
    long int co_nu;
    struct {
	    int math;
	    int sci;
	    int eng; 
    }marks;
    struct node *next;
    struct node *prev;
};



//Function Declarations

void insert(struct node **);
void display(struct node *);
void search(struct node *);
void modify(struct node *);
void delete(struct node **);
int counter(struct node *);
void free_all(struct node **);




int main() 
{
	//var declarations
	int choice,count;
	//declaration of head pointer
	struct node *head=NULL; //initiliasing with null to remove garbage value from pointer
	
	
	if(head!=NULL)		//NULL check if pointer contains garbage value
	{
		printf("pointer having unwanted value\n");
		return 0;
	}
	
	//superloop
	while(1)
	{
		count=counter(head);
		// Count of students.
		printf("\nDatabase:\nStudent Count: %d\n\n",count);
		// Menu 
		printf("[1] Add a Student\n[2] Display all\n[3] Search\n[4] Delete\n[5] Modify\n[0] Exit\nEnter a choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
				insert(&head);
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
			case 5:
				modify(head);
				break;
			case 0:
				free_all(&head);
				exit(0);
			default:
				printf("Invalid Choice\n");
				break;
				
		}
        }
    return 0;
}


//Function Definations


void insert(struct node **h)
{
	
	char buff[30];	//buff string
	
	struct node *temp=NULL;
	struct node *t1;
	int flag;
	
	//dynamic memory allocation to structure
	temp=(struct node *)malloc(sizeof(struct node));
	
	//NULL check
	if(temp==NULL)		//memory allocation check
	{
		printf("Memory allocation failed\n");
		printf("====================================================================================================\n");
		printf("\n");
		return;
	}
	
	printf("====================================================================================================\n");
	printf("Add Data ..............................\n");
	printf("\n");
	//initialising pointers with null
	temp->next=NULL;
	temp->prev=NULL;
	
	do
	{
		
		printf("Enter Roll no: ");
		scanf("%d",&temp->roll_nu); 
		flag=0;
		t1=*h;
		while(t1!=NULL)
		{
			if(temp->roll_nu==t1->roll_nu)	//Duplicate check
			{
				printf("Roll Number exists.\n");
				flag=1;
				break;
			}
			t1=t1->next;
		}
	}while(flag==1);	//loop for re-entering roll nu if flag is 1 and duplicate found 
	
	printf("Enter Name: ");
	__fpurge(stdin);
	scanf("%[^\n]s",buff);
	
	//finding lenght of string
	int l=strlen(buff);
	
	//allocating dynamic memory to char pointer name with size of strlenght + 1 (1 is for \0)
	temp->name=(char *)malloc(sizeof(char)*(l+1));
	//Ccopying data from buff string to dynamically allocated memory name
	strcpy(temp->name,buff);
	
	do
	{
		printf("Enter Contact info:\nMobile number: ");
		__fpurge(stdin);
		scanf("%ld",&temp->co_nu);
		
	
		flag=0;
		if(temp->co_nu < 1000000000 || temp->co_nu > 9999999999)	//contact number validation (contact number should be 10 digit)
		{
			printf("Invalid Contact Number\n");
			flag=1;
		}
	}while(flag==1);
	
		
	printf("Enter Marks(out off 100):\n");
	do
	{
		
		flag=0;
		printf("Maths: ");
		__fpurge(stdin);
		scanf("%d",&temp->marks.math);
		
		if(temp->marks.math>100 || temp->marks.math<0)	//marks validation 
		{	
			flag=1;
			printf("Enter Correct marks\n");
		}
	}while(flag==1);
	
	do
	{	
		
		flag=0;
		printf("Science: ");
		__fpurge(stdin);
		scanf("%d",&temp->marks.sci);
		
		
		if(temp->marks.sci>100 || temp->marks.sci<0)		//marks validation 
		{	
			flag=1;
			printf("Enter Correct marks\n");
		}
	}while(flag==1);
	
	
	do
	{
		flag=0;
		printf("English: ");
		__fpurge(stdin);
		scanf("%d",&temp->marks.eng);
		
		if(temp->marks.eng>100 || temp->marks.eng<0)		//marks validation 
		{	
			flag=1;
			printf("Enter Correct marks\n");
		}
	}while(flag==1);
	
	//arranging linklist in sorted manner (sorted input) 
	
	if(*h==NULL)		//if there is no previous data then data will go to head node only
	{
		*h=temp;
	}
	else
	{
		if(temp->roll_nu<(*h)->roll_nu)	//if new added data has roll number less than head node then data will be inserted at begining
		{
			temp->next=*h;
			*h=temp;
		}
		else
		{
			t1=*h;
			//loop till position is found as per roll number
			while((t1->next!=NULL) && (temp->roll_nu > t1->next->roll_nu))
			{
				t1=t1->next;
			}
			//if loop goes till last node data is inserted at end
			if(t1->next==NULL)
			{
				temp->prev=t1;
				t1->next=temp;
			}
			else	//data will be inserted at position
			{
				
				temp->next=t1->next;
				temp->prev=t1;
				t1->next->prev=temp;
				t1->next=temp;
			}
		}
	}
	printf("====================================================================================================\n");
	printf("\n");
}


void display(struct node *h)
{
	//NULL check
	if(h==NULL)
	{
		printf("No Database\n");
		printf("====================================================================================================\n");
		printf("\n");
		return;
	}
	
	struct node *t=h;
	
	printf("====================================================================================================\n");
	printf("Displaying..............................\n");
	printf("\n");
	while(t!=NULL) //displaying data till last node
	{
		printf("___________________________\n\n");
		printf("Roll No: %d\n",t->roll_nu);
		printf("Student Name: %s\n",t->name);
		printf("Contact Info: %ld\n",t->co_nu);
		printf("Marks----\n");
		printf("\tMaths: %d\n",t->marks.math);
		printf("\tScience: %d\n",t->marks.sci);
		printf("\tEnglish: %d\n",t->marks.eng);
		printf("___________________________\n");
		
		t=t->next;
	}
	printf("\n");
	printf("====================================================================================================\n");
}


void search(struct node *h)
{
	//NULL check
	 if(h==NULL)
	 {
	 	printf("list is empty\n");
        	return;
        }
        
        int count=counter(h);
        
        //declaration of array containing structure node pointers
        
        struct node *arr[size];	// Array with size 50 (because linklist size is not fixed ) extra memory allocated
        
        int roll,i=0;
        
        struct node *t1=h;
        
        while(t1!=NULL)	//intializing array with structure node addresses
        {
        	//printf("\n%d\n",i);
        	arr[i]=t1;
        	i++;
        	t1=t1->next;
        }
        
      //  printf("high\n");
        printf("enter roll to search\n");
        scanf("%d",&roll);
        
        int start=0,end=count-1,mid;
        int flag=0;
        
        //Binary search loop
        while(start<=end)
        {
        	mid=(start+end)/2;
        	
        	if(arr[mid]->roll_nu == roll )	//if data found flag is set.
        	{
        		//printf("mid %d\n",mid);
        		flag=1;
        		break;
        	}
        	else if(arr[mid]->roll_nu > roll )
        	{
        		
        		end=mid-1;
        		//printf("end %d\n",end);
        	}
        	else if(arr[mid]->roll_nu < roll )
        	{
        		
        		start=mid+1;
        		//printf("start %d\n",start);
        	}        
        
        }
        // if flag is set then data is found
        if(flag==1)
        {
        	printf("Roll No: %d\n",arr[mid]->roll_nu);
		printf("Student Name: %s\n",arr[mid]->name);
		printf("Contact Info: %ld\n",arr[mid]->co_nu);
		printf("Marks----\n");
		printf("\tMaths: %d\n",arr[mid]->marks.math);
		printf("\tScience: %d\n",arr[mid]->marks.sci);
		printf("\tEnglish: %d\n",arr[mid]->marks.eng);
        }
        else	//else no data
        {
        	printf("No Data found\n");
        }
        
        
}



void modify(struct node *h)
{
	//NULL check
	if(h==NULL)
	{
		printf("No Database\n");
		printf("====================================================================================================\n");
		printf("\n");
		return;
	}
	printf("====================================================================================================\n");
	printf("\n");
	
	struct node *t=h;
	
	int roll,flag,choice;
	
	printf("Search: \n");
	printf("Enter Roll No: ");
	scanf("%d",&roll);
	
	//loop for traversing the pointer till position
	while( t!=NULL && t->roll_nu != roll)
	{
		t=t->next;
	}
	
	if(t==NULL)
	{
		printf("Roll number not found\n");
		printf("====================================================================================================\n");
		printf("\n");
		return;
	}
	
	//displaying student name and roll number for clarification
	printf("Modification-----------------------\n");
	printf("Roll No: %d\n",t->roll_nu);
	printf("Student Name: %s\n",t->name);
	
	//menu for modification
	printf("[1]Contact Info\nMarks:\n\t[2]Maths\n\t[3]Science\n\t[3]English\n[0]Exit\nEnter Choice: ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			do
			{
				printf("Enter Contact info(Mobile number): ");
				__fpurge(stdin);
				scanf("%ld",&t->co_nu);
		
				flag=0;
				if(t->co_nu < 1000000000 || t->co_nu > 9999999999)
				{
					printf("Invalid Contact Number\n");
					flag=1;
				}
				
			}while(flag==1);
			
			break;
		case 2:
			printf("Enter Marks:\n");
			printf("Maths: ");
			__fpurge(stdin);
			scanf("%d",&t->marks.math);
			
			break;
		case 3:
			printf("Enter Marks:\n");
			printf("Science: ");
			__fpurge(stdin);
			scanf("%d",&t->marks.sci);
			break;
		case 4:
			printf("Enter Marks:\n");
			printf("English: ");
			__fpurge(stdin);
			scanf("%d",&t->marks.eng);
	}
	printf("====================================================================================================\n");
	
	printf("\n");
}


void delete(struct node **h)
{
	//NULL check
	if(*h==NULL)
	{
		printf("No Database\n");
		printf("====================================================================================================\n");
		printf("\n");
		return;
	}
	printf("====================================================================================================\n");
	printf("\n");
	
	struct node *t1=*h;
	struct node *t2=NULL;
	
	int roll;
	
	printf("Enter Roll No: ");
	scanf("%d",&roll);
	
	//if there is only 1 student data and user enters same roll number then head node will be deleted(free) and initialised with NULL
	if((*h)->roll_nu==roll && (*h)->next == NULL)
   	{
   		free((*h)->name);
   		free(*h);
   		*h=NULL;
   	}	//if there are multiple node and use wants to delete first node then first node is deleted(free) and new head is allocated
   	else if((*h)->roll_nu==roll )
   	{
   		t1=*h;
   		*h=(*h)->next;
   		free(t1->name);
   		free(t1);
   		(*h)->prev=NULL;
   	}
	else
	{
		t1=*h;
		while( t1!=NULL && t1->roll_nu != roll)	//loop till roll number is matched
		{
			t2=t1;
			t1=t1->next;
		}
	
		if(t1==NULL)	//if traversing pointer goes till last node then roll number not found
		{
			printf("Roll number not found\n");
			printf("====================================================================================================\n");
			printf("\n");
			return;
		}
		//node will be deleted from positiong and node before and after will be conncted
		t2->next=t1->next;
		if(t1->next!=NULL)
			t1->next->prev=t2;
		
		free(t1->name);
		free(t1);
		
	}
	
	printf("====================================================================================================\n");
	printf("\n");
}

//function for total node counted(total student)
int counter(struct node *h)
{
	if(h==NULL)
	{
		printf("No Database\n");
		printf("====================================================================================================\n");
		printf("\n");
		return 0;
	}
	printf("====================================================================================================\n");
	printf("\n");
	
	struct node *t1=h; 
	int count=0;
	
	while(t1!=NULL)
	{
		count++;
		t1=t1->next;
	}
	
	return count;
}

//function for freeing all nodes
void free_all(struct node **h)
{
	if(h==NULL)
	{
		printf("No Database\n");
		printf("====================================================================================================\n");
		printf("\n");
		return;
	}
	struct node *t;
	
	while(*h!=NULL)
	{
		t=(*h)->next;
		free((*h)->name);
		free(*h);
		*h=t;
	}
	
	*h=NULL;
	
}
