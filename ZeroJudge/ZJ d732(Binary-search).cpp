#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#define N 1000010
#define M 100010
using namespace std;

char s[N];
int a[M], offset, len;

inline int binary(int left, int right, int num)
{
	int middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (a[middle] == num) return middle;
		else if (a[middle] < num) left = middle + 1;
		else right = middle - 1;
	}
	return 0;
}

inline void get_line()
{
	gets(s); offset = 0; len = strlen(s);
	return ;
}

inline void getd(int &d)
{
	int flag = 0;
	for (; offset < len && !isdigit(s[offset]); offset++)
		if (s[offset] == '-') flag = 1;
	d = 0;
	do {
		d *= 10; d += s[offset] - '0';
	} while (++offset < len && isdigit(s[offset]));
	if (flag == 1) d = -d;
	return;
}

int main()
{
	int n, k;
	int i, num;
	while (scanf("%d%d", &n, &k) != EOF)
	{
		getchar();
		for (get_line(), i = 1; i <= n; i++) getd(a[i]);
		for (get_line(), i = 0; i < k; i++)
		{
			getd(num);
			printf("%d\n", binary(1, n, num));
		}
	}
}