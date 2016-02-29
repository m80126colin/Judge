#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
		printf("%d\n", (int)(1.5 * n));
} 