/**
 *  @judge Google Code Jam
 *  @id Qualification Round 2020 pA
 *  @name Vestigium
 *  @contest Google Code Jam Qualification Round 2020
 * 
 *  @tag Ad-hoc, Matrix
 */
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int LL;

int n;
vector<vector<int>> matrix;
map<int, int> M;

bool checkr(int r) {
	M.clear();
	for (int j = 0; j < n; j++) {
		if (M[matrix[r][j]])
			return true;
		M[matrix[r][j]] = 1;
	}
	return false;
}

bool checkc(int c) {
	M.clear();
	for (int j = 0; j < n; j++) {
		if (M[matrix[j][c]])
			return true;
		M[matrix[j][c]] = 1;
	}
	return false;
}

void solve() {
	int k, r, c;
	k = r = c = 0;
	for (int i = 0; i < n; i++) {
		k += matrix[i][i];
		if (checkr(i))
			r++;
		if (checkc(i))
			c++;
	}
	cout << " " << k << " " << r << " " << c;
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		matrix = vector<vector<int>>(n, vector<int>(n));
		for (auto &&row : matrix)
			for (auto &&v : row)
				cin >> v;
		cout << "Case #" << i << ":";
		solve();
		cout << endl;
		matrix.clear();
	}
}