#include<stdio.h>
#include<conio.h>
int min(int a,int b)
{
	return(a<b ? a:b);
}
void floyd();
int n,cost[10][10],dist[10][10];
void main()
{
	int i,j,k;
	clrscr();
	printf("Enter Number of Nodes of the graph:");
	scanf("%d",&n);
	printf("Enter the Adjacency matrix for the graph if no edges enter as 999:\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&cost[i][j]);
	printf("\n The Adjacency matrix is:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%5d",cost[i][j]);
			dist[i][j]=cost[i][j];
		}
		printf("\n");
	}
	floyd();
	getch();
}
//Calculate the Direct and InDirect edges using  intermediate vertices
void floyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		printf("stage %d\n",k);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				printf("%5d",dist[i][j]);
			}
			printf("\n");
		}
		getch();
	}
	printf("\n The Distance Matrix is :\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%5d",dist[i][j]);
			printf("\n");
	}
}

Input:
4

0 999 3 999
2 0 999 999
999 7 0 1
6 999 999 0