#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

#define N 1010
int a[N], len;

int gcd(int a, int b)
{
	return (b)? gcd(b, a % b): a;
}

int input()
{
	int i;
	for (len = 0; scanf("%d", &a[len]), a[len]; len++) ;
	for (i = 1; i < len; i++)
		a[i - 1] -= a[i];
	if (len > 1) len--;
	return len;
}

void sol()
{
	int i, d = a[0];
	for (i = 0; i < len; i++)
		d = gcd(d, abs(a[i]));
	printf("%d\n", d);
	return;
}

int main()
{
	while (input())
		sol();
}