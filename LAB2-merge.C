#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
#define maxi 20000

void mergesort(int a[],int ,int );
void merge(int a[],int ,int ,int, int );

int n;
int a[maxi];

void main()
{
    int i=0,m=0;
    double duration;
    clock_t start,end;
    clrscr();
    printf("Enter number of elements:\n");
    scanf("%d",&n);
    printf("Enter the range:\n");
    scanf("%d",&m);
    printf("Numbers are:\n");
    for(i=0;i<n;i++)
    {
	a[i]=(int)rand()%m;
	printf("%d\t",a[i]);
    }

    getch();

    start=clock();
    //scanf("%d",&m);

    mergesort(a,0,n-1);
    delay(500);
    end=clock();
    duration=( (double) (end)-(double)(start))/(CLK_TCK);
    //printf("/n duration= %2.5f /n",duration);
    printf("\n Sorted Elements are \n");

    for(i=0;i<n;i++)
	printf("%d\t",a[i]);

    printf("\n time taken by mergesort is %2.5f \n",duration);
    free(0);
    getch();
}
void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
	mid=(low+high)/2;
	mergesort(a,low,mid);
	mergesort(a,mid+1,high);
	merge(a,low,mid,mid+1,high);
    }
}
void merge(int a[],int i1,int j1,int i2, int j2)
{
    int i=0,j=0,k=0;//,h=0;
	int temp[20000];
    i=i1;
    j=i2;
    while(i<=j1 && j<=j2)
    {
	if(a[i]<a[j])
	    temp[k++]=a[i++];
	else
	    temp[k++]=a[j++];
    }
    while(i<=j1)
	temp[k++]=a[i++];
    while(j<=j2)
	temp[k++]=a[j++];

    for(i=i1, j=0; i<=j2; i++,j++)
		a[i]=temp[j];
    }

Input:
6
100000