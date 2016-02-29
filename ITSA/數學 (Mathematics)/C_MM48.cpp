#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int k, n;
	for (scanf("%d", &k); k; k--)
	{
		scanf("%d", &n);
		if (n < 101) puts("91");
		else printf("%d\n", n - 10);
	}
}