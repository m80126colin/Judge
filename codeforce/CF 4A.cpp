#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
		puts(((n & 1) == 0 && n >= 4)?"YES":"NO");
}