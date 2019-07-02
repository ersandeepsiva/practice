#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,i,j,iter,lim;
	char **arr;
	char alpha='!';

	scanf("%d",&n);
	iter=n;
	arr = (char **)malloc(8*(2*n - 1));
	for(i=0; i < (2*n - 1); i++) {
		arr[i] = (char *)malloc(1*(2*n - 1));
	}
	lim = 2*n - 1;
	while(iter) {
		if(iter==1) {
			arr[n-iter][n-iter] = alpha;
			break;
		}
		i=n-iter;
		for(j=n-iter; j<lim; j++) {
			arr[i][j] = alpha;
		}
		i=lim-1;
		for(j=n-iter; j<lim; j++) {
			arr[i][j] = alpha;
		}
		j=n-iter;
		for(i=n-iter; i<lim; i++) {
			arr[i][j] = alpha;
		}
		j=lim-1;
		for(i=n-iter; i<lim; i++) {
			arr[i][j] = alpha;
		}
		iter--;
		lim--;
		alpha++;
	}
	for (i=0; i<(2*n - 1); i++) {
		for (j=0; j<(2*n - 1); j++) {
			printf("%c ",arr[i][j]);
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
