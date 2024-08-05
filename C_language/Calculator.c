#include<stdio.h>
void add (int a,int b);
void sub (int a,int b);
void mul (int a,int b);
void div(float a,float b);


int main()
{
	int x,w,choice;
	float y,z;

		printf("enter choice\n 1- add\n 2- sub\n 3- mul\n 4- div\n");
		scanf("%d",&choice);
		if(choice==1||choice==2||choice==3)
		{
		printf("Enter two numbers\n");
		scanf("%d",&w);
		scanf("%d",&x);}
		else{ // for division input  perpose only
			printf("Enter two numbers\n");
			scanf("%f",&y);
			scanf("%f",&z);
		}
		switch(choice)
		{
			case 1:
				add(w,x);
				break;
			case 2:
				sub(w,x);
				break;
			case 3:	
				mul(w,x);
				break;
			case 4:
				div(y,z);
				break;
			default :
				printf("choose from given index");
				break;
		}

}

void add(int a, int b)
{
	int sum;
	sum=a+b;
	printf("sum of %d and %d is %d\n",a,b,sum);

}

void sub(int a, int b)
{
	int sub=a-b;
	printf("sub of %d and %d is %d\n",a,b,sub);
}
void mul(int a, int b)
{
	int mul;
	mul=a*b;
	printf("mul of %d and %d is %d\n",a,b,mul);
}
void div(float a,float b)
{
	float div;
	div=a/b;
	printf(" div of %f and %f is %f\n",a,b,div);
}

