/**
 *  @judge TIOJ
 *  @id 1659
 *  @tag Simple, Sieve, Prime
 */
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

bool ox[5010];
vector <int> pr;

int main()
{
	int n, i, j;
	memset(ox, 1, sizeof(ox));
	for (i = 2; i < 5000; i++)
	{
		if (ox[i])
		{
			pr.push_back(i);
			for (j = 2; i * j < 5000; j++)
				ox[i * j] = 0;
		}
	}
	while (scanf("%d", &n) != EOF)
	{
		printf("primes between 1 ~ %d:", n);
		for (i = 0; i < pr.size() && pr[i] <= n; i++)
			printf(" %d", pr[i]);
		puts("");
	}
}