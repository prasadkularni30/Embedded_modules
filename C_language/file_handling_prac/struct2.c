#include<stdio.h>

struct student{
	int prn;
	char gen;
};

int main(){
	struct student sarr[3]={{1,'m'}, {2,'f'}, {3,'f'}};

	printf("%d\n", sarr[2].prn); // 3
				     //
	for(int i=0; i<3 ;i++){
		printf("%d %c\n", sarr[i].prn, sarr[i].gen);
	}

	return 0;
}			

