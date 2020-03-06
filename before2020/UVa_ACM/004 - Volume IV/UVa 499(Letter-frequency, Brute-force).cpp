/**
 *  @judge UVa
 *  @id 499
 *  @tag Letter frequency, Brute force
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int i, f[52], mx;
	while (getline(cin, s))
	{
		memset(f, 0, sizeof(f));
		for (i = mx = 0; i < s.size(); i++)
		{
			if (s[i] >= 'A' && s[i] <= 'Z') mx = max(mx, ++f[s[i] - 'A']);
			else if (s[i] >= 'a' && s[i] <= 'z') mx = max(mx, ++f[s[i] - 'a' + 26]);
		}
		for (i = 0; i < 26; i++)
			if (mx == f[i]) putchar('A' + i);
		for (i = 26; i < 52; i++)
			if (mx == f[i]) putchar('a' + i - 26);
		printf(" %d\n", mx);
	}
}