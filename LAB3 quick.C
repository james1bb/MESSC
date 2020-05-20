#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#define maxi 20000

clock_t start,end;
void quick_sort(int,int);
int partation(int,int);
int n,*a,i;

void main()
{
	int m;
	double duration;
	clrscr();
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
	printf("Enter the range:\n");
	scanf("%d",&m);
	a=(int*)malloc(sizeof(int)*n);
	if(a==NULL)
	{
		printf("Insufficient memory");
	}
	else
	{
		for(i=0;i<n;i++)
		{
			a[i]=rand()%m;
			printf("a[%d]=%d\n",i,a[i]);
		}
		getch();
		start=clock();
		quick_sort(0,n-1);
		delay(500);
		end=clock();
		duration=((double)(end)-(double)(start))/(CLK_TCK);
		printf("The Sorted Elements are:\n");
		for(i=0;i<n;i++)
		printf("%d\n",a[i]);
		printf("\n The time efficiency is:%2.5f\n",duration);
	}
	free(0);
	getch();
}
void quick_sort(int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=partation(low,high);
		quick_sort(low,mid-1);
		quick_sort(mid+1,high);
	}
}
int partation(int low,int high)
{
	int up,down,pivot,temp;
	up=low;
	down=high;
	pivot=low;
	while(up<down)
	{
		while(a[pivot]>=a[up] && up<=high)
		up++;
		while(a[pivot]<a[down] && down>=low)
		down--;
		if(up<down)
		{
			temp=a[up];
			a[up]=a[down];
			a[down]=temp;
		}
	}
	if(pivot != down)
	{
		temp=a[pivot];
		a[pivot]=a[down];
		a[down]=temp;
	}
	return(down);
}

Input:
5
100