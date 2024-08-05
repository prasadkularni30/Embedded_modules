#include<stdio.h>
int fun(int n);
int main()
{
        int n;
	printf("enter no:");
        scanf("%d",&n);        //input
        printf("factorial=%d\n",fun(n)); //ans
        return 0;
}

int fun(int n)

{
        if(n==0)
                return 1;   //terminating condition
        return n*fun(n-1);  //recurtion call 

}
