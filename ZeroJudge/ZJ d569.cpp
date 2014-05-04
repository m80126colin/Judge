/*
Problem: d569
Language: C++
Result: AC (804ms, 692KB) on ZeroJudge
Author: m80126colin at 2010-07-09 20:07:22
Solution: Putchar
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	bool ox;
	char s[101][5];
	int n,i,j,k,l,m;
	for (ox=0;~scanf("%d",&n);ox=1) {
		if (ox) putchar(10);
		for (i=1;i<=n;i++) scanf("%s",&s[i]);
		for (i=1,j=n,k=n&1;n;n--) {
			if (((j+1-i)&1) == k) {
				for (l=i;l<=j;l++) {
					for (m=0;m<strlen(s[l]);m++) putchar(s[l][m]);
					putchar(32);
				}
				i++;
			}
			else {
				for (l=j;l>=i;l--) {
					for (m=0;m<strlen(s[l]);m++) putchar(s[l][m]);
					putchar(32);
				}
				j--;
			}
			putchar(10);
		}
	}
}