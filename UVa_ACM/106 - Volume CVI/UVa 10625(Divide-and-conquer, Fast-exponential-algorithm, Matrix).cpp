#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 130
unsigned long long mat[MAX][MAX], cmat[MAX][MAX], ans[MAX][MAX], v[MAX];
char rule[MAX];

void mat_mul(unsigned long long m1[MAX][MAX], unsigned long long m2[MAX][MAX])
{
	int i, j, k;
	static unsigned long long tmp1[MAX][MAX], tmp2[MAX][MAX];
	for (i = 0; i < MAX; i++)
		for (j = 0; j < MAX; j++)
		{
			tmp1[i][j] = m1[i][j];
			tmp2[i][j] = m2[i][j];
		}
	for (i = 0; i < MAX; i++)
		for (j = 0; j < MAX; j++)
		{
			m1[i][j] = 0;
			for (k = 0; k < MAX; k++)
				m1[i][j] += tmp1[i][k] * tmp2[k][j];
		}
	return ;
}

void input()
{
	int r, i, len;
	memset(mat, 0, sizeof(mat));
	for (i = 0; i < MAX; i++)
		mat[i][i] = 1;
	for (scanf("%d", &r); r; r--)
	{
		scanf("%s", rule);
		len = strlen(rule);
		mat[rule[0]][rule[0]] = 0;
		for (i = 3; i < len; i++)
			mat[rule[i]][rule[0]]++;
	}
	return ;
}

void output()
{
	unsigned long long sol;
	int q, i, n, len;
	char init[MAX], ch[2];
	for (scanf("%d", &q); q; q--)
	{
		memcpy(cmat, mat, sizeof(mat));
		memset(ans, 0, sizeof(ans));
		for (i = 0; i < MAX; i++)
			ans[i][i] = 1;
		scanf("%s%s%d", init, ch, &n);
		while (n)
		{
			if (n & 1) mat_mul(ans, cmat);
			mat_mul(cmat, cmat);
			n >>= 1;
		}
		memset(v, 0, sizeof(v));
		len = strlen(init);
		for (i = 0; i < len; i++)
			v[init[i]]++;
		sol = 0;
		for (i = 0; i < MAX; i++)
			sol += ans[ch[0]][i] * v[i];
		printf("%llu\n", sol);
	}
	return ;
}

int main()
{
	int t;
	for (scanf("%d", &t); t; t--)
	{
		input();
		output();
	}
}