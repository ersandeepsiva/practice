#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,n,pairs=0;
	int *ar = NULL;
	int *hash = NULL;

	scanf("%d", &n);

	if(100 < n && 1 > n) 
		return -1;
	ar = (int *)malloc(n * (sizeof(int)));
	if(NULL == ar) {
		perror("mem alloc failed");
		return -1;
	}
	hash = (int *)calloc(n, (sizeof(int)));
	if(NULL == hash) {
		perror("mem alloc failed");
		free(ar);
		ar=NULL;
		return -1;
	}
	for(i=0; i<n; i++) {
		scanf("%d",&ar[i]);
	}
	for(i=0; i<n; i++) {
		hash[ar[i]]++;
		if((hash[ar[i]] % 2) == 0) {
			pairs++;
		}
	}
	printf("%d\n",pairs);
	free(hash);
	free(ar);
	hash=NULL;
	ar=NULL;
	return 0;
}
