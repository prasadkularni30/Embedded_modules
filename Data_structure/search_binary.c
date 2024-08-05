

#include<stdio.h>
#include <stdlib.h>
#include<string.h>


void binary_search(int *);
int rec_binary_search(int *,int,int,int);
void display(int *);
void input(int *);

int size;

int main()
{
	int *a,choice,i=0,ele;
	int f=0;
	printf("Enter Size of array: ");
	scanf("%d",&size);
	
	a=(int *)malloc(sizeof(int)*size);
	
	int mid;
	while(1)
	{
	printf("Enter choice :\n[1] Binary Seach\n[2] Recurssive binary search\n[3]Display\n[4]Input\n[0]exit\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			binary_search(a);
			break;
		case 2:
			printf("Enter element: ");
			scanf("%d",&ele);
			mid=rec_binary_search(a,0,(size-1),ele);
			
			printf("Element is at index %d\n",mid+1);
			
			break;  
		case 3:
			display(a);
			break;
		case 4:
			input(a);
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

void input(int *a)
{
		int ele,flag=0,j;
	for(int i=0;i<size;)
	{
		printf("Enter Element : ");
		scanf("%d",&ele);
		
		for(j=0;j<i;j++)
		{
			if(a[j]==ele)
			{
				printf("Element already exist\n");
				flag=1;
				break;	
			}
			
		}
		if(flag==0)
		{
			
			j=i-1;
			while((j>=0)&&a[j]>ele)
			{
				a[j+1]=a[j];
				j--;
			}
				
			a[j+1]=ele;
			i++;	
		}
		flag=0;
		
	}
}

void display(int *a)
{
	for(int i=0;i<size;i++)
	{
		printf("Element [%d]: %d\n",i+1,a[i]);
	}
	printf("\n");
}

void binary_search(int *a)
{
	int ele,start=0,end=size-1,mid,flag=0;
	
	printf("Enter Element: ");
	scanf("%d",&ele);
	while(start<=end)
	{
		mid=(start+end)/2;
		
		if(a[mid]==ele)
		{
			flag=1;
			break;
		}
		else if(a[mid]<ele)
		{
			start=mid+1;
		}
		else if(a[mid]>ele)
		{
			end=mid-1;
		}
		
	}
	if(flag==1)
	{
		printf("Element found at index: %d\n",mid+1);
	}
	else
	{
		printf("Element not found\n");
	}
}

int rec_binary_search(int *a,int start,int end,int ele)
{
	
	
	if(start<=end)
	{
		int mid;
		mid=(start+end)/2;
		
		if(a[mid]==ele)
		{
			return mid;
		}
		else if(a[mid]<ele)
		{
			return rec_binary_search(a,mid+1,end,ele);
		}	
		else if(a[mid]>ele)
		{
		
			return rec_binary_search(a,start,mid-1,ele);			
		}
	
	}
	
	return -1;
}
