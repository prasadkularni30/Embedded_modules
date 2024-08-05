#include<stdio.h>
int power(int,int);


int main()
{
	int p,n;
	printf("Enter Number");
	scanf("%d",&n);
	printf("Enter power");
	scanf("%d",&p);

	        printf("Power of %d=%d\n",n,power(n,p)); //ans
        return 0;
}

int power(int n,int p)

{
        if(p==0)
                return 1;   //terminating condition
        return n*power(n,p-1);  //recurtion call

}


