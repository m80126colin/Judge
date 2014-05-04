/*
Problem: d562
Language: C++
Result: AC (166ms, 720KB) on ZeroJudge
Author: m80126colin at 2010-07-09 18:26:02
Solution: Straight Forward
*/
#include <iostream>
using namespace std;

int main() {
	bool ox;
	int n,i,j,k,l,a[100];
	for (ox=0;~scanf("%d",&n);ox=1) {
		if (ox) printf("\n");
		for (i=1;i<=n;i++) scanf("%d",&a[i]);
		for (i=1,j=n,k=n&1;n;n--) {
			if (((j+1-i)&1) == k) {
				for (l=i;l<=j;l++) printf("%d ",a[l]);
				i++;
			}
			else {
				for (l=j;l>=i;l--) printf("%d ",a[l]);
				j--;
			}
			printf("\n");
		}
	}
}