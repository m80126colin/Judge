/**
 *  @judge UVa
 *  @id 11482
 *  @tag Simple, Ad hoc, String manipulation
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int M, N, i, j, k, r, s, t, C, ctr;
	for (ctr = 1; scanf("%d%d", &M, &N), (M || N); ctr++)
	{
		printf("Triangular Museum %d\n", ctr);
		C = M * N - 1;
		for (i = C; i >= 0; i--)
		{
			for (j = 0; j < i; j++) putchar(' ');
			j = C - i + 1;
			k = (j - 1) / M;
			r = j % M;
			for (s = 0; s <= k; s++)
			{
				if (s)
				{
					if (r)
					{
						for (t = 0; t < M - r; t++) putchar(' ');
						for (t = 0; t < M - r; t++) putchar(' ');
					}
				}
				putchar('/');
				if (r)
				{
					for (t = 0; t < r - 1; t++) putchar(' ');
					for (t = 0; t < r - 1; t++) putchar(' ');
				}
				else
				{
					for (t = 0; t < M - 1; t++) putchar('_');
					for (t = 0; t < M - 1; t++) putchar('_');
				}
				putchar('\\');
			}
			puts("");
		}
		puts("");
	}
}