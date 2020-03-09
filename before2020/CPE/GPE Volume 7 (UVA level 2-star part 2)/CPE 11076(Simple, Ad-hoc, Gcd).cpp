/**
 *  @judge CPE
 *  @id 11076
 *  @source UVa 11417
 * 
 *  @tag Simple, Ad-hoc, Gcd
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int g[501], k[501];

int gcd(int a, int b)
{
	return (b) ? gcd(b, a%b): a;
}

int G(int n)
{
	int d = 0, i;
	for (i = 1; i < n; i++)
			d += gcd(i, n);
	return d;
}

int main()
{
	int n, i;
	k[0] = 0;
	for (i = 1; i <= 500; i++) g[i] = G(i), k[i] = k[i-1] + g[i];
	while (cin >> n, n) cout << k[n] << endl;
}