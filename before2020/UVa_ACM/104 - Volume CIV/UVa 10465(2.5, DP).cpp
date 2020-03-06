/**
 *  @judge UVa
 *  @id 10465
 *  @tag 2.5, DP
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int m, n, t, ans, num;

int main()
{
	int i, j;
	while (scanf("%d%d%d", &m, &n, &t) != EOF)
	{
		ans = num = 0;
		for (i = t / m; i >= 0; i--)
		{
			j = (t - m * i) / n;
			if (i * m + j * n > ans)
			{
				ans = i * m + j * n;
				num = i + j;
			}
			else if (i * m + j * n == ans && i + j > num)
				num = i + j;
		}
		printf("%d", num);
		if (t - ans) printf(" %d", t - ans);
		puts("");
	}
}