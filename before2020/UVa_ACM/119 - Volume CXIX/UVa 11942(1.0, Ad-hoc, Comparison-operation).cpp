/**
 *  @judge UVa
 *  @id 11942
 *  @tag 1.0, Ad-hoc, Comparison operation
 */
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 10
int a[MAX];

int check()
{
	int i;
	for (i = 0; i < MAX - 1; i++)
		if (a[i] > a[i + 1])
			break;
	if (i == 9) return 1;
	for (i = 0; i < MAX - 1; i++)
		if (a[i] < a[i + 1])
			break;
	if (i == 9) return 1;
	return 0;
}

int main()
{
	int n, i;
	puts("Lumberjacks:");
	for (scanf("%d", &n); n; n--)
	{
		for (i = 0; i < MAX; i++)
			scanf("%d", &a[i]);
		if (check()) puts("Ordered");
		else puts("Unordered");
	}
}