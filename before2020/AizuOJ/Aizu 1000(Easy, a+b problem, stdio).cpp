/**
 *  @judge Aizu
 *  @id 1000
 *  @tag Easy, a+b problem, stdio
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF)
		printf("%d\n", a + b);
}