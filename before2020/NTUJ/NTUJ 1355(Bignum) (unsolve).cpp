#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#define N 55
#define M 20
#define MOD 100000000
using namespace std;

class BigNum{
public:
	int num[M], size;
	BigNum()
	{
		int i;
		for (i = 0; i < M; i++) num[i] = 0;
		size = 1;
	}
	BigNum& operator = (const int &a)
	{
		int i;
		for (i = 0; i < M; i++) num[i] = 0;
		size = 1;
		num[0] = a;
		if (num[0] / MOD)
		{
			num[1] += num[0] / MOD;
			num[0] %= MOD;
			size++;
		}
		return (*this);
	}
	BigNum& operator += (const BigNum &a)
	{
		int i;
		size = max(size, a.size);
		for (i = 0; i < size; i++)
			num[i] += a.num[i];
		for (i = 0; i < size; i++)
			if (num[i] / MOD)
			{
				if (i + 1 < M)
				{
					if (i + 1 == size) size++;
					num[i + 1] += num[i] / MOD;
				}
				num[i] %= MOD;
			}
		return (*this);
	}
	BigNum& operator += (const int &a)
	{
		int i;
		num[0] += a;
		for (i = 0; i < size && num[i] / MOD; i++)
		{
			if (i + 1 < M)
			{
				if (i+ 1 == size) size++;
				num[i + 1] += num[i] / MOD;
			}
			num[i] %= MOD;
		}
		return (*this);
	}
	BigNum operator + (const BigNum &a)
	{
		BigNum c;
		c = (*this);
		c += a;
		return c;
	}
	BigNum operator + (const int &a)
	{
		BigNum c;
		c = (*this);
		c += a;
		return c;
	}
	BigNum& operator *= (const int &a)
	{
		int i;
		long long tmp = 0;
		BigNum c;
		for (i = 0; i < size; i++)
		{
			tmp += (long long) num[i] * a;
			c.num[i] = tmp % MOD;
			tmp /= MOD;
		}
		for (; i < M && tmp; i++)
		{
			c.num[i] = tmp % MOD;
			tmp /= MOD;
		}
		for (c.size = i; c.size > 1; c.size--)
			if (c.num[c.size - 1]) break;
		(*this) = c;
		return (*this);
	}
	BigNum& operator *= (const BigNum &a)
	{
		int i, j;
		long long tmp;
		BigNum c;
		for (i = 0; i < size; i++)
		{
			tmp = 0;
			for (j = 0; j < a.size && i + j < M; j++)
			{
				tmp += (long long) num[i] * a.num[j] + c.num[i + j];
				c.num[i + j] = tmp % MOD;
				tmp /= MOD;
			}
			for (; i + j < M && tmp; j++)
			{
				c.num[i + j] = tmp % MOD;
				tmp /= MOD;
			}
			c.size = max(c.size, i + j);
		}
		for (c.size = i; c.size > 1; c.size--)
			if (c.num[c.size - 1]) break;
		(*this) = c;
		return (*this);
	}
	BigNum operator * (const int &a)
	{
		BigNum c;
		c = (*this);
		c *= a;
		return c;
	}
	BigNum operator * (const BigNum &a)
	{
		BigNum c;
		c = (*this);
		c *= a;
		return c;
	}
	void print()
	{
		int flag = 1, i;
		for (i = size - 1; i >= 0; i--)
		{
			if (flag)
			{
				if (num[i])
				{
					flag = 0;
					printf("%d", num[i]);
				}
			}
			else printf("%08d", num[i]);
		}
		if (flag) putchar('0');
		puts("");
		return ;
	}
};
int wlen[N], blen[N];
BigNum wDP[N][N * N], bDP[N][N * N];
BigNum ans[N][N * N];
//F[i,j] = (Len[i]-j+1)*F[i-1,j-1] + F[i-1,j]

inline void Init(int len[N], BigNum DP[N][N * N])
{
	int i, j;
	memset(DP, 0, sizeof(DP));
	for (i = 0; i <= 50; i++) DP[i][0] = 1;
	for (i = 1; i <= 50; i++)
		for (j = 1; j <= i * i; j++)
			DP[i][j] = DP[i - 1][j - 1] * (len[i] - j + 1) + DP[i - 1][j];
	return ;
}

int main()
{
	int i, j, k;
	for (i = 1; i <= 50; i++)
		wlen[i] = blen[i] = ((i + 1) / 2) * 2;
	for (i = 50; i; i--)
	{
		wlen[i]--;
		blen[i] = blen[i - 1];
	}
	Init(wlen, wDP);
	Init(blen, bDP);
	memset(ans, 0, sizeof(ans));
	for (i = 1; i <= 50; i++)
		for (j = 1; j <= i; j++)
			for (k = 0; k <= j; k++)
				ans[i][j] += wDP[i][k] * bDP[i][j - k];
	while (scanf("%d %d", &i, &j) != EOF)
	{
		ans[i][j].print();
	}
}