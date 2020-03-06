/**
 *  @judge UVa
 *  @id 10126
 *  @tag Simple, String Manipulation
 */
#include <stdio.h>
#include <string>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <map>
using namespace std;

int n;
string s, t;
map<string, int> m;
map<string, int>::iterator it;

int main()
{
	int i, j, flag, cnt;
	for (flag = 0; scanf("%d", &n) != EOF; flag = 1)
	{
		s = "";
		m.clear();
		while (getline(cin, t), t != "EndOfText")
			s += " " + t;
		for (i = 0; i < s.size(); i++)
			if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] = s[i] - 'A' + 'a';
		s += " ";
		for (i = 0; i < s.size() - 1; i++)
			if (s[i] >= 'a' && s[i] <= 'z')
			{
				for (j = i; s[j + 1] >= 'a' && s[j + 1] <= 'z'; j++);
				m[s.substr(i, j - i + 1)]++;
				i = j;
			}
		if (flag) puts("");
		cnt = 0;
		for (it = m.begin(); it != m.end(); it++)
			if (it->second == n)
			{
				puts((it->first).c_str());
				cnt++;
			}
		if (!cnt) puts("There is no such word.");
	}
}