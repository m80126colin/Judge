/**
 *  @judge UVa
 *  @id 991
 *  @tag Simple, Recursive, Catalan number
 */
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int flag;
	int catalan[15] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440}, n;
	for (flag = 0; scanf("%d", &n) != EOF; flag = 1)
	{
		if (flag) puts("");
		printf("%d\n", catalan[n]);
	}
}