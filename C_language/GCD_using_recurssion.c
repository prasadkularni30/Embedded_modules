#include<stdio.h>
void fun(int,int,int);
int ans;
int main()
{
	int a,b,temp;
	scanf("%d %d",&a,&b);
	if(a<b)
		fun(a,b,1);
	else
		fun(b,a,1);
	if(ans==1)
		printf("GCD not found!");
	else
		printf("GCD=%d\n",ans);
	return 0;

}

void fun(int a,int b,int div)
{
        if(a%div==0&&b%div==0)
      		 ans=div;
        if(div==a)
                 return;

	fun(a,b,div+1);
 	return ;	

}
