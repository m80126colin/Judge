#include <stdio.h>
#include <iostream>
using namespace std;

int m, n;

int main()
{
	while (scanf("%d%d", &m, &n) != EOF)
		printf("%d\n", m * n - 1);
}