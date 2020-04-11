#include<stdio.h>

int max(int a, int b){
	if(a>b)
		return a;
	else
		return b;	
}

int lcs(char *a,char*b, int p, int q)
{
	int arr[p+1][q+1];
	int i,j;
	for(i=0;i<=q;i++){
		arr[p][i]=0;
	}
	for(i=0;i<=p;i++){
		arr[i][q] =0;
	}
	for(j=q-1;j>=0;j--){
		for(i=p-1;i>=0;i--){
			if(a[i]==b[j])
			{
				arr[i][j] = 1+ arr[i+1][j+1];
			}
			else
				arr[i][j] = max(arr[i+1][j] , arr[i][j+1]);
		}
	}
	return arr[0][0];

}

int main()
{
char *a = "india";
char *b = "indonesia";

printf("The longest common subsequence size  is : %d\n",lcs(a,b,5,9));

}
