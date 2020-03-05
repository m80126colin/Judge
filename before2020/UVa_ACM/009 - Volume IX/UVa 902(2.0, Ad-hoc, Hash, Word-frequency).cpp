#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

#define MAX 1000010
#define BASE 26
int n;
map<long long, int> code;
map<long long, int>::iterator it, ans;
char str[MAX];

string inverse(long long hash, int dep)
{
	if (dep == n)
		return "";
	char ch = hash % BASE + 'a';
	return inverse(hash / 26, dep + 1) + ch;
}

int main()
{
	int i, len;
	long long hash, power;
	while (scanf("%d%s", &n, str) != EOF)
	{
		len = strlen(str);
		if (len < n) puts("");
		else
		{
			code.clear();
			hash = 0;
			power = 1;
			for (i = 0; i < n; i++)
			{
				hash *= BASE;
				power *= BASE;
				hash += (str[i] - 'a');
			}
			code[hash]++;
			for (i = 0; i < len - n; i++)
			{
				hash = (hash * BASE) % power + (str[i + n] - 'a');
				code[hash]++;
			}
			for (it = ans = code.begin(); it != code.end(); it++)
				if (ans->second < it->second)
					ans = it;
			puts(inverse(ans->first, 0).c_str());
		}
	}
}