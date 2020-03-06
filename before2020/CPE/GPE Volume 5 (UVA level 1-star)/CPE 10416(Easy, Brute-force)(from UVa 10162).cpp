/**
 *  @judge CPE
 *  @id 10416
 *  @tag Easy, Brute force
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int table[10][5] = {{0}};
	int n, i, j, ans = 0;
	for (i = 0; i < 10; i++)
	{
		table[i][0] = 1;
		for (j = 1; j < 5; j++)
			table[i][j] = table[i][j-1] * i % 10;
		table[i][0] = table[i][4];
	}
	while (scanf("%d", &n), n)
	{
		ans = 0;
		for (i = 1; i <= n; i++)
			ans = (ans + table[i % 10][i % 4]) % 10;
		printf("%d\n", ans);
	}
}