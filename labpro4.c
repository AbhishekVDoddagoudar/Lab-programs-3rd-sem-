#include<stdio.h>
#include<string.h>
int stack(char symbol)
{
	switch(symbol)
	{
		case '+':return 2;
		case '-':return 2;
		case '*':return 4;
		case '/':return 4;
		case '^':return 5;
		case '%':return 5;
		case '(':return 0;
		case '#':return -1;
		default :return 8;
	}
}
int Input(char symbol)
{
	switch(symbol)
	{
		case '+':return 1;
		case '-':return 1;
		case '*':return 3;
		case '/':return 3;
		case '^':return 6;
		case '%':return 6;
		case '(':return 9;
		case ')':return 0;
		default :return 7;
	}
}
void infix_postfix(char infix[],char postfix[])
{
	int top=-1,j=0,i;
	char s[20],symbol;
	s[++top]='#';
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		while(stack(s[top])>Input(symbol))
		{
			postfix[j++]=s[top--];
		}
		if(stack(s[top])!=Input(symbol)){
			s[++top]=symbol;
		}
		else{
			top--;
		}
	}
		while(s[top]!='#')
		postfix[j++]=s[top--];
		postfix[j]='\0';
		printf("\nThe infix expression is %s\nThe postfix expression is %s\n",infix,postfix);
	
}
void main()
{
	char infix[20],postfix[20];
	printf("Enter the infix expression\n");
	gets(infix);
	infix_postfix(infix,postfix);
}
