/**
 *  @judge UVa
 *  @id 101
 *  @tag Simple, Simulation
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 30
int brick[MAX][MAX], num[MAX], pos[MAX], n, a, b;
char com[MAX], com2[MAX];

void init()
{
	int i;
	for (i = 0; i < n; i++)
	{
		num[i] = 1;
		pos[i] = brick[i][0] = i;
	}
	return ;
}

void print()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		printf("%d:", i);
		for (j = 0; j < num[i]; j++)
			printf(" %d", brick[i][j]);
		puts("");
	}
	return ;
}

void add(int n, int npos)
{
	brick[npos][num[npos]] = n;
	num[npos]++;
	pos[n] = npos;
	return ;
}

void clean(int n)
{
	int i = pos[n], j, tmp;
	for (j = 0; j < num[i]; j++)
		if (brick[i][j] == n) break ;
	tmp = j + 1;
	for (j++; j < num[i]; j++)
		add(brick[i][j], brick[i][j]);
	num[i] = tmp;
	return ;
}

void move(int n, int m)
{
	int i = pos[n], j = pos[m], k, tmp;
	for (k = 0; k < num[i]; k++)
		if (brick[i][k] == n) break;
	tmp = k;
	for (; k < num[i]; k++)
		add(brick[i][k], j);
	num[i] = tmp;
	return ;
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		init();
		while (scanf("%s", com), strcmp(com, "quit"))
		{
			scanf("%d%s%d", &a, com2, &b);
			if (pos[a] != pos[b])
			{
				if (strcmp(com2, "onto") == 0) clean(b);
				if (strcmp(com, "move") == 0) clean(a);
				move(a, b);
			}
		}
		print();
	}
}