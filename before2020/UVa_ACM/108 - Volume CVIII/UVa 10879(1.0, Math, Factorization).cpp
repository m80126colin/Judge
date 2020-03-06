/**
 *  @judge UVa
 *  @id 10879
 *  @tag 1.0, Math, Factorization
 */
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	int t, cnt, n, i, count;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%d", &n);
		printf("Case #%d: %d", cnt, n);
		count = 0;
		for (i = 2; i < sqrt((double) n); i++)
		{
			if (count == 2) break;
			if (n % i == 0)
			{
				printf(" = %d * %d", n / i, i);
				count++;
			}
		}
		puts("");
	}
}