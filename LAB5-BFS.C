#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
	int n,sv,i,j,front=0,rear=0,k=1,u,v;
	int a[10][10],visited[10],queue[20],t[10][2];
	clrscr();
	printf("Enter the Number of nodes:\n");
	scanf("%d",&n);
	printf("Enter Adjacency Materix:\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&a[i][j]);
	printf("Enter Source Vertex:\n");
	scanf("%d",&sv);
	//Mark All Vertix as Unvisited
	for(i=1;i<=n;i++)
	visited[i]=0;
	//Explore each vertex and if not visited place it in the queue
	queue[++rear]=sv;
	++front;
	visited[sv]=1;
	while(front<=rear)
	{
		u=queue[front++];
		for(v=1;v<=n;v++)
		{
			if(a[u][v]==1 && visited[v]==0)
			{
				visited[v]=1;
				queue[++rear]=v;
				t[k][1]=u;
				t[k][2]=v;
				k++;			
			}
		}
	}
	printf("The Reachable Nodes from Starting node are:\n");
	for(i=1;i<k;i++)
	printf("(%d,%d)\n",t[i][1],t[i][2]);
	getch(); 
}

Input:
4

0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0

1