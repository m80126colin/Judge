/**
 *  @judge CodeForces
 *  @id 1312E
 *  @name Array Shrinking
 *  @contest Educational Codeforces Round 83
 * 
 *  @tag Dynamic Programming
 * 
 *  solution:
 *    dp[i][j] = (left element, right element, length)
 * 
 *    for each segment S[i, j] (included), we have SL[i, k] and SR[k + 1, j] with minimum length_S:
 *          dp[i][j] =
 *              (left_SL, right_SR, length_SL + length_SR)         if right_SL != left_SR
 *              (left,    right,    length_SL + length_SR - 1)     if right_SL == left_SR
 *                  where left, right = left_SL, right_SR          if length_SL != 1, length_SR != 1 resp.
 *                                      left_SR + 1, right_SL + 1  otherwise
 */
#include <bits/stdc++.h>
using namespace std;

const int MAX = 510;

int n, a[MAX];
tuple<int, int, int> dp[MAX][MAX];

int solve() {
	for (int i = 0; i < n; i++)
		dp[i][i] = make_tuple(a[i], a[i], 1);
	for (int k = 2; k <= n; k++) {
		for (int i = 0; i + k - 1 < n; i++) {
			int end = i + k - 1;
			dp[i][end] = make_tuple(a[i], a[end], k);
			for (int j = i; j < end; j++) {
				int ltL, ltR, ltLen, rtL, rtR, rtLen;
				tie(ltL, ltR, ltLen) = dp[i][j];
				tie(rtL, rtR, rtLen) = dp[j + 1][end];
				if (ltR == rtL && ltLen + rtLen - 1 < get<2>(dp[i][end]))
					dp[i][end] = make_tuple(ltLen == 1 ? ltR + 1 : ltL, rtLen == 1 ? rtL + 1 : rtR, ltLen + rtLen - 1);
				else if (ltLen + rtLen < get<2>(dp[i][end]))
					dp[i][end] = make_tuple(ltL, rtR, ltLen + rtLen);
			}
		}
	}
	return get<2>(dp[0][n - 1]);
}

int main() {
	while (cin >> n) {
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << solve() << endl;
	}
}