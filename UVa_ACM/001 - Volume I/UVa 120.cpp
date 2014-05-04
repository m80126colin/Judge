#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MAX 140
using namespace std;

struct pan{
	int num, pos;
}b[MAX];
int a[MAX], hash[MAX];

bool cmp(pan down, pan up) {
	return down.num > up.num;
}

inline void reverse(int x, int y) {
	int n = (y - x) / 2, i;
	for (i = 0; i < n; i++) {
		swap(b[hash[a[x+i]]].pos, b[hash[a[y-i-1]]].pos);
		swap(a[x+i], a[y-i-1]);
	}
	return;
}

int main() {
	int n, i;
	char ch;
	while (scanf("%d%c",&i,&ch) != EOF) {
		n = 0;
		memset(hash, 0, sizeof(hash));
		do {
			a[n] = b[n].num = i;
			b[n].pos = n;
			n++;
		} while (ch != '\n' && scanf("%d%c", &i, &ch));
		sort(b, b+n, cmp);
		for (i = 0; i < n; i++) {
			if (i) putchar(' ');
			printf("%d", a[i]);
			hash[b[i].num] = i;
		}
		puts("");
		reverse(0, n);
		for (i = 0; i < n; i++) {
			if (b[i].num != a[i]) {
				if (b[i].pos + 1 != n) {
					printf("%d ", b[i].pos + 1);
					reverse(b[i].pos, n);
				}
				printf("%d ", i + 1);
				reverse(i, n);
			}
		}
		puts("0");
	}
}