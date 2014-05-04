#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

int a, b;

inline int mask(int x)
{
	string c = "";
	while (x)
	{
		if (x % 10 == 4) c = '4' + c;
		if (x % 10 == 7) c = '7' + c;
		x /= 10;
	}
	return atoi(c.c_str());
}

int main()
{
	while (scanf("%d%d", &a, &b) != EOF)
	{
		for (a++; mask(a) != b; a++);
		printf("%d\n", a);
	}
}