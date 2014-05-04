/*
Problem: d575
Language: C++
Result: AC (90ms, 690KB) on ZeroJudge
Author: m80126colin at 2010-07-12 14:33:10
Solution: Math
*/
#include <iostream>
inline long long ab(long long x) {return x>0 ? x : -x;}
int main() {for (long long a,b,c,d,r;~scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&r);puts((ab(c-a)+ab(d-b) >r ? "alive" : "die"))) ;}