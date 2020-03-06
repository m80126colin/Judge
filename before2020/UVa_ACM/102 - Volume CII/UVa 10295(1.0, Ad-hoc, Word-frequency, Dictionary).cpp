/**
 *  @judge UVa
 *  @id 10295
 *  @tag 1.0, Ad-hoc, Word frequency, Dictionary
 */
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

string tmp;
map<string, int> word;
int m, n, tnum;

int main()
{
	int i, ans;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		for (i = 0; i < m; i++)
		{
			cin >> tmp >> tnum;
			word[tmp] = tnum;
		}
		for (i = 0; i < n; i++)
		{
			for (ans = 0; cin >> tmp, tmp != ".";)
				ans += word[tmp];
			printf("%d\n", ans);
		}
	}
}