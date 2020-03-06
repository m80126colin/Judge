/**
 *  @judge TIOJ
 *  @id 1185
 *  @tag Easy, Straight forward, Loop
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) != EOF)
	{
		if (a > b) swap(a, b);
		if (b > c) swap(b, c);
		if (a > b) swap(a, b);
		puts((a > 0 && b > 0 && c > 0 && c - b < a)? "SAFE": "BYE");
	}
}