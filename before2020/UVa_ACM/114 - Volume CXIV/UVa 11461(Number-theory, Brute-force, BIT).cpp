/**
 *  @judge UVa
 *  @id 11461
 *  @tag Number theory, Brute force, BIT
 */
#include <stdio.h>
#include <iostream>
#define M 100010
using namespace std;

int a[M];

int lowbit(int t)
{
	return t & (-t);
}

int getsum(int t)
{
	int sum = 0;
	while (t > 0)
	{
		sum += a[t];
		t -= lowbit(t);
	}
	return sum;
}

void insert(int t, int d)
{
	while (t < M)
	{
		a[t] += d;
		t += lowbit(t);
	}
	return;
}

int main()
{
	int i, a, b;
	for (i = 1; i * i < M; i++)
		insert(i * i, 1);
	while (scanf("%d%d", &a, &b), (a || b))
		printf("%d\n", getsum(b) - getsum(a - 1));
}