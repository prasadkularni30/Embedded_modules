#include<stdio.h>
#include<string.h>
void NormalDisplay(int,char *);
void ReverseDisplay(int,char *);
int main()
{
	printf("enter string :");
        char arr[40];
	
	scanf("%s",arr);
	int size=strlen(arr);

        NormalDisplay(size,arr);
        printf("\n");

        ReverseDisplay(size,arr);
        printf("\n");

        return 0;

}
void NormalDisplay(int size,char *arr)
{
        if(size<0)
                return ;
        NormalDisplay(size-1,arr);
        printf("%c ",arr[size]);

}

void ReverseDisplay(int size,char *arr)
{
        if(size<0)
                return;
        printf("%c ",arr[size]);
        ReverseDisplay(size-1,arr);
}
