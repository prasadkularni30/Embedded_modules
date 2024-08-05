#include<stdio.h>
int f(int);
int main()
{
	printf("%d",f(5));
}

int f(int n){

	int x;

	if(n == 0){
		x = 0;
	}
	else{
		x = n + f(n - 1);
	}

	return x;

}	
