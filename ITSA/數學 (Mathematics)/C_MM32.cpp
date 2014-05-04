#include <stdio.h>
int isarm(int x) {
	int s = 0,t = x,a;
	while (t) {
		a = t%10;
		s += a*a*a;
		t/=10;
	}
	return (s == x);
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (isarm(n)) puts("Yes");else puts("No");
	}
}