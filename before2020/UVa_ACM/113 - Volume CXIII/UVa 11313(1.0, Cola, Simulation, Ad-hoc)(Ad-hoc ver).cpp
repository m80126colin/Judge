/**
 *  @judge UVa
 *  @id 11313
 *  @tag 1.0, Cola, Simulation, Ad-hoc
 */
#include <cstdio>
#include <iostream>
using namespace std;

int t, n, m;

int main()
{
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d", &n, &m);
		if ((n - 1) % (m - 1)) puts("cannot do this");
		else printf("%d\n", (n - 1) / (m - 1));
	}
}