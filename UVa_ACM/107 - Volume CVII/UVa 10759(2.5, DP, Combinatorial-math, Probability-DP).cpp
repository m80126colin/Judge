#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAXN 30
#define MAXX 150
int n, x;
long long gcd(long long a, long long b) { return (b)? gcd(b, a % b): a; }
struct fraction
{
	long long son, parent;
	fraction(){}
	fraction(long long s, long long p)
	{
		long long g = gcd(s, p);
		son = s / g;
		parent = p / g;
	}
	fraction operator + (const fraction& f)
	{
		long long g = gcd(parent, f.parent);
		fraction tmp = fraction(son * (f.parent / g) + (parent / g) * f.son, (parent / g) * f.parent);
		g = gcd(tmp.son, tmp.parent);
		return fraction(tmp.son / g, tmp.parent / g);
	}
	fraction& operator += (const fraction& f)
	{
		(*this) = (*this) + f;
		return (*this);
	}
	fraction operator * (const fraction& f)
	{
		long long g1 = gcd(son, f.parent), g2 = gcd(f.son, parent);
		fraction tmp = fraction((son / g1) * (f.son / g2), (parent / g2) * (f.parent / g1));
		long long g = gcd(tmp.son, tmp.parent);
		return fraction(tmp.son / g, tmp.parent / g);
	}
	fraction& operator *= (const fraction& f)
	{
		(*this) = (*this) * f;
		return (*this);
	}
}num[MAXN][MAXX];
#define DICE (fraction(1, 6))

int main()
{
	int i, j, k;
	for (i = 0; i < MAXN; i++)
		for (j = 0; j < MAXX; j++)
			num[i][j] = fraction(0, 1);
	num[0][0] = fraction(1, 1);
	for (i = 0; i < MAXN - 1; i++)
		for (j = i; j <= min(6 * i, MAXX - 1); j++)
			if (num[i][j].son) for (k = 1; k <= 6 && j + k < MAXX; k++)
				num[i + 1][j + k] += num[i][j] * DICE;
	for (i = 0; i < MAXN; i++)
		for (j = MAXX - 2; j >= 0; j--)
			num[i][j] += num[i][j + 1];
	while (scanf("%d%d", &n, &x), (n || x))
	{
		if (num[n][x].parent == 1) printf("%lld\n", num[n][x].son);
		else printf("%lld/%lld\n", num[n][x].son, num[n][x].parent);
	}
}