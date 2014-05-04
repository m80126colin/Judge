#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, sum;
int *coin;

int main()
{
	int t1, t2;
	for (int cnt = 1; scanf("%d", &n), n; cnt++)
	{
		coin = new int[n];
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d.%d", &t1, &t2);
			coin[i] = t1 * 100 + t2;
			sum += coin[i];
		}
		sort(coin, coin + n);
		int avg = sum / n, res = sum % n;
		int ans = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (res)
			{
				if (coin[i] > avg + 1)
				{
					ans += coin[i] - (avg  + 1);
					res--;
				}
			}
			else
			{
				if (coin[i] > avg)
				{
					ans += coin[i] - avg;
				}
			}
		}
		t1 = ans / 100;
		t2 = ans % 100;
		printf("$%d.%02d\n", t1, t2);
		delete coin;
	}
}