#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 50
long long f[MAX];

int main()
{
	int n;
	f[0] = f[1] = 1;
	for (n = 2; n < MAX; n++)
		f[n] = f[n - 1] + f[n - 2];
	while (scanf("%d", &n) != EOF)
		printf("%lld\n", f[n]);
}