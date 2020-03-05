#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

string s, p;
int count1[26], count2[26];

inline void count(int c[26], string t)
{
	int i;
	for (i = 0; i < s.size(); i++)
	{
		if (t[i] >= 'a' && t[i] <= 'z') c[t[i] - 'a']++;
	}
	return ;
}

inline int satis()
{
	int i;
	for (i = 0; i < 26; i++)
		if (count1[i] < count2[i])
			return 0;
	return 1;
}

int main()
{
	int i;
	
	while (cin >> p >> s)
	{
		if (s.size() > p.size())
		{
			puts("0");
			continue;
		}
		else
		{
			int ans = 0;
			memset(count1, 0, sizeof(count1));
			memset(count2, 0, sizeof(count2));
			count(count1, s);
			count(count2, p);
			if (satis()) ans++;
			for (i = 1; i + s.size() <= p.size(); i++)
			{
				if (p[i + s.size() - 1] >= 'a' && p[i + s.size() - 1] <= 'z') count2[p[i + s.size() - 1] - 'a']++;
				if (p[i - 1] >= 'a' && p[i - 1] <= 'z') count2[p[i - 1] - 'a']--;
				if (satis()) ans++;
			}
			printf("%d\n", ans);
		}
	}
}