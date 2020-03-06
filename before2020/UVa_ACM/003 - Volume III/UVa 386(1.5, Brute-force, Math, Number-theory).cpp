/**
 *  @judge UVa
 *  @id 386
 *  @tag 1.5, Brute force, Math, Number Theory
 */
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

#define MAX 201
#define cube(x) ((x) * (x) * (x))
#define cbrt(x) (pow(x, 1.0 / 3.0))
int table[MAX];

int main()
{
	int a, b, c, d;
	for (a = 1; a < MAX; a++)
		table[a] = cube(a);
	for (a = 2; a < MAX; a++)
	{
		for (b = 2; b < a; b++)
		{
			for (c = b + 1; c < a && table[b] + table[c] < table[a]; c++)
			{
				d = cbrt(0.5 + table[a] - table[b] - table[c]);
				if (d > c && table[a] == table[b] + table[c] + table[d])
					printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
			}
		}
	}
}