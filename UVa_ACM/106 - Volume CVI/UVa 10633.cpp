#include <iostream>
using namespace std;

int main() {
	long long m,k,t;
	while (cin>>m&&m) {
		t=0;
		for (k=m/9-m%10-1;k<=m/9;k++) {
			if (t) cout<<" ";
			if (k==(m+k)/10) {
				cout<<m+k;
				t++;
			}
		}
		cout<<endl;
	}
}