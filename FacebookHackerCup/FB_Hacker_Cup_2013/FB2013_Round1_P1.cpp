#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10010
#define MOD 1000000007LL
int n, k;
long long ans, a[MAX], table[MAX][MAX];

void init()
{
	int i, j;
	memset(table, 0, sizeof(table));
	table[0][0] = 1;
	for (i = 1; i < MAX - 1; i++)
		for (j = 0; j <= i; j++)
			if (j == 0 || j == i) table[i][j] = 1;
			else table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
	return ;
}

void sol()
{
	int i;
	for (i = n; i >= k; i--)
	{
		ans += (table[i - 1][k - 1] * a[i]) % MOD;
		ans %= MOD;
	}
	return ;
}

int main()
{
	freopen("card_game.txt", "r", stdin);
	freopen("card_game.out", "w+", stdout);
	int t, cnt, i;
	init();
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%d%d", &n, &k);
		for (i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		sort(a + 1, a + n + 1);
		ans = 0;
		sol();
		printf("Case #%d: %lld\n", cnt, ans);
	}
}