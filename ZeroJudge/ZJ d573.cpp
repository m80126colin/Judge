/*
Problem: d573
Language: C++
Result: AC (102ms, 863KB) on ZeroJudge
Author: m80126colin at 2010-07-09 21:13:04
Solution: Straight Forward
*/
#include <iostream>
using namespace std;

int n,i,j,k,x[100001];

int main() {
	while (~scanf("%d",&n)) {
		for (;n;n--) for (scanf("%d%d",&i,&j);j;j--) scanf("%d",&k),x[k]=i;
		scanf("%d",&k);
		printf("%d\n",x[k]);
	}
}