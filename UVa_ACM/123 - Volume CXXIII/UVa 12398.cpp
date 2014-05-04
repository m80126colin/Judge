#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

int p, pp[9] = {11, 23, 38, 89, 186, 308, 200, 464, 416}, ans[9];
string s;

int main()
{
	int t, i, j, k;
	for (t = 1; getline(cin, s); t++)
	{
		p = 0;
		memset(ans, 0, sizeof(ans));
		for (i = 0; i < s.size(); i++)
			for (j = 0; j < 3; j++)
				for (k = 0; k < 3; k++)
					if ( pp[s[i] - 'a'] & (1 << (j * 3 + k)) )
						ans[j * 3 + k]++;
		printf("Case #%d:\n", t);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (j) putchar(' ');
				printf("%d", ans[i * 3 + j] % 10);
			}
			puts("");
		}
	}
}