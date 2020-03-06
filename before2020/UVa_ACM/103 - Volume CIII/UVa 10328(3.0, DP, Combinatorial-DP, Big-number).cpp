/**
 *  @judge UVa
 *  @id 10328
 *  @tag 3.0, DP, Combinatorial DP, Big number
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 110
#define DIGIT 4
#define MOD 10000
#define MAXL 15
class bignum
{
public:
	int a[MAXL], len;
	bignum() {
		memset(a, 0, sizeof(a));
		len = 1;
	}
	bignum(int num) {
		memset(a, 0, sizeof(a));
		if (num == 0) len = 1;
		else
		{
			for (len = 0; num; len++)
			{
				a[len] = num % MOD;
				num /= MOD;
			}
		}
	}
	bignum operator + (const bignum &B)
	{
		bignum res;
		int g = 0;
		for (res.len = 0; res.len < max(len, B.len) || g; res.len++)
		{
			if (res.len < len) g += a[res.len];
			if (res.len < B.len) g += B.a[res.len];
			res.a[res.len] = g % MOD;
			g /= MOD;
		}
		if (res.len == 0)
			res.len = 1;
		return res;
	}
	bignum& operator += (const bignum& B)
	{
		return (*this) = (*this) + B;
	}
	bignum operator - (const bignum& B)
	{
		bignum res;
		int g = 0;
		for (res.len = 0; res.len < max(len, B.len) || g; res.len++)
		{
			if (res.len < len) g += a[res.len];
			if (res.len < B.len) g -= B.a[res.len];
			if (g % MOD >= 0) res.a[res.len] = g % MOD;
			else
			{
				res.a[res.len] = g % MOD + MOD;
				g -= MOD;
			}
			g /= MOD;
		}
		while (res.len && res.a[res.len - 1] == 0) res.len--;
		if (res.len == 0)
			res.len = 1;
		return res;
	}
	bignum& operator -= (const bignum& B)
	{
		return (*this) = (*this) - B;
	}
	bignum operator * (const bignum& B)
	{
		bignum res;
		res.len = len + B.len + 1;
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < res.len || res.a[j]; j++)
			{
				if (j < B.len) res.a[i + j] += a[i] * B.a[j];
				if (res.a[i + j] / MOD)
				{
					res.a[i + j + 1] += res.a[i + j] / MOD;
					res.a[i + j] %= MOD;
				}
			}
		}
		while (res.len && res.a[res.len - 1] == 0) res.len--;
		if (res.len == 0)
			res.len = 1;
		return res;
	}
	bignum& operator *= (const bignum& B)
	{
		return (*this) = (*this) * B;
	}
	void print()
	{
		printf("%d", a[len - 1]);
		for (int i = len - 2; i >= 0; i--)
			printf("%04d", a[i]);
		return ;
	}
}dp[MAX][MAX];
bignum bigpow(int base, int expo)
{
	bignum res, tmp;
	for (res = 1, tmp = base; expo; tmp *= tmp, expo >>= 1)
		if (expo & 1) res *= tmp;
	return res;
}
int n, k;

int main()
{
	int i, j;
	while (scanf("%d%d", &n, &k) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (i = 0; i <= n; i++)
			for (j = 0; j < k; j++)
			{
				dp[i + 1][j + 1] += dp[i][j];
				dp[i + 1][0] += dp[i][j];
			}
		(bigpow(2, n) - dp[n + 1][0]).print();
		puts("");
	}
}