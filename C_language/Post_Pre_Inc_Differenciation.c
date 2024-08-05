#include<stdio.h>
int main()
{
	int k,y,q,i,x,p;

	i=10;
	x=20;
	p=9;

	//Post and pre Increment Operator.
	
	k=i++;	//with post increment operator value of i(i=10) will be assigned to k (k=10),then the value of i will be incremented means(i=i+1 --> i=11)
	printf("k=%d\n",k);
	printf("i=%d\n",i);

	k=++i;  //with pre increment operator value of i(i=11) will be incremented first and will become i=i+1 --> i=12, then value of i will be assigned to k(k=12)
	printf("k=%d\n",k);
	printf("i=%d\n",i);

	y=x++*10; //because of post increment of X,the output of expression will be stored in y(y=20*10-->y=200) and then the value of x will be incremented(x=21)
	printf("y=%d\n",y);
	printf("x=%d\n",x);

	y=++x*10; //because of pre increment of X,the value of x will be incremented(x=22) then the output of expression will be stored in y(y=22*10-->y=220)
	printf("y=%d\n",y);
	printf("x=%d\n",x);
	
	q=p--/3; //because of post decrement of p,expression will be solved first and stored in p(p=9/3-->p=3) & p is decremented (p=8)
	printf("p=%d\n",p);
	printf("q=%d\n",q);
	p=10;
	q=--p/3; //int pre decrement, p is decremented first p=p-1 -- p=9 & and then expression will be executed.
	printf("p=%d\n",p);
	printf("q=%d\n",q);
	return 0;

}
