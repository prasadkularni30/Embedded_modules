#include<stdio.h>
#include<stdlib.h>


void merge_sort(int *,int,int);
void merge(int *,int,int,int,int);
void input(int *,int);
void display(int *,int);

void main()
{
	int *arr;
	int n;
	
	printf("Enter size: ");
	scanf("%d",&n);
	
	arr=(int *)malloc(sizeof(int)*n);
	input(arr,n);
	printf("Input array\n");
	display(arr,n);
	merge_sort(arr,0,(n-1));
	printf("sorted array\n");
	display(arr,n);
}

void input(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("arr[%d]: ",i);
		scanf("%d",&a[i]);
	}

}

void display(int *a,int n)
{

	for(int i=0;i<n;i++)
	{
		printf("arr[%d]:%d ",i,a[i]);
		
	}
	printf("\n");

}

void merge_sort(int *a,int low, int high)
{

	if(low>=high)
		return;
	
	int mid=(low+high)/2;
	
	merge_sort(a,low,mid);
	merge_sort(a,(mid+1),high);
	
	
	merge(a,low,mid,(mid+1),high);
}

void merge(int *arr,int first1,int last1, int first2,int last2)
{
	int a=first1;
	int b=first2;
	int c=0;
	int size=(last1-first1+1)+(last2-first2+1);


	int *abc;
	
	abc=(int *)malloc(sizeof(int)*size);
	
	while((a<=last1)&&(b<=last2))
	{
		if(arr[a]<arr[b])
		{
			abc[c]=arr[a];
			c++;
			a++;
		}
		else
		{
			abc[c]=arr[b];
			c++;
			b++;
		}
	}
	
	while(a<=last1)
	{
		abc[c]=arr[a];
		c++;
		a++;
	}
	while(b<=last2)
	{
		abc[c]=arr[b];
		c++;
		b++;
	}
	c=0;
	for(int i=first1;i<=last2;i++)
	{
		arr[i]=abc[c];
		c++;
	}
	free(abc);
	
}
