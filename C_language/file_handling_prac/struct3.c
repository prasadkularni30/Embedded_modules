#include<stdio.h>

struct student{
	int prn;
	char name[15];
	char gen;
};

int main(){
	struct student sarr[3]={{1,"abc", 'm'}, {2,"xyz", 'f'}, {3, "pqr", 'f'}};

				     //
	for(int i=0; i<3 ;i++){
		printf("%d %s %c\n", sarr[i].prn, sarr[i].name,sarr[i].gen);
	}

	return 0;
}			

