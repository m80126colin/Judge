/*
Problem: d636
Language: CPP
Result: AC (2ms, 716KB) on ZeroJudge
Author: m80126colin at 2010-08-23 14:19:18
Solution: fast Exp.
*/
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int i,a,b,exp[32];
	scanf("%d %d",&a,&b);
	exp[0]=1;
	exp[1]=a%10007;
	for (i=1;i<32;i++,exp[i]=(exp[i-1]*exp[i-1])%10007) {
		if (b&(1<<(i-1))) {
			exp[0]*=exp[i];
			exp[0]%=10007;
		}
	}
	printf("%d\n",exp[0]);
}