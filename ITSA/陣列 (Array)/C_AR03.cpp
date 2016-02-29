#include <stdio.h>
#include <iostream>
#define cube(x) (x*x*x)
using namespace std;

int main() {
	int a, i, ans;
	for (i = ans = 0; i < 6; i++) scanf("%d", &a), ans += cube(a);
	printf("%d\n", ans);
}