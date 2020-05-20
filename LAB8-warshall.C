#include<stdio.h>
#include<conio.h>

void warshall();
int n,adj[10][10],path[10][10];
void main()
{
	int i,j,k;
	clrscr();
	printf("Enter no. of nodes of the graph:");
	scanf("%d",&n);
	printf("Enter the Adjacency matrix for the graph:\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&adj[i][j]);
	printf("\n The Adjacency matrix is:\n");
	for(i=1;i<=n;i++)
	{
	for(j=1;j<=n;j++)
	{
	printf("%5d",adj[i][j]);
	path[i][j]=adj[i][j];
	}
	printf("\n");
}
warshall();
getch();
}
//CALCULATE THE DIRECT AND INDIRECT EDGES USING INTERMEDIATE VERTICES

void warshall()
{
	int i,j,k;
	for(k=1;k<=n;k++)
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	path[i][j]=path[i][j] || (path[i][k] && path[k][j]);
	printf("\n The Transitive closure is: \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		printf("%5d",path[i][j]);
		printf("\n");
	}
}


Input:
4

0 1 0 0
0 0 0 1
0 0 0 0
1 0 1 0