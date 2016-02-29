#include <stdio.h>
#include <iostream>
using namespace std;

long long M[101], F[101];

int main() {
	int i;
	M[1] = F[0] = F[1] = 1, M[0] = 0;
	for (i = 2; i <= 100; i++)
	{
		M[i] = M[i - 1] + M[i - 2];
		F[i] = F[i - 1] + M[i - 1];
	}
	while (scanf("%d", &i), i >= 0)
		printf("%lld %lld\n", M[i], M[i] + F[i]);
}