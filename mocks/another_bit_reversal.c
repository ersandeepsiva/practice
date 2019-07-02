#include<stdio.h>
#include<stdlib.h>

int binaryof(int n)
{
	int i;
	for (i=31; i >= 0; i--) {
		if((n>>i) & 1)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	return 0;
}
int main(int argc, char *argv[])
{
	unsigned int rev=0;
	unsigned int a = atoi(argv[1]);
	int bits = 31;

	binaryof(a);
	while(bits) {
		rev |= a&1;
		a=a>>1;
		rev=rev<<1;
		bits--;
	}
	binaryof(rev);
	printf("%u\n",rev);
	return 0;
}
