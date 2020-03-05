#include <iostream>
using namespace std;

int main() {
	int n,a[10001];
	short i,j;
	for (i=1;cin>>n;i++) {
		j=i-1;
		while (n<a[j]&&j>0) {
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=n;
		if (i%2) cout << a[(i+1)/2] << endl;
		else cout << (a[i/2]+a[i/2+1])/2 << endl;
	}
}