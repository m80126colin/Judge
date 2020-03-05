#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class bignum
{
public:
	string s;
	friend ostream& operator << (ostream &os, bignum a);
	friend istream& operator >> (istream &is, bignum &a);
	bool operator > (const bignum &a) const
	{
		if (s.size() != a.s.size())
			return s.size() > a.s.size();
		int i;
		for (i = s.size() - 1; i >= 0; i--)
			if (s[i] != a.s[i])
				return s[i] > a.s[i];
		return 0;
	}
	bignum operator - (const bignum &a)
	{
		bignum b = (*this);
		int i;
		for (i = 0; i < a.s.size(); i++)
			b.s[i] = b.s[i] - a.s[i] + '0';
		for (i = 0; i < b.s.size() - 1; i++)
			if (!(b.s[i] >= '0' && b.s[i] <= '9'))
				b.s[i] += 10, b.s[i + 1]--;
		for (i = b.s.size() - 1; i; i--)
		{
			if (b.s[i] > '0' && b.s[i] <= '9') break;
			else b.s.erase(b.s.begin() + i);
		}
		return b;
	}
}a, b;

istream& operator >> (istream &is, bignum &a)
{
	is >> a.s;
	reverse(a.s.begin(), a.s.end());
	int i;
	for (i = a.s.size() - 1; i; i--)
	{
		if (a.s[i] > '0' && a.s[i] <= '9') break;
		else b.s.erase(b.s.begin() + i);
	}
	return is;
}
ostream& operator << (ostream &os, bignum a)
{
	reverse(a.s.begin(), a.s.end());
	os << a.s;
	return os;
}

int main()
{
	int n;
	for (scanf("%d", &n); n; n--)
	{
		cin >> a >> b;
		if (b > a)
		{
			putchar('-');
			cout << b - a << endl;
		}
		else cout << a - b << endl;
	}
}