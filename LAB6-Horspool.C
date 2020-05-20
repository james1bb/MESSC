#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 256

char text[100],pat[50];
int m,n;
int d[256];
void shift_tab(char pat[])
{
	int i=0;
	for(i=0;i<256;i++)
	{
		d[i]=m;
	}
	for(i=0;i<m-1;i++)
	{
		d[pat[i]]=m-i-1;
	}
}
int search()
{
	int k,i,j;
	n=strlen(text);
	m=strlen(pat);
	shift_tab(pat);
	if(m>n)
	{
		printf("pattern length is more than the text \n");
		getch();
		//exit(0);
	}
	i=m-1;
	while(i<n)
	{
		k=0;
		while((k<m) && (pat[m-1-k]==text[i-k]))
		{
			k++;
		}
		if(k==m)
			return(i-m+1);
		else
			i=i+d[text[i]];
	}
	return(-1);
}
void main()
{
	int pos;
	clrscr();
	printf("Enter the text:\n");
	gets(text);
	printf("Enter the pattern:\n");
	gets(pat);
	printf("\n text=%s\n",text);
	printf("\n pattern=%s\n",pat);
	pos=search();
	if(pos>=0)
	{
		printf("\n Pattern Found at:%d",pos+1);
	}
	else
	{
		printf("\n Pattern not found\n");
	}
	getch();
}


Input:
Your Name

am