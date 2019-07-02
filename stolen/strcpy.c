#include<stdio.h>

int my_strcpy(char * restrict a, char * restrict b)
{
	while((*a ++ = *b++) != 0);
	return 0;
}
int main() {
	char a[10] = {0};
	char *b = "hello";

	my_strcpy(a,b);
	printf("%s\n",a);
	return 0;
}
