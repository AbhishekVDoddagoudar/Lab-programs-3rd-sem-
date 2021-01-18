#include<stdio.h>
#include<string.h>
int i=0,c=0,m=0,k=0,j=0,flag=0;
char STR[20],REP[20],PAT[20],ANS[20];
int pattern_match()
{
	while(STR[c]!='\0')
	{
		if(STR[m]==PAT[i])
		{
			m++;
			i++;
			if(PAT[i]=='\0')
			{
				flag=1;
				while(REP[k]!='\0')
				{
					ANS[j++]=REP[k++];
				}
				i=0;
				c=m;
			}
		}
		else
		{
			ANS[j++]=STR[c++];
			i=0;
			m=c;
		}
	}
	ANS[j]='\0';
	return flag;

}
int main()
{
	printf("Enter the main string\n");
	gets(STR);
	printf("Enter the pattern string to match\n");
	gets(PAT);
	printf("Enter the replace string\n");
	gets(REP);
	if(pattern_match()==1)
	{
		printf("The resultant string is %s\n",ANS);
	}
	else
	{
		printf("Pattern not found\n");
	}
}
