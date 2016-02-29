#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <set>
#define EPS 5.14e-7
using namespace std;

set <int> S;

int IsPrime(int num)
{
	int i, n = sqrt((double) num);
	for (i = 2; i <= n; i++)
		if (num % i == 0)
			return 0;
	return 1;
}

int main()
{
	int a, b, i, j;
	S.clear();
	for (i = 0; i <= 10000; i++)
		if (IsPrime(i * i + i + 41))
			S.insert(i);
	while (scanf("%d%d", &a, &b) != EOF)
	{
		if (a > b) swap(a, b);
		for (i = j = 0; a <= b; a++)
		{
			if (S.find(a) != S.end()) i++;
			j++;
		}
		// i = i * 10000 / j;
		// printf("%d.%02d\n",i / 100,i % 100);
		printf("%.2lf\n", (double) i * 100.00 / j + EPS);
	}
}