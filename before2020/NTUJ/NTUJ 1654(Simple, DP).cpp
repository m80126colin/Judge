/**
 *  @judge NTUJ
 *  @id 1654
 *  @tag Simple, DP
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 510
int t, r, c;
int s[MAX][MAX], m[MAX][MAX];

int trial(int middle)
{
	int i, j;
	memset(m, 0, sizeof(m));
	m[1][1] = middle;
	for (i = 1; i <= r; i++)
		for (j = 1; j <= c; j++)
		{
			if (m[i][j] <= 0) continue;
			m[i + 1][j] = max(m[i + 1][j], m[i][j] + s[i + 1][j]);
			m[i][j + 1] = max(m[i][j + 1], m[i][j] + s[i][j + 1]);
		}
	return (m[r][c] > 0);
}

int sol(int left, int right)
{
	if (left == right) return left;
	int middle = (left + right) / 2;
	if (trial(middle)) return sol(left, middle);
	return sol(middle + 1, right);
}

int main()
{
	int i, j;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d", &r, &c);
		memset(s, 0, sizeof(s));
		for (i = 1; i <= r; i++)
			for (j = 1; j <= c; j++)
				scanf("%d", &s[i][j]);
		printf("%d\n", sol(1, 1000010));
	}
}