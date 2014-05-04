#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 110
long long f[MAX], m[MAX];

int main()
{
	int i;
	f[0] = 1, m[0] = 0;
	for (i = 1; i < MAX; i++)
		f[i] = m[i - 1] + 1, m[i] = f[i - 1] + m[i - 1];
	while (scanf("%d", &i), i != -1)
		printf("%lld %lld\n", m[i], f[i] + m[i]);
}