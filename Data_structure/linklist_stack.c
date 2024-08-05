

#include<stdio.h>
#include<stdlib.h>


struct list{
	int data;
	struct list *next;
};

struct list *top;
int count=0;

void push(int );
int pop();
void delete_all();
void display();

int main()
{
	top=NULL;
	int choice,ele;
	
	while(1)
	{
		printf("[1]Add\n[2]Delete\n[3]Delete all\n[4]Display\n[0]Exit\nEnter Choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter Element: ");
				scanf("%d",&ele);
				push(ele);
				break;
			case 2:
				ele=pop();
				if(ele)
					printf("Poped Element: %d\n",ele);
				printf("======================================\n");
				break;
			case 3:
				delete_all();
				break;
			case 4:
				display();
				break;
			case 0:
				delete_all();
				exit(0);
			default:
				printf("Invalid Choice\n");
				break;
		}
	}
	
}


void push(int ele)
{
	printf("======================================\n");
	if(count==10)
	{	
		printf("Stack Full\n");
		return;
	}
	struct list *temp=NULL;
	temp=(struct list *)malloc(sizeof(struct list));
	
	if(temp==NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}
	
	temp->data=ele;
	temp->next=NULL;
	
	if(top==NULL)
	{
		top=temp;
	}
	else
	{
		temp->next=top;
		top=temp;
	}
	count++;
	
	printf("======================================\n");
}

void display()
{
	printf("======================================\n");
	struct list *temp=top;
	if(top==NULL)
	{
		printf("Stack Empty\n");
		printf("======================================\n");
		return;
	}
	
	while(temp!=NULL)
	{
		printf(" ---> %d",temp->data);
		temp=temp->next;
	}
	printf("======================================\n");
	printf("\n");
	
}
int pop()
{
	if(top==NULL)
	{
		printf("======================================\n");
		printf("Stack Empty\n");
		printf("======================================\n");
		return 0;
	}
	printf("======================================\n");
	int ele=top->data;
	struct list *temp=top;
	
	top=top->next;
	
	free(temp);
	
	count--;
	return ele;
	
}

void delete_all()
{
	struct list *temp;
	if(top==NULL)
	{
		printf("======================================\n");
		printf("Stack Empty\n");
		printf("======================================\n");
		return;
	}
	while(top!=NULL)
	{
		temp=top->next;
		free(top);
		top=temp;
	}
}
