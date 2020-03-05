#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n), n)
		printf("f91(%d) = %d\n", n, (n < 101)? 91: n - 10);
}