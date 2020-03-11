/**
 *  @judge ZeroJudge
 *  @id a702
 *  @name Cousin Primes
 * 
 *  @tag Prime
 */
#include <iostream>
#include <vector>
using namespace std;

const int n = 20000000;
bool sieve[n] = { 0 };
// vector<int> prime;
vector<pair<int, int>> cousins;

void gen_sieve() {
	for (int i = 4; i < n; i += 2)
		sieve[i] = true;
	for (int i = 9; i < n; i += 3)
		sieve[i] = true;
	for (int i = 5; i * i < n; i++)
		if (!sieve[i]) {
			int di = (i << 2) + (i << 1);
			for (int j = i * i; j < n; j += di)
				sieve[j] = true;
			int dj = (i % 6 == 1) ? 4 : 2;
			for (int j = (i + dj) * i; j < n; j += di)
				sieve[j] = true;
		}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	gen_sieve();
	for (int i = 3; i + 4 < n; i += 2)
		if (!sieve[i] && !sieve[i + 4])
			cousins.emplace_back(i, i + 4);
	int n;
	while (cin >> n) {
		cout << "(" << cousins[n - 1].first << ", " << cousins[n - 1].second << ")" << endl;
	}
}