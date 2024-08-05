#include<stdio.h>
void fun(int n);
int cout;
int main()
{
        int n;
	printf("enter no:");
        scanf("%d",&n);
	fun(n);
        printf("no.of digits:%d\n",cout);
        return 0;

}

void fun(int n)

{
        if(n==0)
                return ;
	cout++;
	fun(n/10);
        return ;

}
