#include<stdio.h>
#include<stdlib.h>
int ch,i,n;

struct node
{
	char ssn[10];
	char name[10];
	char dept[5];
	char desig[10];
	char phone[10];
	int salary;
	struct node *llink,*rlink;
};
typedef struct node NODE;
NODE * newnode;
NODE *head=NULL;
NODE *create()
{
	NODE * newnode;
	newnode=(NODE*)malloc(sizeof(NODE));
	printf("enter the Ssn,name,DEPARTMENT,DESIGNATION,PHONE no,SALARY\n");
	scanf("%s%s%s%s%s%d",newnode->ssn,newnode->name,newnode->dept,newnode->desig,newnode->phone,&newnode->salary);
	newnode->llink=newnode->rlink=NULL;
	return newnode;
}
NODE *insert_end(NODE *head)
{
	NODE *curr=head;
	if(head==NULL)
	{
		//printf("hai\n");
		head=create();
	}
	else
	{
		NODE *curr=head;
		newnode=create();
		while(curr->rlink!=NULL)
		{
			curr=curr->rlink;
		}
		curr->rlink=newnode;
		newnode->llink=curr;
		return head;
	}
}
NODE *insert_front(NODE *head)
{
	NODE * newnode;
	if(head==NULL)
	{
	//printf("hai\n");
		head=create();
	}
	else
	{
		newnode=create();
		newnode->rlink=head;
		head->llink = newnode;
		head=newnode;
	}
	return head;
}
NODE *delete_front(NODE *head)
{
	if(head==NULL)
	{
		printf("Empty list\n");
	}
	else
	{
		NODE *curr=head;
		if(curr->rlink==NULL)
		{
			head=NULL;
		}
		else
		{
			head=head->rlink;
		}
		free(curr);
	}
	return head;
}
NODE *delete_end(NODE *head)
{
	if(head==NULL)
	{
		printf("Empty list\n");
	}
	else
	{
		NODE *curr=head,*prev;
		if(curr->rlink==NULL)
		{
			head=NULL;
		}
		else
		{	
			while(curr->rlink!=NULL)
			{
				curr=curr->rlink;
			}
			prev=curr->llink;
			prev->rlink=NULL;
		}
		free(curr);
	}
}
void display(NODE *head)
{
	NODE *curr=head;
	//if(head!=NULL){
		printf("employee details\n");
		printf("SSN \tNAME  \tDEPARTMENT \t DESIGNATION \tPHONE \t SALARY: \n");
		printf("____________________________________________________________________________________\n");
	while(curr!=NULL)
	{
		printf("%s \t %s\t %s\t %s\t %s\t %d\n",curr->ssn,curr->name,curr->dept,curr->desig,curr->phone,curr->salary);
		curr=curr->rlink;
	}
	//printf("SSN:%s\nNAME:%s\nDEPARTMENT:%s\nDESIGNATION:%s\nPHONE:%s\nSALARY:%d\n",curr->ssn,curr->name,curr->dept,curr->desig,curr->phone,curr->salary);
}
void main()
{
	NODE *head=NULL;
	printf("EMPLOYEE DATABASE\n");
	printf("Number of employee data you want to create\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		head=insert_front(head);
	}
	printf("CHOICES ARE:\n1)Display\n2)Insert from the front\n3)Delete from the front\n4)Insert from the end\n5)Delete from the end\n6)Queue insertion\n7)Queue deletion\n8)exit\n");
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
			case 7:head=delete_end(head);
				break;
			case 8:exit(0);
				break;
			default:printf("invalid choice\n");
				break;
		}
	}while(1);
}
