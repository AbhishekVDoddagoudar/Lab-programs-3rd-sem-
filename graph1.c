#include<stdio.h>
#include<stdlib.h>
int adj[20][20],visited[20],G[20],front=-1,rear=-1,top=-1,n,i;
void BFS(int v)
{
int cur;
visited[v]=1;
G[++rear]=v;
while(front!=rear)
{
	cur=G[++front];
	for(i=1;i<=n;i++)
	{
		if((adj[cur][i]==1)&&(visited[i]==0))
		{
			G[++rear]=i;
			visited[i]=1;
			printf("%d->%d\n",cur,i);
		}
	}
}
}
void DFS(int v)
{
visited[v]=1;
G[++top]=v;
for(i=1;i<=n;i++)
{
	if(adj[v][i]==1&&visited[i]==0)
	{
		printf("\n%d--%d",v,i);
		DFS(i);
	}
}
}
int main()
{
	int ch,start,i,j;
	printf("\nenter the number of vertices in graph:");
	scanf("%d",&n);
	printf("\n enter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&adj[i][j]);
	do
	{
		printf("\n 1.reachable vertices using BFS\n2.reachable vertices using DFS");
		printf("\n 3.exit");
		printf("\n enter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
		case 1:for(i=1;i<=n;i++)
		visited[i]=0;
		printf("\n enter the starting vertex:");
		scanf("%d",&start);
		printf("\n nodes reachable from starting vertex%d are:",start);BFS(start);
			break;
		case 2:for(i=1;i<=n;i++)
		visited[i]=0;
		printf("\n enter the starting vertex:");
		scanf("%d",&start);
		printf("\n nodes reachable from starting vertex%d are:",start);DFS(start);
			break;
		case 3:exit(0);
		}
	}
	while(ch!=3);
	
}

