#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,j,iter,lim;
	int **arr;

	scanf("%d",&n);
	iter=n;
	arr = (int **)malloc(8*(2*n - 1));
	for(i=0; i < (2*n - 1); i++) {
		arr[i] = (int *)malloc(4*(2*n - 1));
	}
	lim = 2*n - 2;
	while(iter) {
		if(iter==1) {
			arr[n-iter][n-iter] = iter;
			break;
		}
		i=n-iter;
		for(j=n-iter; j<=lim; j++) {
			arr[i][j] = iter;
		}
		i=lim;
		for(j=n-iter; j<=lim; j++) {
			arr[i][j] = iter;
		}
		j=n-iter;
		for(i=n-iter; i<=lim; i++) {
			arr[i][j] = iter;
		}
		j=lim;
		for(i=n-iter; i<=lim; i++) {
			arr[i][j] = iter;
		}
		iter--;
		lim--;
	}
	for (i=0; i<(2*n - 1); i++) {
		for (j=0; j<(2*n - 1); j++) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	for (i=0; i < (2*n - 1); i++) {
		free(arr[i]);
		arr[i]=NULL;
	}
	free(arr);
	arr=NULL;
	return 0;
}
