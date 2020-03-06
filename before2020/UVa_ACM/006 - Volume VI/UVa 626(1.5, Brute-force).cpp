/**
 *  @judge UVa
 *  @id 626
 *  @tag 1.5, Brute force
 */
#include <cstdio>
#include <iostream>
using namespace std;

#define MAX 110
int M[MAX][MAX], n;

int input()
{
	int i, j;
	if (scanf("%d", &n) == EOF)
		return EOF;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &M[i][j]);
	return 0;
}

int sol()
{
	int i, j, k, ans;
	ans = 0;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			for (k = 1; k <= n; k++)
				if (i != j && j != k && k != i && ((i < j && j < k) || (i > j && j > k)))
					if (M[i][j] && M[j][k] && M[k][i])
					{
						printf("%d %d %d\n", i, j, k);
						ans++;
					}
	return ans;
}

int main()
{
	while (input() != EOF)
		printf("total:%d\n\n", sol());
}