#include <cstdio>
#include <iostream>
using namespace std;

#define MAXN 10000001
#define MAX  10001000
int SOD[MAX], TOT[MAX];

void init()
{
	int tmp, sum;
	for (int i = MAXN - 1; i; i--)
	{
		for (tmp = sum = i; tmp; tmp /= 10)
			sum += tmp % 10;
		SOD[sum] = i;
		TOT[sum] = 1;
	}
	for (int i = 1; i < MAX; i++)
		TOT[i] += TOT[i - 1];
	return ;
}

int main()
{
	int t, cnt, a, b;
	char cmd[110];
	init();
	for (scanf("%d\n", &t), cnt = 1; cnt <= t; cnt++)
	{
		gets(cmd);
		printf("Case %d: %d\n", cnt, (sscanf(cmd, "%d%d", &a, &b) == 2)? (b - a + 1) - (TOT[b] - TOT[a - 1]): (SOD[a]?SOD[a]:-1));
	}
}