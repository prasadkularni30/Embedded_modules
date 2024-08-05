//finding out given character is vowel or not
#include<stdio.h>
int main()
{
	char c;
	printf("Enter a character\n");
	scanf("%c",&c);
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')  // comparing input with all vowels

	{
		printf("Its a vowel");
	}
	else
	{
		printf("its not a vowel");
	}
	return 0;

}
