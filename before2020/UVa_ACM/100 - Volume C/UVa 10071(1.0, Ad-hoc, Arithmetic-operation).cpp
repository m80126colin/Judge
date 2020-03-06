/**
 *  @judge UVa
 *  @id 10071
 *  @tag 1.0, Ad hoc, Arithmetic operation
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int v, t;
	while (scanf("%d%d", &v, &t) != EOF)
		printf("%d\n", (v * t) << 1);
}