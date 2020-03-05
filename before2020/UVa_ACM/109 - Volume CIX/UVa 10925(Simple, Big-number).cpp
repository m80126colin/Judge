#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define M 100000000
using namespace std;

struct bignum
{
	vector <int> ele;
	bignum()
	{
		ele.clear();
		ele.push_back(0);
	}
	bignum& operator = (const int &a)
	{
		ele.clear();
		ele.push_back(a);
		if (ele[0] / M) ele.push_back(ele[0] / M);
		ele[0] %= M;
		return (*this);
	}
	bignum& operator += (const bignum &a)
	{
		int i;
		for (i = 0; i < a.ele.size(); i++)
		{
			if (i >= ele.size()) ele.push_back(0);
			ele[i] += a.ele[i];
		}
		for (i = 0; i < ele.size(); i++)
		{
			if (ele[i] / M)
			{
				if (i + 1 >= ele.size()) ele.push_back(0);
				ele[i + 1] += ele[i] / M;
				ele[i] %= M;
			}
		}
		return (*this);
	}
	bignum operator + (const bignum &a)
	{
		bignum b;
		b = (*this);
		b += a;
		return b;
	}
	bignum operator / (const int &a)
	{
		bignum b;
		int i;
		long long buf;
		b.ele.clear();
		buf = 0;
		for (i = ele.size() - 1; i >= 0; i--)
		{
			buf *= M;
			buf += ele[i];
			b.ele.push_back(buf / a);
			buf %= a;
		}
		reverse(b.ele.begin(), b.ele.end());
		while (b.ele.size() > 1 && b.ele[b.ele.size() - 1] == 0) b.ele.pop_back();
		return b;
	}
	int input(bignum &a)
	{
		int i;
		char s[30];
		if (scanf("%s", s) == EOF) return EOF;
		a.ele.clear();
		for (i = strlen(s); i - 8 > 0; i -= 8)
		{
			a.ele.push_back( atoi(s + i - 8) );
			s[i - 8] = '\0';
		}
		ele.push_back( atoi(s) );
		return 0;
	}
	void output()
	{
		int i = ele.size() - 1;
		printf("%d", ele[i]);
		for (i--; i >= 0; i--)
			printf("%08d", ele[i]);
		return ;
	}
};

int main()
{
	bignum sum, tmp;
	int n, f, i, ctr;
	for (ctr = 1; scanf("%d%d", &n, &f), (n || f); ctr++)
	{
		sum = 0;
		for (i = 0; i < n; i++)
		{
			tmp.input(tmp);
			sum += tmp;
		}
		printf("Bill #%d costs ", ctr);
		sum.output();
		printf(": each friend should pay ");
		(sum / f).output();
		puts("\n");
	}
}