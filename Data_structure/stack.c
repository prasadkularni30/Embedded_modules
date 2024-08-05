/*
Q2. Write a C/C++ program to implement stack data structure using
array. Implement below metioned functions.
a) push b) pop c) peep d) displayStack e)isStackFull
f) isStackEmpty
*/

#include<stdio.h>
#include<stdlib.h>

void push(int *, int *);
void pop(int *,int *);
void peep(int *,int );
void display_stack(int *);
int is_stack_full(int);
int is_stack_empty(int);


int size;

int main()
{
	int *a,choice,i;
	int t=-1;
	printf("Enter Size of array: ");
	scanf("%d",&size);
	
	a=(int *)malloc(sizeof(int)*size);
	
	for(int i=0;i<size;i++)
	{
		a[i]=-99;
	}
	
	while(1)
	{
	printf("Enter choice :\n1) push \n2) pop \n3) peep \n4) displayStack \n5) Stack Full check \n6) Stack Empty check \n0)exit\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			push(a,&t);
			break;
		case 2:
			pop(a,&t);
			break;
		case 3:
			peep(a,t);
			break;
		case 4:
			display_stack(a);
			break;
		case 5:
			i=is_stack_full(t);
			break;
		case 6:
			i=is_stack_empty(t);
			break;
		case 0:
			free(a);
			exit(0);
		default:
			printf("Invalid Choice");
			break;
	}
	
	}
	
}
int is_stack_full(int t)
{
	if(t==(size-1))
	{
		printf("Stack Full\n");
		return 1;
	}
	else
	{
		printf("%d Element present in stack\n",t+1);
		return 0;
	}
}

int is_stack_empty(int t)
{
	if(t==-1)
	{
		printf("Stack Empty\n");
		return 1;
	}
	else
	{	
		printf("%d Element present in stack\n",t+1);
		return 0;
	}
}


void push(int *a, int *t)
{
	if(is_stack_full(*t))
		return;
	int temp;
	
	printf("Enter Element: ");
	scanf("%d",&temp);
		
	(*t)++;
	a[*t]=temp;
	
	
}

void pop(int *a, int *t)
{
	if(is_stack_empty(*t))
		return;
	
	int temp=a[*t];
	a[*t]=-99;
	(*t)--;
	
	printf("Poped Element: %d\n",temp);
}

void peep(int *a,int t)
{
	if(is_stack_empty(t))
		return;
		
	printf("Top Element: %d\n",a[t]);
}

void display_stack(int *a)
{
	for(int i=0;i<size;i++)
	{
		printf("Element [%d]: %d\n",i+1,a[i]);
	}
}
