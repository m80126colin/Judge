/**
 *  @judge UVa
 *  @id 11621
 *  @tag Easy, Brute force
 */
#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;

#define MAX 2147483648LL
set<long long> s;
set<long long>::iterator it;

int main()
{
	long long i, j, m;
	for (i = 1; i <= MAX; i *= 2)
		for (j = 1; j <= MAX; j *= 3)
			s.insert(i * j);
	while (scanf("%lld", &m), m)
	{
		for (it = s.begin(); it != s.end(); it++)
			if ((*it) >= m) break;
		printf("%lld\n", *it);
	}
}