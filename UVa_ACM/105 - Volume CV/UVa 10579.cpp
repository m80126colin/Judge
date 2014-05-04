#include <stdio.h>
#include <iostream>
#include <vector>
#define N 9
#define M 1000000000
#define MAX 4785
using namespace std;

struct bignum
{
	vector <int> ele;
	bignum()
	{
		ele.clear();
		ele.push_back(0);
	}
	bignum& operator =(const int &a)
	{
		ele.clear();
		ele.push_back(a);
		if (ele[0] / M)
			ele.push_back(ele[0] / M);
		ele[0] %= M;
		return (*this);
	}
	bignum& operator +=(const int &a)
	{
		int i;
		ele[0] += a;
		for (i = 0; ele[i] / M; i++)
		{
			if (i + 1 == ele.size()) ele.push_back(0);
			ele[i + 1] += ele[i] / M;
			ele[i] %= M;
		}
		return (*this);
	}
	bignum& operator +=(const bignum &a)
	{
		int i;
		for (i = 0; i < a.ele.size(); i++)
		{
			if (i == ele.size()) ele.push_back(0);
			ele[i] += a.ele[i];
			if (ele[i] / M)
			{
				if (i + 1 == ele.size()) ele.push_back(0);
				ele[i + 1] += ele[i] / M;
				ele[i] %= M;
			}
		}
		return (*this);
	}
	bignum operator +(const int &a)
	{
		bignum b;
		b = (*this);
		b += a;
		return b;
	}
	bignum operator +(const bignum &a)
	{
		bignum b;
		b = (*this);
		b += a;
		return b;
	}
	void print()
	{
		int i;
		printf("%d", ele[ele.size() - 1]);
		for (i = ele.size() - 2; i >= 0; i--)
			printf("%09d", ele[i]);
		puts("");
		return;
	}
}F[MAX];

int main()
{
	int i;
	F[1] = F[2] = 1;
	for (i = 3; i < MAX; i++)
		F[i] = F[i - 1] + F[i - 2];
	while (scanf("%d", &i) != EOF)
		F[i].print();
}