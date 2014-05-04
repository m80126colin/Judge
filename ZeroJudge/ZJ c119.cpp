#include <iostream>
using namespace std;

int main() {
	int n[1001],i,j;
	while (cin>>i) {
		for (j=1000;j;j--) n[j]=0;
		for (n[0]=1;i;i--) {
			for (j=1000;j>=0;j--) {
				n[j]*=i;
				if (n[j]/10000) {
					n[j+1]+=n[j]/10000;
					n[j]%=10000;
				}
			}
		}
		for (j=1000;j>=0;j--) {
			while (n[j]) {
				i+=n[j]%10;
				n[j]/=10;
			}
		}
		cout<<i<<endl;
	}
}