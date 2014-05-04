#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

long n, k;

void work()
{
	double ans = 0;
	double wDP[70][70] = {0};
	double bDP[70][70] = {0};
	double wlen[70] = {0}, blen[70] = {0};
	long   top = 1, top2 = 0;
	long   i, j;
	wlen[1] = n;
	while (wlen[top] > 2)
	{
		wlen[top + 1] = wlen[top] - 2;
		wlen[top + 2] = wlen[top] - 2;
		top += 2;
	}
	for (i = 1, j = top; i <= top / 2; i++, j--)
	{
		wlen[0] = wlen[i];
		wlen[i] = wlen[j];
		wlen[j] = wlen[0];
	}
	for (i = 0; i <= top; i++)
		wDP[i][0] = 1;
	for (i = 1; i <= top; i++)
		for (j = 1; j <= wlen[i]; j++)
			wDP[i][j] = (wlen[i] - j + 1) * wDP[i-1][j-1] + wDP[i-1][j];

	while(blen[top2] + 2 <= n)
	{
		blen[top2 + 1] = blen[top2] + 2;
		blen[top2 + 2] = blen[top2] + 2;
		top2 += 2;
	}
	if (n % 2 == 0) top2--;
	for (i = 0; i <= top2; i++)
		bDP[i][0] = 1;
	for (i = 1; i <= top2; i++)
		for (j = 1; j <= blen[i]; j++)
			bDP[i][j] = (blen[i]-j+1) * bDP[i-1][j-1] + bDP[i-1][j];  

	for (i = 0; i <= k; i++)
		if (i <= wlen[top] && k - i <= blen[top2])
			ans += wDP[top][i] * bDP[top2][k-i];
	printf("%.lf\n", ans);
}
int main()
{
	while(scanf("%ld%ld",&n,&k)!=EOF)
	{
		if(n==0&&k==0) break;
		work();
	}
	return 0;
}