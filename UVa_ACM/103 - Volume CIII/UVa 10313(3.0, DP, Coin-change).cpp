#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAXN 301
#define MAXK 1001
#define MAXC MAXN
long long dp1[MAXN], dp2[MAXN][MAXK];

int main()
{
	int i, j, k;

	dp1[0] = 1;
	for (i = 1; i < MAXC; i++)
		for (j = i; j < MAXN; j++)
			dp1[j] += dp1[j - i];

	dp2[0][0] = 1;
	for (i = 1; i < MAXC; i++)
		for (j = i; j < MAXN; j++)
			for (k = 1; k < MAXK; k++)
				if (dp2[j - i][k - 1])
					dp2[j][k] += dp2[j - i][k - 1];
	for (j = 0; j < MAXN; j++)
		for (k = 1; k < MAXK; k++)
			dp2[j][k] += dp2[j][k - 1];
	int ctnl;
	char cmd[110];
	while (gets(cmd) != NULL)
	{
		ctnl = sscanf(cmd, "%d%d%d", &i, &j, &k);
		if (ctnl == 1) printf("%lld\n", dp1[i]);
		else if (ctnl == 2) printf("%lld\n", dp2[i][j]);
		else printf("%lld\n", dp2[i][k] - (j != 0) * dp2[i][j - 1]);
	}
}