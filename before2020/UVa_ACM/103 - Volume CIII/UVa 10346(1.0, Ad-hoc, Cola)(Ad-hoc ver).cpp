/**
 *  @judge UVa
 *  @id 10346
 *  @tag 1.0, Ad hoc, Cola
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF)
		printf("%d\n", n + (n - 1) / (k - 1));
}