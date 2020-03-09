/**
 *  @judge ZeroJudge
 *  @id d418
 *  @source UVa 993
 */
#include <iostream>
using namespace std;

int main() {
	int n,t,a[10];
	for (cin>>t;t;t--) {
		cin>>n;
		if (n==1) cout<<1;
		else {
			for (a[0]=9;a[0]>1;a[0]--) {
				a[a[0]]=0;
				while (n%a[0]==0) {
					a[a[0]]++;
					n/=a[0];
				}
			}
			if (n==1) {
				for (a[0]=2;a[0]<=9;a[0]++) {
					while (a[a[0]]--) cout<<a[0];
				}
			}
			else cout<<-1;	
		}
		cout<<endl;
	}
}