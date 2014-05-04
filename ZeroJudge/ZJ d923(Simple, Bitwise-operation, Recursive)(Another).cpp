#include <stdio.h>
#include <iostream>
using namespace std;

long long sol(int i, int j, int k)
{
	if (!i && !j) return 1;
	int a, b;
	a = i & (1 << k);
	b = j & (1 << k);
	if (a)
	{
		if (b) return sol(i - (1 << k), j - (1 << k), k - 1) + ((long long) 1 << (2 * k));
		else return sol(i - (1 << k), j, k - 1) + 3 * ((long long) 1 << (2 * k));
	}
	else if (b) return sol(i, j - (1 << k), k - 1) + 2 * ((long long) 1 << (2 * k));
	else return sol(i, j, k - 1);
}

int main()
{
	int i, j;
	while (scanf("%d%d", &i, &j) != EOF)
		printf("%lld\n", sol(i - 1, j - 1, 30));
}