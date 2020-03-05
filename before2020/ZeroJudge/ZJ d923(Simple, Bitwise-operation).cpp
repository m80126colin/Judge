#include <stdio.h>
#include <iostream>
using namespace std;

long long sol(int i, int j)
{
	int k, a, b;
	long long ans = 1;
	for (k = 30; k >= 0; k--)
	{
		a = i & (1 << k);
		b = j & (1 << k);
		if (a)
		{
			if (b) ans += ((long long) 1 << (2 * k));
			else ans += 3 * ((long long) 1 << (2 * k));
		}
		else if (b) ans += 2 * ((long long) 1 << (2 * k));
	}
	return ans;
}

int main()
{
	int i, j;
	while (scanf("%d%d", &i, &j) != EOF)
		printf("%lld\n", sol(i - 1, j - 1));
}