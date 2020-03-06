/**
 *  @judge CPE
 *  @id 10549
 *  @tag Easy, Math, Brute force
 */
#include <stdio.h>
#include <iostream>
using namespace std;

long long n;

inline long long s(long long x)
{
	long long i, j, d = 0, tmp;
	for (i = n; i; i--)
	{
		tmp = 1;
		for (j = 0; j < x; j++)
		{
			tmp *= i;
		}
		d += tmp;
	}
	return d;
}

inline long long r(long long x)
{
	long long i, d = 1;
	for (i = 0; i < x; i++)
	{
		d *= n * (n + 1) / 2;
	}
	return d - s(x);
}

int main()
{
	while (cin >> n)
	{
		cout << s(2) << " " << r(2) << " " << s(3) << " " << r(3) << " " << s(4) << " " << r(4) << endl;
	}
}