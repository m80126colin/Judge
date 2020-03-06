/**
 *  @judge TIOJ
 *  @id 1287
 *  @tag Easy, Sort, STL
 */
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>
using namespace std;

int a[1000010], n;

inline void getd(int &d)
{
	int flag = 0;
	char ch;
	while (!isdigit(ch = getchar()))
		if (ch == '-') flag = 1;
	d = 0;
	do {
		d *= 10; d += ch - '0';
	} while (isdigit(ch = getchar()));
	if (flag) d = -d;
	return ;
}

int main()
{
	int i;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++) getd(a[i]);
		sort(a, a + n);
		for (i = 0; i < n; i++)
		{
			if (i) putchar(' ');
			printf("%d", a[i]);
		}
		puts("");
	}
}