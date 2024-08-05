#include<stdio.h>
#include<stdlib.h>


void quick_sort(int *,int, int );
int split(int *,int,int);
void display(int *,int );
void input(int *a,int n);


int main()
{
	int *arr;
	int n;
	
	printf("Enter element: ");
	scanf("%d",&n);
	
	arr=(int *)malloc(sizeof(int)*n);
	
	input(arr,n);
	
	display(arr,n);
	quick_sort(arr,0,(n-1));
	display(arr,n);
	
	free(arr);
}

void input(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("arr[%d]: ",i);
		scanf("%d",&a[i]);
	}
	printf("\n");
	
}

void display(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("arr[%d]:%d ",i,a[i]);
	}
	printf("\n");
	
}

void quick_sort(int *a,int low, int high)
{
	int i;
	if(low<high)
	{
	i=split(a,low,high);
	
	quick_sort(a,low,(i-1));
	quick_sort(a,(i+1),high);
	}
}

int split(int *a,int low, int high)
{
	int l=low;
	int p=low;
	int r=high;
	int temp;
	while(l<=r)
	{
		while(r!=p)
		{
			if(a[p]>a[r])
			{
				temp=a[p];
				a[p]=a[r];
				a[r]=temp;
			}
			else
			{
				r--;
			}
		}
		
		while((r==p)&&(l!=p))
		{
			if(a[l]>a[p])
			{
				temp=a[p];
				a[p]=a[l];
				a[l]=temp;
			}
			else
			{
				l++;
			}
		}
	}
	
	return p;
}
