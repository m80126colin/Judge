/**
 *  @judge ZeroJudge
 *  @id d123
 *  @tag 1.0, Ad-hoc
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 110
#define BMAX 20010
int n, a[MAX], b[BMAX];

int sol()
{
	if (a[0] < 1) return 0;
	for (int i = 1; i < n; i++)
		if (a[i] <= a[i - 1]) return 0;
	memset(b, 0, sizeof(b));
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
		{
			if (b[a[i] + a[j]]) return 0;
			else b[a[i] + a[j]] = 1;
		}
	return 1;
}

int main()
{
	int t;
	for (t = 1; scanf("%d", &n) != EOF; t++)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		printf("Case #%d: ", t);
		if (sol()) puts("It is a B2-Sequence.");
		else puts("It is not a B2-Sequence.");
		puts("");
	}
}