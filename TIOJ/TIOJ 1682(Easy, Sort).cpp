#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

inline int getd(int &d)
{
	char ch;
	while (!isdigit(ch = getchar()))
		if (ch == EOF) return EOF;
	d = 0;
	do
	{
		d *= 10; d += ch - '0';
	} while (isdigit(ch = getchar()));
	return 0;
}

int main()
{
	int n, i, t;
	vector <int> a;
	while (getd(n) != EOF)
	{
		a.clear();
		for (i = 0; i < n; i++)
			getd(t), a.push_back(t);
		sort(a.begin(), a.end());
		printf("%d", a[0]);
		for (i = 1; i < n; i++)
			printf(" %d", a[i]);
		puts("");
	}
}