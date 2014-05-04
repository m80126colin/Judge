#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int L, N;
map<string, string> word;
string s, t;

int isvowel(char ch)
{
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main()
{
	int i;
	while (scanf("%d%d", &L, &N) != EOF)
	{
		word.clear();
		for (i = 0; i < L; i++)
		{
			cin >> s >> t;
			word[s] = t;
		}
		for (i = 0; i < N; i++)
		{
			cin >> s;
			if (word[s] != "") puts(word[s].c_str());
			else if (s.size() >= 2 && !isvowel(s[s.size() - 2]) && s.substr(s.size() - 1) == "y")
			{
				s[s.size() - 1] = 'i';
				puts((s + "es").c_str());
			}
			else if (s.substr(s.size() - 1) == "o" || s.substr(s.size() - 1) == "s" || s.substr(s.size() - 1) == "x" || s.substr(s.size() - 2) == "ch" || s.substr(s.size() - 2) == "sh")
				puts((s + "es").c_str());
			else puts((s+ "s").c_str());
		}
	}
}