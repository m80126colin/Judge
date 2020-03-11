/**
 * @judge ZeroJudge
 * @id b430
 * @name 簡單乘法
 * 
 * @tag Modulus, Exponentiation by Squaring
 */
#include <bits/stdc++.h>
using namespace std;

uint64_t a, b, n;

uint64_t solve() {
	uint64_t res;
	res = 0;
	if (a >= n) a %= n;
	if (b >= n) b %= n;
	for (res = 0; a; a >>= 1) {
		if (a & 1)
			res = (res + b) % n;
		b = (b + b) % n;
	}
	return res;
}

int main() {
	while (~scanf("%ju%ju%ju", &a, &b, &n))
		printf("%ju\n", solve());
}