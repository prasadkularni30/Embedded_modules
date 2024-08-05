#include<stdio.h>
#include <stdlib.h>




int hash_fun(int);
void insert(int *,int);
int search(int [],int);
void delete(int *,int);
void display(int []);


int main()
{
	int arr[8];
	int ele,index,choice;
	
	for(int i=0;i<8;i++)
	{
		arr[i]=-99;
	}
	
	while(1)
	{
		printf("[1]Insert\n[2]search\n[3]delete\n[4]Display\n[0]Exit\n");
		printf("Enter Choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter Element: ");
				scanf("%d",&ele);
				insert(arr,ele);
				break;
			case 2:
				printf("Enter Element: ");
				scanf("%d",&ele);
				index=search(arr,ele);
				
				if(index==-1)
					printf("Element not found\n");
				else
					printf("Element found at position %d\n",index);
				break;
			case 3:
				printf("Enter Element: ");
				scanf("%d",&ele);
				delete(arr,ele);
				break;
			case 4:
				display(arr);
				break;
			case 0:
				printf("Exiting\n");
				exit(0);
			default:
				printf("Invalid Choice\n");
				break;
		}
	}
}


void display(int arr[])
{
	printf("Display: \n");
	for(int i=0;i<8;i++)
	{
		printf("Element [%d]: %d \n",i,arr[i]);
	}
	printf("\n");
}


int hash_fun(int ele)
{
	return (ele%10);
}


void insert(int *a,int ele)
{
	int i=0;
	int index=hash_fun(ele);
	
	if(a[index]==-99)
	{
		a[index]=ele;
	}
	else
	{
		i=index;
		while(a[i]!=-99 && i<8)
		{
			i++;
		}
		if(i<8)
			a[i]=ele;
		else
		{
			if(i=8)
				i=0;
			while(a[i]!=-99 && i<index)
			{
				i++;
			}
			if(i<index)
				a[i]=ele;
			else
				printf("All Slots occupied\n");
		}
	}	
}

int search(int a[], int ele)
{
	int i=0;
	int index=hash_fun(ele);
	
	if(a[index]==ele)
	{
		return index;
	}
	else
	{
		i=index;
		while(i<8)
		{
			if(a[i]==ele)
			{
				return i;

			}
			i++;
		}
		if(i=8)
			i=0;
		while(i<index)
		{
			if(a[i]==ele)
			{	
				return i;
			}
			i++;
		}
			
	}
	return -1;	
}

void delete(int *a, int ele)
{
	int temp;
	int index=search(a,ele);
	
	if(index==-1)
	{
		printf("Element not found\n");
		return;
	}
	
	temp=a[index]
	a[index]=-99;
	printf("Deleted Element %d\n",temp);
	
	return;
	
}

/*
	else
	{
		i=index;
		while(i<8)
		{
			if(a[index]==ele)
			{
				temp=a[index]=-99;
				printf("Deleted Element %d\n",temp);
				return;
			}
			i++;
		}
		
		if(i=8)
			i=0;
		while(i<index)
		{
			if(a[index]==ele)
			{
				temp=a[index]=-99;
				printf("Deleted Element %d\n",temp);
				return;
			}
			i++;
		}
		if(i>index)
			printf("Element not found\n");
			
	}	
*/
