#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#define N 110
using namespace std;

int n, m, k, s, mxlen;
string list[N];

inline void putline()
{
	puts("------------------------------------------------------------");
	return;
}

int main()
{
	//freopen("UVa_400.txt", "w+", stdout);
	int i, j;
	while (scanf("%d", &n) != EOF)
	{
		mxlen = 0;
		for (i = 0; i < n; i++)
		{
			cin >> list[i];
			mxlen = max(mxlen, (int) list[i].size());
			/*for (j = 0; j < i; j++)
				if (list[i] == list[j]) i--, n--;*/
		}
		sort(list, list + n);
		m = 62 / (mxlen + 2); //5
		k = n / m; // 19 / 5 = 3
		s = n % m; // 19 % 5 = 4
		if (s) k++, s = n % k;
		putline();
		for (i = 0; i < k; i++)
		{
			for (j = 0; j < m && i + j * k < n; j++)
			{
				int tmp = list[i + j * k].size();
				cout << list[i + j * k];
				while (tmp < mxlen && tmp < 60) putchar(' '), tmp++;
				while (j + 1 < m && tmp < mxlen + 2 && tmp < 60) putchar(' '), tmp++;
			}
			if (i < s && i + j * k < n)
			{
				int tmp = list[i + j * k].size();
				cout << list[i + j * k];
				while (tmp < mxlen + 2 && tmp < 60) putchar(' '), tmp++;
			}
			puts("");
		}
	}
}