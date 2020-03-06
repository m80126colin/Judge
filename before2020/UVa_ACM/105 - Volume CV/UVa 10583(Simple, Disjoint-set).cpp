/**
 *  @judge UVa
 *  @id 10583
 *  @tag Simple, Disjoint Set
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int s[50001];

inline int find(int x)
{
	while (x != s[x]) x = s[x];
	return x;
}

int main() {
	int n, m, t, i, j, k, l;
	for (t = 1; scanf("%d%d", &n, &m) , (n || m); t++)
	{
		for (i = 1; i <= n; i++) s[i] = i;
		for (; m; m--) {
			scanf("%d%d", &i, &j);
			k = find(i), l = find(j);
			if (s[k] != s[l]) n--;
			s[k] = s[l];
		}
		printf("Case %d: %d\n", t, n);
	}
}