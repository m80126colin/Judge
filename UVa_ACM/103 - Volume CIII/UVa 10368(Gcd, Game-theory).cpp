#include <stdio.h>

int gcd(int a, int b)
{
	if (b > a) return gcd(b, a);
	if (b == 0) return 0;
	if (a / b == 1) return !gcd(b, a % b);
	return 1;
}

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b), (a || b))
	{
		if (gcd(a, b)) puts("Stan wins");
		else puts("Ollie wins");
	}
}