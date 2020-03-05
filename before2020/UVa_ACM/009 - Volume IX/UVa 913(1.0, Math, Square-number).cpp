#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	long long n;
	while (scanf("%lld", &n) != EOF)
		printf("%lld\n",  3 * ((n + 1) * (n + 1) / 2 - 3));
}