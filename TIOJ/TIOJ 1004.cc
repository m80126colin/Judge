#include <iostream>
using namespace std;

int main(){
	bool a[51];
	int i,j,n,n0;
	while (cin>>n) {
		memset(a,1,sizeof(a));
		n0=n;
		for (i=1,j=0;n0>1;i++) {
			if (i>n) i=1;
			if (a[i]) {
				j++;
				if (!(j%2)) a[i]=0,n0--;
			}
		}
		for (i=1;i<=n;i++) {
			if (a[i]) {
				cout<<i<<endl;
				break;
			}
		}
	}
}