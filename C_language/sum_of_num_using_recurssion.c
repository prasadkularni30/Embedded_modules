        
#include<stdio.h>
int fun(int,int[]);
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
        int sum=fun(size-1,arr);
        printf("%d\n",sum);

        return 0;

}

int fun(int size,int arr[])
{
        if(size<0)
                return 0;
        return arr[size]+fun(size-1,arr);
}



