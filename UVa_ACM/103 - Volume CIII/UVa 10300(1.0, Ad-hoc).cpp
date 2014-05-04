#include <stdio.h>
#include <iostream>
using namespace std;

int n, f, a, b, c;
long long ans;

int main()
{
	for (scanf("%d", &n); n; n--)
	{
		for (scanf("%d", &f), ans = 0; f; f--)
		{
			scanf("%d%d%d", &a, &b, &c);
			ans += (long long) a * c;
		}
		printf("%lld\n", ans);
	}
}