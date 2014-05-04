#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 1010
int p[MAX], n, tot, res;

int main()
{
	int tmp, i, cnt, ans;
	while (scanf("%d", &n), n)
	{
		tot = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d.%d", &p[i], &tmp);
			p[i] *= 100;
			p[i] += tmp;
			tot += p[i];
		}
		res = tot % n;
		tot /= n;
		for (ans = cnt = i = 0; i < n; i++)
		{
			if (p[i] > tot)
			{
				ans += p[i] - tot;
				if (cnt < res)
				{
					ans--;
					cnt++;
				}
			}
		}
		printf("$%d.%02d\n", ans / 100, ans % 100);
	}
}