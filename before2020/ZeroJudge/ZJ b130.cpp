#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int i,n,a[101],b[101];
	while (cin>>n) {
		for (a[0]=1;a[0]<=n;a[0]++) cin>>a[a[0]];
		sort(a+1,a+n+1);
		for (a[0]=n,n=i=0,b[0]=1;b[0]<=a[0];b[0]++) {
			if (a[b[0]]!=i) {
				n++;
				i=b[n]=a[b[0]];
			}
		}
		cout<<n<<endl;
		for (a[0]=1;a[0]<=n;a[0]++) {
			if (a[0]!=1) cout<<" ";
			cout<<b[a[0]];
		}
		cout<<endl;
	}
}