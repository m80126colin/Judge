#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int k, n, t, ans;
	for (scanf("%d", &k); k; k--)
	{
		scanf("%d", &n);
		for (ans = t = 1; t % n; ans++)
			t = (t * 10 + 1) % n;
		printf("%d\n", ans);
	}
}