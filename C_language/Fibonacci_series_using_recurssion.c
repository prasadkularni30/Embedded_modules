#include<stdio.h>

void fun(int ,int,int);

int main()
{
	int a;
	scanf("%d",&a);
	fun(a,0,1);

}
void fun(int a,int prev,int n)
{
	if(a==0)
		return ;
	int next;
	next=prev+n;
	printf("%d ",prev);
	prev=n;
	n=next;
	fun(a-1,prev,n);
	return ;

}
