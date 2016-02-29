#include <iostream>
using namespace std;

int main() {
	int bit_2[31],i,j,n,k,ans;
	bit_2[0]=1;
	for (i=1;i<=30;i++) bit_2[i]=bit_2[i-1]<<1;
	for (cin>>i;i;i--) {
		ans=0;
		cin>>n>>k;
		for (j=n;j;j--) {
			int t=(k/bit_2[j-1])%4;
			if (t==1||t==2) ans+=bit_2[j-1];
		}
		cout<<ans<<endl;
	}
}