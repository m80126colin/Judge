#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF)
		printf("%d\n", n + (n - 1) / (k - 1));
}