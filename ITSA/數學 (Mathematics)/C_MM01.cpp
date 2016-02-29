#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) != EOF) printf("Trapezoid area:%.1lf\n", (double) (a+b)*c/2.0);
}