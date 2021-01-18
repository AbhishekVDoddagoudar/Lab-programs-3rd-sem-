#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
	int coeff,powx,powy,powz,flag;
	struct node *link;
};
typedef struct node NODE;
NODE *insert(int coeff,int x,int y,int z,NODE *head)
{
	NODE *curr;
	NODE *temp=(NODE *)malloc(sizeof(NODE));
	temp->coeff=coeff;
	temp->powx=x;
	temp->powy=y;
	temp->powz=z;
	temp->flag=0;
	if(head==NULL)
		head=temp;
	else
	{
		curr=head;
		while(curr->link!=head)
		{
			curr=curr->link;
		}
		temp->link=head;
		return head;
	}
}
void display(NODE *head)
{
	NODE *temp=head;
	if(head!=NULL)
	{
		printf("\nPolynomial is\n");
		do
		{
			printf("%dx^%dy^%dz^%d",temp->coeff,temp->powx,temp->powy,temp->powz);
			temp=temp->link;
		}while(temp!=head);
	}
	printf("\n");
}
NODE *read_poly(NODE *head)
{
	int powx,powy,powz,coeff,ch;
	printf("Enter the polynomial terms\n");
	do
	{
		printf("\nEnter coeff and power of x,y,z\n");
		scanf("%d%d%d%d",&coeff,&powx,&powy,&powz);
		head=insert(coeff,powx,powy,powz,head);
		printf("\n1 to next term or 0 to stop\n");
		scanf("%d",&ch);
	}while(ch);
	//return(head);
	display(head);
	return(head);
}

int compare(NODE *h1,NODE *h2)
{
	if((h1->powx==h2->powx)&&(h1->powy==h2->powy)&&(h1->powz==h2->powz))
		return 1;
	else
		return 0;
}
int evaluate(NODE *head)
{
	NODE *temp=head;
	int x,y,z,result=0;
	printf("Enter x,y,z terms to evaluate\n");
	scanf("%d%d%d",&x,&y,&z);
	if(head!=NULL)
	{
		do
		{
			result=result+(temp->coeff *pow(x,temp->powx)*pow(y,temp->powy)*pow(z,temp->powz));
			temp=temp->link;
		}while(temp!=head);
		printf("\nPolynomial result is %d\n",result);
	}
}
NODE *addpoly(NODE *h1,NODE *h2)
{
	NODE *p1=h1,*p2,*h3=NULL;
	int coeff;
	do
	{
		p2=h2;
		do
		{
			if(p2->flag!=1)
			{
				if(compare(p1,p2)==1)
				{
					coeff=p1->coeff+p2->coeff;
					h3=insert(coeff,p1->powx,p1->powy,p1->powz,h3);
					p1->flag=p2->flag=1;
				}
			}
			p2=p2->link;
		}while(p2!=h2);
		if(p1->flag!=1)
		{
			h3=insert(p1->coeff,p1->powx,p1->powy,p1->powz,h3);
			p1->flag=1;
		}
		p1=p1->link;
	}while(p1!=h1);
	p2=h2;
	do
	{
		if(p2->flag!=1)
		{
			h3=insert(p2->coeff,p2->powx,p2->powy,p2->powz,h3);
			p2->flag=1;
		}
		p2=p2->link;
	}while(p2!=h2);
	printf("Sum of polymnomial is\n");
	display(h3);
	return h3;
}
int main()
{
	NODE *h1=NULL,*h2=NULL,*h3=NULL;
	int ch;
	do
	{
		printf("1)Evaluate\n2)Add polynomial\n3)Exit\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter polynomial to evaluate\n");
				h1=read_poly(h1);
				evaluate(h1);
				break;
			case 2:h1=read_poly(h3);
				h2=read_poly(h3);
				h3=addpoly(h1,h2);
				break;
			case 3:exit(0);
		}
	}while(1);
}
