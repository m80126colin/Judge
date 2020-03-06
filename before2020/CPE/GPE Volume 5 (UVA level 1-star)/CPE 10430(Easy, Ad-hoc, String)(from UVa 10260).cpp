/**
 *  @judge CPE
 *  @id 10430
 *  @tag Easy, Ad-hoc, String
 */
#include <map>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

map <char, string> T;

int main()
{
	int i;
	string s;
	T['B'] = T['F'] = T['P'] = T['V'] = "1";
	T['C'] = T['G'] = T['J'] = T['K'] = T['Q'] = T['S'] = T['X'] = T['Z'] = "2";
	T['D'] = T['T'] = "3";
	T['L'] = "4";
	T['M'] = T['N'] = "5";
	T['R'] = "6";
	T['A'] = T['E'] = T['I'] = T['O'] = T['U'] = T['H'] = T['W'] = T['Y'] = "";
	while (getline(cin, s))
	{
		cout << T[s[0]];
		for (i = 1; i < s.size(); i++)
			if (T[s[i]] != T[s[i - 1]])
				cout << T[s[i]];
		puts("");
	}
}