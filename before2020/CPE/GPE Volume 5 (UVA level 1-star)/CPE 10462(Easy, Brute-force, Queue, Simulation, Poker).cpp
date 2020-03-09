/**
 *  @judge CPE
 *  @id 10462
 *  @source UVa 10935
 * 
 *  @tag Easy, Brute force, Queue, Simulation, Poker
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main()
{
	int n, i;
	queue <int> q;
	while (cin >> n, n)
	{
		while (!q.empty()) q.pop();
		for (i = 1; i <= n; i++) q.push(i);
		printf("Discarded cards:");
		for (i = 2; i <= n; i++)
		{
			printf(" %d", q.front());
			if (i < n) putchar(',');
			q.pop();
			q.push(q.front());
			q.pop();
		}
		puts("");
		printf("Remaining card: %d\n", q.front());
	}
}