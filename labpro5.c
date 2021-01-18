//Evaluation of suffix expression
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
int i,symbol;
double compute(char symbol,double op1,double op2)
{
	switch(symbol)
	{
		case '+':return op1+op2;
		case '-':return op1-op2;
		case '*':return op1*op2;
		case '/':return op1/op2;
		case '%':return (double)((int)(op1)%(int)(op2));
		case '^':return pow(op1,op2);
		default :return 0;
	}
}
void main()
{
	double s[20],op1,op2;
	int top=-1;
	char postfix[20],symbol;
	printf("Enter the postfix expression\n");
	gets(postfix);
	for(i=0;i<strlen(postfix);i++)
	{
		symbol=postfix[i];
		if(isdigit(symbol))
		{
			s[++top]=symbol-'0';
		}
		else
		{
			op2=s[top--];
			op1=s[top--];
			s[++top]=compute(symbol,op1,op2);
		}
	}
	printf("The result is %f\n",s[top]);
}
