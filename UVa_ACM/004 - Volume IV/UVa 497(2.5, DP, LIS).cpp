#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define N 10010
using namespace std;

int n, m, v[N], table[N], from[N];

inline int LIS()
{
	int i, j, ans = 0;
	for (i = 0; i < m; i++) table[i] = 1;
	memset(from, 0, sizeof(from));
	for (j = 1; j < m; j++)
		for (i = j - 1; i >= 0; i--)
			if (v[j] > v[i] && table[j] < table[i] + 1)
			{
				table[j] = table[i] + 1;
				from[j] = i;
				if (table[j] > table[ans]) ans = j;
			}
	return ans;
}

inline void print(int i)
{
	if (table[i] != 1) print(from[i]);
	printf("%d\n", v[i]);
	return ;
}

int main()
{
	int tmp;
	for (scanf("%d", &n); n; n--)
	{
		m = 0;
		while (scanf("%d", &v[m]))
		{
			cin.ignore(1);
			m++;
			if (cin.peek() == '\n' || cin.peek() == EOF)
				break;
		}
		tmp = LIS();
		printf("Max hits: %d\n", table[tmp]);
		print(tmp);
		if (n > 1) puts("");
	}
}