#include <stdio.h>
#include <string.h>
#include <iostream>
#define N 10010
using namespace std;

int group[N];

inline int find(int x)
{
	return (group[x] == x)? x: (group[x] = find(group[x]));
}

inline void uni(int x, int y)
{
	int a = find(x), b = find(y);
	if (a != b) group[a] = b;
	return ;
}

int main()
{
	int i, j;
	int t, n, a, b;
	char ch;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++) group[i] = i;
		i = j = 0;
		while (1)
		{
			cin >> ch;
			scanf("%d%d", &a, &b);
			if (ch == 'c') uni(a, b);
			else if (ch == 'q')
			{
				if (find(a) == find(b)) i++;
				else j++;
			}
			while (cin.peek() != '\n' && cin.peek() != EOF)
				getchar();
			getchar();
			if (cin.peek() == '\n' || cin.peek() == EOF)
				break;
		}
		printf("%d,%d\n", i, j);
		if (t > 1) puts("");
	}
}