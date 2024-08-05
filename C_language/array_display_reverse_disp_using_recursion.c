#include<stdio.h>
void NormalDisplay(int,int []);
void ReverseDisplay(int,int []);
int n;
int main()
{
	printf("enter size:");
	scanf("%d",&n);
	printf("\n");
        int arr[n];

	for(int i=0;i<n;i++)
		scanf("%d[\n]",&arr[i]);

        int size=sizeof(arr)/sizeof(arr[0]);//calculating size of array

        NormalDisplay(size-1,arr);
        printf("\n");

        ReverseDisplay(size-1,arr);
        printf("\n");

        return 0;

}
void NormalDisplay(int size,int arr[])
{
        if(size<0)
                return ;
        NormalDisplay(size-1,arr);
        printf("%d ",arr[size]);

}

void ReverseDisplay(int size,int arr[])
{
        if(size<0)
                return;
        printf("%d ",arr[size]);
        ReverseDisplay(size-1,arr);
}
