#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n, m, a;
	while (scanf("%d%d%d", &n, &m,&a) != EOF)
	{
		printf("%I64d\n", (long long) (n / a + (n % a != 0)) * (m / a + (m % a != 0)));
	}
}