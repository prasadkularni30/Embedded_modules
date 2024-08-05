/*Q5: Write a C program to create a registration form for the user, the form should ask the
followingdetails:
Name: Age: Gender: City: PinCode:
Marital Status: Annual Salary:
Once input is received, display the data to the user.

Q6: Implement the question 5 with an added feature, wherein at the end, user should be given an
option to verify the data, in-case user wishes to modify the entered data. If user wishes to
modify the data it has entered, new modified data should be displayed as output when
program ends.*/


#include<stdio.h>
#include<stdio_ext.h>

typedef struct Details{
	char name[30];
	char gen;
	int age;
	char city[10];
	int pin;
	char m[10];
	int sal;

}dets;

void input(dets *);
void display(dets *);
void modify(dets *);

int main()
{
	char ch;
	dets d;

	dets *p;
	p=&d;

	input(p);
	printf("\n");

	do{

	display(p);

	printf("\nare you satisfied with information:\n For Modification(Press Y) or to Save Press S: ");
	scanf(" %c",&ch);

	if(ch=='Y'||ch=='y')
	{
		modify(p);
		printf("\n");
	}


	}while(ch=='Y'||ch=='y');

	return 0;
}

void input(dets *d)
{
	printf("Full Name: ");
	scanf(" %[^\n]s",d->name);
	printf("Gender 'M'/'F': ");
	__fpurge(stdin);
	scanf(" %c",&d->gen);
	printf("Age: ");
	__fpurge(stdin);
	scanf(" %d",&d->age);
	printf("City: ");
	__fpurge(stdin);
	scanf(" %[^\n]s",d->city);
	printf("PinCode: ");
	__fpurge(stdin);
	scanf(" %d",&d->pin);
	printf("Marital Status (Married Unmarried) :");
	__fpurge(stdin);
	scanf("%s",d->m);
	printf("Annual Salay in Rs: ");
	__fpurge(stdin);
	scanf(" %d",&d->sal);

	printf("\n");

}

void display(dets *d)
{
	printf("Full Name: %s\n",d->name);

	printf("Gender 'M'/'F': %c \n",d->gen);

	printf("Age: %d\n",d->age);

	printf("City: %s",d->city);

	printf("PinCode: %d\n",d->pin);
	
	printf("Marital Status:%s \n",d->m);
	
	printf("Annual Salay in Rs: %d\n",d->sal);
	printf("\n");

}

void modify(dets *p)
{
	int choice;
	printf("\t:Modification:\n Choose Option no: \n 1. Name \n 2. City \n 3.PinCode \n 4.Annual salary \n");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
			printf("Full Name: ");
			scanf(" %[^\n]s",p->name);
			break;
		case 2:
			printf("City: ");
			__fpurge(stdin);
			scanf(" %[^\n]s",p->city);
			break;
		case 3:
			printf("PinCode: ");
			__fpurge(stdin);
			scanf(" %d",&p->pin);
			break;
		case 4:
			printf("Annual Salay in Rs: ");
			__fpurge(stdin);
			scanf(" %d",&p->sal);
			break;
		default:
			printf("choose correct option\n");
	}
}	
