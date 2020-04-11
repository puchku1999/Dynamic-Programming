#include<stdio.h>
int MatrixChainMultiplication(int p[], int m, int n);
 
void main()
{
    int i;
    int arr[]={2,3,5,10};
    int n=4;
    int m=15;
 
    printf("Total number of ways are %d\n ", MatrixChainMultiplication(arr, m ,n));
 
}

 
int MatrixChainMultiplication(int arr[4], int m, int n)
{
   int a[n][m+1];
    int i, j;

    for(j=0;j<m;j++)
    {
    	if(j%arr[0]==0)
    		a[0][j]=1;
    	else
    		a[0][j]=0;	
    }		

    for (i=1; i<n; i++)
    {
        for (j=0; j<=m; j++)
        {
        	if(arr[i]>j)
            		a[i][j] = a[i-1][j];  //assigning to previous value
	    	else
                	a[i][j] = a[i-1][j] + a[i][j-arr[i]]; 
        }
    }
 
    return a[n-1][m];
 
}
