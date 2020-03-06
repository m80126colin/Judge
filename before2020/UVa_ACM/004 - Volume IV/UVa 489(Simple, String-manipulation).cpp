/**
 *  @judge UVa
 *  @id 489
 *  @tag Simple, String manipulation
 */
#include <stdio.h>
#include <iostream>
#include <ctype.h>
#include <string>
#include <map>
using namespace std;

map <char, int> guess, word;

int main()
{
	int n, i, cnt;
	string s;
	while (scanf("%d", &n), n != -1)
	{
		guess.clear();
		word.clear();
		cin.ignore(1);
		getline(cin, s);
		for (i = 0; i < s.size(); i++)
			if (isalpha(s[i])) word[tolower(s[i])] = 1;
		printf("Round %d\n", n);
		getline(cin, s);
		for (i = cnt = 0; i < s.size(); i++)
		{
			if (!isalpha(s[i])) continue;
			s[i] = tolower(s[i]);
			if (!guess[s[i]])
			{
				guess[s[i]] = 1;
				if (!word[s[i]]) cnt++;
				word.erase(s[i]);
				if (!word.size() || cnt >= 7) break;
			}
		}
		if (cnt >= 7) puts("You lose.");
		else if (!word.size()) puts("You win.");
		else puts("You chickened out.");
	}
}