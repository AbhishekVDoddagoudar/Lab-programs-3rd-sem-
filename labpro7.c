#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int rear = -1,front = 0,q[MAX],item,i;
void insert ()
{
	if (front == (rear + 1) % MAX && rear > -1)
    	{
     	 printf ("queue overflow\n");
    	}
  	else
    	{
     	 printf ("enter the item\n");
      	rear = (rear + 1) % MAX;
      	scanf (" %c",q[rear]);
   	}
}
void delete ()
{
  	if (front == 0 && rear == -1)
    	{
     	 printf ("queue undreflow\n");
    	}
  	else
    	{
		item = q[front];
		if (rear == front)
		{
	  		front = 0;
	  		rear = -1;
		}
      		else
		{
	  		front = (front + 1) % MAX;
		}
    	}
}

void display ()
{
  	if (front == 0 && rear == -1)
    	{
     	 	printf ("queue undreflow\n");
    	}
  	else
    	{
      		for (i = front; i <= rear; i++)
		{
	  		printf (" %c", q[i]);
		}
		printf("\n");
    	}
}
void main ()
{
   	int choice;
  	do
    	{
      		printf ("1.insert\n2.delete\n3.display\n4.exit\n");
      		printf ("enter your choice\n");
     		scanf ("%d", &choice);
      		switch (choice)
		{
			case 1: insert ();
	  			break;
			case 2:delete ();
	  			break;
			case 3:display ();
	 			break;
			case 4:exit (0);
	  			break;
			default:printf ("invalid opration\n");
		}
    	}while (1);
}
