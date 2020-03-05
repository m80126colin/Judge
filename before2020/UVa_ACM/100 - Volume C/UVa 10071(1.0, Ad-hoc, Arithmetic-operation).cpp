#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int v, t;
	while (scanf("%d%d", &v, &t) != EOF)
		printf("%d\n", (v * t) << 1);
}