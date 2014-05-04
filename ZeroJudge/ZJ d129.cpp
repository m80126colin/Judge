#include <iostream>
#include <algorithm>
using namespace std;

long long a,n[1501],t,i;

int re(long long x) {
	int j;
	if (x<0||x>859963392) return 0;
	for (j=1;j<=t;j++) {
		if (x==n[j]) return 0;
	}
	n[t+1]=x;
	t++;
}

int main() {
	n[1]=t=1;
	for (i=1;i<=t&&t<=1500;i++) {
		re(n[i]*2);
		re(n[i]*3);
		re(n[i]*5);
	}
	sort(n+1,n+1501);
	cout<<"The 1500\'th ugly number is "<<n[1500]<<"."<<endl;
}