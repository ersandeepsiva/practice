#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio_ext.h>

int swap(char *a, char *b)
{
	char tmp[64] = {0};

	memset(tmp, 0, sizeof(tmp));
	memcpy(tmp, a, strlen(a));
	memset(a, 0, strlen(a));
	memcpy(a, b, strlen(b));
	memset(b, 0, strlen(b));
	memcpy(b, tmp, strlen(tmp));
	return 0;
}

int lex_order(char *a, char*b)
{
	int j=0, i = 0;
	for (i=0; i < (strlen(a) > strlen(b) ? strlen(b):strlen(a)); i++) {
		if(a[i] == b[i]) {
			j++;
			continue;
		} else if(a[i] > b[i]) {
			swap(a,b);
			break;
		} else {
			break;
		}
	}
	if(j == (strlen(a) > strlen(b) ? strlen(b):strlen(a))) {
		if(strlen(a) > strlen(b))
			swap(a,b);
	}
	return 0;
}

int lex_order_rev(char *a, char *b)
{
	int j = 0, i = 0;
	for (i = 0; i < (strlen(a) > strlen(b) ? strlen(b) : strlen(a)); i++) {
		if (a[i] == b[i]) {
			j++;
			continue;
		} else if (a[i] < b[i]) {
			swap(a, b);
			break;
		} else {
			break;
		}
	}
	if (j == (strlen(a) > strlen(b) ? strlen(b) : strlen(a))) {
		if (strlen(a) < strlen(b))
			swap(a, b);
	}
	return 0;
}

int len_order(char *a, char *b)
{
	if(strlen(a) > strlen(b))
		swap(a,b);
	else if(strlen(a) == strlen(b))
		lex_order(a,b);
	return 0;
}

int dist_chars(char *a)
{
	int *count = NULL;
	int num = 0;

	count  = (int *)calloc(256, 4);
	if(!count)
		return -1;
	for(; *a; a++) {
		count[(int)*a]++;
		if(count[(int)*a] == 1)
			num++;
	}
	return num;
}

int dist_order(char *a, char *b)
{
	if(dist_chars(a) > dist_chars(b))
		swap(a,b);
	else if(dist_chars(a) == dist_chars(b))
		lex_order(a,b);
	return 0;
}

int sort_string(char **arr, int n, int (*compare_fn)(char *, char *))
{
	int i, j;
	for (i=0; i<n; i++) {
		for (j=i+1; j<n; j++) {
			if(compare_fn)
				compare_fn(arr[i], arr[j]);
		}
	}
	return 0;
}
int main()
{
	char **arr = NULL;
	int n,i;
	size_t sb;
	char buff[64] = {0};

	scanf("%d",&n);

	arr = (char **) malloc(sizeof(char *) * n);
	if(NULL == arr) {
		perror("DP allocation failed\n");
		return -1;
	}
	for (i=0; i<n; i++) {
		__fpurge(stdin);
		scanf("%s",buff);
		sb = strlen(buff);
		arr[i] = (char *)malloc(sizeof(char)*sb);
		strncpy(arr[i],buff,sb);
		memset(buff,0,sizeof(buff));
	}

	sort_string(arr, n, lex_order);
	printf("\n");
	for (i=0; i<n; i++) {
		printf("%s\n",arr[i]);
	}
	printf("\n");
	sort_string(arr, n, lex_order_rev);
	for (i=0; i<n; i++) {
		printf("%s\n",arr[i]);
	}
	printf("\n");
	sort_string(arr, n, len_order);
	for (i=0; i<n; i++) {
		printf("%s\n",arr[i]);
	}
	printf("\n");
	sort_string(arr, n, dist_order);
	for (i=0; i<n; i++) {
		printf("%s\n",arr[i]);
	}
	return 0;
}
