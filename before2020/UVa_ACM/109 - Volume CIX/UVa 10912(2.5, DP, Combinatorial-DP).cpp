#include <stdio.h>
#include <iostream>
using namespace std;

#define MAXL 30
#define MAXS 400
#define MAXC 26
#define MAXI 351
int DP[MAXL][MAXL][MAXS]; // DP[L][last][S]
int sum[MAXL][MAXS];

int main()
{
	int t;
	int L, S, la, la_s, ne; // last word and new word
	DP[0][0][0] = 1;
	for (L = 0; L < MAXC; L++)
		for (la = 0; la < MAXC; la++)
			for (la_s = 0; la_s < MAXS; la_s++)
				if (DP[L][la][la_s])
				{
					for (ne = la + 1; ne <= MAXC; ne++)
					{
						DP[L + 1][ne][la_s + ne] += DP[L][la][la_s];
						sum[L + 1][la_s + ne] += DP[L][la][la_s];
					}
				}
	for (t = 1; scanf("%d%d", &L, &S), (L || S); t++)
	{
		printf("Case %d: ", t);
		if (L > MAXC || S > MAXI) puts("0");
		else printf("%d\n", sum[L][S]);
	}
}