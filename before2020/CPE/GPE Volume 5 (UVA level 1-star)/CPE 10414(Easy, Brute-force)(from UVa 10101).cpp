/**
 *  @judge CPE
 *  @id 10414
 *  @tag Easy, Brute force
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s[4] = {"kuti", "lakh", "hajar", "shata"};
long long w[4] = {10000000, 100000, 1000, 100};

void dfs(long long x)
{
	int i;
	if (x / w[0]) dfs(x / w[0]), printf(" %s", s[0].c_str());
	x %= w[0];
	for (i = 1; i < 4; i++)
	{
		if (x / w[i])
		{
			printf(" %lld %s", x / w[i], s[i].c_str());
			x %= w[i];
		}
	}
	printf(" %lld", x);
	return;
}

int main()
{
	
	long long n, ctr;
	for (ctr = 1; cin >> n; ctr++)
	{
		printf("%lld.", ctr);
		dfs(n);
		puts("");
	}
}