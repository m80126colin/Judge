#include <iostream>
using namespace std;

int main() {
	long long a[19],m,temp,i,j,n,t;
	for (t=1;cin>>n;t++) {
		m=0;
		for (i=1;i<=n;i++) cin>>a[i];
		for (i=1;i<=n;i++) {
			temp=1;
			for (j=i;j<=n;j++) {
				temp*=a[j];
				m=max(m,temp);
			}
		}
		cout<<"Case #"<<t<<": The maximum product is "<<m<<".\n\n";
	}
}