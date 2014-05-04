#include <iostream>
using namespace std;

int a[501];

int re(int x,int y) {
	int i;
	for (i=1;i<=y;i++) {
		if (a[i]%x) return 0;
	}
	return 1;
}

int main() {
	int n,i,j,p[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	while (cin>>n) {
		for (i=1;i<=n;i++) cin>>a[i];
		for (a[0]=1,j=0;j<25;j++) {
			while (re(p[j],n)) {
				for (i=1;i<=n;i++) a[i]/=p[j];
				a[0]*=p[j];
			}
		}
		cout<<a[0]<<endl;
	}
}