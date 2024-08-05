#include<stdio.h>
#include<string.h>

void myStrcpy(char *, const char *);

int main(){
	char name[10];

	char *s="cdac";
	puts(name);
	printf("..\n");
	myStrcpy(name,s);
	puts(name);
	return 0;
}

void myStrcpy(char *cp, const char *s){
	int i;
	for(; *s!='\0';){
		*cp=*s;
	printf("cp:%s\n",cp);
	printf("*cp:%c\n",*cp);
		cp++;
	printf("cp:%s\n",cp);
	printf("*cp:%c\n",*cp);
		s++;
	
	printf("s:%s\n",s);
	printf("*s:%c\n",*s);
	}
	*cp='\0';
}

