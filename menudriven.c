#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void insert();
void delete();
int A[100],n,choice,i,POS,ELEM,a;
void main()
{
	do
	{
		printf("\n1.create\n2.display\n3.insert\n4.delete\n5.exit\n");
		printf("\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:create();
				break;
			case 2:display();
				break;
			case 3:insert();
				break;
			case 4:delete();
				break;
			case 5:exit(0);
				break;
		}
	}while(1);
}
void create()
{
	printf("\nEnter how many elements you want to enter\n");
	scanf("%d",&n);
	printf("\nEnter the array \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
}
void display()
{
	printf("\nThe array elements are\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",A[i]);
	}
}
void insert()
{
	printf("\nEnter the element to be inserted\n");
	scanf("%d",&ELEM);
	printf("\nEnter the position to insert the element\n");
	scanf("%d",&POS);
	for(i=n-1;i>=POS;i--)
	{
		A[i+1]=A[i];
	}
	A[POS]=ELEM;
	n++;
}
void delete()
{
	printf("\nEnter the position from which element to be deleted\n");
	scanf("%d",&POS);
	a=A[POS];
	for(i=POS;i<n-1;i++)
	{
		A[i]=A[i+1];
	}
	n--;
}
