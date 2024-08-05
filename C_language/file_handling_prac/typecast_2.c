#include<stdio.h>
#include<string.h>

int main(){
	char ar[]="a"; // size is 2
	char br[]="abcd";

	char cr[]={'d','e','s','d', '\0'};

	printf("ar=%s\n", ar); // a
	printf("br[0]%c\n", br+0); // a
	printf("ar=%s\n", ar); // a
	printf("br=%s\n", br); //abcd
	printf("cr=%s\n", cr); //desd

	printf("strlen(br)=%ld\n", strlen(br)); // 4
	int size=strlen(br);

	for(int i=0; i<size; i++){
		printf("%c ", br[i]);
	}
	printf("\n");
	/*
	//int arr[5]={10, 20, 30, 40, 50};
	//int arr[5]={10, 20, 30};
	int arr[]={10, 20, 30, 40, 50}; // here size is not optional
	int arr[5]; // here size of array must
	*/
	return 0;
}			

