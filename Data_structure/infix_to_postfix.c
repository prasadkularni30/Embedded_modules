#include<stdio.h>
#include<string.h>
#include <stdlib.h>



char *stack=NULL;

int top= -1;
int totalsize=-1;



int stack_empty()
{
	if(totalsize==-1 || stack ==NULL)
		return 1;
	else
		return 0;
}

int stack_full()
{
	if(totalsize==-1 || stack ==NULL)
		return 1;
	
	return top == totalsize - 1;
}

void push(char ele)
{
	if(stack_full())
		printf("Stack Empty\n");
	else
		stack[++top]=ele;
}

char pop()
{
	if(stack_empty())
		return -1;
		
	char temp=stack[top];
	top--;
	return temp; 
}

char peek()
{
	if(stack_empty())
		return -1;
		
	return stack[top];
}

int if_operand(char ele)
{
	if(('a'<=ele && ele<='z') || ('A'<=ele && ele<='Z') && ('1'<=ele && ele<='9'))
		return 1;
	else
		return 0;		
}

int precedence(char ele)
{
	switch(ele)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
			
	}
	return -1;
	
}

void infix_to_postfix(char *expression)
{
	int count=0;
	printf("Postfix Expression :\n");
	while(expression[count]!='\0')
	{
		if(if_operand(expression[count]))
			printf("%c",expression[count]);
			
		else if(expression[count]=='(')
			push(expression[count]);
			
		else if(expression[count]==')')
		{
			while(peek()!='(')
			{
				printf("%c",pop());
			}
			pop();
		}
		else
		{
			while(precedence(peek())>=precedence(expression[count]))
				printf("%c",pop());
				
				push(expression[count]);
		}
		count++;
	}
	
	while (top != -1)
	{
        	printf("%c", pop());
    	}
	printf("\n");
}


int main()
{
	char expression[40];
	
	printf("Enter Expression :");
	scanf("%s",expression);
	
	totalsize=40;
	
	stack=(char *)malloc(sizeof(char)*40);
	
	infix_to_postfix(expression);
	
	
	printf("\n");
	
	
	
}
