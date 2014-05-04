#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int parity;
void convert(int num)
{
	if (num == 0) return ;
	convert(num >> 1);
	char ch = (num & 1) + '0';
	if (num & 1) parity++, putchar('1');
	else putchar('0');
	return ;
}

int main()
{
	int i;
	while (scanf("%d", &i), i)
	{
		printf("The parity of ");
		parity = 0;
		convert(i);
		printf(" is %d (mod 2).\n", parity);
	}
}