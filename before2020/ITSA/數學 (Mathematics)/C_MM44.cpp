#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n, m, ans;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (ans = 0; m >= 10; m /= 10)
			if (m % 100 == n) ans++;
		printf("%d\n", ans);
	}
}