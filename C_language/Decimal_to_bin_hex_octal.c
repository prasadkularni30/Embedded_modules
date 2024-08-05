#include<stdio.h>
void int_to_binary(int);
void int_to_octal();
void int_to_hex();


int main(){
	int n;
	printf("enter int");
	scanf("%d",&n);
	int_to_binary(n);
	int_to_octal(n);
	int_to_hex(n);
	return 0;
}

void int_to_binary(int n){
	int i=0;
	int a[32]={0,0};

	while(i<32)
	{
		a[i]=n%2;
		n=n/2;
		
		i++;
	}
	printf("Binary is: ");
	for(i--;i>=0;i--)
	{
		printf("%d",a[i]);
	}
	printf("\n");
}

void int_to_octal(int n){
	int i=0;
	int a[12]={0};

	while(i<12)
	{
		a[i]=n%8;
		n=n/8;
		i++;
	}
	printf("octal is: ");
	for(i--;i>=0;i--)
	{
		printf("%d",a[i]);
	}

	printf("\n");
}
void int_to_hex(int n){
	int i;
	char a[8]={0};

	while(i<8)
	{
		int temp=n%16;
		if(temp<10)
			temp=temp+48;
		else
			temp=temp+55;
		a[i]=temp;
		n=n/16;
		i++;
	}
	printf("hex is: ");
	for(i--;i>=0;i--)
	{
		printf("%c",a[i]);
	}
	printf("\n");
}


