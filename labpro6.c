#include<stdio.h>
#include<math.h>
void tower(int n,char source,char temp,char dest)
{
	if(n==0)
		return;
	tower(n-1,source,dest,temp);
	printf("\n Move disc %d from %c to %c\n",n,source,dest);
	tower(n-1,temp,source,dest);
}
void main()
{
	int n;
	printf("Enter the number of discs\n");
	scanf("%d",&n);
	tower(n,'S','T','D');
	printf("\n The total number of moves are %d\n",(int)pow(2,n)-1);
}
