/*
Q1. Write a C/C++ program to implement below mentioned Searching
and Sorting Techniques.
(a) Merge Sort
(b) Quick Sort
(c) Heap Sort
*/

#include<stdio.h>
#include <stdlib.h>

#define SIZE 6

void quicksort(int *,int,int);
int split(int *,int ,int );

void display(int a[SIZE]);

void mergesort(int [],int,int);
void merge(int [],int,int,int,int);

int main()
{
	int a[SIZE]={40,20,10,60,30,50};
	int choice;
	
	while(1)
	{
	printf("Enter choice :\n[1]sort\n[2] display\n[0]exit\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			quicksort(a,0,5);
			break;
		case 2:
			display(a);
			break;
		case 3:
			mergesort(a,0,5);
		case 0:
			exit(0);
		default:
			printf("Invalid Choice");
			break;
	}
	
	}
	
	
	
}


void display(int a[SIZE])
{
	for(int i=0;i<SIZE;i++)
	{
		printf("Element [%d]: %d\n",i+1,a[i]);
	}
	printf("\n");
}


// a) Quick sort

void quicksort( int *a,int low,int high )
{
	int i ;
	if (high>low)
	{
	i=split( a, low, high ) ;
	quicksort ( a, low, i - 1 ) ;
	quicksort ( a, i + 1, high ) ;
	}
}

int split(int *a,int low, int high)
{
	int l=low;
	int p=low;
	int r=high;
	int temp;
	while((p!=l) || (p!=r))
	{
		while(p!=r)
		{
			if(a[p]>a[r])
			{
				temp = a[r] ;
				a[r] = a[p] ;
				a[p] = temp ;
				
				p=r;
			}
			else
			{
				r--;
			}
		}
		
		while((p==r)&&(l!=r))
		{
			if(a[p]<a[l])
			{
				temp = a[l] ;
				a[l] = a[p] ;
				a[p] = temp ;
				
				p=l;
			}
			else
			{
				l++;
			}
		}
	}
	return l;
}


//b) merge sort

void mergesort(int a[], int first, int last)
{
	if(first>=last)
		return;
		
	int mid = (first+last)/2;
	
	mergesort(a,first,mid);
	mergesort(a,(mid+1),last);
	
	merge(a,first,mid,(mid+1),last);
	
	
}

void merge(int arr[],int first1,int last1, int first2, int last2)
{
	int a=first1;
	int b= first2;
	int c=0;
	int *merge;
	
	int size=(last1-first1+1)+(last2-first2+1);
	
	merge=(int *)malloc(sizeof(int)*size);
	
	while((a<=last1) && (b<=last2))
	{
		if(arr[a]<arr[b])
		{	merge[c]=arr[a];
			a++;
			c++;
		}
		else
		{
			merge[c]=arr[b];
			b++;
			c++;
		}
	}
	
	while(a<=last1)
	{
		merge[c]=arr[a];
		c++;
		a++;
	}
	while(b<=last2)
	{
		merge[c]=arr[b];
		b++;
		c++;
	}
	c=0;
	for(int i=first1;i<=last2;i++)
	{
		arr[i]=merge[c];
		c++;
	}
	//display(arr);
	printf("\n");
	free(merge);
}
