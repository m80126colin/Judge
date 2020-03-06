/**
 *  @judge UVa
 *  @id 10082
 *  @tag 1.0, Ad-hoc, String, Cryptography
 */
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

string word = "`1234567890-=QWERTYUIOP[]ASDFGHJKL;\'ZXCVBNM,./";

int main()
{
	int pos;
	char ch;
	while ((ch = getchar()) != EOF)
	{
		if ((pos = word.find(ch)) != string::npos) putchar(word[pos - 1]);
		else putchar(ch);
	}
}