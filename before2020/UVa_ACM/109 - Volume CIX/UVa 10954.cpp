#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> m;

void trans() {
	int i, it;
	for (i = 1; 2 * i <= m.size(); ) {
		it = 2 * i;
		if (m.size() > 2 * i && m[it - 1] > m[it]) it++;
		if (m[i - 1] > m[it - 1]) swap(m[i - 1], m[it - 1]), i = it;
		else return;
	}
}

int main() {
	int n, i, j, sum, cost;
	while (cin >> n, n) {
		m.clear();
		for (i = 1; i <= n; i++) scanf("%d", &j), m.push_back(j);
		sort(m.begin(), m.end());
		for (cost = 0; m.size() > 1; trans()) {
			sum = m[0];
			swap(m[0], m[m.size() - 1]);
			m.pop_back();
			trans();
			cost += (sum+=m[0]);
			m[0] = sum;
		}
		cout << cost << endl;
	}
}