#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

inline void cal(string s, int &a)
{
	int i;
	for (i = a = 0; i < s.size(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z') a += s[i] - 'a' + 1;
		else if (s[i] >= 'A' && s[i] <= 'Z') a += s[i] - 'A' + 1;
	}
	return ;
}

inline void cal2(int &a)
{
	int i, len;
	char tmp[15] = "";
	sprintf(tmp, "%d", a);
	a = 0, len = strlen(tmp);
	for (i = 0; i < len; i++)
		a += tmp[i] - '0';
	return ;
}

int main()
{
	int a, b;
	string s, t;
	while (getline(cin, s))
	{
		getline(cin, t);
		cal(s, a);
		cal(t, b);
		while (a >= 10) cal2(a);
		while (b >= 10) cal2(b);
		if (a > b) swap(a, b);
		printf("%.2lf %%", (double) a * 100.0 / b);
		if (cin.peek() != EOF) puts("");
	}
}