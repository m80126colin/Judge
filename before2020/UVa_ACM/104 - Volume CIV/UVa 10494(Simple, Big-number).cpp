#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class Bignum
{
public:
#define MAX 1000
	int top, digit[MAX];
	Bignum()
	{
		top = 0;
		memset(digit, 0, sizeof(digit));
	}
	Bignum& operator = (string str)
	{
		int i, j;
		j = 0;
		memset(digit, 0, sizeof(digit));
		for (i = str.size(); i - 8 > 0; i -= 8)
		{
			digit[j] = atoi( str.substr(i - 8, 8).c_str() );
			j++;
		}
		top = j;
		digit[j] = atoi( str.substr(0, i).c_str() );
		return (*this);
	}
	Bignum& operator <<= (const int& num)
	{
		int i;
		for (i = top; i >= 0; i--)
			digit[i + num] = digit[i];
		for(i = num - 1; i >= 0; i--)
			digit[i] = 0;
		top += num;
		return (*this);
	}
	Bignum operator / (const int& num)
	{
		int i;
		Bignum NUM;
		long long buf = 0;
		for (i = top; i >= 0; i--)
		{
			NUM <<= 1;
			buf *= 100000000;
			buf += digit[i];
			NUM.digit[0] += buf / num;
			buf %= num;
		}
		while (NUM.top > 0 && NUM.digit[NUM.top] == 0) NUM.top--;
		return NUM;
	}
	long long operator % (const int& num)
	{
		int i;
		Bignum NUM;
		long long buf = 0;
		for (i = top; i >= 0; i--)
		{
			NUM <<= 1;
			buf *= 100000000;
			buf += digit[i];
			NUM.digit[0] += buf / num;
			buf %= num;
		}
		while (NUM.top > 0 && NUM.digit[NUM.top] == 0) NUM.top--;
		return buf;
	}
	friend istream& operator >> (istream& in, Bignum& NUM)
	{
		string s;
		cin >> s;
		NUM = s;
		return in;
	}
	friend ostream& operator << (ostream& out, const Bignum& NUM)
	{
		int i;
		char ch[10];
		cout << NUM.digit[NUM.top];
		for (i = NUM.top - 1; i >= 0; i--)
		{
			sprintf(ch, "%08d", NUM.digit[i]);
			cout << ch;
		}
		return out;
	}
};

int main()
{
	char ch;
	Bignum B;
	int n;
	while (cin >> B >> ch >> n)
	{
		if (ch == '/') cout << B / n << endl;
		else cout << B % n << endl;
	}
}