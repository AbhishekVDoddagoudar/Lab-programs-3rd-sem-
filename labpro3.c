#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top=-1,item,i,stack[MAX];
void push()
{
	printf("Enter the item\n");
	scanf("%d",&item);
	if(top==MAX-1)
	{
		pintf("Stack is full\n");
	}
	else
	{
		stack[++top]=item;
	}
}
int del;
int pop()
{
	if(top==-1)
	{
		printf("Stack underflow\n");
	}
	else
	{
		del=stack[top--];
	}
}
void display()
{
	if(top==-1)
	{
		printf("Stack underflow\n");
	}
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("Stack elements are %d\n",stack[i]);
		}
	}
}
void palindrome()
{
	int i,temp=top,count=0;
	for(i=0;i<temp/2;i++)
	{
		if(stack[i]==pop())
		{
			count++;
		}
	}
	if(temp/2==count)
	{
		printf("Palindrome\n");
	}
	else
	{
		printf("Not palindrome\n");
	}
}
int main()
{
	int ch;
	do
	{
		printf("1.push\t2.pop\t3.display\t4.palindrome\t5.exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
				break;
			case 2:pop();
				break;
			case 3:display();
				break;
			case 4:palindrome();
				break;
			case 5:exit(0);
				break;
		}
	}while(1);
}
