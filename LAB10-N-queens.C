#include<stdio.h> 
int x[20],n,k=1; 
void nqueens();  
void main() 
{   
  int i,j; 
    clrscr(); 
    printf("Enter the number of queens : ");      
    scanf("%d",&n); 
    nqueens(); 
    if(k>n) 
    { 
       printf("\nQueens placement on the chess board:\n");
        for(i=1;i<=n;i++) 
       { 
 	  for(j=1;j<=n;j++)
  	   if( j== x[i])
  	      printf("Q%d\t",i);
  	   else
              printf("*\t"); 
 	      printf("\n"); 
 	} 
     }  
   else 
       printf("Queens cannot be placed");     
       getch(); 
}  
void nqueens() 
{    
 int i; 
    while(k<=n && k>=0) 
    { 
    x[k] += 1; 
  /*TWO QUEENS CANNOT BE PLACED IN THE SAME COLUMN 
      OR IN THE SAME DIAGONALS*/ 
    
     for(i=1;i<k&&x[k]<=n;i++) 
          if((x[i] == x[k]) || (abs(x[i]-x[k]) == abs(i-k))) 
	      { 
 	 	  x[k] += 1;  	 	 		
                                i=0; 
 	       } 
 	    if(x[k] > n) 
 	        --k;  	   
         else  	  
            { 
 	 	  k++; 
 	 	  x[k] = 0; 
 	    } 
     } 
}


Input:
4