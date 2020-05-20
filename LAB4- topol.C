#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void Top_str();
int g[10][10],sv,n,visited[10],count=0;

void main()
{
	int i,j;
	clrscr();
	printf("Enter Number of nodes for the Gaph:\n");
	scanf("%d",&n);
	printf("Enter the Adjacency matrix for the Diagraph:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	printf("The Solution for the graph is:\n");
	for(i=1;i<=n;i++)
	{
		Top_str();
	}
	if(count!=n)
	{
		printf("\n graph indicates acyclic Digraph");
	}
	getch();
}

/*Topological Sorting*/

void Top_str()
{
	int i,j,indeg[10];
	for(i=1;i<=n;i++)
	{
		indeg[i]=0;
	}
/* Finding the Indegree of teh vertices which are not visited*/
for(i=1;i<=n;i++)
{
	if(visited[i]==0)
	{
		for(j=1;j<=n;j++)
		{
			if(g[j][i]==1)
			{
				indeg[i]++;
			}
		}
	}
}
/*Identifing the vertex whose indegree is zero*/
for(i=1;i<=n;i++)
if(visited[i]==0  &&  indeg[i]==0)
{
	sv=i;
	break;
}
/*Removing the Vertex Along with their edges and printing*/
if(visited[sv]==0)
{
	for(i=1;i<=n;i++)
	{
		if(g[sv][i]==1)
		{
			g[sv][i]=0;
		}
	}
	visited[sv]=1;
	count=count+1;
	printf("\t%d->",sv);
}
}

Input 1:
4
0 0 1 1
0 0 1 0
0 0 0 0
0 1 0 0

Input 2:
4
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0