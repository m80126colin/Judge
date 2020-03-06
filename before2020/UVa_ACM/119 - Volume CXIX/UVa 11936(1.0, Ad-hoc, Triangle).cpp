/**
 *  @judge UVa
 *  @id 11936
 *  @tag 1.0, Ad hoc, Triangle
 */
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 3
int a[3];

void mysort()
{
	int i, j;
	for (i = 0; i < MAX; i++)
		for (j = i + 1; j < MAX; j++)
			if (a[j] < a[i]) swap(a[j], a[i]);
	return ;
}

int main()
{
	int n, i;
	for (scanf("%d", &n); n; n--)
	{
		for (i = 0; i < MAX; i++)
			scanf("%d", &a[i]);
		mysort();
		if (a[2] - a[1] < a[0]) puts("OK");
		else puts("Wrong!!");
	}
}