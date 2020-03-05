#include <iostream>
using namespace std;

int main() {
	int n,t,i,j,a[1001];
	while (cin>>n) {
		for (t=1;t<=n;t++) cin>>a[t];
		t=0;
		for (i=1;i<n;i++) {
			for (j=1;j<n;j++) {
				if (a[j]>a[j+1]) {
					a[0]=a[j+1];
					a[j+1]=a[j];
					a[j]=a[0];
					t++;
				}
			}
		}
		cout<<"Minimum exchange operations : "<<t<<endl;
	}
}