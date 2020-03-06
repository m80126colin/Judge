/**
 *  @judge UVa
 *  @id 11530
 *  @tag Easy, Ad-hoc, String
 */
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	int t, cnt, ans, i;
	map <char, int> m;
	string s;
	m['a'] = m['d'] = m['g'] = m['j'] = m['m'] = m['p'] = m['t'] = m['w'] = m[' '] = 1;
	m['b'] = m['e'] = m['h'] = m['k'] = m['n'] = m['q'] = m['u'] = m['x'] = 2;
	m['c'] = m['f'] = m['i'] = m['l'] = m['o'] = m['r'] = m['v'] = m['y'] = 3;
	m['s'] = m['z'] = 4;
	scanf("%d", &t);
	cin.ignore(1);
	for (cnt = 1; cnt <= t; cnt++)
	{
		getline(cin, s);
		for (ans = i = 0; i < s.size(); i++)
			ans += m[s[i]];
		printf("Case #%d: %d\n", cnt, ans);
	}
}