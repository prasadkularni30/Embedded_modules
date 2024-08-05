/*
Q4. Write a C/C++ program to implement priority queue data
structure using array.
*/

#include<stdio.h>
#include<stdlib.h>


struct queue{
	int data;
	int prio;
};

void enqueue(struct queue *,int *,int);
int dequeue(struct queue *,int *);
void display(struct queue *,int ,int);


int main()
{
	struct queue *q;
	int n,choice,ele;
	int r=-1;
	
	printf("Enter size of queue: ");
	scanf("%d",&n);
	
	q=(struct queue *)malloc(sizeof(struct queue)*n);
	for(int i=0;i<n;i++)
	{
		q[i].data=-99;
		q[i].prio=-99;
	}
	while(1)
	{
		printf("[1]Insert\n[2]delete\n[3]display\n");
		printf("Enter choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				enqueue(q,&r,n);
				break;
			case 2:
				ele=dequeue(q,&r);
				if(ele!=-1)
					printf("Deleted element is %d\n",ele);
				else
					break;
				break;
			case 3:
				display(q,r,n);
				break;
			case 0:
				free(q);
				exit(0);
			default:
				printf("Invalid Choice\n");
				break;
		}
	}
}

void enqueue(struct queue *q,int *r,int n)
{
	int ele,p,j;
	if(*r==(n-1))
	{
		printf("Queue full\n");
		return;
	}
	printf("Enter Element: ");
	scanf("%d",&ele);
	do
	{
	printf("Enter Priority: ");
	scanf("%d",&p);
	
	if(p<=0)
		printf("Priority cannot be negative\n");
	}while(p<=0);
	
	if(*r==-1)
	{
		*r+=1;
		q[*r].data=ele;
		q[*r].prio=p;
		
		
	}
	else
	{
		j=*r;
		
		while((j>=0)&&(q[j].prio>p))
		{
			q[j+1]=q[j];
			j--;
		}
		q[j+1].data=ele;
		q[j+1].prio=p;
		*r+=1;
		

	}
}


int dequeue(struct queue *q,int *r)
{
	if(*r==-1)
	{
		printf("Queue Empty\n");
		return -1;
	}
	
	int ele=q[0].data;
	
	for(int i=0;i<*r;i++)
	{
		q[i]=q[i+1];
	}
	
	q[*r].prio=-99;
	q[*r].data=-99;
	
	
	*r-=1;
	
	return ele;
}


void display(struct queue *q,int r,int n)
{
	if(r==-1)
	{
		printf("Queue empty\n");
		return;
	}
	for(int i=0;i<n;i++)
	{
		printf("--> %d ",q[i].data);
	}
	printf("\n");
}
