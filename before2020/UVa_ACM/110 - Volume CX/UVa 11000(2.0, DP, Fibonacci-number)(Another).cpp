#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 110
long long f[MAX];

int main()
{
	int i;
	f[0] = f[1] = 1;
	for (i = 2; i < MAX; i++)
		f[i] = f[i - 1] + f[i - 2];
	while (scanf("%d", &i), i != -1)
		printf("%lld %lld\n", f[i + 1] - 1, f[i + 2] - 1);
}