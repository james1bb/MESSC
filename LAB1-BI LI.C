#include<stdio.h>
#include<conio.h>
#include<time.h>
clock_t start,end;
int n,*a;
//binary search
int binary(int *a,int l,int n,int key)
{
 int mid;
 mid=(l+n)/2;
 if(l>n)
 return -1;
 else
 {
 if(key==a[mid])
  return mid;
  else if(key<a[mid])
   binary(a,l,mid-1,key);
   else if(key>a[mid])
   binary(a,mid+1,n,key);
   }
  }
   //linear search
  int linearsearch(int *a,int n,int l,int key)
  {
   if(l>n)
     return -1;
     else if(key==a[l])
      return l;
      else
      linearsearch(a,n,l+1,key);
      }
      void sort(int n)
      {
       int i,j,t;
       for(i=0;i<n;i++)
       {
	for(j=0;j<n;j++)
	{
	 if(a[i]<a[j])
	 {
	  t=a[i];
	  a[i]=a[j];
	  a[j]=t;
	  }
	 }
	}
       }
       void main()
       {
	 int m,key,i,pos,ch;
	 clrscr();
	 printf("\n enter thr no of elements:");
	 scanf("%d",&n);
	 printf("enter the range:");
	 scanf("%d",&m);
	 //dynamic allocation of memory
	 a=(int*)malloc(sizeof(int)*n);
	 if(a==NULL)
	 printf("insufficient memory");
	 else
	 {
	  //generate nos randomly
	  for(i=0;i<n;i++)
	  {
	   a[i]=rand()%m;
	   printf("a[%d=%d\n",i,a[i]);
	   }
	   sort(n);
	   printf("\nafter sorting\n");
	   for(i=0;i<n;i++)
	   {
	   printf("%d\t",a[i]);
	   }
	   while(1)
	   {
	     printf("\n1.binary\n");
	     printf("\n2.linear\n");
	     printf("\n3.exit\n");
	     printf("\nenter the choice\n");
	     scanf("%d",&ch);
	     switch(ch)
	     {
	      case 1:start=clock();
		     printf("\nenter the key element\n");
		     scanf("%d",&key);
		     pos=binary(a,0,n-1,key);
		     if(pos>=0)
		     {
		      printf("search is sucessful at %d",pos+1);
		      }
		      else
		      {
		      printf("unsucessful\n");
		      }
		      end=clock();
		      printf("\ntime spent=%f\n",(end-start)/(CLK_TCK));
		      break;
	     case 2: start=clock();
		     printf("\nenter the key element\n");
		     scanf("%d",&key);
		     pos=linearsearch(a,n-1,0,key);
		     if(pos>=0)
		     {
		      printf("search is sucessful at %d",pos+1);
		      }
		      else
		      {
		      printf("unsucessful\n");
		      }
		      end=clock();
		      printf("\ntime spent=%f\n",(end-start)/(CLK_TCK));
		      getch();
		      break;
	    case 3:exit(0);
	    default:printf("input correction\n");
		     break;
	   }
	   }
	   }
	   free(a);
	   getch();
	   }
	   
Input:
6
10

1
2

2
6

3