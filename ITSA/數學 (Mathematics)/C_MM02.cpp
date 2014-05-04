#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF) printf("%.1lf\n", (double) a*b/2.0);
}