/**
 *  @judge UVa
 *  @id 100
 *  @tag 1.0, Brute force, Collatz conjecture, 3n+1
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int len(int x)
{
	int ans;
	for (ans = 1; x != 1; ans++)
	{
		if (x & 1) x = 3 * x + 1;
		else x >>= 1;
	}
	return ans;
}

int main()
{
	int i, j, mx;
	while (scanf("%d%d", &i, &j) != EOF)
	{
		printf("%d %d ", i, j);
		if (j < i) swap(i, j);
		for (mx = 1; i <= j; i++)
			mx = max(mx, len(i));
		printf("%d\n", mx);
	}
}