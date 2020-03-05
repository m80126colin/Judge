#include <stdio.h>
#include <iostream>
using namespace std;

inline void getd(int &d) {
	char ch;
	while (!isdigit(ch = getchar()));
	d = 0;
	do {
		d = d * 10 + ch - '0';
	} while (isdigit(ch = getchar()));
	return;
}

int main() {
	int i, t, d, b, ans;
	for (getd(t); t; t--) {
		getd(d), getd(b);
		b--;
		b %= (1 << d);
		for (i = ans = 1; i < d; i++) {
			ans <<= 1;
			if (b & 1) ans++;
			b >>= 1;
		}
		printf("%d\n", ans);
	}
}