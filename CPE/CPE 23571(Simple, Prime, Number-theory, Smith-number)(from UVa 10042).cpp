#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
using namespace std;

int sod(int n)
{
	int ans = 0;
	while (n)
	{
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

void factor(int n, int &a)
{
	a = 0;
	int i;
	for (i = 2; i <= sqrt((double) n); i++)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
			{
				n /= i;
				a += sod(i);
			}
		}
	}
	if (n > 1) a += sod(n);
	return ;
}

int isprime(int n)
{
	int i;
	for (i = 2; i <= sqrt((double) n); i++)
		if (n % i  == 0)
			return 0;
	return 1;
}

int issmith(int n)
{
	int a, b;
	if (isprime(n))
		return 0;
	b = sod(n);
	factor(n, a);
	return a == b;
}

int main()
{
	int n, t;
	for (cin >> n; n; n--)
	{
		cin >> t;
		for (t++;; t++)
		{
			if (issmith(t))
			{
				cout << t << endl;
				break;
			}
		}
	}
}