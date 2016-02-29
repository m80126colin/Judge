#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int n, a, b, i, j, ctr;
	for (ctr = 1; cin >> s; ctr++)
	{
		scanf("%d", &n);
		printf("Case %d:\n", ctr);
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &a, &b);
			if (a > b) swap(a, b);
			for (j = a + 1; j <= b; j++)
				if (s[j] != s[a]) break;
			if (j > b) puts("Yes");
			else puts("No");
		}
	}
}