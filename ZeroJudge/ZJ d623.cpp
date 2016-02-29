/*
Problem: d623
Language: C++
Result: AC (4ms, 744KB) on ZeroJudge
Author: m80126colin at 2010-07-13 15:46:05
Solutin: Round-off error
*/
#include <iostream>
#include <math.h>
#define M 1e-5
using namespace std;

int main() {
	for (double a,b,c,d,e;scanf("%lf%lf%lf%lf",&a,&b,&c,&d),fabs(a)>M&&fabs(b)>M&&fabs(c)>M&&fabs(d)>M;(e) ? printf("%.5lf %.5lf\n%.5lf %.5lf\n",d/e,-b/e,-c/e,a/e) : puts("cheat!")) e=a*d-b*c;
}