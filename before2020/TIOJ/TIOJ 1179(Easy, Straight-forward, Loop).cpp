#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n, f, ttl, tmp;
	while (scanf("%d", &tmp), tmp)
	{
		
		for (n = 1, ttl = f = tmp; scanf("%d", &tmp), tmp; n++, ttl += tmp) ;
		printf("%d %d %d\n", f, n, ttl);
	}
}