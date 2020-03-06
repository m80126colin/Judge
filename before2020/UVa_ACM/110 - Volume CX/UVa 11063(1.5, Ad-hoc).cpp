/**
 *  @judge UVa
 *  @id 11063
 *  @tag 1.5, Ad hoc
 */
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

#define N 110
int n, b[N];

int isb2()
{
	int i, j;
	if (b[0] < 1) return 0;
	for (i = 1; i < n; i++)
		if (b[i - 1] >= b[i])
			return 0;
	int c[20010] = {0};
	for (i = 0; i < n; i++)
		for (j = i; j < n; j++)
			if (c[b[i] + b[j]]) return 0;
			else c[b[i] + b[j]] = 1;
	return 1;
}

int main()
{
	for (int cnt = 1; scanf("%d", &n) != EOF; cnt++)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &b[i]);
		printf("Case #%d: ", cnt);
		if (isb2()) puts("It is a B2-Sequence.");
		else puts("It is not a B2-Sequence.");
		puts("");
	}
}