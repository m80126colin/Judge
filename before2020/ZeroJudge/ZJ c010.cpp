#include <iostream>
using namespace std;

int r(int x,int *y) {
	for (x;y[x]<y[x-1]&&x>1;x--) swap(y[x],y[x-1]);
	return 0;
}

int main() {
	int n[10001];
	n[0]=0;
	while (cin>>n[++n[0]]) {
		r(n[0],n);
		if (n[0]%2) cout<<n[n[0]/2+1]<<endl;
		else cout<<(n[n[0]/2]+n[n[0]/2+1])/2<<endl;
	}
}