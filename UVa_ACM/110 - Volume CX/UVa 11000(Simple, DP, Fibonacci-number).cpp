#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 110
long long male[MAX], female[MAX];

int main() {
	int i;
	male[0] = 0;
	female[0] = 1;
	for (i = 1; i < MAX; i++)
	{
		male[i] = male[i - 1] + female[i - 1];
		female[i] = male[i - 1] + 1;
	}
	while (scanf("%d", &i), i >= 0)
		printf("%lld %lld\n", male[i], female[i] + male[i]);
}