#include <stdio.h>
#include <iostream>
using namespace std;

int a[5];

int input()
{
	int i, j;
	for (i = 0; i < 5; i++) scanf("%d", &a[i]);
	for (i = 0; i < 5; i++)
		for (j = i + 1; j < 5; j++)
			if (a[i] > a[j]) swap(a[i], a[j]);
	if (a[4] == 0 && a[0] == a[4]) return 0;
	return 1;
}

int main()
{
	while (input()) printf("%d\n", a[2]);
}