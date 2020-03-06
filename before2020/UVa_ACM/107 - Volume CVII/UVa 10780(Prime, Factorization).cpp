/**
 *  @judge UVa
 *  @id 10780
 *  @tag Prime, Factorization
 */
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#define PMAX 5010
int p[PMAX], pr[PMAX], pn;

void PrimeSieve()
{
	pn = 0;
	p[0] = p[1] = 1;
	int i, j;
	for (i = 2; i <= 70; i++)
		if (!p[i])
		{
			pr[pn] = i;
			pn++;
			for (j = 2; j * i < PMAX; j++)
				p[j * i] = 1;
		}
	for (; i < PMAX; i++)
		if (!p[i])
		{
			pr[pn] = i;
			pn++;
		}
	return;
}

int main()
{
	int m, n, t, cnt, i;
	int tmp, tmp2, f, ans;
	PrimeSieve();
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		printf("Case %d:\n", cnt);
		scanf("%d%d", &m, &n);
		ans = 0;
		for (i = 0; i < pn && p[i] <= m; i++)
		{
			if (m % pr[i] == 0)
			{
				for (tmp = 0; m % pr[i] == 0; m /= pr[i]) tmp++;
				for (tmp2 = 0, f = pr[i]; n / f; f *= pr[i])
				{
					tmp2 += n / f;
					if ((long long) f * pr[i] > 2147483647) break;
				}
				if (!ans) ans = tmp2 / tmp;
				else ans = min(ans, tmp2 / tmp);
			}
		}
		if (ans) printf("%d\n", ans);
		else puts("Impossible to divide");
	}
}