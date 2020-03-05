#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 100
long long Poly[MAX], PolyTemp[MAX], r;

int main()
{
	int n, i, j;
	while (scanf("%d", &n) != EOF)
	{
		memset(Poly, 0, sizeof(Poly));
		Poly[0] = 1;
		for (i = 0; i < n; i++)
		{
			scanf("%lld", &r);
			memset(PolyTemp, 0, sizeof(PolyTemp));
			for (j = 0; j < MAX - 1; j++)
				PolyTemp[j + 1] = Poly[j];
			for (j = 0; j < MAX; j++)
				PolyTemp[j] += Poly[j] * (-r);
			for (j = 0; j < MAX; j++)
				Poly[j] = PolyTemp[j];
		}
		for (i = MAX - 1; i >= 0; i--)
			if (Poly[i]) break;
		printf("x");
		if (i > 1) printf("^%d", i);
		putchar(' ');
		for (i--; i >= 0; i--)
		{
			if (Poly[i] < 0)
			{
				printf("- ");
				Poly[i] = -Poly[i];
			}
			else if ((i == 0) || (i > 0 && Poly[i]))
				printf("+ ");
			if (Poly[i] > 1 || (i == 0))
				printf("%lld", Poly[i]);
			if (i && Poly[i]) printf("x");
			if (Poly[i] && i > 1)
				printf("^%d", i);
			if (Poly[i] || i == 0) printf(" ");
		}
		puts("= 0");
	}
}