#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct matrix
{
	int r, c, flag;
	matrix() { r = c = flag = 0; }
	matrix(int r, int c): r(r), c(c) { flag = 0; }
	matrix(int flag): flag(flag) { r = c = 0; }
}M[26];

int n;
string s;

inline int exp()
{
	int i, ans = 0;
	vector <matrix> S;
	S.clear();
	for (i = 0; i < s.size(); i++)
	{
		if (s[i] == '(') S.push_back(matrix(1));
		else if (s[i] == ')')
		{
			while (S.size() >= 2 && !S[S.size() - 1].flag && !S[S.size() - 2].flag)
			{
				matrix tmp1, tmp2;
				tmp1 = S[S.size() - 2];
				tmp2 = S[S.size() - 1];
				S.pop_back();
				S.pop_back();
				if (tmp1.c != tmp2.r) return -1;
				ans += tmp1.r * tmp1.c * tmp2.c;
				S.push_back(matrix(tmp1.r, tmp2.c));
			}
			if (S.size() <= 1) return -1;
			else if (!S[S.size() - 2].flag) return -1;
			else
			{
				matrix tmp = S[S.size() - 1];
				S.pop_back();
				S.pop_back();
				S.push_back(tmp);
			}
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
			S.push_back(M[s[i] - 'A']);
	}
	while (S.size() >= 2 && !S[S.size() - 1].flag && !S[S.size() - 2].flag)
	{
		matrix tmp1, tmp2;
		tmp1 = S[S.size() - 2];
		tmp2 = S[S.size() - 1];
		S.pop_back();
		S.pop_back();
		if (tmp1.c != tmp2.r) return -1;
		ans += tmp1.r * tmp1.c * tmp2.c;
		S.push_back(matrix(tmp1.r, tmp2.c));
	}
	if (S.size() > 1) return -1;
	return ans;
}

int main()
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		char ch;
		cin >> ch;
		scanf("%d%d", &M[ch - 'A'].r, &M[ch - 'A'].c);
	}
	while (cin >> s)
	{
		int result = exp();
		if (result >= 0) printf("%d\n", result);
		else puts("error");
	}
}