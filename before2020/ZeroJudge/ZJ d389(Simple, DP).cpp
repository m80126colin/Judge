/**
 *  @judge ZeroJudge
 *  @id d389
 *  @tag Simple, DP
 */
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 110
int DP[MAX];

int main()
{
	int i;
	DP[0] = DP[1] = 1;
	DP[2] = 2;
	for (i = 3; i < MAX; i++)
		DP[i] = DP[i - 2] + DP[i - 3];
	while (scanf("%d", &i) != EOF)
		printf("%d\n", DP[i]);
}