/**
 *  @judge UVa
 *  @id 10499
 *  @tag 1.0, Ad hoc
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	long long n;
	while (scanf("%lld", &n), n > 0)
		printf("%lld%%\n", (n > 1) * n * 25);
}