#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

#define EPS 5.14e-7
#define K 50010
#define SQK 224
int ox[K], sq[SQK];

void sol(int m) {
	int i, j, k;
	for (i = 0; i < SQK && sq[i] <= m; i++)
		for (j = i; j < SQK && sq[i] + sq[j] <= m; j++) {
			k = sqrt((double) m - sq[i] - sq[j]) + EPS;
			if (sq[i] + sq[j] + sq[k] == m) {
				printf("%d %d %d\n", i, j, k);
				return;
			}
		}
	return;
}

int main()
{
	int i, j, k, n, m;
	for (i = 0; i < SQK; i++)
		sq[i] = i * i;
	for (i = 0; i < SQK && sq[i] < K; i++)
		for (j = i; j < SQK && sq[i] + sq[j] < K; j++)
			for (k = j; k < SQK && sq[i] + sq[j] + sq[k] < K; k++)
				ox[sq[i] + sq[j] + sq[k]] = 1;
	for (scanf("%d", &n); n; n--) {
		scanf("%d", &m);
		if (ox[m]) sol(m);
		else puts("-1");
	}
}