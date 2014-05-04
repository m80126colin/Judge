#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <string>
using namespace std;

int main()
{
	int d, t;
	double NS, WE;
	char dir[10];
	string S;
	for (t = 1; cin.peek() != 'E'; t++)
	{
		NS = WE = 0;
		if (cin.peek() != '.')
		{
			while (scanf("%d%[^{,|.}]", &d, dir))
			{
				// printf("%d %s\n", d, dir);
				S = dir;
				if (S.size() == 1)
				{
					if (S == "N") NS += d;
					else if (S == "S") NS -= d;
					else if (S == "E") WE += d;
					else WE -= d;
				}
				else
				{
					if (S[0] == 'N') NS += (double) d / sqrt(2.0);
					else NS -= (double) d / sqrt(2.0);
					if (S[1] == 'E') WE += (double) d / sqrt(2.0);
					else WE -= (double) d / sqrt(2.0);
				}
				if (getchar() == '.')
					break;
			}
		}
		else getchar();
		getchar();
		printf("Map #%d\nThe treasure is located at (%.3lf,%.3lf).\nThe distance to the treasure is %.3lf.\n\n", t, WE, NS, sqrt(NS * NS + WE * WE));
	}
}