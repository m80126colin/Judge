/**
 *  @judge ZeroJudge
 *  @id a005
 *  @tag Easy, Loop, Math
 */
#include <iostream>
using namespace std;

int main() {
	int t,i,a[6];
	for (cin>>t;t;t--) {
		cin>>a[1]>>a[2]>>a[3]>>a[4];
		for (i=1;i<4;i++) {
			a[5]=a[i+1]-a[i];
			if (i==1) a[0]=a[5];
			if (a[0]!=a[5]) {
				a[0]=1000000;
				break;
			}
		}
		if (a[0]<1000000) a[5]=a[4]+a[0];
		else {
			for (i=1;i<4;i++) {
				a[5]=a[i+1]/a[i];
				if (i==1) a[0]=a[5];
				if (a[0]!=a[5]) {
					a[0]=1000000;
					break;
				}
			}
			if (a[0]<1000000) a[5]=a[4]*a[0];
		}
		cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<a[5]<<endl;
	}
}