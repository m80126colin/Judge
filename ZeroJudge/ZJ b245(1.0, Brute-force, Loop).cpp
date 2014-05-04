#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int t, n, nt, pre, next, mx, ans;
	for (scanf("%d", &t); t; t--)
	{
		ans = 1;
		mx = 0;
		for (scanf("%d", &n), nt = 0; nt < n; nt++)
		{
			scanf("%d", &next);
			if (nt)
			{
				if (mx < next - pre)
				{
					mx = next - pre;
					ans = nt;
				}
			}
			pre = next;
		}
		printf("%d\n", ans);
	}
}