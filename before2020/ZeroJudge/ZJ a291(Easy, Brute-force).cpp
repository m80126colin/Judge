/**
 *  @judge ZeroJudge
 *  @id a291
 *  @tag Easy, Brute force
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int n, a[4], b[4], taga[4], tagb[4];
int A, B;

bool input(int *x)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (scanf("%d", &x[i]) == EOF) return 0;
	}
	return 1;
}

int main()
{
	int i, j, k;
	while (input(a))
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			input(b);
			for (j = 0; j < 4; j++) taga[j] = tagb[j] = 0;
			for (j = A = 0; j < 4; j++)
			{
				if (a[j] == b[j]) A++, taga[j] = tagb[j] = 1;
			}
			for (j = B = 0; j < 4; j++)
			{
				if (tagb[j] == 0)
				{
					for (k = 0; k < 4; k++)
					{
						if (taga[k] == 0)
						{
							if (a[k] == b[j])
							{
								B++, taga[k] = tagb[j] = 1;
								break;
							}
						}
					}
				}
			}
			printf("%dA%dB\n", A, B);
		}
	}
}