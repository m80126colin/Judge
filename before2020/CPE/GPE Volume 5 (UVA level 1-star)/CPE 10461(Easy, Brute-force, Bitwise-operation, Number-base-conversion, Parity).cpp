/**
 *  @judge CPE
 *  @id 10461
 *  @source UVa 10931
 * 
 *  @tag Easy, Brute force, Bitwise Operation, Number Base Conversion, Parity
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int p;

void sol(int n)
{
	if (n >> 1) sol(n >> 1);
	if (n & 1) p++, putchar('1');
	else putchar('0');
	return;
}

int main()
{
	int n;
	while (cin >> n, n)
	{
		printf("The parity of ");
		p = 0;
		sol(n);
		printf(" is %d (mod 2).\n", p);
	}
}