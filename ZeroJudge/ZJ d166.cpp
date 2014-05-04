#include <iostream>
using namespace std;

int main() {
	int b[51],m,i,j;
	while (cin>>b[1]&&b[1]>=0) {
		for (m=2;cin.peek()!='\n';m++) cin>>b[m];
		for (i=1;i<m;i++) {
			for (j=1;b[j]--;j++) ;
			cout<<j<<" ";
		}
		cout<<endl;
	}
}