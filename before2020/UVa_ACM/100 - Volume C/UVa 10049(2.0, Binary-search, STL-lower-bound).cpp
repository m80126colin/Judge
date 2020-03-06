/**
 *  @judge UVa
 *  @id 10049
 *  @tag 2.0, Binary search, STL lower bound
 */
#include <stdio.h>
#include <iostream>
#include <algorithm>
#define N 1000010
using namespace std;

long long len[N];

int main()
{
	len[1] = 1;
	len[2] = 3;
	for (int i = 3; i < N; i++)
	{
		int j = lower_bound(len, len + i, i) - len;
		len[i] = len[i - 1] + j;
	}
	int n;
	while (scanf("%d", &n), n)
	{
		printf("%d\n",lower_bound(len, len + N, n) - len);
	}
}