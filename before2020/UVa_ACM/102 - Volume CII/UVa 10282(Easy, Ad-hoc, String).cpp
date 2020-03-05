#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map <string, string> word;

int main()
{
	string s, t;
	word.clear();
	while (cin >> s >> t)
	{
		word[t] = s;
		cin.ignore(1);
		if (cin.peek() == '\n') break;
	}
	while (cin >> s)
	{
		if (word[s] != "") cout << word[s] << endl;
		else cout << "eh\n";
	}
}