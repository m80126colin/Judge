/**
 *  @judge UVa
 *  @id 10696
 *  @tag 1.0, Recursive, Ad hoc, F91
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n), n)
		printf("f91(%d) = %d\n", n, (n < 101)? 91: n - 10);
}