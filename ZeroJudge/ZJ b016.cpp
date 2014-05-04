#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#define MAX 30
using namespace std;

struct Matrix
{
	int m, n;
	int ele[MAX][MAX];
	Matrix () {}
	Matrix (int m, int n, int d): m(m), n(n) {
		int i, j;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				ele[i][j] = d;
			}
		}
	}
	inline Matrix operator + (const Matrix &b) {
		Matrix a = (*this);
		int i, j;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				a.ele[i][j] += b.ele[i][j];
			}
		}
		return a;
	}
	inline Matrix operator - (const Matrix &b) {
		Matrix a = (*this);
		int i, j;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				a.ele[i][j] -= b.ele[i][j];
			}
		}
		return a;
	}
	inline Matrix operator * (const Matrix &b) {
		Matrix a = Matrix(m, b.n, 0);
		int i, j, k;
		for (i = 0; i < m; i++) {
			for (j = 0; j < b.n; j++) {
				for (k = 0; k < n; k++) {
					a.ele[i][j] += ele[i][k] * b.ele[k][j];
				}
			}
		}
		return a;
	}
	inline Matrix trans() {
		Matrix a = Matrix(n, m, 0);
		int i, j;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				a.ele[i][j] = ele[j][i];
			}
		}
		return a;
	}
	inline int det() {
		if (n == 1) return ele[0][0];
		if (n == 2) return ele[0][0] * ele[1][1] - ele[1][0] * ele[0][1];
		int i, j, tmp, d = 0;
		for (i = 0; i < m; i++) {
			tmp = 1;
			for (j = 0; j < n; j++) {
				tmp *= ele[j][(i+j) % n];
			}
			d += tmp;
			tmp = -1;
			for (j = 0; j < n; j++) {
				tmp *= ele[j][(i-j+n) % n];
			}
			d += tmp;
		}
		return d;
	}
	inline Matrix minor(int x, int y) {
		Matrix a = Matrix(m - 1, n - 1, 0);
		int i, j;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				a.ele[i - (i > x)][j - (j > y)] = ele[i][j];
			}
		}
		return a;
	}
	inline Matrix inverse() {
		Matrix a = Matrix(n, m, 0);
		int i, j;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				a.ele[i][j] = ( ((i+j) & 1)? -1: 1) * ((*this).minor(i, j)).det();
			}
		}
		return a.trans();
	}
	inline void output() {
		int i, j;
		putchar('[');
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++)
				printf(" %d", ele[i][j]);
			if(i < m - 1)
				printf(" ;");
		}
		puts(" ]");
		return;
	}
}m[26];

char s[3000];

inline void out() {
	int i;
	for (i = 0; i < 26; i++)
		m[i].output();
	return;
}

inline void sol()
{
	int x = s[0] - 'a', i, j, k;
	if(s[4] == '[') {
		i = j = 0;
		int d = 0, p = 1;
		for (k = 6; s[k]; k++) {
			if (isdigit(s[k]) || s[k] == '-') {
				if(s[k] == '-')
					p = -1, k++;
				else
					p = 1;
				while (isdigit(s[k]))
					d = d * 10 + (s[k] - '0') * p, k++;
				m[x].ele[i][j++] = d;
				d = 0;
			}
			else if (s[k] == ';')
				j = 0, i++;
		}
		m[x].m = i + 1;
		m[x].n = j;
	}
	else {
		if (strlen(s) == 5) {
			m[x] = m[s[4] - 'a'];
			return;
		}
		Matrix a = m[s[4] - 'a'], b = m[s[8] - 'a'];
		switch (s[6]) {
			case '+':
				m[x] = a + b;
				break;
			case '-':
				m[x] = a - b;
				break;
			case '*':
				m[x] = a * b;
				break;
			case '/':
				m[x] = a * b.inverse();
				break;
			case '\\':
				m[x] = a.inverse() * b;
				break;
			default:
				break;
		}
	}
	return;
}

int main() {
	int i, c = 0;
	while (gets(s)) {
		if (c++) puts("");
		for (i = 0; i < 26; i++) m[i].n = m[i].m = 0;
		if(!s[0]) {
			out();
			continue;
		}
		sol();
		while (gets(s)) {
			if(!s[0]) break;
			else sol();
		}
		out();
	};
}