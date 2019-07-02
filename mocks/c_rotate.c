#include<stdio.h>
#include<stdlib.h>

int print(int **arr, int n)
{
	int i,j;
	for(i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int main()
{
	int n,i,j,swap;
	int **arr;
	int k=1;

	printf("Enter the number of rows and column\n");
	scanf("%d",&n);
	arr = (int **) malloc (8*n);
	for (i=0; i<n; i++) {
		arr[i] = (int *) malloc (4*n);
	}

	for(i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			arr[i][j] = k;
			printf("%d",k);
			k++;
		}
	}
	printf("The array is:\n");
	print(arr,n);
	printf("transpose of array is:\n");
	for(i=0; i<n; i++) {
		for (j=i; j<n; j++) {
			if(i==j)
				continue;
			swap = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = swap;
		}
	}
	print(arr,n);
	printf("Rotated Matrix is:\n");

	return 0;
}
