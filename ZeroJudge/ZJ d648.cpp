#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	return (b)?gcd(b, a%b):a;
}

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF)
	{
		if (gcd(a, b) == 1) puts("YES");
		else puts("Impossible");
	}
}