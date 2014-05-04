#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

const int maxn = 4000; // the longest digits of big number
struct bign
{
	int len, s[maxn];
	bign(){ memset(s, 0, sizeof(s)); len = 1; } // constructor

	bign operator = (const char *num) // assignment by C string
	{
		len = strlen(num);
		for (int i = 0; i < len; i++) s[i] = num[len - i - 1] - '0';
		return *this;
	}

	bign operator = (int num)
	{
		char s[maxn];
		sprintf(s, "%d", num);
		*this = s;
		return *this;
	}

	bign(int num) { *this = num; }
	bign(const char *num) { *this = num; } // support "bign N = xxx;" feature

	string str() const // transform bign to string
	{
		string res = "";
		for (int i = 0; i < len; i++) res = (char)(s[i] + '0') + res;
		if (res == "") res = "0"; // boundary: when N == 0
		return res;
	}

	friend istream& operator >> (istream &in, bign &x) // istream: input stream -> cin
	{
		string s;
		in >> s; // read in a string
		x = s.c_str(); // transform into C string
		return in;
	}

	friend ostream& operator << (ostream &out, const bign &x) // ostream: output stream -> cout
	{
		out << x.str();
		return out;
	}

	bign operator + (const bign &b) const
	{
		bign c;
		c.len = 0;
		for (int i = 0, g = 0; g || i < max(len, b.len); i++) // g: carry
		{
			int x = g;
			if (i < len) x += s[i];
			if (i < b.len) x += b.s[i];
			c.s[c.len++] = x % 10;
			g = x / 10;
		}
		return c;
	}
	bign operator += (const bign &b)
	{
		*this = *this + b;
		return *this;
	}

	bign operator * (const bign &b) const
	{
		int i, j, k;
		bign c;
		memset((void *) &c, 0, sizeof(c));
		c.len = len + b.len;
		for (i = 0; i < len; i++)
			for (j = 0; j < b.len; j++)
				c.s[i + j] += s[i] * b.s[j];
		for (k = 1; k < c.len; k++)
		{
			c.s[k] += c.s[k - 1] / 10;
			c.s[k - 1] %= 10;
		}
		while (c.s[c.len - 1] > 10)
		{
			c.s[c.len] += c.s[c.len - 1] / 10;
			c.s[c.len++] %= 10;
		}
		while (c.len > 1 && c.s[c.len - 1] == 0)
			c.len--;
		return c;
	}
	bign operator *= (const bign &b)
	{
		*this = *this * b;
		return *this;
	}

	bool operator < (const bign &b) const // comparison
	{
		if (len != b.len) return len < b.len;
		for (int i = len - 1; i >= 0; i--)
			if (s[i] != b.s[i]) return s[i] < b.s[i];
		return false;
	}
	bool operator > (const bign &b) const { return b < *this; }
	bool operator <= (const bign &b) const { return !(b < *this); } // to avoid too much function call, so we don't write !(b > *this)
	bool operator >= (const bign &b) const { return !(*this < b); }
	bool operator != (const bign &b) const { return b < *this || *this < b; } // one is smaller than the other
	bool operator == (const bign &b) const { return !(b < *this) && !(*this < b); }
};

#define MAX 400
bign fact[MAX];
int count[MAX][10], n;

int main()
{
	fact[0] = 1;
	count[0][1] = 1;
	for (int i = 1; i < MAX; i++)
	{
		fact[i] = fact[i - 1] * bign(i);
		for (int j = 0; j < fact[i].len; j++)
			count[i][fact[i].s[j]]++;
	}
	while (scanf("%d", &n), n)
	{
		printf("%d! --", n);
		for (int i = 0; i < 10; i++)
		{
			if (i % 5 == 0) puts("");
			if (i % 5) printf("    ");
			printf("(%d)%5d", i, count[n][i]);
		}
		puts("");
	}
}