#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF) printf("%d\n", a+b);
}