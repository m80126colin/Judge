/**
 *  @judge UVa
 *  @id 12293
 *  @tag 2.5, DP, Game theory
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int n;

int main()
{
	while (scanf("%d", &n), n)
	{
		if (n & (n + 1)) puts("Alice");
		else puts("Bob");
	}
}