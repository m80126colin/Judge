#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int c1[2], c2[2], len;
char a[100010], b[100010];

int main()
{
	int i, j, ans;
	while (scanf("%s%s", a, b) != EOF)
	{
		ans = 0;
		len = strlen(a);
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		for (i = 0; i < len; i++)
		{
			c1[a[i] == '7']++;
			c2[b[i] == '7']++;
		}
		for (i = 0; i < len; i++)
		{
			if (a[i] != b[i])
			{
				for (j = i + 1; j < len; j++)
				{
					if (a[j] != b[j] && a[i] != a[j])
					{
						swap(a[i], a[j]);
						ans++;
						break;
					}
				}
			}
		}
		if (c1[0] != c2[0])
		{
			if (c1[0] > c2[0])
			{
				for (i = 0; i < len && c1[0] != c2[0]; i++)
				{
					if (a[i] == '4' && b[i] == '7')
					{
						a[i] = '7';
						c1[0]--;
						c1[1]++;
						ans++;
					}
				}
			}
			else
			{
				for (i = 0; i < len && c1[0] != c2[0]; i++)
				{
					if (a[i] == '7' && b[i] == '4')
					{
						a[i] = '4';
						c1[0]++;
						c1[1]--;
						ans++;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
}