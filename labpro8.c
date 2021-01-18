#include<stdio.h>
#include<stdlib.h>
int ch,i,n;
struct node
{
	char usn[10],name[10],branch[5],phone[10];
	int sem;
	struct node *link;
};
typedef struct node NODE;
NODE *head=NULL;
NODE *create()
{
	NODE * newnode;
	newnode=(NODE*)malloc(sizeof(NODE));
	printf("Enter the USN,Name,Branch,SEM,Phone no.\n");
	scanf("%s%s%s%d%s",newnode->usn,newnode->name,newnode->branch,&newnode->sem,newnode->phone);
	newnode->link=NULL;
	return newnode;
}

NODE *insert_front(NODE *head)
{
	NODE * newnode;
	if(head==NULL)
	{
		head=create();
	}
	else
	{
		newnode=create();
		newnode->link=head;
		head=newnode;
	}
	return head;
}
NODE *insert_end(NODE *head)
{
	NODE * newnode;
	if(head==NULL)
	{
		head=create();
	}
	else
	{
		NODE *current=head;
		newnode=create();
		while(current->link!=NULL)
		{
			current=current->link;
		}
		current->link=newnode;
		return head;
	}
}
NODE *delete_front(NODE *head)
{
	if(head==NULL)
	{	
		printf("Linked list is empty\n");
	}
	else
	{
		NODE *current=head;
		head=head->link;
		free(current);
	}
	return head;
}
NODE *delete_end(NODE *head)
{
	NODE *current=head,*prev;
	while(current->link!=NULL)
	{
		prev=current;
		current=current->link;
	}
	free(current);
	prev->link=NULL;
}
NODE *display(NODE *head)
{
	NODE *current=head;
	while(current!=NULL)
	{
		printf("USN:%s\nNAME:%s\nBRANCH:%s\nSEM:%d\nPHONE:%s\n\n",current->usn,current->name,current->branch,current->sem,current->phone);
		current=current->link;
	}
	//printf("USN:%s\nNAME:%s\nBRANCH:%s\nSEM:%d\nPHONE:%s\n\n",current->usn,current->name,current->branch,current->sem,current->phone);
}
void main()
{
	NODE *head=NULL;
	printf("STUDENT DATABASE\n");
	printf("Number of students data you want to create\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		head=insert_front(head);
	}
	printf("CHOICES ARE:\n1)display\n2)insert from the front\n3)delete from the front\n4)insert from the end\n5)delete from the end\n6)stack insertion\n7)stack deletion\n8)exit\n");
	do{
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:display(head);
				break;
			case 2:head=insert_front(head);
				break;
			case 3:head=delete_front(head);
				break;
			case 4:head=insert_end(head);
				break;
			case 5:head=delete_end(head);
				break;
			case 6:head=insert_end(head);
				break;
			case 7:head=delete_front(head);
				break;
			case 8:exit(0);
				break;
			default:printf("invalid choice\n");
				break;
		}
	}while(1);
}
