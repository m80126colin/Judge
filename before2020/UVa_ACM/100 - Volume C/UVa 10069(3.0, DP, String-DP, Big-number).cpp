#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 30
#define DIGIT 4
#define MOD 10000
class bignum
{
public:
	int a[MAX], len;
	bignum(){ a[0] = 0, len = 1; }
	bignum(int num)
	{
		for (len = 0; num; len++, num /= MOD) a[len] = num % MOD;
		if (!len) a[0] = 0, len = 1;
	}
	bignum operator + (const bignum& bign)
	{
		bignum res;
		int g = 0;
		for (res.len = 0; res.len < max(len, bign.len) || g; res.len++)
		{
			if (res.len < len) g += a[res.len];
			if (res.len < bign.len) g += bign.a[res.len];
			res.a[res.len] = g % MOD;
			g /= MOD;
		}
		return res;
	}
	bignum& operator += (const bignum& bign) { return (*this) = (*this) + bign; }
	bignum& operator = (const int& num) { return (*this) = bignum(num); }
	void print()
	{
		int i;
		printf("%d", a[len - 1]);
		for (i = len - 2; i >= 0; i--)
			printf("%04d", a[i]);
		return ;
	}
};

#define TEXT 10010
#define PATT 110
#define HASH(x) ((x) & 1)
int tlen, plen;
char text[TEXT], pattern[PATT];
bignum dp[2][TEXT];

int main()
{
	int n, i, j;
	for (scanf("%d", &n); n; n--)
	{
		scanf("%s%s", text + 1, pattern + 1);
		tlen = strlen(text + 1);
		plen = strlen(pattern + 1);
		for (j = 0; j <= tlen; j++) dp[0][j] = 1;
		for (i = 1; i <= plen; i++)
		{
			dp[HASH(i)][0] = 0;
			for (j = 1; j <= tlen; j++)
			{
				dp[HASH(i)][j] = dp[HASH(i)][j - 1];
				if (pattern[i] == text[j])
					dp[HASH(i)][j] += dp[HASH(i - 1)][j - 1];
			}
		}
		dp[HASH(plen)][tlen].print();
		puts("");
	}
}