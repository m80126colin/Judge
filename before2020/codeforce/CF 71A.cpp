#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	string s;
	for (scanf("%d", &n); n; n--)
	{
		cin >> s;
		if (s.size() > 10) printf("%c%d%c\n", s[0], s.size() - 2, s[s.size() - 1]);
		else cout << s << endl;
	}
}