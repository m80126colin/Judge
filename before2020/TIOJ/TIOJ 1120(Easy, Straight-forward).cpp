/**
 *  @judge TIOJ
 *  @id 1120
 *  @tag Easy, Straight forward
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int ix[6] = {0, 10, 15, 15, 5, 5};
int iy[6] = {0, 5, 5, 15, 15, 5};
int dx[6] = {0, 1, 0, -1, 0, 1};
int dy[6] = {0, 0, 1, 0, -1, 0};
int seg[6] = {0, 5, 15, 25, 35, 40};

int main()
{
	int t, i;
	while (scanf("%d", &t) != EOF)
	{
		for (t = (t * 6) % 40, i = 1; i < 6; i++)
		{
			if (t >= seg[i - 1] && t < seg[i])
			{
				t -= seg[i - 1];
				printf("(%d,%d)\n", ix[i] + t * dx[i], iy[i] + t * dy[i]);
				break;
			}
		}
	}
}