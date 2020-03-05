#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;

struct entry {
	char a[7], b[7];
	entry(string str)
	{
		int i, j;
		strcpy(a, str.c_str());
		strcpy(b, str.c_str());
		int len = strlen(b);
		for (i = 0; i < len; i++)
			for (j = i + 1; j < len; j++)
				if (b[i] > b[j])
					swap(b[i], b[j]);
	}
	bool operator < (const entry& E) const
	{
		return strcmp(a, E.a) < 0;
	}
};
set<entry> S;
set<entry>::iterator it;

int Match(entry s, entry t)
{
	return !strcmp(s.b, t.b);
}

int main()
{
	int flag;
	string str;
	S.clear();
	while (cin >> str, str != "XXXXXX")
		S.insert(entry(str));
	while (cin >> str, str != "XXXXXX")
	{
		flag = 1;
		entry temp = entry(str);
		for (it = S.begin(); it != S.end(); it++)
			if (Match(*it, temp))
			{
				printf("%s\n", it -> a);
				flag = 0;
			}
		if (flag) puts("NOT A VALID WORD");
		puts("******");
	}
}