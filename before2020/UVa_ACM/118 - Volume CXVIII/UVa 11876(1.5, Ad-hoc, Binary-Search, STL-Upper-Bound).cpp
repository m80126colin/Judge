/**
 *  @judge UVa
 *  @id 11876
 *  @tag 1.5, Ad-hoc, Binary Search, STL Upper Bound
 */
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

#define EPS 1e-7
int N[70010], n;

inline int NOD(int k)
{
	int i, len, ans = 0;
	len = sqrt((double) k) + EPS;
	for (i = 1; i <= len; i++)
	{
		if (k % i == 0)
		{
			ans++;
			if (i * i != k) ans++;
		}
	}
	return ans;
}

void init()
{
	N[0] = 1;
	for (n = 0; N[n] <= 1000000; n++)
		N[n + 1] = N[n] + NOD(N[n]);
	return ;
}


int BinarySearch(int key)
{
	int left, right, middle;
	left = 0, right = n;
	while (left < right)
	{
		middle = (left + right) / 2;
		if (key < N[middle])
			right = middle;
		else left = middle + 1;
	}
	return left;
}

int main()
{
	int t, cnt, a, b;
	init();
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%d%d", &a, &b);
		printf("Case %d: %d\n", cnt, BinarySearch(b) - BinarySearch(a - 1));
	}
}