/*
Problem: d584
Language: C++
Result: AC (5ms, 722KB) on ZeroJudge
Author: m80126colin at 2010-07-12 19:02:37
Solution: Table
*/
#include <iostream>
using namespace std;

int a[5][201],i,j;
inline void ad() {
	for (a[2][8]=i=1;i<3;i++) a[2][8+i]=a[2][7+i]+3;
	for (i=10;i<=200;i++) {
		if (i==10) a[1][i]=a[3][i]=a[4][i]=a[1][i-1]+1;
		else if (i==30||i==70) for (j=1;j<=4;j++) a[j][i]=a[j][i-1]+4;
		else if (i==120) for (j=1;j<=4;j++) a[j][i]=a[j][i-1]+6;
		else for (j=1;j<=4;j++) a[j][i]=a[j][i-1]+3;
	}
}
int main() {for (ad();~scanf("%d%d",&i,&j);printf("%d\n",a[i][j]));}