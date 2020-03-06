/**
 *  @judge TIOJ
 *  @id 1140
 *  @tag Easy, Straight forward, Matrix
 */
#include <stdio.h>
#include <iostream>
using namespace std;

double makov[3][3] = {
	{0.5149, 0.3244, 0.1607},
	{0.2654, 0.6704, 0.0642},
	{0.0248, 0.1248, 0.8504}
};
double XYZ[3], RGB[3];
int n;

inline void matrix_multiplication()
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		XYZ[i] = 0;
		for (j = 0; j < 3; j++)
			XYZ[i] += makov[i][j] * RGB[j];
	}
	return;
}

int main()
{
	int i, j, k;
	double avg;
	while (scanf("%d", &n) != EOF)
	{
		avg = 0;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				for (k = 0; k < 3; k++)
					scanf("%lf", &RGB[k]);
				matrix_multiplication();
				for (k = 0; k < 3; k++)
				{
					if (k) putchar(' ');
					printf("%.04lf", XYZ[k]);
				}
				puts("");
				avg += XYZ[1];
			}
		printf("The average of Y is %.04lf\n", avg / (n * n));
	}
}