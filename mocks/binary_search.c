#include<stdio.h>
#include<stdlib.h>

int binary_search(int a[], int n, int f)
{
	int ind = (int)n/2;
	while(a[ind] != f) {
		n=n-n/2;
		if(a[ind] < f)
			ind += n/2;
		else
			ind -= n/2;
	}
	printf("the ind is %d\n",ind);
	return 0;
}

int main()
{
	int i,j,n,f,*a = NULL;

	scanf("%d",&n);

	a = (int*)malloc(sizeof(int)*n);

	for(i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}

	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if(a[j] < a[i]) {
				a[i] = a[i] + a[j];
				a[j] = a[i] - a[j];
				a[i] = a[i] - a[j];
			}
		}
	}
	for (i=0; i < n; i++) {
		printf("%d\t",a[i]);
	}
	printf("\nEnter number to find\n");
	scanf("%d",&f);
	binary_search(a, n, f);
	return 0;
}
