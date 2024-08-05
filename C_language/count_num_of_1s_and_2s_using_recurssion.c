#include<stdio.h>
void fun(int);
int count1,count0;
int main(){
	int n;
	scanf("%d",&n);
	fun(n);
	printf("\n count zero = %d\n",count0);
	printf("\n count one = %d\n",count1);
	return 0;
}

void fun(int n)
{
	if(n==0)
		return;
	int a=n%10;
	if(a==0)
		count0++;
	else
		count1++;
	fun(n/10);
}


