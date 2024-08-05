/*Q9: Implement Q5 with data of n number of student (based on user input) and display the data at
the end.
Q10: Implement the Q5, by using dynamic memory allocation for data members “name” and
“city”.
*/
#include<string.h>
#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>

typedef struct Students{
	char *name;
	char gen;
	int age;
	char *city;
	int pin;

}dets;

void input(dets *,int);
void display(dets *,int);
int search(dets *,int);
void modify(dets *,int);

int main()
{
	int n,i;
	char ch,numb;
	printf("Enter er of students:");
	scanf("%d",&n);
	dets *p=(dets *)malloc(sizeof(dets)*n);


	input(p,n);
	printf("\n");

	do{

	display(p,n);


	printf("\nare you satisfied with information:\n For Modification(Press Y) or to Save Press S: ");
	__fpurge(stdin);
	scanf("%c",&ch);
//	printf("ch%c",ch);

	if(ch=='Y'||ch=='y')
	{
	i= search(p,n);
		if(i!=100)
		{
		modify(p,i);

		printf(" ========================== Check Updated information ==========================  \n");
		}
	}

	//printf("i=%d\n",i);

	}while(ch=='Y'||ch=='y');

	for(int z=0;z<n;z++)
	{
		free(p[z].name);
		free(p[z].city);
		p[z].name=NULL;
		p[z].city=NULL;
	}
	free(p);
	p=NULL;

	return 0;
}

void input(dets *d,int n)
{
	char ch[50];
	int i;
	for(int j=0;j<n;j++)
	{
	printf("\n\tEnter information of student %d:\n",j+1);

	printf("Full Name: ");
	scanf(" %[^\n]s",ch);

	i=strlen(ch);
	//i=sizeof(ch);
	printf("%d",i);
	d[j].name=(char *)malloc(sizeof(char)*i);
	strcpy(d[j].name,ch);

	printf("Gender 'M'/'F': ");
	__fpurge(stdin);
	scanf(" %c",&d[j].gen);

	printf("Age: ");
	__fpurge(stdin);
	scanf(" %d",&d[j].age);

	printf("City: ");
	__fpurge(stdin);
	scanf(" %[^\n]s",ch);

	i=strlen(ch);

	d[j].city=(char *)malloc(sizeof(char)*i);
	strcpy(d[j].city,ch);

	printf("PinCode: ");
	__fpurge(stdin);
	scanf(" %d",&d[j].pin);
	
	printf("\n");
	}

	printf("\n");

}

void display(dets *d,int n)
{
	for (int i=0;i<n;i++)
	{
	printf(" =============================== Student %d =============================== \n",i+1);
	
	printf("Full Name: %s\n",d[i].name);

	printf("Gender 'M'/'F': %c \n",d[i].gen);

	printf("Age: %d\n",d[i].age);

	printf("City: %s\n",d[i].city);

	printf("PinCode: %d\n",d[i].pin);
	
	printf("\n");
	}
	printf("\n");

}

int search(dets *p,int n)
{
	//printf("***");
	char ch[20];
	printf("\nEnter name:");
	scanf(" %[^\n]s",ch);

	for(int i=0;i<n;i++)
	{
		if(!strcmp(p[i].name,ch))
		{
			return i;
		}
	}
	printf("no match");
	return 100;
}




void modify(dets *p,int i)
{
	int choice;
	printf("\t:Modification:\n Choose Option no: \n 1. Name \n 2. City \n 3.PinCode \n ");
	scanf("%d",&choice);
	
	printf(" =============================== Student %d =============================== ",i+1);

	switch(choice)
	{
		case 1:
			printf("Full Name: ");
			scanf(" %[^\n]s",p[i].name);
			break;
		case 2:
			printf("City: ");
			__fpurge(stdin);
			scanf(" %[^\n]s",p[i].city);
			break;
		case 3:
			printf("PinCode: ");
			__fpurge(stdin);
			scanf(" %d",&p[i].pin);
			break;
		default:
			printf("choose correct option\n");
	}
}


