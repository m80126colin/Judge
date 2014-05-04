#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#define M 1000003
using namespace std;

map <char, int> m;
string ss = "01234567><+-.,[]";

int main()
{
	int i;
	string s;
	m.clear();
	for (i = 0; i < 16; i++)
		m[ss[i]] = i;
	while (getline(cin, s))
	{
		int ans = 0;
		for (i = 0; i < s.size(); i++)
			ans = (ans * 16 + m[s[i]]) % M;
		printf("%d\n", ans);
	}
}